#ifndef YY_HTMLParser_h_included
#define YY_HTMLParser_h_included

#line 1 "/usr/local/lib/bison.h"
/* before anything */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#endif
#include <stdio.h>

/* #line 14 "/usr/local/lib/bison.h" */
#define YY_HTMLParser_PURE 
#define YY_HTMLParser_DEBUG  1
#define YY_HTMLParser_LEX_BODY  = 0
#define YY_HTMLParser_ERROR_BODY  = 0
#define YY_HTMLParser_MEMBERS \
  virtual ~HTMLParser(); \
  virtual void process(const Document &) = 0;\
  virtual bool read_cdata(const char *terminal, string *) = 0;\
  int list_nesting;
#define YY_HTMLParser_CONSTRUCTOR_INIT  : list_nesting(0)

#line 69 "HTMLParser.y"
typedef union {
  Document                   *document;
  Element                    *element;
  list<auto_ptr<Element> >   *element_list;
  PCData                     *pcdata;
  string                     *strinG;
  list<TagAttribute>         *tag_attributes;
  int                        inT;
  list<auto_ptr<TableRow> >  *table_rows;
  list<auto_ptr<TableCell> > *table_cells;
  ListItem                   *list_item;
  list<auto_ptr<ListItem> >  *list_items;
  Caption                    *caption;
  Heading                    *heading;
  list<auto_ptr<Option> >    *option_list;
  Option                     *option;
  DefinitionList             *definition_list;
  list<auto_ptr<DefinitionListItem> > *definition_list_item_list;
  TermName                   *term_name;
  TermDefinition             *term_definition;
  Preformatted               *preformatted;
  Address                    *address;
  list<auto_ptr<list<TagAttribute> > > *tag_attributes_list;
} yy_HTMLParser_stype;
#define YY_HTMLParser_STYPE yy_HTMLParser_stype

#line 14 "/usr/local/lib/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_HTMLParser_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_HTMLParser_COMPATIBILITY 1
#else
#define  YY_HTMLParser_COMPATIBILITY 0
#endif
#endif

#if YY_HTMLParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_HTMLParser_LTYPE
#define YY_HTMLParser_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_HTMLParser_STYPE 
#define YY_HTMLParser_STYPE YYSTYPE
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
/* use %define STYPE */
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_HTMLParser_DEBUG
#define  YY_HTMLParser_DEBUG YYDEBUG
/* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
/* use %define DEBUG */
#endif
#endif
#ifdef YY_HTMLParser_STYPE
#ifndef yystype
#define yystype YY_HTMLParser_STYPE
#endif
#endif
#endif

#ifndef YY_HTMLParser_PURE

/* #line 54 "/usr/local/lib/bison.h" */

#line 54 "/usr/local/lib/bison.h"
/* YY_HTMLParser_PURE */
#endif

/* #line 56 "/usr/local/lib/bison.h" */

#line 56 "/usr/local/lib/bison.h"
/* prefix */
#ifndef YY_HTMLParser_DEBUG

/* #line 58 "/usr/local/lib/bison.h" */

#line 58 "/usr/local/lib/bison.h"
/* YY_HTMLParser_DEBUG */
#endif
#ifndef YY_HTMLParser_LSP_NEEDED

/* #line 61 "/usr/local/lib/bison.h" */

#line 61 "/usr/local/lib/bison.h"
 /* YY_HTMLParser_LSP_NEEDED*/
#endif
/* DEFAULT LTYPE*/
#ifdef YY_HTMLParser_LSP_NEEDED
#ifndef YY_HTMLParser_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_HTMLParser_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
#ifndef YY_HTMLParser_STYPE
#define YY_HTMLParser_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_HTMLParser_PARSE
#define YY_HTMLParser_PARSE yyparse
#endif
#ifndef YY_HTMLParser_LEX
#define YY_HTMLParser_LEX yylex
#endif
#ifndef YY_HTMLParser_LVAL
#define YY_HTMLParser_LVAL yylval
#endif
#ifndef YY_HTMLParser_LLOC
#define YY_HTMLParser_LLOC yylloc
#endif
#ifndef YY_HTMLParser_CHAR
#define YY_HTMLParser_CHAR yychar
#endif
#ifndef YY_HTMLParser_NERRS
#define YY_HTMLParser_NERRS yynerrs
#endif
#ifndef YY_HTMLParser_DEBUG_FLAG
#define YY_HTMLParser_DEBUG_FLAG yydebug
#endif
#ifndef YY_HTMLParser_ERROR
#define YY_HTMLParser_ERROR yyerror
#endif

#ifndef YY_HTMLParser_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_HTMLParser_PARSE_PARAM
#ifndef YY_HTMLParser_PARSE_PARAM_DEF
#define YY_HTMLParser_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_HTMLParser_PARSE_PARAM
#define YY_HTMLParser_PARSE_PARAM void
#endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

#ifndef YY_HTMLParser_PURE
extern YY_HTMLParser_STYPE YY_HTMLParser_LVAL;
#endif


/* #line 134 "/usr/local/lib/bison.h" */
#define	DOCTYPE	258
#define	PCDATA	259
#define	SCAN_ERROR	260
#define	A	261
#define	ADDRESS	262
#define	APPLET	263
#define	AREA	264
#define	B	265
#define	BASE	266
#define	BASEFONT	267
#define	BIG	268
#define	BLOCKQUOTE	269
#define	BODY	270
#define	BR	271
#define	CAPTION	272
#define	CENTER	273
#define	CITE	274
#define	CODE	275
#define	DD	276
#define	DFN	277
#define	DIR	278
#define	DIV	279
#define	DL	280
#define	DT	281
#define	EM	282
#define	FONT	283
#define	FORM	284
#define	H1	285
#define	H2	286
#define	H3	287
#define	H4	288
#define	H5	289
#define	H6	290
#define	HEAD	291
#define	HR	292
#define	HTML	293
#define	I	294
#define	IMG	295
#define	INPUT	296
#define	ISINDEX	297
#define	KBD	298
#define	LI	299
#define	LINK	300
#define	MAP	301
#define	MENU	302
#define	META	303
#define	NOBR	304
#define	OL	305
#define	OPTION	306
#define	P	307
#define	PARAM	308
#define	PRE	309
#define	SAMP	310
#define	SCRIPT	311
#define	SELECT	312
#define	SMALL	313
#define	STRIKE	314
#define	STRONG	315
#define	STYLE	316
#define	SUB	317
#define	SUP	318
#define	TABLE	319
#define	TD	320
#define	TEXTAREA	321
#define	TH	322
#define	TITLE	323
#define	TR	324
#define	TT	325
#define	U	326
#define	UL	327
#define	VAR	328
#define	END_A	329
#define	END_ADDRESS	330
#define	END_APPLET	331
#define	END_B	332
#define	END_BIG	333
#define	END_BLOCKQUOTE	334
#define	END_BODY	335
#define	END_CAPTION	336
#define	END_CENTER	337
#define	END_CITE	338
#define	END_CODE	339
#define	END_DD	340
#define	END_DFN	341
#define	END_DIR	342
#define	END_DIV	343
#define	END_DL	344
#define	END_DT	345
#define	END_EM	346
#define	END_FONT	347
#define	END_FORM	348
#define	END_H1	349
#define	END_H2	350
#define	END_H3	351
#define	END_H4	352
#define	END_H5	353
#define	END_H6	354
#define	END_HEAD	355
#define	END_HTML	356
#define	END_I	357
#define	END_KBD	358
#define	END_LI	359
#define	END_MAP	360
#define	END_MENU	361
#define	END_NOBR	362
#define	END_OL	363
#define	END_OPTION	364
#define	END_P	365
#define	END_PRE	366
#define	END_SAMP	367
#define	END_SCRIPT	368
#define	END_SELECT	369
#define	END_SMALL	370
#define	END_STRIKE	371
#define	END_STRONG	372
#define	END_STYLE	373
#define	END_SUB	374
#define	END_SUP	375
#define	END_TABLE	376
#define	END_TD	377
#define	END_TEXTAREA	378
#define	END_TH	379
#define	END_TITLE	380
#define	END_TR	381
#define	END_TT	382
#define	END_U	383
#define	END_UL	384
#define	END_VAR	385


#line 134 "/usr/local/lib/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
#ifndef YY_HTMLParser_CLASS
#define YY_HTMLParser_CLASS HTMLParser
#endif

#ifndef YY_HTMLParser_INHERIT
#define YY_HTMLParser_INHERIT
#endif
#ifndef YY_HTMLParser_MEMBERS
#define YY_HTMLParser_MEMBERS 
#endif
#ifndef YY_HTMLParser_LEX_BODY
#define YY_HTMLParser_LEX_BODY  
#endif
#ifndef YY_HTMLParser_ERROR_BODY
#define YY_HTMLParser_ERROR_BODY  
#endif
#ifndef YY_HTMLParser_CONSTRUCTOR_PARAM
#define YY_HTMLParser_CONSTRUCTOR_PARAM
#endif

class YY_HTMLParser_CLASS YY_HTMLParser_INHERIT
{
public: /* static const int token ... */

/* #line 160 "/usr/local/lib/bison.h" */
static const int DOCTYPE;
static const int PCDATA;
static const int SCAN_ERROR;
static const int A;
static const int ADDRESS;
static const int APPLET;
static const int AREA;
static const int B;
static const int BASE;
static const int BASEFONT;
static const int BIG;
static const int BLOCKQUOTE;
static const int BODY;
static const int BR;
static const int CAPTION;
static const int CENTER;
static const int CITE;
static const int CODE;
static const int DD;
static const int DFN;
static const int DIR;
static const int DIV;
static const int DL;
static const int DT;
static const int EM;
static const int FONT;
static const int FORM;
static const int H1;
static const int H2;
static const int H3;
static const int H4;
static const int H5;
static const int H6;
static const int HEAD;
static const int HR;
static const int HTML;
static const int I;
static const int IMG;
static const int INPUT;
static const int ISINDEX;
static const int KBD;
static const int LI;
static const int LINK;
static const int MAP;
static const int MENU;
static const int META;
static const int NOBR;
static const int OL;
static const int OPTION;
static const int P;
static const int PARAM;
static const int PRE;
static const int SAMP;
static const int SCRIPT;
static const int SELECT;
static const int SMALL;
static const int STRIKE;
static const int STRONG;
static const int STYLE;
static const int SUB;
static const int SUP;
static const int TABLE;
static const int TD;
static const int TEXTAREA;
static const int TH;
static const int TITLE;
static const int TR;
static const int TT;
static const int U;
static const int UL;
static const int VAR;
static const int END_A;
static const int END_ADDRESS;
static const int END_APPLET;
static const int END_B;
static const int END_BIG;
static const int END_BLOCKQUOTE;
static const int END_BODY;
static const int END_CAPTION;
static const int END_CENTER;
static const int END_CITE;
static const int END_CODE;
static const int END_DD;
static const int END_DFN;
static const int END_DIR;
static const int END_DIV;
static const int END_DL;
static const int END_DT;
static const int END_EM;
static const int END_FONT;
static const int END_FORM;
static const int END_H1;
static const int END_H2;
static const int END_H3;
static const int END_H4;
static const int END_H5;
static const int END_H6;
static const int END_HEAD;
static const int END_HTML;
static const int END_I;
static const int END_KBD;
static const int END_LI;
static const int END_MAP;
static const int END_MENU;
static const int END_NOBR;
static const int END_OL;
static const int END_OPTION;
static const int END_P;
static const int END_PRE;
static const int END_SAMP;
static const int END_SCRIPT;
static const int END_SELECT;
static const int END_SMALL;
static const int END_STRIKE;
static const int END_STRONG;
static const int END_STYLE;
static const int END_SUB;
static const int END_SUP;
static const int END_TABLE;
static const int END_TD;
static const int END_TEXTAREA;
static const int END_TH;
static const int END_TITLE;
static const int END_TR;
static const int END_TT;
static const int END_U;
static const int END_UL;
static const int END_VAR;


#line 160 "/usr/local/lib/bison.h"
 /* decl const */
public:
 int YY_HTMLParser_PARSE(YY_HTMLParser_PARSE_PARAM);
 virtual void YY_HTMLParser_ERROR(char *) YY_HTMLParser_ERROR_BODY;
#ifdef YY_HTMLParser_PURE
#ifdef YY_HTMLParser_LSP_NEEDED
 virtual int  YY_HTMLParser_LEX(YY_HTMLParser_STYPE *YY_HTMLParser_LVAL,YY_HTMLParser_LTYPE *YY_HTMLParser_LLOC) YY_HTMLParser_LEX_BODY;
#else
 virtual int  YY_HTMLParser_LEX(YY_HTMLParser_STYPE *YY_HTMLParser_LVAL) YY_HTMLParser_LEX_BODY;
#endif
#else
 virtual int YY_HTMLParser_LEX() YY_HTMLParser_LEX_BODY;
 YY_HTMLParser_STYPE YY_HTMLParser_LVAL;
#ifdef YY_HTMLParser_LSP_NEEDED
 YY_HTMLParser_LTYPE YY_HTMLParser_LLOC;
#endif
 int YY_HTMLParser_NERRS;
 int YY_HTMLParser_CHAR;
#endif
#if YY_HTMLParser_DEBUG != 0
public:
 int YY_HTMLParser_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
#endif
public:
 YY_HTMLParser_CLASS(YY_HTMLParser_CONSTRUCTOR_PARAM);
public:
 YY_HTMLParser_MEMBERS 
};
/* other declare folow */
#endif


#if YY_HTMLParser_COMPATIBILITY != 0
/* backward compatibility */
#ifndef YYSTYPE
#define YYSTYPE YY_HTMLParser_STYPE
#endif

#ifndef YYLTYPE
#define YYLTYPE YY_HTMLParser_LTYPE
#endif
#ifndef YYDEBUG
#ifdef YY_HTMLParser_DEBUG 
#define YYDEBUG YY_HTMLParser_DEBUG
#endif
#endif

#endif
/* END */

/* #line 209 "/usr/local/lib/bison.h" */
#endif
