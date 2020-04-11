
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
 * Thu Oct  4 21:50:51 CEST 2001: ported to g++ 3.0
 * Sun Apr  7 12:00:50 CEST 2002: Handle URLs with missing node
 * Wed Jul  2 22:08:05 CEST 2003: ported to g++ 3.3
 * Tue Nov 11 21:11:51 CET 2003: fd_ might be uninitialized
 */

/***************************************************************************/


#ifndef __urlistream_h_INCLUDED__ /* { */
#define __urlistream_h_INCLUDED__

/* ------------------------------------------------------------------------- */

#include <fstream>
#include <string>
#include <unistd.h>

using std::string;

/* ------------------------------------------------------------------------- */

/*
 * Similar to an "ifstream", but "open()" is overloaded: allow a
 * conversion to take place.
 */
class urlistream /* : public ifstream */ {
public:

urlistream() : open_error_(0), fd_(-1)
{}

void open(const char *url, const char *encoding);
void open(const string &url, const char *encoding);
int is_open() const
{
	return fd_ > 0;
}
void close()
{
	::close(fd_);
}
const char *open_error() const;
int get();

private:
void file_open(const char *file_name);

const char *open_error_;
int fd_;
};

/* ------------------------------------------------------------------------- */

#endif /* } */

/* ------------------------------------------------------------------------- */

