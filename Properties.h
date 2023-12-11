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

#ifndef __Properties_h_INCLUDED__ /* { */
#define __Properties_h_INCLUDED__

#include <string>
#include <map>
#include <istream>

using std::string;
using std::map;
using std::istream;

class Properties {
public:
const char *getProperty(const char *key, const char *dflt) const;
const char *getProperty(const char *key) const;
void       setProperty(const string &key, const string &value)
{
	property_map[key] = value;
}
void       setProperty(const char   *key, const string &value)
{
	property_map[key] = value;
}
void       setProperty(const string &key, const char   *value)
{
	property_map[key] = value;
}
void       setProperty(const char   *key, const char   *value)
{
	property_map[key] = value;
}

// Read from file.
void load(istream &);

private:
static bool readProperty(
	istream &is,
	string  *key_return,
	string  *value_return
	);
map<string, string> property_map;
};

#endif /* } */
