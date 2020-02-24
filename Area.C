
 /***************************************************************************/

/*
 * Portions Copyright (c) 1999 GMRS Software GmbH
 * Carl-von-Linde-Str. 38, D-85716 Unterschleissheim, http://www.gmrs.de
 *      All rights reserved.
 *
 * Author: Arno Unkrig <arno@unkrig.de>
 */
 
/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License in the file COPYING for more details.
 */

 /***************************************************************************/

/*
 * Changes to version 1.2.2 were made by Martin Bayer <mbayer@zedat.fu-berlin.de>
 * Dates and reasons of modifications:
 * Wed Jul  2 21:56:45 CEST 2003: ported to g++ 3.3
 */

 /***************************************************************************/


#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "Area.h"
#include "string.h"

#define LATIN1_nbsp 160

/* ------------------------------------------------------------------------- */

#define malloc_array(type, size)\
((type *) malloc(sizeof(type) * (size)))
#define realloc_array(array, type, size) \
((array) = (type *) realloc((array), sizeof(type) * (size)))
#define copy_array(from, to, type, count) \
((void) memcpy((to), (from), (count) * sizeof(type)))

/* ------------------------------------------------------------------------- */

Line::Line(size_type l) : length_(l), cells_(malloc_array(Cell, l))
{
  Cell *p, *end = cells_ + l;
  for (p = cells_; p != end; p++) p->clear();
}

Line::Line(const char *p) :
  length_(strlen(p)),
  cells_(malloc_array(Cell, length_))
{
  Cell *q = cells_, *end = q + length_;
  while (q != end) { q->character = *p++; q->attribute = Cell::NONE; q++; }
}

Line::Line(const string &s) :
  length_(s.length()),
  cells_(malloc_array(Cell, length_))
{
  const char *p = s.c_str();
  Cell *q = cells_, *end = q + length_;
  while (q != end) { q->character = *p++; q->attribute = Cell::NONE; q++; }
}

Line::~Line()
{
  free(cells_);
}

/* ------------------------------------------------------------------------- */

void
Line::resize(size_type l)
{
  if (l == length()) return;
  realloc_array(cells_, Cell, l);
  for (size_type x = length(); x < l; x++) cells_[x].clear();
  length_ = l;
}

void
Line::insert(const Line &l, size_type x)
{
  enlarge(x + l.length());
  const Cell *p = l.cells_, *end = p + l.length();
  Cell       *q = cells_ + x;
  while (p != end) *q++ = *p++;
}

void
Line::insert(const char *p, size_type x)
{
  enlarge(x + strlen(p));
  Cell *q = cells_ + x;
  while (*p) q++->character = *p++;
}

void
Line::insert(const string &s, size_type x)
{
  insert(s.c_str(), x);
}

void
Line::append(char c)
{
  size_type x = length_;
  resize(x + 1);
  cells_[x].character = c;
  cells_[x].attribute = Cell::NONE;
}

void
Line::append(const Line &l)
{
  size_type x = length_;
  enlarge(x + l.length_);
  const Cell *p = l.cells_, *end = p + l.length();
  Cell       *q = cells_ + x;
  while (p != end) *q++ = *p++;
}

void
Line::append(const char *p)
{
  size_type x = length_;
  enlarge(x + strlen(p));
  Cell *q = cells_ + x;
  for (; *p; ++p, ++q) { q->character = *p; q->attribute = Cell::NONE; }
}

void
Line::add_attribute(char addition)
{
  Cell *p = cells_, *end = cells_ + length_;

  while(p != end) p++->attribute |= addition;
}

/* ------------------------------------------------------------------------- */

bool Area::use_backspaces = true;

/* ------------------------------------------------------------------------- */

Area::Area() :
  width_(0),
  height_(0),
  cells_(malloc_array(Cell *, 0))
{
}

Area::Area(
  size_type w /*= 0*/ ,
  size_type h /*= 0*/ ,
  char      c /*= ' '*/ ,
  char      a /*= Cell::NONE*/
) :
  width_(w),
  height_(h),
  cells_(malloc_array(Cell *, h))
{
  for (size_type y = 0; y < h; y++) {
    Cell *p = cells_[y] = malloc_array(Cell, w), *end = p + w;
    while (p != end) { p->character = c; p->attribute = a; p++; }
  }
}

Area::Area(const char *p) :
  width_(strlen(p)),
  height_(1),
  cells_(malloc_array(Cell *, 1))
{
  cells_[0] = malloc_array(Cell, width_);
  Cell *q = cells_[0], *end = q + width_;
  while (q != end) { q->character = *p++; q->attribute = Cell::NONE; q++; }
}

Area::Area(const string &s) :
  width_(s.length()),
  height_(1),
  cells_(malloc_array(Cell *, 1))
{
  cells_[0] = malloc_array(Cell, width_);
  Cell *q = cells_[0];
  for (string::size_type i = 0; i < s.length(); ++i) {
    q->character = s[i];
    q->attribute = Cell::NONE;
    q++;
  }
}

Area::Area(const Line &l) :
  width_(l.length_),
  height_(1),
  cells_(malloc_array(Cell *, 1))
{
  cells_[0] = malloc_array(Cell, width_);
  copy_array(l.cells_, cells_[0], Cell, width_);
}

Area::~Area()
{
  for (size_type y = 0; y < height(); y++) free(cells_[y]);
  free(cells_);
}

/* ------------------------------------------------------------------------- */

const Area &
Area::operator>>=(size_type rs)
{
  if (rs > 0) {
    resize(width_ + rs, height_);
    for (size_type y = 0; y < height_; y++) {
      Cell *c = cells_[y];
      memmove(c + rs, c, (width_ - rs) * sizeof(Cell));
      for (size_type x = 0; x < rs; x++) {
        c[x].character = ' ';
        c[x].attribute = Cell::NONE;
      }
    }
  }
  return *this;
}

void
Area::resize(size_type w, size_type h)
{
  size_type y_max = h < height() ? h : height();

  if (w > width()) {
    for (size_type y = 0; y < y_max; y++) {
      realloc_array(cells_[y], Cell, w);
      Cell *p = cells_[y] + width(), *end = cells_[y] + w;
      while (p != end) p++->clear();
    }
  } else
  if (w < width()) {
    for (size_type y = 0; y < y_max; y++) {
      realloc_array(cells_[y], Cell, w);
    }
  }

  if (h > height()) {
    realloc_array(cells_, Cell *, h);
    for (size_type y = height(); y < h; y++) {
      Cell *p = cells_[y] = malloc_array(Cell, w), *end = p + w;
      while (p != end) p++->clear();
    }
  } else
  if (h < height()) {
    for (size_type y = h; y < height(); y++) free(cells_[y]);
    realloc_array(cells_, Cell *, h);
  }

  width_ = w;
  height_ = h;
}

void
Area::enlarge(size_type w, size_type h)
{
  if (w > width() || h > height()) {
    resize(w > width() ? w : width(), h > height() ? h : height());
  }
}

void
Area::insert(const Area &a, size_type x, size_type y)
{
  enlarge(x + a.width(), y + a.height());

  for (size_type i = 0; i < a.height(); i++) {
    const Cell *p = a.cells_[i], *end = p + a.width();
    Cell       *q = cells_[y + i] + x;
    while (p != end) *q++ = *p++;
  }
}

void
Area::insert(
  const Area &a,
  size_type  x,
  size_type  y,
  size_type  w,
  size_type  h,
  int        halign,
  int        valign
)
{
  if (halign != LEFT && a.width() < w) x += (
    halign == CENTER ? (w - a.width()) / 2 :
    halign == RIGHT  ? w - a.width()       :
    0
  );
  if (valign != TOP && a.height() < h) y += (
    valign == MIDDLE ? (h - a.height()) / 2 :
    valign == BOTTOM ? h - a.height()       :
    0
  );
  insert(a, x, y);
}

void
Area::insert(const Cell &c, size_type x, size_type y)
{
  enlarge(x + 1, y + 1);
  cells_[y][x] = c;
}

void
Area::fill(const Cell &c, size_type x, size_type y, size_type w, size_type h)
{
  enlarge(x + w, y + h);
  for (size_type yy = y; yy < y + h; yy++) {
    Cell *p = &cells_[yy][x];
    for (size_type i = 0; i < w; i++) *p++ = c;
  }
}

void
Area::insert(const Cell *p, size_type count, size_type x, size_type y)
{
  enlarge(x + count, y + 1);
  Cell *q = &cells_[y][x];
  while (count--) *q++ = *p++;
}

void
Area::insert(char c, size_type x, size_type y)
{
  enlarge(x + 1, y + 1);
  cells_[y][x].character = c;
}

void
Area::insert(const string &s, size_type x, size_type y)
{
  enlarge(x + s.length(), y + 1);
  Cell *cell = &cells_[y][x];
  for (string::size_type i = 0; i < s.length(); i++) {
    cell->character = s[i];
    cell->attribute = Cell::NONE;
    cell++;
  }
}

void
Area::prepend(int n)
{
  if (n <= 0) return;

  realloc_array(cells_, Cell *, height() + n);
  memmove(cells_ + n, cells_, height() * sizeof(*cells_));
  for (int y = 0; y < n; ++y) {
    Cell *p = cells_[y] = malloc_array(Cell, width()), *end = p + width();
    while (p != end) p++->clear();
  }
  height_ += n;
}

const Area &
Area::operator+=(const Area &x)
{
  insert(x, 0, height());
  return *this;
}

void
Area::fill(char c, size_type x, size_type y, size_type w, size_type h)
{
  enlarge(x + w, y + h);
  for (size_type yy = y; yy < y + h; yy++) {
    Cell *p = &cells_[yy][x];
    for (size_type i = 0; i < w; i++) p++->character = c;
  }
}

void
Area::add_attribute(char addition)
{
  for (size_type y = 0; y < height(); y++) {
    Cell *p = cells_[y], *end = p + width();
    while (p != end && p->character == ' ') ++p;
    Cell *q = p;
    while (p != end) {
      if (p++->character != ' ') {
	while (q < p) q++->attribute |= addition;
      }
    }
  }
}

void
Area::add_attribute(
  char      addition,
  size_type x,
  size_type y,
  size_type w,
  size_type h
)
{
  enlarge(x + w, y + h);
  for (size_type yy = y; yy < y + h; yy++) {
    Cell *p = &cells_[yy][x], *end = p + w;
    while (p != end) p++->attribute |= addition;
  }
}

/* ------------------------------------------------------------------------- */

ostream &backspace(ostream &os) { return os << '\b'; }

ostream &
operator<<(ostream &os, const Area &a)
{
  for (Area::size_type y = 0; y < a.height(); y++) {
    const Cell *cell = a.cells_[y], *end = cell + a.width();
    while (
      end != cell &&
      end[-1].character == ' ' &&
      (end[-1].attribute & (Cell::UNDERLINE | Cell::STRIKETHROUGH)) == 0
    ) end--;

    for (const Cell *p = cell; p != end; p++) {
      char c = p->character;
      char a = p->attribute;

      if (c == (char) LATIN1_nbsp) c = ' ';

      if (a == Cell::NONE) {
        os << c;
      } else {
	if (Area::use_backspaces) {

          /*
           * No LESS / terminal combination that I know of supports
           * dash-backspace-character as "strikethrough". Pity.
           */
          if (a & Cell::STRIKETHROUGH) os << '-' << backspace;

          /*
           * No LESS that I know of can combine underlining and boldface. In
           * practice, boldface always takes precedence.
	   *
           * It's not a good idea to optimize an underlined space as a single
           * underscore (as opposed to underscore-backspace-space) -- this
           * would not look nice next to an underlined character.
           */
          if ((a & Cell::UNDERLINE)            ) os << '_' << backspace;
          if ((a & Cell::BOLD     ) && c != ' ') os << c   << backspace;
          os << c;
        } else {
	  os << (c == ' ' && (a & Cell::UNDERLINE) ? '_' : c);
	}
      }
    }
    os << std::endl;
  }

  return os;
}

/* ------------------------------------------------------------------------- */

