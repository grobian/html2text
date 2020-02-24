
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

#ifndef __rb_tree_h_INCLUDED__ /* { */
#define __rb_tree_h_INCLUDED__

/* ------------------------------------------------------------------------- */

#ident "$Id: rb_tree.h,v 1.2 1999/11/09 19:54:01 arno Exp $"

#include <sys/types.h>

#include "include/utility"    // For "pair"

#ifdef BOOL_DEFINITION
BOOL_DEFINITION
#undef BOOL_DEFINITION
#endif

/* ------------------------------------------------------------------------- */

class ostream;

class rb_tree {

protected:

  // Protected types

  struct node_type {
    enum color_type { RED, BLACK };

    // Notice: "left" must be the first member, because the "parent" pointer
    // of the top node points to the "root" member of the "rb_tree" object,
    // so that "top->parent->left == top"! This is tricky, but this way
    // "parent" is always non-zero...
    node_type  *left;
    node_type  *right;
    node_type  *parent;
    color_type color;
  };
  typedef void *value_pointer;

  // Types

public:
  typedef size_t size_type;

  // Construct/Copy/Destruct

protected:
  rb_tree() : root(0) {}
  rb_tree(
    const node_type *,
    const node_type *,
    node_type       *(*node_copier)(const node_type *)
  );
  rb_tree(const rb_tree &x) :
    root(x.root ? x.copy_subtree(x.root, end()) : 0)
    {}
//~rb_tree()
//  {}
  const rb_tree &operator=(const rb_tree &);

  // Iterators

  node_type       *begin();
  const node_type *begin() const;
  node_type       *end()
    { return (node_type *) &root; }
  const node_type *end() const
    { return (const node_type *) &root; }

  // Capacity

public:
  bool empty() const
    { return root == 0; }
  size_type size() const { return root ? size(root) : 0; }
  size_type max_size() const { return (size_type) -1; }

  // Modifiers

  node_type *insert(node_type *);
//node_type *insert(node_type *where, node_type *);
  void      insert(const node_type *from, const node_type *to);
  size_type erase_all(value_pointer);
  bool      erase_one(value_pointer);
  node_type *erase(node_type *);
  node_type *erase(node_type *, node_type *);
  void swap(rb_tree &x);
  void clear()
    { if (root) { delete_subtree(root); root = 0; } }

  // Operations.

  node_type *find_first(value_pointer);
  const node_type *find_first(value_pointer vp) const
    { return ((rb_tree *) this)->find_first(vp); }
  node_type *find_any(value_pointer);
  const node_type *find_any(value_pointer vp) const
    { return ((rb_tree *) this)->find_any(vp); }
  size_type count(value_pointer vp) const
    { return root ? count(vp, root) : 0; }
  node_type *lower_bound(value_pointer vp);
  const node_type *lower_bound(value_pointer vp) const
    { return ((rb_tree *) this)->lower_bound(vp); }
  node_type *upper_bound(value_pointer vp);
  const node_type *upper_bound(value_pointer vp) const
    { return ((rb_tree *) this)->upper_bound(vp); }

  bool operator==(const rb_tree &x) const;
  bool operator<(const rb_tree &x) const;

  void check(
    int     *depth_return,
    int     *black_depth_return,
    int     *count_return,
    ostream &os
  ) const
    {
      *count_return = 0;
      check(depth_return, black_depth_return, count_return, root, os);
    }

  // Protected member functions.

protected:
  void                   clear(void (*node_deletor)(node_type *))
    { if (root) { delete_subtree(root, node_deletor); root = 0; } }
public:
  static node_type       *successor(node_type *x)
    { return (node_type *) successor((const node_type *) x); }
  static const node_type *successor(const node_type *);
protected:
  // List-like print-out: "{ nodevalue1, nodevalue2, nodevalue3 }". Calls
  // pure virtual "print_node_value()".
  void print(ostream &os, void *closure) const;
  // Tree-like print-out; rather for debugging. Calls "print_node()", which
  // calls pure virtual "print_node_value()";
  void debug_print(ostream &os, void *closure) const;

  // Virtual member functions to be implemented by derived class

private:
  virtual bool node_less_than(const node_type *x, const node_type *y) const = 0;
  virtual bool node_less_than(value_pointer   x,  const node_type *y) const = 0;
  virtual bool node_less_than(const node_type *x, value_pointer   y ) const = 0;
  virtual void print_node(const node_type &, ostream &, void *closure) const;
  virtual void print_node_value(
    const node_type &,
    ostream         &,
    void            *closure
  ) const = 0;
  virtual node_type *copy_node(const node_type *) const = 0;
  virtual void delete_node(node_type *) const = 0;

  // Private member functions

  static size_type       size(const node_type *);
  size_type              count(value_pointer, const node_type *) const;
  node_type              *copy_subtree(const node_type *n, node_type *pa) const;
  void                   delete_subtree(node_type *);
  static void            delete_subtree(node_type *, void (*)(node_type *));
  void                   print_subtree(
    const node_type *,
    ostream         &,
    int             indent,
    void            *closure
  ) const;
  void                   left_rotate(node_type *);
  void                   right_rotate(node_type *);

  void check(
    int             *depth_return,
    int             *black_depth_return,
    int             *count_in_out,
    const node_type *n,
    ostream         &os
  ) const;

  // Private members.

private:
  node_type *root;
};

/* ------------------------------------------------------------------------- */

#endif /* } */

/* ------------------------------------------------------------------------- */

