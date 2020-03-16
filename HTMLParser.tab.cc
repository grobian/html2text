// A Bison parser, made by GNU Bison 3.5.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "HTMLParser.tab.hh"


// Unqualified %code blocks.
#line 55 "HTMLParser.yy"

#include "HTMLDriver.h"
// call the lex function of HTMLDriver instead of plain yylex
#undef yylex
#define yylex drv.lex
#undef yyerror
#define yyerror drv.yyerror

#line 54 "HTMLParser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 40 "HTMLParser.yy"
namespace html2text {
#line 127 "HTMLParser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  HTMLParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  HTMLParser::HTMLParser (HTMLDriver &drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  HTMLParser::~HTMLParser ()
  {}

  HTMLParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  HTMLParser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  HTMLParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  HTMLParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  HTMLParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  HTMLParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  HTMLParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  HTMLParser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  HTMLParser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  HTMLParser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  HTMLParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  HTMLParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  HTMLParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  HTMLParser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  HTMLParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  HTMLParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  HTMLParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  HTMLParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  HTMLParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  HTMLParser::symbol_number_type
  HTMLParser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  HTMLParser::stack_symbol_type::stack_symbol_type ()
  {}

  HTMLParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  HTMLParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  HTMLParser::stack_symbol_type&
  HTMLParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  HTMLParser::stack_symbol_type&
  HTMLParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  HTMLParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  HTMLParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  HTMLParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  HTMLParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  HTMLParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  HTMLParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  HTMLParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  HTMLParser::debug_level_type
  HTMLParser::debug_level () const
  {
    return yydebug_;
  }

  void
  HTMLParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  HTMLParser::state_type
  HTMLParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  HTMLParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  HTMLParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  HTMLParser::operator() ()
  {
    return parse ();
  }

  int
  HTMLParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 273 "HTMLParser.yy"
            {
    drv.process(*(yystack_[0].value.document));
    delete (yystack_[0].value.document);
  }
#line 609 "HTMLParser.tab.cc"
    break;

  case 3:
#line 304 "HTMLParser.yy"
              {
    (yylhs.value.document) = new Document;
    (yylhs.value.document)->body.content.reset(new list<auto_ptr<Element> >);
  }
#line 618 "HTMLParser.tab.cc"
    break;

  case 4:
#line 308 "HTMLParser.yy"
                    {
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 626 "HTMLParser.tab.cc"
    break;

  case 5:
#line 311 "HTMLParser.yy"
                      {
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 634 "HTMLParser.tab.cc"
    break;

  case 6:
#line 314 "HTMLParser.yy"
                   {
    (yylhs.value.document)->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 643 "HTMLParser.tab.cc"
    break;

  case 7:
#line 318 "HTMLParser.yy"
                       {
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 651 "HTMLParser.tab.cc"
    break;

  case 8:
#line 321 "HTMLParser.yy"
                   {
    delete (yystack_[0].value.tag_attributes);
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 660 "HTMLParser.tab.cc"
    break;

  case 9:
#line 325 "HTMLParser.yy"
                       {
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 668 "HTMLParser.tab.cc"
    break;

  case 10:
#line 328 "HTMLParser.yy"
                                             {
    delete (yystack_[2].value.tag_attributes); // Ignore <TITLE> attributes
    ((yylhs.value.document) = (yystack_[3].value.document))->head.title.reset((yystack_[1].value.pcdata));
  }
#line 677 "HTMLParser.tab.cc"
    break;

  case 11:
#line 332 "HTMLParser.yy"
                      {
    ((yylhs.value.document) = (yystack_[1].value.document))->head.isindex_attributes.reset((yystack_[0].value.tag_attributes));
  }
#line 685 "HTMLParser.tab.cc"
    break;

  case 12:
#line 335 "HTMLParser.yy"
                   {
    ((yylhs.value.document) = (yystack_[1].value.document))->head.base_attributes.reset((yystack_[0].value.tag_attributes));
  }
#line 693 "HTMLParser.tab.cc"
    break;

  case 13:
#line 338 "HTMLParser.yy"
                   {
    ((yylhs.value.document) = (yystack_[1].value.document))->head.meta_attributes.reset((yystack_[0].value.tag_attributes));
  }
#line 701 "HTMLParser.tab.cc"
    break;

  case 14:
#line 341 "HTMLParser.yy"
                   {
    ((yylhs.value.document) = (yystack_[1].value.document))->head.link_attributes.reset((yystack_[0].value.tag_attributes));
  }
#line 709 "HTMLParser.tab.cc"
    break;

  case 15:
#line 344 "HTMLParser.yy"
                     {
    auto_ptr<Script> s(new Script);
    s->attributes.reset((yystack_[0].value.tag_attributes));
    if (!drv.read_cdata("</SCRIPT>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
    ((yylhs.value.document) = (yystack_[1].value.document))->head.scripts.push_back(s);
  }
#line 722 "HTMLParser.tab.cc"
    break;

  case 16:
#line 352 "HTMLParser.yy"
                    {
    auto_ptr<Style> s(new Style);
    s->attributes.reset((yystack_[0].value.tag_attributes));
    if (!drv.read_cdata("</STYLE>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
    ((yylhs.value.document) = (yystack_[1].value.document))->head.styles.push_back(s);
  }
#line 735 "HTMLParser.tab.cc"
    break;

  case 17:
#line 360 "HTMLParser.yy"
                   {
    delete (yystack_[0].value.tag_attributes);
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 744 "HTMLParser.tab.cc"
    break;

  case 18:
#line 364 "HTMLParser.yy"
                       {
    (yylhs.value.document) = (yystack_[1].value.document);
  }
#line 752 "HTMLParser.tab.cc"
    break;

  case 19:
#line 367 "HTMLParser.yy"
                    {
    Paragraph *p = new Paragraph;
    p->texts.reset((yystack_[0].value.element_list));
    ((yylhs.value.document) = (yystack_[1].value.document))->body.content->push_back(auto_ptr<Element>(p));
  }
#line 762 "HTMLParser.tab.cc"
    break;

  case 20:
#line 372 "HTMLParser.yy"
                      {
    ((yylhs.value.document) = (yystack_[1].value.document))->body.content->push_back(auto_ptr<Element>((yystack_[0].value.heading)));
  }
#line 770 "HTMLParser.tab.cc"
    break;

  case 21:
#line 375 "HTMLParser.yy"
                    {
    ((yylhs.value.document) = (yystack_[1].value.document))->body.content->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 778 "HTMLParser.tab.cc"
    break;

  case 22:
#line 378 "HTMLParser.yy"
                      {
    ((yylhs.value.document) = (yystack_[1].value.document))->body.content->push_back(auto_ptr<Element>((yystack_[0].value.address)));
  }
#line 786 "HTMLParser.tab.cc"
    break;

  case 23:
#line 384 "HTMLParser.yy"
         {
    (yylhs.value.pcdata) = new PCData;
    (yylhs.value.pcdata)->text = *(yystack_[0].value.strinG);
    delete (yystack_[0].value.strinG);
  }
#line 796 "HTMLParser.tab.cc"
    break;

  case 24:
#line 392 "HTMLParser.yy"
              {
    (yylhs.value.element_list) = new list<auto_ptr<Element> >;
  }
#line 804 "HTMLParser.tab.cc"
    break;

  case 25:
#line 395 "HTMLParser.yy"
                       {
    (yylhs.value.element_list) = (yystack_[1].value.element_list);
  }
#line 812 "HTMLParser.tab.cc"
    break;

  case 26:
#line 398 "HTMLParser.yy"
                        {
    auto_ptr<Script> s(new Script);
    s->attributes.reset((yystack_[0].value.tag_attributes));
    if (!drv.read_cdata("</SCRIPT>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
//    ($$ = $1)->head.scripts.push_back(s);
  }
#line 825 "HTMLParser.tab.cc"
    break;

  case 27:
#line 406 "HTMLParser.yy"
                       {
    auto_ptr<Style> s(new Style);
    s->attributes.reset((yystack_[0].value.tag_attributes));
    if (!drv.read_cdata("</STYLE>", &s->text)) {
      yyerror("CDATA terminal not found");
    }
//    ($$ = $1)->head.styles.push_back(s);
  }
#line 838 "HTMLParser.tab.cc"
    break;

  case 28:
#line 414 "HTMLParser.yy"
                       {
    Paragraph *p = new Paragraph;
    p->texts = auto_ptr<list<auto_ptr<Element> > >((yystack_[0].value.element_list));
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>(p));
  }
#line 848 "HTMLParser.tab.cc"
    break;

  case 29:
#line 419 "HTMLParser.yy"
                         {
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>((yystack_[0].value.heading)));
  }
#line 856 "HTMLParser.tab.cc"
    break;

  case 30:
#line 422 "HTMLParser.yy"
                       {
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 864 "HTMLParser.tab.cc"
    break;

  case 31:
#line 425 "HTMLParser.yy"
                         {
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>((yystack_[0].value.address)));
  }
#line 872 "HTMLParser.tab.cc"
    break;

  case 32:
#line 431 "HTMLParser.yy"
                              {
            /* EXTENSION: Allow paragraph content in heading, not only texts */
    if ((yystack_[2].value.heading)->level != (yystack_[0].value.inT)) {
      yyerror ("Levels of opening and closing headings don't match");
    }
    (yylhs.value.heading) = (yystack_[2].value.heading);
    (yylhs.value.heading)->content.reset((yystack_[1].value.element_list));
  }
#line 885 "HTMLParser.tab.cc"
    break;

  case 33:
#line 442 "HTMLParser.yy"
                 {
    (yylhs.value.element) = (yystack_[0].value.element);
  }
#line 893 "HTMLParser.tab.cc"
    break;

  case 34:
#line 445 "HTMLParser.yy"
                                  {
    Paragraph *p = new Paragraph;
    p->attributes.reset((yystack_[2].value.tag_attributes));
    p->texts.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = p;
  }
#line 904 "HTMLParser.tab.cc"
    break;

  case 35:
#line 454 "HTMLParser.yy"
              {
    (yylhs.value.element_list) = new list<auto_ptr<Element> >;
  }
#line 912 "HTMLParser.tab.cc"
    break;

  case 36:
#line 457 "HTMLParser.yy"
                            {
    (yylhs.value.element_list) = (yystack_[1].value.element_list);
  }
#line 920 "HTMLParser.tab.cc"
    break;

  case 37:
#line 460 "HTMLParser.yy"
                            {
    (yylhs.value.element_list) = (yystack_[1].value.element_list);
    (yylhs.value.element_list)->splice((yylhs.value.element_list)->end(), *(yystack_[0].value.element_list));
    delete (yystack_[0].value.element_list);
  }
#line 930 "HTMLParser.tab.cc"
    break;

  case 38:
#line 465 "HTMLParser.yy"
                                     {
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 938 "HTMLParser.tab.cc"
    break;

  case 39:
#line 471 "HTMLParser.yy"
       {
    (yylhs.value.element) = (yystack_[0].value.element);
  }
#line 946 "HTMLParser.tab.cc"
    break;

  case 40:
#line 474 "HTMLParser.yy"
                 {
    (yylhs.value.element) = (yystack_[0].value.preformatted);
  }
#line 954 "HTMLParser.tab.cc"
    break;

  case 41:
#line 477 "HTMLParser.yy"
                    {
    (yylhs.value.element) = (yystack_[0].value.definition_list);
  }
#line 962 "HTMLParser.tab.cc"
    break;

  case 42:
#line 480 "HTMLParser.yy"
                                 {
    Division *p = new Division;
    p->attributes.reset((yystack_[2].value.tag_attributes));
    p->body_content.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = p;
  }
#line 973 "HTMLParser.tab.cc"
    break;

  case 43:
#line 486 "HTMLParser.yy"
                                       {
    Center *p = new Center;
    delete (yystack_[2].value.tag_attributes);       // CENTER has no attributes.
    p->body_content.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = p;
  }
#line 984 "HTMLParser.tab.cc"
    break;

  case 44:
#line 492 "HTMLParser.yy"
                                               {
    delete (yystack_[2].value.tag_attributes); // BLOCKQUOTE has no attributes!
    BlockQuote *bq = new BlockQuote;
    bq->content.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = bq;
  }
#line 995 "HTMLParser.tab.cc"
    break;

  case 45:
#line 498 "HTMLParser.yy"
                                   {
    Form *f = new Form;
    f->attributes.reset((yystack_[2].value.tag_attributes));
    f->content.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = f;
  }
#line 1006 "HTMLParser.tab.cc"
    break;

  case 46:
#line 504 "HTMLParser.yy"
       {
    HorizontalRule *h = new HorizontalRule;
    h->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.element) = h;
  }
#line 1016 "HTMLParser.tab.cc"
    break;

  case 47:
#line 509 "HTMLParser.yy"
                                           {
    Table *t = new Table;
    t->attributes.reset((yystack_[3].value.tag_attributes));
    t->caption.reset((yystack_[2].value.caption));
    t->rows.reset((yystack_[1].value.table_rows));
    (yylhs.value.element) = t;
  }
#line 1028 "HTMLParser.tab.cc"
    break;

  case 48:
#line 519 "HTMLParser.yy"
     { ++drv.list_nesting; }
#line 1034 "HTMLParser.tab.cc"
    break;

  case 49:
#line 519 "HTMLParser.yy"
                                                 {
    OrderedList *ol = new OrderedList;
    ol->attributes.reset((yystack_[3].value.tag_attributes));
    ol->items.reset((yystack_[1].value.list_items));
    ol->nesting = --drv.list_nesting;
    (yylhs.value.element) = ol;
  }
#line 1046 "HTMLParser.tab.cc"
    break;

  case 50:
#line 526 "HTMLParser.yy"
       { ++drv.list_nesting; }
#line 1052 "HTMLParser.tab.cc"
    break;

  case 51:
#line 526 "HTMLParser.yy"
                                                       {
    UnorderedList *ul = new UnorderedList;
    ul->attributes.reset((yystack_[3].value.tag_attributes));
    ul->items.reset((yystack_[1].value.list_items));
    ul->nesting = --drv.list_nesting;
    (yylhs.value.element) = ul;
  }
#line 1064 "HTMLParser.tab.cc"
    break;

  case 52:
#line 533 "HTMLParser.yy"
        { ++drv.list_nesting; }
#line 1070 "HTMLParser.tab.cc"
    break;

  case 53:
#line 533 "HTMLParser.yy"
                                                     {
    Dir *d = new Dir;
    d->attributes.reset((yystack_[3].value.tag_attributes));
    d->items.reset((yystack_[1].value.list_items));
    d->nesting = --drv.list_nesting;
    (yylhs.value.element) = d;
  }
#line 1082 "HTMLParser.tab.cc"
    break;

  case 54:
#line 540 "HTMLParser.yy"
         { ++drv.list_nesting; }
#line 1088 "HTMLParser.tab.cc"
    break;

  case 55:
#line 540 "HTMLParser.yy"
                                                       {
    Menu *m = new Menu;
    m->attributes.reset((yystack_[3].value.tag_attributes));
    m->items.reset((yystack_[1].value.list_items));
    m->nesting = --drv.list_nesting;
    (yylhs.value.element) = m;
  }
#line 1100 "HTMLParser.tab.cc"
    break;

  case 56:
#line 550 "HTMLParser.yy"
              {
    (yylhs.value.list_items) = 0;
  }
#line 1108 "HTMLParser.tab.cc"
    break;

  case 57:
#line 553 "HTMLParser.yy"
                       {
    (yylhs.value.list_items) = (yystack_[1].value.list_items);
  }
#line 1116 "HTMLParser.tab.cc"
    break;

  case 58:
#line 556 "HTMLParser.yy"
                           {
    (yylhs.value.list_items) = (yystack_[1].value.list_items) ? (yystack_[1].value.list_items) : new list<auto_ptr<ListItem> >;
    (yylhs.value.list_items)->push_back(auto_ptr<ListItem>((yystack_[0].value.list_item)));
  }
#line 1125 "HTMLParser.tab.cc"
    break;

  case 59:
#line 563 "HTMLParser.yy"
                         {
    ListNormalItem *lni = new ListNormalItem;
    lni->attributes.reset((yystack_[2].value.tag_attributes));
    lni->flow.reset((yystack_[1].value.element_list));
    (yylhs.value.list_item) = lni;
  }
#line 1136 "HTMLParser.tab.cc"
    break;

  case 60:
#line 569 "HTMLParser.yy"
          {   /* EXTENSION: Handle a "block" in a list as an indented block. */
    ListBlockItem *lbi = new ListBlockItem;
    lbi->block.reset((yystack_[0].value.element));
    (yylhs.value.list_item) = lbi;
  }
#line 1146 "HTMLParser.tab.cc"
    break;

  case 61:
#line 574 "HTMLParser.yy"
          {              /* EXTENSION: Treat "texts" in a list as an "<LI>". */
    ListNormalItem *lni = new ListNormalItem;
    lni->flow.reset((yystack_[0].value.element_list));
    (yylhs.value.list_item) = lni;
  }
#line 1156 "HTMLParser.tab.cc"
    break;

  case 62:
#line 584 "HTMLParser.yy"
                                                   {
    delete (yystack_[4].value.tag_attributes);
    delete (yystack_[3].value.element_list); /* Kludge */
    (yylhs.value.definition_list) = (yystack_[1].value.definition_list);
  }
#line 1166 "HTMLParser.tab.cc"
    break;

  case 63:
#line 590 "HTMLParser.yy"
                                                         {
    DefinitionList *dl = new DefinitionList;
    dl->attributes.reset((yystack_[4].value.tag_attributes));
    dl->preamble.reset((yystack_[3].value.element_list));
    dl->items.reset((yystack_[1].value.definition_list_item_list));
    (yylhs.value.definition_list) = dl;
  }
#line 1178 "HTMLParser.tab.cc"
    break;

  case 64:
#line 600 "HTMLParser.yy"
              {
    (yylhs.value.definition_list_item_list) = 0;
  }
#line 1186 "HTMLParser.tab.cc"
    break;

  case 65:
#line 603 "HTMLParser.yy"
                            {
    (yylhs.value.definition_list_item_list) = (yystack_[0].value.definition_list_item_list);
  }
#line 1194 "HTMLParser.tab.cc"
    break;

  case 66:
#line 606 "HTMLParser.yy"
                                      {
    (yylhs.value.definition_list_item_list) = (yystack_[1].value.definition_list_item_list) ? (yystack_[1].value.definition_list_item_list) : new list<auto_ptr<DefinitionListItem> >;
    (yylhs.value.definition_list_item_list)->push_back(auto_ptr<DefinitionListItem>((yystack_[0].value.term_name)));
  }
#line 1203 "HTMLParser.tab.cc"
    break;

  case 67:
#line 610 "HTMLParser.yy"
                                            {
    (yylhs.value.definition_list_item_list) = (yystack_[1].value.definition_list_item_list) ? (yystack_[1].value.definition_list_item_list) : new list<auto_ptr<DefinitionListItem> >;
    (yylhs.value.definition_list_item_list)->push_back(auto_ptr<DefinitionListItem>((yystack_[0].value.term_definition)));
  }
#line 1212 "HTMLParser.tab.cc"
    break;

  case 68:
#line 617 "HTMLParser.yy"
                        {      /* EXTENSION: Allow "flow" instead of "texts" */
    delete (yystack_[2].value.tag_attributes);
    (yylhs.value.term_name) = new TermName;
    (yylhs.value.term_name)->flow.reset((yystack_[1].value.element_list));
  }
#line 1222 "HTMLParser.tab.cc"
    break;

  case 69:
#line 622 "HTMLParser.yy"
                                       {/* EXTENSION: Ignore <P> after </DT> */
    delete (yystack_[4].value.tag_attributes);
    delete (yystack_[1].value.tag_attributes);
    (yylhs.value.term_name) = new TermName;
    (yylhs.value.term_name)->flow.reset((yystack_[3].value.element_list));
  }
#line 1233 "HTMLParser.tab.cc"
    break;

  case 70:
#line 631 "HTMLParser.yy"
                        {
    delete (yystack_[2].value.tag_attributes);
    (yylhs.value.term_definition) = new TermDefinition;
    (yylhs.value.term_definition)->flow.reset((yystack_[1].value.element_list));
  }
#line 1243 "HTMLParser.tab.cc"
    break;

  case 71:
#line 636 "HTMLParser.yy"
                                       {/* EXTENSION: Ignore <P> after </DD> */
    delete (yystack_[4].value.tag_attributes);
    delete (yystack_[1].value.tag_attributes);
    (yylhs.value.term_definition) = new TermDefinition;
    (yylhs.value.term_definition)->flow.reset((yystack_[3].value.element_list));
  }
#line 1254 "HTMLParser.tab.cc"
    break;

  case 72:
#line 645 "HTMLParser.yy"
        {
    (yylhs.value.element_list) = new list<auto_ptr<Element> >;
    (yylhs.value.element_list)->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 1263 "HTMLParser.tab.cc"
    break;

  case 73:
#line 649 "HTMLParser.yy"
               {
    (yylhs.value.element_list) = (yystack_[1].value.element_list);
  }
#line 1271 "HTMLParser.tab.cc"
    break;

  case 74:
#line 652 "HTMLParser.yy"
               {
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 1279 "HTMLParser.tab.cc"
    break;

  case 75:
#line 658 "HTMLParser.yy"
       {
    (yylhs.value.element) = (yystack_[0].value.element);
  }
#line 1287 "HTMLParser.tab.cc"
    break;

  case 76:
#line 661 "HTMLParser.yy"
            {          /* EXTENSION: Allow headings in "flow", i.e. in lists */
    (yylhs.value.element) = (yystack_[0].value.heading);
  }
#line 1295 "HTMLParser.tab.cc"
    break;

  case 77:
#line 664 "HTMLParser.yy"
          {
    (yylhs.value.element) = (yystack_[0].value.element);
  }
#line 1303 "HTMLParser.tab.cc"
    break;

  case 78:
#line 670 "HTMLParser.yy"
                            {
    (yylhs.value.preformatted) = new Preformatted;
    (yylhs.value.preformatted)->attributes.reset((yystack_[2].value.tag_attributes));
    (yylhs.value.preformatted)->texts.reset((yystack_[1].value.element_list));
  }
#line 1313 "HTMLParser.tab.cc"
    break;

  case 79:
#line 678 "HTMLParser.yy"
                                {
    (yylhs.value.caption) = new Caption;
    (yylhs.value.caption)->attributes.reset((yystack_[2].value.tag_attributes));
    (yylhs.value.caption)->texts.reset((yystack_[1].value.element_list));
  }
#line 1323 "HTMLParser.tab.cc"
    break;

  case 80:
#line 686 "HTMLParser.yy"
              {
    (yylhs.value.table_rows) = new list<auto_ptr<TableRow> >;
  }
#line 1331 "HTMLParser.tab.cc"
    break;

  case 81:
#line 689 "HTMLParser.yy"
                     {
    (yylhs.value.table_rows) = (yystack_[1].value.table_rows);
  }
#line 1339 "HTMLParser.tab.cc"
    break;

  case 82:
#line 692 "HTMLParser.yy"
                                         {
    TableRow *tr = new TableRow;
    tr->attributes.reset((yystack_[2].value.tag_attributes));
    tr->cells.reset((yystack_[1].value.table_cells));
    ((yylhs.value.table_rows) = (yystack_[3].value.table_rows))->push_back(auto_ptr<TableRow>(tr));
  }
#line 1350 "HTMLParser.tab.cc"
    break;

  case 83:
#line 701 "HTMLParser.yy"
              {
    (yylhs.value.table_cells) = new list<auto_ptr<TableCell> >;
  }
#line 1358 "HTMLParser.tab.cc"
    break;

  case 84:
#line 704 "HTMLParser.yy"
                      {
    (yylhs.value.table_cells) = (yystack_[1].value.table_cells);
  }
#line 1366 "HTMLParser.tab.cc"
    break;

  case 85:
#line 707 "HTMLParser.yy"
                                           {
    TableCell *tc = new TableCell;
    tc->attributes.reset((yystack_[2].value.tag_attributes));
    tc->content.reset((yystack_[1].value.element_list));
    ((yylhs.value.table_cells) = (yystack_[3].value.table_cells))->push_back(auto_ptr<TableCell>(tc));
  }
#line 1377 "HTMLParser.tab.cc"
    break;

  case 86:
#line 713 "HTMLParser.yy"
                                                      {
                            /* EXTENSION: Allow "</TD>" in place of "</TH>". */
    TableHeadingCell *thc = new TableHeadingCell;
    thc->attributes.reset((yystack_[3].value.tag_attributes));
    thc->content.reset((yystack_[2].value.element_list));
    ((yylhs.value.table_cells) = (yystack_[4].value.table_cells))->push_back(auto_ptr<TableCell>(thc));
  }
#line 1389 "HTMLParser.tab.cc"
    break;

  case 87:
#line 720 "HTMLParser.yy"
                      {    /* EXTENSION: Ignore <INPUT> between table cells. */
    delete (yystack_[0].value.tag_attributes);
    (yylhs.value.table_cells) = (yystack_[1].value.table_cells);
  }
#line 1398 "HTMLParser.tab.cc"
    break;

  case 88:
#line 727 "HTMLParser.yy"
                                { /* Should be "address_content"... */
    delete (yystack_[2].value.tag_attributes);
    (yylhs.value.address) = new Address;
    (yylhs.value.address)->content.reset((yystack_[1].value.element_list));
  }
#line 1408 "HTMLParser.tab.cc"
    break;

  case 89:
#line 737 "HTMLParser.yy"
       {
    (yylhs.value.element_list) = new list<auto_ptr<Element> >;
    (yylhs.value.element_list)->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 1417 "HTMLParser.tab.cc"
    break;

  case 90:
#line 741 "HTMLParser.yy"
               {
    ((yylhs.value.element_list) = (yystack_[1].value.element_list))->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 1425 "HTMLParser.tab.cc"
    break;

  case 91:
#line 747 "HTMLParser.yy"
                                      { (yylhs.value.element) = (yystack_[1].value.pcdata); }
#line 1431 "HTMLParser.tab.cc"
    break;

  case 92:
#line 748 "HTMLParser.yy"
                                      { (yylhs.value.element) = (yystack_[1].value.element); }
#line 1437 "HTMLParser.tab.cc"
    break;

  case 93:
#line 749 "HTMLParser.yy"
                                      { (yylhs.value.element) = (yystack_[1].value.element); }
#line 1443 "HTMLParser.tab.cc"
    break;

  case 94:
#line 750 "HTMLParser.yy"
                                      { (yylhs.value.element) = (yystack_[1].value.element); }
#line 1449 "HTMLParser.tab.cc"
    break;

  case 95:
#line 751 "HTMLParser.yy"
                                      { (yylhs.value.element) = (yystack_[1].value.element); }
#line 1455 "HTMLParser.tab.cc"
    break;

  case 96:
#line 752 "HTMLParser.yy"
                                      { /* EXTENSION: NS 1.1 / IE 2.0 */
    NoBreak *nb = new NoBreak;
    delete (yystack_[3].value.tag_attributes);
    nb->content.reset((yystack_[2].value.element_list));
    (yylhs.value.element) = nb;
  }
#line 1466 "HTMLParser.tab.cc"
    break;

  case 97:
#line 761 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::TT,     (yystack_[1].value.element_list)); }
#line 1472 "HTMLParser.tab.cc"
    break;

  case 98:
#line 762 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::I,      (yystack_[1].value.element_list)); }
#line 1478 "HTMLParser.tab.cc"
    break;

  case 99:
#line 763 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::B,      (yystack_[1].value.element_list)); }
#line 1484 "HTMLParser.tab.cc"
    break;

  case 100:
#line 764 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::U,      (yystack_[1].value.element_list)); }
#line 1490 "HTMLParser.tab.cc"
    break;

  case 101:
#line 765 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::STRIKE, (yystack_[1].value.element_list)); }
#line 1496 "HTMLParser.tab.cc"
    break;

  case 102:
#line 766 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::BIG,    (yystack_[1].value.element_list)); }
#line 1502 "HTMLParser.tab.cc"
    break;

  case 103:
#line 767 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::SMALL,  (yystack_[1].value.element_list)); }
#line 1508 "HTMLParser.tab.cc"
    break;

  case 104:
#line 768 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::SUB,    (yystack_[1].value.element_list)); }
#line 1514 "HTMLParser.tab.cc"
    break;

  case 105:
#line 769 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Font(token::SUP,    (yystack_[1].value.element_list)); }
#line 1520 "HTMLParser.tab.cc"
    break;

  case 106:
#line 773 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::EM,     (yystack_[1].value.element_list)); }
#line 1526 "HTMLParser.tab.cc"
    break;

  case 107:
#line 774 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::STRONG, (yystack_[1].value.element_list)); }
#line 1532 "HTMLParser.tab.cc"
    break;

  case 108:
#line 775 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::DFN,    (yystack_[1].value.element_list)); }
#line 1538 "HTMLParser.tab.cc"
    break;

  case 109:
#line 776 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::CODE,   (yystack_[1].value.element_list)); }
#line 1544 "HTMLParser.tab.cc"
    break;

  case 110:
#line 777 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::SAMP,   (yystack_[1].value.element_list)); }
#line 1550 "HTMLParser.tab.cc"
    break;

  case 111:
#line 778 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::KBD,    (yystack_[1].value.element_list)); }
#line 1556 "HTMLParser.tab.cc"
    break;

  case 112:
#line 779 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::VAR,    (yystack_[1].value.element_list)); }
#line 1562 "HTMLParser.tab.cc"
    break;

  case 113:
#line 780 "HTMLParser.yy"
                                    { delete (yystack_[2].value.tag_attributes); (yylhs.value.element) = new Phrase(token::CITE,   (yystack_[1].value.element_list)); }
#line 1568 "HTMLParser.tab.cc"
    break;

  case 114:
#line 787 "HTMLParser.yy"
                              {
    delete (yystack_[2].value.tag_attributes);
    Anchor *a = new Anchor;
    a->attributes.reset((yystack_[3].value.tag_attributes));
    a->texts.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = a;
  }
#line 1580 "HTMLParser.tab.cc"
    break;

  case 115:
#line 794 "HTMLParser.yy"
        {
    Image *i = new Image;
    i->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.element) = i;
  }
#line 1590 "HTMLParser.tab.cc"
    break;

  case 116:
#line 799 "HTMLParser.yy"
                                     {
    Applet *a = new Applet;
    a->attributes.reset((yystack_[2].value.tag_attributes));
    a->content.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = a;
  }
#line 1601 "HTMLParser.tab.cc"
    break;

  case 117:
#line 807 "HTMLParser.yy"
                               {
    Font2 *f2 = new Font2;
    f2->attributes.reset((yystack_[2].value.tag_attributes));
    f2->elements.reset((yystack_[1].value.element_list));
    (yylhs.value.element) = f2;
  }
#line 1612 "HTMLParser.tab.cc"
    break;

  case 118:
#line 813 "HTMLParser.yy"
             {
    BaseFont *bf = new BaseFont;
    bf->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.element) = bf;
  }
#line 1622 "HTMLParser.tab.cc"
    break;

  case 119:
#line 818 "HTMLParser.yy"
       {
    LineBreak *lb = new LineBreak;
    lb->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.element) = lb;
  }
#line 1632 "HTMLParser.tab.cc"
    break;

  case 120:
#line 823 "HTMLParser.yy"
                            {
    Map *m = new Map;
    m->attributes.reset((yystack_[2].value.tag_attributes));
    m->areas.reset((yystack_[1].value.tag_attributes_list));
    (yylhs.value.element) = m;
  }
#line 1643 "HTMLParser.tab.cc"
    break;

  case 121:
#line 832 "HTMLParser.yy"
              {
    (yylhs.value.element_list) = 0;
  }
#line 1651 "HTMLParser.tab.cc"
    break;

  case 122:
#line 835 "HTMLParser.yy"
                        {
    (yylhs.value.element_list) = (yystack_[1].value.element_list) ? (yystack_[1].value.element_list) : new list<auto_ptr<Element> >;
    (yylhs.value.element_list)->push_back(auto_ptr<Element>((yystack_[0].value.element)));
  }
#line 1660 "HTMLParser.tab.cc"
    break;

  case 123:
#line 839 "HTMLParser.yy"
                         {
    (yylhs.value.element_list) = (yystack_[1].value.element_list) ? (yystack_[1].value.element_list) : new list<auto_ptr<Element> >;
    Param *p = new Param;
    p->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.element_list)->push_back(auto_ptr<Element>(p));
  }
#line 1671 "HTMLParser.tab.cc"
    break;

  case 124:
#line 848 "HTMLParser.yy"
              {
    (yylhs.value.tag_attributes_list) = 0;
  }
#line 1679 "HTMLParser.tab.cc"
    break;

  case 125:
#line 851 "HTMLParser.yy"
                      {
    (yylhs.value.tag_attributes_list) = (yystack_[1].value.tag_attributes_list);
  }
#line 1687 "HTMLParser.tab.cc"
    break;

  case 126:
#line 854 "HTMLParser.yy"
                     {
    (yylhs.value.tag_attributes_list) = (yystack_[1].value.tag_attributes_list) ? (yystack_[1].value.tag_attributes_list) : new list<auto_ptr<list<TagAttribute> > >;
    (yylhs.value.tag_attributes_list)->push_back(auto_ptr<list<TagAttribute> >((yystack_[0].value.tag_attributes)));
  }
#line 1696 "HTMLParser.tab.cc"
    break;

  case 127:
#line 861 "HTMLParser.yy"
        {
    Input *i = new Input;
    i->attributes.reset((yystack_[0].value.tag_attributes));
    (yylhs.value.element) = i;
  }
#line 1706 "HTMLParser.tab.cc"
    break;

  case 128:
#line 866 "HTMLParser.yy"
                                     {
    Select *s = new Select;
    s->attributes.reset((yystack_[2].value.tag_attributes));
    s->content.reset((yystack_[1].value.option_list));
    (yylhs.value.element) = s;
  }
#line 1717 "HTMLParser.tab.cc"
    break;

  case 129:
#line 872 "HTMLParser.yy"
                                 {
    TextArea *ta = new TextArea;
    ta->attributes.reset((yystack_[2].value.tag_attributes));
    ta->pcdata.reset((yystack_[1].value.pcdata));
    (yylhs.value.element) = ta;
  }
#line 1728 "HTMLParser.tab.cc"
    break;

  case 130:
#line 881 "HTMLParser.yy"
         {
    (yylhs.value.option_list) = new list<auto_ptr<Option> >;
    (yylhs.value.option_list)->push_back(auto_ptr<Option>((yystack_[0].value.option)));
  }
#line 1737 "HTMLParser.tab.cc"
    break;

  case 131:
#line 885 "HTMLParser.yy"
                          {
    ((yylhs.value.option_list) = (yystack_[1].value.option_list))->push_back(auto_ptr<Option>((yystack_[0].value.option)));
  }
#line 1745 "HTMLParser.tab.cc"
    break;

  case 132:
#line 891 "HTMLParser.yy"
                               {
    (yylhs.value.option) = new Option;
    (yylhs.value.option)->attributes.reset((yystack_[2].value.tag_attributes));
    (yylhs.value.option)->pcdata.reset((yystack_[1].value.pcdata));
  }
#line 1755 "HTMLParser.tab.cc"
    break;

  case 133:
#line 901 "HTMLParser.yy"
       { (yylhs.value.heading) = new Heading; (yylhs.value.heading)->level = 1; (yylhs.value.heading)->attributes.reset((yystack_[0].value.tag_attributes)); }
#line 1761 "HTMLParser.tab.cc"
    break;

  case 134:
#line 902 "HTMLParser.yy"
       { (yylhs.value.heading) = new Heading; (yylhs.value.heading)->level = 2; (yylhs.value.heading)->attributes.reset((yystack_[0].value.tag_attributes)); }
#line 1767 "HTMLParser.tab.cc"
    break;

  case 135:
#line 903 "HTMLParser.yy"
       { (yylhs.value.heading) = new Heading; (yylhs.value.heading)->level = 3; (yylhs.value.heading)->attributes.reset((yystack_[0].value.tag_attributes)); }
#line 1773 "HTMLParser.tab.cc"
    break;

  case 136:
#line 904 "HTMLParser.yy"
       { (yylhs.value.heading) = new Heading; (yylhs.value.heading)->level = 4; (yylhs.value.heading)->attributes.reset((yystack_[0].value.tag_attributes)); }
#line 1779 "HTMLParser.tab.cc"
    break;

  case 137:
#line 905 "HTMLParser.yy"
       { (yylhs.value.heading) = new Heading; (yylhs.value.heading)->level = 5; (yylhs.value.heading)->attributes.reset((yystack_[0].value.tag_attributes)); }
#line 1785 "HTMLParser.tab.cc"
    break;

  case 138:
#line 906 "HTMLParser.yy"
       { (yylhs.value.heading) = new Heading; (yylhs.value.heading)->level = 6; (yylhs.value.heading)->attributes.reset((yystack_[0].value.tag_attributes)); }
#line 1791 "HTMLParser.tab.cc"
    break;

  case 139:
#line 910 "HTMLParser.yy"
           { (yylhs.value.inT) = 1; }
#line 1797 "HTMLParser.tab.cc"
    break;

  case 140:
#line 911 "HTMLParser.yy"
           { (yylhs.value.inT) = 2; }
#line 1803 "HTMLParser.tab.cc"
    break;

  case 141:
#line 912 "HTMLParser.yy"
           { (yylhs.value.inT) = 3; }
#line 1809 "HTMLParser.tab.cc"
    break;

  case 142:
#line 913 "HTMLParser.yy"
           { (yylhs.value.inT) = 4; }
#line 1815 "HTMLParser.tab.cc"
    break;

  case 143:
#line 914 "HTMLParser.yy"
           { (yylhs.value.inT) = 5; }
#line 1821 "HTMLParser.tab.cc"
    break;

  case 144:
#line 915 "HTMLParser.yy"
           { (yylhs.value.inT) = 6; }
#line 1827 "HTMLParser.tab.cc"
    break;

  case 145:
#line 920 "HTMLParser.yy"
                            { (yylhs.value.pcdata) = 0; }
#line 1833 "HTMLParser.tab.cc"
    break;

  case 146:
#line 920 "HTMLParser.yy"
                                                  { (yylhs.value.pcdata) = (yystack_[0].value.pcdata); }
#line 1839 "HTMLParser.tab.cc"
    break;

  case 147:
#line 921 "HTMLParser.yy"
                            { (yylhs.value.caption) = 0; }
#line 1845 "HTMLParser.tab.cc"
    break;

  case 148:
#line 921 "HTMLParser.yy"
                                                  { (yylhs.value.caption) = (yystack_[0].value.caption); }
#line 1851 "HTMLParser.tab.cc"
    break;

  case 149:
#line 922 "HTMLParser.yy"
                            { (yylhs.value.element_list) = 0; }
#line 1857 "HTMLParser.tab.cc"
    break;

  case 150:
#line 922 "HTMLParser.yy"
                                                  { (yylhs.value.element_list) = (yystack_[0].value.element_list); }
#line 1863 "HTMLParser.tab.cc"
    break;

  case 151:
#line 923 "HTMLParser.yy"
                            { (yylhs.value.element_list) = 0; }
#line 1869 "HTMLParser.tab.cc"
    break;

  case 152:
#line 923 "HTMLParser.yy"
                                                  { (yylhs.value.element_list) = (yystack_[0].value.element_list); }
#line 1875 "HTMLParser.tab.cc"
    break;

  case 153:
#line 925 "HTMLParser.yy"
                            { (yylhs.value.tag_attributes) = 0; }
#line 1881 "HTMLParser.tab.cc"
    break;

  case 154:
#line 925 "HTMLParser.yy"
                                                  { (yylhs.value.tag_attributes) = (yystack_[0].value.tag_attributes); }
#line 1887 "HTMLParser.tab.cc"
    break;

  case 155:
#line 926 "HTMLParser.yy"
                            { (yylhs.value.tag_attributes) = 0; }
#line 1893 "HTMLParser.tab.cc"
    break;

  case 156:
#line 926 "HTMLParser.yy"
                                                  { (yylhs.value.tag_attributes) = (yystack_[0].value.tag_attributes); }
#line 1899 "HTMLParser.tab.cc"
    break;


#line 1903 "HTMLParser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  HTMLParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  HTMLParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short HTMLParser::yypact_ninf_ = -157;

  const short HTMLParser::yytable_ninf_ = -224;

  const short
  HTMLParser::yypact_[] =
  {
    -157,     9,  1696,  -157,  -157,  -157,  -157,   -13,  2104,  -157,
    2104,  -157,  -157,  2104,  -157,  -157,  -157,  -157,  2104,  2104,
    2104,  -157,  -157,  2034,  2104,  2034,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  2104,  -157,  -157,  -157,
    2104,  -157,  -157,  -157,  -157,  2104,  -157,  -157,  2104,  2104,
    -157,   -22,  2104,  2104,  2104,  -157,  2104,  2104,    17,    28,
      28,  2104,  2104,  -157,  2104,  -157,  -157,  -157,   284,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  2104,  -157,   284,   284,
     284,   284,  -157,  -157,  2034,  2104,   -42,  1963,   -39,   -43,
     415,   546,   -40,   -44,   -37,  -157,   677,  -157,  -157,   808,
    -157,  -157,    16,   -36,   -35,   939,   -54,   -49,    15,  -157,
     -51,  -157,  1070,   -53,   -50,    28,   -31,  -157,   -52,   -55,
     -41,   -45,   -56,  2104,  -157,  -157,   -58,  -157,   -59,   -48,
     -47,  -157,   -46,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    1794,     6,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  2104,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  1893,  -157,  -157,
    -157,  -157,    50,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  1616,   284,  1543,  -157,
    -157,  -157,  2104,  -157,  -157,  -157,  -157,  -157,   -19,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,    12,     3,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    1201,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  2034,  -157,  -157,  -157,  2104,   -11,    -3,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,    -9,  -157,  -157,  2034,  2034,  -157,  -157,  -157,     4,
    -157,  -157,    26,    18,  -157,  -157,  -157,  -157,  -157,  -157,
      33,  -157,    33,  -157,  1455,  1331,  -157,    25,    25,  -157,
    -157,  -157,   -26,  -157,  -157,  -157
  };

  const unsigned char
  HTMLParser::yydefact_[] =
  {
       3,     0,     0,     1,     4,     5,    23,   153,   149,   121,
     149,    12,   118,   149,    24,    17,   119,    24,   149,   149,
     149,    52,    24,   151,   149,   151,    24,   133,   134,   135,
     136,   137,   138,     8,    46,     6,   149,   115,   127,    11,
     149,    14,   124,    54,    13,   149,    48,    35,   149,   149,
      15,     0,   149,   149,   149,    16,   149,   149,   147,     0,
     145,   149,   149,    50,   149,    18,     9,     7,     0,    20,
      21,    33,    39,    41,    40,    22,    19,    89,     0,     0,
       0,     0,    35,   154,   151,   150,     0,     0,   159,   163,
       0,     0,   167,   169,   171,    56,     0,    76,    77,     0,
      72,    75,     0,   177,   179,     0,   183,   185,     0,    56,
       0,    56,     0,   193,   195,     0,     0,   130,   197,   199,
     201,   203,   205,   149,   148,    80,     0,   146,   211,   215,
     217,    56,   221,   224,    91,    90,    92,    93,    94,    95,
       0,   157,    88,   123,   116,   122,   160,    99,   164,   102,
      25,    26,    27,   162,    29,    30,    31,    28,    44,   166,
      43,   168,   113,   170,   109,   172,   108,     0,   174,    42,
      73,    74,    64,   178,   106,   180,   117,   182,    45,   184,
      98,   186,   111,   125,   126,   120,     0,     0,     0,    36,
     192,    38,    37,    34,   194,    78,   196,   110,   189,   128,
     131,   198,   103,   200,   101,   202,   107,   204,   104,   206,
     105,     0,     0,   129,   212,    10,   216,    97,   218,   100,
       0,   222,   112,   139,   140,   141,   142,   143,   144,    32,
     158,   114,    57,   151,    53,    60,    58,    61,   175,     0,
      55,    96,    49,   190,   132,    79,    81,    83,    47,   220,
      51,   187,   176,    62,   151,   151,    63,    66,    67,     0,
     188,    59,     0,     0,    84,    87,    24,    24,   214,    82,
     155,    70,   155,    68,     0,     0,   156,     0,     0,   208,
      85,   210,   207,    71,    69,    86
  };

  const short
  HTMLParser::yypgoto_[] =
  {
    -157,  -157,  -157,   -38,   -15,     8,     1,     5,   -87,  -157,
    -157,  -157,  -157,  -157,   -81,  -157,   -72,  -157,  -157,  -157,
    -157,     2,  -157,  -157,  -157,  -157,   100,    -2,   -17,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,     0,  -157,  -157,  -157,
    -157,    99,   -24,  -157,  -150,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -156,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   -66
  };

  const short
  HTMLParser::yydefgoto_[] =
  {
      -1,     1,     2,    68,    90,    97,    98,   112,    71,    72,
     111,   131,    95,   109,   167,   236,    73,   239,   257,   258,
      99,   100,    74,   124,   212,   259,   156,    85,    77,    78,
      79,    80,    87,   108,    81,   116,   117,    82,   229,   128,
     125,    86,   102,    84,   277,   231,   147,   158,   149,   160,
     162,   164,   166,   169,   253,   174,   176,   178,   180,   182,
     261,   244,   193,   195,   197,   202,   204,   206,   208,   210,
     280,   282,   215,   269,   217,   219,   250,   222,   134
  };

  const short
  HTMLParser::yytable_[] =
  {
      76,   104,    91,    70,   246,   264,   101,    96,   101,     3,
      69,   105,   136,   137,   138,   139,   183,   133,   254,   133,
     115,   126,   127,   255,   184,   191,   133,   133,   186,   115,
     188,    83,     6,   142,   123,   148,   172,  -223,   146,  -223,
     163,  -223,  -223,   161,  -223,   265,  -223,  -223,   179,   165,
     220,  -223,  -223,   191,   181,   173,   187,   175,   194,   135,
     141,   203,   196,   201,   209,   213,   214,   101,   135,   266,
     145,   267,   247,  -213,   207,    23,   205,   198,   252,   216,
     230,   218,   101,   199,   221,   276,   256,   140,   157,   157,
     243,   155,   155,   245,   157,   260,   279,   155,   154,   154,
     238,   171,    75,   157,   154,  -223,   155,  -223,   272,    88,
     192,   270,    89,   154,  -223,  -223,   200,    92,    93,    94,
     185,   241,   278,   103,   248,  -213,   285,     0,     0,     0,
     268,     0,     0,     0,     0,   106,     0,     0,   192,   107,
     135,     0,     0,     0,   110,     0,     0,   113,   114,     0,
       0,   118,   119,   120,     0,   121,   122,     0,     0,     0,
     129,   130,     0,   132,     0,   237,     0,     0,   235,     0,
       0,     0,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,     0,   237,     0,   237,   235,     0,   235,
       0,     0,     0,     0,     0,     0,   271,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,   283,   284,     0,     0,     0,   101,     0,   237,     0,
     135,   235,   211,     0,     0,     0,     0,     0,     0,     0,
     262,   263,     0,     0,     0,     0,     0,   101,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   157,     0,   155,   155,     0,     0,     0,
       0,     0,   154,   154,  -223,   133,     0,  -223,  -223,     0,
    -223,  -223,  -223,     0,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,     0,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,     0,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,     0,
    -223,  -223,  -223,     0,  -223,  -223,  -223,     0,     0,  -223,
    -223,  -223,     0,  -223,  -223,  -223,  -223,     0,  -223,     0,
    -223,  -223,  -223,  -223,  -223,  -161,   150,     0,  -161,     6,
       0,     7,     8,     9,     0,    10,  -161,    12,    13,    14,
    -161,    16,     0,    17,    18,    19,  -161,    20,    21,    22,
      23,  -161,    24,    25,    26,    27,    28,    29,    30,    31,
      32,  -161,    34,  -161,    36,    37,    38,  -161,    40,  -161,
    -161,    42,    43,  -161,    45,    46,     0,    47,  -161,    48,
      49,   151,    51,    52,    53,    54,   152,    56,    57,    58,
    -161,    59,  -161,  -161,  -161,    61,    62,    63,    64,  -161,
    -161,  -161,  -161,  -161,   153,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
       0,  -161,  -161,  -161,     0,  -161,  -161,  -161,     0,     0,
    -161,  -161,  -161,     0,  -161,  -161,  -161,  -161,     0,  -161,
       0,  -161,  -161,  -161,  -161,  -161,  -165,   150,     0,  -165,
       6,     0,     7,     8,     9,     0,    10,  -165,    12,    13,
      14,  -165,    16,     0,    17,    18,    19,  -165,    20,    21,
      22,    23,  -165,    24,    25,    26,    27,    28,    29,    30,
      31,    32,  -165,    34,  -165,    36,    37,    38,  -165,    40,
    -165,  -165,    42,    43,  -165,    45,    46,     0,    47,  -165,
      48,    49,   151,    51,    52,    53,    54,   152,    56,    57,
      58,  -165,    59,  -165,  -165,  -165,    61,    62,    63,    64,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,   159,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,     0,  -165,  -165,  -165,     0,  -165,  -165,  -165,     0,
       0,  -165,  -165,  -165,     0,  -165,  -165,  -165,  -165,     0,
    -165,     0,  -165,  -165,  -165,  -165,  -165,  -173,   150,     0,
    -173,     6,     0,     7,     8,     9,     0,    10,  -173,    12,
      13,    14,  -173,    16,     0,    17,    18,    19,  -173,    20,
      21,    22,    23,  -173,    24,    25,    26,    27,    28,    29,
      30,    31,    32,  -173,    34,  -173,    36,    37,    38,  -173,
      40,  -173,  -173,    42,    43,  -173,    45,    46,     0,    47,
    -173,    48,    49,   151,    51,    52,    53,    54,   152,    56,
      57,    58,  -173,    59,  -173,  -173,  -173,    61,    62,    63,
      64,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,   168,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,     0,  -173,  -173,  -173,     0,  -173,  -173,  -173,
       0,     0,  -173,  -173,  -173,     0,  -173,  -173,  -173,  -173,
       0,  -173,     0,  -173,  -173,  -173,  -173,  -173,  -152,   170,
       0,  -152,     6,     0,     7,  -152,     9,     0,    10,  -152,
      12,    13,    14,  -152,    16,     0,    17,    18,    19,  -152,
      20,    21,    22,    23,  -152,    24,    25,    26,    27,    28,
      29,    30,    31,    32,  -152,    34,  -152,    36,    37,    38,
    -152,    40,  -152,  -152,    42,    43,  -152,    45,    46,     0,
      47,  -152,    48,    49,  -152,    51,    52,    53,    54,  -152,
      56,    57,    58,  -152,    59,  -152,  -152,  -152,    61,    62,
      63,    64,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,     0,  -152,  -152,  -152,     0,  -152,  -152,
    -152,     0,     0,  -152,  -152,  -152,     0,  -152,  -152,  -152,
    -152,     0,  -152,     0,  -152,  -152,  -152,  -152,  -152,  -181,
     150,     0,  -181,     6,     0,     7,     8,     9,     0,    10,
    -181,    12,    13,    14,  -181,    16,     0,    17,    18,    19,
    -181,    20,    21,    22,    23,  -181,    24,    25,    26,    27,
      28,    29,    30,    31,    32,  -181,    34,  -181,    36,    37,
      38,  -181,    40,  -181,  -181,    42,    43,  -181,    45,    46,
       0,    47,  -181,    48,    49,   151,    51,    52,    53,    54,
     152,    56,    57,    58,  -181,    59,  -181,  -181,  -181,    61,
      62,    63,    64,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,   177,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,     0,  -181,  -181,  -181,     0,  -181,
    -181,  -181,     0,     0,  -181,  -181,  -181,     0,  -181,  -181,
    -181,  -181,     0,  -181,     0,  -181,  -181,  -181,  -181,  -181,
    -191,   189,     0,  -191,     6,     0,     7,  -191,     9,     0,
      10,  -191,    12,    13,    14,  -191,    16,     0,    17,    18,
      19,  -191,    20,    21,    22,    23,  -191,    24,    25,    26,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,    34,  -191,    36,
      37,    38,  -191,    40,  -191,  -191,    42,    43,  -191,    45,
      46,     0,  -191,  -191,    48,    49,  -191,    51,    52,    53,
      54,  -191,    56,    57,    58,  -191,    59,  -191,  -191,  -191,
      61,    62,    63,    64,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,     0,  -191,  -191,  -191,     0,
     190,  -191,  -191,     0,     0,  -191,  -191,  -191,     0,  -191,
    -191,  -191,  -191,     0,  -191,     0,  -191,  -191,  -191,  -191,
    -191,  -219,   232,     0,  -219,     6,     0,     7,  -219,     9,
       0,    10,  -219,    12,    13,    14,  -219,    16,     0,    17,
      18,    19,  -219,    20,    21,    22,    23,  -219,    24,    25,
      26,  -219,  -219,  -219,  -219,  -219,  -219,  -219,    34,  -219,
      36,    37,    38,  -219,    40,   233,  -219,    42,    43,  -219,
      45,    46,     0,    47,  -219,    48,    49,  -219,    51,    52,
      53,    54,  -219,    56,    57,    58,  -219,    59,  -219,  -219,
    -219,    61,    62,    63,    64,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,     0,  -219,  -219,  -219,
       0,  -219,  -219,  -219,     0,     0,  -219,  -219,  -219,     0,
    -219,  -219,  -219,  -219,     0,  -219,     0,  -219,  -219,  -219,
     249,  -219,   150,     0,     0,     6,     0,     7,     8,     9,
       0,    10,     0,    12,    13,    14,     0,    16,     0,    17,
      18,    19,     0,    20,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,    34,     0,
      36,    37,    38,     0,    40,     0,     0,    42,    43,     0,
      45,    46,     0,    47,     0,    48,    49,   151,    51,    52,
      53,    54,   152,    56,    57,    58,  -209,    59,  -209,     0,
    -209,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -209,  -209,     0,   281,   150,  -209,     0,     6,
       0,     7,     8,     9,     0,    10,     0,    12,    13,    14,
       0,    16,     0,    17,    18,    19,     0,    20,    21,    22,
      23,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,    34,     0,    36,    37,    38,     0,    40,     0,
       0,    42,    43,     0,    45,    46,     0,    47,     0,    48,
      49,   151,    51,    52,    53,    54,   152,    56,    57,    58,
    -207,    59,  -207,     0,  -207,    61,    62,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,     6,     0,     7,
       0,     9,     0,    10,     0,    12,    13,    14,     0,    16,
       0,    17,    18,    19,     0,    20,    21,    22,    23,     0,
      24,    25,    26,     0,     0,     0,  -207,   279,     0,     0,
      34,  -207,    36,    37,    38,     0,    40,   233,     0,    42,
      43,     0,    45,    46,     0,    47,     0,    48,    49,     0,
      51,    52,    53,    54,     0,    56,    57,    58,     0,    59,
       0,     0,     0,    61,    62,    63,    64,   232,     0,     0,
       6,     0,     7,     0,     9,     0,    10,     0,    12,    13,
      14,     0,    16,     0,    17,    18,    19,     0,    20,    21,
      22,    23,     0,    24,    25,    26,     0,     0,     0,     0,
       0,   242,     0,    34,     0,    36,    37,    38,     0,    40,
     233,     0,    42,    43,     0,    45,    46,     0,    47,     0,
      48,    49,     0,    51,    52,    53,    54,     0,    56,    57,
      58,     0,    59,     0,     0,     0,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,    -2,     4,     0,     5,
       6,     0,     7,     8,     9,     0,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,    19,     0,    20,    21,
      22,    23,   240,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,     0,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,     0,    60,     0,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,    66,    67,     6,     0,
       7,     0,     9,     0,    10,     0,    12,    13,    14,     0,
      16,     0,    17,    18,    19,     0,    20,    21,    22,    23,
       0,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    36,    37,    38,     0,    40,     0,     0,
      42,    43,     0,    45,    46,     0,     0,     0,    48,    49,
       0,    51,    52,    53,    54,     0,    56,    57,    58,     0,
      59,     0,     0,     0,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   223,   224,
     225,   226,   227,   228,   232,     0,     0,     6,     0,     7,
       0,     9,     0,    10,     0,    12,    13,    14,     0,    16,
       0,    17,    18,    19,     0,    20,    21,    22,    23,     0,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
      34,     0,    36,    37,    38,     0,    40,   233,     0,    42,
      43,     0,    45,    46,     0,    47,     0,    48,    49,     0,
      51,    52,    53,    54,     0,    56,    57,    58,     0,    59,
       0,     0,     0,    61,    62,    63,    64,     6,     0,     7,
       0,     9,     0,    10,     0,    12,    13,     0,     0,    16,
     234,     0,    18,    19,     0,    20,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,    40,     0,     0,    42,
       0,     0,    45,     0,     0,     0,   143,     0,    49,     0,
      51,    52,    53,    54,     0,    56,    57,     0,     0,    59,
       0,     0,     0,    61,    62,     0,    64,     0,     6,   144,
       7,     0,     9,     0,    10,     0,    12,    13,    14,     0,
      16,     0,    17,    18,    19,     0,    20,    21,    22,    23,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    34,     0,    36,    37,    38,     0,    40,     0,     0,
      42,    43,     0,    45,    46,     0,    47,     0,    48,    49,
       0,    51,    52,    53,    54,     0,    56,    57,    58,     0,
      59,     0,     0,     0,    61,    62,    63,    64,     6,     0,
       7,     0,     9,     0,    10,     0,    12,    13,     0,     0,
      16,     0,     0,    18,    19,     0,    20,     0,     0,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,    40,     0,     0,
      42,     0,     0,    45,     0,     0,     0,     0,     0,    49,
       0,    51,    52,    53,    54,     0,    56,    57,     0,     0,
      59,     0,     0,     0,    61,    62,     0,    64
  };

  const short
  HTMLParser::yycheck_[] =
  {
       2,    25,    17,     2,     1,     1,    23,    22,    25,     0,
       2,    26,    78,    79,    80,    81,     1,     1,    21,     1,
      51,    59,    60,    26,     9,   112,     1,     1,   109,    51,
     111,    44,     4,    75,    17,    78,   102,    21,    77,    21,
      84,    25,    26,    83,    26,    41,    21,    21,   102,    86,
     131,    26,    26,   140,   103,    91,   107,    92,   111,    76,
      84,   116,   112,   115,   120,   123,   125,    84,    85,    65,
      87,    67,    69,    69,   119,    25,   117,   115,    89,   127,
      74,   128,    99,   114,   130,    52,    89,    82,    90,    91,
     109,    90,    91,    81,    96,   104,   122,    96,    90,    91,
     172,    99,     2,   105,    96,    89,   105,    89,    90,    10,
     112,    85,    13,   105,    89,    89,   116,    18,    19,    20,
     105,   187,   272,    24,   121,   121,   282,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    36,    -1,    -1,   140,    40,
     157,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,
      -1,    52,    53,    54,    -1,    56,    57,    -1,    -1,    -1,
      61,    62,    -1,    64,    -1,   167,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,    -1,   188,   186,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,
      -1,   277,   278,    -1,    -1,    -1,   233,    -1,   220,    -1,
     237,   220,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   275,    -1,   274,   275,    -1,    -1,    -1,
      -1,    -1,   274,   275,     0,     1,    -1,     3,     4,    -1,
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
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,   106,   107,   108,    -1,
     110,   111,   112,    -1,    -1,   115,   116,   117,    -1,   119,
     120,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
      -1,   110,   111,   112,    -1,    -1,   115,   116,   117,    -1,
     119,   120,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,     1,    -1,    -1,     4,    -1,     6,     7,     8,
      -1,    10,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    -1,
      39,    40,    41,    -1,    43,    -1,    -1,    46,    47,    -1,
      49,    50,    -1,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,    -1,   124,     1,   126,    -1,     4,
      -1,     6,     7,     8,    -1,    10,    -1,    12,    13,    14,
      -1,    16,    -1,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    -1,    39,    40,    41,    -1,    43,    -1,
      -1,    46,    47,    -1,    49,    50,    -1,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    -1,   121,   122,    -1,    -1,
      37,   126,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    -1,    49,    50,    -1,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    66,
      -1,    -1,    -1,    70,    71,    72,    73,     1,    -1,    -1,
       4,    -1,     6,    -1,     8,    -1,    10,    -1,    12,    13,
      14,    -1,    16,    -1,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    37,    -1,    39,    40,    41,    -1,    43,
      44,    -1,    46,    47,    -1,    49,    50,    -1,    52,    -1,
      54,    55,    -1,    57,    58,    59,    60,    -1,    62,    63,
      64,    -1,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    -1,    22,    23,
      24,    25,   106,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    48,    49,    50,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    -1,    68,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,   100,   101,     4,    -1,
       6,    -1,     8,    -1,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    40,    41,    -1,    43,    -1,    -1,
      46,    47,    -1,    49,    50,    -1,    -1,    -1,    54,    55,
      -1,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,     1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    -1,    43,    44,    -1,    46,
      47,    -1,    49,    50,    -1,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    66,
      -1,    -1,    -1,    70,    71,    72,    73,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    12,    13,    -1,    -1,    16,
      87,    -1,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    43,    -1,    -1,    46,
      -1,    -1,    49,    -1,    -1,    -1,    53,    -1,    55,    -1,
      57,    58,    59,    60,    -1,    62,    63,    -1,    -1,    66,
      -1,    -1,    -1,    70,    71,    -1,    73,    -1,     4,    76,
       6,    -1,     8,    -1,    10,    -1,    12,    13,    14,    -1,
      16,    -1,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    -1,    39,    40,    41,    -1,    43,    -1,    -1,
      46,    47,    -1,    49,    50,    -1,    52,    -1,    54,    55,
      -1,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      66,    -1,    -1,    -1,    70,    71,    72,    73,     4,    -1,
       6,    -1,     8,    -1,    10,    -1,    12,    13,    -1,    -1,
      16,    -1,    -1,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    -1,    43,    -1,    -1,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    57,    58,    59,    60,    -1,    62,    63,    -1,    -1,
      66,    -1,    -1,    -1,    70,    71,    -1,    73
  };

  const unsigned char
  HTMLParser::yystos_[] =
  {
       0,   132,   133,     0,     1,     3,     4,     6,     7,     8,
      10,    11,    12,    13,    14,    15,    16,    18,    19,    20,
      22,    23,    24,    25,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    45,    46,    47,    48,    49,    50,    52,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    66,
      68,    70,    71,    72,    73,    80,   100,   101,   134,   136,
     137,   139,   140,   147,   153,   157,   158,   159,   160,   161,
     162,   165,   168,    44,   174,   158,   172,   163,   172,   172,
     135,   135,   172,   172,   172,   143,   135,   136,   137,   151,
     152,   159,   173,   172,   173,   135,   172,   172,   164,   144,
     172,   141,   138,   172,   172,    51,   166,   167,   172,   172,
     172,   172,   172,    17,   154,   171,   134,   134,   170,   172,
     172,   142,   172,     1,   209,   159,   209,   209,   209,   209,
     138,   173,    75,    53,    76,   159,    77,   177,    78,   179,
       1,    56,    61,    79,   136,   137,   157,   158,   178,    82,
     180,    83,   181,    84,   182,    86,   183,   145,    88,   184,
       1,   152,   209,    91,   186,    92,   187,    93,   188,   102,
     189,   103,   190,     1,     9,   105,   145,   107,   145,     1,
     110,   139,   158,   193,   111,   194,   112,   195,   134,   114,
     167,   115,   196,   116,   197,   117,   198,   119,   199,   120,
     200,   172,   155,   123,   125,   203,   127,   205,   128,   206,
     145,   130,   208,    94,    95,    96,    97,    98,    99,   169,
      74,   176,     1,    44,    87,   137,   146,   158,   147,   148,
     106,   209,   108,   109,   192,    81,     1,    69,   121,   129,
     207,   173,    89,   185,    21,    26,    89,   149,   150,   156,
     104,   191,   173,   173,     1,    41,    65,    67,   126,   204,
      85,   209,    90,   209,   135,   135,    52,   175,   175,   122,
     201,   124,   202,   209,   209,   201
  };

  const unsigned char
  HTMLParser::yyr1_[] =
  {
       0,   131,   132,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   136,   137,   137,   138,   138,   138,   138,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   141,   140,
     142,   140,   143,   140,   144,   140,   145,   145,   145,   146,
     146,   146,   147,   147,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   151,   152,   152,   152,   153,   154,
     155,   155,   155,   156,   156,   156,   156,   156,   157,   158,
     158,   159,   159,   159,   159,   159,   159,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   162,
     162,   163,   163,   163,   164,   164,   164,   165,   165,   165,
     166,   166,   167,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   169,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   175,   175,   176,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     182,   183,   183,   184,   184,   185,   185,   186,   186,   187,
     187,   188,   188,   189,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   208,   208,   209,   209
  };

  const signed char
  HTMLParser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       4,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     0,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     3,     0,     2,     2,     2,     1,
       1,     1,     3,     3,     3,     3,     1,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     2,     2,     3,
       1,     1,     5,     5,     0,     1,     2,     2,     3,     5,
       3,     5,     1,     2,     2,     1,     1,     1,     3,     3,
       0,     2,     4,     0,     2,     4,     5,     2,     3,     1,
       2,     2,     2,     2,     2,     2,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     1,     3,     3,     1,     1,
       3,     0,     2,     2,     0,     2,     2,     1,     3,     3,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const HTMLParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "DOCTYPE", "PCDATA",
  "SCAN_ERROR", "A", "ADDRESS", "APPLET", "AREA", "B", "BASE", "BASEFONT",
  "BIG", "BLOCKQUOTE", "BODY", "BR", "CAPTION", "CENTER", "CITE", "CODE",
  "DD", "DFN", "DIR", "DIV", "DL", "DT", "EM", "FONT", "FORM", "H1", "H2",
  "H3", "H4", "H5", "H6", "HEAD", "HR", "HTML", "I", "IMG", "INPUT",
  "ISINDEX", "KBD", "LI", "LINK", "MAP", "MENU", "META", "NOBR", "OL",
  "OPTION", "P", "PARAM", "PRE", "SAMP", "SCRIPT", "SELECT", "SMALL",
  "STRIKE", "STRONG", "STYLE", "SUB", "SUP", "TABLE", "TD", "TEXTAREA",
  "TH", "TITLE", "TR", "TT", "U", "UL", "VAR", "END_A", "END_ADDRESS",
  "END_APPLET", "END_B", "END_BIG", "END_BLOCKQUOTE", "END_BODY",
  "END_CAPTION", "END_CENTER", "END_CITE", "END_CODE", "END_DD", "END_DFN",
  "END_DIR", "END_DIV", "END_DL", "END_DT", "END_EM", "END_FONT",
  "END_FORM", "END_H1", "END_H2", "END_H3", "END_H4", "END_H5", "END_H6",
  "END_HEAD", "END_HTML", "END_I", "END_KBD", "END_LI", "END_MAP",
  "END_MENU", "END_NOBR", "END_OL", "END_OPTION", "END_P", "END_PRE",
  "END_SAMP", "END_SCRIPT", "END_SELECT", "END_SMALL", "END_STRIKE",
  "END_STRONG", "END_STYLE", "END_SUB", "END_SUP", "END_TABLE", "END_TD",
  "END_TEXTAREA", "END_TH", "END_TITLE", "END_TR", "END_TT", "END_U",
  "END_UL", "END_VAR", "$accept", "document", "document_", "pcdata",
  "body_content", "heading", "block", "paragraph_content",
  "block_except_p", "list", "$@1", "$@2", "$@3", "$@4", "list_content",
  "list_item", "definition_list", "definition_list_content", "term_name",
  "term_definition", "flow", "flow_", "preformatted", "caption",
  "table_rows", "table_cells", "address", "texts", "text", "font",
  "phrase", "special", "applet_content", "map_content", "form",
  "select_content", "option", "HX", "END_HX", "opt_pcdata", "opt_caption",
  "opt_texts", "opt_flow", "opt_LI", "opt_P", "opt_END_A", "opt_END_B",
  "opt_END_BLOCKQUOTE", "opt_END_BIG", "opt_END_CENTER", "opt_END_CITE",
  "opt_END_CODE", "opt_END_DFN", "opt_END_DIV", "opt_END_DL", "opt_END_EM",
  "opt_END_FONT", "opt_END_FORM", "opt_END_I", "opt_END_KBD", "opt_END_LI",
  "opt_END_OPTION", "opt_END_P", "opt_END_PRE", "opt_END_SAMP",
  "opt_END_SMALL", "opt_END_STRIKE", "opt_END_STRONG", "opt_END_SUB",
  "opt_END_SUP", "opt_END_TD", "opt_END_TH", "opt_END_TITLE", "opt_END_TR",
  "opt_END_TT", "opt_END_U", "opt_END_UL", "opt_END_VAR", "opt_error", YY_NULLPTR
  };

#if YYDEBUG
  const short
  HTMLParser::yyrline_[] =
  {
       0,   273,   273,   304,   308,   311,   314,   318,   321,   325,
     328,   332,   335,   338,   341,   344,   352,   360,   364,   367,
     372,   375,   378,   384,   392,   395,   398,   406,   414,   419,
     422,   425,   431,   442,   445,   454,   457,   460,   465,   471,
     474,   477,   480,   486,   492,   498,   504,   509,   519,   519,
     526,   526,   533,   533,   540,   540,   550,   553,   556,   563,
     569,   574,   584,   590,   600,   603,   606,   610,   617,   622,
     631,   636,   645,   649,   652,   658,   661,   664,   670,   678,
     686,   689,   692,   701,   704,   707,   713,   720,   727,   737,
     741,   747,   748,   749,   750,   751,   752,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   773,   774,   775,   776,
     777,   778,   779,   780,   787,   794,   799,   807,   813,   818,
     823,   832,   835,   839,   848,   851,   854,   861,   866,   872,
     881,   885,   891,   901,   902,   903,   904,   905,   906,   910,
     911,   912,   913,   914,   915,   920,   920,   921,   921,   922,
     922,   923,   923,   925,   925,   926,   926,   928,   928,   929,
     929,   930,   930,   931,   931,   932,   932,   933,   933,   934,
     934,   935,   935,   936,   936,   937,   937,   938,   938,   939,
     939,   940,   940,   941,   941,   942,   942,   943,   943,   944,
     944,   945,   945,   946,   946,   947,   947,   948,   948,   949,
     949,   950,   950,   951,   951,   952,   952,   953,   953,   954,
     954,   955,   955,   956,   956,   957,   957,   958,   958,   959,
     959,   960,   960,   962,   962
  };

  // Print the state stack on the debug stream.
  void
  HTMLParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  HTMLParser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  HTMLParser::token_number_type
  HTMLParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130
    };
    const int user_token_number_max_ = 385;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 40 "HTMLParser.yy"
} // html2text
#line 2966 "HTMLParser.tab.cc"

#line 964 "HTMLParser.yy"
 /* } */

void
html2text::HTMLParser::error(const std::string& msg)
{
	yyerror(msg.c_str());
}

