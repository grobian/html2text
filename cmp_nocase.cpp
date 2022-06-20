/*
 * Copyright (c) 1999
 *      GMRS Software GmbH, Innsbrucker Ring 159, 81669 Munich, Germany.
 *      http://www.gmrs.de
 *      All rights reserved.
 *      Author: Arno Unkrig (arno.unkrig@gmrs.de)
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

#include <ctype.h>

#include "cmp_nocase.h"

int
_cmp_nocase(const char *s1, size_t l1, const char *s2, size_t l2)
{
	const char *e1 = s1 + l1;
	const char *e2 = s2 + l2;

	while (s1 != e1 && s2 != e2) {
		int c1 = toupper(*s1);
		int c2 = toupper(*s2);
		if (c1 < c2)
			return -1;
		if (c1 > c2)
			return 1;
		++s1, ++s2;
	}
	return s1 != e1 ? 1 : s2 != e2 ? -1 : 0;
}
