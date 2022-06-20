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

#ifndef __sgml_h_INCLUDED__ /* { */
#define __sgml_h_INCLUDED__ /* { */

#include "istr.h"

/*
 * Replace SGML entities like "&auml;" and "&#233;" within "*s".
 */
extern void replace_sgml_entities(istr *s);

#endif /* } */
