
 /***************************************************************************/

/*
 * Portions Copyright (c) 1999 GMRS Software GmbH
 * Carl-von-Linde-Str. 38, D-85716 Unterschleissheim, http://www.gmrs.de
 * All rights reserved.
 *
 * Author: Arno Unkrig <arno@unkrig.de>
 *
 * All advertising materials mentioning features or use of this software
 * must display the following acknowledgement:
 * "This product includes software developed by GMRS Software GmbH."
 * The name of GMRS Software GmbH may not be used to endorse or promote
 * products derived from this software without specific prior written
 * permission.
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
 * Fre Jun  8 17:46:31 CEST 2001: new method
 * Thu Oct  4 21:38:47 CEST 2001: ported to g++ 3.0
 */
  
 /***************************************************************************/


#ifndef __html_h_INCLUDED__ /* { */
#define __html_h_INCLUDED__

/* ------------------------------------------------------------------------- */


#include <string>
#include <list>
#ifdef AUTO_PTR_BROKEN /* { */
#  define auto_ptr broken_auto_ptr
#  include <memory>
#  undef auto_ptr
#  include "libstd/include/auto_ptr.h"
#else /* } { */
#  include <memory>
#endif /* } */
#include <utility>

#include "Area.h"

/* ------------------------------------------------------------------------- */

#define LATIN1_nbsp   160
#define LATIN1_iexcl  161
#define LATIN1_cent   162
#define LATIN1_pound  163
#define LATIN1_curren 164
#define LATIN1_yen    165
#define LATIN1_brvbar 166
#define LATIN1_sect   167
#define LATIN1_uml    168
#define LATIN1_copy   169
#define LATIN1_ordf   170
#define LATIN1_laquo  171
#define LATIN1_not    172
#define LATIN1_shy    173
#define LATIN1_reg    174
#define LATIN1_macr   175
#define LATIN1_deg    176
#define LATIN1_plusmn 177
#define LATIN1_sup2   178
#define LATIN1_sup3   179
#define LATIN1_acute  180
#define LATIN1_micro  181
#define LATIN1_para   182
#define LATIN1_middot 183
#define LATIN1_cedil  184
#define LATIN1_sup1   185
#define LATIN1_ordm   186
#define LATIN1_raquo  187
#define LATIN1_frac14 188
#define LATIN1_frac12 189
#define LATIN1_frac34 190
#define LATIN1_iquest 191
#define LATIN1_Agrave 192
#define LATIN1_Aacute 193
#define LATIN1_Acirc  194
#define LATIN1_Atilde 195
#define LATIN1_Auml   196
#define LATIN1_Aring  197
#define LATIN1_AElig  198
#define LATIN1_Ccedil 199
#define LATIN1_Egrave 200
#define LATIN1_Eacute 201
#define LATIN1_Ecirc  202
#define LATIN1_Euml   203
#define LATIN1_Igrave 204
#define LATIN1_Iacute 205
#define LATIN1_Icirc  206
#define LATIN1_Iuml   207
#define LATIN1_ETH    208
#define LATIN1_Ntilde 209
#define LATIN1_Ograve 210
#define LATIN1_Oacute 211
#define LATIN1_Ocirc  212
#define LATIN1_Otilde 213
#define LATIN1_Ouml   214
#define LATIN1_times  215
#define LATIN1_Oslash 216
#define LATIN1_Ugrave 217
#define LATIN1_Uacute 218
#define LATIN1_Ucirc  219
#define LATIN1_Uuml   220
#define LATIN1_Yacute 221
#define LATIN1_THORN  222
#define LATIN1_szlig  223
#define LATIN1_agrave 224
#define LATIN1_aacute 225
#define LATIN1_acirc  226
#define LATIN1_atilde 227
#define LATIN1_auml   228
#define LATIN1_aring  229
#define LATIN1_aelig  230
#define LATIN1_ccedil 231
#define LATIN1_egrave 232
#define LATIN1_eacute 233
#define LATIN1_ecirc  234
#define LATIN1_euml   235
#define LATIN1_igrave 236
#define LATIN1_iacute 237
#define LATIN1_icirc  238
#define LATIN1_iuml   239
#define LATIN1_eth    240
#define LATIN1_ntilde 241
#define LATIN1_ograve 242
#define LATIN1_oacute 243
#define LATIN1_ocirc  244
#define LATIN1_otilde 245
#define LATIN1_ouml   246
#define LATIN1_divide 247
#define LATIN1_oslash 248
#define LATIN1_ugrave 249
#define LATIN1_uacute 250
#define LATIN1_ucirc  251
#define LATIN1_uuml   252
#define LATIN1_yacute 253
#define LATIN1_thorn  254
#define LATIN1_yuml   255

/* ------------------------------------------------------------------------- */

using std::string;
using std::pair;
using std::list;

typedef pair<string, string> TagAttribute;

string get_attribute(
  const list<TagAttribute> *, const char *name, const char *dflt
);
// neue Methode fuer leere Attribute - Johannes Geiger
string get_attribute(
  const list<TagAttribute> *, const char *name, bool *exists
);
int get_attribute(
  const list<TagAttribute> *, const char *name, int dflt
);
int get_attribute(
  const list<TagAttribute> *, const char *name, int dflt,
  const char *s1, int v1, ... /* ... NULL */
);
int get_attribute(
  const list<TagAttribute> *, const char *name, const char *dflt1, int dflt2,
  const char *s1, int v1, ... /* ... NULL */
);

/* ------------------------------------------------------------------------- */

typedef ostream &(*ostream_manipulator)(ostream &);

struct Element {
  virtual ~Element();
  virtual void unparse(ostream &, ostream_manipulator separator) const = 0;

  /*
   * Attempt to line-format the element. If the element contains "Block"s,
   * then it cannot be line-formatted, and 0 will be returned. However, it
   * is still possible to try "format()" (see below).
   */
  virtual Line *line_format() const
  { return 0; }

  /*
   * Format the element into a rectangular area. Attempt to not exceed "width".
   */
  virtual Area *format(
    Area::size_type /*width*/,
    int             /*halign*/ 
  ) const
  { return 0; }

  virtual struct PCData *to_PCData() { return 0; }
};

/* ------------------------------------------------------------------------- */

struct PCData : public Element {
  string text;

  /*virtual*/ PCData *to_PCData() { return this; }

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
};

struct Font : public Element {
  int                                 attribute; // TT I B U STRIKE BIG SMALL
						 // SUB SUP
  auto_ptr<list<auto_ptr<Element> > > texts;

  Font(int a, list<auto_ptr<Element> > *t = 0) : attribute(a), texts(t) {}
  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Phrase : public Element {
  int                                 attribute; // EM STRONG DFN CODE SAMP
						 // KBD VAR CITE
  auto_ptr<list<auto_ptr<Element> > > texts;

  Phrase(int a, list<auto_ptr<Element> > *t = 0) : attribute(a), texts(t) {}
  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Font2 : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // SIZE COLOR
  auto_ptr<list<auto_ptr<Element> > > elements;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Anchor : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // NAME HREF REL REV TITLE
  auto_ptr<list<auto_ptr<Element> > > texts;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct BaseFont : public Element {
  auto_ptr<list<TagAttribute> > attributes; // SIZE

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
};

struct LineBreak : public Element {
  auto_ptr<list<TagAttribute> > attributes; // CLEAR

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
};

struct Map : public Element {
  auto_ptr<list<TagAttribute> >                   attributes; // NAME
  auto_ptr<list<auto_ptr<list<TagAttribute> > > > areas;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
};

struct Paragraph : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // ALIGN
  auto_ptr<list<auto_ptr<Element> > > texts;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Image : public Element {
  auto_ptr<list<TagAttribute> > attributes; // SRC ALT ALIGN WIDTH HEIGHT
					    // BORDER HSPACE VSPACE USEMAP
					    // ISMAP

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
};

struct Applet : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // CODEBASE CODE ALT NAME
						  // WIDTH HEIGHT ALIGN HSPACE
						  // VSPACE
  auto_ptr<list<auto_ptr<Element> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Param : public Element {
  auto_ptr<list<TagAttribute> > attributes; // NAME VALUE

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
};

struct Division : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // ALIGN
  auto_ptr<list<auto_ptr<Element> > > body_content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Center : public Element {
  // No attributes specified for <CENTER>!
  auto_ptr<list<auto_ptr<Element> > > body_content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct BlockQuote : public Element {
  // No attributes specified for <BLOCKQUOTE>!
  auto_ptr<list<auto_ptr<Element> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Address : public Element {
  // No attributes specified for <ADDRESS>!
  auto_ptr<list<auto_ptr<Element> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

/* ------------------------------------------------------------------------- */

struct Form : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // ACTION METHOD ENCTYPE
  auto_ptr<list<auto_ptr<Element> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Input : public Element {
  auto_ptr<list<TagAttribute> > attributes; // TYPE NAME VALUE CHECKED SIZE
					    // MAXLENGTH SRC ALIGN

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
};

struct Option {
  auto_ptr<list<TagAttribute> > attributes; // SELECTED VALUE
  auto_ptr<PCData>              pcdata;

  void unparse(ostream &, ostream_manipulator separator) const;
};

struct Select : public Element {
  auto_ptr<list<TagAttribute> >      attributes; // NAME SIZE MULTIPLE
  auto_ptr<list<auto_ptr<Option> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
};

struct TextArea : public Element {
  auto_ptr<list<TagAttribute> > attributes; // NAME ROWS COLS
  auto_ptr<PCData>              pcdata;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

/* ------------------------------------------------------------------------- */

struct Preformatted : public Element {
  auto_ptr<list<TagAttribute> >       attributes; // WIDTH
  auto_ptr<list<auto_ptr<Element> > > texts;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Body {
  auto_ptr<list<TagAttribute> >       attributes; // BACKGROUND BGCOLOR TEXT
						  // LINK VLINK ALINK
  auto_ptr<list<auto_ptr<Element> > > content;

  virtual ~Body() {}
  virtual void unparse(ostream &, ostream_manipulator separator) const;
  virtual Area *format(Area::size_type w, int halign) const;
  void format(
    Area::size_type indent_left,
    Area::size_type w,
    int             halign,
    ostream         &os
  ) const;
};

struct Script {
  auto_ptr<list<TagAttribute> > attributes; // LANGUAGE, ???
  string                        text;

  void unparse(ostream &, ostream_manipulator separator) const;
};

struct Style {
  auto_ptr<list<TagAttribute> > attributes; // ???
  string                        text;

  void unparse(ostream &, ostream_manipulator separator) const;
};

struct Head {
  auto_ptr<PCData>              title;
  auto_ptr<list<TagAttribute> > isindex_attributes; // PROMPT
  auto_ptr<list<TagAttribute> > base_attributes;    // HREF
  list<auto_ptr<Script> >       scripts;
  list<auto_ptr<Style> >        styles;
  auto_ptr<list<TagAttribute> > meta_attributes;    // HTTP-EQUIV NAME CONTENT
  auto_ptr<list<TagAttribute> > link_attributes;    // HREF REL REV TITLE

  void unparse(ostream &, ostream_manipulator separator) const;
};

struct Document {
  auto_ptr<list<TagAttribute> > attributes; // VERSION
  Head                          head;
  Body                          body;

  void unparse(ostream &, ostream_manipulator separator) const;
  Area *format(Area::size_type w, int halign) const;
  void format(
    Area::size_type indent_left,
    Area::size_type w,
    int             halign,
    ostream         &os
  ) const;
};

struct Heading : public Element {
  int                                 level;
  auto_ptr<list<TagAttribute> >       attributes; // ALIGN
  auto_ptr<list<auto_ptr<Element> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct TableCell : public Body {
  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
};

struct TableHeadingCell : public TableCell {
  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct TableRow {
  auto_ptr<list<TagAttribute> >         attributes; // ALIGN VALIGN
  auto_ptr<list<auto_ptr<TableCell> > > cells;

  void unparse(ostream &, ostream_manipulator separator) const;
};

struct Caption {
  auto_ptr<list<TagAttribute> >       attributes; // ALIGN
  auto_ptr<list<auto_ptr<Element> > > texts;

  void unparse(ostream &, ostream_manipulator separator) const;
  Area *format(Area::size_type w, int halign) const;
};

struct Table : public Element {
  auto_ptr<list<TagAttribute> >        attributes; // ALIGN WIDTH BORDER
						   // CELLSPACING CELLPADDING
  auto_ptr<Caption>                    caption;
  auto_ptr<list<auto_ptr<TableRow> > > rows;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct NoBreak : public Element {
  auto_ptr<list<auto_ptr<Element> > > content;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Line *line_format() const;
};

struct HorizontalRule : public Element {
  auto_ptr<list<TagAttribute> > attributes; // ALIGN NOSHADE SIZE WIDTH

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

/* ------------------------------------------------------------------------- */

struct ListItem {
  virtual ~ListItem() {}
  virtual void unparse(ostream &, ostream_manipulator separator) const = 0;
  virtual Area *format(
    Area::size_type w,
    int             style,
    Area::size_type indent,
    int             *number_in_out = 0
  ) const = 0;
};

struct ListNormalItem : public ListItem {
  auto_ptr<list<TagAttribute> >       attributes; // TYPE VALUE
  auto_ptr<list<auto_ptr<Element> > > flow;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(
    Area::size_type w,
    int             style,
    Area::size_type indent,
    int             *number_in_out
  ) const;
};

struct ListBlockItem : public ListItem {
  auto_ptr<Element> block;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(
    Area::size_type w,
    int             style,
    Area::size_type indent,
    int             *
  ) const;
};

struct OrderedList : public Element {
  auto_ptr<list<TagAttribute> >        attributes; // TYPE START COMPACT
  auto_ptr<list<auto_ptr<ListItem> > > items;
  int                                  nesting;
  // Item indentation depends on on the list nesting level.

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct UnorderedList : public Element {
  auto_ptr<list<TagAttribute> >        attributes; // TYPE COMPACT
  auto_ptr<list<auto_ptr<ListItem> > > items;
  int                                  nesting;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Dir : public Element {
  auto_ptr<list<TagAttribute> >        attributes; // COMPACT
  auto_ptr<list<auto_ptr<ListItem> > > items;
  int                                  nesting;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct Menu : public Element {
  auto_ptr<list<TagAttribute> >        attributes; // COMPACT
  auto_ptr<list<auto_ptr<ListItem> > > items;
  int                                  nesting;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

/* ------------------------------------------------------------------------- */

struct DefinitionListItem {
  virtual ~DefinitionListItem() {}
  virtual void unparse(ostream &, ostream_manipulator separator) const = 0;
  virtual Area *format(Area::size_type w, int halign) const = 0;
};

struct TermName : public DefinitionListItem {
  auto_ptr<list<auto_ptr<Element> > > flow;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct TermDefinition : public DefinitionListItem {
  auto_ptr<list<auto_ptr<Element> > > flow;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

struct DefinitionList : public Element {
  auto_ptr<list<TagAttribute> >                  attributes; // COMPACT
  auto_ptr<list<auto_ptr<Element> > >            preamble;
  auto_ptr<list<auto_ptr<DefinitionListItem> > > items;

  /*virtual*/ void unparse(ostream &, ostream_manipulator separator) const;
  /*virtual*/ Area *format(Area::size_type w, int halign) const;
};

/* ------------------------------------------------------------------------- */

#endif /* } */

/* ------------------------------------------------------------------------- */

