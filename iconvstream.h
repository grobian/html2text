/*
 * Copyright 2020-2025 Fabian Groffen <grobian@gentoo.org>
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

#ifndef ICONVSTREAM_H
#define ICONVSTREAM_H 1

#include <fstream>
#include <string>
#include <unistd.h>
#include <iconv.h>

using std::string;

const char endl = '\n';
const char flush = '\0';

class iconvstream {
	public:
		iconvstream():
			open_err(0),
			fd_is(-1),
			fd_os(-1)
		{
		}
		~iconvstream()
		{
			if (find_tokens_c_str_buf != nullptr)
				delete[] find_tokens_c_str_buf;
		}

		void open_is(const char *url, const char *encoding);
		void open_is(const string &url, const char *encoding);
		void close_is(void);
		void open_os(const char *url, const char *encoding);
		void open_os(const string &url, const char *encoding);
		void close_os(void);
		int is_open() const
		{
			return fd_is >= 0;
		}
		int os_open() const
		{
			return fd_os >= 0;
		}
		void close()
		{
			close_is();
			close_os();
		}
		bool os_isatty() const
		{
			return fd_os >= 0 ? (isatty(fd_os) ? true : false) : false;
		}
		const char *open_error_msg() const;
		int get();
		int write(const char *inp, size_t len);
		iconvstream &operator<<(const char *inp);
		iconvstream &operator<<(const string &inp);
		iconvstream &operator<<(char inp);

	private:
		const char* find_tokens(char*, size_t, const char**);
		char *find_tokens_c_str_buf = nullptr;

		const char *open_err;
		const char *encoding;

		int fd_is;
		iconv_t iconv_handle_is = nullptr;
		unsigned char *readbuf = nullptr;
		size_t readbufsze;
		size_t readbuflen;
		size_t readbufpos;
		unsigned char *rutf8buf = nullptr;
		size_t rutf8bufsze;
		size_t rutf8buflen;
		size_t rutf8bufpos;

		int fd_os;
		iconv_t iconv_handle_os = nullptr;
		unsigned char *writebuf = nullptr;
		size_t writebufsze;
		size_t writebuflen;
		size_t writebufpos;
		unsigned char *wutf8buf = nullptr;
		size_t wutf8bufsze;
		size_t wutf8buflen;
		size_t wutf8bufpos;
};

#endif
