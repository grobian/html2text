
 /***************************************************************************/

/*
 * Portions Copyright (c) 1999 GMRS Software GmbH
 * Carl-von-Linde-Str. 38, D-85716 Unterschleissheim, http://www.gmrs.de
 * All rights reserved.
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
 * Fre Jun  8 17:43:02 CEST 2001: new method
 * Wed Jul  2 22:07:12 CEST 2003: ported to g++ 3.3
 */

 /***************************************************************************/


#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "html.h"
#include "HTMLParser.h"
#include "cmp_nocase.h"

/* ------------------------------------------------------------------------- */

/*
 * Define some helpers.
 */

#define define_foreach(T, args, action) \
void foreach args { \
  for (T::const_iterator i = l.begin(); i != l.end(); ++i) { \
    action; \
  } \
}

#define pack(T) \
define_foreach(list<auto_ptr<T> >, ( \
  const list<auto_ptr<T> > &l, \
  ostream                  &os, \
  ostream_manipulator      separator \
), (*i)->unparse(os, separator))

static pack(Element)
static pack(TableCell)
static pack(TableRow)
static pack(ListItem)
static pack(Option)
static pack(DefinitionListItem)
static pack(Script)
static pack(Style)

#undef pack

/*
 * Special helper for "const auto_ptr<list<TagAttribute> > &".
 */
static ostream &operator<<(ostream &os, const auto_ptr<list<TagAttribute> > &a)
{
  if (a.get()) {
    const list<TagAttribute> &al(*a);
    list<TagAttribute>::const_iterator i;
    for (i = al.begin(); i != al.end(); ++i) {
      os << " " << (*i).first << "=\"" << (*i).second << "\"";
    }
  }
  return os;
}

/* ------------------------------------------------------------------------- */

/*
 * Brothers of "endl".
 */
static ostream &none(ostream &os) { return os; }

/* ------------------------------------------------------------------------- */

/*
 * Some C++ compilers (e.g. EGCS 2.91.66) have problems if all virtual
 * methods of a class are inline or pure virtual, so we define the virtual
 * "Element::~Element()", which is the only virtual method, non-inline,
 * although it is empty.
 */
Element::~Element()
{
}

/* ------------------------------------------------------------------------- */

void
Document::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<HTML" << attributes << ">" << separator;
  head.unparse(os, separator);
  body.unparse(os, separator);
  os << "</HTML>" << separator;
}

void
Head::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<HEAD>" << separator;
  if (title.get()) {
    os << "<TITLE>" << separator;
    title->unparse(os, separator);
    os << "</TITLE>" << separator;
  }
  if (isindex_attributes.get()) {
    os << "<ISINDEX"<< isindex_attributes << ">" << std::endl;
  }
  if (base_attributes.get()) os << "<BASE" << base_attributes << ">" << std::endl;
  foreach(scripts, os, separator);
  foreach(styles, os, separator);
  if (meta_attributes.get()) os << "<META" << meta_attributes << ">" << std::endl;
  if (link_attributes.get()) os << "<LINK" << link_attributes << ">" << std::endl;
  os << "</HEAD>" << separator;
}

void
Script::unparse(ostream &os, ostream_manipulator separator) const
{
  os
    << "<SCRIPT" << attributes << ">" << separator
    << text
    << "</SCRIPT>" << separator;
}

void
Style::unparse(ostream &os, ostream_manipulator separator) const
{
  os
    << "<STYLE" << attributes << ">" << separator
    << text
    << "</STYLE>" << separator;
}

void
Body::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<BODY" << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</BODY>" << separator;
}

void
PCData::unparse(ostream &os, ostream_manipulator separator) const
{
  for (string::size_type j = 0; j < text.length(); ++j) {
    char c = text[j];
    switch (((int) c) & 255) {
    case LATIN1_nbsp: os << "&nbsp;"; break;
    case '&':         os << "&amp;";  break;
    case '<':         os << "&lt;";   break;
    case '>':         os << "&gt;";   break;
    case '"':         os << "&quot;"; break;
    default:
      if (c & 0x80) {
        os << "&#" << (((int) c) & 255) << ";";
      } else {
        os << c;
      }
      break;
    }
  }

  os << separator;
}

void
Heading::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<H" << level << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</H" << level << ">" << separator;
}

void
Paragraph::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<P" << attributes << ">" << separator;
  if (texts.get()) foreach(*texts, os, separator);
  os << "</P>" << separator;
}

void
Image::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<IMG" << attributes << ">" << separator;
}

void
Applet::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<APPLET" << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</APPLET>" << separator;
}

void
Param::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<PARAM" << attributes << ">" << separator;
}

void
Division::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<DIV" << attributes << ">" << separator;
  if (body_content.get()) foreach(*body_content, os, separator);
  os << "</DIV>" << separator;
}

void
Center::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<CENTER>" << separator;
  if (body_content.get()) foreach(*body_content, os, separator);
  os << "</CENTER>" << separator;
}

void
BlockQuote::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<BLOCKQUOTE>" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</BLOCKQUOTE>" << separator;
}

void
Address::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<ADDRESS>" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</ADDRESS>" << separator;
}

void
Form::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<FORM" << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</FORM>" << separator;
}

void
Preformatted::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<PRE" << attributes << ">" << separator;
  if (texts.get()) { foreach(*texts, os, none); os << separator; }
  os << "</PRE>" << separator;
}

void
HorizontalRule::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<HR" << attributes << ">" << separator;
}

void
Input::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<INPUT" << attributes << ">" << separator;
}

void
Option::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<OPTION" << attributes << ">" << separator;
  if (pcdata.get()) pcdata->unparse(os, separator);
  os << "</OPTION>" << std::endl;
}

void
Select::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<SELECT" << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</SELECT>" << std::endl;
}

void
TextArea::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<TEXTAREA" << attributes << ">" << separator;
  if (pcdata.get()) pcdata->unparse(os, separator);
  os << "</TEXTAREA>" << std::endl;
}

/* ------------------------------------------------------------------------- */

void
OrderedList::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<OL" << attributes << ">" << separator;
  if (items.get()) foreach(*items, os, separator);
  os << "</OL>" << separator;
}

void
UnorderedList::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<UL" << attributes << ">" << separator;
  if (items.get()) foreach(*items, os, separator);
  os << "</UL>" << separator;
}

void
Dir::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<DIR" << attributes << ">" << separator;
  if (items.get()) foreach(*items, os, separator);
  os << "</DIR>" << separator;
}

void
Menu::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<MENU" << attributes << ">" << separator;
  if (items.get()) foreach(*items, os, separator);
  os << "</MENU>" << separator;
}

void
ListNormalItem::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<LI" <<attributes << ">" << separator;
  if (flow.get()) foreach(*flow, os, separator);
  os << "</LI>" << separator;
}

void
ListBlockItem::unparse(ostream &os, ostream_manipulator separator) const
{
  if (block.get()) block->unparse(os, separator);
}

/* ------------------------------------------------------------------------- */

void
DefinitionList::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<DL" << attributes << ">" << separator;
  if (items.get()) foreach(*items, os, separator);
  os << "</DL>" << separator;
}

void
TermName::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<DT>" << separator;
  if (flow.get()) foreach(*flow, os, separator);
  os << "</DT>" << separator;
}

void
TermDefinition::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<DD>" << separator;
  if (flow.get()) foreach(*flow, os, separator);
  os << "</DD>" << separator;
}

/* ------------------------------------------------------------------------- */

void
Table::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<TABLE" << attributes << ">" << separator;
  if (caption.get()) caption->unparse(os, separator);
  if (rows.get()) foreach(*rows, os, separator);
  os << "</TABLE>" << separator;
}

void
NoBreak::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<NOBR>" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</NOBR>" << separator;
}

void
Font::unparse(ostream &os, ostream_manipulator separator) const
{
  const char *tag = (
    attribute == HTMLParser::TT     ? "TT" :
    attribute == HTMLParser::I      ? "I" :
    attribute == HTMLParser::B      ? "B" :
    attribute == HTMLParser::U      ? "U" :
    attribute == HTMLParser::STRIKE ? "STRIKE" :
    attribute == HTMLParser::BIG    ? "BIG" :
    attribute == HTMLParser::SMALL  ? "SMALL" :
    attribute == HTMLParser::SUB    ? "SUB" :
    attribute == HTMLParser::SUP    ? "SUP" :
    "???"
  );

  os << "<" << tag << ">" << separator;
  if (texts.get()) foreach(*texts, os, separator);
  os << "</" << tag << ">" << separator;
}

void
Phrase::unparse(ostream &os, ostream_manipulator separator) const
{
  const char *tag = (
    attribute == HTMLParser::EM     ? "EM" :
    attribute == HTMLParser::STRONG ? "STRONG" :
    attribute == HTMLParser::DFN    ? "DFN" :
    attribute == HTMLParser::CODE   ? "CODE" :
    attribute == HTMLParser::SAMP   ? "SAMP" :
    attribute == HTMLParser::KBD    ? "KBD" :
    attribute == HTMLParser::VAR    ? "VAR" :
    attribute == HTMLParser::CITE   ? "CITE" :
    "???"
  );

  os << "<" << tag << ">" << separator;
  if (texts.get()) foreach(*texts, os, separator);
  os << "</" << tag << ">" << separator;
}

void
Anchor::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<A" << attributes << ">" << separator;
  if (texts.get()) foreach(*texts, os, separator);
  os << "</A>" << separator;
}

void
BaseFont::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<BASEFONT" << attributes << ">" << separator;
}

void
LineBreak::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<BR" << attributes << ">" << separator;
}

void
Map::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<MAP" << attributes << ">" << separator;
  if (areas.get()) {
    const list<auto_ptr<list<TagAttribute> > >           &al(*areas);
    list<auto_ptr<list<TagAttribute> > >::const_iterator i;
    for (i = al.begin(); i != al.end(); ++i) {
      os << "<AREA" << *i << ">" << separator;
    }
  }
  os << "</MAP>" << separator;
}

void
Font2::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<FONT" << attributes << ">" << separator;
  if (elements.get()) foreach(*elements, os, separator);
  os << "</FONT>" << separator;
}

void
TableRow::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<TR" << attributes << ">" << separator;
  if (cells.get()) foreach(*cells, os, separator);
  os << "</TR>" << separator;
}

void
TableCell::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<TD" << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</TD>" << separator;
}

void
TableHeadingCell::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<TH" << attributes << ">" << separator;
  if (content.get()) foreach(*content, os, separator);
  os << "</TH>" << separator;
}

void
Caption::unparse(ostream &os, ostream_manipulator separator) const
{
  os << "<CAPTION" << attributes << ">" << separator;
  if (texts.get()) foreach(*texts, os, separator);
  os << "</CAPTION>" << separator;
}

/* ------------------------------------------------------------------------- */

string
get_attribute(
  const list<TagAttribute> *as,
  const char               *name,
  const char               *dflt
)
{
  if (as) {
    list<TagAttribute>::const_iterator i;
    for (i = as->begin(); i != as->end(); ++i) {
      if (cmp_nocase((*i).first, name) == 0) return string((*i).second);
    }
  }
  return string(dflt);
}

// *exists is set to false if attribute *name does not exist - Johannes Geiger

string
get_attribute(
  const list<TagAttribute> *as,
  const char               *name,
  bool                     *exists
)
{
  *exists = true;
  if (as) {
    list<TagAttribute>::const_iterator i;
    for (i = as->begin(); i != as->end(); ++i) {
      if (cmp_nocase((*i).first, name) == 0) return string((*i).second);
    }
  }
  *exists = false;
  return string("");
}


int
get_attribute(
  const list<TagAttribute> *as,
  const char               *name,
  int                      dflt
)
{
  if (as) {
    list<TagAttribute>::const_iterator i;
    for (i = as->begin(); i != as->end(); ++i) {
      if (cmp_nocase((*i).first, name) == 0) return atoi((*i).second.c_str());
    }
  }
  return dflt;
}

int
get_attribute(
  const list<TagAttribute> *as,
  const char               *name,
  int                      dflt,
  const char               *s1,
  int                      v1,
  ...
)
{
  if (as) {
    list<TagAttribute>::const_iterator i;
    for (i = as->begin(); i != as->end(); ++i) {
      if (cmp_nocase((*i).first, name) == 0) {
        const char *s = s1;
        int        v = v1;

        va_list va;
        va_start(va, v1);
        for (;;) {
          if (cmp_nocase(s, (*i).second) == 0) break;
          s = va_arg(va, const char *);
          if (!s) { v = dflt; break; }
          v = va_arg(va, int);
        }
        va_end(va);
        return v;
      }
    }
  }
  return dflt;
}

int
get_attribute(
  const list<TagAttribute> *as,
  const char               *name,   // Attribute name
  const char               *dflt1,  // If attribute not specified
  int                      dflt2,   // If string value does not match s1, ...
  const char               *s1,
  int                      v1,
  ...
)
{
  if (as) {
    list<TagAttribute>::const_iterator i;
    for (i = as->begin(); i != as->end(); ++i) {
      if (cmp_nocase((*i).first, name) == 0) {
	dflt1 = (*i).second.c_str();
        break;
      }
    }
  }

  if (!dflt1) return dflt2;

  const char *s = s1;
  int        v = v1;

  va_list va;
  va_start(va, v1);
  for (;;) {
    if (cmp_nocase(s, dflt1) == 0) break;
    s = va_arg(va, const char *);
    if (!s) break;
    v = va_arg(va, int);
  }
  va_end(va);

  return s ? v : dflt2;
}

/* ------------------------------------------------------------------------- */

