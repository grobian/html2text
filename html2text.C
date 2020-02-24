
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
 * Fre Jun  8 19:00:26 CEST 2001: new image handling
 * Thu Oct  4 21:42:24 CEST 2001: ported to g++ 3.0, bugfix for '-' as synonym for STDIN
 * Mon Jul 22 13:48:26 CEST 2002: Made finaly reading from STDIN work.
 * Sat Sep 14 15:04:09 CEST 2002: Added plain ASCII output patch by Bela Lubkin
 * Wed Jul  2 22:08:45 CEST 2003: ported to g++ 3.3
 */
  
 /***************************************************************************/


#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "html.h"
#include "HTMLControl.h"
#include "urlistream.h"
#include "format.h"

#define stringify(x) stringify2(x)
#define stringify2(x) #x

/* ------------------------------------------------------------------------- */

class MyParser : public HTMLControl {

public:
  enum { PRINT_AS_ASCII, UNPARSE, SYNTAX_CHECK };

  MyParser(
    urlistream &is_,
    bool       debug_scanner_,
    bool       debug_parser_,
    ostream    &os_,
    int        mode_,
    int        width_,
    const char *file_name_
  ) :
    HTMLControl(is_, debug_scanner_, debug_parser_),
    os(os_),
    mode(mode_),
    width(width_),
    file_name(file_name_)
  {}

private:
  /*virtual*/ void yyerror(char *);
  /*virtual*/ void process(const Document &);

  ostream &os;
  int     mode;
  int     width;
  string  file_name;
};

/*virtual*/ void
MyParser::yyerror(char *p)
{

  /*
   * Swallow parse error messages if not in "syntax check" mode.
   */
  if (mode != SYNTAX_CHECK && !strcmp(p, "parse error")) return;

  std::cerr
    << "File \""
    << file_name
    << "\", line "
    << current_line
    << ", column "
    << current_column
    << ": "
    << p
    << std::endl;
}

/*virtual*/ void
MyParser::process(const Document &document)
{
  switch (mode) {

  case PRINT_AS_ASCII:
    document.format(/*indent_left*/ 0, width, Area::LEFT, os);
    break;

  case UNPARSE:
    document.unparse(os, std::endl);
    break;

  case SYNTAX_CHECK:
    break;

  default:
    std::cerr << "??? Invalid mode " << mode << " ??? " << std::endl;
    exit(1);
    break;
  }
}

/* ------------------------------------------------------------------------- */

static const char *usage = "\
Usage:\n\
  html2text -help\n\
  html2text -version\n\
  html2text [ -unparse | -check ] [ -debug-scanner ] [ -debug-parser ] \\\n\
     [ -rcfile <file> ] [ -style ( compact | pretty ) ] [ -width <w> ] \\\n\
     [ -o <file> ] [ -nobs ] [ -ascii ] [ <input-url> ] ...\n\
Formats HTML document(s) read from <input-url> or STDIN and generates ASCII\n\
text.\n\
  -help          Print this text and exit\n\
  -version       Print program version and copyright notice\n\
  -unparse       Generate HTML instead of ASCII output\n\
  -check         Do syntax checking only\n\
  -debug-scanner Report parsed tokens on STDERR (debugging)\n\
  -debug-parser  Report parser activity on STDERR (debugging)\n\
  -rcfile <file> Read <file> instead of \"$HOME/.html2textrc\"\n\
  -style compact Create a \"compact\" output format (default)\n\
  -style pretty  Insert some vertical space for nicer output\n\
  -width <w>     Optimize for screen widths other than 79\n\
  -o <file>      Redirect output into <file>\n\
  -nobs          Do not use backspaces for boldface and underlining\n\
  -ascii         Use plain ASCII for output instead of ISO-8859-1\n\
";

int use_iso8859 = 1;

int
main(int argc, char **argv)
{
  if (argc == 2 && !strcmp(argv[1], "-help")) {
    std::cout
      << "This is html2text, version " stringify(VERSION) << std::endl
      << std::endl
      << usage;
    exit(0);
  }

  if (argc == 2 && !strcmp(argv[1], "-version")) {
    std::cout
      << "This is html2text, version " stringify(VERSION) << std::endl
      << std::endl
      << "The latest version can be found at http://userpage.fu-berlin.de/~mbayer/tools/" << std::endl
      << std::endl
      << "This program is distributed in the hope that it will be useful, but WITHOUT" << std::endl
      << "ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS" << std::endl
      << "FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details." << std::endl
      << std::endl;
    exit(0);
  }

  bool       mode              = MyParser::PRINT_AS_ASCII;
  bool       debug_scanner     = false;
  bool       debug_parser      = false;
  const char *home             = getenv("HOME");
  string     rcfile            = string(home ? home : "") + "/.html2textrc";
  const char *style            = "compact";
  int        width             = 79;
  const char *output_file_name = "-";
  bool       use_backspaces    = true;

  int i;
  for (i = 1; i < argc && argv[i][0] == '-' && argv[i][1]; i++) {
    const char *arg = argv[i];

    if (!strcmp(arg, "-unparse"      )) { mode = MyParser::UNPARSE;      } else
    if (!strcmp(arg, "-check"        )) { mode = MyParser::SYNTAX_CHECK; } else
    if (!strcmp(arg, "-debug-scanner")) { debug_scanner = true;          } else
    if (!strcmp(arg, "-debug-parser" )) { debug_parser = true;           } else
    if (!strcmp(arg, "-rcfile"       )) { rcfile = argv[++i];            } else
    if (!strcmp(arg, "-style"        )) { style = argv[++i];             } else
    if (!strcmp(arg, "-width"        )) { width = atoi(argv[++i]);       } else
    if (!strcmp(arg, "-o"            )) { output_file_name = argv[++i];  } else
    if (!strcmp(arg, "-nobs"         )) { use_backspaces = false;        } else
    if (!strcmp(arg, "-ascii"        )) { use_iso8859 = false;           } else
    {
      std::cerr
	<< "Unrecognized command line option \""
	<< arg
	<< "\", try \"-help\"."
	<< std::endl;
      exit(1);
    }
  }
  if (i > argc) {
    std::cerr
      << "Error: Required parameter after \""
      << argv[argc - 1]
      << "\" missing."
      << std::endl;
    exit(1);
  }

  const char *const *input_urls;
  int        number_of_input_urls;

  if (i >= argc) {
    static const char *const x = "-";
    input_urls = &x;
    number_of_input_urls = 1;
  } else {
    input_urls = argv + i;
    number_of_input_urls = argc - i;
  }

  /*
   * Set up formatting: First, set some formatting properties depending on
   * the "-style" command line option.
   */
  if (!strcmp(style, "compact")) {
    ;
  } else
  if (!strcmp(style, "pretty")) {

    /*
     * The "pretty" style was kindly supplied by diligent user Rolf Niepraschk.
     */
    static const struct {
      const char *key;
      const char *value;
    } properties[] = {
      { "OL.TYPE",                  "1" },
      { "OL.vspace.before",         "1" },
      { "OL.vspace.after",          "1" },
      { "OL.indents",               "5" },
      { "UL.vspace.before",         "1" },
      { "UL.vspace.after",          "1" },
      { "UL.indents",               "2" },
      { "DL.vspace.before",         "1" },
      { "DL.vspace.after",          "1" },
      { "DT.vspace.before",         "1" },
      { "DIR.vspace.before",        "1" },
      { "DIR.indents",              "2" },
      { "MENU.vspace.before",       "1" },
      { "MENU.vspace.after",        "1" },
      { "DT.indent",                "2" },
      { "DD.indent",                "6" },
      { "HR.marker",                "-" },
      { "H1.prefix",                ""  },
      { "H2.prefix",                ""  },
      { "H3.prefix",                ""  },
      { "H4.prefix",                ""  },
      { "H5.prefix",                ""  },
      { "H6.prefix",                ""  },
      { "H1.suffix",                ""  },
      { "H2.suffix",                ""  },
      { "H3.suffix",                ""  },
      { "H4.suffix",                ""  },
      { "H5.suffix",                ""  },
      { "H6.suffix",                ""  },
      { "H1.vspace.before",         "2" },
      { "H2.vspace.before",         "1" },
      { "H3.vspace.before",         "1" },
      { "H4.vspace.before",         "1" },
      { "H5.vspace.before",         "1" },
      { "H6.vspace.before",         "1" },
      { "H1.vspace.after",          "1" },
      { "H2.vspace.after",          "1" },
      { "H3.vspace.after",          "1" },
      { "H4.vspace.after",          "1" },
      { "H5.vspace.after",          "1" },
      { "H6.vspace.after",          "1" },
      { "TABLE.vspace.before",      "1" },
      { "TABLE.vspace.after",       "1" },
      { "CODE.vspace.before",       "0" },
      { "CODE.vspace.after",        "0" },
      { "BLOCKQUOTE.vspace.before", "1" },
      { "BLOCKQUOTE.vspace.after",  "1" },
      { "PRE.vspace.before",        "1" },
      { "PRE.vspace.after",         "1" },
      { "PRE.indent.left",          "2" },
      { "IMG.replace.noalt",        ""  },
      { "IMG.alt.prefix",           " " },
      { "IMG.alt.suffix",           " " },
      { 0, 0 }
    }, *p;
    for (p = properties; p->key; ++p) {
      Formatting::setProperty(p->key, p->value);
    }
  } else {
    std::cerr
      << "Unknown style \""
      << style
      << "\" specified -- try \"-help\"."
      << std::endl;
    ::exit(1);
  }

  {
    std::ifstream ifs(rcfile.c_str());
    if (!ifs.rdbuf()->is_open()) ifs.open("/etc/html2textrc");
    if (ifs.rdbuf()->is_open()) {
      Formatting::loadProperties(ifs);
    }
  }

  /*
   * Set up printing.
   */
  Area::use_backspaces = use_backspaces;

  ostream  *osp;
  std::ofstream ofs;

  if (!strcmp(output_file_name, "-")) {
    osp = &std::cout;
  } else {
    ofs.open(output_file_name, std::ios::out);
    if (!ofs) {
      std::cerr
        << "Could not open output file \""
        << output_file_name
        << "\"."
        << std::endl;
    exit(1);
    }
    osp = &ofs;
  }

  for (i = 0; i < number_of_input_urls; ++i) {
    const char *input_url = input_urls[i];

    if (number_of_input_urls != 1) {
      *osp << "###### " << input_url << " ######" << std::endl;
    }

    istream    *isp;
    urlistream uis;

    uis.open(input_url);
    if (!uis.is_open()) {
      std::cerr
        << "Opening input URL \""
	<< input_url
        << "\": "
        << uis.open_error()
        << std::endl;
      exit(1);
    }

    MyParser parser(
      uis,
      debug_scanner,
      debug_parser,
      *osp,
      mode,
      width,
      input_url
    );

    if (parser.yyparse() != 0) exit(1);
  }

  return 0;
}

/* ------------------------------------------------------------------------- */
