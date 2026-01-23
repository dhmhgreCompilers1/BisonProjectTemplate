// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 3 "grammar.y"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ConcreteNode.h"
#include "grammar.tab.h"
extern int yylex(yy::parser::semantic_type *yylval, yy::parser::location_type* loc);
void yyerror(const char *s);

#line 51 "grammar.tab.cpp"


#include "grammar.tab.h"




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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 148 "grammar.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 28 "grammar.y"
{
// Filename for locations here
yyla.location.begin.filename = yyla.location.end.filename = new std::string("test.txt");
}

#line 492 "grammar.tab.cpp"


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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // compilation_unit: declarations statements
#line 61 "grammar.y"
                                          { STNode::mg_root= (yylhs.value.node) = new CompilationUnit((yystack_[1].value.node),(yystack_[0].value.node)); }
#line 630 "grammar.tab.cpp"
    break;

  case 3: // compilation_unit: statements
#line 62 "grammar.y"
                                     { STNode::mg_root= (yylhs.value.node) = new CompilationUnit((yystack_[0].value.node)); }
#line 636 "grammar.tab.cpp"
    break;

  case 4: // compilation_unit: declarations
#line 63 "grammar.y"
                                       { STNode::mg_root= (yylhs.value.node) = new CompilationUnit((yystack_[0].value.node)); }
#line 642 "grammar.tab.cpp"
    break;

  case 5: // declarations: declaration
#line 66 "grammar.y"
                                { (yylhs.value.node) = new Declarations((yystack_[0].value.node)); }
#line 648 "grammar.tab.cpp"
    break;

  case 6: // declarations: declarations declaration
#line 67 "grammar.y"
                                                   { (yylhs.value.node) = new Declarations((yystack_[1].value.node),(yystack_[0].value.node)); }
#line 654 "grammar.tab.cpp"
    break;

  case 7: // statements: statement
#line 70 "grammar.y"
                      { (yylhs.value.node) = new Statements((yystack_[0].value.node)); }
#line 660 "grammar.tab.cpp"
    break;

  case 8: // statements: statements statement
#line 71 "grammar.y"
                                               { (yylhs.value.node) = new Statements((yystack_[1].value.node),(yystack_[0].value.node)); }
#line 666 "grammar.tab.cpp"
    break;

  case 9: // declaration: function_definition
#line 74 "grammar.y"
                                 { (yylhs.value.node) = new Declaration((yystack_[0].value.node)); }
#line 672 "grammar.tab.cpp"
    break;

  case 10: // declaration: variable_declaration
#line 75 "grammar.y"
                                               { (yylhs.value.node) = new Declaration((yystack_[0].value.node)); }
#line 678 "grammar.tab.cpp"
    break;

  case 11: // function_definition: type_specifier IDENTIFIER '(' param_list ')' compound_statement
#line 78 "grammar.y"
                                                                                          { (yylhs.value.node) = new FunctionDefinition((yystack_[5].value.node),(yystack_[4].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 684 "grammar.tab.cpp"
    break;

  case 12: // function_definition: type_specifier IDENTIFIER '(' ')' compound_statement
#line 79 "grammar.y"
                                                                { (yylhs.value.node) = new FunctionDefinition((yystack_[4].value.node),(yystack_[3].value.node),(yystack_[0].value.node)); }
#line 690 "grammar.tab.cpp"
    break;

  case 13: // param_list: IDENTIFIER
#line 82 "grammar.y"
                        { (yylhs.value.node) = new ParamList((yystack_[0].value.node)); }
#line 696 "grammar.tab.cpp"
    break;

  case 14: // param_list: param_list ',' IDENTIFIER
#line 83 "grammar.y"
                                                        { (yylhs.value.node) = new ParamList((yystack_[2].value.node),(yystack_[0].value.node)); }
#line 702 "grammar.tab.cpp"
    break;

  case 15: // variable_declaration: type_specifier declarators SEMICOLON
#line 87 "grammar.y"
                                                                { (yylhs.value.node) = new VariableDeclaration((yystack_[2].value.node),(yystack_[1].value.node)); }
#line 708 "grammar.tab.cpp"
    break;

  case 16: // type_specifier: INT
#line 90 "grammar.y"
                 { (yylhs.value.node) = (yystack_[0].value.node); }
#line 714 "grammar.tab.cpp"
    break;

  case 17: // type_specifier: FLOAT
#line 91 "grammar.y"
          { (yylhs.value.node) = (yystack_[0].value.node); }
#line 720 "grammar.tab.cpp"
    break;

  case 18: // type_specifier: VOID
#line 92 "grammar.y"
          { (yylhs.value.node) = (yystack_[0].value.node); }
#line 726 "grammar.tab.cpp"
    break;

  case 19: // type_specifier: CHAR
#line 93 "grammar.y"
          { (yylhs.value.node) = (yystack_[0].value.node); }
#line 732 "grammar.tab.cpp"
    break;

  case 20: // declarators: direct_declarator
#line 96 "grammar.y"
                                         { (yylhs.value.node) = new Declarators((yystack_[0].value.node)); }
#line 738 "grammar.tab.cpp"
    break;

  case 21: // declarators: direct_declarator '=' expression
#line 97 "grammar.y"
                                                { (yylhs.value.node) = new Declarators((yystack_[2].value.node),(yystack_[0].value.node)); }
#line 744 "grammar.tab.cpp"
    break;

  case 22: // declarators: declarators ',' direct_declarator
#line 98 "grammar.y"
                                                 { (yylhs.value.node) = new Declarators((yystack_[2].value.node),(yystack_[0].value.node)); }
#line 750 "grammar.tab.cpp"
    break;

  case 23: // declarators: declarators ',' direct_declarator '=' expression
#line 99 "grammar.y"
                                                                { (yylhs.value.node) = new Declarators((yystack_[4].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 756 "grammar.tab.cpp"
    break;

  case 24: // direct_declarator: IDENTIFIER
#line 102 "grammar.y"
                                { (yylhs.value.node) = new DirectDeclarator((yystack_[0].value.node)); }
#line 762 "grammar.tab.cpp"
    break;

  case 25: // direct_declarator: direct_declarator '[' ']'
#line 103 "grammar.y"
                                                              { (yylhs.value.node) = new DirectDeclarator((yystack_[2].value.node)); }
#line 768 "grammar.tab.cpp"
    break;

  case 26: // statement: expression_statement
#line 106 "grammar.y"
                                 { (yylhs.value.node) = new ExpressionStatement((yystack_[0].value.node)); }
#line 774 "grammar.tab.cpp"
    break;

  case 27: // statement: compound_statement
#line 107 "grammar.y"
                                        { (yylhs.value.node) = new CompoundStatement((yystack_[0].value.node)); }
#line 780 "grammar.tab.cpp"
    break;

  case 28: // statement: iteration_statement
#line 108 "grammar.y"
                    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 786 "grammar.tab.cpp"
    break;

  case 29: // statement: selection_statement
#line 109 "grammar.y"
                    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 792 "grammar.tab.cpp"
    break;

  case 30: // statement: jump_statement
#line 110 "grammar.y"
                    { (yylhs.value.node) = (yystack_[0].value.node); }
#line 798 "grammar.tab.cpp"
    break;

  case 31: // expression_statement: expression SEMICOLON
#line 112 "grammar.y"
                                                { (yylhs.value.node) = new ExpressionStatement((yystack_[1].value.node)); }
#line 804 "grammar.tab.cpp"
    break;

  case 32: // expression_statement: SEMICOLON
#line 113 "grammar.y"
                                                                                { (yylhs.value.node) = new EmptyStatement(); }
#line 810 "grammar.tab.cpp"
    break;

  case 33: // compound_statement: '{' statements '}'
#line 116 "grammar.y"
                                        { (yylhs.value.node) = new CompoundStatement((yystack_[1].value.node)); }
#line 816 "grammar.tab.cpp"
    break;

  case 34: // compound_statement: '{' '}'
#line 117 "grammar.y"
                                                                        { (yylhs.value.node) = new CompoundStatement(); }
#line 822 "grammar.tab.cpp"
    break;

  case 35: // iteration_statement: WHILE '(' expression ')' statement
#line 120 "grammar.y"
                                                         { (yylhs.value.node) = new WhileLoop((yystack_[2].value.node),(yystack_[0].value.node)); }
#line 828 "grammar.tab.cpp"
    break;

  case 36: // iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement
#line 121 "grammar.y"
                                                                                                                      { (yylhs.value.node) = new ForLoop((yystack_[4].value.node),(yystack_[3].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 834 "grammar.tab.cpp"
    break;

  case 37: // iteration_statement: FOR '(' expression_statement expression_statement ')' statement
#line 122 "grammar.y"
                                                                                                          { (yylhs.value.node) = new ForLoop((yystack_[3].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 840 "grammar.tab.cpp"
    break;

  case 38: // iteration_statement: DO statement WHILE '(' expression ')' SEMICOLON
#line 123 "grammar.y"
                                                                                          { (yylhs.value.node) = new DoWhileLoop((yystack_[5].value.node),(yystack_[2].value.node)); }
#line 846 "grammar.tab.cpp"
    break;

  case 39: // selection_statement: IF '(' expression ')' statement ELSE statement
#line 126 "grammar.y"
                                                                        { (yylhs.value.node) = new IfElseStatement((yystack_[4].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 852 "grammar.tab.cpp"
    break;

  case 40: // selection_statement: IF '(' expression ')' statement
#line 127 "grammar.y"
                                                                                                    { (yylhs.value.node) = new IfStatement((yystack_[2].value.node),(yystack_[0].value.node)); }
#line 858 "grammar.tab.cpp"
    break;

  case 41: // jump_statement: RETURN expression SEMICOLON
#line 129 "grammar.y"
                                             { (yylhs.value.node) = new ReturnStatement((yystack_[1].value.node)); }
#line 864 "grammar.tab.cpp"
    break;

  case 42: // jump_statement: RETURN SEMICOLON
#line 130 "grammar.y"
                                              { (yylhs.value.node) = new ReturnStatement(); }
#line 870 "grammar.tab.cpp"
    break;

  case 43: // jump_statement: BREAK SEMICOLON
#line 131 "grammar.y"
                                             { (yylhs.value.node) = new BreakStatement(); }
#line 876 "grammar.tab.cpp"
    break;

  case 44: // jump_statement: CONTINUE SEMICOLON
#line 132 "grammar.y"
                                                { (yylhs.value.node) = new ContinueStatement(); }
#line 882 "grammar.tab.cpp"
    break;

  case 45: // expression: NUMBER
#line 136 "grammar.y"
                                                                { (yylhs.value.node) = (yystack_[0].value.node); }
#line 888 "grammar.tab.cpp"
    break;

  case 46: // expression: IDENTIFIER
#line 137 "grammar.y"
                                                                { (yylhs.value.node) = (yystack_[0].value.node); }
#line 894 "grammar.tab.cpp"
    break;

  case 47: // expression: '(' expression ')'
#line 138 "grammar.y"
                                                        { (yylhs.value.node) = (yystack_[1].value.node); }
#line 900 "grammar.tab.cpp"
    break;

  case 48: // expression: IDENTIFIER '(' ')'
#line 139 "grammar.y"
                                                        { (yylhs.value.node) = new BuiltInFunctionCall((yystack_[2].value.node)); }
#line 906 "grammar.tab.cpp"
    break;

  case 49: // expression: IDENTIFIER '(' args ')'
#line 140 "grammar.y"
                                                        { (yylhs.value.node) = new BuiltInFunctionCall((yystack_[3].value.node),(yystack_[1].value.node)); }
#line 912 "grammar.tab.cpp"
    break;

  case 50: // expression: expression '+' expression
#line 141 "grammar.y"
                                                { (yylhs.value.node) = new Addition((yystack_[2].value.node),(yystack_[0].value.node));}
#line 918 "grammar.tab.cpp"
    break;

  case 51: // expression: expression '-' expression
#line 142 "grammar.y"
                                                { (yylhs.value.node) = new Subtraction((yystack_[2].value.node),(yystack_[0].value.node));}
#line 924 "grammar.tab.cpp"
    break;

  case 52: // expression: expression '*' expression
#line 143 "grammar.y"
                                                { (yylhs.value.node) = new Multiplication((yystack_[2].value.node),(yystack_[0].value.node));}
#line 930 "grammar.tab.cpp"
    break;

  case 53: // expression: expression '/' expression
#line 144 "grammar.y"
                                                { (yylhs.value.node) = new Division((yystack_[2].value.node),(yystack_[0].value.node));}
#line 936 "grammar.tab.cpp"
    break;

  case 54: // expression: expression '%' expression
#line 145 "grammar.y"
                                                { (yylhs.value.node) = new Modulo((yystack_[2].value.node),(yystack_[0].value.node));}
#line 942 "grammar.tab.cpp"
    break;

  case 55: // expression: '-' expression
#line 146 "grammar.y"
                                                                { (yylhs.value.node) = new UnaryMinus((yystack_[0].value.node));}
#line 948 "grammar.tab.cpp"
    break;

  case 56: // expression: '+' expression
#line 147 "grammar.y"
                                                                { (yylhs.value.node) = new UnaryMinus((yystack_[0].value.node));}
#line 954 "grammar.tab.cpp"
    break;

  case 57: // expression: expression FDIV expression
#line 148 "grammar.y"
                                                { (yylhs.value.node) = new FloorDivision((yystack_[2].value.node),(yystack_[0].value.node));}
#line 960 "grammar.tab.cpp"
    break;

  case 58: // expression: expression INCREMENT
#line 149 "grammar.y"
                                                        { (yylhs.value.node) = new Increment((yystack_[1].value.node));}
#line 966 "grammar.tab.cpp"
    break;

  case 59: // expression: expression DECREMENT
#line 150 "grammar.y"
                                                        { (yylhs.value.node) = new Decrement((yystack_[1].value.node));}
#line 972 "grammar.tab.cpp"
    break;

  case 60: // expression: expression '^' expression
#line 151 "grammar.y"
                                                { (yylhs.value.node) = new Exponentiation((yystack_[2].value.node),(yystack_[0].value.node));}
#line 978 "grammar.tab.cpp"
    break;

  case 61: // expression: expression LAND expression
#line 152 "grammar.y"
                                                { (yylhs.value.node) = new LogicalAnd((yystack_[2].value.node),(yystack_[0].value.node));}
#line 984 "grammar.tab.cpp"
    break;

  case 62: // expression: expression LOR expression
#line 153 "grammar.y"
                                                { (yylhs.value.node) = new LogicalOr((yystack_[2].value.node),(yystack_[0].value.node));}
#line 990 "grammar.tab.cpp"
    break;

  case 63: // expression: LNOT expression
#line 154 "grammar.y"
                                                                { (yylhs.value.node) = new LogicalNot((yystack_[0].value.node));}
#line 996 "grammar.tab.cpp"
    break;

  case 64: // expression: expression EQ expression
#line 155 "grammar.y"
                                                        { (yylhs.value.node) = new Equal((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1002 "grammar.tab.cpp"
    break;

  case 65: // expression: expression NEQ expression
#line 156 "grammar.y"
                                                { (yylhs.value.node) = new NotEqual((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1008 "grammar.tab.cpp"
    break;

  case 66: // expression: expression LT expression
#line 157 "grammar.y"
                                                        { (yylhs.value.node) = new LessThan((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1014 "grammar.tab.cpp"
    break;

  case 67: // expression: expression LTE expression
#line 158 "grammar.y"
                                                { (yylhs.value.node) = new LessThanOrEqual((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1020 "grammar.tab.cpp"
    break;

  case 68: // expression: expression GT expression
#line 159 "grammar.y"
                                                        { (yylhs.value.node) = new GreaterThan((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1026 "grammar.tab.cpp"
    break;

  case 69: // expression: expression GTE expression
#line 160 "grammar.y"
                                                { (yylhs.value.node) = new GreaterThanOrEqual((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1032 "grammar.tab.cpp"
    break;

  case 70: // expression: expression BITAND expression
#line 161 "grammar.y"
                                                { (yylhs.value.node) = new BITWISEAND((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1038 "grammar.tab.cpp"
    break;

  case 71: // expression: expression BITOR expression
#line 162 "grammar.y"
                                                        { (yylhs.value.node) = new BITWISEOR((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1044 "grammar.tab.cpp"
    break;

  case 72: // expression: expression BITXOR expression
#line 163 "grammar.y"
                                                        { (yylhs.value.node) = new BITWISEXOR((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1050 "grammar.tab.cpp"
    break;

  case 73: // expression: expression LSHIFT expression
#line 164 "grammar.y"
                                                        { (yylhs.value.node) = new LSHIFT((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1056 "grammar.tab.cpp"
    break;

  case 74: // expression: expression RSHIFT expression
#line 165 "grammar.y"
                                                        { (yylhs.value.node) = new RSHIFT((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1062 "grammar.tab.cpp"
    break;

  case 75: // expression: BNOT expression
#line 166 "grammar.y"
                                                                        { (yylhs.value.node) = new BITWISENOT((yystack_[0].value.node));}
#line 1068 "grammar.tab.cpp"
    break;

  case 76: // expression: IDENTIFIER '=' expression
#line 167 "grammar.y"
                                                        { (yylhs.value.node) = new Assignment((yystack_[2].value.node),(yystack_[0].value.node));}
#line 1074 "grammar.tab.cpp"
    break;

  case 77: // args: expression
#line 170 "grammar.y"
                                                                { (yylhs.value.node) = new ArgumentList((yystack_[0].value.node)); }
#line 1080 "grammar.tab.cpp"
    break;

  case 78: // args: args ',' expression
#line 171 "grammar.y"
                                                        { (yylhs.value.node) = new ArgumentList((yystack_[2].value.node),(yystack_[0].value.node)); }
#line 1086 "grammar.tab.cpp"
    break;


#line 1090 "grammar.tab.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
    YY_STACK_PRINT ();
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -122;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     219,  -122,    43,  -122,  -122,  -122,  -122,  -122,   -39,     8,
     114,     9,   235,    13,    33,   158,   158,   158,   158,   158,
     129,    79,   219,   235,  -122,  -122,  -122,    84,  -122,  -122,
    -122,  -122,  -122,  -122,   267,   158,    47,   158,   158,  -122,
     293,   121,    77,  -122,  -122,   -23,   -23,     5,     5,   319,
    -122,   171,  -122,   235,  -122,  -122,    46,    -6,   -16,  -122,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,  -122,  -122,   158,   158,   158,   158,
     158,   158,   459,  -122,   459,   -22,   347,   375,  -122,   121,
      52,  -122,  -122,    -2,  -122,    91,   158,    49,   484,   508,
     531,   553,   574,   595,   595,   614,   614,   614,   614,   -13,
     -13,    51,     5,     5,    51,    51,    51,    51,  -122,   158,
     235,   235,    68,   158,  -122,    50,    10,  -122,     7,   459,
    -122,   459,    87,  -122,   235,   403,   431,  -122,    50,    96,
     158,   235,  -122,   235,    92,  -122,  -122,   459,  -122,  -122,
    -122
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    45,    46,    17,    16,    18,    19,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     3,     5,     9,    10,     0,     7,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,    42,
       0,     0,     0,    43,    44,    63,    75,    56,    55,     0,
      34,     0,     1,     2,     6,     8,    24,     0,    20,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,    76,    48,    77,     0,     0,     0,    41,     0,
       0,    47,    33,     0,    15,     0,     0,     0,    62,    61,
      71,    72,    70,    64,    65,    66,    67,    68,    69,    73,
      74,    57,    50,    51,    52,    53,    54,    60,    49,     0,
       0,     0,     0,     0,    13,     0,     0,    24,    22,    21,
      25,    78,    40,    35,     0,     0,     0,    12,     0,     0,
       0,     0,    37,     0,     0,    11,    14,    23,    39,    36,
      38
  };

  const signed char
  parser::yypgoto_[] =
  {
    -122,  -122,  -122,   -14,    82,  -122,  -122,  -122,  -122,  -122,
      15,   -12,   -40,  -121,  -122,  -122,  -122,    -3,  -122
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    21,    22,    23,    24,    25,   126,    26,    27,    57,
      58,    28,    29,    30,    31,    32,    33,    34,    85
  };

  const short
  parser::yytable_[] =
  {
      42,    89,   124,    94,   137,    37,    51,    40,    53,    74,
      75,    55,    45,    46,    47,    48,    49,   145,    73,    74,
      75,    96,    43,   118,   119,    76,    77,    78,    79,    80,
      81,    97,    82,    84,    86,    87,    73,    74,    75,    55,
      95,    55,    44,   125,   140,    78,    79,    80,    81,   122,
       1,     2,    38,    41,    97,   138,   139,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     1,     2,   112,   113,   114,   115,   116,   117,    52,
      35,    15,    16,    74,    75,    17,    18,    36,    56,    90,
      93,    19,    83,   129,    81,   127,   123,   130,   141,    20,
     146,   150,    15,    16,    54,     0,    17,    18,   132,   133,
     128,     0,    19,   134,     0,     0,   131,     1,     2,   135,
     136,     0,   142,    39,     1,     2,     0,     0,     0,   148,
       7,   149,     1,     2,     0,     0,     0,   147,     7,     8,
       0,     9,    10,    11,    12,    13,    14,     0,    15,    16,
       0,     0,    17,    18,     0,    15,    16,     0,    19,    17,
      18,     1,     2,    15,    16,    19,     0,    17,    18,     0,
       0,     0,     0,    19,     1,     2,     0,     0,    20,    50,
       7,     8,     0,     9,    10,    11,    12,    13,    14,     0,
       0,     0,    15,    16,     0,     0,    17,    18,     0,     0,
       0,     0,    19,     0,     0,    15,    16,     0,     0,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    92,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,    10,    11,    12,    13,    14,     0,     1,     2,
       0,     0,     0,     0,     7,     8,     0,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    20,    15,
      16,     0,     0,    17,    18,     0,    59,     0,     0,    19,
       0,     0,     0,     0,    20,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    88,     0,     0,    76,    77,    78,    79,    80,
      81,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,     0,    91,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,     0,   120,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,     0,
     121,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,     0,   143,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,     0,   144,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81
  };

  const short
  parser::yycheck_[] =
  {
      12,    41,     4,     9,   125,    44,    20,    10,    22,    32,
      33,    23,    15,    16,    17,    18,    19,   138,    31,    32,
      33,    37,     9,    45,    46,    38,    39,    40,    41,    42,
      43,    47,    35,    36,    37,    38,    31,    32,    33,    51,
      46,    53,     9,    45,    37,    40,    41,    42,    43,    89,
       3,     4,    44,    44,    47,    45,    46,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     3,     4,    76,    77,    78,    79,    80,    81,     0,
      37,    34,    35,    32,    33,    38,    39,    44,     4,    12,
      44,    44,    45,    96,    43,     4,    44,    48,    11,    49,
       4,     9,    34,    35,    22,    -1,    38,    39,   120,   121,
      95,    -1,    44,    45,    -1,    -1,   119,     3,     4,   122,
     123,    -1,   134,     9,     3,     4,    -1,    -1,    -1,   141,
       9,   143,     3,     4,    -1,    -1,    -1,   140,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,    34,    35,
      -1,    -1,    38,    39,    -1,    34,    35,    -1,    44,    38,
      39,     3,     4,    34,    35,    44,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,     3,     4,    -1,    -1,    49,    50,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    34,    35,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      49,    50,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    34,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    34,
      35,    -1,    -1,    38,    39,    -1,     9,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,     9,    -1,    -1,    38,    39,    40,    41,    42,
      43,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    -1,    45,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    -1,    45,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    -1,
      45,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    -1,    45,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    -1,    45,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    34,    35,    38,    39,    44,
      49,    52,    53,    54,    55,    56,    58,    59,    62,    63,
      64,    65,    66,    67,    68,    37,    44,    44,    44,     9,
      68,    44,    62,     9,     9,    68,    68,    68,    68,    68,
      50,    54,     0,    54,    55,    62,     4,    60,    61,     9,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    38,    39,    40,    41,
      42,    43,    68,    45,    68,    69,    68,    68,     9,    63,
      12,    45,    50,    44,     9,    46,    37,    47,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    45,    46,
      45,    45,    63,    44,     4,    45,    57,     4,    61,    68,
      48,    68,    62,    62,    45,    68,    68,    64,    45,    46,
      37,    11,    62,    45,    45,    64,     4,    68,    62,    62,
       9
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    66,
      66,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     2,     1,     2,     1,
       1,     6,     5,     1,     3,     3,     1,     1,     1,     1,
       1,     3,     3,     5,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     3,     2,     5,     7,     6,     7,     7,
       5,     3,     2,     2,     2,     1,     1,     3,     3,     4,
       3,     3,     3,     3,     3,     2,     2,     3,     2,     2,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "FLOAT", "INT", "VOID", "CHAR", "SEMICOLON", "IF", "ELSE", "WHILE",
  "RETURN", "FOR", "DO", "BREAK", "CONTINUE", "LOR", "LAND", "BITOR",
  "BITXOR", "BITAND", "EQ", "NEQ", "LT", "LTE", "GT", "GTE", "LSHIFT",
  "RSHIFT", "FDIV", "INCREMENT", "DECREMENT", "LNOT", "BNOT", "LOWIF",
  "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('", "')'", "','",
  "'['", "']'", "'{'", "'}'", "$accept", "compilation_unit",
  "declarations", "statements", "declaration", "function_definition",
  "param_list", "variable_declaration", "type_specifier", "declarators",
  "direct_declarator", "statement", "expression_statement",
  "compound_statement", "iteration_statement", "selection_statement",
  "jump_statement", "expression", "args", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    61,    61,    62,    63,    66,    67,    70,    71,    74,
      75,    78,    79,    82,    83,    87,    90,    91,    92,    93,
      96,    97,    98,    99,   102,   103,   106,   107,   108,   109,
     110,   112,   113,   116,   117,   120,   121,   122,   123,   126,
     127,   129,   130,   131,   132,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   170,   171
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      44,    45,    40,    38,    46,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36
    };
    // Last valid token kind.
    const int code_max = 291;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1807 "grammar.tab.cpp"

#line 174 "grammar.y"


void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << msg << " at "<< loc <<  std::endl;
}
