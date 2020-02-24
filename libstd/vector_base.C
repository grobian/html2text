
/* ------------------------------------------------------------------------- */

/*
 * Copyright (c) 1999
 *      GMRS Software GmbH, Innsbrucker Ring 159, 81669 Munich, Germany.
 *      http://www.gmrs.de
 *      All rights reserved.
 *      Author: Arno Unkrig (arno.unkrig@gmrs.de)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by GMRS Software GmbH.
 * 4. The name of GMRS Software GmbH may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GMRS SOFTWARE GMBH ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GMRS SOFTWARE GMBH BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/* ------------------------------------------------------------------------- */

#ident "$Id: vector_base.C,v 1.1 1999/10/26 10:57:28 arno Exp $"

#include <stdlib.h>
#include <iostream.h>

#include "vector_base.h"

/* ------------------------------------------------------------------------- */

/*
 * The minimum number of elements in a vector; in other words: If the vector
 * is not empty, then it reserves space for at least that many elements. Must
 * be a power of two.
 * As the vector grows beyond its limit, its size is doubled.
 */

#define MIN_SIZE 4

/* ------------------------------------------------------------------------- */

vector_base::vector_base(
  size_t                    element_size,
  size_type                 n,
  value_default_constructor c
) {
  init(element_size, n);
  for (char *q = p; n; --n, q += element_size) c(q);
}

vector_base::vector_base(
  size_t                 element_size,
  size_type              n,
  value_copy_constructor c,
  void                   *value
) {
  init(element_size, n);
  for (char *q = p; n; --n, q += element_size) c( /*that*/ q, value);
}

vector_base::vector_base(
  size_t                 element_size,
  value_copy_constructor c,
  char                   *from,
  char                   *to
) {
  size_type n = (to - from) / element_size;
  init(element_size, n);
  for (char *q = p; n; --n, q += element_size, from += element_size) {
    c( /*that*/ q, from);
  }
}

vector_base::~vector_base() {
  free(p);
}

void
vector_base::assign(size_t element_size, char *from, char *to) {
  clear(element_size);
  size_type n = (to - from) / element_size;
  init(element_size, n);
  for (char *q = p; n; --n, q += element_size, from += element_size) {
    construct_value(q, from);
  }
}

void
vector_base::assign(size_t element_size, size_type n) {
  clear(element_size);
  init(element_size, n);
  for (char *q = p; n; --n, q += element_size) construct_value(q);
}

void
vector_base::assign(size_t element_size, size_type n, void *v) {
  clear(element_size);
  init(element_size, n);
  for (char *q = p; n; --n, q += element_size) construct_value(q, v);
}

void
vector_base::resize(size_t element_size, size_type n) {
  if (n > size1) {
    reserve(element_size, n);
    char *from = p + element_size * size1;
    char *to   = p + element_size * n;
    for (char *q = from; q < to; q += element_size) construct_value(q);
  } else {
    char *from = p + element_size * n;
    char *to   = p + element_size * size1;
    for (char *q = from; q < to; q += element_size) destruct_value(q);
  }
  size1 = n;
}

void
vector_base::resize(size_t element_size, size_type n, void *v) {
  if (n > size1) {
    reserve(element_size, n);
    char *from = p + element_size * size1;
    char *to   = p + element_size * n;
    for (char *q = from; q < to; q += element_size) construct_value(q, v);
  } else {
    char *from = p + element_size * n;
    char *to   = p + element_size * size1;
    for (char *q = from; q < to; q += element_size) destruct_value(q);
  }
  size1 = n;
}

/*
 * If "iter_in_out != 0", assume that "*iter_in_out" is an iterator in this
 * vector, and correct it while new elements are "reserve()"ed.
 */
void
vector_base::reserve(
  size_t    element_size,
  size_type n,
  char      **iter_in_out /*= 0*/
) {
  if (n <= size2) return;

  size_type m;
  for (m = MIN_SIZE; m < n; m <<= 1);
  char *p2 = (char *) malloc(element_size * m);
  if (!p2) abort();
  char *q1 = p, *q2 = p2;
  for (int i = 0; i < size1; ++i, q1 += element_size, q2 += element_size) {
    construct_value(q2, q1);
    destruct_value(q1);
  }
  if (iter_in_out) *iter_in_out += p2 - p;
  free(p);
  p = p2;
  size2 = m;
}

void
vector_base::push_back(size_t element_size, void *v) {
  reserve(element_size, size1 + 1);
  construct_value(p + element_size * size1, v);
  ++size1;
}

void
vector_base::pop_back(size_t element_size) {
  if (size1 == 0) abort();
  --size1;
  destruct_value(p + element_size * size1);
}

void *
vector_base::insert(size_t element_size, char *pos) {
  if (size1 == size2) reserve(element_size, size1 + 1, &pos);
  char *end = p + element_size * size1;
  if (pos == end) {
    construct_value(pos);
  } else {
    construct_value(end, end - element_size);
    for (char *q = end - element_size; q != pos; q -= element_size) {
      assign_value(q, q - element_size);
    }
    assign_value(pos);
  }
  ++size1;
  return pos;
}

void *
vector_base::insert(size_t element_size, char *pos, void *v) {
  if (size1 == size2) reserve(element_size, size1 + 1, &pos);
  char *end = p + element_size * size1;
  if (pos == end) {
    construct_value(pos, v);
  } else {
    construct_value(end, end - element_size);
    for (char *q = end - element_size; q != pos; q -= element_size) {
      assign_value(q, q - element_size);
    }
    assign_value(pos, v);
  }
  ++size1;
  return pos;
}

void
vector_base::insert(size_t element_size, char *pos, size_type n, void *v) {
  if (size1 + n > size2) reserve(element_size, size1 + n, &pos);
  char *end = p + element_size * size1;
  char *q = end - element_size;
  char *r = q + element_size * n;
  while (q >= pos && r >= end) {
    construct_value(r, q);
    r -= element_size;
    q -= element_size;
  }
  while (q >= pos) {
    assign_value(r, q);
    r -= element_size;
    q -= element_size;
  }
  while (r >= end) { construct_value(r, v); r -= element_size; }
  while (r >= pos) { assign_value(r, v); r -= element_size; }
  size1 += n;
}

void
vector_base::insert(size_t element_size, char *pos, char *from, char *to) {
  size_type n = (to - from) / element_size;
  if (size1 + n > size2) reserve(element_size, size1 + n, &pos);
  char *end = p + element_size * size1;
  char *q = end - element_size;
  char *r = q + element_size * n;
  while (q >= pos && r >= end) {
    construct_value(r, q);
    r -= element_size;
    q -= element_size;
  }
  while (q >= pos) {
    assign_value(r, q);
    r -= element_size;
    q -= element_size;
  }
  while (r >= end) {
    to -= element_size;
    construct_value(r, to);
    r -= element_size;
  }
  while (r >= pos) {
    to -= element_size;
    assign_value(r, to);
    r -= element_size;
  }
  size1 += n;
}

void *
vector_base::erase(size_t element_size, char *pos) {
  char *pos2 = pos;
  char *end = p + element_size * --size1;
  while (pos2 < end) {
    assign_value(pos2, pos2 + element_size);
    pos2 += element_size;
  }
  destruct_value(pos2);
  return pos;
}

void *
vector_base::erase(size_t element_size, char *from, char *to) {
  char *res = from;
  char *end = p + element_size * size1;
  size1 -= (to - from) / element_size;
  while (to < end) {
    assign_value(from, to);
    from += element_size;
    to += element_size;
  }
  while (from < end) {
    destruct_value(from);
    from += element_size;
  }
  return res;
}

void
vector_base::swap(vector_base &x) {
  size_type size1_tmp = size1;
  size_type size2_tmp = size2;
  char      *p_tmp    = p;
  size1 = x.size1;
  size2 = x.size2;
  p     = x.p;
  x.size1 = size1_tmp;
  x.size2 = size2_tmp;
  x.p     = p_tmp;
}

void
vector_base::clear(size_t element_size) {
  char *q = p;
  for (size_type i = 0; i < size1; q += element_size, ++i) {
    destruct_value(q);
  }
  size1 = 0;
}

void
vector_base::clear(size_t element_size, value_destructor d) {
  char *q = p;
  for (size_type i = 0; i < size1; q += element_size, ++i) d(q);
  size1 = 0;
}

/* ------------------------------------------------------------------------- */

void
vector_base::init(size_t element_size, size_type n) {
  size1 = n;
  for (size2 = MIN_SIZE; size2 < n; size2 <<= 1);
  p = (char *) malloc(element_size * size2);
  if (!p) abort();
}

// Need to use a function pointer because we don't "operator==(T, T)" to be
// a member function.
bool
vector_base::equals(
  size_t            element_size,
  const vector_base &y,
  value_comparator  value_equals
) const {
  if (size1 != y.size1) return false;
  char *xp = p, *xend = p + size1 * element_size;
  char *yp = y.p, *yend = y.p + y.size1 * element_size;
  for (;;) {
    if (xp >= xend) return yp >= yend;
    if (yp >= yend) return false;
    if (!value_equals(xp, yp)) return false;
    xp += element_size;
    yp += element_size;
  }
}

// Need to use a function pointer because we don't "operator<(T, T)" to be
// a member function.
bool
vector_base::less_than(
  size_t            element_size,
  const vector_base &y,
  value_comparator  value_less_than
) const {
  char *xp = p, *xend = p + size1 * element_size;
  char *yp = y.p, *yend = y.p + y.size1 * element_size;
  for (;;) {
    if (xp >= xend) return yp < yend;
    if (yp >= yend) return true;
    if (value_less_than(xp, yp)) return true;
    xp += element_size;
    yp += element_size;
  }
}

void
vector_base::print(size_t element_size, ostream &os, void *closure) const {
  os << "[ ";
  char *q = p;
  for (size_type i = 0; i < size1; ++i, q += element_size) {
    os << "[" << i << "]=";
    print_value(os, q, closure);
    os << " ";
  }
  os << "]";
}

/* ------------------------------------------------------------------------- */

