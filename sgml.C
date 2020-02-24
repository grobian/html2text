
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
  unsigned long unicode;
} entities[] = {
  { "AElig",   LATIN1_AElig,  "AE",  0x00c6},
  { "AMP",     0,             "&",   0x0026},
  { "Aacute",  LATIN1_Aacute, "A'",  0x00c1},
  { "Acirc",   LATIN1_Acirc,  "A^",  0x00c2},
  { "Agrave",  LATIN1_Agrave, "A`",  0x00c0},
  { "Alpha",   0,             "A",   0x0391},
  { "Aring",   LATIN1_Aring,  "AA",  0x00c5},
  { "Atilde",  LATIN1_Atilde, "A~",  0x00c3},
  { "Auml",    LATIN1_Auml,   "A\"", 0x00c4},
  { "Beta",    0,             "B",   0x0392},
  { "Ccedil",  LATIN1_Ccedil, "C,",  0x00c7},
  { "Chi",     0,             "H",   0x03a7},
  { "Dagger",  0,             "++",  0x2020},
  { "Delta",   0,             "D",   0x0394},
  { "ETH",     LATIN1_ETH,    "D-",  0x00d0},
  { "Eacute",  LATIN1_Eacute, "E'",  0x00c9},
  { "Ecirc",   LATIN1_Ecirc,  "E^",  0x00ca},
  { "Egrave",  LATIN1_Egrave, "E`",  0x00c8},
  { "Epsilon", 0,             "E",   0x0395},
  { "Eta",     0,             "E",   0x0397},
  { "Euml",    LATIN1_Euml,   "E\"", 0x00cb},
  { "GT",      0,             ">",   0x003e},
  { "Gamma",   0,             "G",   0x0393},
  { "Iacute",  LATIN1_Iacute, "I'",  0x00cd},
  { "Icirc",   LATIN1_Icirc,  "I^",  0x00ce},
  { "Igrave",  LATIN1_Igrave, "I`",  0x00cc},
  { "Iota",    0,             "I",   0x0399},
  { "Iuml",    LATIN1_Iuml,   "I\"", 0x00cf},
  { "Kappa",   0,             "K",   0x039a},
  { "LT",      0,             "<",   0x003c},
  { "Lambda",  0,             "L",   0x039b},
  { "Mu",      0,             "M",   0x039c},
  { "Ntilde",  LATIN1_Ntilde, "N~",  0x00d1},
  { "Nu",      0,             "N",   0x039d},
  { "OElig",   0,             "OE",  0x0152},
  { "Oacute",  LATIN1_Oacute, "O'",  0x00d3},
  { "Ocirc",   LATIN1_Ocirc,  "O^",  0x00d4},
  { "Ograve",  LATIN1_Ograve, "O`",  0x00d2},
  { "Omega",   0,             "O",   0x03a9},
  { "Omicron", 0,             "O",   0x039f},
  { "Oslash",  LATIN1_Oslash, "O/",  0x00d8},
  { "Otilde",  LATIN1_Otilde, "O~",  0x00d5},
  { "Ouml",    LATIN1_Ouml,   "O\"", 0x00d6},
  { "Phi",     0,             "F",   0x03a6},
  { "Pi",      0,             "P",   0x03a0},
  { "Prime",   0,             "''",        },
  { "Psi",     0,             "PS",  0x03a8},
  { "QUOT",    0,             "\"",        },
  { "Rho",     0,             "R",   0x03a1},
  { "Scaron",  0,             "S",   0x0161},
  { "Sigma",   0,             "S",   0x03a3},
  { "THORN",   LATIN1_THORN,  "TH",  0x00de},
  { "Tau",     0,             "T",   0x03a4},
  { "Theta",   0,             "TH",  0x0398},
  { "Uacute",  LATIN1_Uacute, "U'",  0x00da},
  { "Ucirc",   LATIN1_Ucirc,  "U^",  0x00db},
  { "Ugrave",  LATIN1_Ugrave, "U`",  0x00d9},
  { "Upsilon", 0,             "U",   0x03a5},
  { "Uuml",    LATIN1_Uuml,   "U\"", 0x00dc},
  { "Xi",      0,             "X",   0x039e},
  { "Yacute",  LATIN1_Yacute, "Y'",  0x00dd},
  { "Yuml",    0,             "Y\"", 0x0178},
  { "Zeta",    0,             "Z",   0x0396},
  { "aacute",  LATIN1_aacute, "a'",  0x00e1},
  { "acirc",   LATIN1_acirc,  "a^",  0x00e2},
  { "acute",   LATIN1_acute,  "'",   0x00b4},
  { "aelig",   LATIN1_aelig,  "ae",  0x00e6},
  { "agrave",  LATIN1_agrave, "a`",  0x00e0},
  { "alefsym", 0,             "Aleph"      },
  { "alpha",   0,             "a",   0x03b1},
  { "amp",     0,             "&"          },
  { "and",     0,             "AND"        },
  { "ang",     0,             "-V"         },
  { "apos",    0,             "'"          },
  { "aring",   LATIN1_aring,  "aa",  0x00e5},
  { "asymp",   0,             "~=",  0x2248},
  { "atilde",  LATIN1_atilde, "a~",  0x00e3},
  { "auml",    LATIN1_auml,   "a\"", 0x00e5},
  { "bdquo",   0,             "\""         },
  { "beta",    0,             "b",   0x03b2},
  { "brvbar",  LATIN1_brvbar, "|",   0x00a6},
  { "bull",    0,             " o ", 0x2022},
  { "cap",     0,             "(U"         },
  { "ccedil",  LATIN1_ccedil, "c,",  0x00e7},
  { "cedil",   LATIN1_cedil,  ",",   0x00b8},
  { "cent",    LATIN1_cent,   "-c-", 0x00a2},
  { "chi",     0,             "h",   0x03c7},
  { "circ",    0,             "^",   0x005e},
//  { "clubs",   0,             "[clubs]"    },
  { "cong",    0,             "?="         },
  { "copy",    LATIN1_copy,   "(c)", 0x00a9},
  { "crarr",   0,             "<-'"        },
  { "cup",     0,             ")U"         },
  { "curren",  LATIN1_curren, "CUR", 0x00a4},
  { "dArr",    0,             "vv"         },
  { "dagger",  0,             "+",   0x2020},
  { "darr",    0,             "v"          },
  { "deg",     LATIN1_deg,    "DEG", 0x00b0},
  { "delta",   0,             "d",   0x03b4},
//  { "diams",   0,             "[diamonds]" },
  { "divide",  LATIN1_divide, "/",   0x00f7},
  { "eacute",  LATIN1_eacute, "e'",  0x00e9},
  { "ecirc",   LATIN1_ecirc,  "e^",  0x00ea},
  { "egrave",  LATIN1_egrave, "e`",  0x00e8},
  { "empty",   0,             "{}"         },
  { "epsilon", 0,             "e",   0x03b5},
  { "equiv",   0,             "==",  0x2261},
  { "eta",     0,             "e",   0x03b7},
  { "eth",     LATIN1_eth,    "d-",  0x00f0},
  { "euml",    LATIN1_euml,   "e\"", 0x00eb},
  { "euro",    0,             "EUR", 0x20ac},
  { "exist",   0,             "TE"         },
  { "fnof",    0,             "f"          },
  { "forall",  0,             "FA"         },
  { "frac12",  LATIN1_frac12, " 1/2",0x00bd},
  { "frac14",  LATIN1_frac14, " 1/4",0x00bc},
  { "frac34",  LATIN1_frac34, " 3/4",0x00be},
  { "frasl",   0,             "/"          },
  { "gamma",   0,             "g",   0x03b3},
  { "ge",      0,             ">=",  0x2265},
  { "gt",      0,             ">",   0x003e},
  { "hArr",    0,             "<=>"        },
  { "harr",    0,             "<->"        },
//  { "hearts",  0,             "[hearts]"   },
  { "hellip",  0,             "...", 0x2026},
  { "iacute",  LATIN1_iacute, "i'",  0x00ed},
  { "icirc",   LATIN1_icirc,  "i^",  0x00ee},
  { "iexcl",   LATIN1_iexcl,  "!",   0x00a1},
  { "igrave",  LATIN1_igrave, "i`",  0x00ec},
  { "image",   0,             "Im"         },
  { "infin",   0,             "oo",  0x221e},
  { "int",     0,             "INT", 0x222b},
  { "iota",    0,             "i",   0x03b9},
  { "iquest",  LATIN1_iquest, "?",   0x00bf},
  { "isin",    0,             "(-"         },
  { "iuml",    LATIN1_iuml,   "i\"", 0x00ef},
  { "kappa",   0,             "k",   0x03ba},
  { "lArr",    0,             "<="         },
  { "lambda",  0,             "l",   0x03bb},
  { "lang",    0,             "</"         },
  { "laquo",   LATIN1_laquo,  "<<"         },
  { "larr",    0,             "<-",  0x2190},
//  { "lceil",   0,             "<|"         },
  { "ldquo",   0,             "\""         },
  { "le",      0,             "<=",  0x2264},
//  { "lfloor",  0,             "|<"         },
  { "lowast",  0,             "*"          },
  { "loz",     0,             "<>"         },
  { "lsaquo",  0,             "<"          },
  { "lsquo",   0,             "`"          },
  { "lt",      0,             "<",   0x003c},
  { "macr",    LATIN1_macr,   "-",   0x00af},
  { "mdash",   0,             "--"         },
  { "micro",   LATIN1_micro,  "my",  0x00b5},
  { "middot",  LATIN1_middot, ".",   0x00b7},
  { "minus",   0,             "-",   0x2212},
  { "mu",      0,             "m",   0x03bc},
  { "nabla",   0,             "Nabla"      },
  { "nbsp",    LATIN1_nbsp,   " ",   0x00a0},
  { "ndash",   0,             "-"          },
  { "ne",      0,             "!=",  0x2260},
  { "ni",      0,             "-)"         },
  { "not",     LATIN1_not,    "NOT"        },
  { "notin",   0,             "!(-"        },
  { "nsub",    0,             "!(C"        },
  { "ntilde",  LATIN1_ntilde, "n~",  0x00f1},
  { "nu",      0,             "n",   0x03bd},
  { "oacute",  LATIN1_oacute, "o'",  0x00f3},
  { "ocirc",   LATIN1_ocirc,  "o^",  0x00f4},
  { "oelig",   0,             "oe"         },
  { "ograve",  LATIN1_ograve, "o`",  0x00f2},
  { "oline",   LATIN1_macr,   "-"          },
  { "omega",   0,             "o",   0x03c9},
  { "omicron", 0,             "o",   0x03bf},
  { "oplus",   0,             "(+)"        },
  { "or",      0,             "OR"         },
  { "ordf",    LATIN1_ordf,   "-a",  0x00aa},
  { "ordm",    LATIN1_ordm,   "-o",  0x00ba},
  { "oslash",  LATIN1_oslash, "o/",  0x00f8},
  { "otilde",  LATIN1_otilde, "o~",  0x00f5},
  { "otimes",  0,             "(x)"        },
  { "ouml",    LATIN1_ouml,   "o\"", 0x00f6},
  { "para",    LATIN1_para,   "P:",  0x00b6},
  { "part",    0,             "PART",0x2202},
  { "permil",  0,             " 0/00",0x2030},
  { "perp",    0,             "-T"         },
  { "phi",     0,             "f",   0x03c6},
  { "pi",      0,             "p",   0x03c0},
  { "piv",     0,             "Pi"         },
  { "plusmn",  LATIN1_plusmn, "+/-", 0x00b1},
  { "pound",   LATIN1_pound,  "-L-", 0x00a3},
  { "prime",   0,             "'"          },
  { "prod",    0,             "PROD",0x220f},
  { "prop",    0,             "0("         },
  { "psi",     0,             "ps",  0x03c8},
  { "quot",    0,             "\""         },
  { "rArr",    0,             "=>"         },
  { "radic",   0,             "SQRT",0x221a},
  { "rang",    0,             "/>"         },
  { "raquo",   LATIN1_raquo,  ">>"         },
  { "rarr",    0,             "->",  0x2192},
//  { "rceil",   0,             ">|"         },
  { "rdquo",   0,             "\""         },
  { "real",    0,             "Re"         },
  { "reg",     LATIN1_reg,    "(R)", 0x00ae},
//  { "rfloor",  0,             "|>"         },
  { "rho",     0,             "r",   0x03c1},
  { "rsaquo",  0,             ">"          },
  { "rsquo",   0,             "'"          },
  { "sbquo",   0,             "'"          },
  { "scaron",  0,             "s",   0x0161},
  { "sdot",    0,             "DOT"        },
  { "sect",    LATIN1_sect,   "S:",  0x00a7},
  { "shy",     LATIN1_shy,    ""           },
  { "sigma",   0,             "s",   0x03c3},
  { "sigmaf",  0,             "s",   0x03c2},
  { "sim",     0,             "~"          },
//  { "spades",  0,             "[spades]"   },
  { "sub",     0,             "(C"         },
  { "sube",    0,             "(_"         },
  { "sum",     0,             "SUM", 0x2211},
  { "sup",     0,             ")C"         },
  { "sup1",    LATIN1_sup1,   "^1",  0x00b9},
  { "sup2",    LATIN1_sup2,   "^2",  0x00b2},
  { "sup3",    LATIN1_sup3,   "^3",  0x00b3},
  { "supe",    0,             ")_"         },
  { "szlig",   LATIN1_szlig,  "ss",  0x00df},
  { "tau",     0,             "t",   0x03c4},
  { "there4",  0,             ".:"         },
  { "theta",   0,             "th",  0x03b8},
  { "thorn",   LATIN1_thorn,  "th",  0x00fe},
  { "tilde",   0,             "~",   0x02dc},
  { "times",   LATIN1_times,  "x",   0x00d7},
  { "trade",   0,             "[TM]",0x2122},
  { "uArr",    0,             "^^"         },
  { "uacute",  LATIN1_uacute, "u'",  0x00fa},
  { "uarr",    0,             "^"          },
  { "ucirc",   LATIN1_ucirc,  "u^",  0x00fb},
  { "ugrave",  LATIN1_ugrave, "u`",  0x00f9},
  { "uml",     LATIN1_uml,    "\"",  0x00a8},
  { "upsilon", 0,             "u",   0x03c5},
  { "uuml",    LATIN1_uuml,   "u\"", 0x00fc},
  { "weierp",  0,             "P"          },
  { "xi",      0,             "x",   0x03be},
  { "yacute",  LATIN1_yacute, "y'",  0x00fd},
  { "yen",     LATIN1_yen,    "YEN", 0x00a5},
  { "yuml",    LATIN1_yuml,   "y\"", 0x00ff},
  { "zeta",    0,             "z",   0x03b6},
};

extern int use_encoding;

/* ------------------------------------------------------------------------- */

char ubuf[4];

char *mkutf(unsigned long x)
{
  memset(ubuf, 0, 4);
  if(x < 128) ubuf[0] = x;
  else if(x < 0x800) {
     ubuf[0] = (0xc0 | ((x >> 6) & 0x1f));
     ubuf[1] = (0x80 | (x & 0x3f));
  }
  else {
     ubuf[0] = (0xe0 | ((x >> 12) & 0x0f));
     ubuf[1] = (0x80 | ((x >> 6) & 0x3f));
     ubuf[2] = (0x80 | (x & 0x3f));
  }
  return ubuf;
}

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
     * We could convert high-bit chars to "&#233;" here if USE_ASCII
     * is on, then let them be translated or not.  Is the purpose of
     * USE_ASCII to allow SGML entities to be seen, or to strongly
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
        if (USE_UTF8) {
          s->replace(beg, j - beg, mkutf(x));
          j = beg + 1;
        }
        else if (USE_ISO8859 && (x < 256) || USE_ASCII && (x < 128)) {
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
        if (USE_ISO8859 && entity->iso8859code) {
          s->replace(beg, j - beg, 1, (char) entity->iso8859code);
          j = beg + 1;
        } else if (USE_ASCII && entity->asciistr) {
          s->replace(beg, j - beg, entity->asciistr);
        j = beg + 1;
        } /* else don't replace it at all, we don't have a translation */
        else if(USE_UTF8 && entity->unicode) {
        s->replace(beg, j - beg, mkutf(entity->unicode));
        j = beg + 1;
        }
      }
    } else {
      ;                         /* EXTENSION: Allow literal '&' sometimes. */
    }
  }
}

/* ------------------------------------------------------------------------- */

