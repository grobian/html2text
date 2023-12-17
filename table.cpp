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

/*
 * "Table::format()" has been taken out of "format.C" because it is way more
 * complex than the "format()" methods of the other HTML elements.
 */

#include <iostream>
#include <cmath>
#include "html.h"
#include "auto_aptr.h"
#include "format.h"

// Should be local to "Table::format()", but CFRONT can't handle this.
struct LogicalCell {
	const TableCell *cell;    // Points to the parsed cell..
	int x, y;                 // Position of cell in table.
	int w, h;                 // COLSPAN/ROWSPAN of cell.
	int halign;
	int valign;
	Area::size_type width;    // Current contents width.
	Area::size_type minwidth; // Minimal contents width.
	bool minimized;           // Cannot be narrowed any more.
	auto_ptr<Area>  area;     // Formatted cell -- computed at a late stage.
};

/*
 * Correct x and y of the logical cells according to the other cells' ROWSPAN
 * and COLSPAN.
 */
static void
correct_xy(
	list<auto_ptr<LogicalCell>> *const lcs_in_out,
	int                         *const number_of_rows_in_out,
	int                         *const number_of_columns_in_out
	)
{
	list<auto_ptr<LogicalCell>>::iterator i;
	for (i = lcs_in_out->begin(); i != lcs_in_out->end(); ++i) {
		const LogicalCell *const p = (*i).get();
		if (p->w != 1 || p->h != 1) {
			list<auto_ptr<LogicalCell> >::iterator j;
			for (j = i, ++j; j != lcs_in_out->end(); ++j) {
				LogicalCell *const q = (*j).get();
				if (q->y != p->y)
					break;
				q->x += p->w - 1;
			}
			for (; j != lcs_in_out->end(); ++j) {
				LogicalCell *const q = (*j).get();
				if (q->y >= p->y + p->h)
					break;
				if (q->x >= p->x)
					q->x += p->w;
			}
		}
		if (p->x + p->w > *number_of_columns_in_out)
			*number_of_columns_in_out = p->x + p->w;
		if (p->y + p->h > *number_of_rows_in_out)
			*number_of_rows_in_out = p->y + p->h;
	}
}

static void
create_lcs(
	const Table                 &t,
	const Area::size_type        w,
	const Area::size_type        left_border_width,
	const Area::size_type        right_border_width,
	const Area::size_type        column_spacing,
	list<auto_ptr<LogicalCell>> *const lcs_return,
	int                         *const number_of_rows_return,
	int                         *const number_of_columns_return
	)
{
	*number_of_rows_return    = 0;
	*number_of_columns_return = 0;

	const list<auto_ptr<TableRow>>           &rl(*t.rows);
	list<auto_ptr<TableRow>>::const_iterator  ri;
	int y;

	for (ri = rl.begin(), y = 0; ri != rl.end(); ++ri, ++y) {
		if (!(*ri).get())
			continue;

		const TableRow &row(**ri);
		int             row_halign;
		int             row_valign;

		istr align = get_style_attr(row.attributes.get(),
									"text-align", "ALIGN", "").get()->front();
		if (align.iequals("center"))
			row_halign = Area::CENTER;
		else if (align.iequals("right"))
			row_halign = Area::RIGHT;
		else
			row_halign = Area::LEFT;

		align = get_style_attr(row.attributes.get(),
							   "vertical-align", "VALIGN", "").get()->front();
		if (align.iequals("top"))
			row_valign = Area::TOP;
		else if (align.iequals("bottom"))
			row_valign = Area::BOTTOM;
		else
			row_valign = Area::MIDDLE;

		const list<auto_ptr<TableCell>>          &cl(*row.cells);
		list<auto_ptr<TableCell>>::const_iterator ci;
		int x;

		for (ci = cl.begin(), x = 0; ci != cl.end(); ++ci, ++x) {
			if (!(*ci).get())
				continue;
			const TableCell &cell(**ci);

			auto_ptr<LogicalCell> p(new LogicalCell);
			p->cell = &cell;
			p->x = x;
			p->y = y;
			p->w = get_attribute(cell.attributes.get(), "COLSPAN", 1);
			p->h = get_attribute(cell.attributes.get(), "ROWSPAN", 1);
			if (p->w < 1)
				p->w = 1;
			if (p->h < 1)
				p->h = 1;
			if (x + p->w > *number_of_columns_return)
				*number_of_columns_return = x + p->w;
			if (y + p->h > *number_of_rows_return)
				*number_of_rows_return = y + p->h;

			align = get_style_attr(cell.attributes.get(),
								   "text-align", "ALIGN", "").get()->front();
			if (align.iequals("center"))
				p->halign = Area::CENTER;
			else if (align.iequals("right"))
				p->halign = Area::RIGHT;
			else if (align.iequals("left"))
				p->halign = Area::LEFT;
			else
				p->halign = row_halign;

			align = get_style_attr(cell.attributes.get(),
							   	   "vertical-align",
							   	   "VALIGN", "").get()->front();
			if (align.iequals("top"))
				p->valign = Area::TOP;
			else if (align.iequals("bottom"))
				p->valign = Area::BOTTOM;
			else if (align.iequals("middle"))
				p->valign = Area::MIDDLE;
			else
				p->valign = row_valign;

			Area::size_type wanted_width   =
				Formatting::get_width(cell.attributes.get(), w);
			Area::size_type colspace_width =
				(*number_of_columns_return - 1) * column_spacing;

			if (wanted_width == 0)
				wanted_width = w;

			if (wanted_width >= left_border_width)
				wanted_width -= left_border_width;
			else
				wanted_width = 0;
			if (wanted_width >= right_border_width)
				wanted_width -= right_border_width;
			else
				wanted_width = 0;
			if (wanted_width >= colspace_width)
				wanted_width -= colspace_width;
			else
				wanted_width = 0;

			if (wanted_width == 0)
				wanted_width = (left_border_width +
								right_border_width +
								colspace_width);

			/* render LEFT for width, we need the space estimation, not
			 * some padding at this point */
			auto_ptr<Area> tmp(cell.format(wanted_width, Area::LEFT));
			p->width     = tmp.get() ? tmp->width() : 0;
			p->minwidth  = 0;
			p->minimized = p->width == 0;

			lcs_return->push_back(p);
		}
	}

	correct_xy(lcs_return, number_of_rows_return, number_of_columns_return);
}

static void
compute_widths(
	const list<auto_ptr<LogicalCell>> &lcs,
	const int                          number_of_columns,
	const Area::size_type              column_spacing,
	const Area::size_type              left_border_width,
	const Area::size_type              right_border_width,
	Area::size_type                   *const table_width_return,
	Area::size_type                   *const column_widths_return
	)
{
	/* compute the column widths */
	for (int x = 0; x < number_of_columns; x++) {
		list<auto_ptr<LogicalCell>>::const_iterator i;
		column_widths_return[x] = 0;
		for (i = lcs.begin(); i != lcs.end(); i++) {
			Area::size_type width;
			const LogicalCell &lc(**i);
			if (x != lc.x + lc.w - 1)
				continue;  /* cell does not end at this column */
			width = lc.width;
			for (int j = lc.x; j < x; j++) {
				if (column_widths_return[j] + column_spacing >= width) {
					width = 0;
				} else {
					width -= column_widths_return[j] + column_spacing;
				}
			}
			if (width >= column_widths_return[x])
				column_widths_return[x] = width;
		}
	}

	/* compute the table width */
	*table_width_return = (
		left_border_width
		+ (number_of_columns - 1) * column_spacing
		+ right_border_width
		);

	for (int x = 0; x < number_of_columns; x++)
		*table_width_return += column_widths_return[x];
}

/*
 * Examine the table for the widest column that can be narrowed. (A column
 * cannot be narrowed if its widest cell cannot be narrowed.) Return "false"
 * if none of the columns can be narrowed. Otherwise, attempt to narrow that
 * column and update "lcs_in_out", "column_widths_in_out", and
 * "table_width_in_out".
 */
static bool
narrow_table(
	list<auto_ptr<LogicalCell>> *const lcs_in_out,
	const int                    number_of_columns,
	const Area::size_type        column_spacing,
	Area::size_type             *const column_widths_in_out,
	Area::size_type             *const table_width_in_out,
	const Area::size_type        wanted_size
)
{
	int    maxcolspan      =  1;
	int    span;
	int    i;
	bool   ret;

	const list<auto_ptr<LogicalCell>>           &lcl = *lcs_in_out;
	LogicalCell                                  lc;
	list<auto_ptr<LogicalCell>>::const_iterator  c;

	Area::size_type  newtablesize;
	Area::size_type  waste;
	Area::size_type  wantedspace;
	Area::size_type  totcolwidth;
	Area::size_type  totcolneedsize;
	Area::size_type  totcolcursize;
	Area::size_type  colneedsizes[number_of_columns];
	Area::size_type  colcursizes[number_of_columns];

	if (wanted_size >= *table_width_in_out)
		return false;

	/* look at columns which are already minimised, therefore locked to
	 * their narrowest state */
	for (i = 0; i < number_of_columns; i++) {
		colneedsizes[i] = 0;
		colcursizes[i]  = 0;
	}
	for (c = lcl.begin(); c != lcl.end(); c++) {
		lc = **c;

		{
			Area::size_type cw = 0;

			for (int j = lc.x; j < lc.x + lc.w; j++)
				cw += column_widths_in_out[j];

			if (cw < lc.width) {
				/* compute size with current width */
				auto_ptr<Area> tmp(lc.cell->format(cw, Area::LEFT));

				if (tmp.get())
					lc.width = tmp->width();
			}
		}

		if (!lc.minimized && lc.minwidth == 0) {
			/* compute absolute minimum width */
			auto_ptr<Area> tmp(lc.cell->format(1, Area::LEFT));
			if (!tmp.get())
				continue;
			lc.minwidth = tmp->width();

			if (lc.minwidth >= lc.width) {
				lc.width     = lc.minwidth;
				lc.minimized = true;
			}
		}

		/* colspan really gives us the creeps here, because a column
		 * no longer is just a column :(  w => colspan
		 * phase one, only consider colspan = 1 columns */
		if (lc.w > 1) {
			if (lc.w > maxcolspan)
				maxcolspan = lc.w;
			continue;
		}

		/* at this point, (colsiz - lc.width) is the wiggle room for the
		 * column, but that's just for this cell, so first finish all of
		 * them before drawing conclusions */
		if (lc.width > colcursizes[lc.x])
			colcursizes[lc.x] = lc.width;
		if (lc.minwidth > colneedsizes[lc.x])
			colneedsizes[lc.x] = lc.minwidth;
	}
	/* colspan phase two, for every level up in colspan, process them,
	 * to stretch up column levels evenly after considering disbalance
	 * in them */
	for (span = 2; span <= maxcolspan; span++) {
		for (c = lcl.begin(); c != lcl.end(); c++) {
			Area::size_type colsiz = 0;
			Area::size_type minsiz = 0;
			Area::size_type gap;
			double          scale;
			int             j;

			lc = **c;

			/* column not of colspan level we're looking for? move on */
			if (lc.w != span)
				continue;

			/* compute the needed size of the columns this cell spans */
			for (j = 0; j < lc.w; j++) {
				if (j > 0) {
					colsiz += column_spacing;
					minsiz += column_spacing;
				}
				if (colcursizes[lc.x + j] > 0)
					colsiz += colcursizes[lc.x + j];
				if (colneedsizes[lc.x + j] > 0)
					minsiz += colneedsizes[lc.x + j];
			}

			/* if it doesn't fit increment the columns affected */
			if (colsiz < lc.width) {
				scale  = (double)lc.width / (double)colsiz;
				colsiz = lc.width - colsiz;
				for (j = 0; j < lc.w - 1; j++) {
					gap =
						(Area::size_type)ceil((double)(colcursizes[lc.x + j]) *
											  scale);
					colsiz -= gap - colcursizes[lc.x + j];
					colcursizes[lc.x + j] = gap;
				}
				colcursizes[lc.x + j] = colsiz;
			}
			if (minsiz < lc.minwidth) {
				scale  = (double)lc.minwidth / (double)minsiz;
				minsiz = lc.minwidth - minsiz;
				for (j = 0; j < lc.w - 1; j++) {
					gap =
						(Area::size_type)ceil((double)(colneedsizes[lc.x + j]) *
											  scale);
					minsiz -= gap - colneedsizes[lc.x + j];
					colneedsizes[lc.x + j] = gap;
				}
				colneedsizes[lc.x + j] = minsiz;
			}
		}
	}
	/* check whether all columns are on a minimum now
	 * compute space we lose by mandatory items like borders and
	 * spacing */
	totcolwidth    = 0;
	totcolneedsize = 0;
	totcolcursize  = 0;
	for (i = 0; i < number_of_columns; i++) {
		totcolwidth    += column_widths_in_out[i];
		totcolneedsize += colneedsizes[i];
		totcolcursize  += colcursizes[i];
	}
	waste = *table_width_in_out - totcolwidth;

	newtablesize = *table_width_in_out;
	if (waste >= wanted_size)
		wantedspace = 0;
	else
		wantedspace = wanted_size - waste;

	/* we have three sizes:
	 * - columns_widths_in_out: the current size displayed/assigned
	 * - colneedsizes:          the minimum size required to display
	 * - colcursizes:           the current size of the content */

	if (totcolneedsize >= wantedspace) {
		/* take the minimum, it doesn't fit */
		for (i = 0; i < number_of_columns; i++) {
			newtablesize           -= column_widths_in_out[i] - colneedsizes[i];
			column_widths_in_out[i] = colneedsizes[i];
		}

		ret = false;
	} else {
		/* we can scale all columns by ratio, but if we do, we also make
		 * columns no longer fit if others still have space
		 * (columns_widths_in_out > colcursizes), so in phase one, first
		 * try to reduce in this space, by ratio of space needed */
		Area::size_type whitespace = 0;
		for (i = 0; i < number_of_columns; i++) {
			if (column_widths_in_out[i] > colcursizes[i])
				whitespace += column_widths_in_out[i] - colcursizes[i];
		}
		if (whitespace > 0) {
			Area::size_type redux = newtablesize - waste - wantedspace;
			if (redux < whitespace) {
				double scale = ((double)redux / (double)whitespace);
				/* remove space by ratio */
				for (i = 0; i < number_of_columns - 1; i++) {
					Area::size_type newcolsiz;
					if (column_widths_in_out[i] > colcursizes[i]) {
						Area::size_type space     =
							column_widths_in_out[i] - colcursizes[i];
						newcolsiz = colcursizes[i] +
							(Area::size_type)ceil((double)(space) * scale);
					} else {
						newcolsiz = column_widths_in_out[i];
					}
					wantedspace              -= newcolsiz;
					column_widths_in_out[i]   = newcolsiz;
				}
				/* fit the remainder */
				column_widths_in_out[i]  = wantedspace;
				newtablesize             = wanted_size;
			} else {
				/* remove all extra space */
				for (i = 0; i < number_of_columns; i++) {
					if (colcursizes[i] < column_widths_in_out[i])
						column_widths_in_out[i] = colcursizes[i];
				}
			}
		}

		/* we still need to reduce, squeeze columns where possible, do
		 * this one by one, because a reduction may cause a wrap, and
		 * therefore a freeing of space which we can use */
		if (newtablesize > wanted_size) {
			Area::size_type redux = newtablesize - waste - wantedspace;

			/* we know columns won't get smaller than their needsize, so
			 * if we need more space than the absolute min could provide
			 * us, shorten the next column in the same go */
			while (redux > 0) {
				/* find largest column */
				Area::size_type largestsize;
				int             largestcol  = -1;
				for (i = 0; i < number_of_columns; i++) {
					if (largestcol < 0 ||
						colcursizes[i] - colneedsizes[i] > largestsize)
					{
						largestsize = colcursizes[i] - colneedsizes[i];
						largestcol  = i;
					}
				}
				if (largestcol < 0 || largestsize == 0) /* ?!? */
					break;
				column_widths_in_out[largestcol]--;
  				/* disable next round */
				colcursizes[largestcol] = colneedsizes[largestcol];
				newtablesize--;
				redux -= std::min(redux, largestsize);
			}
		}

		ret = true;
	}

	*table_width_in_out = newtablesize;

	return ret;
}

/* scale up a table by relative proportions, may return a larger table
 * than requested (e.g. use narrow_table afterwards) */
static bool
widen_table
(
	list<auto_ptr<LogicalCell>> *const lcs_in_out,
	const int                    number_of_columns,
	const Area::size_type        column_spacing,
	Area::size_type             *const column_widths_in_out,
	Area::size_type             *const table_width_in_out,
	const Area::size_type        wanted_size
)
{
	int    i;
	int    addwidth = 0;
	int    newwidth;
	double scale;
	
	if (wanted_size <= *table_width_in_out)
		return false;
	if ((number_of_columns * column_spacing) >= *table_width_in_out)
		return false;

	scale = (double)(wanted_size) / (double)(*table_width_in_out -
											 (number_of_columns *
											  column_spacing));

	/* update columns and compute effectual width */
	for (i = 0; i < number_of_columns; i++) {
		newwidth = (int)ceil(((double)column_widths_in_out[i]) * scale);
		addwidth += newwidth - column_widths_in_out[i];
		column_widths_in_out[i] = newwidth;
	}

	*table_width_in_out += addwidth;
	return true;
}

/*
 * Compute the heights of each row. Take into account the cells of the row,
 * plus the cells above that "hang" into the row.
 *
 * As a side effect, format the table cells.
 */
static void
compute_row_heights
(
	list<auto_ptr<LogicalCell>> *lcs_in_out,
	const int                    number_of_rows,
	const Area::size_type        row_spacing,
	Area::size_type             *const row_heights_return,
	const int                    column_spacing,
	const Area::size_type       *column_widths
)
{
	for (int y = 0; y < number_of_rows; y++)
		row_heights_return[y] = 0;

	list<auto_ptr<LogicalCell>>::reverse_iterator i;
	for (i = lcs_in_out->rbegin(); i != lcs_in_out->rend(); i++) {
		LogicalCell &lc(**i);
		Area::size_type w = (lc.w - 1) * column_spacing;

		for (int x = lc.x; x < lc.x + lc.w; ++x)
			w += column_widths[x];
		
		lc.area.reset(lc.cell->format(w, lc.halign));
		if (!lc.area.get())
			continue;
		
		Area::size_type h = (lc.h - 1) * row_spacing;

		for (int y = lc.y; y < lc.y + lc.h; ++y)
			h += row_heights_return[y];

		istr height = get_style_attr(lc.cell->attributes.get(),
							   		 "height", "HEIGHT", "").get()->front();
		Area::size_type wanted_height = 0;
		if (!height.empty()) {
			/* I don't believe we can do anything with percentages here,
			 * so we'll only try and see if there's absolute values we
			 * can work with */
			if (isdigit(height[height.length() - 1])) {
				wanted_height =
					(Area::size_type)ceil((double)atoi(height.c_str()) /
										  (double)Area::heightsize);
			} else if (height.slice(height.length() - 2, 2).iequals("px")) {
				height.erase(height.length() - 2);
				wanted_height =
					(Area::size_type)ceil((double)atoi(height.c_str()) /
										  (double)Area::heightsize);
			}
			if (wanted_height < lc.area->height())
				wanted_height = lc.area->height();
		} else {
			wanted_height = lc.area->height();
		}

		if (wanted_height > h)
			row_heights_return[lc.y + lc.h - 1] += wanted_height - h;
	}
}

/* ------------------------------------------------------------------------- */

// <TABLE> Attributes: ALIGN (processed) WIDTH (ignored) BORDER (processed)
//                     CELLSPACING CELLPADDING (ignored)
// <TR> Attributes:    ALIGN VALIGN (processed)
// <TD> Attributes:    NOWRAP (ignored) ROWSPAN COLSPAN ALIGN VALIGN
//                     (processed) WIDTH HEIGHT (ignored)
Area *
Table::format(Area::size_type w, int halign) const
{
	istr clr;
	istr wdth;
	istr align;

	align = get_style_attr(attributes.get(), "text-align",
						   "ALIGN", "").get()->front();
	if (align.iequals("center"))
		halign = Area::CENTER;
	else if (align.iequals("right"))
		halign = Area::RIGHT;
	else if (align.iequals("left"))
		halign = Area::LEFT;
	/* else keep halign */

	/* <TABLE>                      => default  => no border
	 * <TABLE BORDER>               => "border" => draw border
	 * <TABLE BORDER=0>             => "0"      => no border
	 * <TABLE STYLE="border: none"> => "none"   => no border
	 * <TABLE BORDER="9px">         => "9px"    => draw border */
	bool draw_border = false;
	auto_ptr<list<istr>> brdr =
		get_style_attr(attributes.get(), "border", "BORDER", "0");
	/* border may be something like border: 1px solid red */
	list<istr>::const_iterator it;
	for (it = brdr.get()->begin(); it != brdr.get()->end(); it++) {
		const istr &sstr(*it);
		if (sstr.iequals("none") || sstr.iequals("0")) {
			draw_border = false;
		} else if (sstr[0] >= '1' && sstr[0] <= '9') {
			draw_border = true;
		} else if (sstr.iequals("border")) {
			draw_border = true;
		}
		/* ignore the rest */
	}

	/* allow override for debugging purposes */
	if (getenv("HTML2TEXT_FORCE_BORDER") != NULL)
		draw_border = true;

	static const Area::size_type column_spacing      = 1;
	static const Area::size_type row_spacing         = 0;
	Area::size_type              left_border_width   = draw_border ? 1 : 0;
	Area::size_type              right_border_width  = draw_border ? 1 : 0;
	static const Area::size_type top_border_width    = 0;
	static const Area::size_type bottom_border_width = 0;

	/* Iterate through the table's cells and create a list of "LogicalCell"s.
	 * Compute the positions and sizes of all cells, format their contents, and
	 * compute the number of rows and columns. */
	list<auto_ptr<LogicalCell>> lcs;
	int number_of_rows, number_of_columns;

	create_lcs(*this,
			   w,
			   left_border_width,
			   right_border_width,
			   column_spacing,
			   &lcs,
			   &number_of_rows,
			   &number_of_columns);

	/* The code below relies on that a table has 1 or more rows and one or
	 * more columns. Arno Unkrig 2002-07-21. */
	if (number_of_rows == 0 || number_of_columns == 0)
		return 0;

	/* Now compute the column widths and the table width. */
	auto_aptr<Area::size_type> column_widths =
		new Area::size_type[number_of_columns];
	Area::size_type table_width;

	compute_widths(lcs,
				   number_of_columns,
				   column_spacing,
				   left_border_width,
				   right_border_width,
				   &table_width,
				   column_widths.get());

	/* see if there is a width defined by percentage or pixels */
	Area::size_type wanted_width = Formatting::get_width(attributes.get(), w);
	if (wanted_width == 0)
		wanted_width = table_width;

	/* don't scale to anything bigger than our viewport */
	if (wanted_width > w)
		wanted_width = w;

	/* upscale the table if it is supposed to be bigger */
	while (table_width < wanted_width) {
		if (!widen_table(&lcs,                 /* in/out */
						 number_of_columns,
						 column_spacing,
						 column_widths.get(),  /* in/out */
						 &table_width,         /* in/out */
						 wanted_width))
			break;
	}

	/* narrow the columns that allow to when necessary, note that
	 * upscaling will deliberately produce a larger output so
	 * downscaling can get the number to the exact required size */
	while (table_width > wanted_width) {
		if (!narrow_table(&lcs,                /* in/out */
						  number_of_columns,
						  column_spacing,
						  column_widths.get(), /* in/out */
						  &table_width,        /* in/out */
						  wanted_width))
			break;
	}

	/* At this point, all cells are formatted such that the table width fits
	 * into "w" (if possible). */

	/* compute row heights, this also renders the cells for the final
	 * view */
	auto_aptr<Area::size_type> row_heights =
	    new Area::size_type[number_of_rows];

	compute_row_heights(&lcs,
						number_of_rows,
						row_spacing,
						row_heights.get(),
						column_spacing,
						column_widths.get());

	Area::size_type table_height = (top_border_width +
									(number_of_rows - 1) * row_spacing +
									bottom_border_width);

	for (int y = 0; y < number_of_rows; y++)
		table_height += row_heights[y];

	/* Everything is prepared... start drawing! */
	auto_ptr<Area> res(new Area);

	static int vspace_before = Formatting::getInt("TABLE.vspace.before", 0);
	res->prepend(vspace_before);

	Area::size_type x0 = 0;

	if (halign != Area::LEFT && table_width < w) {
		if (halign == Area::CENTER)
			x0 += (w - table_width) / 2;
		else if (halign == Area::RIGHT)
			x0 += w - table_width;
	}

	/* Draw the caption, if any. */
	if (caption.get()) {
		auto_ptr<Area> cap(caption->format(table_width, Area::CENTER));
		if (cap.get() && cap->height() >= 1) {
			cap->add_attribute(Cell::BOLD);
			res->insert(*cap, x0, 0);
		}
	}

	/* Draw the top and the left border. */
	Area::size_type y0 = res->height();
	if (draw_border) {
		if (y0 == 0)
			y0 = 1;
		res->fill('|', x0, y0, left_border_width, table_height);
		res->add_attribute(
				Cell::UNDERLINE,
				x0 + left_border_width,
				y0 - 1,
				table_width - left_border_width - right_border_width, 1);
	} else {
		res->fill(' ', x0, y0, left_border_width, table_height);
	}

	/* Draw the cells and their bottom and right borders. */
	const list<auto_ptr<LogicalCell>>           &lcl(lcs);
	list<auto_ptr<LogicalCell>>::const_iterator  i;

	for (i = lcl.begin(); i != lcl.end(); ++i) {
		const LogicalCell &lc = **i;

		/* Calculate cell position. */
		Area::size_type x = x0 + left_border_width;
		for (int j = 0; j < lc.x; j++)
			x += column_widths[j] + column_spacing;

		Area::size_type y = y0 + top_border_width;
		for (int j = 0; j < lc.y; j++)
			y += row_heights  [j] + row_spacing;

		/* Calculate cell dimensions. */
		Area::size_type w = (lc.w - 1) * column_spacing;
		for (int j = lc.x; j < lc.x + lc.w; j++)
			w += column_widths[j];

		Area::size_type h = (lc.h - 1) * row_spacing;
		for (int j = lc.y; j < lc.y + lc.h; j++)
			h += row_heights[j];

		/* Draw cell contents and borders. */
		if (lc.area.get()) {
			/* horizontal alignment is already taken care of when the
			 * cell contents was rendered, so ensure we don't re-align
			 * it, which basically makes centered content appear too
			 * much to the right */
			res->insert(*lc.area, x, y, w, h, Area::LEFT, lc.valign);
		}
		if (draw_border) {
			/* If the right neighbor cell bottom is flush with this
			 * cell's bottom, then also underline the border between
			 * the two cells. */
			bool underline_column_separator = false;
			{
				int lx = lc.x + lc.w, ly = lc.y + lc.h;
				list<auto_ptr<LogicalCell>>::const_iterator j;
				for (j = lcl.begin(); j != lcl.end(); ++j) {
					const LogicalCell &lc2 = **j;
					if (lc2.x == lx && lc2.y + lc2.h == ly) {
						underline_column_separator = true;
						break;
					}
				}
			}
			res->add_attribute(Cell::UNDERLINE,
							   x, y + h - 1,
							   w + underline_column_separator, 1);
		}
		res->fill(draw_border ? '|' : ' ', x + w, y, 1, h);

		/* apply colours */
		Formatting::set_bgcolour(attributes.get(), res.get());
		Formatting::set_fgcolour(attributes.get(), res.get());
	}

	static int vspace_after = Formatting::getInt("TABLE.vspace.after", 0);
	res->append(vspace_after);

	return res.release();
}
