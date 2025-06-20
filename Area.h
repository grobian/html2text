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

#ifndef __Area_h_INCLUDED__ /* { */
#define __Area_h_INCLUDED__

#include <sys/types.h>
#include <string>
#include "iconvstream.h"
#include "istr.h"

using std::string;

struct Cell {
	int  character;
	char attribute;

	/* these are the decoration properties */
	enum {
		NONE            = 0<<0,
		UNDERLINE       = 1<<0,
		BOLD            = 1<<1,
		STRIKETHROUGH   = 1<<2,
		FGCOLOUR        = 1<<3,
		BGCOLOUR        = 1<<4,
		ITALICS         = 1<<5,
		COLOUR          = FGCOLOUR | BGCOLOUR
	};

	/* 8-bit colours */
	unsigned char fgcolour;
	unsigned char bgcolour;

	enum {
		/* standard */
		BLACK     =  0,
		RED       =  1,
		GREEN     =  2,
		YELLOW    =  3,
		BLUE      =  4,
		MAGENTA   =  5,
		CYAN      =  6,
		WHITE     =  7,
		/* intense (bright) */
		BRBLACK   =  8,
		BRRED     =  9,
		BRGREEN   = 10,
		BRYELLOW  = 11,
		BRBLUE    = 12,
		BRMAGENTA = 13,
		BRCYAN    = 14,
		BRWHITE   = 15,
		/* 216 colours: 16 + 36 * r + 6 * g + b */
		/* shades of grey: 233-255 */
		DKGREY    = 238,
		GREY      = 244,
		BRGREY    = 250
	};

	void clear()
	{
		character = ' ';
		attribute = NONE;
		fgcolour  = 0;
		bgcolour  = 0;
	}
};

class Line {
	public:
		typedef size_t size_type;

		Line(size_type l = 0);
		Line(const char *);
		Line(const string &);
		Line(const istr &);
		~Line();

		size_type length() const
		{
			return length_;
		}
		bool      empty()  const
		{
			return length_ == 0;
		}

		const Cell &operator[](size_type x) const
		{
			return cells_[x];
		}
		Cell       &operator[](size_type x)
		{
			return cells_[x];
		}
		const Cell *cells() const
		{
			return cells_;
		}

		void resize(size_type l);
		void enlarge(size_type l)
		{
			if (l > length_)
				resize(l);
		}

		void insert(const Line &, size_type x);
		void insert(const char *, size_type x);
		void insert(const string &, size_type x);

		void append(char c);
		void append(const Line &l);
		void append(const char *p);

		const Line &operator+=(char c)
		{
			append(c);
			return *this;
		}
		const Line &operator+=(const Line &l)
		{
			append(l);
			return *this;
		}
		const Line &operator+=(const char *p)
		{
			append(p);
			return *this;
		}

		void set_bgcolour(unsigned char clr);
		void set_fgcolour(unsigned char clr);
		void add_attribute(char addition);

	private:
		Line(const Line &);
		const Line &operator=(const Line &);

		size_type length_;
		Cell      *cells_;

		friend class Area;
};

class Area {
	public:
		typedef size_t size_type;

		enum {
			LEFT, CENTER, RIGHT,
			TOP, MIDDLE, BOTTOM
		};

		Area();
		Area(size_type w, size_type h = 0, char = ' ', char = Cell::NONE);
		Area(const char *);
		Area(const string &);
		Area(const Line &);
		Area(const istr &);
		~Area();

		size_type width() const
		{
			return width_;
		}
		size_type height() const
		{
			return height_;
		}

		const Cell *operator[](size_type y) const
		{
			return cells_[y];
		}
		Cell       *operator[](size_type y)
		{
			return cells_[y];
		}
		const Area &operator>>=(size_type rs);
		const Area &operator>>=(const char *prefix);

		void resize(size_type w, size_type h);
		void enlarge(size_type w, size_type h);

		void insert(const Line &l, size_type x, size_type y)
		{
			insert(l.cells_, l.length_, x, y);
		}
		void insert(const Area &, size_type x, size_type y);
		void insert(
				const Area &,
				size_type x,
				size_type y,
				size_type w,
				size_type h,
				int halign,
				int valign
				);
		void insert(const Cell &, size_type x, size_type y);
		void insert(const Cell *, size_type count, size_type x, size_type y);
		void insert(char, size_type x, size_type y);
		void insert(const string &, size_type x, size_type y);
		void prepend(int n);      // Prepend blank lines at top
		void append(int n)        // Append blank lines at bottom
		{
			enlarge(width(), height() + n);
		}
		const Area &operator+=(const Area &);     // Append at bottom!
		const Area &operator+=(int n)
		{
			append(n);
			return *this;
		}

		void fill(const Cell &, size_type x, size_type y, size_type w, size_type h);
		void fill(char, size_type x, size_type y, size_type w, size_type h);

		void set_bgcolour(unsigned char clr);
		void set_fgcolour(unsigned char clr);
		void add_attribute(char addition);   // ...but not to left and right free areas
		void add_attribute(
				char addition,
				size_type x,
				size_type y,
				size_type w,
				size_type h
				);

		/* see Area.cpp for the defaults for the below variables */
		static bool            use_backspaces;
		static bool            use_ansi;
		static Area::size_type widthsize;
		static Area::size_type heightsize;

	private:
		Area(const Area &);
		const Area &operator=(const Area &);

		size_type width_;
		size_type height_;
		Cell      **cells_;

		friend iconvstream &operator<<(iconvstream&, const Area &);
};

#endif /* } */
