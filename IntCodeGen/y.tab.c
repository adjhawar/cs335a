/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "list.h"

extern int yylex();
extern int yyparse();
extern FILE *yyin;
FILE *out;
void yyerror(const char *s);
char TEMP[7];
char LABEL[5];
char t[100];
int flag1;
SymtabEntry *p;
Symtab *mainTable,*table;

char* tempVar(){
	static int i=0;
	sprintf(TEMP,"temp%d",i);
	i++;
	return TEMP;
}

char* newLabel(){
	static int z=0;
	sprintf(LABEL,"L%d",z);
	z++;
	return LABEL;
}


#line 102 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    INSTANCEOF = 259,
    NEW = 260,
    SUPER = 261,
    THIS = 262,
    BOOL = 263,
    BYTE = 264,
    CHAR = 265,
    T = 266,
    FLOAT = 267,
    INT = 268,
    F = 269,
    N = 270,
    VOID = 271,
    BREAK = 272,
    CASE = 273,
    DEFAULT = 274,
    ELSE = 275,
    IF = 276,
    SWITCH = 277,
    CONT = 278,
    DO = 279,
    FOR = 280,
    WHILE = 281,
    RETURN = 282,
    CONST = 283,
    CID = 284,
    ID = 285,
    SEP = 286,
    TRM = 287,
    COLON = 288,
    ARRAY_S = 289,
    ARRAY_E = 290,
    BLOCK_S = 291,
    BLOCK_E = 292,
    PAREN_S = 293,
    PAREN_E = 294,
    OP_ASS = 295,
    OP_ADD_ASS = 296,
    OP_SUB_ASS = 297,
    OP_DIV_ASS = 298,
    OP_MUL_ASS = 299,
    OP_MOD_ASS = 300,
    OP_LSH_ASS = 301,
    OP_RSH_ASS = 302,
    OP_AND_ASS = 303,
    OP_OR_ASS = 304,
    OP_XOR_ASS = 305,
    OP_ZRSH_ASS = 306,
    OP_CON_Q = 307,
    OP_CON_AND = 308,
    OP_CON_OR = 309,
    OP_OR = 310,
    OP_XOR = 311,
    OP_AND = 312,
    OP_EQ = 313,
    OP_NEQ = 314,
    OP_GRE = 315,
    OP_LES = 316,
    OP_GEQ = 317,
    OP_LEQ = 318,
    OP_NEG = 319,
    OP_RSH = 320,
    OP_LSH = 321,
    OP_ADD = 322,
    OP_SUB = 323,
    OP_MUL = 324,
    OP_DIV = 325,
    OP_MOD = 326,
    OP_INC = 327,
    OP_DEC = 328,
    OP_DOT = 329,
    OP_ZRSH = 330,
    INT_LIT_D = 331,
    INT_LIT_O = 332,
    INT_LIT_H = 333,
    FLOAT_LIT = 334,
    CHAR_LIT = 335,
    STR_LIT = 336,
    STRING = 337,
    ERROR = 338,
    PRINT = 339,
    SCAN = 340,
    EXTENDS = 341
  };
#endif
/* Tokens.  */
#define CLASS 258
#define INSTANCEOF 259
#define NEW 260
#define SUPER 261
#define THIS 262
#define BOOL 263
#define BYTE 264
#define CHAR 265
#define T 266
#define FLOAT 267
#define INT 268
#define F 269
#define N 270
#define VOID 271
#define BREAK 272
#define CASE 273
#define DEFAULT 274
#define ELSE 275
#define IF 276
#define SWITCH 277
#define CONT 278
#define DO 279
#define FOR 280
#define WHILE 281
#define RETURN 282
#define CONST 283
#define CID 284
#define ID 285
#define SEP 286
#define TRM 287
#define COLON 288
#define ARRAY_S 289
#define ARRAY_E 290
#define BLOCK_S 291
#define BLOCK_E 292
#define PAREN_S 293
#define PAREN_E 294
#define OP_ASS 295
#define OP_ADD_ASS 296
#define OP_SUB_ASS 297
#define OP_DIV_ASS 298
#define OP_MUL_ASS 299
#define OP_MOD_ASS 300
#define OP_LSH_ASS 301
#define OP_RSH_ASS 302
#define OP_AND_ASS 303
#define OP_OR_ASS 304
#define OP_XOR_ASS 305
#define OP_ZRSH_ASS 306
#define OP_CON_Q 307
#define OP_CON_AND 308
#define OP_CON_OR 309
#define OP_OR 310
#define OP_XOR 311
#define OP_AND 312
#define OP_EQ 313
#define OP_NEQ 314
#define OP_GRE 315
#define OP_LES 316
#define OP_GEQ 317
#define OP_LEQ 318
#define OP_NEG 319
#define OP_RSH 320
#define OP_LSH 321
#define OP_ADD 322
#define OP_SUB 323
#define OP_MUL 324
#define OP_DIV 325
#define OP_MOD 326
#define OP_INC 327
#define OP_DEC 328
#define OP_DOT 329
#define OP_ZRSH 330
#define INT_LIT_D 331
#define INT_LIT_O 332
#define INT_LIT_H 333
#define FLOAT_LIT 334
#define CHAR_LIT 335
#define STR_LIT 336
#define STRING 337
#define ERROR 338
#define PRINT 339
#define SCAN 340
#define EXTENDS 341

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "parser.y" /* yacc.c:355  */

	int ival;
	char *sval;
	float fval;
	char *type;
        struct Attr *attr;

#line 322 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 353 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1646

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    91,    92,    95,    96,    97,   100,   101,
     104,   107,   108,   111,   114,   117,   118,   121,   122,   125,
     126,   129,   130,   133,   136,   139,   140,   143,   144,   147,
     154,   155,   158,   159,   162,   165,   169,   175,   178,   184,
     185,   188,   191,   204,   206,   207,   210,   213,   214,   217,
     218,   221,   222,   225,   226,   227,   228,   231,   232,   235,
     236,   239,   240,   241,   244,   245,   248,   251,   254,   257,
     258,   261,   262,   266,   267,   270,   273,   276,   277,   278,
     279,   280,   281,   282,   285,   286,   287,   288,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   303,   306,
     309,   310,   311,   312,   313,   314,   317,   320,   331,   348,
     365,   375,   378,   379,   382,   383,   387,   397,   401,   419,
     437,   455,   478,   502,   503,   506,   507,   510,   511,   514,
     515,   518,   521,   522,   525,   531,   537,   545,   546,   549,
     579,   580,   581,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   598,   599,   602,   603,   611,
     612,   620,   621,   629,   630,   638,   639,   647,   648,   654,
     662,   663,   669,   675,   681,   687,   691,   692,   698,   704,
     713,   714,   720,   728,   729,   735,   741,   749,   750,   753,
     754,   755,   762,   769,   772,   778,   784,   785,   792,   795,
     806,   817,   818,   819,   820,   823,   824,   825,   828,   829,
     832,   833,   836,   837,   838,   839,   840,   841,   845,   848,
     851,   852,   855,   856,   859,   860,   863,   864,   867,   868,
     871,   872,   875,   876,   879,   883,   887,   891,   895,   899,
     903,   909,   910,   911,   914
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "INSTANCEOF", "NEW", "SUPER",
  "THIS", "BOOL", "BYTE", "CHAR", "T", "FLOAT", "INT", "F", "N", "VOID",
  "BREAK", "CASE", "DEFAULT", "ELSE", "IF", "SWITCH", "CONT", "DO", "FOR",
  "WHILE", "RETURN", "CONST", "CID", "ID", "SEP", "TRM", "COLON",
  "ARRAY_S", "ARRAY_E", "BLOCK_S", "BLOCK_E", "PAREN_S", "PAREN_E",
  "OP_ASS", "OP_ADD_ASS", "OP_SUB_ASS", "OP_DIV_ASS", "OP_MUL_ASS",
  "OP_MOD_ASS", "OP_LSH_ASS", "OP_RSH_ASS", "OP_AND_ASS", "OP_OR_ASS",
  "OP_XOR_ASS", "OP_ZRSH_ASS", "OP_CON_Q", "OP_CON_AND", "OP_CON_OR",
  "OP_OR", "OP_XOR", "OP_AND", "OP_EQ", "OP_NEQ", "OP_GRE", "OP_LES",
  "OP_GEQ", "OP_LEQ", "OP_NEG", "OP_RSH", "OP_LSH", "OP_ADD", "OP_SUB",
  "OP_MUL", "OP_DIV", "OP_MOD", "OP_INC", "OP_DEC", "OP_DOT", "OP_ZRSH",
  "INT_LIT_D", "INT_LIT_O", "INT_LIT_H", "FLOAT_LIT", "CHAR_LIT",
  "STR_LIT", "STRING", "ERROR", "PRINT", "SCAN", "EXTENDS", "$accept",
  "compilation_unit", "type_declarations_e", "type_declarations",
  "type_declaration", "class_declaration", "super_e", "supers",
  "class_body", "class_body_decl_e", "class_body_decls", "class_body_decl",
  "class_mem_decl", "const_decl", "const_declarator", "formal_para_list_e",
  "formal_para_list", "formal_para", "const_body", "explicit_const_invo",
  "field_decl", "var_declarators", "var_declarator", "var_decl_id",
  "method_decl", "method_header", "method_declarator", "method_body",
  "array_init", "var_init_e", "var_inits", "var_init", "type",
  "primitive_type", "numeric_type", "integer_type", "reference_type",
  "class_type", "array_type", "block", "bl_statements_e", "bl_statements",
  "block_statement", "loc_var_dec_st", "loc_var_dec", "statement",
  "st_no_short_if", "st_wo_tsub", "empty_st", "expr_st", "st_expr",
  "if_then_st", "if_then_else_st", "if_then_else_no_short_if_st",
  "switch_st", "switch_block", "switch_block_st_gr_e",
  "switch_block_st_grps", "switch_block_st_grp", "while_st",
  "while_st_no_short_if", "do_st", "for_st", "for_st_no_short_if",
  "for_init_e", "for_init", "expr_e", "for_update_e", "for_update",
  "st_expr_list", "break_st", "continue_st", "return_st", "expr", "assgn",
  "lhs", "assgn_op", "cond_expr", "cond_or_expr", "cond_and_expr",
  "incl_or_expr", "excl_or_expr", "and_expr", "equality_expr", "rel_expr",
  "shift_expr", "add_expr", "mul_expr", "cast_expr", "unary_expr",
  "preinc_expr", "predec_expr", "unary_expr_not_plus_minus",
  "postdec_expr", "postinc_expr", "postfix_expr", "method_invo",
  "field_access", "primary", "primary_no_new_array", "object_expr",
  "arg_list_e", "argument_list", "array_creat_expr", "dim_expr",
  "array_access", "type_name", "name", "literal", "int_literal",
  "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

#define YYPACT_NINF -352

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-352)))

#define YYTABLE_NINF -205

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,    41,    27,  -352,    74,  -352,    12,  -352,  -352,  -352,
      59,  -352,     6,  -352,  -352,  -352,    27,    63,  -352,  -352,
    -352,    24,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
      64,   125,  -352,  -352,  -352,    75,  -352,  -352,    -9,    37,
    -352,  -352,  -352,  -352,  -352,  -352,    84,  -352,  -352,  1017,
    -352,  -352,  1099,  -352,  -352,    92,   129,    11,  -352,    68,
    -352,   223,    99,   115,   -22,   105,  -352,  -352,  -352,   140,
     137,   139,   155,  1345,   153,   160,   674,  -352,  -352,   674,
     674,   674,  -352,  -352,  -352,  -352,  -352,  -352,   168,   170,
    1099,   112,  -352,   173,  1181,  -352,  -352,   184,  -352,  -352,
    -352,  -352,   189,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,   243,  -352,  -352,    86,   113,   117,    34,
     673,   151,   192,    49,  -352,   791,   727,  -352,  -352,  -352,
     154,  -352,   181,   223,  -352,   197,  -352,   202,  1474,   203,
     210,  -352,   112,  -352,  -352,   209,   114,   674,   214,   674,
    -352,   674,   674,  -352,   108,   219,  1454,   674,   569,   674,
     674,   674,   215,  -352,  -352,  -352,    97,   193,   194,   201,
     191,    61,    15,    30,   135,   110,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,   117,  -352,  -352,   220,  -352,  -352,  -352,
     -12,  -352,  1474,   214,   216,  -352,   227,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,   674,  -352,  -352,   214,   674,   674,   674,
     214,  -352,   221,  -352,  -352,  1474,  -352,  -352,  -352,  -352,
     266,   229,  1510,  -352,   674,  -352,  -352,   222,   235,   230,
     232,   233,   234,   242,  -352,  -352,   249,  -352,   265,   260,
     270,   267,   268,  -352,  -352,  -352,  -352,   674,   674,   674,
     674,   674,   674,   674,   674,   266,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,  -352,    73,
    -352,   269,  -352,  -352,   271,   275,   276,   273,  -352,  -352,
     278,   282,  -352,  -352,   283,   280,  -352,   674,   674,  -352,
    1373,   281,   674,   674,  1554,  1345,   674,  1565,   288,   193,
     194,   201,   191,    61,    15,    15,   292,    30,    30,    30,
      30,   135,   135,   135,   110,   110,  -352,  -352,  -352,  1474,
    -352,  -352,   674,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
     290,   284,   289,   294,  -352,   313,   314,  -352,  -352,  -352,
     186,  -352,   296,   304,  -352,  -352,  -352,  -352,   674,  -352,
     300,  -352,   674,  1454,   674,  1345,   674,   311,   309,   186,
    -352,   319,  1554,  -352,  -352,   320,   326,   329,  -352,   332,
    1263,  -352,  -352,  -352,   333,  -352,   265,  1373,   674,  1373,
    1263,   853,  1345,   353,   342,  -352,   935,  -352,  1373,  1554,
    -352,   336,  1373,  -352
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     2,     3,     5,     8,     7,
       0,   230,    12,     1,     6,   231,     0,     0,    11,    13,
      66,     0,    10,    58,    61,    62,    60,    63,    55,    56,
       0,     0,    17,    19,    20,     0,    21,    22,     0,     0,
      53,    57,    59,    54,    64,    65,    66,    14,    18,     0,
      23,    45,     0,    41,    44,    39,     0,     0,    35,    37,
      42,     0,     0,     0,     0,   213,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,   128,   244,    98,     0,
       0,     0,   243,   242,   241,   235,   236,   237,     0,     0,
       0,     0,    88,     0,     0,    71,    73,     0,    74,    77,
      89,    90,     0,    78,    79,    91,    80,    92,    81,    93,
      94,    95,   100,     0,   101,   103,   104,   102,     0,   217,
     216,   201,   210,   215,   211,   218,   202,   212,   234,   232,
       0,   213,     0,     0,    67,     0,    34,     0,     0,     0,
      25,    27,     0,    82,    83,     0,     0,   221,     0,   221,
     134,     0,     0,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   138,   137,   155,   157,   159,   161,
     163,   165,   167,   170,   176,   180,   198,   183,   189,   190,
     193,   204,   203,   196,   217,   215,     0,   194,   216,   218,
     202,   195,     0,     0,     0,    39,    76,    31,    72,    75,
      99,   143,   147,   148,   145,   144,   146,   149,   150,   152,
     154,   153,   151,     0,   200,   199,     0,     0,     0,   221,
       0,    68,     0,    36,    40,    48,    52,    38,    51,    24,
       0,    29,     0,   224,   221,   225,   222,     0,   220,   209,
       0,     0,     0,     0,   126,   132,     0,   123,   125,     0,
       0,    53,    54,   197,   191,   192,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,     0,
      49,     0,    30,   139,   208,     0,     0,     0,   233,    43,
       0,    47,    28,   227,     0,     0,    33,     0,   221,    32,
       0,     0,     0,   128,     0,     0,     0,     0,     0,   158,
     160,   162,   164,   166,   168,   169,   175,   172,   171,   174,
     173,   178,   177,   179,   181,   182,   184,   185,   186,     0,
      97,    96,   221,   229,   228,   205,    46,   226,   219,   223,
       0,     0,     0,     0,   107,     0,    77,    85,    86,    87,
     113,   110,     0,     0,   133,   118,   187,   188,     0,    50,
       0,   207,     0,     0,     0,     0,     0,     0,     0,   112,
     114,     0,   130,   156,   206,     0,     0,     0,   108,     0,
       0,   111,   115,   120,     0,   129,   131,     0,   128,     0,
       0,     0,     0,     0,     0,   119,     0,   121,     0,   130,
     109,     0,     0,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -352,  -352,  -352,  -352,   370,  -352,  -352,  -352,  -352,  -352,
    -352,   347,  -352,  -352,  -352,   246,  -352,   150,  -352,  -352,
    -352,   291,   255,   239,  -352,  -352,  -352,  -352,  -352,  -352,
     166,  -132,    -1,   -55,  -352,  -352,  -148,     5,  -352,   356,
     -39,  -351,   -93,  -352,  -154,   167,  -224,  -289,  -352,  -352,
    -149,  -352,  -352,  -352,  -352,  -352,  -352,  -352,    28,  -352,
    -352,  -352,  -352,  -352,    38,  -352,  -294,     7,  -352,  -341,
    -352,  -352,  -352,   400,   -49,  -352,  -352,    46,  -352,   147,
     149,   157,   152,   158,   -51,  -100,   -88,   -54,  -352,   -76,
     -35,    -3,   107,    20,    66,    98,   121,   401,  -352,  -352,
     144,  -137,  -352,  -352,   277,   523,    33,   550,  -352,  -352,
    -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    17,    18,    22,    30,
      31,    32,    33,    34,    35,   139,   140,   141,    50,    90,
      36,    57,    58,    59,    37,    38,    60,    53,   226,   290,
     279,   280,    91,    40,    41,    42,    43,    44,    45,    92,
      93,    94,    95,    96,    97,    98,   345,    99,   100,   101,
     102,   103,   104,   347,   105,   351,   368,   369,   370,   106,
     348,   107,   108,   349,   246,   247,   162,   384,   385,   248,
     109,   110,   111,   236,   164,   113,   213,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   120,   121,   122,
     185,   237,   238,   124,   233,   125,    20,   126,   127,   128,
     129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     112,   198,   244,   112,   187,   191,   227,   245,   145,   353,
     252,   346,   240,   132,   114,     2,   147,   114,   239,   265,
      39,    19,   218,    51,   112,    10,   219,    52,    10,   391,
      39,   386,    23,    24,    25,    12,    26,    27,   114,   396,
      28,   112,   135,   136,     3,   112,   115,    -4,     1,   115,
       2,   194,   148,    11,    46,   114,    11,     9,   386,   114,
     142,   -16,   220,   281,    46,  -105,  -105,    55,   146,   116,
     115,    56,   116,  -105,    13,   266,   267,   268,   269,     3,
    -106,  -106,   287,   253,   254,   255,   284,   115,  -106,    15,
     288,   115,    16,   116,   394,   270,   271,   295,   346,    21,
     346,    47,   137,   251,   329,   272,    29,   112,   138,   346,
     116,    49,   330,   346,   116,   117,    10,   316,   117,   263,
     264,   114,    61,    23,    24,    25,    10,    26,    27,    15,
     133,   143,   142,    23,    24,    25,   144,    26,    27,   117,
     143,    28,   195,   149,    11,   144,    56,   118,   232,   257,
     118,   258,   234,   115,    11,   354,   117,   250,  -204,  -204,
     117,   340,   -15,   393,   134,   395,   317,   318,   319,   320,
     119,   118,   150,   119,   400,   151,   116,   152,   403,   275,
     276,   277,   321,   322,   323,  -203,  -203,   153,   118,   214,
     215,   156,   118,   123,   119,   360,   123,   359,   157,   326,
     327,   328,   273,   274,   366,   367,   192,    29,   193,   244,
     197,   119,   314,   315,   245,   119,   199,   123,   221,   324,
     325,   200,   117,   245,    10,   216,   217,   195,   148,   142,
     356,    23,    24,    25,   123,    26,    27,   224,   123,    28,
     155,   230,   229,   232,    77,   243,   259,   256,   262,   260,
     245,   112,    11,   282,   118,   112,   112,   261,   135,   278,
     289,   296,   -26,   137,   250,   114,   297,    10,   298,   114,
     114,   299,   300,   301,    23,    24,    25,   119,    26,    27,
     302,   303,    28,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    11,   304,   115,   198,   305,
     123,   115,   115,   198,    56,    29,   306,   307,   331,   332,
     333,   334,   335,   329,   112,   336,   112,   350,   337,   338,
     116,   358,   362,   112,   116,   116,   -54,   363,   114,   361,
     114,   112,   364,   365,   -84,   371,   372,   114,   112,   374,
     112,   112,   112,   112,   380,   114,   381,   112,    29,   112,
     112,   383,   114,   112,   114,   114,   114,   114,   388,   387,
     115,   114,   115,   114,   114,   390,   117,   114,   389,   115,
     117,   117,   392,   398,   399,   402,    14,   115,    48,   222,
     292,   231,   196,   116,   115,   116,   115,   115,   115,   115,
     223,   291,   116,   115,    54,   115,   115,   382,   118,   115,
     116,   376,   118,   118,   373,   309,   401,   116,   310,   116,
     116,   116,   116,   312,   357,     0,   116,   311,   116,   116,
     313,   119,   116,   235,     0,   119,   119,     0,     0,   117,
       0,   117,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,     0,   123,     0,   117,     0,   123,   123,
       0,     0,     0,   117,     0,   117,   117,   117,   117,     0,
       0,   118,   117,   118,   117,   117,     0,   344,   117,     0,
     118,     0,   355,     0,     0,     0,   163,     0,   118,   186,
       0,   188,   188,     0,   119,   118,   119,   118,   118,   118,
     118,     0,     0,   119,   118,     0,   118,   118,     0,     0,
     118,   119,     0,     0,     0,     0,     0,   123,   119,   123,
     119,   119,   119,   119,     0,     0,   123,   119,     0,   119,
     119,     0,     0,   119,   123,     0,     0,     0,     0,     0,
       0,   123,   378,   123,   123,   123,   123,     0,   228,     0,
     123,     0,   123,   123,     0,     0,   123,     0,     0,     0,
       0,   241,   242,     0,   344,     0,   355,   249,   186,   397,
     188,   188,   188,     0,     0,   378,     0,     0,     0,   397,
      10,     0,     0,     0,    63,   130,   131,    23,    24,    25,
      66,    26,    27,    67,    68,    28,     0,     0,     0,     0,
       0,     0,   228,     0,     0,     0,     0,     0,    11,    77,
       0,     0,     0,   189,   189,     0,     0,   158,     0,     0,
       0,     0,     0,   283,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
     190,   190,   294,   159,     0,     0,   160,   161,     0,     0,
       0,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    29,     0,     0,     0,     0,     0,   308,     0,   188,
     188,   188,   188,   188,   188,   188,     0,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,    63,
     130,   131,   189,   189,   189,    66,     0,     0,    67,    68,
       0,     0,     0,     0,     0,     0,     0,   339,     0,     0,
       0,     0,   352,   163,    77,     0,     0,   188,   188,   190,
     190,   190,   158,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,     0,     0,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,   159,     0,
       0,   160,   161,     0,     0,     0,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,   188,
       0,   218,   375,     0,   377,   219,   379,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,     0,
       0,   189,   189,   189,   189,   189,   189,   189,   163,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   220,     0,     0,     0,     0,     0,     0,   190,   190,
     190,   190,   190,   190,   190,     0,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,     0,   189,
     189,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,   190,   190,    63,   130,
     131,    23,    24,    25,    66,    26,    27,    67,    68,    28,
      69,  -117,  -117,     0,    70,    71,    72,    73,    74,    75,
      76,   189,    11,    77,     0,    78,     0,     0,     0,    52,
    -117,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    29,    62,    88,    89,     0,
      63,   130,   131,    23,    24,    25,    66,    26,    27,    67,
      68,    28,    69,  -116,  -116,     0,    70,    71,    72,    73,
      74,    75,    76,     0,    11,    77,     0,    78,     0,     0,
       0,    52,  -116,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    29,    62,    88,
      89,     0,    63,    64,    65,    23,    24,    25,    66,    26,
      27,    67,    68,    28,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,     0,    11,    77,     0,    78,
       0,     0,     0,    52,   -70,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    29,
      62,    88,    89,     0,    63,   130,   131,    23,    24,    25,
      66,    26,    27,    67,    68,    28,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,     0,    11,    77,
       0,    78,     0,     0,     0,    52,   -70,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    29,    62,    88,    89,     0,    63,   130,   131,    23,
      24,    25,    66,    26,    27,    67,    68,    28,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,     0,
      11,    77,     0,    78,     0,     0,     0,    52,   -69,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    29,    62,    88,    89,     0,    63,   130,
     131,    23,    24,    25,    66,    26,    27,    67,    68,    28,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,     0,    11,    77,     0,    78,     0,     0,     0,    52,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    29,   154,    88,    89,     0,
      63,   130,   131,     0,     0,     0,    66,     0,     0,    67,
      68,     0,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,     0,   154,    77,     0,    78,    63,   130,
     131,    52,     0,    79,    66,     0,     0,    67,    68,     0,
      69,     0,     0,     0,   341,    71,    72,    73,   342,   343,
      76,     0,     0,    77,     0,    78,     0,     0,     0,    52,
       0,    79,     0,     0,     0,     0,     0,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,     0,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    10,     0,    88,    89,    63,
     130,   131,    23,    24,    25,    66,    26,    27,    67,    68,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    63,
     130,   131,     0,    11,    77,    66,  -124,     0,    67,    68,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
     225,     0,   158,     0,     0,    63,   130,   131,     0,     0,
       0,    66,     0,     0,    67,    68,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    29,     0,   159,     0,
      77,   160,   161,     0,     0,   293,    80,    81,   158,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,    63,
     130,   131,     0,     0,     0,    66,     0,     0,    67,    68,
      63,   130,   131,     0,   159,     0,    66,   160,   161,    67,
      68,     0,    80,    81,    77,     0,    82,    83,    84,    85,
      86,    87,    79,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,   159,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      49,    94,   156,    52,    80,    81,   138,   156,    63,   303,
     158,   300,   149,    52,    49,     3,    38,    52,   148,     4,
      21,    16,    34,    32,    73,     1,    38,    36,     1,   380,
      31,   372,     8,     9,    10,     2,    12,    13,    73,   390,
      16,    90,    31,    32,    32,    94,    49,     0,     1,    52,
       3,    90,    74,    29,    21,    90,    29,    16,   399,    94,
      61,    37,    74,   193,    31,    31,    32,    30,    63,    49,
      73,    34,    52,    39,     0,    60,    61,    62,    63,    32,
      31,    32,   219,   159,   160,   161,   216,    90,    39,    30,
     220,    94,    86,    73,   388,    65,    66,   234,   387,    36,
     389,    37,    34,   158,    31,    75,    82,   156,    40,   398,
      90,    36,    39,   402,    94,    49,     1,   265,    52,    58,
      59,   156,    38,     8,     9,    10,     1,    12,    13,    30,
      38,    32,   133,     8,     9,    10,    37,    12,    13,    73,
      32,    16,    30,    38,    29,    37,    34,    49,    34,    52,
      52,    54,    38,   156,    29,   304,    90,   158,    72,    73,
      94,   298,    37,   387,    35,   389,   266,   267,   268,   269,
      49,    73,    32,    52,   398,    38,   156,    38,   402,    69,
      70,    71,   270,   271,   272,    72,    73,    32,    90,    72,
      73,    38,    94,    49,    73,   332,    52,   329,    38,   275,
     276,   277,    67,    68,    18,    19,    38,    82,    38,   363,
      37,    90,   263,   264,   363,    94,    32,    73,    37,   273,
     274,    32,   156,   372,     1,    74,    34,    30,    74,   230,
     306,     8,     9,    10,    90,    12,    13,    35,    94,    16,
      73,    31,    39,    34,    30,    26,    53,    32,    57,    55,
     399,   300,    29,    37,   156,   304,   305,    56,    31,    39,
      39,    39,    39,    34,   265,   300,    31,     1,    38,   304,
     305,    39,    39,    39,     8,     9,    10,   156,    12,    13,
      38,    32,    16,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    29,    31,   300,   391,    39,
     156,   304,   305,   396,    34,    82,    39,    39,    39,    38,
      35,    35,    39,    31,   363,    37,   365,    36,    35,    39,
     300,    33,    38,   372,   304,   305,    34,    38,   363,    39,
     365,   380,    38,    20,    20,    39,    32,   372,   387,    39,
     389,   390,   391,   392,    33,   380,    37,   396,    82,   398,
     399,    32,   387,   402,   389,   390,   391,   392,    32,    39,
     363,   396,   365,   398,   399,    33,   300,   402,    39,   372,
     304,   305,    39,    20,    32,    39,     6,   380,    31,   133,
     230,   142,    91,   363,   387,   365,   389,   390,   391,   392,
     135,   225,   372,   396,    38,   398,   399,   369,   300,   402,
     380,   363,   304,   305,   358,   258,   399,   387,   259,   389,
     390,   391,   392,   261,   307,    -1,   396,   260,   398,   399,
     262,   300,   402,   146,    -1,   304,   305,    -1,    -1,   363,
      -1,   365,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,    -1,    -1,   300,    -1,   380,    -1,   304,   305,
      -1,    -1,    -1,   387,    -1,   389,   390,   391,   392,    -1,
      -1,   363,   396,   365,   398,   399,    -1,   300,   402,    -1,
     372,    -1,   305,    -1,    -1,    -1,    76,    -1,   380,    79,
      -1,    80,    81,    -1,   363,   387,   365,   389,   390,   391,
     392,    -1,    -1,   372,   396,    -1,   398,   399,    -1,    -1,
     402,   380,    -1,    -1,    -1,    -1,    -1,   363,   387,   365,
     389,   390,   391,   392,    -1,    -1,   372,   396,    -1,   398,
     399,    -1,    -1,   402,   380,    -1,    -1,    -1,    -1,    -1,
      -1,   387,   365,   389,   390,   391,   392,    -1,   138,    -1,
     396,    -1,   398,   399,    -1,    -1,   402,    -1,    -1,    -1,
      -1,   151,   152,    -1,   387,    -1,   389,   157,   158,   392,
     159,   160,   161,    -1,    -1,   398,    -1,    -1,    -1,   402,
       1,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    80,    81,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      80,    81,   232,    64,    -1,    -1,    67,    68,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,   257,    -1,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     5,
       6,     7,   159,   160,   161,    11,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,
      -1,    -1,   302,   303,    30,    -1,    -1,   306,   307,   159,
     160,   161,    38,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,   329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    67,    68,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,   358,
      -1,    34,   362,    -1,   364,    38,   366,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,   258,   259,   260,   261,   262,   263,   264,   388,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,    74,    -1,    -1,    -1,    -1,    -1,    -1,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,    -1,   306,
     307,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,   306,   307,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,   358,    29,    30,    -1,    32,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,     1,    84,    85,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,     1,    84,
      85,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
       1,    84,    85,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,     1,    84,    85,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,     1,    84,    85,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    -1,    -1,    36,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,     1,    84,    85,    -1,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,     1,    30,    -1,    32,     5,     6,
       7,    36,    -1,    38,    11,    -1,    -1,    14,    15,    -1,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    36,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,     1,    -1,    84,    85,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,    -1,    29,    30,    11,    32,    -1,    14,    15,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    15,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    -1,    64,    -1,
      30,    67,    68,    -1,    -1,    35,    72,    73,    38,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,
       5,     6,     7,    -1,    64,    -1,    11,    67,    68,    14,
      15,    -1,    72,    73,    30,    -1,    76,    77,    78,    79,
      80,    81,    38,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    64,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    32,    88,    89,    90,    91,    92,    16,
       1,    29,   193,     0,    91,    30,    86,    93,    94,   124,
     193,    36,    95,     8,     9,    10,    12,    13,    16,    82,
      96,    97,    98,    99,   100,   101,   107,   111,   112,   119,
     120,   121,   122,   123,   124,   125,   193,    37,    98,    36,
     105,    32,    36,   114,   126,    30,    34,   108,   109,   110,
     113,    38,     1,     5,     6,     7,    11,    14,    15,    17,
      21,    22,    23,    24,    25,    26,    27,    30,    32,    38,
      72,    73,    76,    77,    78,    79,    80,    81,    84,    85,
     106,   119,   126,   127,   128,   129,   130,   131,   132,   134,
     135,   136,   137,   138,   139,   141,   146,   148,   149,   157,
     158,   159,   161,   162,   177,   178,   180,   181,   182,   183,
     184,   185,   186,   187,   190,   192,   194,   195,   196,   197,
       6,     7,   127,    38,    35,    31,    32,    34,    40,   102,
     103,   104,   119,    32,    37,   120,   124,    38,    74,    38,
      32,    38,    38,    32,     1,   132,    38,    38,    38,    64,
      67,    68,   153,   160,   161,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   187,   160,   176,   184,   192,
     194,   176,    38,    38,   127,    30,   108,    37,   129,    32,
      32,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   163,    72,    73,    74,    34,    34,    38,
      74,    37,   102,   109,    35,    36,   115,   118,   160,    39,
      31,   110,    34,   191,    38,   191,   160,   188,   189,   197,
     188,   160,   160,    26,   131,   137,   151,   152,   156,   160,
     119,   120,   123,   176,   176,   176,    32,    52,    54,    53,
      55,    56,    57,    58,    59,     4,    60,    61,    62,    63,
      65,    66,    75,    67,    68,    69,    70,    71,    39,   117,
     118,   197,    37,   160,   197,   160,   160,   188,   197,    39,
     116,   117,   104,    35,   160,   188,    39,    31,    38,    39,
      39,    39,    38,    32,    31,    39,    39,    39,   160,   166,
     167,   168,   169,   170,   171,   171,   123,   172,   172,   172,
     172,   173,   173,   173,   174,   174,   176,   176,   176,    31,
      39,    39,    38,    35,    35,    39,    37,    35,    39,   160,
     188,    21,    25,    26,   132,   133,   134,   140,   147,   150,
      36,   142,   160,   153,   137,   132,   176,   179,    33,   118,
     188,    39,    38,    38,    38,    20,    18,    19,   143,   144,
     145,    39,    32,   164,    39,   160,   151,   160,   132,   160,
      33,    37,   145,    32,   154,   155,   156,    39,    32,    39,
      33,   128,    39,   133,   153,   133,   128,   132,    20,    32,
     133,   154,    39,   133
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    93,    93,    94,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   102,   102,   103,   103,   104,
     105,   105,   106,   106,   107,   108,   108,   109,   109,   110,
     110,   111,   112,   113,   114,   114,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   124,   125,   126,   127,
     127,   128,   128,   129,   129,   130,   131,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   135,   136,
     137,   137,   137,   137,   137,   137,   137,   138,   139,   140,
     141,   142,   143,   143,   144,   144,   145,   145,   146,   147,
     148,   149,   150,   151,   151,   152,   152,   153,   153,   154,
     154,   155,   156,   156,   157,   158,   159,   160,   160,   161,
     162,   162,   162,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   164,   164,   165,   165,   166,
     166,   167,   167,   168,   168,   169,   169,   170,   170,   170,
     171,   171,   171,   171,   171,   171,   172,   172,   172,   172,
     173,   173,   173,   174,   174,   174,   174,   175,   175,   176,
     176,   176,   176,   176,   177,   178,   179,   179,   179,   180,
     181,   182,   182,   182,   182,   183,   183,   183,   184,   184,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   195,   195,   195,   195,
     195,   196,   196,   196,   197
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     2,     2,     1,     1,
       4,     1,     0,     2,     3,     1,     0,     1,     2,     1,
       1,     1,     1,     2,     4,     1,     0,     1,     3,     2,
       4,     3,     4,     4,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     4,     1,     1,     3,     1,     0,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       0,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     7,
       5,     3,     1,     0,     1,     2,     4,     3,     5,     5,
       7,     9,     9,     1,     0,     1,     1,     1,     0,     1,
       0,     1,     1,     3,     2,     2,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     4,     4,     1,
       1,     2,     2,     1,     2,     2,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     4,     6,     6,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     5,
       1,     0,     1,     3,     3,     3,     3,     2,     4,     4,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:
#line 97 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "parser.y" /* yacc.c:1646  */
    {strcpy(table->name,(yyvsp[-2].sval));}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);printList((yyvsp[0].attr)->code);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);printList((yyvsp[0].attr)->code);}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						 strcpy((yyval.attr)->place,(yyvsp[0].sval));
						 strcpy((yyval.attr)->type,(yyvsp[-1].type));
						 p=Insert(table,(yyvsp[0].sval),(yyvsp[-1].type));
						 (yyval.attr)->code=NULL;}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
						 strcpy((yyval.attr)->type,(yyvsp[-1].type));
						 p=Insert(table,(yyvsp[0].attr)->place,(yyval.attr)->type);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-2].attr);
						 strcpy((yyval.attr)->type,(yyvsp[-3].type));
						 (yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
						 p=Insert(table,(yyvsp[0].attr)->place,(yyval.attr)->type);}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								(yyval.attr)->code=NULL;	
								strcpy((yyval.attr)->place,(yyvsp[0].sval));}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								sprintf(t,"%s = %s",(yyvsp[-2].sval),(yyvsp[0].attr)->place);
								(yyval.attr)->code=append(NULL,newList(t));	
								strcpy((yyval.attr)->place,(yyvsp[-2].sval));}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-2].sval);}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);(yyval.attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);table=table->prev;}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								strcpy((yyval.attr)->place,(yyvsp[0].sval));
								strcpy((yyval.attr)->type,(yyvsp[-1].type));
				 				strcat((yyval.attr)->type,"_func");
								sprintf(t,"label,%s",(yyvsp[0].sval));
								(yyval.attr)->code=newList(t);
				  				p=Insert(table,(yyvsp[0].sval),(yyval.attr)->type);
								p->func=(Symtab *)malloc(sizeof(Symtab));
								p->func->prev=table;
								table=p->func;
								strcpy(table->name,(yyvsp[0].sval));}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-3].sval);}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 235 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 236 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 241 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 258 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);
							 (yyval.attr)=(yyvsp[-1].attr);}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 267 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 282 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 293 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
					sprintf(t,"call, %s",(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 320 "parser.y" /* yacc.c:1646  */
    { char end[5];
									  strcpy(end,newLabel());
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,"label , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 331 "parser.y" /* yacc.c:1646  */
    { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());		
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-4].attr)->code);
									  sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-4].attr)->place,else_beg);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  sprintf(t,"goto , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,"label , %s",else_beg);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,"label , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  
									   	  }
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 349 "parser.y" /* yacc.c:1646  */
    { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-4].attr)->code);
									  sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-4].attr)->place,else_beg);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  sprintf(t,"goto , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,"label , %s",else_beg);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,"label , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t)); }
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 365 "parser.y" /* yacc.c:1646  */
    {  char end[5];
							 	strcpy(end,newLabel());
								(yyval.attr)=(yyvsp[0].attr);
								patchBreak((yyvsp[0].attr)->code,end);
								sprintf(t,"label,%s",end);
								(yyval.attr)->code = append((yyval.attr)->code,newList(t));
								patchSwitch((yyval.attr)->code,(yyvsp[-2].attr)->place);
								}
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 375 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 383 "parser.y" /* yacc.c:1646  */
    {   (yyval.attr)=(yyvsp[-1].attr);
									(yyval.attr)->code= append((yyval.attr)->code,(yyvsp[0].attr)->code);}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval.attr)=(Attr*)malloc(sizeof(Attr));
								char nexLabel[5];
								strcpy(nexLabel,newLabel());
								sprintf(t,"ifgoto,neq,%s,        ,%s",(yyvsp[-2].attr)->place,nexLabel);
								(yyval.attr)->code=newList(t);
								(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
								sprintf(t,"label,%s",nexLabel);
								(yyval.attr)->code=append((yyval.attr)->code,newList(t));
								(yyval.attr)->code->swt = 1;	}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 397 "parser.y" /* yacc.c:1646  */
    { (yyval.attr)=(Attr*)malloc(sizeof(Attr));
								(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);	}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 401 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());	
                                                                          sprintf(t,"label , %s",begin);
                                                                          (yyval.attr)=(Attr *)malloc(sizeof(Attr));
									  patchBreak((yyvsp[0].attr)->code,end);
									  patchContinue((yyvsp[0].attr)->code,begin);	
       								          (yyval.attr)->code = newList(t);
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,"goto , %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,"label , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 419 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
									  patchBreak((yyvsp[0].attr)->code,end);
									  patchContinue((yyvsp[0].attr)->code,begin);	
                                                                          sprintf(t,"label , %s",begin);
                                                                          (yyval.attr)=(Attr *)malloc(sizeof(Attr));
       								          (yyval.attr)->code = newList(t);
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,"goto , %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,"label , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 437 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
									  patchBreak((yyvsp[-5].attr)->code,end);
									  patchContinue((yyvsp[-5].attr)->code,begin);		
                                                                          sprintf(t,"label , %s",begin);
                                                                          (yyval.attr)=(Attr *)malloc(sizeof(Attr));
       								          (yyval.attr)->code = newList(t);
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-5].attr)->code);
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  sprintf(t,"goto , %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,"label , %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 455 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5],cont[5];
									  			strcpy(begin,newLabel());
									  			strcpy(end,newLabel());
												strcpy(cont,newLabel());
												patchBreak((yyvsp[0].attr)->code,end);
									                        patchContinue((yyvsp[0].attr)->code,cont);	
												(yyval.attr)=(Attr *)malloc(sizeof(Attr));
												(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-6].attr)->code);
												sprintf(t,"label , %s",begin);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-4].attr)->code);
												sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-4].attr)->place,end);
									  			(yyval.attr)->code = append((yyval.attr)->code ,newList(t));
       								          			(yyval.attr)->code = append((yyval.attr)->code , (yyvsp[0].attr)->code);
												sprintf(t,"label , %s",cont);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                      						          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  			sprintf(t,"goto , %s",begin);
       								          		        (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  		        sprintf(t,"label , %s",end);
       								          	               (yyval.attr)->code = append((yyval.attr)->code,newList(t));}
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 479 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5],cont[5];
									  			strcpy(begin,newLabel());
									  			strcpy(end,newLabel());
												strcpy(cont,newLabel());
												patchBreak((yyvsp[0].attr)->code,end);
									                        patchContinue((yyvsp[0].attr)->code,cont);	
												(yyval.attr)=(Attr *)malloc(sizeof(Attr));
												(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-6].attr)->code);
												sprintf(t,"label , %s",begin);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-4].attr)->code);
												sprintf(t,"ifgoto, eq,%s,0,%s",(yyvsp[-4].attr)->place,end);
									  			(yyval.attr)->code = append((yyval.attr)->code ,newList(t));
       								          			(yyval.attr)->code = append((yyval.attr)->code , (yyvsp[0].attr)->code);
												sprintf(t,"label , %s",cont);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                      						          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  			sprintf(t,"goto , %s",begin);
       								          		        (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  		        sprintf(t,"label , %s",end);
       								          	               (yyval.attr)->code = append((yyval.attr)->code,newList(t));}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 502 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 503 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 506 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 507 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 510 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 511 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;strcpy((yyval.attr)->place,"");}
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 514 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 515 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 518 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 521 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 522 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);(yyval.attr)=(yyvsp[-2].attr);}
#line 2832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 525 "parser.y" /* yacc.c:1646  */
    {  (yyval.attr) = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,"goto , ");
					(yyval.attr)->code = newList(t);
					(yyval.attr)->code->br = 1;}
#line 2841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 531 "parser.y" /* yacc.c:1646  */
    {  (yyval.attr) = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,"goto , ");
					(yyval.attr)->code = newList(t);
					(yyval.attr)->code->cont = 1;}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 537 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);
					if(strcmp((yyvsp[-1].attr)->place,""))
					 	sprintf(t,"ret,%s",(yyvsp[-1].attr)->place);
					else
						strcpy(t,"ret");
					 (yyval.attr)->code=append((yyvsp[-1].attr)->code,newList(t));}
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 545 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 546 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 549 "parser.y" /* yacc.c:1646  */
    {switch(flag1){
						case 0:sprintf(t,"%s = %s",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 1:sprintf(t,"%s = %s * %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 2:sprintf(t,"%s = %s / %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 3:sprintf(t,"%s = %s %% %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 4:sprintf(t,"%s = %s + %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 5:sprintf(t,"%s = %s - %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 6:sprintf(t,"%s = %s << %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 7:sprintf(t,"%s = %s >> %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 8:sprintf(t,"%s = %s >>> %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 9:sprintf(t,"%s = %s & %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 10:sprintf(t,"%s = %s ^ %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;
						case 11:sprintf(t,"%s = %s | %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							break;}
						(yyval.attr)=(yyvsp[0].attr);
						(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));
						}
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 579 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 584 "parser.y" /* yacc.c:1646  */
    {flag1=0;}
#line 2918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 585 "parser.y" /* yacc.c:1646  */
    {flag1=1;}
#line 2924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 586 "parser.y" /* yacc.c:1646  */
    {flag1=2;}
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 587 "parser.y" /* yacc.c:1646  */
    {flag1=3;}
#line 2936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 588 "parser.y" /* yacc.c:1646  */
    {flag1=4;}
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 589 "parser.y" /* yacc.c:1646  */
    {flag1=5;}
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 590 "parser.y" /* yacc.c:1646  */
    {flag1=6;}
#line 2954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 591 "parser.y" /* yacc.c:1646  */
    {flag1=7;}
#line 2960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 592 "parser.y" /* yacc.c:1646  */
    {flag1=8;}
#line 2966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 593 "parser.y" /* yacc.c:1646  */
    {flag1=9;}
#line 2972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 594 "parser.y" /* yacc.c:1646  */
    {flag1=10;}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 595 "parser.y" /* yacc.c:1646  */
    {flag1=11;}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 598 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 602 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 603 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s || %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 611 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 612 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s && %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 620 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 621 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s | %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 629 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 630 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s ^ %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 638 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 639 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s & %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 647 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 648 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s == %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 654 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s != %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 662 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 3107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 663 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s < %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 669 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s > %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 675 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s <= %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 681 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s >= %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 691 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 692 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s & %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 698 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s >> %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 704 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s >>> %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 713 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 714 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s + %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 720 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s - %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 728 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 729 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s * %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 735 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s / %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 741 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s %% %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 753 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 754 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 755 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							strcpy(temp,tempVar());
							sprintf(t,"%s = + %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 762 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							strcpy(temp,tempVar());
							sprintf(t,"%s = - %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 769 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 772 "parser.y" /* yacc.c:1646  */
    {sprintf(t,"%s = %s + 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 778 "parser.y" /* yacc.c:1646  */
    {sprintf(t,"%s = %s - 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 784 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 785 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							strcpy(temp,tempVar());
							sprintf(t,"%s = ! %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 795 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							sprintf(temp,"%s",tempVar());
							sprintf(t,"%s = %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,"%s = %s - 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							}
#line 3345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 806 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							sprintf(temp,"%s",tempVar());
							sprintf(t,"%s = %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,"%s = %s + 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							}
#line 3359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 817 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 818 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 819 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 820 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 823 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-3].attr);}
#line 3389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 832 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 836 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 838 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 3407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 841 "parser.y" /* yacc.c:1646  */
    {sprintf(t,"=, %s, call, %s",tempVar(),(yyvsp[0].attr)->place);
						(yyval.attr)=(yyvsp[0].attr);
						strcpy((yyval.attr)->place,TEMP);
						(yyval.attr)->code=newList(t);}
#line 3416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 871 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 3422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 875 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 879 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					sprintf((yyval.attr)->place,"%d",(yyvsp[0].ival));
					strcpy((yyval.attr)->type,"int_lit");
					(yyval.attr)->code=NULL;}
#line 3437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 883 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					sprintf((yyval.attr)->place,"%f",(yyvsp[0].fval));
					strcpy((yyval.attr)->type,"float_lit");
					(yyval.attr)->code=NULL;}
#line 3446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 887 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,(yyvsp[0].sval));
					strcpy((yyval.attr)->type,"char_lit");
					(yyval.attr)->code=NULL;}
#line 3455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 891 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,(yyvsp[0].sval));
					strcpy((yyval.attr)->type,"str_lit");
					(yyval.attr)->code=NULL;}
#line 3464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 895 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,"1");
					strcpy((yyval.attr)->type,"bool_lit");
					(yyval.attr)->code=NULL;}
#line 3473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 899 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->type,"bool_lit");
					(yyval.attr)->code=NULL;
					strcpy((yyval.attr)->place,"0");}
#line 3482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 903 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->type,"bool_lit");
					(yyval.attr)->code=NULL;
					strcpy((yyval.attr)->place,"null");}
#line 3491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 909 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 3497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 910 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 3503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 911 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 3509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 914 "parser.y" /* yacc.c:1646  */
    {SymtabEntry *tempo=look_up(table,(yyvsp[0].sval));
					if(tempo!=NULL){
						(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						strcpy((yyval.attr)->place,(yyvsp[0].sval));
						strcpy((yyval.attr)->type,tempo->type);
						(yyval.attr)->code=NULL;
						}
					else
						yyerrok;}
#line 3523 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3527 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 924 "parser.y" /* yacc.c:1906  */

int main(int argc, char** argv){
	p=(SymtabEntry *)malloc(sizeof(SymtabEntry));
	mainTable=(Symtab *)malloc(sizeof(Symtab));
	mainTable->prev=NULL;
	table=mainTable;
	FILE *fptr = fopen(argv[1], "r");
	if(argc==2 && fptr!=NULL){
		yyin = fptr;
	}
	else{
		printf("Error in opening file \n . Aborting....");
		exit(0);
	}
	while(!feof(yyin)){
		yyparse();
	}
	printSymtab(mainTable);
	free(p);
	free(mainTable);
	fclose(fptr);
	return 0;
}
