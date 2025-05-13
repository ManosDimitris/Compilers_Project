/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser/parser.y"

    #include <iostream>
    #include <string>
    #include <cstring>
    #include <fstream>
    #include<vector>
    #include"../SymTable/SymTable.hpp"
    using namespace std;

    int yyerror(string yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;

    SymbolTable symTable;
    int scope = 0;
    bool found_Func = false, isCall = false;
    int curr_func = 1;

    ostream *outStream;

    bool hasLibFuncName(string name);

#line 97 "parser/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_FUNCTION = 7,                   /* FUNCTION  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_LOCAL = 13,                     /* LOCAL  */
  YYSYMBOL_TRUE = 14,                      /* TRUE  */
  YYSYMBOL_FALSE = 15,                     /* FALSE  */
  YYSYMBOL_NIL = 16,                       /* NIL  */
  YYSYMBOL_EQUAL = 17,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 18,                    /* ASSIGN  */
  YYSYMBOL_UPLUS = 19,                     /* UPLUS  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_UMINUS = 21,                    /* UMINUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MULTI = 23,                     /* MULTI  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_NEQUAL = 26,                    /* NEQUAL  */
  YYSYMBOL_INTCONST = 27,                  /* INTCONST  */
  YYSYMBOL_REAL = 28,                      /* REAL  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_GREATER_EQUAL = 30,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 31,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 32,                   /* GREATER  */
  YYSYMBOL_LESS = 33,                      /* LESS  */
  YYSYMBOL_LEFT_CBRACKET = 34,             /* LEFT_CBRACKET  */
  YYSYMBOL_RIGHT_CBRACKET = 35,            /* RIGHT_CBRACKET  */
  YYSYMBOL_LEFT_BRACKET = 36,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 37,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_PARENTHES = 38,            /* LEFT_PARENTHES  */
  YYSYMBOL_RIGHT_PARENTHES = 39,           /* RIGHT_PARENTHES  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_DCOLON = 42,                    /* DCOLON  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_DOTS = 44,                      /* DOTS  */
  YYSYMBOL_DOT = 45,                       /* DOT  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_THEN = 48,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_stmntlist = 51,                 /* stmntlist  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_assignexpr = 55,                /* assignexpr  */
  YYSYMBOL_primary = 56,                   /* primary  */
  YYSYMBOL_lvalue = 57,                    /* lvalue  */
  YYSYMBOL_member = 58,                    /* member  */
  YYSYMBOL_call = 59,                      /* call  */
  YYSYMBOL_callsuffix = 60,                /* callsuffix  */
  YYSYMBOL_normcall = 61,                  /* normcall  */
  YYSYMBOL_methodcall = 62,                /* methodcall  */
  YYSYMBOL_elist = 63,                     /* elist  */
  YYSYMBOL_objectdef = 64,                 /* objectdef  */
  YYSYMBOL_indexed = 65,                   /* indexed  */
  YYSYMBOL_indexedelemlist = 66,           /* indexedelemlist  */
  YYSYMBOL_indexedelem = 67,               /* indexedelem  */
  YYSYMBOL_block = 68,                     /* block  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_funcdef = 70,                   /* funcdef  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_const = 79,                     /* const  */
  YYSYMBOL_idlist = 80,                    /* idlist  */
  YYSYMBOL_ifstmt = 81,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 82,                 /* whilestmt  */
  YYSYMBOL_forstmt = 83,                   /* forstmt  */
  YYSYMBOL_84_10 = 84,                     /* $@10  */
  YYSYMBOL_85_11 = 85,                     /* $@11  */
  YYSYMBOL_returnstmt = 86                 /* returnstmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   605

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    61,    64,    65,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    97,    98,    99,   100,   101,   102,   103,   104,   107,
     110,   111,   112,   113,   114,   117,   134,   146,   151,   154,
     155,   156,   157,   160,   161,   162,   164,   165,   168,   171,
     174,   175,   176,   179,   180,   183,   186,   187,   190,   193,
     193,   197,   200,   204,   204,   204,   200,   206,   215,   215,
     215,   206,   218,   219,   220,   221,   222,   223,   226,   227,
     236,   247,   248,   251,   254,   254,   254,   257,   258
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "OR", "LOCAL",
  "TRUE", "FALSE", "NIL", "EQUAL", "ASSIGN", "UPLUS", "PLUS", "UMINUS",
  "MINUS", "MULTI", "DIV", "MOD", "NEQUAL", "INTCONST", "REAL", "STRING",
  "GREATER_EQUAL", "LESS_EQUAL", "GREATER", "LESS", "LEFT_CBRACKET",
  "RIGHT_CBRACKET", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PARENTHES",
  "RIGHT_PARENTHES", "SEMICOLON", "COMMA", "DCOLON", "COLON", "DOTS",
  "DOT", "ID", "NOT", "THEN", "$accept", "program", "stmntlist", "stmt",
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelemlist", "indexedelem", "block", "$@1", "funcdef", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "const", "idlist",
  "ifstmt", "whilestmt", "forstmt", "$@10", "$@11", "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     198,   -21,   -18,    -7,    -6,   233,    22,    25,     8,   -59,
     -59,   -59,    21,    21,   268,   -59,   -59,   -59,    35,    99,
      14,   -59,    41,   -31,   268,   122,   198,   -59,   320,   -59,
     -59,   -59,   -13,   -59,   -35,   -59,   -59,   -59,   -59,    95,
     -59,   -59,   -59,   268,   268,   -59,   -59,    87,   -59,   344,
     -59,   -59,   -59,   123,   -34,   -35,   -34,     1,   -59,   198,
     268,   524,   -19,    97,   -59,    91,   392,   101,   -59,   268,
      92,   -59,   -59,   -59,   -59,   -59,   -59,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     -59,   268,   -59,   -59,   268,   103,   268,   268,   105,   198,
     415,   438,   268,    98,   -59,   -59,   104,   153,   296,   -59,
     268,   -59,   118,   -59,   115,     6,   116,    78,   541,   558,
       1,     1,   -59,   -59,   -59,   558,   572,   572,   572,   572,
     524,   461,   -59,   484,     7,   -59,   -59,   198,   198,    17,
     -59,   109,   115,   -59,   268,   524,   -59,   268,   -59,   268,
     -59,   -59,   -59,   -59,   -59,   268,   109,   -59,    12,   507,
      27,    30,   368,    49,   -59,   111,   -59,   -59,   -59,   268,
     -59,   -59,   -59,    90,   -59,   136,   -59,   136,   -59,   198,
     -59,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,    72,     0,     0,     0,     0,    86,
      87,    85,     0,     0,     0,    82,    83,    84,    69,    60,
       0,    15,     0,    45,     0,     0,     3,     4,     0,    30,
      16,    38,    40,    48,    41,    42,    13,    14,    44,     7,
       8,     9,    10,     0,     0,    94,    77,     0,    97,     0,
      11,    12,    46,     0,    34,     0,    36,    32,    71,     0,
       0,    61,     0,     0,    65,    66,     0,     0,    47,    60,
       0,    54,    56,    57,    33,     1,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,    35,    37,     0,     0,     0,    60,     0,     0,
       0,     0,    60,     0,    73,    98,     0,     0,     0,    63,
       0,    64,     0,    31,    43,     0,     0,    28,    29,    26,
      17,    18,    19,    20,    21,    27,    23,    25,    22,    24,
      39,     0,    49,     0,     0,    51,    92,     0,     0,     0,
      78,    88,     0,    70,     0,    62,    67,    60,    58,    60,
      50,    52,    53,    91,    93,     0,    88,    89,     0,     0,
       0,     0,     0,     0,    74,     0,    68,    55,    59,    60,
      79,    75,    90,     0,    80,     0,    95,     0,    76,     0,
      81,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   112,   -14,    -5,   -59,   -59,   -59,    94,   -59,
     135,   -59,   -59,   -59,   -53,   -59,   -59,    61,   -59,   -58,
     -59,   -16,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,    20,   -59,   -59,   -59,   -59,   -59,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    71,    72,    73,    62,    35,    63,    64,    65,    36,
      59,    37,    47,   141,   171,   175,   103,   156,   174,   177,
      38,   158,    39,    40,    41,   102,   179,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    96,    94,    97,    67,    91,    92,    69,    93,    57,
      98,    95,    76,    70,    61,    66,   115,    43,   109,    74,
      44,     4,   110,    94,    82,    83,    84,     8,     9,    10,
      11,    45,    95,    12,     8,    13,    14,   106,   100,   101,
      46,    15,    16,    17,   134,   148,   152,   110,   110,   139,
      19,   164,    20,   165,    52,   108,    22,   155,   110,    53,
      23,    24,    50,    22,    61,    51,   167,    23,   110,   168,
      58,   110,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   136,   130,    68,   170,   131,
     165,   133,    61,    76,   160,    79,   161,    61,    80,    99,
      81,    82,    83,    84,    85,   145,    54,    56,    86,    87,
      88,    89,     8,     9,    10,    11,   173,   178,    12,   180,
      13,    14,    75,   153,   154,   104,    15,    16,    17,   176,
       4,   110,   112,    60,   111,    19,   140,    20,   116,   159,
     114,    22,    61,   142,    61,    23,    24,    55,    55,   132,
     162,   135,    60,   147,   149,   157,     1,   172,     2,     3,
       4,     5,     6,     7,    61,   181,     8,     9,    10,    11,
      18,   107,    12,   146,    13,    14,   163,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,    18,   143,    19,
       0,    20,     0,    21,     0,    22,     0,     0,     0,    23,
      24,     1,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     9,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,    19,     0,    20,     0,    21,     0,
      22,     0,     0,     0,    23,    24,     8,     9,    10,    11,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    19,
       0,    20,     0,    48,     0,    22,     0,     0,     0,    23,
      24,     8,     9,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    77,    78,     0,
      22,     0,     0,    79,    23,    24,    80,     0,    81,    82,
      83,    84,    85,     0,     0,     0,    86,    87,    88,    89,
       0,    77,    78,     0,     0,     0,     0,    79,     0,   144,
      80,     0,    81,    82,    83,    84,    85,     0,     0,     0,
      86,    87,    88,    89,     0,    77,    78,     0,     0,     0,
      90,    79,     0,     0,    80,     0,    81,    82,    83,    84,
      85,     0,     0,     0,    86,    87,    88,    89,     0,    77,
      78,     0,     0,     0,   105,    79,     0,     0,    80,     0,
      81,    82,    83,    84,    85,     0,     0,     0,    86,    87,
      88,    89,     0,    77,    78,     0,     0,     0,   169,    79,
       0,     0,    80,     0,    81,    82,    83,    84,    85,     0,
       0,     0,    86,    87,    88,    89,    77,    78,     0,     0,
       0,   113,    79,     0,     0,    80,     0,    81,    82,    83,
      84,    85,     0,     0,     0,    86,    87,    88,    89,    77,
      78,     0,     0,     0,   137,    79,     0,     0,    80,     0,
      81,    82,    83,    84,    85,     0,     0,     0,    86,    87,
      88,    89,    77,    78,     0,     0,     0,   138,    79,     0,
       0,    80,     0,    81,    82,    83,    84,    85,     0,     0,
       0,    86,    87,    88,    89,    77,    78,     0,   150,     0,
       0,    79,     0,     0,    80,     0,    81,    82,    83,    84,
      85,     0,     0,     0,    86,    87,    88,    89,    77,    78,
       0,   151,     0,     0,    79,     0,     0,    80,     0,    81,
      82,    83,    84,    85,     0,    77,    78,    86,    87,    88,
      89,    79,   166,     0,    80,     0,    81,    82,    83,    84,
      85,     0,    77,     0,    86,    87,    88,    89,    79,     0,
       0,    80,     0,    81,    82,    83,    84,    85,     0,     0,
       0,    86,    87,    88,    89,    -1,     0,     0,    80,     0,
      81,    82,    83,    84,    -1,     0,     0,     0,    86,    87,
      88,    89,    80,     0,    81,    82,    83,    84,     0,     0,
       0,     0,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
       5,    36,    36,    38,    20,    18,    19,    38,    21,    14,
      45,    45,    26,    44,    19,    20,    69,    38,    37,    24,
      38,     7,    41,    36,    23,    24,    25,    13,    14,    15,
      16,    38,    45,    19,    13,    21,    22,    53,    43,    44,
      46,    27,    28,    29,    97,    39,    39,    41,    41,   102,
      36,    39,    38,    41,    46,    60,    42,    40,    41,    38,
      46,    47,    40,    42,    69,    40,    39,    46,    41,    39,
      35,    41,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    99,    91,    46,    39,    94,
      41,    96,    97,   107,   147,    17,   149,   102,    20,     4,
      22,    23,    24,    25,    26,   110,    12,    13,    30,    31,
      32,    33,    13,    14,    15,    16,   169,   175,    19,   177,
      21,    22,     0,   137,   138,    38,    27,    28,    29,    39,
       7,    41,    41,    34,    37,    36,    38,    38,    46,   144,
      39,    42,   147,    39,   149,    46,    47,    12,    13,    46,
     155,    46,    34,    38,    38,    46,     3,    46,     5,     6,
       7,     8,     9,    10,   169,   179,    13,    14,    15,    16,
      34,    59,    19,   112,    21,    22,   156,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,     3,    -1,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    36,    -1,    38,    -1,    40,    -1,
      42,    -1,    -1,    -1,    46,    47,    13,    14,    15,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,    13,    14,    15,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    11,    12,    -1,
      42,    -1,    -1,    17,    46,    47,    20,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      -1,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    43,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    11,    12,    -1,    -1,    -1,
      40,    17,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    -1,    11,
      12,    -1,    -1,    -1,    40,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    -1,    11,    12,    -1,    -1,    -1,    40,    17,
      -1,    -1,    20,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    11,    12,    -1,    -1,
      -1,    39,    17,    -1,    -1,    20,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    11,
      12,    -1,    -1,    -1,    39,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    11,    12,    -1,    -1,    -1,    39,    17,    -1,
      -1,    20,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    11,    12,    -1,    37,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    11,    12,
      -1,    37,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    -1,    11,    12,    30,    31,    32,
      33,    17,    35,    -1,    20,    -1,    22,    23,    24,    25,
      26,    -1,    11,    -1,    30,    31,    32,    33,    17,    -1,
      -1,    20,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    13,    14,
      15,    16,    19,    21,    22,    27,    28,    29,    34,    36,
      38,    40,    42,    46,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    64,    68,    70,    79,    81,
      82,    83,    86,    38,    38,    38,    46,    71,    40,    53,
      40,    40,    46,    38,    57,    59,    57,    53,    35,    69,
      34,    53,    63,    65,    66,    67,    53,    70,    46,    38,
      44,    60,    61,    62,    53,     0,    52,    11,    12,    17,
      20,    22,    23,    24,    25,    26,    30,    31,    32,    33,
      40,    18,    19,    21,    36,    45,    36,    38,    45,     4,
      53,    53,    84,    75,    38,    40,    70,    51,    53,    37,
      41,    37,    41,    39,    39,    63,    46,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    46,    53,    63,    46,    52,    39,    39,    63,
      38,    72,    39,    35,    43,    53,    66,    38,    39,    38,
      37,    37,    39,    52,    52,    40,    76,    46,    80,    53,
      63,    63,    53,    80,    39,    41,    35,    39,    39,    40,
      39,    73,    46,    63,    77,    74,    39,    78,    68,    85,
      68,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    61,    62,
      63,    63,    63,    64,    64,    65,    66,    66,    67,    69,
      68,    68,    71,    72,    73,    74,    70,    75,    76,    77,
      78,    70,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    81,    81,    82,    84,    85,    83,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     4,     2,     6,     1,     1,     3,     5,
       0,     1,     3,     3,     3,     1,     1,     3,     5,     0,
       4,     2,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    10,     1,     1,     1,     1,     1,     1,     0,     1,
       3,     5,     3,     5,     0,     0,    11,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 45: /* lvalue: ID  */
#line 117 "parser/parser.y"
           {
            if(!(symTable.lookup(*(yyvsp[0].strVal)))){
                if(scope == 0){         
                    symTable.insert(*(yyvsp[0].strVal), "global_variable", scope, yylineno);
                }else{
                    symTable.insert(*(yyvsp[0].strVal), "local_variable", scope, yylineno);
                }
            }else{
                
                if(!symTable.lookup(*(yyvsp[0].strVal),0) &&!symTable.lookup(*(yyvsp[0].strVal), scope) && found_Func) yyerror("Undefined refrence to " + *(yyvsp[0].strVal));
                else if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Variable " + *(yyvsp[0].strVal) + " cannot have the same name as a library function");
                else if(symTable.isFunction(*(yyvsp[0].strVal),scope)){
                        yyerror(*(yyvsp[0].strVal) + " Defined as function");
                }
                
            }
        }
#line 1395 "parser/parser.cpp"
    break;

  case 46: /* lvalue: LOCAL ID  */
#line 134 "parser/parser.y"
               {
        if(scope != 0){
            if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !(hasLibFuncName(*(yyvsp[0].strVal)))){ 
                symTable.insert(*(yyvsp[0].strVal), "local_variable", scope, yylineno);
            }
            else{
                if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Variable " + *(yyvsp[0].strVal) + " cannot have the same name as a library function");
                else yyerror("redefinition of " + *(yyvsp[0].strVal));
            }
        }
        else yyerror("Cannot declare local va riable with scope 0");
    }
#line 1412 "parser/parser.cpp"
    break;

  case 47: /* lvalue: DCOLON ID  */
#line 146 "parser/parser.y"
                { 
                if(!symTable.lookup(*(yyvsp[0].strVal),0)){
                    yyerror("Undefined refrence to " + *(yyvsp[0].strVal));
                }
        }
#line 1422 "parser/parser.cpp"
    break;

  case 69: /* $@1: %empty  */
#line 193 "parser/parser.y"
                    {++scope;}
#line 1428 "parser/parser.cpp"
    break;

  case 70: /* block: LEFT_CBRACKET $@1 stmntlist RIGHT_CBRACKET  */
#line 193 "parser/parser.y"
                                                       {
        symTable.ScopeHide(scope);
        scope--;
    }
#line 1437 "parser/parser.cpp"
    break;

  case 72: /* $@2: %empty  */
#line 200 "parser/parser.y"
                 {  
        string name = "$" + to_string(curr_func);
        symTable.insert(name, "user function", scope, yylineno);
        curr_func++;
    }
#line 1447 "parser/parser.cpp"
    break;

  case 73: /* $@3: %empty  */
#line 204 "parser/parser.y"
                    {++scope;}
#line 1453 "parser/parser.cpp"
    break;

  case 74: /* $@4: %empty  */
#line 204 "parser/parser.y"
                                                     {scope--;}
#line 1459 "parser/parser.cpp"
    break;

  case 75: /* $@5: %empty  */
#line 204 "parser/parser.y"
                                                                {found_Func = true;}
#line 1465 "parser/parser.cpp"
    break;

  case 76: /* funcdef: FUNCTION $@2 LEFT_PARENTHES $@3 idlist RIGHT_PARENTHES $@4 $@5 block  */
#line 204 "parser/parser.y"
                                                                                           { found_Func = false; }
#line 1471 "parser/parser.cpp"
    break;

  case 77: /* $@6: %empty  */
#line 206 "parser/parser.y"
                  {
        bool isInSmtb = true;

        isInSmtb = symTable.lookup(*(yyvsp[0].strVal), scope);

        if(!isInSmtb && !hasLibFuncName(*(yyvsp[0].strVal))) symTable.insert(*(yyvsp[0].strVal), "user function", scope, yylineno);

        if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("user function " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
        else if (isInSmtb) yyerror("redefinition of " + *(yyvsp[0].strVal));
    }
#line 1486 "parser/parser.cpp"
    break;

  case 78: /* $@7: %empty  */
#line 215 "parser/parser.y"
                   {++scope;}
#line 1492 "parser/parser.cpp"
    break;

  case 79: /* $@8: %empty  */
#line 215 "parser/parser.y"
                                                     {scope--;}
#line 1498 "parser/parser.cpp"
    break;

  case 80: /* $@9: %empty  */
#line 215 "parser/parser.y"
                                                                {found_Func = true;}
#line 1504 "parser/parser.cpp"
    break;

  case 81: /* funcdef: FUNCTION ID $@6 LEFT_PARENTHES $@7 idlist RIGHT_PARENTHES $@8 $@9 block  */
#line 215 "parser/parser.y"
                                                                                           { found_Func = false; }
#line 1510 "parser/parser.cpp"
    break;

  case 89: /* idlist: ID  */
#line 227 "parser/parser.y"
         {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 1524 "parser/parser.cpp"
    break;

  case 90: /* idlist: idlist COMMA ID  */
#line 236 "parser/parser.y"
                      {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 1538 "parser/parser.cpp"
    break;

  case 94: /* $@10: %empty  */
#line 254 "parser/parser.y"
                           {++scope;}
#line 1544 "parser/parser.cpp"
    break;

  case 95: /* $@11: %empty  */
#line 254 "parser/parser.y"
                                                                                          {scope--;}
#line 1550 "parser/parser.cpp"
    break;


#line 1554 "parser/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 261 "parser/parser.y"


bool hasLibFuncName(string name){
    string funcs[12] = {"print", "input", "objectmemberkeys", "objecttotalmembers", "objectcopy", "totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin"};
    for(int i = 0; i < 12; i++){
        if(funcs[i] == name) return true;
    }
    return false;
}

int yyerror(string yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
    return 1;
}

int main(int argc, char* argv[]){
     if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file> [output_file]" << endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        cerr << "Error opening input file: " << argv[1] << endl;
        return 1;
    }

    streambuf* backup = cout.rdbuf();
    ofstream file;
    if (argc >= 3) {
        file.open(argv[2]);
        if (!file.is_open()) {
            cerr << "Error opening output file: " << argv[2] << endl;
            return 1;
        }
        cout.rdbuf(file.rdbuf());
    }

    yyparse();
    symTable.display();

    cout.rdbuf(backup); 
    if (file.is_open()) file.close();
    fclose(yyin);

    return 0;
}

