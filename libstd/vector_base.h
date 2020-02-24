
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

#ifndef __vector_base_h_INCLUDED__ /* { */
#define __vector_base_h_INCLUDED__

/* ------------------------------------------------------------------------- */

#ident "$Id: vector_base.h,v 1.1 1999/10/26 10:57:30 arno Exp $"

#include <sys/types.h>

#ifdef BOOL_DEFINITION
BOOL_DEFINITION
#undef BOOL_DEFINITION
#endif

class ostream;

/* ------------------------------------------------------------------------- */

class vector_base {

public:
  typedef size_t size_type;

protected:
  typedef void (*value_default_constructor)(void *that);
  typedef void (*value_copy_constructor)(void *that, void *v);
  typedef void (*value_destructor)(void *that);

protected:

  // Construct/Copy/Destroy

  vector_base() : p(0), size1(0), size2(0) {}
  vector_base(size_t element_size, size_type n, value_default_constructor c);
  vector_base(
    size_t                 element_size,
    size_type              n,
    value_copy_constructor c,
    void                   *value
  );
  vector_base(
    size_t                 element_size,
    value_copy_constructor c,
    char                   *from,
    char                   *to
  );
  ~vector_base();
  void assign(size_t element_size, char *from, char *to);
  void assign(size_t element_size, size_type n);
  void assign(size_t element_size, size_type n, void *v);

  // Capacity

public:
  size_type size() const { return size1; }
  size_type max_size() const { return (size_type) -1; }
protected:
  void resize(size_t element_size, size_type n);
  void resize(size_t element_size, size_type n, void *v);
public:
  size_type capacity() const { return size2; }
  bool empty() const { return size1 == 0; }
protected:
  void reserve(size_t element_size, size_type n, char **iter_in_out = 0);

  // Modifiers

  void push_back(size_t element_size, void *v);
  void pop_back(size_t element_size);
  void *insert(size_t element_size, char *pos);
  void *insert(size_t element_size, char *pos, void *v);
  void insert(size_t element_size, char *pos, size_type n, void *v);
  void insert(size_t element_size, char *pos, char *from, char *to);
  void *erase(size_t element_size, char *pos);
  void *erase(size_t element_size, char *from, char *to);
  void swap(vector_base &x);
  void clear(size_t element_size);
  void clear(size_t element_size, value_destructor d);

protected:
  virtual void construct_value(void *that) = 0;
  virtual void construct_value(void *that, void *v) = 0;
  virtual void destruct_value(void *that) = 0;
  virtual void assign_value(void *to) = 0;
  virtual void assign_value(void *to, void *from) = 0;
  virtual void print_value(ostream &os, void *v, void *closure) const = 0;

  void init(size_t element_size, size_type n);
  typedef bool (*value_comparator)(void *, void *);
  bool equals(
    size_t            element_size, 
    const vector_base &y, 
    value_comparator  value_equals
  ) const;
  bool less_than(
    size_t            element_size,
    const vector_base &y,
    value_comparator  value_less_than
  ) const;
  void print(size_t element_size, ostream &os, void *closure) const;

  char      *p;
  size_type size1;
  size_type size2;
};

/* ------------------------------------------------------------------------- */

#endif /* } */

/* ------------------------------------------------------------------------- */

