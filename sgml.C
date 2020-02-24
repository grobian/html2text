
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
 * Thu Oct  4 22:14:38 CEST 2001: included EURO-sign
 * Sat Sep 14 15:23:25 CEST 2002: Added plain ASCII output patch by Bela Lubkin
 * Thu Nov 20 18:23:59 CET 2003: SGML entities array revised
 */
  
 /***************************************************************************/


#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "html.h"
#include "sgml.h"

#ifndef nelems
#define nelems(array) (sizeof(array) / sizeof((array)[0]))
#endif

/* ------------------------------------------------------------------------- */

/*
 * Selected SGML entities, with translations to ISO-8859-1 and to
 * plain ASCII.
 */
  
/* Straight-ASCII and extra entities partially
 * added by Bela Lubkin <belal@caldera.com>.
 */

/*
 * Keep this array sorted alphabetically!
 */
static const struct TextToInt {
  char name[8];
  int  iso8859code;
  char *asciistr;
} entities[] = {
  { "AElig",   LATIN1_AElig,  "AE"         },
  { "AMP",     0,             "&"          },
  { "Aacute",  LATIN1_Aacute, "A'"         },
  { "Acirc",   LATIN1_Acirc,  "A^"         },
  { "Agrave",  LATIN1_Agrave, "A`"         },
  { "Alpha",   0,             "A"          },
  { "Aring",   LATIN1_Aring,  "AA"         },
  { "Atilde",  LATIN1_Atilde, "A~"         },
  { "Auml",    LATIN1_Auml,   "A\""        },
  { "Beta",    0,             "B"          },
  { "Ccedil",  LATIN1_Ccedil, "C,"         },
  { "Chi",     0,             "H"          },
  { "Dagger",  0,             "++"         },
  { "Delta",   0,             "D"          },
  { "ETH",     LATIN1_ETH,    "D-"         },
  { "Eacute",  LATIN1_Eacute, "E'"         },
  { "Ecirc",   LATIN1_Ecirc,  "E^"         },
  { "Egrave",  LATIN1_Egrave, "E`"         },
  { "Epsilon", 0,             "E"          },
  { "Eta",     0,             "E"          },
  { "Euml",    LATIN1_Euml,   "E\""        },
  { "GT",      0,             ">"          },
  { "Gamma",   0,             "G"          },
  { "Iacute",  LATIN1_Iacute, "I'"         },
  { "Icirc",   LATIN1_Icirc,  "I^"         },
  { "Igrave",  LATIN1_Igrave, "I`"         },
  { "Iota",    0,             "I"          },
  { "Iuml",    LATIN1_Iuml,   "I\""        },
  { "Kappa",   0,             "K"          },
  { "LT",      0,             "<"          },
  { "Lambda",  0,             "L"          },
  { "Mu",      0,             "M"          },
  { "Ntilde",  LATIN1_Ntilde, "N~"         },
  { "Nu",      0,             "N"          },
  { "OElig",   0,             "OE"         },
  { "Oacute",  LATIN1_Oacute, "O'"         },
  { "Ocirc",   LATIN1_Ocirc,  "O^"         },
  { "Ograve",  LATIN1_Ograve, "O`"         },
  { "Omega",   0,             "O"          },
  { "Omicron", 0,             "O"          },
  { "Oslash",  LATIN1_Oslash, "O/"         },
  { "Otilde",  LATIN1_Otilde, "O~"         },
  { "Ouml",    LATIN1_Ouml,   "O\""        },
  { "Phi",     0,             "F"          },
  { "Pi",      0,             "P"          },
  { "Prime",   0,             "''"         },
  { "Psi",     0,             "PS"         },
  { "QUOT",    0,             "\""         },
  { "Rho",     0,             "R"          },
  { "Scaron",  0,             "S"          },
  { "Sigma",   0,             "S"          },
  { "THORN",   LATIN1_THORN,  "TH"         },
  { "Tau",     0,             "T"          },
  { "Theta",   0,             "TH"         },
  { "Uacute",  LATIN1_Uacute, "U'"         },
  { "Ucirc",   LATIN1_Ucirc,  "U^"         },
  { "Ugrave",  LATIN1_Ugrave, "U`"         },
  { "Upsilon", 0,             "U"          },
  { "Uuml",    LATIN1_Uuml,   "U\""        },
  { "Xi",      0,             "X"          },
  { "Yacute",  LATIN1_Yacute, "Y'"         },
  { "Yuml",    0,             "Y\""        },
  { "Zeta",    0,             "Z"          },
  { "aacute",  LATIN1_aacute, "a'"         },
  { "acirc",   LATIN1_acirc,  "a^"         },
  { "acute",   LATIN1_acute,  "'"          },
  { "aelig",   LATIN1_aelig,  "ae"         },
  { "agrave",  LATIN1_agrave, "a`"         },
  { "alefsym", 0,             "Aleph"      },
  { "alpha",   0,             "a"          },
  { "amp",     0,             "&"          },
  { "and",     0,             "AND"        },
  { "ang",     0,             "-V"         },
  { "apos",    0,             "'"          },
  { "aring",   LATIN1_aring,  "aa"         },
  { "asymp",   0,             "~="         },
  { "atilde",  LATIN1_atilde, "a~"         },
  { "auml",    LATIN1_auml,   "a\""        },
  { "bdquo",   0,             "\""         },
  { "beta",    0,             "b"          },
  { "brvbar",  LATIN1_brvbar, "|"          },
  { "bull",    0,             " o "        },
  { "cap",     0,             "(U"         },
  { "ccedil",  LATIN1_ccedil, "c,"         },
  { "cedil",   LATIN1_cedil,  ","          },
  { "cent",    LATIN1_cent,   "-c-"        },
  { "chi",     0,             "h"          },
  { "circ",    0,             "^"          },
//  { "clubs",   0,             "[clubs]"    },
  { "cong",    0,             "?="         },
  { "copy",    LATIN1_copy,   "(c)"        },
  { "crarr",   0,             "<-'"        },
  { "cup",     0,             ")U"         },
  { "curren",  LATIN1_curren, "CUR"        },
  { "dArr",    0,             "vv"         },
  { "dagger",  0,             "+"          },
  { "darr",    0,             "v"          },
  { "deg",     LATIN1_deg,    "DEG"        },
  { "delta",   0,             "d"          },
//  { "diams",   0,             "[diamonds]" },
  { "divide",  LATIN1_divide, "/"          },
  { "eacute",  LATIN1_eacute, "e'"         },
  { "ecirc",   LATIN1_ecirc,  "e^"         },
  { "egrave",  LATIN1_egrave, "e`"         },
  { "empty",   0,             "{}"         },
  { "epsilon", 0,             "e"          },
  { "equiv",   0,             "=="         },
  { "eta",     0,             "e"          },
  { "eth",     LATIN1_eth,    "d-"         },
  { "euml",    LATIN1_euml,   "e\""        },
  { "euro",    0,             "EUR"        },
  { "exist",   0,             "TE"         },
  { "fnof",    0,             "f"          },
  { "forall",  0,             "FA"         },
  { "frac12",  LATIN1_frac12, " 1/2"       },
  { "frac14",  LATIN1_frac14, " 1/4"       },
  { "frac34",  LATIN1_frac34, " 3/4"       },
  { "frasl",   0,             "/"          },
  { "gamma",   0,             "g"          },
  { "ge",      0,             ">="         },
  { "gt",      0,             ">"          },
  { "hArr",    0,             "<=>"        },
  { "harr",    0,             "<->"        },
//  { "hearts",  0,             "[hearts]"   },
  { "hellip",  0,             "..."        },
  { "iacute",  LATIN1_iacute, "i'"         },
  { "icirc",   LATIN1_icirc,  "i^"         },
  { "iexcl",   LATIN1_iexcl,  "!"          },
  { "igrave",  LATIN1_igrave, "i`"         },
  { "image",   0,             "Im"         },
  { "infin",   0,             "oo"         },
  { "int",     0,             "INT"        },
  { "iota",    0,             "i"          },
  { "iquest",  LATIN1_iquest, "?"          },
  { "isin",    0,             "(-"         },
  { "iuml",    LATIN1_iuml,   "i\""        },
  { "kappa",   0,             "k"          },
  { "lArr",    0,             "<="         },
  { "lambda",  0,             "l"          },
  { "lang",    0,             "</"         },
  { "laquo",   LATIN1_laquo,  "<<"         },
  { "larr",    0,             "<-"         },
//  { "lceil",   0,             "<|"         },
  { "ldquo",   0,             "\""         },
  { "le",      0,             "<="         },
//  { "lfloor",  0,             "|<"         },
  { "lowast",  0,             "*"          },
  { "loz",     0,             "<>"         },
  { "lsaquo",  0,             "<"          },
  { "lsquo",   0,             "`"          },
  { "lt",      0,             "<"          },
  { "macr",    LATIN1_macr,   "-"          },
  { "mdash",   0,             "--"         },
  { "micro",   LATIN1_micro,  "my"         },
  { "middot",  LATIN1_middot, "."          },
  { "minus",   0,             "-"          },
  { "mu",      0,             "m"          },
  { "nabla",   0,             "Nabla"      },
  { "nbsp",    LATIN1_nbsp,   " "          },
  { "ndash",   0,             "-"          },
  { "ne",      0,             "!="         },
  { "ni",      0,             "-)"         },
  { "not",     LATIN1_not,    "NOT"        },
  { "notin",   0,             "!(-"        },
  { "nsub",    0,             "!(C"        },
  { "ntilde",  LATIN1_ntilde, "n~"         },
  { "nu",      0,             "n"          },
  { "oacute",  LATIN1_oacute, "o'"         },
  { "ocirc",   LATIN1_ocirc,  "o^"         },
  { "oelig",   0,             "oe"         },
  { "ograve",  LATIN1_ograve, "o`"         },
  { "oline",   LATIN1_macr,   "-"          },
  { "omega",   0,             "o"          },
  { "omicron", 0,             "o"          },
  { "oplus",   0,             "(+)"        },
  { "or",      0,             "OR"         },
  { "ordf",    LATIN1_ordf,   "-a"         },
  { "ordm",    LATIN1_ordm,   "-o"         },
  { "oslash",  LATIN1_oslash, "o/"         },
  { "otilde",  LATIN1_otilde, "o~"         },
  { "otimes",  0,             "(x)"        },
  { "ouml",    LATIN1_ouml,   "o\""        },
  { "para",    LATIN1_para,   "P:"         },
  { "part",    0,             "PART"       },
  { "permil",  0,             " 0/00"      },
  { "perp",    0,             "-T"         },
  { "phi",     0,             "f"          },
  { "pi",      0,             "p"          },
  { "piv",     0,             "Pi"         },
  { "plusmn",  LATIN1_plusmn, "+/-"        },
  { "pound",   LATIN1_pound,  "-L-"        },
  { "prime",   0,             "'"          },
  { "prod",    0,             "PROD"       },
  { "prop",    0,             "0("         },
  { "psi",     0,             "ps"         },
  { "quot",    0,             "\""         },
  { "rArr",    0,             "=>"         },
  { "radic",   0,             "SQRT"       },
  { "rang",    0,             "/>"         },
  { "raquo",   LATIN1_raquo,  ">>"         },
  { "rarr",    0,             "->"         },
//  { "rceil",   0,             ">|"         },
  { "rdquo",   0,             "\""         },
  { "real",    0,             "Re"         },
  { "reg",     LATIN1_reg,    "(R)"        },
//  { "rfloor",  0,             "|>"         },
  { "rho",     0,             "r"          },
  { "rsaquo",  0,             ">"          },
  { "rsquo",   0,             "'"          },
  { "sbquo",   0,             "'"          },
  { "scaron",  0,             "s"          },
  { "sdot",    0,             "DOT"        },
  { "sect",    LATIN1_sect,   "S:"         },
  { "shy",     LATIN1_shy,    ""           },
  { "sigma",   0,             "s"          },
  { "sigmaf",  0,             "s"          },
  { "sim",     0,             "~"          },
//  { "spades",  0,             "[spades]"   },
  { "sub",     0,             "(C"         },
  { "sube",    0,             "(_"         },
  { "sum",     0,             "SUM"        },
  { "sup",     0,             ")C"         },
  { "sup1",    LATIN1_sup1,   "^1"         },
  { "sup2",    LATIN1_sup2,   "^2"         },
  { "sup3",    LATIN1_sup3,   "^3"         },
  { "supe",    0,             ")_"         },
  { "szlig",   LATIN1_szlig,  "ss"         },
  { "tau",     0,             "t"          },
  { "there4",  0,             ".:"         },
  { "theta",   0,             "th"         },
  { "thorn",   LATIN1_thorn,  "th"         },
  { "tilde",   0,             "~"          },
  { "times",   LATIN1_times,  "x"          },
  { "trade",   0,             "[TM]"       },
  { "uArr",    0,             "^^"         },
  { "uacute",  LATIN1_uacute, "u'"         },
  { "uarr",    0,             "^"          },
  { "ucirc",   LATIN1_ucirc,  "u^"         },
  { "ugrave",  LATIN1_ugrave, "u`"         },
  { "uml",     LATIN1_uml,    "\""         },
  { "upsilon", 0,             "u"          },
  { "uuml",    LATIN1_uuml,   "u\""        },
  { "weierp",  0,             "P"          },
  { "xi",      0,             "x"          },
  { "yacute",  LATIN1_yacute, "y'"         },
  { "yen",     LATIN1_yen,    "YEN"        },
  { "yuml",    LATIN1_yuml,   "y\""        },
  { "zeta",    0,             "z"          },
};

extern int use_iso8859;

/* ------------------------------------------------------------------------- */

void
replace_sgml_entities(string *s)
{
  string::size_type j = 0;
  
  for (;;) {
    string::size_type l = s->length();

    /*
     * Skip characters before ampersand.
     */
    while (j < l && s->at(j) != '&') ++j;
    /*
     * We could convert high-bit chars to "&#233;" here if use_iso8859
     * is off, then let them be translated or not.  Is the purpose of
     * !use_iso8859 to allow SGML entities to be seen, or to strongly
     * filter against high-ASCII chars that might blow up a terminal
     * that doesn't speak ISO8859?  For the moment, "allow SGML entities
     * to be seen" -- no filtering here.
     */
    if (j >= l) break;

    /*
     * So we have an ampersand...
     */

    /*
     * Don't process the last three characters; an SGML entity wouldn't fit
     * in anyway!
     */
    if (j + 3 >= l) break;          // Watch out! Unsigned arithmetics!

    string::size_type beg = j++;    // Skip the ampersand;

    /*
     * Look at the next character.
     */
    char c = s->at(j++);
    if (c == '#') {

      /*
       * Decode entities like "&#233;".
       * Some authors forget the ";", but we tolerate this.
       */
      c = s->at(j++);
      if (isdigit(c)) {
        int x = c - '0';
        for (; j < l; ++j) {
          c = s->at(j);
          if (c == ';') { ++j; break; }
          if (!isdigit(c)) break;
          x = 10 * x + c - '0';
        }
        if (use_iso8859 || (x < 128)) {
        s->replace(beg, j - beg, 1, (char) x);
        j = beg + 1;
        } else {
          for (int i = 0; i < nelems(entities); i++) {
            if (x == entities[i].iso8859code) {
              s->replace(beg, j - beg, entities[i].asciistr);
              break;
            }
          }
          /* else don't replace it at all, we don't have a translation */
        }
      }
    } else

    if (isalpha(c)) {

      /*
       * Decode entities like "&nbsp;".
       * Some authors forget the ";", but we tolerate this.
       */
      char name[8];
      name[0] = c;
      size_t i = 1;
      for (; j < l; ++j) {
        c = s->at(j);
        if (c == ';') { ++j; break; }
        if (!isalnum(c)) break;
        if (i < sizeof(name) - 1) name[i++] = c;
      }
      name[i] = '\0';

      const TextToInt *entity = (const TextToInt *) bsearch(
        name,
        entities, nelems(entities), sizeof(TextToInt),
        (int (*)(const void *, const void *)) strcmp
      );
      if (entity != NULL) {
        if (use_iso8859 && entity->iso8859code) {
          s->replace(beg, j - beg, 1, (char) entity->iso8859code);
          j = beg + 1;
        } else if (entity->asciistr) {
          s->replace(beg, j - beg, entity->asciistr);
        j = beg + 1;
        } /* else don't replace it at all, we don't have a translation */
      }
    } else {
      ;                         /* EXTENSION: Allow literal '&' sometimes. */
    }
  }
}

/* ------------------------------------------------------------------------- */

