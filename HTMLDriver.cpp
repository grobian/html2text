/* GNU */

#include "HTMLDriver.h"
#include "HTMLControl.h"
#include "HTMLParser.tab.hh"

extern OrderedList *links;

HTMLDriver::HTMLDriver(HTMLControl& c,
		ostream& os_,
		bool& enable_links_,
		int& width_,
		int& mode_,
		bool& debug_parser) :
	control(c),
	os(os_),
	enable_links(enable_links_),
	width(width_),
	mode(mode_),
	trace_parsing(debug_parser)
{
};

int HTMLDriver::parse()
{
	html2text::HTMLParser parse(*this);
	parse.set_debug_level(trace_parsing);
	return parse();
}

int HTMLDriver::lex(html2text::HTMLParser::semantic_type * const lval)
{
	return control.htmlparser_yylex(lval);
}

void HTMLDriver::process(const Document& document)
{
	switch (mode) {
	case PRINT_AS_ASCII:
		if (enable_links && links->items->size() > 0) {
			Heading *h = new Heading;
			PCData *d = new PCData;
			h->level = 6;
			d->text = "References";
			list<auto_ptr<Element>> *data = new list<auto_ptr<Element>>;
			data->push_back(auto_ptr<Element>(d));
			h->content.reset(data);
			document.body.content->push_back(auto_ptr<Element>(h));
			document.body.content->push_back(auto_ptr<Element>(links));
		}

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

bool HTMLDriver::read_cdata(const char *terminal, string *ret)
{
	return control.read_cdata(terminal, ret);
}

void HTMLDriver::yyerror(const char *msg)
{
	return control.htmlparser_yyerror(msg);
}
