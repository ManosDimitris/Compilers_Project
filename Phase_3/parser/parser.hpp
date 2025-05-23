/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    FUNCTION = 262,                /* FUNCTION  */
    RETURN = 263,                  /* RETURN  */
    BREAK = 264,                   /* BREAK  */
    CONTINUE = 265,                /* CONTINUE  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    LOCAL = 268,                   /* LOCAL  */
    TRUE = 269,                    /* TRUE  */
    FALSE = 270,                   /* FALSE  */
    NIL = 271,                     /* NIL  */
    EQUAL = 272,                   /* EQUAL  */
    ASSIGN = 273,                  /* ASSIGN  */
    UPLUS = 274,                   /* UPLUS  */
    PLUS = 275,                    /* PLUS  */
    UMINUS = 276,                  /* UMINUS  */
    MINUS = 277,                   /* MINUS  */
    MULTI = 278,                   /* MULTI  */
    DIV = 279,                     /* DIV  */
    MOD = 280,                     /* MOD  */
    NEQUAL = 281,                  /* NEQUAL  */
    INTCONST = 282,                /* INTCONST  */
    REAL = 283,                    /* REAL  */
    STRING = 284,                  /* STRING  */
    GREATER_EQUAL = 285,           /* GREATER_EQUAL  */
    LESS_EQUAL = 286,              /* LESS_EQUAL  */
    GREATER = 287,                 /* GREATER  */
    LESS = 288,                    /* LESS  */
    LEFT_CBRACKET = 289,           /* LEFT_CBRACKET  */
    RIGHT_CBRACKET = 290,          /* RIGHT_CBRACKET  */
    LEFT_BRACKET = 291,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 292,           /* RIGHT_BRACKET  */
    LEFT_PARENTHES = 293,          /* LEFT_PARENTHES  */
    RIGHT_PARENTHES = 294,         /* RIGHT_PARENTHES  */
    SEMICOLON = 295,               /* SEMICOLON  */
    COMMA = 296,                   /* COMMA  */
    DCOLON = 297,                  /* DCOLON  */
    COLON = 298,                   /* COLON  */
    DOTS = 299,                    /* DOTS  */
    DOT = 300,                     /* DOT  */
    ID = 301,                      /* ID  */
    NOT = 302,                     /* NOT  */
    THEN = 303                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define AND 266
#define OR 267
#define LOCAL 268
#define TRUE 269
#define FALSE 270
#define NIL 271
#define EQUAL 272
#define ASSIGN 273
#define UPLUS 274
#define PLUS 275
#define UMINUS 276
#define MINUS 277
#define MULTI 278
#define DIV 279
#define MOD 280
#define NEQUAL 281
#define INTCONST 282
#define REAL 283
#define STRING 284
#define GREATER_EQUAL 285
#define LESS_EQUAL 286
#define GREATER 287
#define LESS 288
#define LEFT_CBRACKET 289
#define RIGHT_CBRACKET 290
#define LEFT_BRACKET 291
#define RIGHT_BRACKET 292
#define LEFT_PARENTHES 293
#define RIGHT_PARENTHES 294
#define SEMICOLON 295
#define COMMA 296
#define DCOLON 297
#define COLON 298
#define DOTS 299
#define DOT 300
#define ID 301
#define NOT 302
#define THEN 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "parser/parser.y"

    std::string *strVal;
    int intVal;
    double realVal;
    struct expr* exprVal;

#line 170 "parser/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_PARSER_HPP_INCLUDED  */
