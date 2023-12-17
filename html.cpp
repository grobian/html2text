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

#include <stdlib.h>
#include <stdarg.h>

#include "html.h"
#include "HTMLParser.hh"
#include "cmp_nocase.h"
#include "iconvstream.h"

/*
 * Some C++ compilers (e.g. EGCS 2.91.66) have problems if all virtual
 * methods of a class are inline or pure virtual, so we define the virtual
 * "Element::~Element()", which is the only virtual method, non-inline,
 * although it is empty.
 */
Element::~Element()
{}

istr
get_attribute(
	const list<TagAttribute> *as,
	const char               *name,
	const char               *dflt
	)
{
	if (as) {
		list<TagAttribute>::const_iterator i;
		for (i = as->begin(); i != as->end(); ++i) {
			if (cmp_nocase((*i).first, name) == 0)
				return (*i).second;
		}
	}
	return istr(dflt);
}

// *exists is set to false if attribute *name does not exist - Johannes Geiger
istr
get_attribute(
	const list<TagAttribute> *as,
	const char               *name,
	bool                     *exists
	)
{
	*exists = true;
	if (as) {
		list<TagAttribute>::const_iterator i;
		for (i = as->begin(); i != as->end(); ++i) {
			if (cmp_nocase((*i).first, name) == 0)
				return (*i).second;
		}
	}
	*exists = false;
	return istr("");
}

int
get_attribute(
	const list<TagAttribute> *as,
	const char               *name,
	int dflt
	)
{
	if (as) {
		list<TagAttribute>::const_iterator i;
		for (i = as->begin(); i != as->end(); ++i) {
			if (cmp_nocase((*i).first, name) == 0)
				return atoi((*i).second.c_str());
		}
	}
	return dflt;
}

int
get_attribute(
	const list<TagAttribute> *as,
	const char               *name,
	int dflt,
	const char               *s1,
	int v1,
	...
	)
{
	if (as) {
		list<TagAttribute>::const_iterator i;
		for (i = as->begin(); i != as->end(); ++i) {
			if (cmp_nocase((*i).first, name) == 0) {
				const char *s = s1;
				int v = v1;

				va_list va;
				va_start(va, v1);
				for (;;) {
					if (cmp_nocase(s, (*i).second.c_str()) == 0)
						break;
					s = va_arg(va, const char *);
					if (!s) {
						v = dflt;
						break;
					}
					v = va_arg(va, int);
				}
				va_end(va);
				return v;
			}
		}
	}
	return dflt;
}

int
get_attribute(
	const list<TagAttribute> *as,
	const char               *name, // Attribute name
	const char               *dflt1,// If attribute not specified
	int dflt2,                      // If string value does not match s1, ...
	const char               *s1,
	int v1,
	...
	)
{
	if (as) {
		list<TagAttribute>::const_iterator i;
		for (i = as->begin(); i != as->end(); ++i) {
			if (cmp_nocase((*i).first, name) == 0) {
				dflt1 = (*i).second.c_str();
				break;
			}
		}
	}

	if (!dflt1)
		return dflt2;

	const char *s = s1;
	int v = v1;

	va_list va;
	va_start(va, v1);
	for (;;) {
		if (cmp_nocase(s, dflt1) == 0)
			break;
		s = va_arg(va, const char *);
		if (!s)
			break;
		v = va_arg(va, int);
	}
	va_end(va);

	return s ? v : dflt2;
}

/**
 * Return a styling property from the embedded style attribute, falling
 * back to the given attribute, if possible.
 * This is meant for retrieval of properties such as colour, width, etc.
 */
auto_ptr<list<istr>>
get_style_attr
(
	const list<TagAttribute> *attrs,
	const char               *style_name,
	const char               *attr_name,
	const char               *dflt
)
{
	bool   iskey    = true;
	size_t keystart = 0;
	size_t valstart = 0;
	size_t t;
	istr   style    = get_attribute(attrs, "STYLE", "");

	auto_ptr<list<istr>> ret;
	ret.reset(new list<istr>);

	if (style != NULL && style_name != NULL) {
		for (size_t i = 0; i < style.length(); i++) {
			switch (style[i]) {
				case ':':
					/* keystart:i = key */
					for (t = i - 1; style[t] == ' '; t--)
						;
					t++;
					iskey = false;
					valstart = i + 1;
					break;
				case ';':
					/* end of value */
					if (!iskey) {
						if (style.compare(keystart, t - keystart,
										  style_name) == 0)
						{
							list<istr>::const_iterator it;
							size_t lastsp = valstart - 1;
							for (t = i - 1; style[t] == ' '; t--)
								;
							t++;
							for (size_t p = valstart; p < t; p++) {
								if (style[p] == ' ') {
									if (p - 1 == lastsp) {
										lastsp = p;
										continue;
									}
									ret.get()->push_back(
											style.slice(lastsp + 1,
														p - valstart));
								}
							}
							if (t > lastsp + 1)
								ret.get()->push_back(
										style.slice(lastsp + 1,
													t - valstart));

							/* weed out cruft we don't support anyway */
							for (it = ret.get()->begin();
								 it != ret.get()->end();
								 it++)
							{
								const istr &s(*it);
								if (s.iequals("!important"))
									ret.get()->erase(it);
							}

							/* we're done */
							i = style.length();
							break;
						}
					}
					keystart = i + 1;
					iskey = true;
					break;
				case ' ':
					if (keystart == i)
						keystart++;
					if (valstart == i)
						valstart++;
					break;
			}
		}
	}

	if (ret.get()->empty() && attr_name != NULL)
		ret.get()->push_back(get_attribute(attrs, attr_name, dflt));

	if (ret.get()->empty())
		ret.get()->push_back(istr(dflt));

	return ret;
}
