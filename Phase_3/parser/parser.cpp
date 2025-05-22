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
    #include <stack>
    #include <fstream>
    #include <vector>
    #include "../SymTable/SymTable.hpp"
    #include "../quad/quad.hpp"
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
    bool returnSTMT = false;
    ostream *outStream;
    //Helper expr* var to print the curr function name
    expr* curr_func_expr = nullptr; 
    bool hasLibFuncName(string name);
    
    stack<int> breakAvailable;
    stack<int> continueAvailable;

    /*THE VEVTOR OF THE QUADS*/
    vector<quad *> quads;

#line 106 "parser/parser.cpp"

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
  YYSYMBOL_83_10 = 83,                     /* $@10  */
  YYSYMBOL_forstmt = 84,                   /* forstmt  */
  YYSYMBOL_returnstmt = 85,                /* returnstmt  */
  YYSYMBOL_86_11 = 86,                     /* $@11  */
  YYSYMBOL_87_12 = 87                      /* $@12  */
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
#define YYLAST   580

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

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
       0,    72,    72,    73,    76,    77,    80,    81,    82,    83,
      84,    85,    92,    99,   100,   101,   104,   105,   111,   117,
     123,   129,   135,   150,   165,   180,   195,   210,   225,   232,
     239,   242,   243,   251,   259,   269,   278,   288,   297,   300,
     312,   313,   314,   315,   316,   319,   344,   356,   361,   364,
     367,   373,   374,   377,   378,   379,   380,   382,   383,   386,
     389,   392,   393,   394,   397,   398,   401,   404,   405,   408,
     411,   411,   415,   418,   424,   424,   424,   418,   431,   446,
     446,   446,   431,   455,   459,   463,   467,   470,   474,   480,
     481,   490,   501,   502,   505,   505,   514,   517,   518,   520,
     518
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
  "ifstmt", "whilestmt", "$@10", "forstmt", "returnstmt", "$@11", "$@12", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     182,   -36,    -4,    15,   -23,   -13,    39,    55,    52,  -141,
    -141,  -141,   -10,   -10,   288,  -141,  -141,  -141,    58,   253,
     218,  -141,    54,     1,   288,    61,   182,  -141,   316,  -141,
    -141,  -141,    -3,    69,     2,  -141,  -141,  -141,  -141,   115,
    -141,  -141,  -141,   288,   288,   288,  -141,    83,  -141,   288,
    -141,  -141,  -141,   116,   -28,     2,   -28,    26,  -141,   182,
     288,   496,     7,    88,  -141,    85,   364,    89,  -141,   288,
      84,  -141,  -141,  -141,  -141,  -141,  -141,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
    -141,   288,  -141,  -141,   288,    86,   288,   288,   288,    91,
     182,   387,   410,    73,    93,  -141,   496,    90,   137,    79,
    -141,   288,  -141,   100,  -141,    97,   -15,   110,   530,   513,
     547,    26,    26,  -141,  -141,  -141,   547,   -11,   -11,   -11,
     -11,   496,   433,  -141,    17,   456,    18,  -141,  -141,   182,
    -141,   288,  -141,    95,   109,    97,  -141,   288,   496,  -141,
     288,  -141,   288,  -141,  -141,  -141,  -141,  -141,   182,   340,
      95,  -141,    21,  -141,   479,    37,    46,  -141,   288,    47,
    -141,   111,  -141,  -141,  -141,    53,  -141,  -141,  -141,   182,
    -141,   121,  -141,   121,  -141,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,    73,    98,     0,     0,     0,    87,
      88,    86,     0,     0,     0,    83,    84,    85,    70,    61,
       0,    15,     0,    45,     0,     0,     3,     4,     0,    30,
      16,    38,    40,    48,    41,    42,    13,    14,    44,     7,
       8,     9,    10,     0,     0,    61,    78,     0,    97,     0,
      11,    12,    46,     0,    34,     0,    36,    32,    72,     0,
       0,    62,     0,     0,    66,    67,     0,     0,    47,    61,
       0,    55,    57,    58,    33,     1,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     0,    35,    37,     0,     0,    61,     0,    61,     0,
       0,     0,     0,     0,     0,    74,    99,     0,     0,     0,
      64,     0,    65,     0,    31,    43,     0,     0,    28,    29,
      26,    17,    18,    19,    20,    21,    27,    23,    25,    22,
      24,    39,     0,    49,     0,     0,     0,    51,    93,     0,
      94,     0,    79,    89,     0,     0,    71,     0,    63,    68,
      61,    59,    61,    50,    54,    52,    53,    92,     0,     0,
      89,    90,     0,   100,     0,     0,     0,    95,    61,     0,
      75,     0,    69,    56,    60,     0,    80,    76,    91,     0,
      81,     0,    96,     0,    77,    82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,   102,   -19,   -14,  -141,  -141,  -141,   103,  -141,
     105,  -141,  -141,  -141,   -44,  -141,  -141,    49,  -141,  -140,
    -141,   -16,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,     3,  -141,  -141,  -141,  -141,  -141,  -141,  -141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    71,    72,    73,    62,    35,    63,    64,    65,    36,
      59,    37,    47,   143,   177,   181,   104,   160,   180,   183,
      38,   162,    39,    40,   158,    41,    42,    49,   144
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   103,    43,     8,    67,    61,    66,    76,    94,    80,
      74,    81,    82,    83,    84,    91,    92,    95,    93,    -1,
      -1,    -1,    -1,    46,   151,   116,   111,    48,    53,   101,
     102,    61,    22,    94,    44,   106,    23,   107,    97,    69,
      98,   184,    95,   185,   110,    70,   109,    99,   111,    82,
      83,    84,   134,    45,   136,    61,   154,   156,   111,   111,
     170,    75,   171,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   173,   131,   111,    50,
     132,   138,    61,   135,    61,   174,   176,   111,   171,    76,
      77,    78,   179,    58,   111,    51,    79,   148,    52,    80,
      68,    81,    82,    83,    84,    85,   165,    96,   166,    86,
      87,    88,    89,   141,   111,    54,    56,    55,    55,   100,
     157,   105,   147,     4,   175,   112,   113,   159,   115,   145,
     117,   142,   133,   164,    60,   150,    61,   137,    61,   167,
       1,   161,     2,     3,     4,     5,     6,     7,   152,   163,
       8,     9,    10,    11,    61,    18,    12,   178,    13,    14,
     182,   108,   149,   169,    15,    16,    17,     0,     0,     0,
       0,    18,   146,    19,     0,    20,     0,    21,     0,    22,
       0,     0,     0,    23,    24,     1,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     9,    10,    11,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,    18,     0,    19,     0,
      20,     0,    21,     0,    22,     4,     0,     0,    23,    24,
       0,     8,     9,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,    19,     0,    20,     0,     0,     0,
      22,     0,     0,     0,    23,    24,     8,     9,    10,    11,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,    60,     0,    19,
       0,    20,     0,     0,     0,    22,     0,     0,     0,    23,
      24,     8,     9,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    77,    78,     0,
      22,     0,     0,    79,    23,    24,    80,     0,    81,    82,
      83,    84,    85,     0,     0,     0,    86,    87,    88,    89,
       0,    77,    78,     0,     0,     0,    90,    79,     0,     0,
      80,     0,    81,    82,    83,    84,    85,     0,     0,     0,
      86,    87,    88,    89,     0,    77,    78,     0,     0,     0,
     168,    79,     0,     0,    80,     0,    81,    82,    83,    84,
      85,     0,     0,     0,    86,    87,    88,    89,    77,    78,
       0,     0,     0,   114,    79,     0,     0,    80,     0,    81,
      82,    83,    84,    85,     0,     0,     0,    86,    87,    88,
      89,    77,    78,     0,     0,     0,   139,    79,     0,     0,
      80,     0,    81,    82,    83,    84,    85,     0,     0,     0,
      86,    87,    88,    89,    77,    78,     0,     0,     0,   140,
      79,     0,     0,    80,     0,    81,    82,    83,    84,    85,
       0,     0,     0,    86,    87,    88,    89,    77,    78,     0,
     153,     0,     0,    79,     0,     0,    80,     0,    81,    82,
      83,    84,    85,     0,     0,     0,    86,    87,    88,    89,
      77,    78,     0,   155,     0,     0,    79,     0,     0,    80,
       0,    81,    82,    83,    84,    85,     0,    77,    78,    86,
      87,    88,    89,    79,   172,     0,    80,     0,    81,    82,
      83,    84,    85,     0,    77,     0,    86,    87,    88,    89,
      79,     0,     0,    80,     0,    81,    82,    83,    84,    85,
       0,     0,     0,    86,    87,    88,    89,    79,     0,     0,
      80,     0,    81,    82,    83,    84,    85,     0,     0,     0,
      86,    87,    88,    89,    -1,     0,     0,    80,     0,    81,
      82,    83,    84,    -1,     0,     0,     0,    86,    87,    88,
      89
};

static const yytype_int16 yycheck[] =
{
      14,    45,    38,    13,    20,    19,    20,    26,    36,    20,
      24,    22,    23,    24,    25,    18,    19,    45,    21,    30,
      31,    32,    33,    46,    39,    69,    41,    40,    38,    43,
      44,    45,    42,    36,    38,    49,    46,    53,    36,    38,
      38,   181,    45,   183,    37,    44,    60,    45,    41,    23,
      24,    25,    96,    38,    98,    69,    39,    39,    41,    41,
      39,     0,    41,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    39,    91,    41,    40,
      94,   100,    96,    97,    98,    39,    39,    41,    41,   108,
      11,    12,    39,    35,    41,    40,    17,   111,    46,    20,
      46,    22,    23,    24,    25,    26,   150,    38,   152,    30,
      31,    32,    33,    40,    41,    12,    13,    12,    13,     4,
     139,    38,    43,     7,   168,    37,    41,   141,    39,    39,
      46,    38,    46,   147,    34,    38,   150,    46,   152,   158,
       3,    46,     5,     6,     7,     8,     9,    10,    38,    40,
      13,    14,    15,    16,   168,    34,    19,    46,    21,    22,
     179,    59,   113,   160,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    36,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    46,    47,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    -1,
      38,    -1,    40,    -1,    42,     7,    -1,    -1,    46,    47,
      -1,    13,    14,    15,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    13,    14,    15,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,
      -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    13,    14,    15,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    11,    12,    -1,
      42,    -1,    -1,    17,    46,    47,    20,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      -1,    11,    12,    -1,    -1,    -1,    40,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    -1,    11,    12,    -1,    -1,    -1,
      40,    17,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    11,    12,
      -1,    -1,    -1,    39,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    11,    12,    -1,    -1,    -1,    39,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    11,    12,    -1,    -1,    -1,    39,
      17,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    11,    12,    -1,
      37,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      11,    12,    -1,    37,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    26,    -1,    11,    12,    30,
      31,    32,    33,    17,    35,    -1,    20,    -1,    22,    23,
      24,    25,    26,    -1,    11,    -1,    30,    31,    32,    33,
      17,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    13,    14,
      15,    16,    19,    21,    22,    27,    28,    29,    34,    36,
      38,    40,    42,    46,    47,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    64,    68,    70,    79,    81,
      82,    84,    85,    38,    38,    38,    46,    71,    40,    86,
      40,    40,    46,    38,    57,    59,    57,    53,    35,    69,
      34,    53,    63,    65,    66,    67,    53,    70,    46,    38,
      44,    60,    61,    62,    53,     0,    52,    11,    12,    17,
      20,    22,    23,    24,    25,    26,    30,    31,    32,    33,
      40,    18,    19,    21,    36,    45,    38,    36,    38,    45,
       4,    53,    53,    63,    75,    38,    53,    70,    51,    53,
      37,    41,    37,    41,    39,    39,    63,    46,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    46,    63,    53,    63,    46,    52,    39,
      39,    40,    38,    72,    87,    39,    35,    43,    53,    66,
      38,    39,    38,    37,    39,    37,    39,    52,    83,    53,
      76,    46,    80,    40,    53,    63,    63,    52,    40,    80,
      39,    41,    35,    39,    39,    63,    39,    73,    46,    39,
      77,    74,    52,    78,    68,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    59,    60,    60,    61,
      62,    63,    63,    63,    64,    64,    65,    66,    66,    67,
      69,    68,    68,    71,    72,    73,    74,    70,    75,    76,
      77,    78,    70,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    81,    81,    83,    82,    84,    85,    86,    87,
      85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     4,     4,     2,     6,     1,     1,     3,
       5,     0,     1,     3,     3,     3,     1,     1,     3,     5,
       0,     4,     2,     0,     0,     0,     0,     9,     0,     0,
       0,     0,    10,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     5,     3,     0,     6,     9,     2,     0,     0,
       5
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
  case 7: /* stmt: ifstmt  */
#line 81 "parser/parser.y"
            {ressettemp();}
#line 1388 "parser/parser.cpp"
    break;

  case 8: /* stmt: whilestmt  */
#line 82 "parser/parser.y"
               {ressettemp();}
#line 1394 "parser/parser.cpp"
    break;

  case 11: /* stmt: BREAK SEMICOLON  */
#line 85 "parser/parser.y"
                     {
        if(breakAvailable.empty()){
            yyerror("Break not in loop");
        }else{
            emit(jump, nullptr, nullptr, nullptr, breakAvailable.top(), yylineno);
        }
    }
#line 1406 "parser/parser.cpp"
    break;

  case 12: /* stmt: CONTINUE SEMICOLON  */
#line 92 "parser/parser.y"
                        {
         if(continueAvailable.empty()){
            yyerror("Continue not in loop");
        }else{
            emit(jump, nullptr, nullptr, nullptr, breakAvailable.top(), yylineno);
        }
    }
#line 1418 "parser/parser.cpp"
    break;

  case 13: /* stmt: block  */
#line 99 "parser/parser.y"
           {ressettemp();}
#line 1424 "parser/parser.cpp"
    break;

  case 14: /* stmt: funcdef  */
#line 100 "parser/parser.y"
             {ressettemp();}
#line 1430 "parser/parser.cpp"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 105 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(add, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1441 "parser/parser.cpp"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 111 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(sub, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1452 "parser/parser.cpp"
    break;

  case 19: /* expr: expr MULTI expr  */
#line 117 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(mul, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1463 "parser/parser.cpp"
    break;

  case 20: /* expr: expr DIV expr  */
#line 123 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(div_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1474 "parser/parser.cpp"
    break;

  case 21: /* expr: expr MOD expr  */
#line 129 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(mod, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1485 "parser/parser.cpp"
    break;

  case 22: /* expr: expr GREATER expr  */
#line 135 "parser/parser.y"
                       {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_greater, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1505 "parser/parser.cpp"
    break;

  case 23: /* expr: expr GREATER_EQUAL expr  */
#line 150 "parser/parser.y"
                             {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_greatereq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1525 "parser/parser.cpp"
    break;

  case 24: /* expr: expr LESS expr  */
#line 165 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_less, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1545 "parser/parser.cpp"
    break;

  case 25: /* expr: expr LESS_EQUAL expr  */
#line 180 "parser/parser.y"
                          {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_lesseq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1565 "parser/parser.cpp"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 195 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_eq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1585 "parser/parser.cpp"
    break;

  case 27: /* expr: expr NEQUAL expr  */
#line 210 "parser/parser.y"
                      {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* bool_expr1 = NewExpr(constbool_e), *bool_expr2 = NewExpr(constbool_e);
        expr* new_Tmp = newtemp();

        bool_expr1->boolConst = false;

        emit(if_noteq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), nullptr, curr_quad + 3, yylineno);
        emit(assign, bool_expr1, nullptr, new_Tmp, 0, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        bool_expr2->boolConst = true;
        emit(assign, bool_expr2, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1605 "parser/parser.cpp"
    break;

  case 28: /* expr: expr AND expr  */
#line 225 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* new_Tmp = newtemp();
        emit(and_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1617 "parser/parser.cpp"
    break;

  case 29: /* expr: expr OR expr  */
#line 232 "parser/parser.y"
                  {
        (yyval.exprVal) = NewExpr(boolexpr_e);
        expr* new_Tmp = newtemp();
        emit(or_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1629 "parser/parser.cpp"
    break;

  case 30: /* expr: term  */
#line 239 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1635 "parser/parser.cpp"
    break;

  case 31: /* term: LEFT_PARENTHES expr RIGHT_PARENTHES  */
#line 242 "parser/parser.y"
                                          {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1641 "parser/parser.cpp"
    break;

  case 32: /* term: MINUS expr  */
#line 243 "parser/parser.y"
                 {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(uminus, (yyvsp[0].exprVal), nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1654 "parser/parser.cpp"
    break;

  case 33: /* term: NOT expr  */
#line 251 "parser/parser.y"
               {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(not_i, (yyvsp[0].exprVal), nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1667 "parser/parser.cpp"
    break;

  case 34: /* term: UPLUS lvalue  */
#line 259 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(add, (yyvsp[0].exprVal), one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, (yyvsp[0].exprVal), 0, yylineno);

        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
    }
#line 1682 "parser/parser.cpp"
    break;

  case 35: /* term: lvalue UPLUS  */
#line 269 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(assign, new_Tmp, nullptr, (yyvsp[-1].exprVal), 0, yylineno);
        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
        emit(add, (yyvsp[-1].exprVal), one, new_Tmp, 0, yylineno);
    }
#line 1696 "parser/parser.cpp"
    break;

  case 36: /* term: UMINUS lvalue  */
#line 278 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(add, (yyvsp[0].exprVal), one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, (yyvsp[0].exprVal), 0, yylineno);

        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
    }
#line 1711 "parser/parser.cpp"
    break;

  case 37: /* term: lvalue UMINUS  */
#line 288 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(assign, new_Tmp, nullptr, (yyvsp[-1].exprVal), 0, yylineno);
        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
        emit(add, (yyvsp[-1].exprVal), one, new_Tmp, 0, yylineno);
    }
#line 1725 "parser/parser.cpp"
    break;

  case 38: /* term: primary  */
#line 297 "parser/parser.y"
              {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1731 "parser/parser.cpp"
    break;

  case 39: /* assignexpr: lvalue ASSIGN expr  */
#line 300 "parser/parser.y"
                              {
    
    (yyval.exprVal) = NewExpr(var_e);
    if((yyvsp[-2].exprVal)->type == tableitem_e){
        emit(tablesetelem, (yyvsp[0].exprVal), (yyvsp[-2].exprVal)->index, (yyvsp[-2].exprVal), 0, yylineno);
    }else{
        emit(assign, (yyvsp[0].exprVal), nullptr, (yyvsp[-2].exprVal), 0, yylineno);
    }
    (yyval.exprVal) = (yyvsp[-2].exprVal);
}
#line 1746 "parser/parser.cpp"
    break;

  case 40: /* primary: lvalue  */
#line 312 "parser/parser.y"
                {(yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));}
#line 1752 "parser/parser.cpp"
    break;

  case 41: /* primary: call  */
#line 313 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1758 "parser/parser.cpp"
    break;

  case 42: /* primary: objectdef  */
#line 314 "parser/parser.y"
                {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1764 "parser/parser.cpp"
    break;

  case 43: /* primary: LEFT_PARENTHES funcdef RIGHT_PARENTHES  */
#line 315 "parser/parser.y"
                                             {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1770 "parser/parser.cpp"
    break;

  case 44: /* primary: const  */
#line 316 "parser/parser.y"
            {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1776 "parser/parser.cpp"
    break;

  case 45: /* lvalue: ID  */
#line 319 "parser/parser.y"
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
                else if(symTable.isFunction(*(yyvsp[0].strVal),scope) && !returnSTMT){
                        yyerror(*(yyvsp[0].strVal) + " Defined as function");
                }
            }
            
            SymbolEntry* entry = symTable.returnSymbol(*(yyvsp[0].strVal));
            if(!entry){
                yyerror("Undefined Variable: " + *(yyvsp[0].strVal));
                (yyval.exprVal) = nullptr;
            } else {
                (yyval.exprVal) = NewExpr(var_e);  
                (yyval.exprVal)->sym = entry;
            }
        }
#line 1806 "parser/parser.cpp"
    break;

  case 46: /* lvalue: LOCAL ID  */
#line 344 "parser/parser.y"
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
#line 1823 "parser/parser.cpp"
    break;

  case 47: /* lvalue: DCOLON ID  */
#line 356 "parser/parser.y"
                { 
                if(!symTable.lookup(*(yyvsp[0].strVal),0)){
                    yyerror("Undefined refrence to " + *(yyvsp[0].strVal));
                }
        }
#line 1833 "parser/parser.cpp"
    break;

  case 48: /* lvalue: member  */
#line 361 "parser/parser.y"
            { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1839 "parser/parser.cpp"
    break;

  case 49: /* member: lvalue DOT ID  */
#line 364 "parser/parser.y"
                     {
        (yyval.exprVal) = member_item ((yyvsp[-2].exprVal),*(yyvsp[0].strVal));
}
#line 1847 "parser/parser.cpp"
    break;

  case 50: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 367 "parser/parser.y"
                                            {
        (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal));
        (yyval.exprVal) = NewExpr(tableitem_e);
        (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
        (yyval.exprVal)->index = (yyvsp[-1].exprVal);
    }
#line 1858 "parser/parser.cpp"
    break;

  case 55: /* call: ID callsuffix  */
#line 379 "parser/parser.y"
                   { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1864 "parser/parser.cpp"
    break;

  case 57: /* callsuffix: normcall  */
#line 382 "parser/parser.y"
                     { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1870 "parser/parser.cpp"
    break;

  case 58: /* callsuffix: methodcall  */
#line 383 "parser/parser.y"
                { (yyval.exprVal) = (yyvsp[0].exprVal); }
#line 1876 "parser/parser.cpp"
    break;

  case 59: /* normcall: LEFT_PARENTHES elist RIGHT_PARENTHES  */
#line 386 "parser/parser.y"
                                              { (yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1882 "parser/parser.cpp"
    break;

  case 62: /* elist: expr  */
#line 393 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1888 "parser/parser.cpp"
    break;

  case 70: /* $@1: %empty  */
#line 411 "parser/parser.y"
                    {++scope;}
#line 1894 "parser/parser.cpp"
    break;

  case 71: /* block: LEFT_CBRACKET $@1 stmntlist RIGHT_CBRACKET  */
#line 411 "parser/parser.y"
                                                       {
        symTable.ScopeHide(scope);
        scope--;
    }
#line 1903 "parser/parser.cpp"
    break;

  case 73: /* $@2: %empty  */
#line 418 "parser/parser.y"
                 {  
        string name = "$" + to_string(curr_func);
        symTable.insert(name, "user function", scope, yylineno);
        curr_func++;
        emit(funcstart, nullptr, nullptr, NewExpr(programfunc_e), 0, yylineno);

        }
#line 1915 "parser/parser.cpp"
    break;

  case 74: /* $@3: %empty  */
#line 424 "parser/parser.y"
                        {++scope;}
#line 1921 "parser/parser.cpp"
    break;

  case 75: /* $@4: %empty  */
#line 424 "parser/parser.y"
                                                         {scope--;}
#line 1927 "parser/parser.cpp"
    break;

  case 76: /* $@5: %empty  */
#line 424 "parser/parser.y"
                                                                    {found_Func = true;}
#line 1933 "parser/parser.cpp"
    break;

  case 77: /* funcdef: FUNCTION $@2 LEFT_PARENTHES $@3 idlist RIGHT_PARENTHES $@4 $@5 block  */
#line 424 "parser/parser.y"
                                                                                               {
            found_Func = false; 
            (yyval.exprVal) = NewExpr(programfunc_e);
            (yyval.exprVal)->sym = symTable.returnSymbol("$" + to_string(curr_func - 1));
            emit(funcend, nullptr, nullptr, (yyval.exprVal), 0, yylineno);
        }
#line 1944 "parser/parser.cpp"
    break;

  case 78: /* $@6: %empty  */
#line 431 "parser/parser.y"
                  {
        bool isInSmtb = true;

        isInSmtb = symTable.lookup(*(yyvsp[0].strVal), scope);

        if(!isInSmtb && !hasLibFuncName(*(yyvsp[0].strVal))) {
            symTable.insert(*(yyvsp[0].strVal), "user function", scope, yylineno);
            curr_func_expr = NewExpr(programfunc_e);
            curr_func_expr->sym = symTable.returnSymbol(*(yyvsp[0].strVal));
            emit(funcstart, nullptr, nullptr, curr_func_expr, 0, yylineno);
        }
        if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("user function " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
        else if (isInSmtb) yyerror("redefinition of " + *(yyvsp[0].strVal));


    }
#line 1965 "parser/parser.cpp"
    break;

  case 79: /* $@7: %empty  */
#line 446 "parser/parser.y"
                   {++scope;}
#line 1971 "parser/parser.cpp"
    break;

  case 80: /* $@8: %empty  */
#line 446 "parser/parser.y"
                                                     {scope--;}
#line 1977 "parser/parser.cpp"
    break;

  case 81: /* $@9: %empty  */
#line 446 "parser/parser.y"
                                                                {found_Func = true;}
#line 1983 "parser/parser.cpp"
    break;

  case 82: /* funcdef: FUNCTION ID $@6 LEFT_PARENTHES $@7 idlist RIGHT_PARENTHES $@8 $@9 block  */
#line 446 "parser/parser.y"
                                                                                           { found_Func = false;
      if(curr_func_expr != nullptr){
            emit(funcend, nullptr, nullptr, curr_func_expr, 0, yylineno);
            (yyval.exprVal) = curr_func_expr;
            curr_func_expr = nullptr;  
        }
     }
#line 1995 "parser/parser.cpp"
    break;

  case 83: /* const: INTCONST  */
#line 455 "parser/parser.y"
                {
        (yyval.exprVal) = NewExpr(constnum_e);
        (yyval.exprVal)->numConst = (yyvsp[0].intVal);
    }
#line 2004 "parser/parser.cpp"
    break;

  case 84: /* const: REAL  */
#line 459 "parser/parser.y"
          {
        (yyval.exprVal) = NewExpr(constnum_e);
        (yyval.exprVal)->numConst = (yyvsp[0].realVal);
    }
#line 2013 "parser/parser.cpp"
    break;

  case 85: /* const: STRING  */
#line 463 "parser/parser.y"
            {
        (yyval.exprVal) = NewExpr(conststring_e);
        (yyval.exprVal)->strConst = *(yyvsp[0].strVal);
    }
#line 2022 "parser/parser.cpp"
    break;

  case 86: /* const: NIL  */
#line 467 "parser/parser.y"
         {
        (yyval.exprVal) = NewExpr(nil_e);
    }
#line 2030 "parser/parser.cpp"
    break;

  case 87: /* const: TRUE  */
#line 470 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(constbool_e);
        (yyval.exprVal)->boolConst = true;
    }
#line 2039 "parser/parser.cpp"
    break;

  case 88: /* const: FALSE  */
#line 474 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(constbool_e);
        (yyval.exprVal)->boolConst = false;
    }
#line 2048 "parser/parser.cpp"
    break;

  case 90: /* idlist: ID  */
#line 481 "parser/parser.y"
         {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 2062 "parser/parser.cpp"
    break;

  case 91: /* idlist: idlist COMMA ID  */
#line 490 "parser/parser.y"
                      {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 2076 "parser/parser.cpp"
    break;

  case 94: /* $@10: %empty  */
#line 505 "parser/parser.y"
                                                    {
            breakAvailable.push(curr_quad);
            continueAvailable.push(curr_quad);
    }
#line 2085 "parser/parser.cpp"
    break;

  case 95: /* whilestmt: WHILE LEFT_PARENTHES expr RIGHT_PARENTHES $@10 stmt  */
#line 508 "parser/parser.y"
          {
            breakAvailable.pop();
            continueAvailable.pop();
    }
#line 2094 "parser/parser.cpp"
    break;

  case 98: /* $@11: %empty  */
#line 518 "parser/parser.y"
            {
        returnSTMT = 1;
    }
#line 2102 "parser/parser.cpp"
    break;

  case 99: /* $@12: %empty  */
#line 520 "parser/parser.y"
          {
        returnSTMT = 0;
    }
#line 2110 "parser/parser.cpp"
    break;


#line 2114 "parser/parser.cpp"

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

#line 525 "parser/parser.y"


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
    printQuads();

    cout.rdbuf(backup); 
    if (file.is_open()) file.close();
    fclose(yyin);

    return 0;
}

