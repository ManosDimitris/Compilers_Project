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
    unsigned int scopeSpaceCounter = 1;

    stack<bool> returnAvailabe; 
    ostream *outStream;
    //Helper expr* var to print the curr function name
    bool hasLibFuncName(string name);
    
    struct LoopContext {
        bool isLoop;
        list<unsigned int> breakList;
        list<unsigned int> continueList;
    };
    stack<LoopContext> loopStack;
    stack<expr*> curr_func_expr;

    /*THE VEVTOR OF THE QUADS*/
    vector<quad *> quads;

#line 113 "parser/parser.cpp"

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
  YYSYMBOL_returnstmt = 93                 /* returnstmt  */
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
#define YYLAST   606

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,    81,    81,    82,    85,    86,    89,    90,    91,    92,
      93,    94,   101,   108,   109,   110,   113,   114,   120,   126,
     132,   138,   144,   159,   174,   189,   204,   219,   234,   234,
     254,   254,   274,   277,   278,   286,   294,   304,   313,   323,
     332,   335,   352,   353,   354,   355,   356,   359,   384,   396,
     401,   404,   407,   413,   414,   417,   425,   444,   466,   488,
     496,   498,   502,   513,   514,   518,   528,   529,   532,   535,
     536,   539,   542,   542,   546,   549,   561,   561,   561,   549,
     572,   591,   591,   591,   572,   604,   608,   612,   616,   619,
     623,   629,   630,   639,   650,   654,   654,   663,   675,   675,
     675,   704,   704,   715,   715,   704,   737,   744
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
  "@15", "@16", "@17", "@18", "returnstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     178,   -31,  -117,   -20,   -25,   213,   -13,     1,    13,  -117,
    -117,  -117,    16,    16,   283,  -117,  -117,  -117,    30,   248,
       9,  -117,    22,    45,    64,   283,    99,   178,  -117,   335,
    -117,  -117,  -117,    25,    86,   -28,  -117,  -117,  -117,  -117,
     121,   178,  -117,  -117,  -117,   283,    89,   283,  -117,    94,
    -117,   359,  -117,  -117,  -117,   126,    27,   -28,    27,   -12,
    -117,   178,   283,   539,   -35,    97,  -117,    96,   407,   111,
    -117,    64,   283,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,  -117,   283,  -117,  -117,   283,   105,   107,   283,   283,
     110,  -117,  -117,  -117,   430,   283,     8,   120,  -117,  -117,
     124,   133,   311,  -117,   283,  -117,   125,  -117,    64,  -117,
      -7,   283,   283,   556,   -12,   -12,  -117,  -117,  -117,   556,
      98,    98,    98,    98,   539,   476,    64,  -117,    -6,   499,
    -117,   178,  -117,   453,  -117,  -117,   118,    64,  -117,   283,
     539,  -117,  -117,  -117,   573,    81,  -117,  -117,  -117,  -117,
    -117,  -117,   283,   118,  -117,    47,   522,   178,   383,    69,
    -117,   128,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
     132,   283,   132,  -117,   129,  -117,   139,   178,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    98,     0,    75,     0,     0,     0,     0,    89,
      90,    88,     0,     0,     0,    85,    86,    87,    72,    63,
       0,    15,     0,     0,    47,     0,     0,     3,     4,     0,
      32,    16,    40,    42,    50,    43,    44,    13,    14,    46,
       7,     0,     8,     9,    10,     0,     0,    63,    80,     0,
     106,     0,    11,    12,    48,     0,    36,     0,    38,    34,
      74,     0,     0,    64,     0,     0,    68,    69,     0,     0,
      49,     0,    63,    58,    61,    35,     1,     5,    28,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,    37,    39,     0,     0,     0,    63,     0,
       0,    55,    95,    94,     0,     0,     0,     0,    76,   107,
       0,     0,     0,    66,     0,    67,     0,    33,    45,    60,
       0,     0,     0,    26,    17,    18,    19,    20,    21,    27,
      23,    25,    22,    24,    41,     0,     0,    51,     0,     0,
      53,     0,    97,     0,   101,    81,    91,     0,    73,     0,
      65,    70,    59,    62,    29,    31,    52,    56,    57,    54,
      96,    99,     0,    91,    92,     0,     0,     0,     0,     0,
      77,     0,    71,   100,   102,    82,    78,    93,   103,    83,
       0,    63,     0,    79,   104,    84,     0,     0,   105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   134,   -22,    -5,  -117,  -117,  -117,  -117,  -117,
      61,  -117,    83,   -21,  -117,   -46,  -117,  -117,    56,  -117,
    -116,  -117,   -16,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,    19,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,    28,    29,   121,   122,    30,    31,    32,
      33,    34,    35,   101,    74,    64,    36,    65,    66,    67,
      37,    61,    38,    49,   146,   176,   180,   107,   163,   179,
     182,    39,   165,    40,   141,    41,    42,    46,   167,    43,
     162,   178,   181,   186,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,   106,   113,    73,    69,    77,   114,    45,    99,    59,
      72,    83,    84,    85,    63,    68,     4,   100,    47,   103,
      75,    48,     8,     9,    10,    11,   120,    52,    12,     8,
      13,    14,   153,   158,   114,   114,    15,    16,    17,   110,
     104,    53,    63,    92,    93,    19,    94,    20,   144,   114,
     119,    22,   138,    23,    55,    24,    25,   112,    22,    54,
      23,    95,    24,    95,   183,    60,   185,    63,    70,    96,
      97,    96,    97,    56,    58,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   170,   134,   171,    77,
     135,    71,    78,    63,   139,    57,    57,   152,    80,    76,
     143,    81,    72,    82,    83,    84,    85,    86,   175,   150,
     171,    87,    88,    89,    90,   157,   154,   155,    81,   160,
      82,    83,    84,    85,    98,   102,   152,   105,    -1,    -1,
      -1,    -1,   108,     4,   115,   184,     1,   116,     2,     3,
       4,     5,     6,     7,   166,   173,     8,     9,    10,    11,
     118,   136,    12,   137,    13,    14,   140,   168,   145,    62,
      15,    16,    17,   147,   164,   188,    18,    18,   148,    19,
     114,    20,   151,    21,   177,    22,    63,    23,   187,    24,
      25,     1,   169,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     9,    10,    11,   111,     0,    12,     0,    13,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,    19,     0,    20,     0,    21,     0,
      22,     0,    23,     0,    24,    25,     8,     9,    10,    11,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    19,
       0,    20,     0,    50,     0,    22,     0,    23,     0,    24,
      25,     8,     9,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,    62,     0,    19,     0,    20,     0,     0,     0,
      22,     0,    23,     0,    24,    25,     8,     9,    10,    11,
       0,     0,    12,     0,    13,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    78,    79,     0,    22,     0,    23,    80,    24,
      25,    81,     0,    82,    83,    84,    85,    86,     0,     0,
       0,    87,    88,    89,    90,     0,    78,    79,     0,     0,
       0,     0,    80,     0,   149,    81,     0,    82,    83,    84,
      85,    86,     0,     0,     0,    87,    88,    89,    90,     0,
      78,    79,     0,     0,     0,    91,    80,     0,     0,    81,
       0,    82,    83,    84,    85,    86,     0,     0,     0,    87,
      88,    89,    90,     0,    78,    79,     0,     0,     0,   109,
      80,     0,     0,    81,     0,    82,    83,    84,    85,    86,
       0,     0,     0,    87,    88,    89,    90,     0,    78,    79,
       0,     0,     0,   174,    80,     0,     0,    81,     0,    82,
      83,    84,    85,    86,     0,     0,     0,    87,    88,    89,
      90,    78,    79,     0,     0,     0,   117,    80,     0,     0,
      81,     0,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    78,    79,     0,     0,     0,   142,
      80,     0,     0,    81,     0,    82,    83,    84,    85,    86,
       0,     0,     0,    87,    88,    89,    90,    78,    79,     0,
       0,     0,   161,    80,     0,     0,    81,     0,    82,    83,
      84,    85,    86,     0,     0,     0,    87,    88,    89,    90,
      78,    79,     0,   156,     0,     0,    80,     0,     0,    81,
       0,    82,    83,    84,    85,    86,     0,     0,     0,    87,
      88,    89,    90,    78,    79,     0,   159,     0,     0,    80,
       0,     0,    81,     0,    82,    83,    84,    85,    86,     0,
      78,    79,    87,    88,    89,    90,    80,   172,     0,    81,
       0,    82,    83,    84,    85,    86,     0,     0,     0,    87,
      88,    89,    90,    -1,     0,     0,    81,     0,    82,    83,
      84,    85,    -1,     0,     0,     0,    87,    88,    89,    90,
      80,     0,     0,    81,     0,    82,    83,    84,    85,    86,
       0,     0,     0,    87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
       5,    47,    37,    24,    20,    27,    41,    38,    36,    14,
      38,    23,    24,    25,    19,    20,     7,    45,    38,    41,
      25,    46,    13,    14,    15,    16,    72,    40,    19,    13,
      21,    22,    39,    39,    41,    41,    27,    28,    29,    55,
      45,    40,    47,    18,    19,    36,    21,    38,    40,    41,
      71,    42,    98,    44,    38,    46,    47,    62,    42,    46,
      44,    36,    46,    36,   180,    35,   182,    72,    46,    44,
      45,    44,    45,    12,    13,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    39,    92,    41,   111,
      95,    46,    11,    98,    99,    12,    13,   118,    17,     0,
     105,    20,    38,    22,    23,    24,    25,    26,    39,   114,
      41,    30,    31,    32,    33,   136,   121,   122,    20,   141,
      22,    23,    24,    25,    38,     4,   147,    38,    30,    31,
      32,    33,    38,     7,    37,   181,     3,    41,     5,     6,
       7,     8,     9,    10,   149,   167,    13,    14,    15,    16,
      39,    46,    19,    46,    21,    22,    46,   162,    38,    34,
      27,    28,    29,    39,    46,   187,    34,    34,    35,    36,
      41,    38,   116,    40,    46,    42,   181,    44,    39,    46,
      47,     3,   163,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    15,    16,    61,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    36,    -1,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    46,    47,    13,    14,    15,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,    44,    -1,    46,
      47,    13,    14,    15,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    36,    -1,    38,    -1,    -1,    -1,
      42,    -1,    44,    -1,    46,    47,    13,    14,    15,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    11,    12,    -1,    42,    -1,    44,    17,    46,
      47,    20,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    43,    20,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    -1,
      11,    12,    -1,    -1,    -1,    40,    17,    -1,    -1,    20,
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
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    17,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      17,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33
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
      40,    53,    40,    40,    46,    38,    59,    61,    59,    53,
      35,    70,    34,    53,    64,    66,    67,    68,    53,    71,
      46,    46,    38,    62,    63,    53,     0,    52,    11,    12,
      17,    20,    22,    23,    24,    25,    26,    30,    31,    32,
      33,    40,    18,    19,    21,    36,    44,    45,    38,    36,
      45,    62,     4,    52,    53,    38,    64,    76,    38,    40,
      71,    51,    53,    37,    41,    37,    41,    39,    39,    62,
      64,    54,    55,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    46,    46,    64,    53,
      46,    83,    39,    53,    40,    38,    73,    39,    35,    43,
      53,    67,    62,    39,    53,    53,    37,    62,    39,    37,
      52,    39,    89,    77,    46,    81,    53,    87,    53,    81,
      39,    41,    35,    52,    40,    39,    74,    46,    90,    78,
      75,    91,    79,    69,    64,    69,    92,    39,    52
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
      85,    89,    90,    91,    92,    88,    93,    93
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
       7,     0,     0,     0,     0,    13,     2,     3
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
#line 90 "parser/parser.y"
            {ressettemp();}
#line 1408 "parser/parser.cpp"
    break;

  case 8: /* stmt: whilestmt  */
#line 91 "parser/parser.y"
               {ressettemp();}
#line 1414 "parser/parser.cpp"
    break;

  case 11: /* stmt: BREAK SEMICOLON  */
#line 94 "parser/parser.y"
                      {
        if(loopStack.top().isLoop){
            emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
            loopStack.top().breakList.push_back(curr_quad);
        }
        else yyerror("Break not in a loop");
    }
#line 1426 "parser/parser.cpp"
    break;

  case 12: /* stmt: CONTINUE SEMICOLON  */
#line 101 "parser/parser.y"
                        {
        if(loopStack.top().isLoop){
            emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
            loopStack.top().continueList.push_back(curr_quad);
        }
        else yyerror("Continue not in a loop");
    }
#line 1438 "parser/parser.cpp"
    break;

  case 13: /* stmt: block  */
#line 108 "parser/parser.y"
           {ressettemp();}
#line 1444 "parser/parser.cpp"
    break;

  case 14: /* stmt: funcdef  */
#line 109 "parser/parser.y"
             {ressettemp();}
#line 1450 "parser/parser.cpp"
    break;

  case 17: /* expr: expr PLUS expr  */
#line 114 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(add, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1461 "parser/parser.cpp"
    break;

  case 18: /* expr: expr MINUS expr  */
#line 120 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(sub, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1472 "parser/parser.cpp"
    break;

  case 19: /* expr: expr MULTI expr  */
#line 126 "parser/parser.y"
                     {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(mul, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1483 "parser/parser.cpp"
    break;

  case 20: /* expr: expr DIV expr  */
#line 132 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(div_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1494 "parser/parser.cpp"
    break;

  case 21: /* expr: expr MOD expr  */
#line 138 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(arithexpr_e);
        expr* newTmp = newtemp();
        (yyval.exprVal)->sym = newTmp->sym;
        emit(mod, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), newTmp, 0, yylineno);
    }
#line 1505 "parser/parser.cpp"
    break;

  case 22: /* expr: expr GREATER expr  */
#line 144 "parser/parser.y"
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
#line 1525 "parser/parser.cpp"
    break;

  case 23: /* expr: expr GREATER_EQUAL expr  */
#line 159 "parser/parser.y"
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
#line 1545 "parser/parser.cpp"
    break;

  case 24: /* expr: expr LESS expr  */
#line 174 "parser/parser.y"
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
#line 1565 "parser/parser.cpp"
    break;

  case 25: /* expr: expr LESS_EQUAL expr  */
#line 189 "parser/parser.y"
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
#line 1585 "parser/parser.cpp"
    break;

  case 26: /* expr: expr EQUAL expr  */
#line 204 "parser/parser.y"
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
#line 1605 "parser/parser.cpp"
    break;

  case 27: /* expr: expr NEQUAL expr  */
#line 219 "parser/parser.y"
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
#line 1625 "parser/parser.cpp"
    break;

  case 28: /* @1: %empty  */
#line 234 "parser/parser.y"
               {
        expr* boolConst = NewExpr(constbool_e);
        boolConst->boolConst = false;
        emit(if_eq, (yyvsp[-1].exprVal), boolConst, nullptr, 0, yylineno);
        (yyval.intVal) = curr_quad;
    }
#line 1636 "parser/parser.cpp"
    break;

  case 29: /* expr: expr AND @1 expr  */
#line 239 "parser/parser.y"
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
#line 1656 "parser/parser.cpp"
    break;

  case 30: /* @2: %empty  */
#line 254 "parser/parser.y"
               {
        expr* boolConst = NewExpr(constbool_e);
        boolConst->boolConst = true;
        emit(if_eq, (yyvsp[-1].exprVal), boolConst, nullptr, 0, yylineno);
        (yyval.intVal) = curr_quad;
    }
#line 1667 "parser/parser.cpp"
    break;

  case 31: /* expr: expr OR @2 expr  */
#line 259 "parser/parser.y"
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
#line 1687 "parser/parser.cpp"
    break;

  case 32: /* expr: term  */
#line 274 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1693 "parser/parser.cpp"
    break;

  case 33: /* term: LEFT_PARENTHES expr RIGHT_PARENTHES  */
#line 277 "parser/parser.y"
                                          {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1699 "parser/parser.cpp"
    break;

  case 34: /* term: MINUS expr  */
#line 278 "parser/parser.y"
                 {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(uminus, (yyvsp[0].exprVal), nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1712 "parser/parser.cpp"
    break;

  case 35: /* term: NOT expr  */
#line 286 "parser/parser.y"
               {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();

        emit(not_i, (yyvsp[0].exprVal), nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1725 "parser/parser.cpp"
    break;

  case 36: /* term: UPLUS lvalue  */
#line 294 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(add, (yyvsp[0].exprVal), one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, (yyvsp[0].exprVal), 0, yylineno);

        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
    }
#line 1740 "parser/parser.cpp"
    break;

  case 37: /* term: lvalue UPLUS  */
#line 304 "parser/parser.y"
                   {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = 1;
        emit(assign, new_Tmp, nullptr, (yyvsp[-1].exprVal), 0, yylineno);
        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
        emit(add, (yyvsp[-1].exprVal), one, new_Tmp, 0, yylineno);
    }
#line 1754 "parser/parser.cpp"
    break;

  case 38: /* term: UMINUS lvalue  */
#line 313 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(add, (yyvsp[0].exprVal), one, new_Tmp, 0, yylineno);
        emit(assign, new_Tmp, nullptr, (yyvsp[0].exprVal), 0, yylineno);

        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
    }
#line 1769 "parser/parser.cpp"
    break;

  case 39: /* term: lvalue UMINUS  */
#line 323 "parser/parser.y"
                    {
        (yyval.exprVal) = NewExpr(var_e);
        expr* new_Tmp = newtemp();
        expr* one = NewExpr(constnum_e);
        one->numConst = -1;
        emit(assign, new_Tmp, nullptr, (yyvsp[-1].exprVal), 0, yylineno);
        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
        emit(add, (yyvsp[-1].exprVal), one, new_Tmp, 0, yylineno);
    }
#line 1783 "parser/parser.cpp"
    break;

  case 40: /* term: primary  */
#line 332 "parser/parser.y"
              {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1789 "parser/parser.cpp"
    break;

  case 41: /* assignexpr: lvalue ASSIGN expr  */
#line 335 "parser/parser.y"
                              {
    
    if((yyvsp[-2].exprVal)->type == tableitem_e){    
        emit(tablesetelem, (yyvsp[-2].exprVal), (yyvsp[-2].exprVal)->index, (yyvsp[0].exprVal), 0, yylineno);
        (yyval.exprVal) = emit_iftableitem((yyvsp[-2].exprVal));
        (yyval.exprVal)->type = assignexpr_e;
    }else{
       emit(assign, (yyvsp[0].exprVal), nullptr, (yyvsp[-2].exprVal), 0, yylineno);
       expr* tmp = newtemp();
        emit(assign,(yyvsp[-2].exprVal),nullptr,tmp,0,yylineno);
        (yyval.exprVal) = NewExpr(assignexpr_e);
        (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
    }
    
}
#line 1809 "parser/parser.cpp"
    break;

  case 42: /* primary: lvalue  */
#line 352 "parser/parser.y"
                {(yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));}
#line 1815 "parser/parser.cpp"
    break;

  case 43: /* primary: call  */
#line 353 "parser/parser.y"
           {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1821 "parser/parser.cpp"
    break;

  case 44: /* primary: objectdef  */
#line 354 "parser/parser.y"
                {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1827 "parser/parser.cpp"
    break;

  case 45: /* primary: LEFT_PARENTHES funcdef RIGHT_PARENTHES  */
#line 355 "parser/parser.y"
                                             {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1833 "parser/parser.cpp"
    break;

  case 46: /* primary: const  */
#line 356 "parser/parser.y"
            {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1839 "parser/parser.cpp"
    break;

  case 47: /* lvalue: ID  */
#line 359 "parser/parser.y"
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
#line 1869 "parser/parser.cpp"
    break;

  case 48: /* lvalue: LOCAL ID  */
#line 384 "parser/parser.y"
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
#line 1886 "parser/parser.cpp"
    break;

  case 49: /* lvalue: DCOLON ID  */
#line 396 "parser/parser.y"
                { 
                if(!symTable.lookup(*(yyvsp[0].strVal),0)){
                    yyerror("Undefined refrence to " + *(yyvsp[0].strVal));
                }
        }
#line 1896 "parser/parser.cpp"
    break;

  case 50: /* lvalue: member  */
#line 401 "parser/parser.y"
            { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1902 "parser/parser.cpp"
    break;

  case 51: /* member: lvalue DOT ID  */
#line 404 "parser/parser.y"
                     {
        (yyval.exprVal) = member_item ((yyvsp[-2].exprVal),*(yyvsp[0].strVal));
}
#line 1910 "parser/parser.cpp"
    break;

  case 52: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 407 "parser/parser.y"
                                            {
        (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal));
        (yyval.exprVal) = NewExpr(tableitem_e);
        (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
        (yyval.exprVal)->index = (yyvsp[-1].exprVal);
    }
#line 1921 "parser/parser.cpp"
    break;

  case 55: /* call: call callsuffix  */
#line 417 "parser/parser.y"
                     {
        expr* new_Tmp = newtemp();
        emit(call, (yyvsp[-1].exprVal), nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal) = NewExpr(programfunc_e);
        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 1934 "parser/parser.cpp"
    break;

  case 56: /* call: lvalue DOTS ID callsuffix  */
#line 425 "parser/parser.y"
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
#line 1958 "parser/parser.cpp"
    break;

  case 57: /* call: member LEFT_PARENTHES elist RIGHT_PARENTHES  */
#line 444 "parser/parser.y"
                                                 {
        if((yyvsp[-3].exprVal)->type == tableitem_e){
            expr* tableMember = newtemp();
            emit(tablegetelem, (yyvsp[-3].exprVal), (yyvsp[-3].exprVal), tableMember, 0,yylineno );
            (yyvsp[-3].exprVal) = tableMember;
        }


         if((yyvsp[-1].exprVal) != nullptr){
            expr* tmp = (yyvsp[-1].exprVal)->next;
            while(tmp != nullptr){
                emit(param, tmp, nullptr, nullptr, 0, yylineno);
                tmp = tmp->next;
            }
        }
        emit(call, (yyvsp[-3].exprVal), NULL, nullptr, 0,yylineno);        
    
        expr* result = newtemp();
        emit(getretval, result, NULL, NULL, 0, yylineno);

        (yyval.exprVal) = result;
    }
#line 1985 "parser/parser.cpp"
    break;

  case 58: /* call: ID callsuffix  */
#line 466 "parser/parser.y"
                   {
        
        SymbolEntry *sym = symTable.returnSymbol(*(yyvsp[-1].strVal));
        if(!sym){
            symTable.insert(*(yyvsp[-1].strVal), "user function", scope, yylineno);
            sym = symTable.returnSymbol(*(yyvsp[-1].strVal));
        }
        expr* func, *new_Tmp = newtemp();
        if(!hasLibFuncName(*(yyvsp[-1].strVal))){
            func = NewExpr(programfunc_e);
            (yyval.exprVal) = NewExpr(programfunc_e);
        }
        else{
            func = NewExpr(libraryfunc_e);
            (yyval.exprVal) = NewExpr(libraryfunc_e);
        }
        func->sym = sym;
        emit(call, func, nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);
        (yyval.exprVal)->sym = new_Tmp->sym;
        
    }
#line 2012 "parser/parser.cpp"
    break;

  case 59: /* call: LEFT_PARENTHES funcdef RIGHT_PARENTHES callsuffix  */
#line 488 "parser/parser.y"
                                                       {
        expr* new_Tmp = newtemp();
        emit(call, (yyvsp[-2].exprVal), nullptr, nullptr, 0, yylineno);
        emit(getretval, nullptr, nullptr, new_Tmp, 0, yylineno);

        (yyval.exprVal) = NewExpr(programfunc_e);
        (yyval.exprVal)->sym = new_Tmp->sym;
    }
#line 2025 "parser/parser.cpp"
    break;

  case 60: /* call: DOTS ID callsuffix  */
#line 496 "parser/parser.y"
                        {}
#line 2031 "parser/parser.cpp"
    break;

  case 61: /* callsuffix: normcall  */
#line 498 "parser/parser.y"
                     { (yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2037 "parser/parser.cpp"
    break;

  case 62: /* normcall: LEFT_PARENTHES elist RIGHT_PARENTHES  */
#line 502 "parser/parser.y"
                                              {
    if((yyvsp[-1].exprVal) != nullptr){
        expr* tmp = (yyvsp[-1].exprVal)->next;
        while(tmp != nullptr){
            emit(param, tmp, nullptr, nullptr, 0, yylineno);
            tmp = tmp->next;
        }
    }
}
#line 2051 "parser/parser.cpp"
    break;

  case 63: /* elist: %empty  */
#line 513 "parser/parser.y"
        { (yyval.exprVal) = nullptr; }
#line 2057 "parser/parser.cpp"
    break;

  case 64: /* elist: expr  */
#line 514 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(newtable_e);
        (yyval.exprVal)->next = (yyvsp[0].exprVal);
    }
#line 2066 "parser/parser.cpp"
    break;

  case 65: /* elist: elist COMMA expr  */
#line 518 "parser/parser.y"
                       {
        expr* tmp = (yyvsp[-2].exprVal);

        while(tmp->next != nullptr){
            tmp = tmp->next; 
        }
        tmp->next = (yyvsp[0].exprVal);
    }
#line 2079 "parser/parser.cpp"
    break;

  case 72: /* $@3: %empty  */
#line 542 "parser/parser.y"
                    {++scope;}
#line 2085 "parser/parser.cpp"
    break;

  case 73: /* block: LEFT_CBRACKET $@3 stmntlist RIGHT_CBRACKET  */
#line 542 "parser/parser.y"
                                                       {
        symTable.ScopeHide(scope);
        scope--;
    }
#line 2094 "parser/parser.cpp"
    break;

  case 75: /* $@4: %empty  */
#line 549 "parser/parser.y"
                 {
        LoopContext ctx;
        ctx.isLoop = false;
        loopStack.push(ctx);

        string name = "$" + to_string(curr_func);
        symTable.insert(name, "user function", scope, yylineno);
        curr_func_expr.push(NewExpr(programfunc_e));
        curr_func_expr.top()->sym = symTable.returnSymbol(name);
        curr_func++;
        emit(funcstart, nullptr, nullptr, curr_func_expr.top(), 0, yylineno);

        }
#line 2112 "parser/parser.cpp"
    break;

  case 76: /* $@5: %empty  */
#line 561 "parser/parser.y"
                        {++scope; ++scopeSpaceCounter;}
#line 2118 "parser/parser.cpp"
    break;

  case 77: /* $@6: %empty  */
#line 561 "parser/parser.y"
                                                                              {scope--;}
#line 2124 "parser/parser.cpp"
    break;

  case 78: /* $@7: %empty  */
#line 561 "parser/parser.y"
                                                                                         {found_Func = true; ++scopeSpaceCounter;}
#line 2130 "parser/parser.cpp"
    break;

  case 79: /* funcdef: FUNCTION $@4 LEFT_PARENTHES $@5 idlist RIGHT_PARENTHES $@6 $@7 block  */
#line 561 "parser/parser.y"
                                                                                                                                         {
            found_Func = false; 
            emit(funcend, nullptr, nullptr, curr_func_expr.top(), 0, yylineno);
            (yyval.exprVal) = curr_func_expr.top();
            curr_func_expr.pop();

            loopStack.pop();

            scopeSpaceCounter -= 2;
        }
#line 2145 "parser/parser.cpp"
    break;

  case 80: /* $@8: %empty  */
#line 572 "parser/parser.y"
                  {
        LoopContext ctx;
        ctx.isLoop = false;
        loopStack.push(ctx);

        bool isInSmtb = true;
        returnAvailabe.push(1);
        isInSmtb = symTable.lookup(*(yyvsp[0].strVal), scope);

        if(!isInSmtb && !hasLibFuncName(*(yyvsp[0].strVal))) {
            symTable.insert(*(yyvsp[0].strVal), "user function", scope, yylineno);
            curr_func_expr.push(NewExpr(programfunc_e));
            curr_func_expr.top()->sym = symTable.returnSymbol(*(yyvsp[0].strVal));
            emit(funcstart, nullptr, nullptr, curr_func_expr.top(), 0, yylineno);
        }
        if(hasLibFuncName(*(yyvsp[0].strVal))){ yyerror("user function " + *(yyvsp[0].strVal) + " cannot have the same id as a library function"); curr_func_expr.push(nullptr); }
        else if (isInSmtb){ yyerror("redefinition of " + *(yyvsp[0].strVal)); curr_func_expr.push(nullptr);}


    }
#line 2170 "parser/parser.cpp"
    break;

  case 81: /* $@9: %empty  */
#line 591 "parser/parser.y"
                   {++scope; ++scopeSpaceCounter;}
#line 2176 "parser/parser.cpp"
    break;

  case 82: /* $@10: %empty  */
#line 591 "parser/parser.y"
                                                                          {scope--;}
#line 2182 "parser/parser.cpp"
    break;

  case 83: /* $@11: %empty  */
#line 591 "parser/parser.y"
                                                                                     {found_Func = true; ++scopeSpaceCounter;}
#line 2188 "parser/parser.cpp"
    break;

  case 84: /* funcdef: FUNCTION ID $@8 LEFT_PARENTHES $@9 idlist RIGHT_PARENTHES $@10 $@11 block  */
#line 591 "parser/parser.y"
                                                                                                                                     { found_Func = false;
      if(curr_func_expr.top() != nullptr){
            emit(funcend, nullptr, nullptr, curr_func_expr.top(), 0, yylineno);
            (yyval.exprVal) = curr_func_expr.top();
            curr_func_expr.pop(); 
        }
        returnAvailabe.pop();
        loopStack.pop();

        scopeSpaceCounter -= 2;
     }
#line 2204 "parser/parser.cpp"
    break;

  case 85: /* const: INTCONST  */
#line 604 "parser/parser.y"
                {
        (yyval.exprVal) = NewExpr(constnum_e);
        (yyval.exprVal)->numConst = (yyvsp[0].intVal);
    }
#line 2213 "parser/parser.cpp"
    break;

  case 86: /* const: REAL  */
#line 608 "parser/parser.y"
          {
        (yyval.exprVal) = NewExpr(constnum_e);
        (yyval.exprVal)->numConst = (yyvsp[0].realVal);
    }
#line 2222 "parser/parser.cpp"
    break;

  case 87: /* const: STRING  */
#line 612 "parser/parser.y"
            {
        (yyval.exprVal) = NewExpr(conststring_e);
        (yyval.exprVal)->strConst = *(yyvsp[0].strVal);
    }
#line 2231 "parser/parser.cpp"
    break;

  case 88: /* const: NIL  */
#line 616 "parser/parser.y"
         {
        (yyval.exprVal) = NewExpr(nil_e);
    }
#line 2239 "parser/parser.cpp"
    break;

  case 89: /* const: TRUE  */
#line 619 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(constbool_e);
        (yyval.exprVal)->boolConst = true;
    }
#line 2248 "parser/parser.cpp"
    break;

  case 90: /* const: FALSE  */
#line 623 "parser/parser.y"
           {
        (yyval.exprVal) = NewExpr(constbool_e);
        (yyval.exprVal)->boolConst = false;
    }
#line 2257 "parser/parser.cpp"
    break;

  case 92: /* idlist: ID  */
#line 630 "parser/parser.y"
         {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 2271 "parser/parser.cpp"
    break;

  case 93: /* idlist: idlist COMMA ID  */
#line 639 "parser/parser.y"
                      {
        if(!symTable.lookup(*(yyvsp[0].strVal), scope) && !hasLibFuncName(*(yyvsp[0].strVal))){ 
            symTable.insert(*(yyvsp[0].strVal), "formal argument", scope, yylineno);
        }
        else{
            if(hasLibFuncName(*(yyvsp[0].strVal))) yyerror("Argument " + *(yyvsp[0].strVal) + " cannot have the same id as a library function");
            else yyerror("redefinition of " + *(yyvsp[0].strVal));
        }
    }
#line 2285 "parser/parser.cpp"
    break;

  case 94: /* ifstmt: ifprefix stmt  */
#line 650 "parser/parser.y"
                     {
        patchLabel((yyvsp[-1].intVal),  curr_quad);
        (yyval.intVal) = (yyvsp[-1].intVal);
    }
#line 2294 "parser/parser.cpp"
    break;

  case 95: /* $@12: %empty  */
#line 654 "parser/parser.y"
                  {
        patchLabel((yyvsp[-1].intVal), curr_quad + 1);
        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
        (yyvsp[-1].intVal) = curr_quad;
    }
#line 2304 "parser/parser.cpp"
    break;

  case 96: /* ifstmt: ifstmt ELSE $@12 stmt  */
#line 658 "parser/parser.y"
         {
        patchLabel((yyvsp[-3].intVal), curr_quad);
    }
#line 2312 "parser/parser.cpp"
    break;

  case 97: /* ifprefix: IF LEFT_PARENTHES expr RIGHT_PARENTHES  */
#line 663 "parser/parser.y"
                                                 {
        expr *boolExpr = NewExpr(constbool_e);
        boolExpr->boolConst = true;

        emit(if_eq, (yyvsp[-1].exprVal), boolExpr, nullptr, curr_quad + 2, yylineno);
        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);

        (yyval.intVal) = curr_quad;
    }
#line 2326 "parser/parser.cpp"
    break;

  case 98: /* @13: %empty  */
#line 675 "parser/parser.y"
                 { (yyval.intVal) = curr_quad; }
#line 2332 "parser/parser.cpp"
    break;

  case 99: /* @14: %empty  */
#line 675 "parser/parser.y"
                                                                                {
    LoopContext ctx;
    ctx.isLoop = true;
    loopStack.push(ctx);
    
    expr* temp_e =NewExpr(constbool_e);
    temp_e->boolConst = true;
    emit(if_eq,(yyvsp[-1].exprVal),temp_e,nullptr, curr_quad + 2, yylineno);
    emit(jump, nullptr, nullptr,nullptr,0, yylineno);
    (yyval.intVal)=curr_quad;
}
#line 2348 "parser/parser.cpp"
    break;

  case 100: /* whilestmt: WHILE @13 LEFT_PARENTHES expr RIGHT_PARENTHES @14 stmt  */
#line 685 "parser/parser.y"
      {
    
    emit(jump, nullptr, nullptr,nullptr, (yyvsp[-5].intVal) ,yylineno);

    patchLabel((yyvsp[-1].intVal), curr_quad);

    /*Patching breaks and continues*/
    for(int index : loopStack.top().breakList){
        patchLabel(index, curr_quad);
    }

    for(int index : loopStack.top().continueList){
        patchLabel(index, (yyvsp[-5].intVal));
    }

    loopStack.pop();
}
#line 2370 "parser/parser.cpp"
    break;

  case 101: /* @15: %empty  */
#line 704 "parser/parser.y"
                                            { (yyval.intVal) = curr_quad;}
#line 2376 "parser/parser.cpp"
    break;

  case 102: /* @16: %empty  */
#line 704 "parser/parser.y"
                                                                                      {
    LoopContext ctx;
    ctx.isLoop = true;
    loopStack.push(ctx);

    expr* boolConstexpr = NewExpr(constbool_e);
    boolConstexpr->boolConst = true;
    
    emit(if_eq, (yyvsp[-1].exprVal), boolConstexpr, nullptr, 0, yylineno);
    (yyval.intVal) = curr_quad;
    emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
}
#line 2393 "parser/parser.cpp"
    break;

  case 103: /* @17: %empty  */
#line 715 "parser/parser.y"
  {(yyval.intVal) = curr_quad;}
#line 2399 "parser/parser.cpp"
    break;

  case 104: /* @18: %empty  */
#line 715 "parser/parser.y"
                                 {
    patchLabel((yyvsp[-2].intVal), curr_quad + 1);
    emit(jump, nullptr, nullptr, nullptr, (yyvsp[-5].intVal), yylineno);
    (yyval.intVal) = curr_quad;
}
#line 2409 "parser/parser.cpp"
    break;

  case 105: /* forstmt: FOR LEFT_PARENTHES elist SEMICOLON @15 expr SEMICOLON @16 @17 elist @18 RIGHT_PARENTHES stmt  */
#line 719 "parser/parser.y"
                       {
    patchLabel((yyvsp[-5].intVal) + 1, (yyvsp[-2].intVal) + 1);
    emit(jump, nullptr, nullptr, nullptr, (yyvsp[-4].intVal), yylineno);


    /*Patching breaks and continues*/
    for(int index : loopStack.top().breakList){
        patchLabel(index, curr_quad);
    }

    for(int index : loopStack.top().continueList){
        patchLabel(index, (yyvsp[-8].intVal));
    }

    loopStack.pop();
}
#line 2430 "parser/parser.cpp"
    break;

  case 106: /* returnstmt: RETURN SEMICOLON  */
#line 737 "parser/parser.y"
                            {
        if(returnAvailabe.top()){
            emit(ret, nullptr, nullptr, nullptr, 0, yylineno);
        }else{
            yyerror("Return statement outside of fucntion.");
        }
    }
#line 2442 "parser/parser.cpp"
    break;

  case 107: /* returnstmt: RETURN expr SEMICOLON  */
#line 744 "parser/parser.y"
                            {
        if(returnAvailabe.top()){
        emit(ret, nullptr, nullptr, (yyvsp[-1].exprVal), 0, yylineno);}
        else{
            yyerror("Return statement outside of fucntion.");
        }
    }
#line 2454 "parser/parser.cpp"
    break;


#line 2458 "parser/parser.cpp"

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

#line 753 "parser/parser.y"


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

