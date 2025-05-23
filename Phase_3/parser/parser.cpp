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
    int curr_func = 1, loopCount = 0;
    bool returnSTMT = false;
    ostream *outStream;
    //Helper expr* var to print the curr function name
    expr* curr_func_expr = nullptr; 
    bool hasLibFuncName(string name);
    
    struct LoopContext {
        std::list<unsigned int> breakList;
        std::list<unsigned int> continueList;
    };
    stack<LoopContext> loopStack;

    /*THE VEVTOR OF THE QUADS*/
    vector<quad *> quads;

#line 109 "parser/parser.cpp"

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
  YYSYMBOL_54_1 = 54,                      /* @1  */
  YYSYMBOL_55_2 = 55,                      /* @2  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_assignexpr = 57,                /* assignexpr  */
  YYSYMBOL_primary = 58,                   /* primary  */
  YYSYMBOL_lvalue = 59,                    /* lvalue  */
  YYSYMBOL_member = 60,                    /* member  */
  YYSYMBOL_call = 61,                      /* call  */
  YYSYMBOL_callsuffix = 62,                /* callsuffix  */
  YYSYMBOL_normcall = 63,                  /* normcall  */
  YYSYMBOL_elist = 64,                     /* elist  */
  YYSYMBOL_objectdef = 65,                 /* objectdef  */
  YYSYMBOL_indexed = 66,                   /* indexed  */
  YYSYMBOL_indexedelemlist = 67,           /* indexedelemlist  */
  YYSYMBOL_indexedelem = 68,               /* indexedelem  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_70_3 = 70,                      /* $@3  */
  YYSYMBOL_funcdef = 71,                   /* funcdef  */
  YYSYMBOL_72_4 = 72,                      /* $@4  */
  YYSYMBOL_73_5 = 73,                      /* $@5  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_75_7 = 75,                      /* $@7  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_78_10 = 78,                     /* $@10  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_const = 80,                     /* const  */
  YYSYMBOL_idlist = 81,                    /* idlist  */
  YYSYMBOL_ifstmt = 82,                    /* ifstmt  */
  YYSYMBOL_83_12 = 83,                     /* $@12  */
  YYSYMBOL_ifprefix = 84,                  /* ifprefix  */
  YYSYMBOL_whilestmt = 85,                 /* whilestmt  */
  YYSYMBOL_86_13 = 86,                     /* @13  */
  YYSYMBOL_87_14 = 87,                     /* @14  */
  YYSYMBOL_forstmt = 88,                   /* forstmt  */
  YYSYMBOL_89_15 = 89,                     /* @15  */
  YYSYMBOL_90_16 = 90,                     /* @16  */
  YYSYMBOL_91_17 = 91,                     /* @17  */
  YYSYMBOL_92_18 = 92,                     /* @18  */
  YYSYMBOL_returnstmt = 93,                /* returnstmt  */
  YYSYMBOL_94_19 = 94,                     /* $@19  */
  YYSYMBOL_95_20 = 95                      /* $@20  */
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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   583

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
       0,    77,    77,    78,    81,    82,    85,    86,    87,    88,
      89,    90,    98,   106,   107,   108,   111,   112,   118,   124,
     130,   136,   142,   157,   172,   187,   202,   217,   232,   232,
     252,   252,   272,   275,   276,   284,   292,   302,   311,   321,
     330,   333,   345,   346,   347,   348,   349,   352,   377,   389,
     394,   397,   400,   406,   407,   410,   418,   437,   438,   457,
     465,   467,   471,   490,   491,   495,   505,   506,   509,   512,
     513,   516,   519,   519,   523,   526,   534,   534,   534,   526,
     541,   556,   556,   556,   541,   565,   569,   573,   577,   580,
     584,   590,   591,   600,   611,   615,   615,   624,   636,   636,
     636,   650,   650,   657,   657,   650,   667,   668,   670,   668
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
  "expr", "@1", "@2", "term", "assignexpr", "primary", "lvalue", "member",
  "call", "callsuffix", "normcall", "elist", "objectdef", "indexed",
  "indexedelemlist", "indexedelem", "block", "$@3", "funcdef", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "const", "idlist",
  "ifstmt", "$@12", "ifprefix", "whilestmt", "@13", "@14", "forstmt",
  "@15", "@16", "@17", "@18", "returnstmt", "$@19", "$@20", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     197,    -8,  -160,    -4,     3,    20,    25,    43,    42,  -160,
    -160,  -160,    -6,    -6,   267,  -160,  -160,  -160,    52,   232,
     104,  -160,    44,    46,    51,   267,    93,   197,  -160,   319,
    -160,  -160,  -160,    -1,    56,   -26,  -160,  -160,  -160,  -160,
      91,   197,  -160,  -160,  -160,   267,    58,   267,  -160,    60,
    -160,   267,  -160,  -160,  -160,    92,   -23,   -26,   -23,    22,
    -160,   197,   267,   499,   -13,    64,  -160,    61,   367,    65,
    -160,    51,   267,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,  -160,   267,  -160,  -160,   267,    57,    59,   267,   267,
      63,  -160,  -160,  -160,   390,   267,   -32,    68,  -160,   499,
      71,   152,   295,  -160,   267,  -160,    78,  -160,    51,  -160,
     -12,   267,   267,   533,    22,    22,  -160,  -160,  -160,   533,
      31,    31,    31,    31,   499,   436,    51,  -160,    18,   459,
    -160,   197,  -160,   413,  -160,  -160,    67,    74,    51,  -160,
     267,   499,  -160,  -160,  -160,   550,   516,  -160,  -160,  -160,
    -160,  -160,  -160,   267,    67,  -160,    38,  -160,   482,   197,
     343,    41,  -160,    75,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,    88,   267,    88,  -160,    83,  -160,    89,   197,
    -160
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    98,     0,    75,   107,     0,     0,     0,    89,
      90,    88,     0,     0,     0,    85,    86,    87,    72,    63,
       0,    15,     0,     0,    47,     0,     0,     3,     4,     0,
      32,    16,    40,    42,    50,    43,    44,    13,    14,    46,
       7,     0,     8,     9,    10,     0,     0,    63,    80,     0,
     106,     0,    11,    12,    48,     0,    36,     0,    38,    34,
      74,     0,     0,    64,     0,     0,    68,    69,     0,     0,
      49,     0,    63,    58,    61,    35,     1,     5,    28,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,    37,    39,     0,     0,     0,    63,     0,
       0,    55,    95,    94,     0,     0,     0,     0,    76,   108,
       0,     0,     0,    66,     0,    67,     0,    33,    45,    60,
       0,     0,     0,    26,    17,    18,    19,    20,    21,    27,
      23,    25,    22,    24,    41,     0,     0,    51,     0,     0,
      53,     0,    97,     0,   101,    81,    91,     0,     0,    73,
       0,    65,    70,    59,    62,    29,    31,    52,    56,    57,
      54,    96,    99,     0,    91,    92,     0,   109,     0,     0,
       0,     0,    77,     0,    71,   100,   102,    82,    78,    93,
     103,    83,     0,    63,     0,    79,   104,    84,     0,     0,
     105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,    69,   -25,   -14,  -160,  -160,  -160,  -160,  -160,
       2,  -160,    29,   -21,  -160,   -46,  -160,  -160,    13,  -160,
    -159,  -160,   -16,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,   -30,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,    28,    29,   121,   122,    30,    31,    32,
      33,    34,    35,   101,    74,    64,    36,    65,    66,    67,
      37,    61,    38,    49,   146,   178,   182,   107,   164,   181,
     184,    39,   166,    40,   141,    41,    42,    46,   169,    43,
     163,   180,   183,   188,    44,    51,   147
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   106,    77,    73,    69,    63,    68,     8,   144,   114,
      99,    75,    72,    95,    56,    58,   103,    92,    93,   100,
      94,    96,    97,   185,   113,   187,   120,   154,   114,   114,
      45,   104,    55,    63,    47,    95,    22,   109,    23,   110,
      24,    57,    57,    96,    97,    83,    84,    85,   112,    48,
     119,    81,   138,    82,    83,    84,    85,   159,    63,   114,
      50,    -1,    -1,    -1,    -1,    52,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   172,   134,   173,
     177,   135,   173,    53,    63,   139,    77,    60,    54,    72,
      70,   143,    71,    76,    98,   102,   105,   153,   108,     4,
     151,   115,   116,   136,   118,   137,   145,   155,   156,   140,
     148,     4,    62,   165,   167,   158,   161,     8,     9,    10,
      11,   179,    18,    12,   114,    13,    14,   153,   189,   152,
     111,    15,    16,    17,   171,     0,   168,   186,     0,     0,
      19,     0,    20,     0,   175,     0,    22,     0,    23,   170,
      24,    25,     0,     0,     0,     1,     0,     2,     3,     4,
       5,     6,     7,     0,   190,     8,     9,    10,    11,    63,
       0,    12,     0,    13,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,    18,   149,    19,     0,
      20,     0,    21,     0,    22,     0,    23,     0,    24,    25,
       1,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     9,    10,    11,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,    18,     0,    19,     0,    20,     0,    21,     0,    22,
       0,    23,     0,    24,    25,     8,     9,    10,    11,     0,
       0,    12,     0,    13,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,    62,     0,    19,     0,
      20,     0,     0,     0,    22,     0,    23,     0,    24,    25,
       8,     9,    10,    11,     0,     0,    12,     0,    13,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,    19,     0,    20,    78,    79,     0,    22,
       0,    23,    80,    24,    25,    81,     0,    82,    83,    84,
      85,    86,     0,     0,     0,    87,    88,    89,    90,     0,
      78,    79,     0,     0,     0,     0,    80,     0,   150,    81,
       0,    82,    83,    84,    85,    86,     0,     0,     0,    87,
      88,    89,    90,     0,    78,    79,     0,     0,     0,    91,
      80,     0,     0,    81,     0,    82,    83,    84,    85,    86,
       0,     0,     0,    87,    88,    89,    90,     0,    78,    79,
       0,     0,     0,   176,    80,     0,     0,    81,     0,    82,
      83,    84,    85,    86,     0,     0,     0,    87,    88,    89,
      90,    78,    79,     0,     0,     0,   117,    80,     0,     0,
      81,     0,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    78,    79,     0,     0,     0,   142,
      80,     0,     0,    81,     0,    82,    83,    84,    85,    86,
       0,     0,     0,    87,    88,    89,    90,    78,    79,     0,
       0,     0,   162,    80,     0,     0,    81,     0,    82,    83,
      84,    85,    86,     0,     0,     0,    87,    88,    89,    90,
      78,    79,     0,   157,     0,     0,    80,     0,     0,    81,
       0,    82,    83,    84,    85,    86,     0,     0,     0,    87,
      88,    89,    90,    78,    79,     0,   160,     0,     0,    80,
       0,     0,    81,     0,    82,    83,    84,    85,    86,     0,
      78,    79,    87,    88,    89,    90,    80,   174,     0,    81,
       0,    82,    83,    84,    85,    86,     0,    78,     0,    87,
      88,    89,    90,    80,     0,     0,    81,     0,    82,    83,
      84,    85,    86,     0,     0,     0,    87,    88,    89,    90,
      -1,     0,     0,    81,     0,    82,    83,    84,    85,    -1,
       0,     0,     0,    87,    88,    89,    90,    80,     0,     0,
      81,     0,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      14,    47,    27,    24,    20,    19,    20,    13,    40,    41,
      36,    25,    38,    36,    12,    13,    41,    18,    19,    45,
      21,    44,    45,   182,    37,   184,    72,    39,    41,    41,
      38,    45,    38,    47,    38,    36,    42,    51,    44,    55,
      46,    12,    13,    44,    45,    23,    24,    25,    62,    46,
      71,    20,    98,    22,    23,    24,    25,    39,    72,    41,
      40,    30,    31,    32,    33,    40,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    39,    92,    41,
      39,    95,    41,    40,    98,    99,   111,    35,    46,    38,
      46,   105,    46,     0,    38,     4,    38,   118,    38,     7,
     114,    37,    41,    46,    39,    46,    38,   121,   122,    46,
      39,     7,    34,    46,    40,   136,   141,    13,    14,    15,
      16,    46,    34,    19,    41,    21,    22,   148,    39,   116,
      61,    27,    28,    29,   164,    -1,   150,   183,    -1,    -1,
      36,    -1,    38,    -1,   169,    -1,    42,    -1,    44,   163,
      46,    47,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    -1,   189,    13,    14,    15,    16,   183,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      38,    -1,    40,    -1,    42,    -1,    44,    -1,    46,    47,
       3,    -1,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,    38,    -1,    40,    -1,    42,
      -1,    44,    -1,    46,    47,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    -1,
      38,    -1,    -1,    -1,    42,    -1,    44,    -1,    46,    47,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    11,    12,    -1,    42,
      -1,    44,    17,    46,    47,    20,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    43,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    -1,    11,    12,    -1,    -1,    -1,    40,
      17,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    -1,    11,    12,
      -1,    -1,    -1,    40,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    31,    32,
      33,    11,    12,    -1,    -1,    -1,    39,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    11,    12,    -1,    -1,    -1,    39,
      17,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    11,    12,    -1,
      -1,    -1,    39,    17,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      11,    12,    -1,    37,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    11,    12,    -1,    37,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    24,    25,    26,    -1,
      11,    12,    30,    31,    32,    33,    17,    35,    -1,    20,
      -1,    22,    23,    24,    25,    26,    -1,    11,    -1,    30,
      31,    32,    33,    17,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      17,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    17,    -1,    -1,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    13,    14,
      15,    16,    19,    21,    22,    27,    28,    29,    34,    36,
      38,    40,    42,    44,    46,    47,    50,    51,    52,    53,
      56,    57,    58,    59,    60,    61,    65,    69,    71,    80,
      82,    84,    85,    88,    93,    38,    86,    38,    46,    72,
      40,    94,    40,    40,    46,    38,    59,    61,    59,    53,
      35,    70,    34,    53,    64,    66,    67,    68,    53,    71,
      46,    46,    38,    62,    63,    53,     0,    52,    11,    12,
      17,    20,    22,    23,    24,    25,    26,    30,    31,    32,
      33,    40,    18,    19,    21,    36,    44,    45,    38,    36,
      45,    62,     4,    52,    53,    38,    64,    76,    38,    53,
      71,    51,    53,    37,    41,    37,    41,    39,    39,    62,
      64,    54,    55,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    46,    46,    64,    53,
      46,    83,    39,    53,    40,    38,    73,    95,    39,    35,
      43,    53,    67,    62,    39,    53,    53,    37,    62,    39,
      37,    52,    39,    89,    77,    46,    81,    40,    53,    87,
      53,    81,    39,    41,    35,    52,    40,    39,    74,    46,
      90,    78,    75,    91,    79,    69,    64,    69,    92,    39,
      52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    53,
      55,    53,    53,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    63,    64,    64,    64,    65,    65,    66,    67,
      67,    68,    70,    69,    69,    72,    73,    74,    75,    71,
      76,    77,    78,    79,    71,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    82,    83,    82,    84,    86,    87,
      85,    89,    90,    91,    92,    88,    93,    94,    95,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     4,
       0,     4,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     2,     2,
       1,     3,     4,     3,     4,     2,     4,     4,     2,     4,
       3,     1,     3,     0,     1,     3,     3,     3,     1,     1,
       3,     5,     0,     4,     2,     0,     0,     0,     0,     9,
       0,     0,     0,     0,    10,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     2,     0,     4,     4,     0,     0,
       7,     0,     0,     0,     0,    13,     2,     0,     0,     5
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
#line 86 "parser/parser.y"
            {ressettemp();}
#line 1405 "parser/parser.cpp"
    break;

  case 8: /* stmt: whilestmt  */
#line 87 "parser/parser.y"
               {ressettemp();}
#line 1411 "parser/parser.cpp"
    break;

  case 11: /* stmt: BREAK SEMICOLON  */
#line 90 "parser/parser.y"
                     {
        if(found_Func || loopCount == 0){
            yyerror("Break not in loop");
        }else{
            emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
            loopStack.top().breakList.push_back(curr_quad - 1);
        }
    }
#line 1424 "parser/parser.cpp"
    break;

  case 12: /* stmt: CONTINUE SEMICOLON  */
#line 98 "parser/parser.y"
                        {
         if(found_Func || loopCount == 0){
            yyerror("Continue not in loop");
        }else{
            emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
            loopStack.top().continueList.push_back(curr_quad - 1);
        }
    }
#line 1437 "parser/parser.cpp"
    break;

  case 13: /* stmt: block  */
#line 106 "parser/parser.y"
           {ressettemp();}
#line 1443 "parser/parser.cpp"
    break;

  case 14: /* stmt: funcdef  */
#line 107 "parser/parser.y"
             {ressettemp();}
#line 1449 "parser/parser.cpp"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 112 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(add, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1460 "parser/parser.cpp"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 118 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(sub, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1471 "parser/parser.cpp"
    break;

  case 19: /* expr: expr MULTI expr  */
#line 124 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(mul, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1482 "parser/parser.cpp"
    break;

  case 20: /* expr: expr DIV expr  */
#line 130 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(div_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1493 "parser/parser.cpp"
    break;

  case 21: /* expr: expr MOD expr  */
#line 136 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(mod, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1504 "parser/parser.cpp"
    break;

  case 22: /* expr: expr GREATER expr  */
#line 142 "parser/parser.y"
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
#line 1524 "parser/parser.cpp"
    break;

  case 23: /* expr: expr GREATER_EQUAL expr  */
#line 157 "parser/parser.y"
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
#line 1544 "parser/parser.cpp"
    break;

  case 24: /* expr: expr LESS expr  */
#line 172 "parser/parser.y"
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
#line 1564 "parser/parser.cpp"
    break;

  case 25: /* expr: expr LESS_EQUAL expr  */
#line 187 "parser/parser.y"
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
#line 1584 "parser/parser.cpp"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 202 "parser/parser.y"
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
#line 1604 "parser/parser.cpp"
    break;

  case 27: /* expr: expr NEQUAL expr  */
#line 217 "parser/parser.y"
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
#line 1624 "parser/parser.cpp"
    break;

  case 28: /* @1: %empty  */
#line 232 "parser/parser.y"
               {
        expr* boolConst = NewExpr(constbool_e);
        boolConst->boolConst = false;
        emit(if_eq, (yyvsp[-1].exprVal), boolConst, nullptr, 0, yylineno);
        (yyval.intVal) = curr_quad;
    }
#line 1635 "parser/parser.cpp"
    break;

  case 29: /* expr: expr AND @1 expr  */
#line 237 "parser/parser.y"
          {
        expr* trueConst = NewExpr(constbool_e), *falseConst = NewExpr(constbool_e), *new_Tmp = newtemp();;
        trueConst->boolConst = true;
        falseConst->boolConst = false;

        emit(if_eq, (yyvsp[0].exprVal), falseConst, nullptr, curr_quad + 2, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 3, yylineno);
        emit(assign, falseConst, nullptr, new_Tmp, 0, yylineno);
        patchLabel((yyvsp[-1].intVal), curr_quad - 1);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        emit(assign, trueConst, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal) = NewExpr(boolexpr_e);
        (yyval.exprVal)->sym = new_Tmp->sym;;
    }
#line 1655 "parser/parser.cpp"
    break;

  case 30: /* @2: %empty  */
#line 252 "parser/parser.y"
               {
        expr* boolConst = NewExpr(constbool_e);
        boolConst->boolConst = true;
        emit(if_eq, (yyvsp[-1].exprVal), boolConst, nullptr, 0, yylineno);
        (yyval.intVal) = curr_quad;
    }
#line 1666 "parser/parser.cpp"
    break;

  case 31: /* expr: expr OR @2 expr  */
#line 257 "parser/parser.y"
           {
        expr* trueConst = NewExpr(constbool_e), *falseConst = NewExpr(constbool_e), *new_Tmp = newtemp();;
        trueConst->boolConst = true;
        falseConst->boolConst = false;

        emit(if_eq, (yyvsp[0].exprVal), trueConst, nullptr, curr_quad + 2, yylineno);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 3, yylineno);
        emit(assign, trueConst, nullptr, new_Tmp, 0, yylineno);
        patchLabel((yyvsp[-1].intVal), curr_quad - 1);
        emit(jump, nullptr, nullptr, nullptr, curr_quad + 2, yylineno);
        emit(assign, falseConst, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal) = NewExpr(boolexpr_e);
        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1686 "parser/parser.cpp"
    break;

  case 32: /* expr: term  */
#line 272 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1692 "parser/parser.cpp"
    break;

  case 33: /* term: LEFT_PARENTHES expr RIGHT_PARENTHES  */
#line 275 "parser/parser.y"
                                          {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1698 "parser/parser.cpp"
    break;

  case 34: /* term: MINUS expr  */
#line 276 "parser/parser.y"
                 {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(uminus, (yyvsp[0].exprVal), nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1711 "parser/parser.cpp"
    break;

  case 35: /* term: NOT expr  */
#line 284 "parser/parser.y"
               {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(not_i, (yyvsp[0].exprVal), nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1724 "parser/parser.cpp"
    break;

  case 36: /* term: UPLUS lvalue  */
#line 292 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(add, (yyvsp[0].exprVal), one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, (yyvsp[0].exprVal), 0, yylineno);

        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
    }
#line 1739 "parser/parser.cpp"
    break;

  case 37: /* term: lvalue UPLUS  */
#line 302 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(assign, new_Tmp, nullptr, (yyvsp[-1].exprVal), 0, yylineno);
        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
        emit(add, (yyvsp[-1].exprVal), one, new_Tmp, 0, yylineno);
    }
#line 1753 "parser/parser.cpp"
    break;

  case 38: /* term: UMINUS lvalue  */
#line 311 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(add, (yyvsp[0].exprVal), one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, (yyvsp[0].exprVal), 0, yylineno);

        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
    }
#line 1768 "parser/parser.cpp"
    break;

  case 39: /* term: lvalue UMINUS  */
#line 321 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(assign, new_Tmp, nullptr, (yyvsp[-1].exprVal), 0, yylineno);
        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
        emit(add, (yyvsp[-1].exprVal), one, new_Tmp, 0, yylineno);
    }
#line 1782 "parser/parser.cpp"
    break;

  case 40: /* term: primary  */
#line 330 "parser/parser.y"
              {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1788 "parser/parser.cpp"
    break;

  case 41: /* assignexpr: lvalue ASSIGN expr  */
#line 333 "parser/parser.y"
                              {
    
    (yyval.exprVal) = NewExpr(var_e);
    if((yyvsp[-2].exprVal)->type == tableitem_e){
        emit(tablesetelem, (yyvsp[0].exprVal), (yyvsp[-2].exprVal)->index, (yyvsp[-2].exprVal), 0, yylineno);
    }else{
        emit(assign, (yyvsp[0].exprVal), nullptr, (yyvsp[-2].exprVal), 0, yylineno);
    }
    (yyval.exprVal) = (yyvsp[-2].exprVal);
}
#line 1803 "parser/parser.cpp"
    break;

  case 42: /* primary: lvalue  */
#line 345 "parser/parser.y"
                {(yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));}
#line 1809 "parser/parser.cpp"
    break;

  case 43: /* primary: call  */
#line 346 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1815 "parser/parser.cpp"
    break;

  case 44: /* primary: objectdef  */
#line 347 "parser/parser.y"
                {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1821 "parser/parser.cpp"
    break;

  case 45: /* primary: LEFT_PARENTHES funcdef RIGHT_PARENTHES  */
#line 348 "parser/parser.y"
                                             {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1827 "parser/parser.cpp"
    break;

  case 46: /* primary: const  */
#line 349 "parser/parser.y"
            {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1833 "parser/parser.cpp"
    break;

  case 47: /* lvalue: ID  */
#line 352 "parser/parser.y"
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
#line 1863 "parser/parser.cpp"
    break;

  case 48: /* lvalue: LOCAL ID  */
#line 377 "parser/parser.y"
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
#line 1880 "parser/parser.cpp"
    break;

  case 49: /* lvalue: DCOLON ID  */
#line 389 "parser/parser.y"
                { 
                if(!symTable.lookup(*(yyvsp[0].strVal),0)){
                    yyerror("Undefined refrence to " + *(yyvsp[0].strVal));
                }
        }
#line 1890 "parser/parser.cpp"
    break;

  case 50: /* lvalue: member  */
#line 394 "parser/parser.y"
            { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1896 "parser/parser.cpp"
    break;

  case 51: /* member: lvalue DOT ID  */
#line 397 "parser/parser.y"
                     {
        (yyval.exprVal) = member_item ((yyvsp[-2].exprVal),*(yyvsp[0].strVal));
}
#line 1904 "parser/parser.cpp"
    break;

  case 52: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 400 "parser/parser.y"
                                            {
        (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal));
        (yyval.exprVal) = NewExpr(tableitem_e);
        (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
        (yyval.exprVal)->index = (yyvsp[-1].exprVal);
    }
#line 1915 "parser/parser.cpp"
    break;

  case 55: /* call: call callsuffix  */
#line 410 "parser/parser.y"
                     {
        expr* new_Tmp = newtemp();
        emit(call, (yyvsp[-1].exprVal), nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal) = NewExpr(programfunc_e);
        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1928 "parser/parser.cpp"
    break;

  case 56: /* call: lvalue DOTS ID callsuffix  */
#line 418 "parser/parser.y"
                               {
        SymbolEntry *sym = symTable.returnSymbol(*(yyvsp[-1].strVal));
        if(!sym){
            symTable.insert(*(yyvsp[-1].strVal), "user function", scope, yylineno);
            sym = symTable.returnSymbol(*(yyvsp[-1].strVal));
        }
        expr* func = NewExpr(programfunc_e), *new_Tmp = newtemp();
        func->sym = sym;
        emit(call, func, nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);
        if(!hasLibFuncName(*(yyvsp[-1].strVal))){
            (yyval.exprVal) = NewExpr(programfunc_e);
            (yyval.exprVal)->sym = new_Tmp->sym;
        }else{
            (yyval.exprVal) = NewExpr(libraryfunc_e);
            (yyval.exprVal)->sym = new_Tmp->sym;
        }
        
    }
#line 1952 "parser/parser.cpp"
    break;

  case 58: /* call: ID callsuffix  */
#line 438 "parser/parser.y"
                   {
        SymbolEntry *sym = symTable.returnSymbol(*(yyvsp[-1].strVal));
        if(!sym){
            symTable.insert(*(yyvsp[-1].strVal), "user function", scope, yylineno);
            sym = symTable.returnSymbol(*(yyvsp[-1].strVal));
        }
        expr* func = NewExpr(programfunc_e), *new_Tmp = newtemp();
        func->sym = sym;
        emit(call, func, nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);
        if(!hasLibFuncName(*(yyvsp[-1].strVal))){
            (yyval.exprVal) = NewExpr(programfunc_e);
            (yyval.exprVal)->sym = new_Tmp->sym;
        }else{
            (yyval.exprVal) = NewExpr(libraryfunc_e);
            (yyval.exprVal)->sym = new_Tmp->sym;
        }
        
    }
#line 1976 "parser/parser.cpp"
    break;

  case 59: /* call: LEFT_PARENTHES funcdef RIGHT_PARENTHES callsuffix  */
#line 457 "parser/parser.y"
                                                       {
        expr* new_Tmp = newtemp();
        emit(call, (yyvsp[-2].exprVal), nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal) = NewExpr(programfunc_e);
        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1989 "parser/parser.cpp"
    break;

  case 60: /* call: DOTS ID callsuffix  */
#line 465 "parser/parser.y"
                        {}
#line 1995 "parser/parser.cpp"
    break;

  case 61: /* callsuffix: normcall  */
#line 467 "parser/parser.y"
                     { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2001 "parser/parser.cpp"
    break;

  case 62: /* normcall: LEFT_PARENTHES elist RIGHT_PARENTHES  */
#line 471 "parser/parser.y"
                                              {
    if((yyvsp[-1].exprVal) != nullptr){
        expr* tmp = (yyvsp[-1].exprVal)->next;
        while(tmp != nullptr){
            emit(param, tmp, nullptr, nullptr, 0, yylineno);
            tmp = tmp->next;
        }
    }
}
#line 2015 "parser/parser.cpp"
    break;

  case 63: /* elist: %empty  */
#line 490 "parser/parser.y"
        { (yyval.exprVal) = nullptr; }
#line 2021 "parser/parser.cpp"
    break;

  case 64: /* elist: expr  */
#line 491 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(newtable_e);
        (yyval.exprVal)->next = (yyvsp[0].exprVal);
    }
#line 2030 "parser/parser.cpp"
    break;

  case 65: /* elist: elist COMMA expr  */
#line 495 "parser/parser.y"
                       {
        expr* tmp = (yyvsp[-2].exprVal);

        while(tmp->next != nullptr){
            tmp = tmp->next; 
        }
        tmp->next = (yyvsp[0].exprVal);
    }
#line 2043 "parser/parser.cpp"
    break;

  case 72: /* $@3: %empty  */
#line 519 "parser/parser.y"
                    {++scope;}
#line 2049 "parser/parser.cpp"
    break;

  case 73: /* block: LEFT_CBRACKET $@3 stmntlist RIGHT_CBRACKET  */
#line 519 "parser/parser.y"
                                                       {
        symTable.ScopeHide(scope);
        scope--;
    }
#line 2058 "parser/parser.cpp"
    break;

  case 75: /* $@4: %empty  */
#line 526 "parser/parser.y"
                 {  
        string name = "$" + to_string(curr_func);
        symTable.insert(name, "user function", scope, yylineno);
        curr_func_expr = NewExpr(programfunc_e);
        curr_func_expr->sym = symTable.returnSymbol(name);
        curr_func++;
        emit(funcstart, nullptr, nullptr, curr_func_expr, 0, yylineno);

        }
#line 2072 "parser/parser.cpp"
    break;

  case 76: /* $@5: %empty  */
#line 534 "parser/parser.y"
                        {++scope;}
#line 2078 "parser/parser.cpp"
    break;

  case 77: /* $@6: %empty  */
#line 534 "parser/parser.y"
                                                         {scope--;}
#line 2084 "parser/parser.cpp"
    break;

  case 78: /* $@7: %empty  */
#line 534 "parser/parser.y"
                                                                    {found_Func = true;}
#line 2090 "parser/parser.cpp"
    break;

  case 79: /* funcdef: FUNCTION $@4 LEFT_PARENTHES $@5 idlist RIGHT_PARENTHES $@6 $@7 block  */
#line 534 "parser/parser.y"
                                                                                               {
            found_Func = false; 
            emit(funcend, nullptr, nullptr, curr_func_expr, 0, yylineno);
            (yyval.exprVal) = curr_func_expr;
            curr_func_expr = nullptr;
        }
#line 2101 "parser/parser.cpp"
    break;

  case 80: /* $@8: %empty  */
#line 541 "parser/parser.y"
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
#line 2122 "parser/parser.cpp"
    break;

  case 81: /* $@9: %empty  */
#line 556 "parser/parser.y"
                   {++scope;}
#line 2128 "parser/parser.cpp"
    break;

  case 82: /* $@10: %empty  */
#line 556 "parser/parser.y"
                                                     {scope--;}
#line 2134 "parser/parser.cpp"
    break;

  case 83: /* $@11: %empty  */
#line 556 "parser/parser.y"
                                                                {found_Func = true;}
#line 2140 "parser/parser.cpp"
    break;

  case 84: /* funcdef: FUNCTION ID $@8 LEFT_PARENTHES $@9 idlist RIGHT_PARENTHES $@10 $@11 block  */
#line 556 "parser/parser.y"
                                                                                           { found_Func = false;
      if(curr_func_expr != nullptr){
            emit(funcend, nullptr, nullptr, curr_func_expr, 0, yylineno);
            (yyval.exprVal) = curr_func_expr;
            curr_func_expr = nullptr;  
        }
     }
#line 2152 "parser/parser.cpp"
    break;

  case 85: /* const: INTCONST  */
#line 565 "parser/parser.y"
                {
        (yyval.exprVal) = NewExpr(constnum_e);
        (yyval.exprVal)->numConst = (yyvsp[0].intVal);
    }
#line 2161 "parser/parser.cpp"
    break;

  case 86: /* const: REAL  */
#line 569 "parser/parser.y"
          {
        (yyval.exprVal) = NewExpr(constnum_e);
        (yyval.exprVal)->numConst = (yyvsp[0].realVal);
    }
#line 2170 "parser/parser.cpp"
    break;

  case 87: /* const: STRING  */
#line 573 "parser/parser.y"
            {
        (yyval.exprVal) = NewExpr(conststring_e);
        (yyval.exprVal)->strConst = *(yyvsp[0].strVal);
    }
#line 2179 "parser/parser.cpp"
    break;

  case 88: /* const: NIL  */
#line 577 "parser/parser.y"
         {
        (yyval.exprVal) = NewExpr(nil_e);
    }
#line 2187 "parser/parser.cpp"
    break;

  case 89: /* const: TRUE  */
#line 580 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(constbool_e);
        (yyval.exprVal)->boolConst = true;
    }
#line 2196 "parser/parser.cpp"
    break;

  case 90: /* const: FALSE  */
#line 584 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(constbool_e);
        (yyval.exprVal)->boolConst = false;
    }
#line 2205 "parser/parser.cpp"
    break;

  case 92: /* idlist: ID  */
#line 591 "parser/parser.y"
         {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 2219 "parser/parser.cpp"
    break;

  case 93: /* idlist: idlist COMMA ID  */
#line 600 "parser/parser.y"
                      {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 2233 "parser/parser.cpp"
    break;

  case 94: /* ifstmt: ifprefix stmt  */
#line 611 "parser/parser.y"
                     {
        patchLabel((yyvsp[-1].intVal), curr_quad);
        (yyval.intVal) = (yyvsp[-1].intVal);
    }
#line 2242 "parser/parser.cpp"
    break;

  case 95: /* $@12: %empty  */
#line 615 "parser/parser.y"
                  {
        patchLabel((yyvsp[-1].intVal), curr_quad + 1);
        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
        (yyvsp[-1].intVal) = curr_quad;
    }
#line 2252 "parser/parser.cpp"
    break;

  case 96: /* ifstmt: ifstmt ELSE $@12 stmt  */
#line 619 "parser/parser.y"
         {
        patchLabel((yyvsp[-3].intVal), curr_quad);
    }
#line 2260 "parser/parser.cpp"
    break;

  case 97: /* ifprefix: IF LEFT_PARENTHES expr RIGHT_PARENTHES  */
#line 624 "parser/parser.y"
                                                 {
        expr *boolExpr = NewExpr(constbool_e);
        boolExpr->boolConst = true;

        emit(if_eq, (yyvsp[-1].exprVal), boolExpr, nullptr, curr_quad + 2, yylineno);
        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);

        (yyval.intVal) = curr_quad;
    }
#line 2274 "parser/parser.cpp"
    break;

  case 98: /* @13: %empty  */
#line 636 "parser/parser.y"
                 { (yyval.intVal) = curr_quad; }
#line 2280 "parser/parser.cpp"
    break;

  case 99: /* @14: %empty  */
#line 636 "parser/parser.y"
                                                                                {
    expr* temp_e =NewExpr(constbool_e);
    temp_e->boolConst = true;
    emit(if_eq,(yyvsp[-1].exprVal),temp_e,nullptr, curr_quad + 2, yylineno);
    emit(jump, nullptr, nullptr,nullptr,0, yylineno);
    (yyval.intVal)=curr_quad;
}
#line 2292 "parser/parser.cpp"
    break;

  case 100: /* whilestmt: WHILE @13 LEFT_PARENTHES expr RIGHT_PARENTHES @14 stmt  */
#line 642 "parser/parser.y"
      {
    
    emit(jump, nullptr, nullptr,nullptr, (yyvsp[-5].intVal) ,yylineno);

    patchLabel((yyvsp[-1].intVal), curr_quad);
}
#line 2303 "parser/parser.cpp"
    break;

  case 101: /* @15: %empty  */
#line 650 "parser/parser.y"
                                            { (yyval.intVal) = curr_quad;}
#line 2309 "parser/parser.cpp"
    break;

  case 102: /* @16: %empty  */
#line 650 "parser/parser.y"
                                                                                      {
    expr* boolConstexpr = NewExpr(constbool_e);
    boolConstexpr->boolConst = true;
    
    emit(if_eq, (yyvsp[-1].exprVal), boolConstexpr, nullptr, 0, yylineno);
    (yyval.intVal) = curr_quad;
    emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
}
#line 2322 "parser/parser.cpp"
    break;

  case 103: /* @17: %empty  */
#line 657 "parser/parser.y"
  {(yyval.intVal) = curr_quad;}
#line 2328 "parser/parser.cpp"
    break;

  case 104: /* @18: %empty  */
#line 657 "parser/parser.y"
                                 {
    patchLabel((yyvsp[-2].intVal), curr_quad + 1);
    emit(jump, nullptr, nullptr, nullptr, (yyvsp[-5].intVal), yylineno);
    (yyval.intVal) = curr_quad;
}
#line 2338 "parser/parser.cpp"
    break;

  case 105: /* forstmt: FOR LEFT_PARENTHES elist SEMICOLON @15 expr SEMICOLON @16 @17 elist @18 RIGHT_PARENTHES stmt  */
#line 661 "parser/parser.y"
                       {
    patchLabel((yyvsp[-5].intVal) + 1, (yyvsp[-2].intVal) + 1);
    emit(jump, nullptr, nullptr, nullptr, (yyvsp[-4].intVal), yylineno);
}
#line 2347 "parser/parser.cpp"
    break;

  case 107: /* $@19: %empty  */
#line 668 "parser/parser.y"
            {
        returnSTMT = 1;
    }
#line 2355 "parser/parser.cpp"
    break;

  case 108: /* $@20: %empty  */
#line 670 "parser/parser.y"
          {
        returnSTMT = 0;
    }
#line 2363 "parser/parser.cpp"
    break;


#line 2367 "parser/parser.cpp"

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

#line 675 "parser/parser.y"


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

