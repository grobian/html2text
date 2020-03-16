/* GNU */

#ifndef HTML_DRIVER_H
#define HTML_DRIVER_H 1

#include "HTMLParser.tab.hh"
#include "HTMLControl.h"

class HTMLDriver {
	public:
		HTMLDriver(HTMLControl &c,
				ostream& os_,
				bool& enable_links_,
				int& width_,
				int& mode_,
				bool& debug_parser);

		int parse();
		int lex(html2text::HTMLParser::semantic_type * const lval);
		void yyerror(const char *msg);
		void process(const Document&);
		bool read_cdata(const char *terminal, string *);
		int list_nesting = 0;

		enum {
			PRINT_AS_ASCII, UNPARSE, SYNTAX_CHECK
		};

	private:
		HTMLControl& control;
		bool trace_parsing;
		bool enable_links;
		int width;
		int mode;
		ostream& os;

		html2text::HTMLParser::semantic_type *yylval = nullptr;
};

#endif
