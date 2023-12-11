/*
 * Portions Copyright (c) 1999 GMRS Software GmbH
 * Carl-von-Linde-Str. 38, D-85716 Unterschleissheim, http://www.gmrs.de
 * All rights reserved.
 *
 * Author: Arno Unkrig <arno@unkrig.de>
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

#ifndef __format_h_INCLUDED__ /* { */
#define __format_h_INCLUDED__

#include <string>
#include <vector>
#include <istream>

using std::string;
using std::vector;
using std::istream;

class Formatting {
public:
static void            setProperty(const char *key, const char *value);
static void            loadProperties(istream &is);

static const char     *getString(const char *key, const char *dflt);
static const char     *getString(const char *key);
static vector<string> *getStringVector(const char *key, const char *dflt);
static int             getInt(const char *key, int dflt);
static vector<int>    *getIntVector(const char *key, const char *dflt);
static char            getAttributes(const char *key, char dflt);
static int             colour_from_string(const char *clrc);
static Area::size_type get_width(const list<TagAttribute> *, Area::size_type w);
static void            set_fgcolour(const list<TagAttribute> *, Area *);
static void            set_bgcolour(const list<TagAttribute> *, Area *);
static void            set_fgcolour(const list<TagAttribute> *, Line *);
static void            set_bgcolour(const list<TagAttribute> *, Line *);

private:
Formatting();      // Do not instantiate me!
};

#endif /* } */
