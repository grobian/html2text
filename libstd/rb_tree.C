
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

#ident "$Id: rb_tree.C,v 1.2 1999/11/17 21:57:41 arno Exp $"

#include <iostream.h>

#include "rb_tree.h"

#define ASSERT(x) if (!(x)) cerr << __FILE__ << ":" << __LINE__ << ": Assertion failed: " << #x << endl; else

/* ------------------------------------------------------------------------- */

rb_tree::rb_tree(
  const node_type *from,
  const node_type *to,
  node_type       *(*node_copier)(const node_type *)
)
{
  while (from && from != to) {
    insert(node_copier(from));
    from = successor(from);
  }
}

/*
 * Returns "end()" if tree is empty.
 */
rb_tree::node_type *
rb_tree::begin()
{
  node_type *n = end();
  while (n->left) n = n->left;
  return n;
}

const rb_tree::node_type *
rb_tree::begin() const
{
  const node_type *n = end();
  while (n->left) n = n->left;
  return n;
}

/*
 * Finds the first node that matches.
 * Returns "end()" if key cannot be found.
 */
rb_tree::node_type *
rb_tree::find_first(value_pointer vp)
{
  node_type *n = lower_bound(vp);
  return n == end() || node_less_than(vp, n) ? end() : n;
} 

/*
 * Finds any of the nodes that match.
 * Returns "end()" if key cannot be found.
 * Notice that this function is faster than "find_first()".
 */
rb_tree::node_type *
rb_tree::find_any(value_pointer vp)
{
  node_type *n = root;

  while (n) {
    if (node_less_than(vp, n)) {
      n = n->left;
    } else
    if (node_less_than(n, vp)) {
      n = n->right;
    } else {
      return n;
    }
  }

  return end();
} 

/*static*/ rb_tree::size_type
rb_tree::size(const node_type *n)
{
  return (
    (n->left  ? size(n->left ) : 0) +
    1 +
    (n->right ? size(n->right) : 0)
  );
}

rb_tree::size_type
rb_tree::count(value_pointer vp, const node_type *n) const
{
  if (node_less_than(n, vp)) return n->right ? count(vp, n->right) : 0;
  if (node_less_than(vp, n)) return n->left  ? count(vp, n->left ) : 0;
  return (
    1 +
    (n->left  ? count(vp, n->left ) : 0) +
    (n->right ? count(vp, n->right) : 0)
  );
}

/*
 * Returns "end()" if tree is less than the tree.
 */
rb_tree::node_type *
rb_tree::lower_bound(value_pointer vp)
{
  if (!root) return end();

  node_type *n = root;
  node_type *res = end();

  for (;;) {
    while (node_less_than(n, vp)) {
      n = n->right;
      if (!n) return res;
    }
    for (;;) {
      if (!n->left) return n;
      if (node_less_than(n->left, vp)) {
        res = n;
        n = n->left;
        break;
      }
      n = n->left;
    }
  }
}

rb_tree::node_type *
rb_tree::upper_bound(value_pointer vp)
{
  if (!root) return end();

  node_type *n = root;
  node_type *res = end();

  for (;;) {
    while (!node_less_than(vp, n)) {
      n = n->right;
      if (!n) return res;
    }
    for (;;) {
      if (!n->left) return n;
      if (!node_less_than(vp, n->left)) {
        res = n;
        n = n->left;
        break;
      }
      n = n->left;
    }
  }
}

void
rb_tree::check(
  int             *depth_return,
  int             *black_depth_return,
  int             *count_in_out,
  const node_type *n,
  ostream         &os
) const
{
  if (!n) { *depth_return = *black_depth_return = 0; return; }

  if (n->parent == end()) {
    if (root != n) os << "Inconsistent root pointer" << endl;
    if (n->color != node_type::BLACK) os << "Top node is not black" << endl;
  }

  // "n->parent->left == n" should also be true for the top node!
  if (n->parent->left != n && n->parent->right != n) {
    os << "Node is not child of its parent" << endl;
  }

  (*count_in_out)++;

  int ld, rd, lbd, rbd;

  if (n->left) {
    if (n->color == node_type::RED && n->left->color == node_type::RED) {
      os << "Red node has red left child" << endl;
    }
    check(&ld, &lbd, count_in_out, n->left, os);
  } else {
    ld = 0;
  }
  if (n->right) {
    if (n->color == node_type::RED && n->right->color == node_type::RED) {
      os << "Red node has red right child" << endl;
    }
    check(&rd, &rbd, count_in_out, n->right, os);
  } else {
    rd = 0;
  }
  *depth_return = 1 + (ld > rd ? ld : rd);
  if (n->left && n->right && lbd != rbd) {
    os << "Inconsistent black depth" << endl;
  }
  *black_depth_return = (
    (n->color == node_type::BLACK) +
    (n->left ? lbd : n->right ? rbd : 0)
  );
}

/*
 * This function has two modes of operation:
 *
 * (A) indent == -1:
 *        Print like
 *
 *                nodevalue1, nodevalue2, nodevalue3
 *
 *        Notice the ascending order.
 *        Notice that only the node *values* are printed, not the other node
 *        members like "left", "right", "parent", "color".
 *
 * (B) indent >= 0:
 *        Print a tree-like structure; one line per node, like:
 *
 *                    node1
 *                  node2
 *                    node3
 *                node4
 *                    node5
 *                  node6
 *                    node7
 *
 *        Notice that the entire nodes are printed, i.e. "left", "right",
 *        "parent", "color", "value".
 *        Notice that this only yields nice results if "operator<<(os, value)"
 *        does not generate any newline characters.
 */
void
rb_tree::print_subtree(
  const node_type *n,
  ostream         &os,
  int             indent,
  void            *closure
) const
{
  ASSERT(n);
  if (indent == -1) {
    if (n->left) { print_subtree(n->left, os, -1, closure); os << ", "; }
    print_node_value(*n, os, closure);
    if (n->right) { os << ", "; print_subtree(n->right, os, -1, closure); }
  } else {
    if (n->left) print_subtree(n->left, os, indent + 1, closure);
    for (int i = 0; i < indent; ++i) os << "  ";
    print_node(*n, os, closure); os << endl;
    if (n->right) print_subtree(n->right, os, indent + 1, closure);
  }
}

/*
 * Warning: Calls pure virtual method "copy_node()".
 */
rb_tree::node_type *
rb_tree::copy_subtree(const node_type *n1, node_type *pa) const
{
  ASSERT(n1);
  node_type *n2 = copy_node(n1);
  n2->left   = n1->left  ? copy_subtree(n1->left,  n2) : 0;
  n2->right  = n1->right ? copy_subtree(n1->right, n2) : 0;
  n2->parent = pa;
  n2->color  = n1->color;
  return n2;
}

/*
 * Warning: Calls pure virtual method "delete_node()".
 * Notice: Does not invalidate the "n->parent"'s reference to "n".
 */
void
rb_tree::delete_subtree(node_type *n)
{
  if (n->left ) delete_subtree(n->left );
  if (n->right) delete_subtree(n->right);
  delete_node(n);
}

/*
 * May be called from the destructor, because no pure virtual functions are
 * called.
 * Notice: Does not invalidate the "n->parent"'s reference to "n".
 */
/*static*/ void
rb_tree::delete_subtree(node_type *n, void (*node_deletor)(node_type *))
{
  if (n->left ) delete_subtree(n->left,  node_deletor);
  if (n->right) delete_subtree(n->right, node_deletor);
  node_deletor(n);
}

/*
 * Only "node_less_than()" must work for "x", i.e. "x"'s value must be set;
 * all other member are explicitly set here.
 */

/*
 * Case 1:
 *
 *        BLACK              x-> RED        (Continue with new "x".)
 *        /   \                 /   \
 *      RED   RED    ===>   BLACK   BLACK
 *       |                    |
 *  x-> RED                  RED
 *
 * --------------------------------------------------------------------
 *
 * Case 2:
 *
 *             F-BLACK                         D-BLACK      (Done.)
 *            /       \                        /     \
 *       B-RED     G-BLACK-opt   ===>     B-RED       F-RED
 *      /     \                           /   \       /   \
 *   A-opt     D-RED <-x               A-opt C-opt E-opt G-BLACK-opt
 *             /   \
 *          C-opt E-opt
 *
 * --------------------------------------------------------------------
 *
 * Case 3:
 *
 *              F-BLACK                        D-BLACK      (Done.)
 *              /     \                        /     \
 *          D-RED     G-BLACK-opt ===>    B-RED       F-RED
 *          /   \                         /   \       /   \
 *  x-> B-RED   E-opt                  A-opt C-opt E-opt G-BLACK-opt
 *      /   \
 *   A-opt C-opt
 *
 * (These cases apply for "parent(x) == left_child(grandparent(x))"; otherwise
 * mirror the diagrams.)
 */

rb_tree::node_type *
rb_tree::insert(node_type *x)
{
  x->left  = 0;
  x->right = 0;

  if (empty()) {
    x->parent = end();
    x->color = node_type::BLACK;
    root = x;
    return x;
  }

  x->color = node_type::RED;
  node_type *y = root;
  for (;;) {
    if (node_less_than(x, y)) {
      if (!y->left) { y->left = x; x->parent = y; break; }
      y = y->left;
    } else {
      if (!y->right) { y->right = x; x->parent = y; break; }
      y = y->right;
    }
  }

  node_type *saved_x = x;

  /*
   * Rebalance the tree from "x" to "root".
   */
  while (x->parent->color == node_type::RED) {
    ASSERT(x);
    ASSERT(x != end());
    ASSERT(x->color == node_type::RED);
    ASSERT(x->parent != end());
    ASSERT(x->parent->color == node_type::RED);
    ASSERT(x->parent->parent != end());
    ASSERT(x->parent->parent->color == node_type::BLACK);

    node_type *pa = x->parent;
    node_type *gp = pa->parent;

    ASSERT(x ->color == node_type::RED);
    ASSERT(pa->color == node_type::RED);
    ASSERT(gp->color == node_type::BLACK);

    node_type *uncle;
    if (pa == gp->left) {

      /*
       * Parent is left child of grandparent.
       */
      uncle = gp->right;               // May be 0
      if (!uncle || uncle->color == node_type::BLACK) {
        if (pa->right == x) {

          /*
           * X is right child of parent.
           */
          if (x->left) x->left->parent = pa;          // Case 2
          pa->right = x->left;
          x->left = pa;
          pa->parent = x;
          pa = x;
        }
        if (pa->right) pa->right->parent = gp;        // Case 3
        pa->parent = gp->parent;
        if (gp == gp->parent->left) {
          gp->parent->left = pa;
        } else {
          gp->parent->right = pa;
        }
        gp->parent = pa;
        gp->left = pa->right;
        pa->right = gp;
        pa->color = node_type::BLACK;
        gp->color = node_type::RED;
        break;
      }
    } else {

      /*
       * Parent is right child of grandparent.
       */
      uncle = gp->left;               // May be 0
      if (!uncle || uncle->color == node_type::BLACK) {
        if (pa->left == x) {

          /*
           * X is left child of parent.
           */
          if (x->right) x->right->parent = pa;        // Case 2
          pa->left = x->right;
          x->right = pa;
          pa->parent = x;
          pa = x;
        }
        if (pa->left) pa->left->parent = gp;          // Case 3
        pa->parent = gp->parent;
        if (gp == gp->parent->left) {
          gp->parent->left = pa;
        } else {
          gp->parent->right = pa;
        }
        gp->parent = pa;
        gp->right = pa->left;
        pa->left = gp;
        pa->color = node_type::BLACK;
        gp->color = node_type::RED;
        break;
      }
    }

    pa   ->color = node_type::BLACK;                  // Case 1
    uncle->color = node_type::BLACK;

    if (gp == root) break;

    gp->color = node_type::RED;
    x = gp;
  }

  return saved_x;
}

void
rb_tree::insert(const node_type *from, const node_type *to)
{
  while (from && from != to) {
    insert(copy_node(from));
    from = successor(from);
  }
}

/*
 * Erase all matching nodes. Return number of nodes erased.
 */
rb_tree::size_type
rb_tree::erase_all(value_pointer vp)
{
  size_type count = 0;

  for (
    node_type *z = lower_bound(vp);
    z != end() && !node_less_than(vp, z);
    z = erase(z), ++count
  );
  return count;
}

/*
 * Erase one of the matching nodes. Return "false" if no node matches.
 */
bool
rb_tree::erase_one(value_pointer vp)
{
  node_type *z = find_any(vp);
  if (z == end()) return false;
  erase(z);
  return true;
}

rb_tree::node_type *
rb_tree::erase(node_type *z)
{
  if (z == end()) return end();

  ASSERT(z);
  ASSERT(z != end());

  node_type *succ = successor(z);               // May be "end()"
  node_type *y = z->left && z->right ? succ : z;

  ASSERT(y);
  ASSERT(y != end());
  ASSERT(!(y->left && y->right));

  node_type *x = y->left ? y->left : y->right;  // May be 0.
  node_type *x_parent = y->parent;              // May be "end()"

  /*
   * Isolate "y".
   */
  if (x) x->parent = x_parent;

  if (x_parent->left == y) {
    x_parent->left = x;
  } else {
    x_parent->right = x;
  }
  node_type::color_type old_color = y->color;

  /*
   * Implant "y" in place of "z"; this isolates "z".
   */
  if (y != z) {

    /*
     * Instead of copying the value, change all the links.
     */
    y->parent = z->parent;
    y->left   = z->left;
    y->right  = z->right;
    y->color  = z->color;
    if (z->parent->left == z) {
      z->parent->left = y;
    } else {
      z->parent->right = y;
    }
    if (z->left) z->left->parent = y;
    if (z->right) z->right->parent = y;
    if (x_parent == z) x_parent = y;
  }

  delete_node(z);

  /*
   * Check if fixup is necessary...
   */
  if (old_color == node_type::RED) return succ;

  while (x != root && (!x || x->color == node_type::BLACK)) {
    ASSERT(x_parent != end());
    if (x == x_parent->left) {
      node_type *sibling = x_parent->right;
      ASSERT(sibling);
      if (sibling->color == node_type::RED) {               // Case 1
        sibling->color = node_type::BLACK;
        x_parent->color = node_type::RED;
        left_rotate(x_parent);
        ASSERT(x_parent);
        ASSERT(x_parent != end());
        sibling = x_parent->right;
      }
      ASSERT(sibling);
      ASSERT(sibling != end());
      if (
        (!sibling->left || sibling->left->color == node_type::BLACK) &&
        (!sibling->right || sibling->right->color == node_type::BLACK)
      ) {                                                   // Case 2
        sibling->color = node_type::RED;
        x = x_parent;
        ASSERT(x_parent);
        ASSERT(x_parent != end());
        x_parent = x_parent->parent;
      } else {
        if (
          !sibling->right ||
          sibling->right->color == node_type::BLACK
        ) {                                                 // Case 3
          ASSERT(sibling);
          ASSERT(sibling != end());
          ASSERT(sibling->left);
          /*if (sibling->left)*/ sibling->left->color = node_type::BLACK;
          sibling->color = node_type::RED;
          right_rotate(sibling);
          ASSERT(x_parent);
          ASSERT(x_parent != end());
          sibling = x_parent->right;
        }
        ASSERT(x_parent);
        ASSERT(x_parent != end());
        sibling->color = x_parent->color;                   // Case 4
        x_parent->color = node_type::BLACK;
        ASSERT(sibling);
        ASSERT(sibling->right);
        /*if (sibling->right)*/ sibling->right->color = node_type::BLACK;
        left_rotate(x_parent);
        break;
      }
    } else {     // x->parent()->right == x
      node_type *sibling = x_parent->left;
      ASSERT(sibling);
      if (sibling->color == node_type::RED) {               // Case 1
        sibling->color = node_type::BLACK;
        x_parent->color = node_type::RED;
        right_rotate(x_parent);
        ASSERT(x_parent);
        ASSERT(x_parent != end());
        sibling = x_parent->left;
      }
      ASSERT(sibling);
      if (
        (!sibling->right || sibling->right->color == node_type::BLACK) &&
        (!sibling->left || sibling->left->color == node_type::BLACK)
      ) {                                                   // Case 2
        sibling->color = node_type::RED;
        x = x_parent;
        ASSERT(x_parent);
        ASSERT(x_parent != end());
        x_parent = x_parent->parent;
      } else {
        ASSERT(sibling);
        ASSERT(sibling != end());
        if (
          !sibling->left ||
          sibling->left->color == node_type::BLACK
        ) {                                                 // Case 3
          ASSERT(sibling->right);
          /*if (sibling->right)*/ sibling->right->color = node_type::BLACK;
          sibling->color = node_type::RED;
          left_rotate(sibling);
          ASSERT(x_parent);
          ASSERT(x_parent != end());
          sibling = x_parent->left;
        }
        ASSERT(x_parent);
        ASSERT(x_parent != end());
        sibling->color = x_parent->color;                   // Case 4
        x_parent->color = node_type::BLACK;
        ASSERT(sibling);
        ASSERT(sibling != end());
        ASSERT(sibling->left);
        /*if (sibling->left)*/ sibling->left->color = node_type::BLACK;
        right_rotate(x_parent);
        break;
      }
    }
  }

  ASSERT(x != end());
  if (x) x->color = node_type::BLACK;
  return succ;
}

/*
 * Erase all nodes from "n1" (inclusive) to "n2" (exclusive). "n1" may only be
 * "end()" if "n2" is also "end()".
 */
rb_tree::node_type *
rb_tree::erase(node_type *n1, node_type *n2)
{
  while (n1 != n2) n1 = erase(n1);
  return n1;
}

void
rb_tree::swap(rb_tree &x)
{

  /*
   * Swap pointers to root node.
   */
  node_type *tmp = root;
  root = x.root;
  x.root = tmp;

  /*
   * Fix up parent pointers of root nodes.
   */
  if (root) root->parent = end();
  if (x.root) x.root->parent = x.end();
}

/*
 * Returns "end()" if "x" was the last node.
 */
/*static*/ const rb_tree::node_type *
rb_tree::successor(const node_type *x)
{
  if (x->right) {
    x = x->right;
    while (x->left) x = x->left;
    return x;
  } else {
    for (;;) {
      if (x == x->parent->left) return x->parent;
      x = x->parent;
    }
  }
}

void
rb_tree::print(ostream &os, void *closure) const
{
  if (root) {
    os << "{ "; print_subtree(root, os, -1, closure); os << " }";
  } else {
    os << "{}";
  }
}

void
rb_tree::debug_print(ostream &os, void *closure) const
{
  if (root) print_subtree(root, os, 0, closure);
}


// "x" must have a right child, but not necessarily a parent.
void
rb_tree::left_rotate(node_type *x)
{
  ASSERT(x);
  ASSERT(x->right);

  node_type *y = x->right;          // set temporary y

  x->right = y->left;               // y's left is x's right
  if (y->left) y->left->parent = x; // link y->left's parent to x
  y->parent = x->parent;            // link x's parent to y
  if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;                      // x is left child of y
  x->parent = y; 
}

// "x" must have a left child, but not necessarily a parent.
void
rb_tree::right_rotate(node_type *x)
{
  ASSERT(x);
  ASSERT(x->left);

  node_type* y = x->left;             // set temporary y

  x->left = y->right;                 // x's left is y's right
  if (y->right) y->right->parent = x; // link y->right's parent to x
  y->parent = x->parent;              // link y's parent to x
  if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->right = x;                       // x is right child of y
  x->parent = y;
} 

/*virtual*/ void
rb_tree::print_node(const node_type &n, ostream &os, void *closure) const
{
  os << "value=";
  print_node_value(n, os, closure);
  os << ", left=";
  if (n.left) { print_node_value(*n.left, os, closure); } else { os << "0"; }
  os << ", right=";
  if (n.right) { print_node_value(*n.right, os, closure); } else { os << "0"; }

  os << ", color=" << (n.color == node_type::RED ? "RED" : "BLACK");
  os << ", parent=";
  if (n.parent == end()) {
    os << "TOP";
  } else {
    print_node_value(*n.parent, os, closure);
  }
}

/* ------------------------------------------------------------------------- */

