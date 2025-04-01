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
#line 1 "parser.y"

    #include <iostream>
    #include <string>
    #include <cstring>
    #include<vector>

    #include "parser.hpp"

    using namespace std;

    int yyerror(char *yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;


#line 60 "parser.cpp"


#include "parser.hpp"




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
#line 138 "parser.cpp"

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
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_op: // op
        value.copy< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        value.copy< string * > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




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
    switch (this->kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_op: // op
        value.move< string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        value.move< string * > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

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
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_op: // op
        value.YY_MOVE_OR_COPY< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< string * > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_op: // op
        value.move< string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        value.move< string * > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_op: // op
        value.copy< string > (that.value);
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        value.copy< string * > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_REAL: // REAL
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        value.move< int > (that.value);
        break;

      case symbol_kind::S_op: // op
        value.move< string > (that.value);
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        value.move< string * > (that.value);
        break;

      default:
        break;
    }

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
            << ' ' << yysym.name () << " (";
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_REAL: // REAL
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTCONST: // INTCONST
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_op: // op
        yylhs.value.emplace< string > ();
        break;

      case symbol_kind::S_KEYWORD: // KEYWORD
      case symbol_kind::S_OPERATOR: // OPERATOR
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_PUNCTUATION: // PUNCTUATION
      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< string * > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // stmt: expr PUNCTUATION
#line 61 "parser.y"
                         { 
        if(*yystack_[0].value.as < string * > () != ";") yyerror("Line not finished with ;"); YYERROR;
    }
#line 754 "parser.cpp"
    break;

  case 9: // stmt: KEYWORD PUNCTUATION
#line 68 "parser.y"
                          {
        if(*yystack_[0].value.as < string * > () != ";") yyerror("Line not finished with ;"); YYERROR;

        if(*yystack_[1].value.as < string * > () == "break") cout << "Found break statement" << endl;
        else if(*yystack_[1].value.as < string * > () == "continue") cout << "Found continue statement" << endl;
        else{
            yyerror("Invalid statement");
            YYERROR;
        }
    }
#line 769 "parser.cpp"
    break;

  case 12: // stmt: PUNCTUATION
#line 80 "parser.y"
                  {if(*yystack_[0].value.as < string * > () != ";") yyerror("INVALID PUNCTUATION"); YYERROR;}
#line 775 "parser.cpp"
    break;

  case 16: // op: OPERATOR
#line 88 "parser.y"
             {
        string validOps[11] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        bool found = false;
        for (const string& op : validOps) {
            if (*yystack_[0].value.as < string * > () == op) {
                found = true;
                yylhs.value.as < string > () = op;
                break;
            }
        }
        if (!found) {
            yyerror("Invalid operator");
            YYERROR;
        }
    }
#line 795 "parser.cpp"
    break;

  case 17: // op: KEYWORD
#line 103 "parser.y"
              {
        if(*yystack_[0].value.as < string * > () == "and") yylhs.value.as < string > () = new string("and");
        else if(*yystack_[0].value.as < string * > () == "or") yylhs.value.as < string > () = new string("or");
        else yyerror("Invalid operator"); YYERROR;
    }
#line 805 "parser.cpp"
    break;

  case 18: // term: PUNCTUATION expr PUNCTUATION
#line 110 "parser.y"
                                  {
        if(*yystack_[2].value.as < string * > () != "(") yyerror("Term does not begin with ("); YYERROR;
        if(*yystack_[0].value.as < string * > () != ")") yyerror("Term does not end with )"); YYERROR;
    }
#line 814 "parser.cpp"
    break;

  case 19: // term: OPERATOR expr
#line 114 "parser.y"
                   {
        if(*yystack_[1].value.as < string * > () != "-") yyerror("Term cannot does not begin -"); YYERROR;
    }
#line 822 "parser.cpp"
    break;

  case 20: // term: KEYWORD expr
#line 117 "parser.y"
                  {
        if(*yystack_[1].value.as < string * > () != "not") yyerror("Term does not begin with not"); YYERROR;
    }
#line 830 "parser.cpp"
    break;

  case 21: // term: OPERATOR lvalue
#line 120 "parser.y"
                     {
        if(*yystack_[1].value.as < string * > () != "++" || *yystack_[1].value.as < string * > () != "--") yyerror("Term must begin with \"++\" or \"--\""); YYERROR;
    }
#line 838 "parser.cpp"
    break;

  case 22: // term: lvalue OPERATOR
#line 123 "parser.y"
                     {
        if(*yystack_[0].value.as < string * > () != "++" || *yystack_[0].value.as < string * > () != "--") yyerror("Term must end with \"++\" or \"--\""); YYERROR;
    }
#line 846 "parser.cpp"
    break;

  case 24: // assignexpr: lvalue OPERATOR expr
#line 129 "parser.y"
                                 {if(*yystack_[1].value.as < string * > () != "=") yyerror("Operator must be \"=\" in assignment expressions"); YYERROR;}
#line 852 "parser.cpp"
    break;

  case 28: // primary: OPERATOR funcdef OPERATOR
#line 135 "parser.y"
                               {
        if(*yystack_[2].value.as < string * > () != "(") yyerror("primary does not begin with ("); YYERROR;
        if(*yystack_[0].value.as < string * > () != ")") yyerror("primary does not end with )"); YYERROR;
    }
#line 861 "parser.cpp"
    break;

  case 31: // lvalue: KEYWORD ID
#line 143 "parser.y"
                {
        if(*yystack_[1].value.as < string * > () != "local") yyerror("lvalue does not begin with keyword \"local\""); YYERROR;
    }
#line 869 "parser.cpp"
    break;

  case 32: // lvalue: PUNCTUATION ID
#line 146 "parser.y"
                     {
        if(*yystack_[1].value.as < string * > () != "::") yyerror("lvalue does not begin with punctuation \"::\""); YYERROR;
    }
#line 877 "parser.cpp"
    break;

  case 34: // member: lvalue PUNCTUATION ID
#line 152 "parser.y"
                             {
        if(*yystack_[1].value.as < string * > () != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
#line 885 "parser.cpp"
    break;

  case 35: // member: lvalue PUNCTUATION expr PUNCTUATION
#line 155 "parser.y"
                                         {
        if(*yystack_[2].value.as < string * > () != "[") yyerror("member can only contain ["); YYERROR;
        if(*yystack_[0].value.as < string * > () != "]") yyerror("member can only contain ]"); YYERROR;
    }
#line 894 "parser.cpp"
    break;

  case 36: // member: call PUNCTUATION ID
#line 159 "parser.y"
                         {
        if(*yystack_[1].value.as < string * > () != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
#line 902 "parser.cpp"
    break;

  case 37: // member: call PUNCTUATION expr PUNCTUATION
#line 162 "parser.y"
                                       {
        if(*yystack_[2].value.as < string * > () != "[") yyerror("member can only contain ["); YYERROR;
        if(*yystack_[0].value.as < string * > () != "]") yyerror("member can only contain ]"); YYERROR; 
    }
#line 911 "parser.cpp"
    break;

  case 38: // call: call PUNCTUATION elist PUNCTUATION
#line 168 "parser.y"
                                        {
        if(*yystack_[2].value.as < string * > () != "(") yyerror("Invalid punctuation"); YYERROR;
        if(*yystack_[0].value.as < string * > () != ")") yyerror("Invalid punctuation"); YYERROR;
    }
#line 920 "parser.cpp"
    break;

  case 40: // call: PUNCTUATION funcdef PUNCTUATION PUNCTUATION elist PUNCTUATION
#line 173 "parser.y"
                                                                   {
        if(*yystack_[5].value.as < string * > () != "(" || *yystack_[3].value.as < string * > () != ")") yyerror("Invalid call must be \"( function )\""); YYERROR;
        if(*yystack_[2].value.as < string * > () != "(" || *yystack_[0].value.as < string * > () != ")") yyerror("Invalid call must be \"( function ) ( expr )\""); YYERROR;
    }
#line 929 "parser.cpp"
    break;

  case 43: // normcall: PUNCTUATION elist PUNCTUATION
#line 183 "parser.y"
                                        {
        if(*yystack_[2].value.as < string * > () != "(") yyerror("normcall must begin with ("); YYERROR;
        if(*yystack_[0].value.as < string * > () != ")") yyerror("normcall must end with )"); YYERROR; 
    }
#line 938 "parser.cpp"
    break;

  case 44: // methodcall: PUNCTUATION ID PUNCTUATION elist PUNCTUATION
#line 189 "parser.y"
                                                         {
        if(*yystack_[4].value.as < string * > () != "..") yyerror("methodcall must begin with \"..\""); YYERROR;
        if(*yystack_[2].value.as < string * > () != "(" || *yystack_[0].value.as < string * > () != ")") yyerror("Invalid methodcall must be like \"..id(elist)\""); YYERROR;
    }
#line 947 "parser.cpp"
    break;

  case 47: // elist: elist PUNCTUATION expr
#line 197 "parser.y"
                            {
        if(*yystack_[1].value.as < string * > () != ",") yyerror("Invalid punctuation in elist"); YYERROR; 
    }
#line 955 "parser.cpp"
    break;

  case 48: // objectdef: PUNCTUATION PUNCTUATION
#line 202 "parser.y"
                                  {
        if(*yystack_[1].value.as < string * > () != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*yystack_[0].value.as < string * > () != "]") yyerror("objectdef must end with ]"); YYERROR;
    }
#line 964 "parser.cpp"
    break;

  case 49: // objectdef: PUNCTUATION elist PUNCTUATION
#line 206 "parser.y"
                                   {
        if(*yystack_[2].value.as < string * > () != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*yystack_[0].value.as < string * > () != "]") yyerror("objectdef must end with ]"); YYERROR;
    }
#line 973 "parser.cpp"
    break;

  case 50: // block: PUNCTUATION stmtlist PUNCTUATION
#line 226 "parser.y"
                                        {if(*yystack_[2].value.as < string * > () != "{" || *yystack_[0].value.as < string * > () != "}") yyerror("wrong punctuation in block"); YYERROR;}
#line 979 "parser.cpp"
    break;

  case 54: // funcdef: KEYWORD PUNCTUATION idlist PUNCTUATION block
#line 234 "parser.y"
                                                      {
        if(*yystack_[4].value.as < string * > () != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*yystack_[3].value.as < string * > () != "(" || *yystack_[1].value.as < string * > () != ")") yyerror("function must have (params)"); YYERROR;
    }
#line 988 "parser.cpp"
    break;

  case 55: // funcdef: KEYWORD ID PUNCTUATION idlist PUNCTUATION block
#line 238 "parser.y"
                                                      {
        if(*yystack_[5].value.as < string * > () != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*yystack_[3].value.as < string * > () != "(" || *yystack_[1].value.as < string * > () != ")") yyerror("function must have (params)"); YYERROR;
    }
#line 997 "parser.cpp"
    break;

  case 56: // const: KEYWORD
#line 244 "parser.y"
              {
    if(*yystack_[0].value.as < string * > () != "true" || *yystack_[0].value.as < string * > () != "false" || *yystack_[0].value.as < string * > () != "nil") yyerror("not a valid value"); YYERROR;
    }
#line 1005 "parser.cpp"
    break;

  case 62: // idlist: idlist PUNCTUATION ID
#line 254 "parser.y"
                            {if(*yystack_[1].value.as < string * > () != ",") yyerror("Wrong punctuation in idlist"); YYERROR;}
#line 1011 "parser.cpp"
    break;

  case 63: // ifstmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt
#line 257 "parser.y"
                                                  {
        if(*yystack_[4].value.as < string * > () != "if") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*yystack_[3].value.as < string * > () != "(" || *yystack_[1].value.as < string * > () != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR;
    }
#line 1020 "parser.cpp"
    break;

  case 64: // ifstmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt KEYWORD stmt
#line 261 "parser.y"
                                                            {
        if(*yystack_[6].value.as < string * > () != "if" || *yystack_[1].value.as < string * > () != "else") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*yystack_[5].value.as < string * > () != "(" || *yystack_[3].value.as < string * > () != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR; 
    }
#line 1029 "parser.cpp"
    break;

  case 65: // whilestmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt
#line 267 "parser.y"
                                                     {
        if(*yystack_[4].value.as < string * > () != "while") yyerror("Invalid keyword in whilestmt"); YYERROR;
        if(*yystack_[3].value.as < string * > () != "(" || *yystack_[1].value.as < string * > () != ")") yyerror("Invalid punctuation in whilestmt"); YYERROR; 
    }
#line 1038 "parser.cpp"
    break;

  case 66: // forstmt: KEYWORD PUNCTUATION elist PUNCTUATION expr PUNCTUATION elist PUNCTUATION stmt
#line 273 "parser.y"
                                                                                      {
    if(*yystack_[8].value.as < string * > () != "for") yyerror("Invalid keyword in forstmt"); YYERROR;
    if(*yystack_[7].value.as < string * > () != "(" || *yystack_[1].value.as < string * > () != ")") yyerror("forstmt does not contain ()"); YYERROR;
    if(*yystack_[5].value.as < string * > () != ";" || *yystack_[3].value.as < string * > () != ";") yyerror("forstmt must be like for(elist; expr; elist) mprokoloko"); YYERROR;
}
#line 1048 "parser.cpp"
    break;

  case 67: // returnstmt: KEYWORD PUNCTUATION
#line 280 "parser.y"
                                {
        if(*yystack_[1].value.as < string * > () != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*yystack_[0].value.as < string * > () != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    }
#line 1057 "parser.cpp"
    break;

  case 68: // returnstmt: KEYWORD expr PUNCTUATION
#line 284 "parser.y"
                              {
        if(*yystack_[2].value.as < string * > () != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*yystack_[0].value.as < string * > () != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    char *yaccProvidedMessage}
#line 1066 "parser.cpp"
    break;


#line 1070 "parser.cpp"

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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


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

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


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
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -81;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      90,   107,   114,   -81,   -81,   -81,   121,   -81,    15,   -81,
       8,   -81,   -81,   -81,     6,   -81,    17,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   128,   135,    21,    42,   142,
     149,    39,     6,    30,   121,   -81,   -81,    51,    28,   156,
      32,   -81,   -81,   -81,   -81,   -81,   163,   163,   170,   -81,
     -81,   -81,   177,   -81,    39,   149,   -81,    57,    36,    32,
      43,    29,   -81,   135,    68,   -81,   -81,   163,   121,   -81,
      44,    39,    39,    49,    70,    50,   -81,    81,    55,    90,
     163,    -4,   -81,    69,   -81,    39,   163,   163,   -81,   163,
     -81,   163,    77,   184,    90,   -81,   -81,    -4,    39,    75,
      78,    90,   163,   -81,   163,   163,   -81,    83,    90,   -81,
       8
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,    57,    58,    59,    12,    30,     0,     2,
       0,    15,    13,    23,    25,    33,    26,    27,    10,    11,
      29,     5,     6,     7,     8,     0,     9,    30,     0,     0,
       0,    19,    21,     0,     0,    30,    52,     0,     0,     0,
      11,     1,     3,    17,    16,     4,     0,     0,     0,    39,
      41,    42,     0,    30,    20,     0,    30,     0,     0,     0,
       0,    60,    68,     0,     0,    28,     4,     0,    50,    53,
       0,    14,    24,    30,     0,     0,    30,     0,     0,     0,
       0,     0,    61,     0,    18,    47,     0,     0,    35,     0,
      37,     0,    63,     0,     0,    62,    54,     0,    46,     0,
       0,     0,     0,    55,     0,     0,    64,     0,     0,    66,
       0
  };

  const signed char
  parser::yypgoto_[] =
  {
     -81,   -81,     0,     1,   -81,   -81,   -81,   -81,    98,   -81,
     -81,   -81,   -81,   -81,   -20,   -81,   -80,   -81,     7,   -81,
      41,   -81,   -81,   -81,   -81
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     8,    36,    10,    46,    11,    12,    13,    14,    15,
      16,    49,    50,    51,    38,    17,    18,    39,    19,    20,
      60,    21,    22,    23,    24
  };

  const signed char
  parser::yytable_[] =
  {
       9,    96,    28,    31,    94,    95,    58,    37,    42,    33,
      47,    43,    44,    40,    48,    41,    45,   103,     1,     2,
       3,     4,     5,     6,     7,    52,    54,    57,    75,    61,
      54,    64,    78,    59,    65,    37,    67,    59,    82,    69,
      70,    40,    43,    44,    80,    43,    44,    71,    72,    74,
      62,    81,    86,    77,    43,    44,    64,    87,    89,    66,
      43,    44,    59,    91,    64,    79,    99,   100,    85,    37,
      59,    43,    44,    43,    44,    40,    84,    97,    88,    92,
     101,    93,   107,   104,    43,    44,   105,    98,    98,    90,
      85,   108,    85,     1,     2,     3,     4,     5,     6,     7,
      32,   106,    83,    98,     0,    85,    85,     0,   109,   110,
      25,     2,     3,     4,     5,    26,    27,    29,     2,     3,
       4,     5,    30,     7,     1,     2,     3,     4,     5,    34,
      35,    25,     2,     3,     4,     5,    30,    53,    29,     2,
       3,     4,     5,    55,    56,    25,     2,     3,     4,     5,
      63,    27,    29,     2,     3,     4,     5,    55,    35,     1,
       2,     3,     4,     5,    68,     7,    25,     2,     3,     4,
       5,    30,     7,    25,     2,     3,     4,     5,    30,    73,
      25,     2,     3,     4,     5,    30,    76,    43,    44,     0,
       0,     0,   102
  };

  const signed char
  parser::yycheck_[] =
  {
       0,    81,     1,     2,     8,     9,    26,     6,     8,     2,
       4,     3,     4,     6,     8,     0,     8,    97,     3,     4,
       5,     6,     7,     8,     9,     8,    25,    26,    48,     8,
      29,    30,    52,    26,     4,    34,     8,    30,     9,    39,
       8,    34,     3,     4,     8,     3,     4,    46,    47,    48,
       8,     8,     8,    52,     3,     4,    55,     8,     8,     8,
       3,     4,    55,     8,    63,     8,    86,    87,    67,    68,
      63,     3,     4,     3,     4,    68,     8,     8,     8,    79,
       3,    80,   102,     8,     3,     4,     8,    86,    87,     8,
      89,     8,    91,     3,     4,     5,     6,     7,     8,     9,
       2,   101,    61,   102,    -1,   104,   105,    -1,   108,   108,
       3,     4,     5,     6,     7,     8,     9,     3,     4,     5,
       6,     7,     8,     9,     3,     4,     5,     6,     7,     8,
       9,     3,     4,     5,     6,     7,     8,     9,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,     3,     4,     5,     6,     7,     8,     9,     3,
       4,     5,     6,     7,     8,     9,     3,     4,     5,     6,
       7,     8,     9,     3,     4,     5,     6,     7,     8,     9,
       3,     4,     5,     6,     7,     8,     9,     3,     4,    -1,
      -1,    -1,     8
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    32,    33,
      34,    36,    37,    38,    39,    40,    41,    46,    47,    49,
      50,    52,    53,    54,    55,     3,     8,     9,    34,     3,
       8,    34,    39,    49,     8,     9,    33,    34,    45,    48,
      49,     0,    33,     3,     4,     8,    35,     4,     8,    42,
      43,    44,     8,     9,    34,     8,     9,    34,    45,    49,
      51,     8,     8,     8,    34,     4,     8,     8,     8,    33,
       8,    34,    34,     9,    34,    45,     9,    34,    45,     8,
       8,     8,     9,    51,     8,    34,     8,     8,     8,     8,
       8,     8,    33,    34,     8,     9,    47,     8,    34,    45,
      45,     3,     8,    47,     8,     8,    33,    45,     8,    33,
      34
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    31,    32,    32,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    34,    34,    35,    35,    36,    36,
      36,    36,    36,    36,    37,    38,    38,    38,    38,    38,
      39,    39,    39,    39,    40,    40,    40,    40,    41,    41,
      41,    42,    42,    43,    44,    45,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      51,    51,    51,    52,    52,    53,    54,    55,    55
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     2,
       2,     2,     2,     1,     3,     1,     1,     1,     3,     1,
       1,     2,     2,     1,     3,     4,     3,     4,     4,     2,
       6,     1,     1,     3,     5,     0,     1,     3,     2,     3,
       3,     0,     1,     2,     5,     6,     1,     1,     1,     1,
       0,     1,     3,     5,     7,     5,     9,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "KEYWORD", "OPERATOR",
  "INTCONST", "REAL", "STRING", "PUNCTUATION", "ID", "\"=\"", "\"or\"",
  "\"and\"", "\"==\"", "\"!=\"", "\">\"", "\">=\"", "\"<\"", "\"<=\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "NOT", "UOP", "MINUS",
  "\".\"", "\"..\"", "BRACKETS", "PARENTHESIS", "$accept", "program",
  "stmt", "expr", "op", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elist",
  "objectdef", "block", "stmtlist", "funcdef", "const", "idlist", "ifstmt",
  "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    57,    57,    58,    61,    64,    65,    66,    67,    68,
      78,    79,    80,    83,    84,    85,    88,   103,   110,   114,
     117,   120,   123,   126,   129,   132,   133,   134,   135,   139,
     142,   143,   146,   149,   152,   155,   159,   162,   168,   172,
     173,   179,   180,   183,   189,   195,   196,   197,   202,   206,
     226,   229,   230,   231,   234,   238,   244,   247,   248,   249,
     252,   253,   254,   257,   261,   267,   273,   280,   284
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
      25,    26,    27,    28,    29,    30
    };
    // Last valid token kind.
    const int code_max = 285;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1515 "parser.cpp"

#line 289 "parser.y"


yyerror(char *yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
}

int main(){
    yyparse();
    return 0;
}

