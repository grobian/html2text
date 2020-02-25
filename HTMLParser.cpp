#define YY_HTMLParser_h_included

/*  A Bison parser, made from HTMLParser.y  */


#line 1 "/usr/local/lib/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#ifndef _MSDOS
#ifdef MSDOS
#define _MSDOS
#endif
#endif
/* turboc */
#ifdef __MSDOS__
#ifndef _MSDOS
#define _MSDOS
#endif
#endif

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)
#include <alloca.h>
#else /* not sparc */
#if defined (_MSDOS)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */
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
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#define YYBISON 1  

/* #line 70 "/usr/local/lib/bison.cc" */
#define YY_HTMLParser_PURE 
#define YY_HTMLParser_DEBUG  1
#line 40 "HTMLParser.y"


/* ------------------------------------------------------------------------- */

#ident "$Id: HTMLParser.y,v 1.14 1999/10/26 10:56:55 arno Exp $"

#include "html.h"
#include "HTMLParser.h"

// MIPS machines don't have "alloca()", so disable stack realloc'ing.
#ifdef mips
#define yyoverflow yyerror("parser stack overflow"), (void)
#endif

/* ------------------------------------------------------------------------- */

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

#line 70 "/usr/local/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_HTMLParser_BISON 1
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
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_HTMLParser_STYPE 
#define YY_HTMLParser_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_HTMLParser_DEBUG
#define  YY_HTMLParser_DEBUG YYDEBUG
#endif
#endif
#ifdef YY_HTMLParser_STYPE
#ifndef yystype
#define yystype YY_HTMLParser_STYPE
#endif
#endif
#endif

#ifndef YY_HTMLParser_PURE

/* #line 105 "/usr/local/lib/bison.cc" */

#line 105 "/usr/local/lib/bison.cc"
/*  YY_HTMLParser_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 109 "/usr/local/lib/bison.cc" */

#line 109 "/usr/local/lib/bison.cc"
/* prefix */
#ifndef YY_HTMLParser_DEBUG

/* #line 111 "/usr/local/lib/bison.cc" */

#line 111 "/usr/local/lib/bison.cc"
/* YY_HTMLParser_DEBUG */
#endif


#ifndef YY_HTMLParser_LSP_NEEDED

/* #line 116 "/usr/local/lib/bison.cc" */

#line 116 "/usr/local/lib/bison.cc"
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
      /* We used to use `unsigned long' as YY_HTMLParser_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

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
#if YY_HTMLParser_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_HTMLParser_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_HTMLParser_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_HTMLParser_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_HTMLParser_PURE
#ifndef YYPURE
#define YYPURE YY_HTMLParser_PURE
#endif
#endif
#ifdef YY_HTMLParser_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_HTMLParser_DEBUG 
#endif
#endif
#ifndef YY_HTMLParser_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_HTMLParser_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_HTMLParser_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_HTMLParser_LSP_NEEDED YYLSP_NEEDED
#endif
#endif


/* #line 223 "/usr/local/lib/bison.cc" */
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


#line 223 "/usr/local/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
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
#ifndef YY_HTMLParser_CONSTRUCTOR_CODE
#define YY_HTMLParser_CONSTRUCTOR_CODE
#endif
#ifndef YY_HTMLParser_CONSTRUCTOR_INIT
#define YY_HTMLParser_CONSTRUCTOR_INIT
#endif

class YY_HTMLParser_CLASS YY_HTMLParser_INHERIT
{
public: /* static const int token ... */

/* #line 254 "/usr/local/lib/bison.cc" */
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


#line 254 "/usr/local/lib/bison.cc"
 /* decl const */
public:
 int YY_HTMLParser_PARSE (YY_HTMLParser_PARSE_PARAM);
 virtual void YY_HTMLParser_ERROR(char *msg) YY_HTMLParser_ERROR_BODY;
#ifdef YY_HTMLParser_PURE
#ifdef YY_HTMLParser_LSP_NEEDED
 virtual int  YY_HTMLParser_LEX (YY_HTMLParser_STYPE *YY_HTMLParser_LVAL,YY_HTMLParser_LTYPE *YY_HTMLParser_LLOC) YY_HTMLParser_LEX_BODY;
#else
 virtual int  YY_HTMLParser_LEX (YY_HTMLParser_STYPE *YY_HTMLParser_LVAL) YY_HTMLParser_LEX_BODY;
#endif
#else
 virtual int YY_HTMLParser_LEX() YY_HTMLParser_LEX_BODY;
 YY_HTMLParser_STYPE YY_HTMLParser_LVAL;
#ifdef YY_HTMLParser_LSP_NEEDED
 YY_HTMLParser_LTYPE YY_HTMLParser_LLOC;
#endif
 int   YY_HTMLParser_NERRS;
 int    YY_HTMLParser_CHAR;
#endif
#if YY_HTMLParser_DEBUG != 0
 int YY_HTMLParser_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_HTMLParser_CLASS(YY_HTMLParser_CONSTRUCTOR_PARAM);
public:
 YY_HTMLParser_MEMBERS 
};
/* other declare folow */

/* #line 282 "/usr/local/lib/bison.cc" */
const int YY_HTMLParser_CLASS::DOCTYPE=258;
const int YY_HTMLParser_CLASS::PCDATA=259;
const int YY_HTMLParser_CLASS::SCAN_ERROR=260;
const int YY_HTMLParser_CLASS::A=261;
const int YY_HTMLParser_CLASS::ADDRESS=262;
const int YY_HTMLParser_CLASS::APPLET=263;
const int YY_HTMLParser_CLASS::AREA=264;
const int YY_HTMLParser_CLASS::B=265;
const int YY_HTMLParser_CLASS::BASE=266;
const int YY_HTMLParser_CLASS::BASEFONT=267;
const int YY_HTMLParser_CLASS::BIG=268;
const int YY_HTMLParser_CLASS::BLOCKQUOTE=269;
const int YY_HTMLParser_CLASS::BODY=270;
const int YY_HTMLParser_CLASS::BR=271;
const int YY_HTMLParser_CLASS::CAPTION=272;
const int YY_HTMLParser_CLASS::CENTER=273;
const int YY_HTMLParser_CLASS::CITE=274;
const int YY_HTMLParser_CLASS::CODE=275;
const int YY_HTMLParser_CLASS::DD=276;
const int YY_HTMLParser_CLASS::DFN=277;
const int YY_HTMLParser_CLASS::DIR=278;
const int YY_HTMLParser_CLASS::DIV=279;
const int YY_HTMLParser_CLASS::DL=280;
const int YY_HTMLParser_CLASS::DT=281;
const int YY_HTMLParser_CLASS::EM=282;
const int YY_HTMLParser_CLASS::FONT=283;
const int YY_HTMLParser_CLASS::FORM=284;
const int YY_HTMLParser_CLASS::H1=285;
const int YY_HTMLParser_CLASS::H2=286;
const int YY_HTMLParser_CLASS::H3=287;
const int YY_HTMLParser_CLASS::H4=288;
const int YY_HTMLParser_CLASS::H5=289;
const int YY_HTMLParser_CLASS::H6=290;
const int YY_HTMLParser_CLASS::HEAD=291;
const int YY_HTMLParser_CLASS::HR=292;
const int YY_HTMLParser_CLASS::HTML=293;
const int YY_HTMLParser_CLASS::I=294;
const int YY_HTMLParser_CLASS::IMG=295;
const int YY_HTMLParser_CLASS::INPUT=296;
const int YY_HTMLParser_CLASS::ISINDEX=297;
const int YY_HTMLParser_CLASS::KBD=298;
const int YY_HTMLParser_CLASS::LI=299;
const int YY_HTMLParser_CLASS::LINK=300;
const int YY_HTMLParser_CLASS::MAP=301;
const int YY_HTMLParser_CLASS::MENU=302;
const int YY_HTMLParser_CLASS::META=303;
const int YY_HTMLParser_CLASS::NOBR=304;
const int YY_HTMLParser_CLASS::OL=305;
const int YY_HTMLParser_CLASS::OPTION=306;
const int YY_HTMLParser_CLASS::P=307;
const int YY_HTMLParser_CLASS::PARAM=308;
const int YY_HTMLParser_CLASS::PRE=309;
const int YY_HTMLParser_CLASS::SAMP=310;
const int YY_HTMLParser_CLASS::SCRIPT=311;
const int YY_HTMLParser_CLASS::SELECT=312;
const int YY_HTMLParser_CLASS::SMALL=313;
const int YY_HTMLParser_CLASS::STRIKE=314;
const int YY_HTMLParser_CLASS::STRONG=315;
const int YY_HTMLParser_CLASS::STYLE=316;
const int YY_HTMLParser_CLASS::SUB=317;
const int YY_HTMLParser_CLASS::SUP=318;
const int YY_HTMLParser_CLASS::TABLE=319;
const int YY_HTMLParser_CLASS::TD=320;
const int YY_HTMLParser_CLASS::TEXTAREA=321;
const int YY_HTMLParser_CLASS::TH=322;
const int YY_HTMLParser_CLASS::TITLE=323;
const int YY_HTMLParser_CLASS::TR=324;
const int YY_HTMLParser_CLASS::TT=325;
const int YY_HTMLParser_CLASS::U=326;
const int YY_HTMLParser_CLASS::UL=327;
const int YY_HTMLParser_CLASS::VAR=328;
const int YY_HTMLParser_CLASS::END_A=329;
const int YY_HTMLParser_CLASS::END_ADDRESS=330;
const int YY_HTMLParser_CLASS::END_APPLET=331;
const int YY_HTMLParser_CLASS::END_B=332;
const int YY_HTMLParser_CLASS::END_BIG=333;
const int YY_HTMLParser_CLASS::END_BLOCKQUOTE=334;
const int YY_HTMLParser_CLASS::END_BODY=335;
const int YY_HTMLParser_CLASS::END_CAPTION=336;
const int YY_HTMLParser_CLASS::END_CENTER=337;
const int YY_HTMLParser_CLASS::END_CITE=338;
const int YY_HTMLParser_CLASS::END_CODE=339;
const int YY_HTMLParser_CLASS::END_DD=340;
const int YY_HTMLParser_CLASS::END_DFN=341;
const int YY_HTMLParser_CLASS::END_DIR=342;
const int YY_HTMLParser_CLASS::END_DIV=343;
const int YY_HTMLParser_CLASS::END_DL=344;
const int YY_HTMLParser_CLASS::END_DT=345;
const int YY_HTMLParser_CLASS::END_EM=346;
const int YY_HTMLParser_CLASS::END_FONT=347;
const int YY_HTMLParser_CLASS::END_FORM=348;
const int YY_HTMLParser_CLASS::END_H1=349;
const int YY_HTMLParser_CLASS::END_H2=350;
const int YY_HTMLParser_CLASS::END_H3=351;
const int YY_HTMLParser_CLASS::END_H4=352;
const int YY_HTMLParser_CLASS::END_H5=353;
const int YY_HTMLParser_CLASS::END_H6=354;
const int YY_HTMLParser_CLASS::END_HEAD=355;
const int YY_HTMLParser_CLASS::END_HTML=356;
const int YY_HTMLParser_CLASS::END_I=357;
const int YY_HTMLParser_CLASS::END_KBD=358;
const int YY_HTMLParser_CLASS::END_LI=359;
const int YY_HTMLParser_CLASS::END_MAP=360;
const int YY_HTMLParser_CLASS::END_MENU=361;
const int YY_HTMLParser_CLASS::END_NOBR=362;
const int YY_HTMLParser_CLASS::END_OL=363;
const int YY_HTMLParser_CLASS::END_OPTION=364;
const int YY_HTMLParser_CLASS::END_P=365;
const int YY_HTMLParser_CLASS::END_PRE=366;
const int YY_HTMLParser_CLASS::END_SAMP=367;
const int YY_HTMLParser_CLASS::END_SCRIPT=368;
const int YY_HTMLParser_CLASS::END_SELECT=369;
const int YY_HTMLParser_CLASS::END_SMALL=370;
const int YY_HTMLParser_CLASS::END_STRIKE=371;
const int YY_HTMLParser_CLASS::END_STRONG=372;
const int YY_HTMLParser_CLASS::END_STYLE=373;
const int YY_HTMLParser_CLASS::END_SUB=374;
const int YY_HTMLParser_CLASS::END_SUP=375;
const int YY_HTMLParser_CLASS::END_TABLE=376;
const int YY_HTMLParser_CLASS::END_TD=377;
const int YY_HTMLParser_CLASS::END_TEXTAREA=378;
const int YY_HTMLParser_CLASS::END_TH=379;
const int YY_HTMLParser_CLASS::END_TITLE=380;
const int YY_HTMLParser_CLASS::END_TR=381;
const int YY_HTMLParser_CLASS::END_TT=382;
const int YY_HTMLParser_CLASS::END_U=383;
const int YY_HTMLParser_CLASS::END_UL=384;
const int YY_HTMLParser_CLASS::END_VAR=385;


#line 282 "/usr/local/lib/bison.cc"
 /* const YY_HTMLParser_CLASS::token */
/*apres const  */
YY_HTMLParser_CLASS::YY_HTMLParser_CLASS(YY_HTMLParser_CONSTRUCTOR_PARAM) YY_HTMLParser_CONSTRUCTOR_INIT
{
#if YY_HTMLParser_DEBUG != 0
YY_HTMLParser_DEBUG_FLAG=0;
#endif
YY_HTMLParser_CONSTRUCTOR_CODE;
};
#endif

/* #line 292 "/usr/local/lib/bison.cc" */


#define	YYFINAL		286
#define	YYFLAG		-32768
#define	YYNTBASE	131

#define YYTRANSLATE(x) ((unsigned)(x) <= 385 ? yytranslate[x] : 209)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130
};

#if YY_HTMLParser_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     3,     6,     9,    12,    15,    18,    21,    26,
    29,    32,    35,    38,    41,    44,    47,    50,    53,    56,
    59,    62,    64,    65,    68,    71,    74,    77,    80,    83,
    86,    90,    92,    96,    97,   100,   103,   106,   108,   110,
   112,   116,   120,   124,   128,   130,   135,   136,   141,   142,
   147,   148,   153,   154,   159,   160,   163,   166,   170,   172,
   174,   180,   186,   187,   189,   192,   195,   199,   205,   209,
   215,   217,   220,   223,   225,   227,   229,   233,   237,   238,
   241,   246,   247,   250,   255,   261,   264,   268,   270,   273,
   276,   279,   282,   285,   288,   293,   297,   301,   305,   309,
   313,   317,   321,   325,   329,   333,   337,   341,   345,   349,
   353,   357,   361,   366,   368,   372,   376,   378,   380,   384,
   385,   388,   391,   392,   395,   398,   400,   404,   408,   410,
   413,   417,   419,   421,   423,   425,   427,   429,   431,   433,
   435,   437,   439,   441,   442,   444,   445,   447,   448,   450,
   451,   453,   454,   456,   457,   459,   460,   462,   463,   465,
   466,   468,   469,   471,   472,   474,   475,   477,   478,   480,
   481,   483,   484,   486,   487,   489,   490,   492,   493,   495,
   496,   498,   499,   501,   502,   504,   505,   507,   508,   510,
   511,   513,   514,   516,   517,   519,   520,   522,   523,   525,
   526,   528,   529,   531,   532,   534,   535,   537,   538,   540,
   541,   543,   544,   546,   547,   549,   550,   552,   553,   555,
   556,   558,   559
};

#endif

static const short yyrhs[] = {   132,
     0,     0,   132,     1,     0,   132,     3,     0,   132,    38,
     0,   132,   101,     0,   132,    36,     0,   132,   100,     0,
   132,    68,   169,   202,     0,   132,    42,     0,   132,    11,
     0,   132,    48,     0,   132,    45,     0,   132,    56,     0,
   132,    61,     0,   132,    15,     0,   132,    80,     0,   132,
   157,     0,   132,   135,     0,   132,   136,     0,   132,   156,
     0,     4,     0,     0,   134,     1,     0,   134,    56,     0,
   134,    61,     0,   134,   157,     0,   134,   135,     0,   134,
   136,     0,   134,   156,     0,   167,   137,   168,     0,   138,
     0,    52,   137,   192,     0,     0,   137,     1,     0,   137,
   157,     0,   137,   138,     0,   139,     0,   152,     0,   146,
     0,    24,   134,   183,     0,    18,   134,   179,     0,    14,
   134,   177,     0,    29,   134,   187,     0,    37,     0,    64,
   170,   154,   121,     0,     0,    50,   140,   144,   108,     0,
     0,    72,   141,   144,   206,     0,     0,    23,   142,   144,
    87,     0,     0,    47,   143,   144,   106,     0,     0,   144,
     1,     0,   144,   145,     0,    44,   172,   190,     0,   136,
     0,   157,     0,    25,   172,   208,   146,   184,     0,    25,
   172,   208,   147,    89,     0,     0,   147,     0,   147,   148,
     0,   147,   149,     0,    26,   172,   208,     0,    26,   172,
    90,   174,   208,     0,    21,   172,   208,     0,    21,   172,
    85,   174,   208,     0,   151,     0,   150,     1,     0,   150,
   151,     0,   158,     0,   135,     0,   136,     0,    54,   171,
   193,     0,    17,   171,    81,     0,     0,   154,     1,     0,
   154,    69,   155,   203,     0,     0,   155,     1,     0,   155,
    65,   134,   200,     0,   155,    67,   134,   201,   200,     0,
   155,    41,     0,     7,   171,    75,     0,   158,     0,   157,
   158,     0,   133,   208,     0,   159,   208,     0,   160,   208,
     0,   161,   208,     0,   164,   208,     0,    49,   171,   107,
   208,     0,    70,   171,   204,     0,    39,   171,   188,     0,
    10,   171,   176,     0,    71,   171,   205,     0,    59,   171,
   196,     0,    13,   171,   178,     0,    58,   171,   195,     0,
    62,   171,   198,     0,    63,   171,   199,     0,    27,   171,
   185,     0,    60,   171,   197,     0,    22,   171,   182,     0,
    20,   171,   181,     0,    55,   171,   194,     0,    43,   171,
   189,     0,    73,   171,   207,     0,    19,   171,   180,     0,
     6,   173,   172,   175,     0,    40,     0,     8,   162,    76,
     0,    28,   172,   186,     0,    12,     0,    16,     0,    46,
   163,   105,     0,     0,   162,   158,     0,   162,    53,     0,
     0,   163,     1,     0,   163,     9,     0,    41,     0,    57,
   165,   114,     0,    66,   133,   123,     0,   166,     0,   165,
   166,     0,    51,   133,   191,     0,    30,     0,    31,     0,
    32,     0,    33,     0,    34,     0,    35,     0,    94,     0,
    95,     0,    96,     0,    97,     0,    98,     0,    99,     0,
     0,   133,     0,     0,   153,     0,     0,   157,     0,     0,
   150,     0,     0,    44,     0,     0,    52,     0,     0,    74,
     0,     0,    77,     0,     0,    79,     0,     0,    78,     0,
     0,    82,     0,     0,    83,     0,     0,    84,     0,     0,
    86,     0,     0,    88,     0,     0,    89,     0,     0,    91,
     0,     0,    92,     0,     0,    93,     0,     0,   102,     0,
     0,   103,     0,     0,   104,     0,     0,   109,     0,     0,
   110,     0,     0,   111,     0,     0,   112,     0,     0,   115,
     0,     0,   116,     0,     0,   117,     0,     0,   119,     0,
     0,   120,     0,     0,   122,     0,     0,   124,     0,     0,
   125,     0,     0,   126,     0,     0,   127,     0,     0,   128,
     0,     0,   129,     0,     0,   130,     0,     0,     1,     0
};

#if YY_HTMLParser_DEBUG != 0
static const short yyrline[] = { 0,
   273,   304,   309,   312,   315,   319,   322,   326,   329,   333,
   336,   339,   342,   345,   353,   361,   365,   368,   373,   376,
   379,   384,   392,   396,   399,   407,   415,   420,   423,   426,
   431,   442,   446,   454,   458,   461,   466,   471,   475,   478,
   481,   487,   493,   499,   505,   510,   519,   520,   527,   527,
   534,   534,   541,   541,   550,   554,   557,   563,   570,   575,
   582,   591,   600,   604,   607,   611,   617,   623,   631,   637,
   645,   650,   653,   658,   662,   665,   670,   678,   686,   690,
   693,   701,   705,   708,   714,   721,   727,   737,   742,   747,
   749,   750,   751,   752,   753,   761,   763,   764,   765,   766,
   767,   768,   769,   770,   773,   775,   776,   777,   778,   779,
   780,   781,   784,   795,   800,   808,   814,   819,   824,   832,
   836,   840,   848,   852,   855,   861,   867,   873,   881,   886,
   891,   901,   903,   904,   905,   906,   907,   910,   912,   913,
   914,   915,   916,   921,   921,   922,   922,   923,   923,   924,
   924,   926,   926,   927,   927,   929,   929,   930,   930,   931,
   931,   932,   932,   933,   933,   934,   934,   935,   935,   936,
   936,   937,   937,   938,   938,   939,   939,   940,   940,   941,
   941,   942,   942,   943,   943,   944,   944,   945,   945,   946,
   946,   947,   947,   948,   948,   949,   949,   950,   950,   951,
   951,   952,   952,   953,   953,   954,   954,   955,   955,   956,
   956,   957,   957,   958,   958,   959,   959,   960,   960,   961,
   961,   963,   963
};

static const char * const yytname[] = {   "$","error","$illegal.","DOCTYPE",
"PCDATA","SCAN_ERROR","A","ADDRESS","APPLET","AREA","B","BASE","BASEFONT","BIG",
"BLOCKQUOTE","BODY","BR","CAPTION","CENTER","CITE","CODE","DD","DFN","DIR","DIV",
"DL","DT","EM","FONT","FORM","H1","H2","H3","H4","H5","H6","HEAD","HR","HTML",
"I","IMG","INPUT","ISINDEX","KBD","LI","LINK","MAP","MENU","META","NOBR","OL",
"OPTION","P","PARAM","PRE","SAMP","SCRIPT","SELECT","SMALL","STRIKE","STRONG",
"STYLE","SUB","SUP","TABLE","TD","TEXTAREA","TH","TITLE","TR","TT","U","UL",
"VAR","END_A","END_ADDRESS","END_APPLET","END_B","END_BIG","END_BLOCKQUOTE",
"END_BODY","END_CAPTION","END_CENTER","END_CITE","END_CODE","END_DD","END_DFN",
"END_DIR","END_DIV","END_DL","END_DT","END_EM","END_FONT","END_FORM","END_H1",
"END_H2","END_H3","END_H4","END_H5","END_H6","END_HEAD","END_HTML","END_I","END_KBD",
"END_LI","END_MAP","END_MENU","END_NOBR","END_OL","END_OPTION","END_P","END_PRE",
"END_SAMP","END_SCRIPT","END_SELECT","END_SMALL","END_STRIKE","END_STRONG","END_STYLE",
"END_SUB","END_SUP","END_TABLE","END_TD","END_TEXTAREA","END_TH","END_TITLE",
"END_TR","END_TT","END_U","END_UL","END_VAR","document","document_","pcdata",
"body_content","heading","block","paragraph_content","block_except_p","list",
"@1","@2","@3","@4","list_content","list_item","definition_list","definition_list_content",
"term_name","term_definition","flow","flow_","preformatted","caption","table_rows",
"table_cells","address","texts","text","font","phrase","special","applet_content",
"map_content","form","select_content","option","HX","END_HX","opt_pcdata","opt_caption",
"opt_texts","opt_flow","opt_LI","opt_P","opt_END_A","opt_END_B","opt_END_BLOCKQUOTE",
"opt_END_BIG","opt_END_CENTER","opt_END_CITE","opt_END_CODE","opt_END_DFN","opt_END_DIV",
"opt_END_DL","opt_END_EM","opt_END_FONT","opt_END_FORM","opt_END_I","opt_END_KBD",
"opt_END_LI","opt_END_OPTION","opt_END_P","opt_END_PRE","opt_END_SAMP","opt_END_SMALL",
"opt_END_STRIKE","opt_END_STRONG","opt_END_SUB","opt_END_SUP","opt_END_TD","opt_END_TH",
"opt_END_TITLE","opt_END_TR","opt_END_TT","opt_END_U","opt_END_UL","opt_END_VAR",
"opt_error",""
};
#endif

static const short yyr1[] = {     0,
   131,   132,   132,   132,   132,   132,   132,   132,   132,   132,
   132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
   132,   133,   134,   134,   134,   134,   134,   134,   134,   134,
   135,   136,   136,   137,   137,   137,   137,   138,   138,   138,
   138,   138,   138,   138,   138,   138,   140,   139,   141,   139,
   142,   139,   143,   139,   144,   144,   144,   145,   145,   145,
   146,   146,   147,   147,   147,   147,   148,   148,   149,   149,
   150,   150,   150,   151,   151,   151,   152,   153,   154,   154,
   154,   155,   155,   155,   155,   155,   156,   157,   157,   158,
   158,   158,   158,   158,   158,   159,   159,   159,   159,   159,
   159,   159,   159,   159,   160,   160,   160,   160,   160,   160,
   160,   160,   161,   161,   161,   161,   161,   161,   161,   162,
   162,   162,   163,   163,   163,   164,   164,   164,   165,   165,
   166,   167,   167,   167,   167,   167,   167,   168,   168,   168,
   168,   168,   168,   169,   169,   170,   170,   171,   171,   172,
   172,   173,   173,   174,   174,   175,   175,   176,   176,   177,
   177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
   182,   183,   183,   184,   184,   185,   185,   186,   186,   187,
   187,   188,   188,   189,   189,   190,   190,   191,   191,   192,
   192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
   197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
   202,   203,   203,   204,   204,   205,   205,   206,   206,   207,
   207,   208,   208
};

static const short yyr2[] = {     0,
     1,     0,     2,     2,     2,     2,     2,     2,     4,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     1,     0,     2,     2,     2,     2,     2,     2,     2,
     3,     1,     3,     0,     2,     2,     2,     1,     1,     1,
     3,     3,     3,     3,     1,     4,     0,     4,     0,     4,
     0,     4,     0,     4,     0,     2,     2,     3,     1,     1,
     5,     5,     0,     1,     2,     2,     3,     5,     3,     5,
     1,     2,     2,     1,     1,     1,     3,     3,     0,     2,
     4,     0,     2,     4,     5,     2,     3,     1,     2,     2,
     2,     2,     2,     2,     4,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     4,     1,     3,     3,     1,     1,     3,     0,
     2,     2,     0,     2,     2,     1,     3,     3,     1,     2,
     3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
     1,     0,     1
};

static const short yydefact[] = {     2,
     0,     3,     4,    22,   152,   148,   120,   148,    11,   117,
   148,    23,    16,   118,    23,   148,   148,   148,    51,    23,
   150,   148,   150,    23,   132,   133,   134,   135,   136,   137,
     7,    45,     5,   148,   114,   126,    10,   148,    13,   123,
    53,    12,   148,    47,    34,   148,   148,    14,     0,   148,
   148,   148,    15,   148,   148,   146,     0,   144,   148,   148,
    49,   148,    17,     8,     6,     0,    19,    20,    32,    38,
    40,    39,    21,    18,    88,     0,     0,     0,     0,    34,
   153,   150,   149,     0,     0,   158,   162,     0,     0,   166,
   168,   170,    55,     0,    75,    76,     0,    71,    74,     0,
   176,   178,     0,   182,   184,     0,    55,     0,    55,     0,
   192,   194,     0,     0,   129,   196,   198,   200,   202,   204,
   148,   147,    79,     0,   145,   210,   214,   216,    55,   220,
   223,    90,    89,    91,    92,    93,    94,     0,   156,    87,
   122,   115,   121,   159,    98,   163,   101,    24,    25,    26,
   161,    28,    29,    30,    27,    43,   165,    42,   167,   112,
   169,   108,   171,   107,     0,   173,    41,    72,    73,    63,
   177,   105,   179,   116,   181,    44,   183,    97,   185,   110,
   124,   125,   119,     0,     0,     0,    35,   191,    37,    36,
    33,   193,    77,   195,   109,   188,   127,   130,   197,   102,
   199,   100,   201,   106,   203,   103,   205,   104,     0,     0,
   128,   211,     9,   215,    96,   217,    99,     0,   221,   111,
   138,   139,   140,   141,   142,   143,    31,   157,   113,    56,
   150,    52,    59,    57,    60,   174,     0,    54,    95,    48,
   189,   131,    78,    80,    82,    46,   219,    50,   186,   175,
    61,   150,   150,    62,    65,    66,     0,   187,    58,     0,
     0,    83,    86,    23,    23,   213,    81,   154,    69,   154,
    67,     0,     0,   155,     0,     0,   207,    84,   209,   206,
    70,    68,    85,     0,     0,     0
};

static const short yydefgoto[] = {   284,
     1,    66,    88,    95,    96,   110,    69,    70,   109,   129,
    93,   107,   165,   234,    71,   237,   255,   256,    97,    98,
    72,   122,   210,   257,   154,    83,    75,    76,    77,    78,
    85,   106,    79,   114,   115,    80,   227,   126,   123,    84,
   100,    82,   275,   229,   145,   156,   147,   158,   160,   162,
   164,   167,   251,   172,   174,   176,   178,   180,   259,   242,
   191,   193,   195,   200,   202,   204,   206,   208,   278,   280,
   213,   267,   215,   217,   248,   220,   132
};

static const short yypact[] = {-32768,
  1740,-32768,-32768,-32768,   -24,  2148,-32768,  2148,-32768,-32768,
  2148,-32768,-32768,-32768,-32768,  2148,  2148,  2148,-32768,-32768,
  2078,  2148,  2078,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  2148,-32768,-32768,-32768,  2148,-32768,-32768,
-32768,-32768,  2148,-32768,-32768,  2148,  2148,-32768,   -26,  2148,
  2148,  2148,-32768,  2148,  2148,    14,    28,    28,  2148,  2148,
-32768,  2148,-32768,-32768,-32768,   283,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  2148,-32768,   283,   283,   283,   283,-32768,
-32768,  2078,  2148,   -42,  2007,   -43,   -41,   414,   545,   -48,
   -45,   -46,-32768,   676,-32768,-32768,   807,-32768,-32768,    21,
   -50,   -40,   938,   -58,   -52,     8,-32768,   -51,-32768,  1069,
   -53,   -49,    28,   -32,-32768,   -56,   -55,   -47,   -57,   -39,
  2148,-32768,-32768,   -59,-32768,   -36,   -60,   -54,-32768,   -44,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1838,    -2,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  2148,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  1937,-32768,-32768,-32768,-32768,    50,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,  1660,   283,  1587,-32768,-32768,-32768,  2148,
-32768,-32768,-32768,-32768,-32768,   -31,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    -4,     7,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  1200,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  2078,-32768,-32768,-32768,  2148,    -6,    -5,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -19,-32768,
-32768,  2078,  2078,-32768,-32768,-32768,     4,-32768,-32768,    29,
    17,-32768,-32768,-32768,-32768,-32768,-32768,    40,-32768,    40,
-32768,  1454,  1330,-32768,    27,    27,-32768,-32768,-32768,   -28,
-32768,-32768,-32768,    95,    99,-32768
};

static const short yypgoto[] = {-32768,
-32768,   -34,   -13,     9,     2,    20,   -84,-32768,-32768,-32768,
-32768,-32768,   -80,-32768,   -69,-32768,-32768,-32768,-32768,    11,
-32768,-32768,-32768,-32768,   103,    -1,   -17,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    -3,-32768,-32768,-32768,-32768,  1527,
   -22,-32768,  -155,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -163,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   -64
};


#define	YYLAST		2221


static const short yytable[] = {    74,
   102,    89,    68,    99,   262,    99,    94,   244,   181,    67,
   103,   134,   135,   136,   137,   252,   182,   131,   113,    81,
   253,   131,   124,   125,   113,   189,   184,   131,   186,   131,
   121,     4,   140,   144,   159,   170,   146,  -222,   161,   163,
   171,  -222,  -222,   177,   263,  -222,  -222,  -222,   218,  -222,
   179,   173,  -222,   189,  -222,   185,   133,   192,   199,   139,
   201,   205,   194,   211,    99,   133,   214,   143,   264,   203,
   265,   228,  -212,   216,    21,   245,   243,   241,   196,    99,
   207,   197,   250,   254,   258,   219,   155,   155,   212,   153,
   153,   274,   155,   277,   285,   153,   152,   152,   286,   138,
   236,   155,   152,    73,   153,  -222,   270,   169,   190,  -222,
   198,   152,   183,   268,   276,  -222,   283,  -222,     0,     0,
   239,     0,     0,     0,  -212,     0,     0,   246,     0,   266,
     0,     0,     0,     0,     0,     0,   190,   133,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   235,     0,     0,   233,     0,     0,     0,
     0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   235,     0,   235,   233,     0,   233,     0,     0,
     0,     0,     0,     0,     0,   269,   271,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   249,     0,
   281,   282,     0,    99,     0,     0,   235,   133,     0,   233,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
   261,     0,     0,     0,    99,    99,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   272,   273,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   155,   155,     0,   153,   153,     0,     0,     0,     0,     0,
   152,   152,  -222,   131,     0,  -222,  -222,     0,  -222,  -222,
  -222,     0,  -222,  -222,  -222,  -222,  -222,  -222,  -222,     0,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,     0,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
  -222,  -222,  -222,  -222,  -222,  -222,  -222,     0,  -222,  -222,
  -222,     0,  -222,  -222,  -222,     0,     0,  -222,  -222,  -222,
     0,  -222,  -222,  -222,  -222,     0,  -222,     0,  -222,  -222,
  -222,  -222,  -222,  -160,   148,     0,  -160,     4,     0,     5,
     6,     7,     0,     8,  -160,    10,    11,    12,  -160,    14,
     0,    15,    16,    17,  -160,    18,    19,    20,    21,  -160,
    22,    23,    24,    25,    26,    27,    28,    29,    30,  -160,
    32,  -160,    34,    35,    36,  -160,    38,  -160,  -160,    40,
    41,  -160,    43,    44,     0,    45,  -160,    46,    47,   149,
    49,    50,    51,    52,   150,    54,    55,    56,  -160,    57,
  -160,  -160,  -160,    59,    60,    61,    62,  -160,  -160,  -160,
  -160,  -160,   151,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
  -160,  -160,  -160,  -160,  -160,  -160,  -160,  -160,     0,  -160,
  -160,  -160,     0,  -160,  -160,  -160,     0,     0,  -160,  -160,
  -160,     0,  -160,  -160,  -160,  -160,     0,  -160,     0,  -160,
  -160,  -160,  -160,  -160,  -164,   148,     0,  -164,     4,     0,
     5,     6,     7,     0,     8,  -164,    10,    11,    12,  -164,
    14,     0,    15,    16,    17,  -164,    18,    19,    20,    21,
  -164,    22,    23,    24,    25,    26,    27,    28,    29,    30,
  -164,    32,  -164,    34,    35,    36,  -164,    38,  -164,  -164,
    40,    41,  -164,    43,    44,     0,    45,  -164,    46,    47,
   149,    49,    50,    51,    52,   150,    54,    55,    56,  -164,
    57,  -164,  -164,  -164,    59,    60,    61,    62,  -164,  -164,
  -164,  -164,  -164,  -164,  -164,  -164,   157,  -164,  -164,  -164,
  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,     0,
  -164,  -164,  -164,     0,  -164,  -164,  -164,     0,     0,  -164,
  -164,  -164,     0,  -164,  -164,  -164,  -164,     0,  -164,     0,
  -164,  -164,  -164,  -164,  -164,  -172,   148,     0,  -172,     4,
     0,     5,     6,     7,     0,     8,  -172,    10,    11,    12,
  -172,    14,     0,    15,    16,    17,  -172,    18,    19,    20,
    21,  -172,    22,    23,    24,    25,    26,    27,    28,    29,
    30,  -172,    32,  -172,    34,    35,    36,  -172,    38,  -172,
  -172,    40,    41,  -172,    43,    44,     0,    45,  -172,    46,
    47,   149,    49,    50,    51,    52,   150,    54,    55,    56,
  -172,    57,  -172,  -172,  -172,    59,    60,    61,    62,  -172,
  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
  -172,  -172,  -172,   166,  -172,  -172,  -172,  -172,  -172,  -172,
  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
     0,  -172,  -172,  -172,     0,  -172,  -172,  -172,     0,     0,
  -172,  -172,  -172,     0,  -172,  -172,  -172,  -172,     0,  -172,
     0,  -172,  -172,  -172,  -172,  -172,  -151,   168,     0,  -151,
     4,     0,     5,  -151,     7,     0,     8,  -151,    10,    11,
    12,  -151,    14,     0,    15,    16,    17,  -151,    18,    19,
    20,    21,  -151,    22,    23,    24,    25,    26,    27,    28,
    29,    30,  -151,    32,  -151,    34,    35,    36,  -151,    38,
  -151,  -151,    40,    41,  -151,    43,    44,     0,    45,  -151,
    46,    47,  -151,    49,    50,    51,    52,  -151,    54,    55,
    56,  -151,    57,  -151,  -151,  -151,    59,    60,    61,    62,
  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
  -151,     0,  -151,  -151,  -151,     0,  -151,  -151,  -151,     0,
     0,  -151,  -151,  -151,     0,  -151,  -151,  -151,  -151,     0,
  -151,     0,  -151,  -151,  -151,  -151,  -151,  -180,   148,     0,
  -180,     4,     0,     5,     6,     7,     0,     8,  -180,    10,
    11,    12,  -180,    14,     0,    15,    16,    17,  -180,    18,
    19,    20,    21,  -180,    22,    23,    24,    25,    26,    27,
    28,    29,    30,  -180,    32,  -180,    34,    35,    36,  -180,
    38,  -180,  -180,    40,    41,  -180,    43,    44,     0,    45,
  -180,    46,    47,   149,    49,    50,    51,    52,   150,    54,
    55,    56,  -180,    57,  -180,  -180,  -180,    59,    60,    61,
    62,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
   175,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
  -180,  -180,     0,  -180,  -180,  -180,     0,  -180,  -180,  -180,
     0,     0,  -180,  -180,  -180,     0,  -180,  -180,  -180,  -180,
     0,  -180,     0,  -180,  -180,  -180,  -180,  -180,  -190,   187,
     0,  -190,     4,     0,     5,  -190,     7,     0,     8,  -190,
    10,    11,    12,  -190,    14,     0,    15,    16,    17,  -190,
    18,    19,    20,    21,  -190,    22,    23,    24,  -190,  -190,
  -190,  -190,  -190,  -190,  -190,    32,  -190,    34,    35,    36,
  -190,    38,  -190,  -190,    40,    41,  -190,    43,    44,     0,
  -190,  -190,    46,    47,  -190,    49,    50,    51,    52,  -190,
    54,    55,    56,  -190,    57,  -190,  -190,  -190,    59,    60,
    61,    62,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
  -190,  -190,  -190,     0,  -190,  -190,  -190,     0,   188,  -190,
  -190,     0,     0,  -190,  -190,  -190,     0,  -190,  -190,  -190,
  -190,     0,  -190,     0,  -190,  -190,  -190,  -190,  -190,  -218,
   230,     0,  -218,     4,     0,     5,  -218,     7,     0,     8,
  -218,    10,    11,    12,  -218,    14,     0,    15,    16,    17,
  -218,    18,    19,    20,    21,  -218,    22,    23,    24,  -218,
  -218,  -218,  -218,  -218,  -218,  -218,    32,  -218,    34,    35,
    36,  -218,    38,   231,  -218,    40,    41,  -218,    43,    44,
     0,    45,  -218,    46,    47,  -218,    49,    50,    51,    52,
  -218,    54,    55,    56,  -218,    57,  -218,  -218,  -218,    59,
    60,    61,    62,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
  -218,  -218,  -218,  -218,     0,  -218,  -218,  -218,     0,  -218,
  -218,  -218,     0,     0,  -218,  -218,  -218,     0,  -218,  -218,
  -218,  -218,     0,  -218,     0,  -218,  -218,  -218,   247,  -218,
   148,     0,     0,     4,     0,     5,     6,     7,     0,     8,
     0,    10,    11,    12,     0,    14,     0,    15,    16,    17,
     0,    18,    19,    20,    21,     0,    22,    23,    24,    25,
    26,    27,    28,    29,    30,     0,    32,     0,    34,    35,
    36,     0,    38,     0,     0,    40,    41,     0,    43,    44,
     0,    45,     0,    46,    47,   149,    49,    50,    51,    52,
   150,    54,    55,    56,  -208,    57,  -208,     0,  -208,    59,
    60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
  -208,  -208,     0,   279,   148,  -208,     0,     4,     0,     5,
     6,     7,     0,     8,     0,    10,    11,    12,     0,    14,
     0,    15,    16,    17,     0,    18,    19,    20,    21,     0,
    22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
    32,     0,    34,    35,    36,     0,    38,     0,     0,    40,
    41,     0,    43,    44,     0,    45,     0,    46,    47,   149,
    49,    50,    51,    52,   150,    54,    55,    56,  -206,    57,
  -206,     0,  -206,    59,    60,    61,    62,     0,     0,     0,
     0,     0,     0,     0,    86,     0,     0,    87,     0,     0,
     0,     0,    90,    91,    92,     0,     0,     0,   101,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   104,     0,     0,     0,   105,     0,     0,     0,     0,   108,
     0,     0,   111,   112,  -206,   277,   116,   117,   118,  -206,
   119,   120,     0,     0,     0,   127,   128,   230,   130,     0,
     4,     0,     5,     0,     7,     0,     8,     0,    10,    11,
    12,     0,    14,     0,    15,    16,    17,     0,    18,    19,
    20,    21,     0,    22,    23,    24,     0,     0,     0,     0,
     0,     0,     0,    32,     0,    34,    35,    36,     0,    38,
   231,     0,    40,    41,     0,    43,    44,     0,    45,     0,
    46,    47,     0,    49,    50,    51,    52,   209,    54,    55,
    56,     0,    57,     0,     0,     0,    59,    60,    61,    62,
   230,     0,     0,     4,     0,     5,     0,     7,     0,     8,
     0,    10,    11,    12,     0,    14,     0,    15,    16,    17,
     0,    18,    19,    20,    21,     0,    22,    23,    24,     0,
     0,     0,     0,     0,   240,     0,    32,     0,    34,    35,
    36,     0,    38,   231,     0,    40,    41,     0,    43,    44,
     0,    45,     0,    46,    47,     0,    49,    50,    51,    52,
     0,    54,    55,    56,     0,    57,     0,     0,     0,    59,
    60,    61,    62,     0,     0,     0,     0,     0,     0,    -1,
     2,     0,     3,     4,     0,     5,     6,     7,     0,     8,
     9,    10,    11,    12,    13,    14,     0,    15,    16,    17,
     0,    18,    19,    20,    21,   238,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
     0,    45,     0,    46,    47,    48,    49,    50,    51,    52,
    53,    54,    55,    56,     0,    57,     0,    58,     0,    59,
    60,    61,    62,     0,     0,     0,     0,     0,     0,    63,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   187,    64,
    65,     4,     0,     5,     0,     7,     0,     8,     0,    10,
    11,    12,     0,    14,     0,    15,    16,    17,     0,    18,
    19,    20,    21,     0,    22,    23,    24,     0,     0,     0,
     0,     0,     0,     0,    32,     0,    34,    35,    36,     0,
    38,     0,     0,    40,    41,     0,    43,    44,     0,     0,
     0,    46,    47,     0,    49,    50,    51,    52,     0,    54,
    55,    56,     0,    57,     0,     0,     0,    59,    60,    61,
    62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   221,   222,   223,   224,   225,   226,   230,     0,     0,
     4,     0,     5,     0,     7,     0,     8,     0,    10,    11,
    12,     0,    14,     0,    15,    16,    17,     0,    18,    19,
    20,    21,     0,    22,    23,    24,     0,     0,     0,     0,
     0,     0,     0,    32,     0,    34,    35,    36,     0,    38,
   231,     0,    40,    41,     0,    43,    44,     0,    45,     0,
    46,    47,     0,    49,    50,    51,    52,     0,    54,    55,
    56,     0,    57,     0,     0,     0,    59,    60,    61,    62,
     4,     0,     5,     0,     7,     0,     8,     0,    10,    11,
     0,     0,    14,   232,     0,    16,    17,     0,    18,     0,
     0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    34,    35,    36,     0,    38,
     0,     0,    40,     0,     0,    43,     0,     0,     0,   141,
     0,    47,     0,    49,    50,    51,    52,     0,    54,    55,
     0,     0,    57,     0,     0,     0,    59,    60,     0,    62,
     0,     4,   142,     5,     0,     7,     0,     8,     0,    10,
    11,    12,     0,    14,     0,    15,    16,    17,     0,    18,
    19,    20,    21,     0,    22,    23,    24,    25,    26,    27,
    28,    29,    30,     0,    32,     0,    34,    35,    36,     0,
    38,     0,     0,    40,    41,     0,    43,    44,     0,    45,
     0,    46,    47,     0,    49,    50,    51,    52,     0,    54,
    55,    56,     0,    57,     0,     0,     0,    59,    60,    61,
    62,     4,     0,     5,     0,     7,     0,     8,     0,    10,
    11,     0,     0,    14,     0,     0,    16,    17,     0,    18,
     0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    34,    35,    36,     0,
    38,     0,     0,    40,     0,     0,    43,     0,     0,     0,
     0,     0,    47,     0,    49,    50,    51,    52,     0,    54,
    55,     0,     0,    57,     0,     0,     0,    59,    60,     0,
    62
};

static const short yycheck[] = {     1,
    23,    15,     1,    21,     1,    23,    20,     1,     1,     1,
    24,    76,    77,    78,    79,    21,     9,     1,    51,    44,
    26,     1,    57,    58,    51,   110,   107,     1,   109,     1,
    17,     4,    75,    77,    83,   100,    78,    21,    84,    86,
    91,    21,    26,   102,    41,    25,    26,    21,   129,    21,
   103,    92,    26,   138,    26,   107,    74,   111,   115,    82,
   116,   119,   112,   123,    82,    83,   127,    85,    65,   117,
    67,    74,    69,   128,    25,    69,    81,   109,   113,    97,
   120,   114,    89,    89,   104,   130,    88,    89,   125,    88,
    89,    52,    94,   122,     0,    94,    88,    89,     0,    80,
   170,   103,    94,     1,   103,    89,    90,    97,   110,    89,
   114,   103,   105,    85,   270,    89,   280,    89,    -1,    -1,
   185,    -1,    -1,    -1,   121,    -1,    -1,   121,    -1,   126,
    -1,    -1,    -1,    -1,    -1,    -1,   138,   155,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,   165,    -1,    -1,   165,    -1,    -1,    -1,
    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   184,    -1,   186,   184,    -1,   186,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   260,   261,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,
   275,   276,    -1,   231,    -1,    -1,   218,   235,    -1,   218,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,
   253,    -1,    -1,    -1,   252,   253,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   264,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   272,   273,    -1,   272,   273,    -1,    -1,    -1,    -1,    -1,
   272,   273,     0,     1,    -1,     3,     4,    -1,     6,     7,
     8,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
    18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
    48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,   117,
    -1,   119,   120,   121,   122,    -1,   124,    -1,   126,   127,
   128,   129,   130,     0,     1,    -1,     3,     4,    -1,     6,
     7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
    -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    -1,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
    97,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
   107,   108,    -1,   110,   111,   112,    -1,    -1,   115,   116,
   117,    -1,   119,   120,   121,   122,    -1,   124,    -1,   126,
   127,   128,   129,   130,     0,     1,    -1,     3,     4,    -1,
     6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
    16,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
   106,   107,   108,    -1,   110,   111,   112,    -1,    -1,   115,
   116,   117,    -1,   119,   120,   121,   122,    -1,   124,    -1,
   126,   127,   128,   129,   130,     0,     1,    -1,     3,     4,
    -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
    15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    45,    46,    47,    48,    49,    50,    -1,    52,    53,    54,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
    85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
    -1,   106,   107,   108,    -1,   110,   111,   112,    -1,    -1,
   115,   116,   117,    -1,   119,   120,   121,   122,    -1,   124,
    -1,   126,   127,   128,   129,   130,     0,     1,    -1,     3,
     4,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
    14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
    24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    -1,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
   104,    -1,   106,   107,   108,    -1,   110,   111,   112,    -1,
    -1,   115,   116,   117,    -1,   119,   120,   121,   122,    -1,
   124,    -1,   126,   127,   128,   129,   130,     0,     1,    -1,
     3,     4,    -1,     6,     7,     8,    -1,    10,    11,    12,
    13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
    23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    45,    46,    47,    48,    49,    50,    -1,    52,
    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
    83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
   103,   104,    -1,   106,   107,   108,    -1,   110,   111,   112,
    -1,    -1,   115,   116,   117,    -1,   119,   120,   121,   122,
    -1,   124,    -1,   126,   127,   128,   129,   130,     0,     1,
    -1,     3,     4,    -1,     6,     7,     8,    -1,    10,    11,
    12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
    32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
   102,   103,   104,    -1,   106,   107,   108,    -1,   110,   111,
   112,    -1,    -1,   115,   116,   117,    -1,   119,   120,   121,
   122,    -1,   124,    -1,   126,   127,   128,   129,   130,     0,
     1,    -1,     3,     4,    -1,     6,     7,     8,    -1,    10,
    11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
    -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
   101,   102,   103,   104,    -1,   106,   107,   108,    -1,   110,
   111,   112,    -1,    -1,   115,   116,   117,    -1,   119,   120,
   121,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     1,    -1,    -1,     4,    -1,     6,     7,     8,    -1,    10,
    -1,    12,    13,    14,    -1,    16,    -1,    18,    19,    20,
    -1,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    -1,    37,    -1,    39,    40,
    41,    -1,    43,    -1,    -1,    46,    47,    -1,    49,    50,
    -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   121,   122,    -1,   124,     1,   126,    -1,     4,    -1,     6,
     7,     8,    -1,    10,    -1,    12,    13,    14,    -1,    16,
    -1,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
    37,    -1,    39,    40,    41,    -1,    43,    -1,    -1,    46,
    47,    -1,    49,    50,    -1,    52,    -1,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    67,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    -1,    -1,
    -1,    -1,    16,    17,    18,    -1,    -1,    -1,    22,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,
    -1,    -1,    46,    47,   121,   122,    50,    51,    52,   126,
    54,    55,    -1,    -1,    -1,    59,    60,     1,    62,    -1,
     4,    -1,     6,    -1,     8,    -1,    10,    -1,    12,    13,
    14,    -1,    16,    -1,    18,    19,    20,    -1,    22,    23,
    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,    43,
    44,    -1,    46,    47,    -1,    49,    50,    -1,    52,    -1,
    54,    55,    -1,    57,    58,    59,    60,   121,    62,    63,
    64,    -1,    66,    -1,    -1,    -1,    70,    71,    72,    73,
     1,    -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,
    -1,    12,    13,    14,    -1,    16,    -1,    18,    19,    20,
    -1,    22,    23,    24,    25,    -1,    27,    28,    29,    -1,
    -1,    -1,    -1,    -1,   108,    -1,    37,    -1,    39,    40,
    41,    -1,    43,    44,    -1,    46,    47,    -1,    49,    50,
    -1,    52,    -1,    54,    55,    -1,    57,    58,    59,    60,
    -1,    62,    63,    64,    -1,    66,    -1,    -1,    -1,    70,
    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,     0,
     1,    -1,     3,     4,    -1,     6,     7,     8,    -1,    10,
    11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
    -1,    22,    23,    24,    25,   106,    27,    28,    29,    30,
    31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
    41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
    -1,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
    61,    62,    63,    64,    -1,    66,    -1,    68,    -1,    70,
    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    80,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,   100,
   101,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    12,
    13,    14,    -1,    16,    -1,    18,    19,    20,    -1,    22,
    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,
    43,    -1,    -1,    46,    47,    -1,    49,    50,    -1,    -1,
    -1,    54,    55,    -1,    57,    58,    59,    60,    -1,    62,
    63,    64,    -1,    66,    -1,    -1,    -1,    70,    71,    72,
    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    94,    95,    96,    97,    98,    99,     1,    -1,    -1,
     4,    -1,     6,    -1,     8,    -1,    10,    -1,    12,    13,
    14,    -1,    16,    -1,    18,    19,    20,    -1,    22,    23,
    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,    43,
    44,    -1,    46,    47,    -1,    49,    50,    -1,    52,    -1,
    54,    55,    -1,    57,    58,    59,    60,    -1,    62,    63,
    64,    -1,    66,    -1,    -1,    -1,    70,    71,    72,    73,
     4,    -1,     6,    -1,     8,    -1,    10,    -1,    12,    13,
    -1,    -1,    16,    87,    -1,    19,    20,    -1,    22,    -1,
    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    43,
    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,
    -1,    55,    -1,    57,    58,    59,    60,    -1,    62,    63,
    -1,    -1,    66,    -1,    -1,    -1,    70,    71,    -1,    73,
    -1,     4,    76,     6,    -1,     8,    -1,    10,    -1,    12,
    13,    14,    -1,    16,    -1,    18,    19,    20,    -1,    22,
    23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
    33,    34,    35,    -1,    37,    -1,    39,    40,    41,    -1,
    43,    -1,    -1,    46,    47,    -1,    49,    50,    -1,    52,
    -1,    54,    55,    -1,    57,    58,    59,    60,    -1,    62,
    63,    64,    -1,    66,    -1,    -1,    -1,    70,    71,    72,
    73,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    12,
    13,    -1,    -1,    16,    -1,    -1,    19,    20,    -1,    22,
    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
    43,    -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,
    -1,    -1,    55,    -1,    57,    58,    59,    60,    -1,    62,
    63,    -1,    -1,    66,    -1,    -1,    -1,    70,    71,    -1,
    73
};

#line 292 "/usr/local/lib/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_HTMLParser_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        return(0)
#define YYABORT         return(1)
#define YYERROR         goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_HTMLParser_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_HTMLParser_CHAR = (token), YY_HTMLParser_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_HTMLParser_CHAR);                                \
      YYPOPSTACK;                                               \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    { YY_HTMLParser_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_HTMLParser_PURE
/* UNPURE */
#define YYLEX           YY_HTMLParser_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_HTMLParser_CHAR;                      /*  the lookahead symbol        */
YY_HTMLParser_STYPE      YY_HTMLParser_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_HTMLParser_NERRS;                 /*  number of parse errors so far */
#ifdef YY_HTMLParser_LSP_NEEDED
YY_HTMLParser_LTYPE YY_HTMLParser_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_HTMLParser_LSP_NEEDED
#define YYLEX           YY_HTMLParser_LEX(&YY_HTMLParser_LVAL, &YY_HTMLParser_LLOC)
#else
#define YYLEX           YY_HTMLParser_LEX(&YY_HTMLParser_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_HTMLParser_DEBUG != 0
int YY_HTMLParser_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_HTMLParser_CLASS::
#endif
     YY_HTMLParser_PARSE(YY_HTMLParser_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_HTMLParser_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_HTMLParser_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_HTMLParser_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_HTMLParser_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_HTMLParser_LSP_NEEDED
  YY_HTMLParser_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_HTMLParser_LTYPE *yyls = yylsa;
  YY_HTMLParser_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_HTMLParser_PURE
  int YY_HTMLParser_CHAR;
  YY_HTMLParser_STYPE YY_HTMLParser_LVAL;
  int YY_HTMLParser_NERRS;
#ifdef YY_HTMLParser_LSP_NEEDED
  YY_HTMLParser_LTYPE YY_HTMLParser_LLOC;
#endif
#endif

  YY_HTMLParser_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  YY_HTMLParser_NERRS = 0;
  YY_HTMLParser_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_HTMLParser_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_HTMLParser_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_HTMLParser_LSP_NEEDED
      YY_HTMLParser_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
#ifdef YY_HTMLParser_LSP_NEEDED
		 &yyls1, size * sizeof (*yylsp),
#endif
		 &yystacksize);

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_HTMLParser_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_HTMLParser_ERROR("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YY_HTMLParser_STYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YY_HTMLParser_LSP_NEEDED
      yyls = (YY_HTMLParser_LTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_HTMLParser_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_HTMLParser_DEBUG != 0
      if (YY_HTMLParser_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_HTMLParser_CHAR == YYEMPTY)
    {
#if YY_HTMLParser_DEBUG != 0
      if (YY_HTMLParser_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_HTMLParser_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_HTMLParser_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_HTMLParser_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_HTMLParser_DEBUG != 0
      if (YY_HTMLParser_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_HTMLParser_CHAR);

#if YY_HTMLParser_DEBUG != 0
      if (YY_HTMLParser_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_HTMLParser_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_HTMLParser_CHAR, YY_HTMLParser_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_HTMLParser_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_HTMLParser_CHAR != YYEOF)
    YY_HTMLParser_CHAR = YYEMPTY;

  *++yyvsp = YY_HTMLParser_LVAL;
#ifdef YY_HTMLParser_LSP_NEEDED
  *++yylsp = YY_HTMLParser_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 697 "/usr/local/lib/bison.cc" */

  switch (yyn) {

case 1:
#line 274 "HTMLParser.y"
{
    process(*yyvsp[0].document);
    delete yyvsp[0].document;
  ;
    break;}
case 2:
#line 305 "HTMLParser.y"
{
    yyval.document = new Document;
    yyval.document->body.content.reset(new list<auto_ptr<Element> >);
  ;
    break;}
case 3:
#line 309 "HTMLParser.y"
{
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 4:
#line 312 "HTMLParser.y"
{
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 5:
#line 315 "HTMLParser.y"
{
    yyval.document->attributes.reset(yyvsp[0].tag_attributes);
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 6:
#line 319 "HTMLParser.y"
{
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 7:
#line 322 "HTMLParser.y"
{
    delete yyvsp[0].tag_attributes;
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 8:
#line 326 "HTMLParser.y"
{
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 9:
#line 329 "HTMLParser.y"
{
    delete yyvsp[-2].tag_attributes; // Ignore <TITLE> attributes
    (yyval.document = yyvsp[-3].document)->head.title.reset(yyvsp[-1].pcdata);
  ;
    break;}
case 10:
#line 333 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->head.isindex_attributes.reset(yyvsp[0].tag_attributes);
  ;
    break;}
case 11:
#line 336 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->head.base_attributes.reset(yyvsp[0].tag_attributes);
  ;
    break;}
case 12:
#line 339 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->head.meta_attributes.reset(yyvsp[0].tag_attributes);
  ;
    break;}
case 13:
#line 342 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->head.link_attributes.reset(yyvsp[0].tag_attributes);
  ;
    break;}
case 14:
#line 345 "HTMLParser.y"
{
    auto_ptr<Script> s(new Script);
    s->attributes.reset(yyvsp[0].tag_attributes);
    if (!read_cdata("</SCRIPT>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
    (yyval.document = yyvsp[-1].document)->head.scripts.push_back(s);
  ;
    break;}
case 15:
#line 353 "HTMLParser.y"
{
    auto_ptr<Style> s(new Style);
    s->attributes.reset(yyvsp[0].tag_attributes);
    if (!read_cdata("</STYLE>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
    (yyval.document = yyvsp[-1].document)->head.styles.push_back(s);
  ;
    break;}
case 16:
#line 361 "HTMLParser.y"
{
    delete yyvsp[0].tag_attributes;
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 17:
#line 365 "HTMLParser.y"
{
    yyval.document = yyvsp[-1].document;
  ;
    break;}
case 18:
#line 368 "HTMLParser.y"
{
    Paragraph *p = new Paragraph;
    p->texts.reset(yyvsp[0].element_list);
    (yyval.document = yyvsp[-1].document)->body.content->push_back(auto_ptr<Element>(p));
  ;
    break;}
case 19:
#line 373 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->body.content->push_back(auto_ptr<Element>(yyvsp[0].heading));
  ;
    break;}
case 20:
#line 376 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->body.content->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 21:
#line 379 "HTMLParser.y"
{
    (yyval.document = yyvsp[-1].document)->body.content->push_back(auto_ptr<Element>(yyvsp[0].address));
  ;
    break;}
case 22:
#line 385 "HTMLParser.y"
{
    yyval.pcdata = new PCData;
    yyval.pcdata->text = *yyvsp[0].strinG;
    delete yyvsp[0].strinG;
  ;
    break;}
case 23:
#line 393 "HTMLParser.y"
{
    yyval.element_list = new list<auto_ptr<Element> >;
  ;
    break;}
case 24:
#line 396 "HTMLParser.y"
{
    yyval.element_list = yyvsp[-1].element_list;
  ;
    break;}
case 25:
#line 399 "HTMLParser.y"
{
    auto_ptr<Script> s(new Script);
    s->attributes.reset(yyvsp[0].tag_attributes);
    if (!read_cdata("</SCRIPT>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
//    ($$ = $1)->head.scripts.push_back(s);
  ;
    break;}
case 26:
#line 407 "HTMLParser.y"
{
    auto_ptr<Style> s(new Style);
    s->attributes.reset(yyvsp[0].tag_attributes);
    if (!read_cdata("</STYLE>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
//    ($$ = $1)->head.styles.push_back(s);
  ;
    break;}
case 27:
#line 415 "HTMLParser.y"
{
    Paragraph *p = new Paragraph;
    p->texts = auto_ptr<list<auto_ptr<Element> > >(yyvsp[0].element_list);
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(p));
  ;
    break;}
case 28:
#line 420 "HTMLParser.y"
{
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(yyvsp[0].heading));
  ;
    break;}
case 29:
#line 423 "HTMLParser.y"
{
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 30:
#line 426 "HTMLParser.y"
{
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(yyvsp[0].address));
  ;
    break;}
case 31:
#line 432 "HTMLParser.y"
{
            /* EXTENSION: Allow paragraph content in heading, not only texts */
    if (yyvsp[-2].heading->level != yyvsp[0].inT) {
      yyerror ("Levels of opening and closing headings don't match");
    }
    yyval.heading = yyvsp[-2].heading;
    yyval.heading->content.reset(yyvsp[-1].element_list);
  ;
    break;}
case 32:
#line 443 "HTMLParser.y"
{
    yyval.element = yyvsp[0].element;
  ;
    break;}
case 33:
#line 446 "HTMLParser.y"
{
    Paragraph *p = new Paragraph;
    p->attributes.reset(yyvsp[-2].tag_attributes);
    p->texts.reset(yyvsp[-1].element_list);
    yyval.element = p;
  ;
    break;}
case 34:
#line 455 "HTMLParser.y"
{
    yyval.element_list = new list<auto_ptr<Element> >;
  ;
    break;}
case 35:
#line 458 "HTMLParser.y"
{
    yyval.element_list = yyvsp[-1].element_list;
  ;
    break;}
case 36:
#line 461 "HTMLParser.y"
{
    yyval.element_list = yyvsp[-1].element_list;
    yyval.element_list->splice(yyval.element_list->end(), *yyvsp[0].element_list);
    delete yyvsp[0].element_list;
  ;
    break;}
case 37:
#line 466 "HTMLParser.y"
{
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 38:
#line 472 "HTMLParser.y"
{
    yyval.element = yyvsp[0].element;
  ;
    break;}
case 39:
#line 475 "HTMLParser.y"
{
    yyval.element = yyvsp[0].preformatted;
  ;
    break;}
case 40:
#line 478 "HTMLParser.y"
{
    yyval.element = yyvsp[0].definition_list;
  ;
    break;}
case 41:
#line 481 "HTMLParser.y"
{
    Division *p = new Division;
    p->attributes.reset(yyvsp[-2].tag_attributes);
    p->body_content.reset(yyvsp[-1].element_list);
    yyval.element = p;
  ;
    break;}
case 42:
#line 487 "HTMLParser.y"
{
    Center *p = new Center;
    delete yyvsp[-2].tag_attributes;       // CENTER has no attributes.
    p->body_content.reset(yyvsp[-1].element_list);
    yyval.element = p;
  ;
    break;}
case 43:
#line 493 "HTMLParser.y"
{
    delete yyvsp[-2].tag_attributes; // BLOCKQUOTE has no attributes!
    BlockQuote *bq = new BlockQuote;
    bq->content.reset(yyvsp[-1].element_list);
    yyval.element = bq;
  ;
    break;}
case 44:
#line 499 "HTMLParser.y"
{
    Form *f = new Form;
    f->attributes.reset(yyvsp[-2].tag_attributes);
    f->content.reset(yyvsp[-1].element_list);
    yyval.element = f;
  ;
    break;}
case 45:
#line 505 "HTMLParser.y"
{
    HorizontalRule *h = new HorizontalRule;
    h->attributes.reset(yyvsp[0].tag_attributes);
    yyval.element = h;
  ;
    break;}
case 46:
#line 510 "HTMLParser.y"
{
    Table *t = new Table;
    t->attributes.reset(yyvsp[-3].tag_attributes);
    t->caption.reset(yyvsp[-2].caption);
    t->rows.reset(yyvsp[-1].table_rows);
    yyval.element = t;
  ;
    break;}
case 47:
#line 520 "HTMLParser.y"
{ ++list_nesting; ;
    break;}
case 48:
#line 520 "HTMLParser.y"
{
    OrderedList *ol = new OrderedList;
    ol->attributes.reset(yyvsp[-3].tag_attributes);
    ol->items.reset(yyvsp[-1].list_items);
    ol->nesting = --list_nesting;
    yyval.element = ol;
  ;
    break;}
case 49:
#line 527 "HTMLParser.y"
{ ++list_nesting; ;
    break;}
case 50:
#line 527 "HTMLParser.y"
{
    UnorderedList *ul = new UnorderedList;
    ul->attributes.reset(yyvsp[-3].tag_attributes);
    ul->items.reset(yyvsp[-1].list_items);
    ul->nesting = --list_nesting;
    yyval.element = ul;
  ;
    break;}
case 51:
#line 534 "HTMLParser.y"
{ ++list_nesting; ;
    break;}
case 52:
#line 534 "HTMLParser.y"
{
    Dir *d = new Dir;
    d->attributes.reset(yyvsp[-3].tag_attributes);
    d->items.reset(yyvsp[-1].list_items);
    d->nesting = --list_nesting;
    yyval.element = d;
  ;
    break;}
case 53:
#line 541 "HTMLParser.y"
{ ++list_nesting; ;
    break;}
case 54:
#line 541 "HTMLParser.y"
{
    Menu *m = new Menu;
    m->attributes.reset(yyvsp[-3].tag_attributes);
    m->items.reset(yyvsp[-1].list_items);
    m->nesting = --list_nesting;
    yyval.element = m;
  ;
    break;}
case 55:
#line 551 "HTMLParser.y"
{
    yyval.list_items = 0;
  ;
    break;}
case 56:
#line 554 "HTMLParser.y"
{
    yyval.list_items = yyvsp[-1].list_items;
  ;
    break;}
case 57:
#line 557 "HTMLParser.y"
{
    yyval.list_items = yyvsp[-1].list_items ? yyvsp[-1].list_items : new list<auto_ptr<ListItem> >;
    yyval.list_items->push_back(auto_ptr<ListItem>(yyvsp[0].list_item));
  ;
    break;}
case 58:
#line 564 "HTMLParser.y"
{
    ListNormalItem *lni = new ListNormalItem;
    lni->attributes.reset(yyvsp[-2].tag_attributes);
    lni->flow.reset(yyvsp[-1].element_list);
    yyval.list_item = lni;
  ;
    break;}
case 59:
#line 570 "HTMLParser.y"
{   /* EXTENSION: Handle a "block" in a list as an indented block. */
    ListBlockItem *lbi = new ListBlockItem;
    lbi->block.reset(yyvsp[0].element);
    yyval.list_item = lbi;
  ;
    break;}
case 60:
#line 575 "HTMLParser.y"
{              /* EXTENSION: Treat "texts" in a list as an "<LI>". */
    ListNormalItem *lni = new ListNormalItem;
    lni->flow.reset(yyvsp[0].element_list);
    yyval.list_item = lni;
  ;
    break;}
case 61:
#line 585 "HTMLParser.y"
{
    delete yyvsp[-4].tag_attributes;
    delete yyvsp[-3].element_list; /* Kludge */
    yyval.definition_list = yyvsp[-1].definition_list;
  ;
    break;}
case 62:
#line 591 "HTMLParser.y"
{
    DefinitionList *dl = new DefinitionList;
    dl->attributes.reset(yyvsp[-4].tag_attributes);
    dl->preamble.reset(yyvsp[-3].element_list);
    dl->items.reset(yyvsp[-1].definition_list_item_list);
    yyval.definition_list = dl;
  ;
    break;}
case 63:
#line 601 "HTMLParser.y"
{
    yyval.definition_list_item_list = 0;
  ;
    break;}
case 64:
#line 604 "HTMLParser.y"
{
    yyval.definition_list_item_list = yyvsp[0].definition_list_item_list;
  ;
    break;}
case 65:
#line 607 "HTMLParser.y"
{
    yyval.definition_list_item_list = yyvsp[-1].definition_list_item_list ? yyvsp[-1].definition_list_item_list : new list<auto_ptr<DefinitionListItem> >;
    yyval.definition_list_item_list->push_back(auto_ptr<DefinitionListItem>(yyvsp[0].term_name));
  ;
    break;}
case 66:
#line 611 "HTMLParser.y"
{
    yyval.definition_list_item_list = yyvsp[-1].definition_list_item_list ? yyvsp[-1].definition_list_item_list : new list<auto_ptr<DefinitionListItem> >;
    yyval.definition_list_item_list->push_back(auto_ptr<DefinitionListItem>(yyvsp[0].term_definition));
  ;
    break;}
case 67:
#line 618 "HTMLParser.y"
{      /* EXTENSION: Allow "flow" instead of "texts" */
    delete yyvsp[-2].tag_attributes;
    yyval.term_name = new TermName;
    yyval.term_name->flow.reset(yyvsp[-1].element_list);
  ;
    break;}
case 68:
#line 623 "HTMLParser.y"
{/* EXTENSION: Ignore <P> after </DT> */
    delete yyvsp[-4].tag_attributes;
    delete yyvsp[-1].tag_attributes;
    yyval.term_name = new TermName;
    yyval.term_name->flow.reset(yyvsp[-3].element_list);
  ;
    break;}
case 69:
#line 632 "HTMLParser.y"
{
    delete yyvsp[-2].tag_attributes;
    yyval.term_definition = new TermDefinition;
    yyval.term_definition->flow.reset(yyvsp[-1].element_list);
  ;
    break;}
case 70:
#line 637 "HTMLParser.y"
{/* EXTENSION: Ignore <P> after </DD> */
    delete yyvsp[-4].tag_attributes;
    delete yyvsp[-1].tag_attributes;
    yyval.term_definition = new TermDefinition;
    yyval.term_definition->flow.reset(yyvsp[-3].element_list);
  ;
    break;}
case 71:
#line 646 "HTMLParser.y"
{
    yyval.element_list = new list<auto_ptr<Element> >;
    yyval.element_list->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 72:
#line 650 "HTMLParser.y"
{
    yyval.element_list = yyvsp[-1].element_list;
  ;
    break;}
case 73:
#line 653 "HTMLParser.y"
{
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 74:
#line 659 "HTMLParser.y"
{
    yyval.element = yyvsp[0].element;
  ;
    break;}
case 75:
#line 662 "HTMLParser.y"
{          /* EXTENSION: Allow headings in "flow", i.e. in lists */
    yyval.element = yyvsp[0].heading;
  ;
    break;}
case 76:
#line 665 "HTMLParser.y"
{
    yyval.element = yyvsp[0].element;
  ;
    break;}
case 77:
#line 671 "HTMLParser.y"
{
    yyval.preformatted = new Preformatted;
    yyval.preformatted->attributes.reset(yyvsp[-2].tag_attributes);
    yyval.preformatted->texts.reset(yyvsp[-1].element_list);
  ;
    break;}
case 78:
#line 679 "HTMLParser.y"
{
    yyval.caption = new Caption;
    yyval.caption->attributes.reset(yyvsp[-2].tag_attributes);
    yyval.caption->texts.reset(yyvsp[-1].element_list);
  ;
    break;}
case 79:
#line 687 "HTMLParser.y"
{
    yyval.table_rows = new list<auto_ptr<TableRow> >;
  ;
    break;}
case 80:
#line 690 "HTMLParser.y"
{
    yyval.table_rows = yyvsp[-1].table_rows;
  ;
    break;}
case 81:
#line 693 "HTMLParser.y"
{
    TableRow *tr = new TableRow;
    tr->attributes.reset(yyvsp[-2].tag_attributes);
    tr->cells.reset(yyvsp[-1].table_cells);
    (yyval.table_rows = yyvsp[-3].table_rows)->push_back(auto_ptr<TableRow>(tr));
  ;
    break;}
case 82:
#line 702 "HTMLParser.y"
{
    yyval.table_cells = new list<auto_ptr<TableCell> >;
  ;
    break;}
case 83:
#line 705 "HTMLParser.y"
{
    yyval.table_cells = yyvsp[-1].table_cells;
  ;
    break;}
case 84:
#line 708 "HTMLParser.y"
{
    TableCell *tc = new TableCell;
    tc->attributes.reset(yyvsp[-2].tag_attributes);
    tc->content.reset(yyvsp[-1].element_list);
    (yyval.table_cells = yyvsp[-3].table_cells)->push_back(auto_ptr<TableCell>(tc));
  ;
    break;}
case 85:
#line 714 "HTMLParser.y"
{
                            /* EXTENSION: Allow "</TD>" in place of "</TH>". */
    TableHeadingCell *thc = new TableHeadingCell;
    thc->attributes.reset(yyvsp[-3].tag_attributes);
    thc->content.reset(yyvsp[-2].element_list);
    (yyval.table_cells = yyvsp[-4].table_cells)->push_back(auto_ptr<TableCell>(thc));
  ;
    break;}
case 86:
#line 721 "HTMLParser.y"
{    /* EXTENSION: Ignore <INPUT> between table cells. */
    delete yyvsp[0].tag_attributes;
    yyval.table_cells = yyvsp[-1].table_cells;
  ;
    break;}
case 87:
#line 728 "HTMLParser.y"
{ /* Should be "address_content"... */
    delete yyvsp[-2].tag_attributes;
    yyval.address = new Address;
    yyval.address->content.reset(yyvsp[-1].element_list);
  ;
    break;}
case 88:
#line 738 "HTMLParser.y"
{
    yyval.element_list = new list<auto_ptr<Element> >;
    yyval.element_list->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 89:
#line 742 "HTMLParser.y"
{
    (yyval.element_list = yyvsp[-1].element_list)->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 90:
#line 748 "HTMLParser.y"
{ yyval.element = yyvsp[-1].pcdata; ;
    break;}
case 91:
#line 749 "HTMLParser.y"
{ yyval.element = yyvsp[-1].element; ;
    break;}
case 92:
#line 750 "HTMLParser.y"
{ yyval.element = yyvsp[-1].element; ;
    break;}
case 93:
#line 751 "HTMLParser.y"
{ yyval.element = yyvsp[-1].element; ;
    break;}
case 94:
#line 752 "HTMLParser.y"
{ yyval.element = yyvsp[-1].element; ;
    break;}
case 95:
#line 753 "HTMLParser.y"
{ /* EXTENSION: NS 1.1 / IE 2.0 */
    NoBreak *nb = new NoBreak;
    delete yyvsp[-3].tag_attributes;
    nb->content.reset(yyvsp[-2].element_list);
    yyval.element = nb;
  ;
    break;}
case 96:
#line 762 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(TT,     yyvsp[-1].element_list); ;
    break;}
case 97:
#line 763 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(I,      yyvsp[-1].element_list); ;
    break;}
case 98:
#line 764 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(B,      yyvsp[-1].element_list); ;
    break;}
case 99:
#line 765 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(U,      yyvsp[-1].element_list); ;
    break;}
case 100:
#line 766 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(STRIKE, yyvsp[-1].element_list); ;
    break;}
case 101:
#line 767 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(BIG,    yyvsp[-1].element_list); ;
    break;}
case 102:
#line 768 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(SMALL,  yyvsp[-1].element_list); ;
    break;}
case 103:
#line 769 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(SUB,    yyvsp[-1].element_list); ;
    break;}
case 104:
#line 770 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Font(SUP,    yyvsp[-1].element_list); ;
    break;}
case 105:
#line 774 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(EM,     yyvsp[-1].element_list); ;
    break;}
case 106:
#line 775 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(STRONG, yyvsp[-1].element_list); ;
    break;}
case 107:
#line 776 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(DFN,    yyvsp[-1].element_list); ;
    break;}
case 108:
#line 777 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(CODE,   yyvsp[-1].element_list); ;
    break;}
case 109:
#line 778 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(SAMP,   yyvsp[-1].element_list); ;
    break;}
case 110:
#line 779 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(KBD,    yyvsp[-1].element_list); ;
    break;}
case 111:
#line 780 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(VAR,    yyvsp[-1].element_list); ;
    break;}
case 112:
#line 781 "HTMLParser.y"
{ delete yyvsp[-2].tag_attributes; yyval.element = new Phrase(CITE,   yyvsp[-1].element_list); ;
    break;}
case 113:
#line 788 "HTMLParser.y"
{
    delete yyvsp[-2].tag_attributes;
    Anchor *a = new Anchor;
    a->attributes.reset(yyvsp[-3].tag_attributes);
    a->texts.reset(yyvsp[-1].element_list);
    yyval.element = a;
  ;
    break;}
case 114:
#line 795 "HTMLParser.y"
{
    Image *i = new Image;
    i->attributes.reset(yyvsp[0].tag_attributes);
    yyval.element = i;
  ;
    break;}
case 115:
#line 800 "HTMLParser.y"
{
    Applet *a = new Applet;
    a->attributes.reset(yyvsp[-2].tag_attributes);
    a->content.reset(yyvsp[-1].element_list);
    yyval.element = a;
  ;
    break;}
case 116:
#line 808 "HTMLParser.y"
{
    Font2 *f2 = new Font2;
    f2->attributes.reset(yyvsp[-2].tag_attributes);
    f2->elements.reset(yyvsp[-1].element_list);
    yyval.element = f2;
  ;
    break;}
case 117:
#line 814 "HTMLParser.y"
{
    BaseFont *bf = new BaseFont;
    bf->attributes.reset(yyvsp[0].tag_attributes);
    yyval.element = bf;
  ;
    break;}
case 118:
#line 819 "HTMLParser.y"
{
    LineBreak *lb = new LineBreak;
    lb->attributes.reset(yyvsp[0].tag_attributes);
    yyval.element = lb;
  ;
    break;}
case 119:
#line 824 "HTMLParser.y"
{
    Map *m = new Map;
    m->attributes.reset(yyvsp[-2].tag_attributes);
    m->areas.reset(yyvsp[-1].tag_attributes_list);
    yyval.element = m;
  ;
    break;}
case 120:
#line 833 "HTMLParser.y"
{
    yyval.element_list = 0;
  ;
    break;}
case 121:
#line 836 "HTMLParser.y"
{
    yyval.element_list = yyvsp[-1].element_list ? yyvsp[-1].element_list : new list<auto_ptr<Element> >;
    yyval.element_list->push_back(auto_ptr<Element>(yyvsp[0].element));
  ;
    break;}
case 122:
#line 840 "HTMLParser.y"
{
    yyval.element_list = yyvsp[-1].element_list ? yyvsp[-1].element_list : new list<auto_ptr<Element> >;
    Param *p = new Param;
    p->attributes.reset(yyvsp[0].tag_attributes);
    yyval.element_list->push_back(auto_ptr<Element>(p));
  ;
    break;}
case 123:
#line 849 "HTMLParser.y"
{
    yyval.tag_attributes_list = 0;
  ;
    break;}
case 124:
#line 852 "HTMLParser.y"
{
    yyval.tag_attributes_list = yyvsp[-1].tag_attributes_list;
  ;
    break;}
case 125:
#line 855 "HTMLParser.y"
{
    yyval.tag_attributes_list = yyvsp[-1].tag_attributes_list ? yyvsp[-1].tag_attributes_list : new list<auto_ptr<list<TagAttribute> > >;
    yyval.tag_attributes_list->push_back(auto_ptr<list<TagAttribute> >(yyvsp[0].tag_attributes));
  ;
    break;}
case 126:
#line 862 "HTMLParser.y"
{
    Input *i = new Input;
    i->attributes.reset(yyvsp[0].tag_attributes);
    yyval.element = i;
  ;
    break;}
case 127:
#line 867 "HTMLParser.y"
{
    Select *s = new Select;
    s->attributes.reset(yyvsp[-2].tag_attributes);
    s->content.reset(yyvsp[-1].option_list);
    yyval.element = s;
  ;
    break;}
case 128:
#line 873 "HTMLParser.y"
{
    TextArea *ta = new TextArea;
    ta->attributes.reset(yyvsp[-2].tag_attributes);
    ta->pcdata.reset(yyvsp[-1].pcdata);
    yyval.element = ta;
  ;
    break;}
case 129:
#line 882 "HTMLParser.y"
{
    yyval.option_list = new list<auto_ptr<Option> >;
    yyval.option_list->push_back(auto_ptr<Option>(yyvsp[0].option));
  ;
    break;}
case 130:
#line 886 "HTMLParser.y"
{
    (yyval.option_list = yyvsp[-1].option_list)->push_back(auto_ptr<Option>(yyvsp[0].option));
  ;
    break;}
case 131:
#line 892 "HTMLParser.y"
{
    yyval.option = new Option;
    yyval.option->attributes.reset(yyvsp[-2].tag_attributes);
    yyval.option->pcdata.reset(yyvsp[-1].pcdata);
  ;
    break;}
case 132:
#line 902 "HTMLParser.y"
{ yyval.heading = new Heading; yyval.heading->level = 1; yyval.heading->attributes.reset(yyvsp[0].tag_attributes); ;
    break;}
case 133:
#line 903 "HTMLParser.y"
{ yyval.heading = new Heading; yyval.heading->level = 2; yyval.heading->attributes.reset(yyvsp[0].tag_attributes); ;
    break;}
case 134:
#line 904 "HTMLParser.y"
{ yyval.heading = new Heading; yyval.heading->level = 3; yyval.heading->attributes.reset(yyvsp[0].tag_attributes); ;
    break;}
case 135:
#line 905 "HTMLParser.y"
{ yyval.heading = new Heading; yyval.heading->level = 4; yyval.heading->attributes.reset(yyvsp[0].tag_attributes); ;
    break;}
case 136:
#line 906 "HTMLParser.y"
{ yyval.heading = new Heading; yyval.heading->level = 5; yyval.heading->attributes.reset(yyvsp[0].tag_attributes); ;
    break;}
case 137:
#line 907 "HTMLParser.y"
{ yyval.heading = new Heading; yyval.heading->level = 6; yyval.heading->attributes.reset(yyvsp[0].tag_attributes); ;
    break;}
case 138:
#line 911 "HTMLParser.y"
{ yyval.inT = 1; ;
    break;}
case 139:
#line 912 "HTMLParser.y"
{ yyval.inT = 2; ;
    break;}
case 140:
#line 913 "HTMLParser.y"
{ yyval.inT = 3; ;
    break;}
case 141:
#line 914 "HTMLParser.y"
{ yyval.inT = 4; ;
    break;}
case 142:
#line 915 "HTMLParser.y"
{ yyval.inT = 5; ;
    break;}
case 143:
#line 916 "HTMLParser.y"
{ yyval.inT = 6; ;
    break;}
case 144:
#line 921 "HTMLParser.y"
{ yyval.pcdata = 0; ;
    break;}
case 145:
#line 921 "HTMLParser.y"
{ yyval.pcdata = yyvsp[0].pcdata; ;
    break;}
case 146:
#line 922 "HTMLParser.y"
{ yyval.caption = 0; ;
    break;}
case 147:
#line 922 "HTMLParser.y"
{ yyval.caption = yyvsp[0].caption; ;
    break;}
case 148:
#line 923 "HTMLParser.y"
{ yyval.element_list = 0; ;
    break;}
case 149:
#line 923 "HTMLParser.y"
{ yyval.element_list = yyvsp[0].element_list; ;
    break;}
case 150:
#line 924 "HTMLParser.y"
{ yyval.element_list = 0; ;
    break;}
case 151:
#line 924 "HTMLParser.y"
{ yyval.element_list = yyvsp[0].element_list; ;
    break;}
case 152:
#line 926 "HTMLParser.y"
{ yyval.tag_attributes = 0; ;
    break;}
case 153:
#line 926 "HTMLParser.y"
{ yyval.tag_attributes = yyvsp[0].tag_attributes; ;
    break;}
case 154:
#line 927 "HTMLParser.y"
{ yyval.tag_attributes = 0; ;
    break;}
case 155:
#line 927 "HTMLParser.y"
{ yyval.tag_attributes = yyvsp[0].tag_attributes; ;
    break;}
}

#line 697 "/usr/local/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_HTMLParser_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_HTMLParser_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_HTMLParser_LLOC.first_line;
      yylsp->first_column = YY_HTMLParser_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_HTMLParser_NERRS;

#ifdef YY_HTMLParser_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_HTMLParser_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_HTMLParser_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_HTMLParser_ERROR_VERBOSE */
	YY_HTMLParser_ERROR("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_HTMLParser_CHAR == YYEOF)
	YYABORT;

#if YY_HTMLParser_DEBUG != 0
      if (YY_HTMLParser_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_HTMLParser_CHAR, yytname[yychar1]);
#endif

      YY_HTMLParser_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_HTMLParser_LSP_NEEDED
  yylsp--;
#endif

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_HTMLParser_DEBUG != 0
  if (YY_HTMLParser_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_HTMLParser_LVAL;
#ifdef YY_HTMLParser_LSP_NEEDED
  *++yylsp = YY_HTMLParser_LLOC;
#endif

  yystate = yyn;
  goto yynewstate;
}

/* END */

/* #line 891 "/usr/local/lib/bison.cc" */
#line 965 "HTMLParser.y"
 /* } */

/*
 * Some C++ compilers (e.g. EGCS 2.91.66) have problems if all virtual
 * methods of a class are inline or pure virtual, so we define the destructor,
 * which is the only virtual method, non-inline, although it is empty.
 */

HTMLParser::~HTMLParser()
{
}

/* ------------------------------------------------------------------------- */

