
/***************************************************************************/

/*
 * Portions Copyright (c) 1999 GMRS Software GmbH
 * Carl-von-Linde-Str. 38, D-85716 Unterschleissheim, http://www.gmrs.de
 * All rights reserved.
 *
 * Author: Arno Unkrig <arno@unkrig.de>
 */

/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License in the file COPYING for more details.
 */

/***************************************************************************/

/*
 * Changes to version 1.2.2 were made by Martin Bayer <mbayer@zedat.fu-berlin.de>
 * Dates and reasons of modifications:
 * Thu Oct  4 21:49:09 CEST 2001: ported to g++ 3.0
 * Sun Apr  7 11:59:03 CEST 2002: Handle URLs with missing node
 * Mon Jul 22 13:53:02 CEST 2002: Made finaly reading from STDIN work.
 */

/***************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "urlistream.h"

using std::ios;

void
urlistream::open(const char *url, const char *encoding)
{
	if (is_open())
		close();

	file_open(url);
}

void
urlistream::open(const string &url, const char *encoding)
{
	open(url.c_str(), encoding);
}

/* ------------------------------------------------------------------------- */

void
urlistream::file_open(const char *file_name)
{
	fd_ = !strcmp(file_name, "-") ? ::dup(0) : ::open(file_name, O_RDONLY);
	open_error_ = strerror(errno);
}

/* ------------------------------------------------------------------------- */

const char *
urlistream::open_error() const
{
	return open_error_ ? open_error_ : "No error";
}

/* ------------------------------------------------------------------------- */

int
urlistream::get()
{
	unsigned char ch;
	int ret = ::read(fd_, &ch, 1);
	return ret > 0 ? ch : -1;
}

/* ------------------------------------------------------------------------- */
