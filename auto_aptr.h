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

#ifndef __auto_aptr_h_INCLUDED__ /* { */
#define __auto_aptr_h_INCLUDED__

/*
 * This template class is very similar to the standard "auto_ptr", but it is
 * used for *array* pointers rather than *object* pointers, i.e. the pointer
 * passed to it must have been allocated with "new[]", and "auto_aptr" will
 * delete it with "delete[]".
 */

#include <stdlib.h>

template <class T>
class auto_aptr {
public:

// Constructor/copy/destroy

auto_aptr() : p(0)
{}
auto_aptr(T *x) : p(x)
{}
auto_aptr(const auto_aptr<T> &x) : p(x.p)
{
	((auto_aptr<T> *) &x)->p = 0;
}
void operator=(const auto_aptr<T> &x)
{
	delete[] p;
	p = x.p;
	((auto_aptr<T> *) &x)->p = 0;
}
// Extension: "operator=(T *)" is identical to "auto_aptr::reset(T *)".
void operator=(T *x)
{
	delete[] p;
	p = x;
}
~auto_aptr()
{
	delete[] p;
}

// Members

T    &operator[](size_t idx) const
{
	if (!p)
		abort();
	return p[idx];
}
T    *get() const
{
	return (T *) p;
}
T    *release()
{
	T *tmp = p;
	p = 0;
	return tmp;
}
void reset(T *x = 0)
{
	delete[] p;
	p = x;
}

// These would make a nice extension, but are not provided by many other
// implementations.
//operator const void *() const { return p; }
//int operator!() const { return p == 0; }

private:
T *p;
};

#endif /* } */
