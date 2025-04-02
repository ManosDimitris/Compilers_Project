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


#line 90 "parser.tab.c"

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
    KEYWORD = 258,                 /* KEYWORD  */
    OPERATOR = 259,                /* OPERATOR  */
    INTCONST = 260,                /* INTCONST  */
    REAL = 261,                    /* REAL  */
    STRING = 262,                  /* STRING  */
    PUNCTUATION = 263,             /* PUNCTUATION  */
    ID = 264,                      /* ID  */
    NOT = 279,                     /* NOT  */
    UOP = 280,                     /* UOP  */
    NEGATIVE = 281,                /* NEGATIVE  */
    BRACKETS = 284,                /* BRACKETS  */
    PARENTHESIS = 285              /* PARENTHESIS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    std::string *strVal;
    int intVal;
    double realVal;

#line 157 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KEYWORD = 3,                    /* KEYWORD  */
  YYSYMBOL_OPERATOR = 4,                   /* OPERATOR  */
  YYSYMBOL_INTCONST = 5,                   /* INTCONST  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_PUNCTUATION = 8,                /* PUNCTUATION  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_10_ = 10,                       /* "="  */
  YYSYMBOL_11_or_ = 11,                    /* "or"  */
  YYSYMBOL_12_and_ = 12,                   /* "and"  */
  YYSYMBOL_13_ = 13,                       /* "=="  */
  YYSYMBOL_14_ = 14,                       /* "!="  */
  YYSYMBOL_15_ = 15,                       /* ">"  */
  YYSYMBOL_16_ = 16,                       /* ">="  */
  YYSYMBOL_17_ = 17,                       /* "<"  */
  YYSYMBOL_18_ = 18,                       /* "<="  */
  YYSYMBOL_19_ = 19,                       /* "+"  */
  YYSYMBOL_20_ = 20,                       /* "-"  */
  YYSYMBOL_21_ = 21,                       /* "*"  */
  YYSYMBOL_22_ = 22,                       /* "/"  */
  YYSYMBOL_23_ = 23,                       /* "%"  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_UOP = 25,                       /* UOP  */
  YYSYMBOL_NEGATIVE = 26,                  /* NEGATIVE  */
  YYSYMBOL_27_ = 27,                       /* "."  */
  YYSYMBOL_28_ = 28,                       /* ".."  */
  YYSYMBOL_BRACKETS = 29,                  /* BRACKETS  */
  YYSYMBOL_PARENTHESIS = 30,               /* PARENTHESIS  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_stmt = 33,                      /* stmt  */
  YYSYMBOL_expr = 34,                      /* expr  */
  YYSYMBOL_op = 35,                        /* op  */
  YYSYMBOL_term = 36,                      /* term  */
  YYSYMBOL_assignexpr = 37,                /* assignexpr  */
  YYSYMBOL_primary = 38,                   /* primary  */
  YYSYMBOL_lvalue = 39,                    /* lvalue  */
  YYSYMBOL_member = 40,                    /* member  */
  YYSYMBOL_call = 41,                      /* call  */
  YYSYMBOL_callsuffix = 42,                /* callsuffix  */
  YYSYMBOL_normcall = 43,                  /* normcall  */
  YYSYMBOL_methodcall = 44,                /* methodcall  */
  YYSYMBOL_elist = 45,                     /* elist  */
  YYSYMBOL_objectdef = 46,                 /* objectdef  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_stmtlist = 48,                  /* stmtlist  */
  YYSYMBOL_funcdef = 49,                   /* funcdef  */
  YYSYMBOL_const = 50,                     /* const  */
  YYSYMBOL_idlist = 51,                    /* idlist  */
  YYSYMBOL_ifstmt = 52,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 53,                 /* whilestmt  */
  YYSYMBOL_forstmt = 54,                   /* forstmt  */
  YYSYMBOL_returnstmt = 55                 /* returnstmt  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    61,    64,    67,    68,    69,    70,    71,
      81,    82,    83,    86,    87,    88,    91,   106,   113,   117,
     120,   123,   126,   129,   132,   135,   136,   137,   138,   142,
     145,   146,   149,   152,   155,   158,   162,   165,   171,   175,
     176,   182,   183,   186,   192,   198,   199,   200,   205,   209,
     229,   232,   233,   234,   237,   241,   247,   250,   251,   252,
     255,   256,   257,   260,   264,   270,   276,   283,   287
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
  "\"end of file\"", "error", "\"invalid token\"", "KEYWORD", "OPERATOR",
  "INTCONST", "REAL", "STRING", "PUNCTUATION", "ID", "\"=\"", "\"or\"",
  "\"and\"", "\"==\"", "\"!=\"", "\">\"", "\">=\"", "\"<\"", "\"<=\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "NOT", "UOP", "NEGATIVE",
  "\".\"", "\"..\"", "BRACKETS", "PARENTHESIS", "$accept", "program",
  "stmt", "expr", "op", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elist",
  "objectdef", "block", "stmtlist", "funcdef", "const", "idlist", "ifstmt",
  "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,     0,     1,   -81,   -81,   -81,   -81,    98,   -81,
     -81,   -81,   -81,   -81,   -20,   -81,   -80,   -81,     7,   -81,
      41,   -81,   -81,   -81,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,    36,    10,    46,    11,    12,    13,    14,    15,
      16,    49,    50,    51,    38,    17,    18,    39,    19,    20,
      60,    21,    22,    23,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
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

static const yytype_int8 yycheck[] =
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    34,    34,    34,    35,    35,    36,    36,
      36,    36,    36,    36,    37,    38,    38,    38,    38,    38,
      39,    39,    39,    39,    40,    40,    40,    40,    41,    41,
      41,    42,    42,    43,    44,    45,    45,    45,    46,    46,
      47,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      51,    51,    51,    52,    52,    53,    54,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     2,
       2,     2,     2,     1,     3,     1,     1,     1,     3,     1,
       1,     2,     2,     1,     3,     4,     3,     4,     4,     2,
       6,     1,     1,     3,     5,     0,     1,     3,     2,     3,
       3,     0,     1,     2,     5,     6,     1,     1,     1,     1,
       0,     1,     3,     5,     7,     5,     9,     2,     3
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
  case 4: /* stmt: expr PUNCTUATION  */
#line 64 "parser.y"
                         { 
        if(*(yyvsp[0].strVal) != ";") yyerror("Line not finished with ;"); YYERROR;
    }
#line 1282 "parser.tab.c"
    break;

  case 9: /* stmt: KEYWORD PUNCTUATION  */
#line 71 "parser.y"
                          {
        if(*(yyvsp[0].strVal) != ";") yyerror("Line not finished with ;"); YYERROR;

        if(*(yyvsp[-1].strVal) == "break") cout << "Found break statement" << endl;
        else if(*(yyvsp[-1].strVal) == "continue") cout << "Found continue statement" << endl;
        else{
            yyerror("Invalid statement");
            YYERROR;
        }
    }
#line 1297 "parser.tab.c"
    break;

  case 12: /* stmt: PUNCTUATION  */
#line 83 "parser.y"
                  {if(*(yyvsp[0].strVal) != ";") yyerror("INVALID PUNCTUATION"); YYERROR;}
#line 1303 "parser.tab.c"
    break;

  case 16: /* op: OPERATOR  */
#line 91 "parser.y"
             {
        string validOps[11] = {"+", "-", "/", "*", "%", ">", ">=", "<", "<=", "==", "!="};
        bool found = false;
        for (const string& op : validOps) {
            if (*(yyvsp[0].strVal) == op) {
                found = true;
                (yyval.strVal) = new string(op);
                break;
            }
        }
        if (!found) {
            yyerror("Invalid operator");
            YYERROR;
        }
    }
#line 1323 "parser.tab.c"
    break;

  case 17: /* op: KEYWORD  */
#line 106 "parser.y"
              {
        if(*(yyvsp[0].strVal) != "or") (yyval.strVal) = new string("or");
        else if(*(yyvsp[0].strVal) != "and") (yyval.strVal) = new string("and");
        else yyerror("Invalid operator"); YYERROR;
    }
#line 1333 "parser.tab.c"
    break;

  case 18: /* term: PUNCTUATION expr PUNCTUATION  */
#line 113 "parser.y"
                                  {
        if(*(yyvsp[-2].strVal) != "(") yyerror("Term does not begin with ("); YYERROR;
        if(*(yyvsp[0].strVal) != ")") yyerror("Term does not end with )"); YYERROR;
    }
#line 1342 "parser.tab.c"
    break;

  case 19: /* term: OPERATOR expr  */
#line 117 "parser.y"
                   {
        if(*(yyvsp[-1].strVal) != "-") yyerror("Term cannot does not begin -"); YYERROR;
    }
#line 1350 "parser.tab.c"
    break;

  case 20: /* term: KEYWORD expr  */
#line 120 "parser.y"
                  {
        if(*(yyvsp[-1].strVal) != "not") yyerror("Term does not begin with not"); YYERROR;
    }
#line 1358 "parser.tab.c"
    break;

  case 21: /* term: OPERATOR lvalue  */
#line 123 "parser.y"
                     {
        if(*(yyvsp[-1].strVal) != "++" || *(yyvsp[-1].strVal) != "--") yyerror("Term must begin with \"++\" or \"--\""); YYERROR;
    }
#line 1366 "parser.tab.c"
    break;

  case 22: /* term: lvalue OPERATOR  */
#line 126 "parser.y"
                     {
        if(*(yyvsp[0].strVal) != "++" || *(yyvsp[0].strVal) != "--") yyerror("Term must end with \"++\" or \"--\""); YYERROR;
    }
#line 1374 "parser.tab.c"
    break;

  case 24: /* assignexpr: lvalue OPERATOR expr  */
#line 132 "parser.y"
                                 {if(*(yyvsp[-1].strVal) != "=") yyerror("Operator must be \"=\" in assignment expressions"); YYERROR;}
#line 1380 "parser.tab.c"
    break;

  case 28: /* primary: OPERATOR funcdef OPERATOR  */
#line 138 "parser.y"
                               {
        if(*(yyvsp[-2].strVal) != "(") yyerror("primary does not begin with ("); YYERROR;
        if(*(yyvsp[0].strVal) != ")") yyerror("primary does not end with )"); YYERROR;
    }
#line 1389 "parser.tab.c"
    break;

  case 31: /* lvalue: KEYWORD ID  */
#line 146 "parser.y"
                {
        if(*(yyvsp[-1].strVal) != "local") yyerror("lvalue does not begin with keyword \"local\""); YYERROR;
    }
#line 1397 "parser.tab.c"
    break;

  case 32: /* lvalue: PUNCTUATION ID  */
#line 149 "parser.y"
                     {
        if(*(yyvsp[-1].strVal) != "::") yyerror("lvalue does not begin with punctuation \"::\""); YYERROR;
    }
#line 1405 "parser.tab.c"
    break;

  case 34: /* member: lvalue PUNCTUATION ID  */
#line 155 "parser.y"
                             {
        if(*(yyvsp[-1].strVal) != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
#line 1413 "parser.tab.c"
    break;

  case 35: /* member: lvalue PUNCTUATION expr PUNCTUATION  */
#line 158 "parser.y"
                                         {
        if(*(yyvsp[-2].strVal) != "[") yyerror("member can only contain ["); YYERROR;
        if(*(yyvsp[0].strVal) != "]") yyerror("member can only contain ]"); YYERROR;
    }
#line 1422 "parser.tab.c"
    break;

  case 36: /* member: call PUNCTUATION ID  */
#line 162 "parser.y"
                         {
        if(*(yyvsp[-1].strVal) != ".") yyerror("punctuation in member must be \".\""); YYERROR;
    }
#line 1430 "parser.tab.c"
    break;

  case 37: /* member: call PUNCTUATION expr PUNCTUATION  */
#line 165 "parser.y"
                                       {
        if(*(yyvsp[-2].strVal) != "[") yyerror("member can only contain ["); YYERROR;
        if(*(yyvsp[0].strVal) != "]") yyerror("member can only contain ]"); YYERROR; 
    }
#line 1439 "parser.tab.c"
    break;

  case 38: /* call: call PUNCTUATION elist PUNCTUATION  */
#line 171 "parser.y"
                                        {
        if(*(yyvsp[-2].strVal) != "(") yyerror("Invalid punctuation"); YYERROR;
        if(*(yyvsp[0].strVal) != ")") yyerror("Invalid punctuation"); YYERROR;
    }
#line 1448 "parser.tab.c"
    break;

  case 40: /* call: PUNCTUATION funcdef PUNCTUATION PUNCTUATION elist PUNCTUATION  */
#line 176 "parser.y"
                                                                   {
        if(*(yyvsp[-5].strVal) != "(" || *(yyvsp[-3].strVal) != ")") yyerror("Invalid call must be \"( function )\""); YYERROR;
        if(*(yyvsp[-2].strVal) != "(" || *(yyvsp[0].strVal) != ")") yyerror("Invalid call must be \"( function ) ( expr )\""); YYERROR;
    }
#line 1457 "parser.tab.c"
    break;

  case 43: /* normcall: PUNCTUATION elist PUNCTUATION  */
#line 186 "parser.y"
                                        {
        if(*(yyvsp[-2].strVal) != "(") yyerror("normcall must begin with ("); YYERROR;
        if(*(yyvsp[0].strVal) != ")") yyerror("normcall must end with )"); YYERROR; 
    }
#line 1466 "parser.tab.c"
    break;

  case 44: /* methodcall: PUNCTUATION ID PUNCTUATION elist PUNCTUATION  */
#line 192 "parser.y"
                                                         {
        if(*(yyvsp[-4].strVal) != "..") yyerror("methodcall must begin with \"..\""); YYERROR;
        if(*(yyvsp[-2].strVal) != "(" || *(yyvsp[0].strVal) != ")") yyerror("Invalid methodcall must be like \"..id(elist)\""); YYERROR;
    }
#line 1475 "parser.tab.c"
    break;

  case 47: /* elist: elist PUNCTUATION expr  */
#line 200 "parser.y"
                            {
        if(*(yyvsp[-1].strVal) != ",") yyerror("Invalid punctuation in elist"); YYERROR; 
    }
#line 1483 "parser.tab.c"
    break;

  case 48: /* objectdef: PUNCTUATION PUNCTUATION  */
#line 205 "parser.y"
                                  {
        if(*(yyvsp[-1].strVal) != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*(yyvsp[0].strVal) != "]") yyerror("objectdef must end with ]"); YYERROR;
    }
#line 1492 "parser.tab.c"
    break;

  case 49: /* objectdef: PUNCTUATION elist PUNCTUATION  */
#line 209 "parser.y"
                                   {
        if(*(yyvsp[-2].strVal) != "[") yyerror("objectdef must begin with ["); YYERROR;
        if(*(yyvsp[0].strVal) != "]") yyerror("objectdef must end with ]"); YYERROR;
    }
#line 1501 "parser.tab.c"
    break;

  case 50: /* block: PUNCTUATION stmtlist PUNCTUATION  */
#line 229 "parser.y"
                                        {if(*(yyvsp[-2].strVal) != "{" || *(yyvsp[0].strVal) != "}") yyerror("wrong punctuation in block"); YYERROR;}
#line 1507 "parser.tab.c"
    break;

  case 54: /* funcdef: KEYWORD PUNCTUATION idlist PUNCTUATION block  */
#line 237 "parser.y"
                                                      {
        if(*(yyvsp[-4].strVal) != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*(yyvsp[-3].strVal) != "(" || *(yyvsp[-1].strVal) != ")") yyerror("function must have (params)"); YYERROR;
    }
#line 1516 "parser.tab.c"
    break;

  case 55: /* funcdef: KEYWORD ID PUNCTUATION idlist PUNCTUATION block  */
#line 241 "parser.y"
                                                      {
        if(*(yyvsp[-5].strVal) != "function") yyerror("Invalid keyword in funcdef"); YYERROR;
        if(*(yyvsp[-3].strVal) != "(" || *(yyvsp[-1].strVal) != ")") yyerror("function must have (params)"); YYERROR;
    }
#line 1525 "parser.tab.c"
    break;

  case 56: /* const: KEYWORD  */
#line 247 "parser.y"
              {
    if(*(yyvsp[0].strVal) != "true" || *(yyvsp[0].strVal) != "false" || *(yyvsp[0].strVal) != "nil") yyerror("not a valid value"); YYERROR;
    }
#line 1533 "parser.tab.c"
    break;

  case 62: /* idlist: idlist PUNCTUATION ID  */
#line 257 "parser.y"
                            {if(*(yyvsp[-1].strVal) != ",") yyerror("Wrong punctuation in idlist"); YYERROR;}
#line 1539 "parser.tab.c"
    break;

  case 63: /* ifstmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt  */
#line 260 "parser.y"
                                                  {
        if(*(yyvsp[-4].strVal) != "if") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*(yyvsp[-3].strVal) != "(" || *(yyvsp[-1].strVal) != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR;
    }
#line 1548 "parser.tab.c"
    break;

  case 64: /* ifstmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt KEYWORD stmt  */
#line 264 "parser.y"
                                                            {
        if(*(yyvsp[-6].strVal) != "if" || *(yyvsp[-1].strVal) != "else") yyerror("Invalid keyword in ifstmt"); YYERROR;
        if(*(yyvsp[-5].strVal) != "(" || *(yyvsp[-3].strVal) != ")") yyerror("Invalid punctuation in ifstmt"); YYERROR; 
    }
#line 1557 "parser.tab.c"
    break;

  case 65: /* whilestmt: KEYWORD PUNCTUATION expr PUNCTUATION stmt  */
#line 270 "parser.y"
                                                     {
        if(*(yyvsp[-4].strVal) != "while") yyerror("Invalid keyword in whilestmt"); YYERROR;
        if(*(yyvsp[-3].strVal) != "(" || *(yyvsp[-1].strVal) != ")") yyerror("Invalid punctuation in whilestmt"); YYERROR; 
    }
#line 1566 "parser.tab.c"
    break;

  case 66: /* forstmt: KEYWORD PUNCTUATION elist PUNCTUATION expr PUNCTUATION elist PUNCTUATION stmt  */
#line 276 "parser.y"
                                                                                      {
    if(*(yyvsp[-8].strVal) != "for") yyerror("Invalid keyword in forstmt"); YYERROR;
    if(*(yyvsp[-7].strVal) != "(" || *(yyvsp[-1].strVal) != ")") yyerror("forstmt does not contain ()"); YYERROR;
    if(*(yyvsp[-5].strVal) != ";" || *(yyvsp[-3].strVal) != ";") yyerror("forstmt must be like for(elist; expr; elist) mprokoloko"); YYERROR;
}
#line 1576 "parser.tab.c"
    break;

  case 67: /* returnstmt: KEYWORD PUNCTUATION  */
#line 283 "parser.y"
                                {
        if(*(yyvsp[-1].strVal) != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*(yyvsp[0].strVal) != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    }
#line 1585 "parser.tab.c"
    break;

  case 68: /* returnstmt: KEYWORD expr PUNCTUATION  */
#line 287 "parser.y"
                              {
        if(*(yyvsp[-2].strVal) != "return") yyerror("Den les return sto returnstmt"); YYERROR;
        if(*(yyvsp[0].strVal) != ";") yyerror("Den exeis balei ; meta to return"); YYERROR;
    char *yaccProvidedMessage}
#line 1594 "parser.tab.c"
    break;


#line 1598 "parser.tab.c"

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

#line 292 "parser.y"


yyerror(char *yaccProvidedMessage){
    cout << yaccProvidedMessage << " at line " << yylineno << endl;
}

int main(){
    yyparse();
    return 0;
}

