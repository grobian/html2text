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

#ifndef __auto_ptr_h_INCLUDED__ /* { */
#define __auto_ptr_h_INCLUDED__

/*
 * Yet another implementation of the "auto_ptr" template... I am not sure
 * if the standard does specify "auto_ptr", and how, but this implementation
 * uses a scheme *without* an "owns" flag: When the ownership is taken away
 * from the "auto_ptr", its pointer *is set to 0*! This may seem odd, but
 * in practice, it saves you from problems because such an "auto_ptr" can
 * never be dangling, only "0", which is checked in "operator*()" and
 * "operator->()". I never found this scheme limiting.
 */

#include <stdlib.h>

template <class T>
class auto_ptr {

public:

  // Constructor/copy/destroy

  explicit auto_ptr(T *x = 0) : p(x) {}
  auto_ptr(const auto_ptr<T> &x) : p(x.p) { ((auto_ptr<T> *) &x)->p = 0; }
  void operator=(const auto_ptr<T> &x)
  { delete p; p = x.p; ((auto_ptr<T> *) &x)->p = 0; }
  ~auto_ptr() { delete p; }

  // Members

  T    &operator*() const  { if (!p) abort(); return *(T *) p; }
  T    *operator->() const { if (!p) abort(); return (T *) p; }
  T    *get() const        { return (T *) p; }
  T    *release()          { T *tmp = p; p = 0; return tmp; }
  void reset(T *x = 0)     { delete p; p = x; }

private:
  T *p;
};

#endif /* } */
