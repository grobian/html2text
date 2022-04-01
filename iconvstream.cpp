/*
 * Copyright 2020-2022 Fabian Groffen
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License in the file COPYING for more details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <iconv.h>

#include <iostream>
#include "iconvstream.h"

void
iconvstream::open_is(const char *file_name, const char *encoding_in)
{
	close_is();

	encoding = encoding_in;

	fd_is =
		strcmp(file_name, "-") == 0 ? ::dup(0) : ::open(file_name, O_RDONLY);
	if (fd_is == -1)
		open_err = strerror(errno);

	readbufsze = 1024;  /* matches w3c's req for content type declaration */
	rutf8bufsze = readbufsze * 4;
	readbuflen = 0;
	rutf8buflen = 0;
	readbufpos = 0;
	rutf8bufpos = 0;
	readbuf = new unsigned char[readbufsze];
	rutf8buf = new unsigned char[rutf8bufsze];

	/* trigger charset detection, and reset the pointer afterwards,
	 * doing this now generates an error if the charset is invalid,
	 * which is not expected to be set during reading */
	if (!open_err) {
		get();
		rutf8bufpos = 0;
		if (open_err) {
			close_is();
			fd_is = -1;
		}
	}
}

void
iconvstream::open_is(const string &url, const char *encoding)
{
	open_is(url.c_str(), encoding);
}

void
iconvstream::close_is(void)
{
	if (is_open()) {
		::close(fd_is);
		delete readbuf;
		delete rutf8buf;
	}
}

void
iconvstream::open_os(const char *file_name, const char *encoding)
{
	close_os();

	/* internal processing uses UTF-8 */
	iconv_handle_os = iconv_open(encoding, "UTF-8");
	if (iconv_handle_os == iconv_t(-1)) {
		open_err = "invalid to_encoding";
		return;
	}

	fd_os = strcmp(file_name, "-") == 0 ?
			::dup(1) :
			::open(file_name, O_WRONLY | O_CREAT,
				   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_os == -1)
		open_err = strerror(errno);

	writebufsze = 1024;
	wutf8bufsze = writebufsze * 4;  /* worst case scenario UTF-32 */
	writebuflen = 0;
	wutf8buflen = 0;
	writebufpos = 0;
	wutf8bufpos = 0;
	writebuf = new unsigned char[writebufsze];
	wutf8buf = new unsigned char[wutf8bufsze];
}

void
iconvstream::open_os(const string &url, const char *encoding)
{
	open_os(url.c_str(), encoding);
}

void
iconvstream::close_os(void)
{
	if (os_open()) {
		*this << flush;
		::close(fd_os);
		delete writebuf;
		delete wutf8buf;
	}
}

static const char *
find_tokens(char *buf, size_t len, const char **tokens)
{
	char        *startp     = NULL;
	char        *curp;
	const char **curtoken   = tokens;
	char         startfound = 0;

	for (curp = buf; curp - buf < len; curp++) {
		/* [a-zA-Z0-9/-]+ */
		if ((*curp >= 'a' && *curp <= 'z') ||
			(*curp >= 'A' && *curp <= 'Z') ||
			(*curp >= '0' && *curp <= '9') ||
			*curp == '/' || *curp == '-')
		{
			if (startp == NULL)
				startp = curp;
		}
		else
		{
			if (startp != NULL) {
				if (*curtoken == NULL) {
					return strndup(startp, curp - startp);  /* LEAK */
				} else if (strlen(*curtoken) == curp - startp &&
						   strncasecmp(*curtoken, startp, curp - startp) == 0)
				{
					if (startfound != 0 || startp[-1] == '<') {
						startfound = 1;
						curtoken++;
					}
				} else if (startfound == 1) {
					startfound = 0;
					curtoken   = tokens;
				}
			}
			startp = NULL;
		}
	}

	return NULL;
}

const char *
iconvstream::open_error_msg() const
{
	return open_err ? open_err : "No error";
}

int
iconvstream::get()
{
	if (rutf8bufpos == rutf8buflen) {
		char *procinp = (char *)readbuf;
		char *procout = (char *)rutf8buf;
		size_t iconvret;

		readbuflen = read(fd_is, readbuf + readbufpos, readbufsze - readbufpos);
		if (readbuflen <= 0)
			return EOF;

		if (rutf8buflen == 0) {
			/* on first read, figure out what encoding this is, unless a
		 	 * specific override is in place */
			if (strcmp(encoding, "auto") == 0) {
				/* look for UTF-BOM, this should override any meta
				 * declaration (feels like a safe way for M$ to screw
				 * this up, but let's go with this for now)
				 * https://www.w3.org/International/questions/qa-html-encoding-declarations#bom */
				if (readbuflen >= 2 && memcmp(readbuf, "\ufeff", 2) == 0) {
					encoding = "UTF-8";
				} else {
					const char *tokens_charset[] = {
						"meta", "charset", NULL
					};
					const char *tokens_contenttype[] = {
						"meta", "http-equiv", "content-type",
						"content", "text/html", "charset", NULL
					};
					/* hunt down meta, which can be two forms
					 * - <meta charset="utf-8"/>
					 * - <meta http-equiv="Content-Type"
					 *    content="text/html; charset=utf-8"/>
					 * https://www.w3.org/International/questions/qa-html-encoding-declarations#quickanswer
					 * now there is the correct way, which would be to
					 * parse whatever xml, and the quick 'n' dirty way,
					 * which is to simply do some lame-@$$ parsing */
					encoding = find_tokens((char *)readbuf, readbuflen,
										   tokens_charset);
					if (encoding == NULL) {
						encoding = find_tokens((char *)readbuf, readbuflen,
											   tokens_contenttype);
					}
					/* fall back to lame historical default */
					if (encoding == NULL)
						encoding = "ISO-8859-1";
				}
			}

			/* we always encode to UTF-8 for internal processing */
			iconv_handle_is = iconv_open("UTF-8", encoding);
			if (iconv_handle_is == iconv_t(-1)) {
				open_err = "invalid from_encoding";
				return 0;
			}
		}

		readbuflen += readbufpos;
		readbufpos = 0;
		rutf8buflen = rutf8bufsze;
		/* iconv updates readbuflen and utf8buflen */
		do {
			iconvret = iconv(iconv_handle_is, &procinp, &readbuflen,
					&procout, &rutf8buflen);
			if (iconvret == (size_t)-1) {
				switch (errno) {
					case EILSEQ:
						/* byte is invalid, try to step over it */
						*procout++ = '?';
						procinp++;
						readbuflen--;
						rutf8buflen--;
						break;
					case EINVAL:
						/* this typically means we stopped reading halfway,
						 * e.g. this is fine, resume next time */
						memmove(readbuf, procinp, readbuflen);
						readbufpos = readbuflen;
						iconvret = 0;
						break;
					case E2BIG:
						/* output buffer is not large enough, this is
						 * impossible since we allocate 4x */
					default:
						return EOF;
				}
			}
		} while (iconvret == (size_t)-1);
		rutf8bufpos = 0;
		rutf8buflen = procout - (char *)rutf8buf;
	}

	return rutf8bufpos < rutf8buflen ? rutf8buf[rutf8bufpos++] : EOF;
}

int
iconvstream::write(const char *inp, size_t len)
{
	size_t outlen = len;
	size_t copylen;
	size_t copypos = 0;
	int ret = -1;

	do {
		copylen = writebufsze - writebufpos;
		if (copylen > outlen)
			copylen = outlen;
		memcpy(writebuf + writebufpos, inp + copypos, copylen);
		outlen -= copylen;
		copypos += copylen;
		writebufpos += copylen;

		/* flush if the buffer is full, or when explicitly requested */
		if (writebufpos == writebufsze || len == 0) {
			size_t iconvret;
			size_t inplen = writebufpos;
			char *procinp = (char *)writebuf;
			char *procout = (char *)wutf8buf;
			writebufpos = 0;

			wutf8buflen = wutf8bufsze;
			do {
				/* iconv updates len and writebuflen */
				iconvret = iconv(iconv_handle_os, &procinp, &inplen,
						&procout, &wutf8buflen);

				if (iconvret == (size_t)-1) {
					switch (errno) {
						case EILSEQ:
							/* byte is invalid, try to step over it,
							 * this shouldn't happen for the input is
							 * generated by iconv itself during input */
							*procout++ = '?';
							procinp++;
							inplen--;
							wutf8buflen--;
							break;
						case EINVAL:
							/* the only valid problem should be the end
							 * of the input being truncated */
							if (inplen < 4 && len != 0) {
								/* shift this so a next attempt can
								 * retry the completion */
								memmove(writebuf, procinp, inplen);
								writebufpos = inplen;
								iconvret = 0;
								break;
							}
						case E2BIG:
							/* output buffer is not large enough, this is
							 * impossible since we allocate 4x */
						default:
							return EOF;
					}
				}
			} while (iconvret == (size_t)-1);

			ret = ::write(fd_os, wutf8buf, procout - (char *)wutf8buf);
		} else {
			ret = len;
		}
	} while (outlen > 0);

	return ret;
}

iconvstream &iconvstream::operator<<(const char *inp)
{
	(void)write(inp, strlen(inp));
	return *this;
}

iconvstream &iconvstream::operator<<(const string &inp)
{
	(void)write(inp.c_str(), inp.length());
	return *this;
}

iconvstream &iconvstream::operator<<(char inp)
{
	(void)write(&inp, inp == '\0' ? 0 : 1);
	return *this;
}
