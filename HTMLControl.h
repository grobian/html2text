
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
 * Thu Oct  4 21:25:07 CEST 2001: ported to g++ 3.0
 * Wed Jul  2 22:01:12 CEST 2003: ported to g++ 3.3
 */
  
 /***************************************************************************/


#ifndef __HTMLControl_h_INCLUDED__ /* { */
#define __HTMLControl_h_INCLUDED__

/* ------------------------------------------------------------------------- */

#include "HTMLParser.h"
#include "urlistream.h"
#include <istream>

using std::istream;

/* ------------------------------------------------------------------------- */

class HTMLControl : public HTMLParser {

public:
  HTMLControl(urlistream &is_, bool debug_scanner_, bool debug_parser_) :
    HTMLParser(),
    current_line(1),
    current_column(0),
    literal_mode(false),
    next_token(EOF),
    debug_scanner(debug_scanner_),
    is(is_),
    number_of_ungotten_chars(0)
  { yydebug = debug_parser_; }

  int current_line;
  int current_column;

private:

  /*
   * Implementing virtual methods of "HTMLParser".
   */
  /*virtual*/ int yylex(yy_HTMLParser_stype *value_return);
  /*virtual*/ bool read_cdata(const char *terminal, string *value_return);

  /*
   * Helpers.
   */
  int yylex2(yy_HTMLParser_stype *value_return, int *tag_type_return);
  bool                literal_mode;
  int                 next_token;
  yy_HTMLParser_stype next_token_value;
  int                 next_token_tag_type;

  int get_char();
  void unget_char(int);

  bool debug_scanner;

  urlistream &is;
  int     ungotten_chars[5];
  int     number_of_ungotten_chars;
};

/* ------------------------------------------------------------------------- */

#endif /* } */

/* ------------------------------------------------------------------------- */

