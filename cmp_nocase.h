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

#ifndef __cmp_nocase_h_INCLUDED__ /* { */
#define __cmp_nocase_h_INCLUDED__

#include <string.h>
#include <string>

using std::string;

/*
 * The Standard C++ library is lacking a case-insensitive string comparison
 * function... so I define my own, adapting Stroustrup's ("The C++ Programming
 * Language", 3rd edition).
 */

// Helper
extern int _cmp_nocase(const char *s1, size_t l1, const char *s2, size_t l2);

// -1: s1 < s2; 0: s1 == s2, 1: s1 > s2
inline int cmp_nocase(const string &s1, const string &s2)
{
	return _cmp_nocase(s1.data(), s1.length(), s2.data(), s2.length());
}
inline int cmp_nocase(const char   *s1, const string &s2)
{
	return _cmp_nocase(s1, strlen(s1), s2.data(), s2.length());
}
inline int cmp_nocase(const string &s1, const char   *s2)
{
	return _cmp_nocase(s1.data(), s1.length(), s2, strlen(s2));
}
inline int cmp_nocase(const char   *s1, const char   *s2)
{
	return _cmp_nocase(s1, strlen(s1), s2, strlen(s2));
}

#endif /* } */
