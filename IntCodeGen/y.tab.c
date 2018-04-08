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
extern int yylineno;
extern FILE *yyin;
FILE *out;
void yyerror(const char *s);
char TEMP[7];
char LABEL[5];
char t[100];
char idr[15];
int flag1;
bool ret;	//to check if function has a return statement or not
SymtabEntry *p;
Arr_dim *h;
Symtab *mainTable,*table;

/*
	type is int:	normal variable of int type
	type is int0:	integer literal
	type is int1:	function that returns an integer value
	type is int2:	array of int type
*/
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


#line 112 "y.tab.c" /* yacc.c:339  */

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
#line 49 "parser.y" /* yacc.c:355  */

	int ival;
	char *sval;
	float fval;
	char *type;
        struct Attr *attr;

#line 332 "y.tab.c" /* yacc.c:355  */
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

#line 363 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1686

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  245
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  409

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
       0,    99,    99,   102,   103,   106,   107,   108,   111,   112,
     115,   118,   119,   122,   125,   128,   129,   132,   133,   136,
     137,   140,   141,   144,   147,   150,   151,   154,   155,   158,
     165,   166,   169,   170,   173,   176,   184,   194,   198,   207,
     208,   213,   225,   243,   245,   246,   249,   252,   253,   256,
     260,   268,   269,   273,   274,   275,   276,   279,   280,   283,
     284,   287,   288,   289,   292,   293,   296,   299,   302,   305,
     306,   309,   310,   314,   315,   318,   321,   324,   325,   326,
     327,   328,   329,   330,   333,   334,   335,   336,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   350,   355,   358,
     361,   362,   363,   364,   365,   366,   369,   372,   383,   400,
     417,   427,   430,   431,   434,   435,   439,   449,   453,   471,
     489,   507,   530,   554,   555,   558,   559,   562,   563,   566,
     567,   570,   573,   574,   577,   583,   589,   598,   599,   600,
     604,   657,   658,   659,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   682,   683,   686,   687,
     704,   705,   722,   723,   740,   741,   758,   759,   776,   777,
     792,   809,   810,   837,   864,   891,   918,   922,   923,   938,
     953,   971,   972,   987,  1004,  1005,  1020,  1035,  1052,  1053,
    1056,  1057,  1058,  1069,  1080,  1083,  1093,  1103,  1104,  1115,
    1118,  1133,  1148,  1149,  1150,  1151,  1154,  1155,  1156,  1159,
    1160,  1163,  1167,  1168,  1169,  1170,  1171,  1172,  1178,  1181,
    1182,  1185,  1186,  1190,  1193,  1206,  1209,  1210,  1213,  1227,
    1242,  1262,  1263,  1266,  1267,  1270,  1274,  1278,  1282,  1286,
    1290,  1294,  1300,  1301,  1302,  1305
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
  "arg_list_e", "argument_list", "assgn1", "array_creat_expr", "dim_exprs",
  "dim_expr", "array_access", "type_name", "name", "literal",
  "int_literal", "identifier", YY_NULLPTR
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

#define YYPACT_NINF -355

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-355)))

#define YYTABLE_NINF -218

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    37,    33,  -355,    90,  -355,    23,  -355,  -355,  -355,
      77,  -355,    28,  -355,  -355,  -355,    33,    88,  -355,  -355,
    -355,    60,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
     101,   166,  -355,  -355,  -355,   107,  -355,  -355,     1,    82,
    -355,  -355,  -355,  -355,  -355,  -355,   109,  -355,  -355,  1068,
    -355,  -355,  1150,  -355,  -355,   128,   133,    35,  -355,    54,
    -355,   486,     6,    33,   -28,   139,  -355,  -355,  -355,   161,
     156,   158,   165,  1396,   163,   164,  1561,  -355,  -355,  1561,
    1561,  1561,  -355,  -355,  -355,  -355,  -355,  -355,   187,   196,
    1150,   102,  -355,   167,  1232,  -355,  -355,   204,  -355,  -355,
    -355,  -355,   205,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,   840,  -355,  -355,    62,    68,    78,    81,
     852,   168,  -355,   114,   206,    -9,  -355,  -355,  -355,   169,
    -355,   202,   486,  -355,   215,  -355,   212,  1525,   210,   226,
    -355,   102,  -355,  -355,   220,  1561,   229,  1561,  -355,  1561,
    1561,  -355,    42,   234,  1505,  1561,   616,  1561,  1561,  1561,
     231,  -355,  -355,  -355,    39,   211,   213,   214,   216,   104,
      38,    12,   113,   120,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,    78,  -355,  -355,  -355,   793,   228,  -355,  -355,   -25,
    -355,   229,   229,   235,  -355,   240,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,  -355,  1561,  -355,  -355,   229,  1561,  1561,  1561,   229,
    -355,   236,  -355,  -355,  1525,  -355,  -355,  -355,  -355,   435,
     242,  1561,  -355,   238,   243,   244,   239,   241,   245,   247,
    -355,  -355,   249,  -355,   255,   248,   254,   250,   251,  -355,
    -355,  -355,  -355,  1561,  1561,  1561,  1561,  1561,  1561,  1561,
    1561,   435,  1561,  1561,  1561,  1561,  1561,  1561,  1561,  1561,
    1561,  1561,  1561,  1561,   286,  -355,   253,   257,  -355,  -355,
     256,   258,   263,   260,  -355,  -355,   266,   269,  -355,  -355,
     265,  -355,  1561,  1561,  -355,  1424,   270,  1561,  1561,  1605,
    1396,  1561,   523,   275,   211,   213,   214,   216,   104,    38,
      38,   276,    12,    12,    12,    12,   113,   113,   113,   120,
     120,  -355,  -355,  -355,   136,  -355,  -355,  -355,  1561,  -355,
    -355,  -355,  -355,  1525,  -355,  -355,   272,   277,   278,   279,
    -355,   298,   299,  -355,  -355,  -355,   153,  -355,   281,   290,
    -355,  -355,  -355,  -355,  1561,   300,   300,   285,  -355,  -355,
    1561,  1505,  1561,  1396,  1561,   304,   295,   153,  -355,   306,
    1605,  -355,  1561,   300,  -355,  -355,  -355,   301,   309,   310,
    -355,   317,  1314,  -355,  -355,  -355,   312,  -355,   255,   318,
    -355,  1424,  1561,  1424,  1314,   904,  1396,  -355,   336,   332,
    -355,   986,  -355,  1424,  1605,  -355,   327,  1424,  -355
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     2,     3,     5,     8,     7,
       0,   231,    12,     1,     6,   232,     0,     0,    11,    13,
      66,     0,    10,    58,    61,    62,    60,    63,    55,    56,
       0,     0,    17,    19,    20,     0,    21,    22,     0,     0,
      53,    57,    59,    54,    64,    65,    66,    14,    18,     0,
      23,    45,     0,    41,    44,    39,     0,     0,    35,    37,
      42,     0,     0,     0,     0,   213,   239,   240,   241,     0,
       0,     0,     0,     0,     0,     0,   128,   245,    98,     0,
       0,     0,   244,   243,   242,   236,   237,   238,     0,     0,
       0,     0,    88,     0,     0,    71,    73,     0,    74,    77,
      89,    90,     0,    78,    79,    91,    80,    92,    81,    93,
      94,    95,   100,     0,   101,   103,   104,   102,     0,   105,
     216,   202,   211,   106,   143,   141,   212,   235,   233,     0,
     213,     0,     0,    67,     0,    34,     0,     0,     0,    25,
      27,     0,    82,    83,     0,   220,     0,   220,   134,     0,
       0,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   138,   137,   156,   158,   160,   162,   164,   166,
     168,   171,   177,   181,   199,   184,   190,   191,   194,   205,
     204,   197,   217,   215,   139,   203,     0,   195,   216,   203,
     196,     0,     0,     0,    39,    76,    31,    72,    75,    99,
     144,   148,   149,   146,   145,   147,   150,   151,   153,   155,
     154,   152,     0,   201,   200,     0,     0,     0,   220,     0,
      68,     0,    36,    40,    48,    52,    38,    51,    24,     0,
      29,   220,   221,     0,   219,   210,     0,     0,     0,     0,
     126,   132,     0,   123,   125,     0,     0,    53,    54,   198,
     192,   193,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,    30,   140,
     209,     0,     0,     0,   234,    43,     0,    47,    49,    28,
       0,    33,     0,   220,    32,     0,     0,     0,   128,     0,
       0,     0,     0,     0,   159,   161,   163,   165,   167,   169,
     170,   176,   173,   172,   175,   174,   179,   178,   180,   182,
     183,   185,   186,   187,     0,   223,    97,    96,   220,   230,
     229,   206,    46,     0,   218,   222,     0,     0,     0,     0,
     107,     0,    77,    85,    86,    87,   113,   110,     0,     0,
     133,   118,   188,   189,     0,     0,     0,     0,    50,   208,
       0,     0,     0,     0,     0,     0,     0,   112,   114,     0,
     130,   157,     0,   224,   226,   225,   207,     0,     0,     0,
     108,     0,     0,   111,   115,   120,     0,   129,   131,     0,
     227,     0,   128,     0,     0,     0,     0,   228,     0,     0,
     119,     0,   121,     0,   130,   109,     0,     0,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -355,  -355,  -355,  -355,   362,  -355,  -355,  -355,  -355,  -355,
    -355,   340,  -355,  -355,  -355,   267,  -355,   146,  -355,  -355,
    -355,   289,   252,   246,  -355,  -355,  -355,  -355,  -355,  -355,
    -355,  -215,   -17,  -154,  -355,  -355,  -139,   -15,  -355,   338,
     -32,  -347,   -88,  -355,  -132,   -68,  -280,  -274,  -355,  -355,
    -135,  -355,  -355,  -355,  -355,  -355,  -355,  -355,    10,  -355,
    -355,  -355,  -355,  -355,    20,  -355,  -286,   -22,  -355,  -354,
    -355,  -355,  -355,   457,   -34,  -355,  -355,    29,  -355,   131,
     134,   144,   145,   132,   -76,  -104,   -12,   -39,  -355,   -73,
       2,    31,   105,    79,   189,   339,   366,   606,  -355,  -355,
     419,  -136,  -355,  -355,  -355,  -355,  -333,  -355,    50,   -49,
    -355,  -355,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    17,    18,    22,    30,
      31,    32,    33,    34,    35,   138,   139,   140,    50,    90,
      36,    57,    58,    59,    37,    38,    60,    53,   225,   286,
     287,   226,    91,    40,    41,    42,    43,    44,    45,    92,
      93,    94,    95,    96,    97,    98,   341,    99,   100,   101,
     102,   103,   104,   343,   105,   347,   366,   367,   368,   106,
     344,   107,   108,   345,   242,   243,   160,   386,   387,   244,
     109,   110,   111,   232,   162,   113,   212,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   120,   121,   122,
     183,   233,   234,   184,   325,   373,   374,   124,    20,   185,
     126,   127,   128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     125,    19,   247,   125,    39,   153,   197,   187,   190,   288,
     145,   236,   349,   218,    39,   112,   388,   248,   112,   241,
     131,   342,   240,   375,   125,   217,     2,    -4,     1,   218,
       2,   189,   189,    51,    10,   395,    15,    52,   142,   112,
     390,   125,   261,   143,   141,   125,   146,   401,   144,   219,
     388,   114,    12,     9,   114,     3,   112,   235,   193,     3,
     112,    10,    11,  -203,  -203,   219,   134,   135,    23,    24,
      25,    46,    26,    27,   142,   114,    28,   266,   267,   143,
     115,    46,   283,   115,   249,   250,   251,   268,   136,    11,
      13,   253,   114,   254,   137,   290,   114,   -16,   262,   263,
     264,   265,   276,   277,   115,   125,   399,    15,   189,   189,
     189,   398,    55,   400,    16,   141,    56,   342,   358,   342,
     112,   115,   311,   405,    21,   115,   280,   408,   116,   342,
     284,   116,   194,   342,  -205,  -205,    56,    10,    47,   246,
    -204,  -204,    29,    49,    23,    24,    25,    61,    26,    27,
     213,   214,   116,  -217,  -217,  -217,   114,   336,   312,   313,
     314,   315,   259,   260,   350,    11,   132,    10,   133,   116,
     355,   364,   365,   116,    23,    24,    25,   147,    26,    27,
     269,   270,    28,   309,   310,   115,  -215,  -215,  -215,   271,
     272,   273,   357,   148,   149,    11,   150,   151,   321,   322,
     323,   154,   155,   -15,   196,   189,   189,   189,   189,   189,
     189,   189,   141,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   191,   241,   340,   352,   240,
     319,   320,   351,   116,   192,   241,   198,   199,   117,   220,
     216,   117,   215,   146,   246,   194,   125,   223,    29,   228,
     125,   125,   189,   189,   316,   317,   318,   229,   231,    77,
     239,   112,   117,   252,   255,   112,   112,   275,   256,   241,
     257,   134,   278,   258,   292,   285,   136,   291,   294,   117,
     295,   298,   293,   117,   296,   297,   299,   300,    56,   301,
     302,   324,   326,   329,   328,   380,   327,   114,   330,   331,
     333,   114,   114,   332,   334,   189,   346,   197,   354,   356,
     -54,   359,   125,   197,   125,   360,   361,   362,   363,   -84,
     369,   125,   370,   340,   376,   351,   115,   112,   402,   112,
     115,   115,   383,   125,   372,   380,   112,   382,   385,   402,
     391,   392,   125,   117,   125,   125,   125,   125,   112,   393,
     394,   396,   125,   397,   125,   125,   403,   112,   125,   112,
     112,   112,   112,   114,   404,   114,   407,   112,    14,   112,
     112,    48,   114,   112,   116,   289,    54,   384,   116,   116,
     195,   378,   406,   371,   114,   304,   222,   230,   118,   305,
     308,   118,   115,   114,   115,   114,   114,   114,   114,   221,
     306,   115,   307,   114,     0,   114,   114,   353,     0,   114,
       0,     0,   118,   115,     0,   119,     0,     0,   119,     0,
       0,     0,   115,     0,   115,   115,   115,   115,     0,   118,
       0,     0,   115,   118,   115,   115,    10,     0,   115,   119,
     116,     0,   116,    23,    24,    25,     0,    26,    27,   116,
       0,    28,     0,     0,     0,     0,   119,     0,     0,     0,
     119,   116,     0,     0,    11,     0,     0,     0,   123,     0,
     116,   123,   116,   116,   116,   116,     0,     0,     0,     0,
     116,     0,   116,   116,   117,     0,   116,    10,   117,   117,
       0,     0,   123,   118,    23,    24,    25,     0,    26,    27,
       0,     0,    28,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,   123,     0,    11,     0,    29,     0,     0,
     119,     0,     0,     0,     0,   -26,     0,     0,    63,   129,
     130,     0,     0,   161,    66,     0,   186,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,   117,    77,     0,     0,     0,     0,     0,   117,
       0,   156,     0,     0,     0,     0,     0,     0,    29,     0,
       0,   117,     0,   123,     0,     0,     0,     0,     0,     0,
     117,     0,   117,   117,   117,   117,     0,   157,     0,     0,
     117,     0,   117,   117,   227,     0,   117,     0,     0,    82,
      83,    84,    85,    86,    87,     0,   237,   238,     0,     0,
       0,     0,   245,   186,     0,     0,     0,    10,     0,     0,
       0,    63,   129,   130,    23,    24,    25,    66,    26,    27,
      67,    68,    28,     0,   118,     0,     0,     0,   118,   118,
       0,     0,     0,     0,     0,    11,    77,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
       0,   119,     0,     0,     0,   119,   119,     0,     0,   279,
       0,     0,     0,   281,   282,     0,     0,     0,     0,     0,
     157,   227,     0,   158,   159,     0,   188,   188,    80,    81,
       0,     0,    82,    83,    84,    85,    86,    87,    29,     0,
     118,     0,   118,     0,     0,     0,     0,     0,     0,   118,
     303,     0,     0,     0,   123,     0,     0,     0,   123,   123,
       0,   118,     0,     0,     0,     0,     0,   119,     0,   119,
     118,     0,   118,   118,   118,   118,   119,     0,     0,     0,
     118,     0,   118,   118,     0,     0,   118,     0,   119,   335,
       0,     0,     0,     0,   348,   161,     0,   119,     0,   119,
     119,   119,   119,   188,   188,   188,     0,   119,     0,   119,
     119,     0,     0,   119,     0,     0,     0,     0,     0,     0,
     123,     0,   123,     0,     0,     0,     0,     0,     0,   123,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,   123,   123,   123,   123,     0,   377,     0,   379,
     123,   381,   123,   123,     0,     0,   123,   217,     0,   389,
       0,   218,     0,   274,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   188,   188,   188,   188,   188,   188,   219,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,     0,    62,     0,   188,   188,    63,
     129,   130,    23,    24,    25,    66,    26,    27,    67,    68,
      28,    69,  -117,  -117,     0,    70,    71,    72,    73,    74,
      75,    76,     0,    11,    77,     0,    78,     0,     0,     0,
      52,  -117,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    29,    62,    88,    89,
       0,    63,   129,   130,    23,    24,    25,    66,    26,    27,
      67,    68,    28,    69,  -116,  -116,     0,    70,    71,    72,
      73,    74,    75,    76,     0,    11,    77,     0,    78,     0,
       0,     0,    52,  -116,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
       0,     0,    82,    83,    84,    85,    86,    87,    29,    62,
      88,    89,     0,    63,    64,    65,    23,    24,    25,    66,
      26,    27,    67,    68,    28,    69,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,     0,    11,    77,     0,
      78,     0,     0,     0,    52,   -70,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,    82,    83,    84,    85,    86,    87,
      29,    62,    88,    89,     0,    63,   129,   130,    23,    24,
      25,    66,    26,    27,    67,    68,    28,    69,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,     0,    11,
      77,     0,    78,     0,     0,     0,    52,   -70,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,    82,    83,    84,    85,
      86,    87,    29,    62,    88,    89,     0,    63,   129,   130,
      23,    24,    25,    66,    26,    27,    67,    68,    28,    69,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
       0,    11,    77,     0,    78,     0,     0,     0,    52,   -69,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,    82,    83,
      84,    85,    86,    87,    29,    62,    88,    89,     0,    63,
     129,   130,    23,    24,    25,    66,    26,    27,    67,    68,
      28,    69,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,     0,    11,    77,     0,    78,     0,     0,     0,
      52,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    29,   152,    88,    89,
       0,    63,   129,   130,     0,     0,     0,    66,     0,     0,
      67,    68,     0,    69,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,     0,   152,    77,     0,    78,    63,
     129,   130,    52,     0,    79,    66,     0,     0,    67,    68,
       0,    69,     0,     0,     0,   337,    71,    72,    73,   338,
     339,    76,     0,     0,    77,     0,    78,     0,     0,     0,
      52,     0,    79,     0,     0,     0,     0,     0,    80,    81,
       0,     0,    82,    83,    84,    85,    86,    87,     0,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
      82,    83,    84,    85,    86,    87,    10,     0,    88,    89,
      63,   129,   130,    23,    24,    25,    66,    26,    27,    67,
      68,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      63,   129,   130,     0,    11,    77,    66,  -124,     0,    67,
      68,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,   224,     0,   156,     0,     0,    63,   129,   130,     0,
       0,     0,    66,     0,     0,    67,    68,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    29,     0,   157,
       0,    77,   158,   159,     0,     0,     0,    80,    81,   156,
       0,    82,    83,    84,    85,    86,    87,     0,     0,     0,
      63,   129,   130,     0,     0,     0,    66,     0,     0,    67,
      68,     0,     0,     0,     0,   157,     0,     0,   158,   159,
       0,     0,     0,    80,    81,    77,     0,    82,    83,    84,
      85,    86,    87,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      49,    16,   156,    52,    21,    73,    94,    80,    81,   224,
      38,   147,   298,    38,    31,    49,   370,   156,    52,   154,
      52,   295,   154,   356,    73,    34,     3,     0,     1,    38,
       3,    80,    81,    32,     1,   382,    30,    36,    32,    73,
     373,    90,     4,    37,    61,    94,    74,   394,    63,    74,
     404,    49,     2,    16,    52,    32,    90,   146,    90,    32,
      94,     1,    29,    72,    73,    74,    31,    32,     8,     9,
      10,    21,    12,    13,    32,    73,    16,    65,    66,    37,
      49,    31,   218,    52,   157,   158,   159,    75,    34,    29,
       0,    52,    90,    54,    40,   231,    94,    37,    60,    61,
      62,    63,   191,   192,    73,   154,   392,    30,   157,   158,
     159,   391,    30,   393,    86,   132,    34,   391,   333,   393,
     154,    90,   261,   403,    36,    94,   215,   407,    49,   403,
     219,    52,    30,   407,    72,    73,    34,     1,    37,   156,
      72,    73,    82,    36,     8,     9,    10,    38,    12,    13,
      72,    73,    73,    72,    73,    74,   154,   293,   262,   263,
     264,   265,    58,    59,   299,    29,    38,     1,    35,    90,
     324,    18,    19,    94,     8,     9,    10,    38,    12,    13,
      67,    68,    16,   259,   260,   154,    72,    73,    74,    69,
      70,    71,   328,    32,    38,    29,    38,    32,   271,   272,
     273,    38,    38,    37,    37,   254,   255,   256,   257,   258,
     259,   260,   229,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,    38,   361,   295,   301,   361,
     269,   270,   300,   154,    38,   370,    32,    32,    49,    37,
      34,    52,    74,    74,   261,    30,   295,    35,    82,    39,
     299,   300,   301,   302,   266,   267,   268,    31,    38,    30,
      26,   295,    73,    32,    53,   299,   300,    39,    55,   404,
      56,    31,    37,    57,    31,    39,    34,    39,    39,    90,
      39,    32,    38,    94,    39,    38,    31,    39,    34,    39,
      39,     5,    39,    35,    38,   363,    39,   295,    35,    39,
      31,   299,   300,    37,    39,   354,    36,   395,    33,   324,
      34,    39,   361,   401,   363,    38,    38,    38,    20,    20,
      39,   370,    32,   391,    39,   393,   295,   361,   396,   363,
     299,   300,    37,   382,    34,   403,   370,    33,    32,   407,
      39,    32,   391,   154,   393,   394,   395,   396,   382,    39,
      33,    39,   401,    35,   403,   404,    20,   391,   407,   393,
     394,   395,   396,   361,    32,   363,    39,   401,     6,   403,
     404,    31,   370,   407,   295,   229,    38,   367,   299,   300,
      91,   361,   404,   354,   382,   254,   134,   141,    49,   255,
     258,    52,   361,   391,   363,   393,   394,   395,   396,   132,
     256,   370,   257,   401,    -1,   403,   404,   302,    -1,   407,
      -1,    -1,    73,   382,    -1,    49,    -1,    -1,    52,    -1,
      -1,    -1,   391,    -1,   393,   394,   395,   396,    -1,    90,
      -1,    -1,   401,    94,   403,   404,     1,    -1,   407,    73,
     361,    -1,   363,     8,     9,    10,    -1,    12,    13,   370,
      -1,    16,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      94,   382,    -1,    -1,    29,    -1,    -1,    -1,    49,    -1,
     391,    52,   393,   394,   395,   396,    -1,    -1,    -1,    -1,
     401,    -1,   403,   404,   295,    -1,   407,     1,   299,   300,
      -1,    -1,    73,   154,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    29,    -1,    82,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    39,    -1,    -1,     5,     6,
       7,    -1,    -1,    76,    11,    -1,    79,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     361,    -1,   363,    30,    -1,    -1,    -1,    -1,    -1,   370,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,   382,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     391,    -1,   393,   394,   395,   396,    -1,    64,    -1,    -1,
     401,    -1,   403,   404,   137,    -1,   407,    -1,    -1,    76,
      77,    78,    79,    80,    81,    -1,   149,   150,    -1,    -1,
      -1,    -1,   155,   156,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,   295,    -1,    -1,    -1,   299,   300,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,   299,   300,    -1,    -1,   212,
      -1,    -1,    -1,   216,   217,    -1,    -1,    -1,    -1,    -1,
      64,   224,    -1,    67,    68,    -1,    80,    81,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    -1,
     361,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,   370,
     253,    -1,    -1,    -1,   295,    -1,    -1,    -1,   299,   300,
      -1,   382,    -1,    -1,    -1,    -1,    -1,   361,    -1,   363,
     391,    -1,   393,   394,   395,   396,   370,    -1,    -1,    -1,
     401,    -1,   403,   404,    -1,    -1,   407,    -1,   382,   292,
      -1,    -1,    -1,    -1,   297,   298,    -1,   391,    -1,   393,
     394,   395,   396,   157,   158,   159,    -1,   401,    -1,   403,
     404,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,
     361,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,   370,
     333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     391,    -1,   393,   394,   395,   396,    -1,   360,    -1,   362,
     401,   364,   403,   404,    -1,    -1,   407,    34,    -1,   372,
      -1,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,   258,   259,   260,    74,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,     1,    -1,   301,   302,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    32,    -1,    -1,    -1,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,     1,    84,    85,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,     1,
      84,    85,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    -1,
      32,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,     1,    84,    85,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,     1,    84,    85,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    -1,    32,    -1,    -1,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,     1,    84,    85,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    32,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,     1,    84,    85,
      -1,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,
      14,    15,    -1,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,     1,    30,    -1,    32,     5,
       6,     7,    36,    -1,    38,    11,    -1,    -1,    14,    15,
      -1,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,     1,    -1,    84,    85,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,    -1,    29,    30,    11,    32,    -1,    14,
      15,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    38,    -1,    -1,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    15,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    -1,    64,
      -1,    30,    67,    68,    -1,    -1,    -1,    72,    73,    38,
      -1,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      -1,    -1,    -1,    72,    73,    30,    -1,    76,    77,    78,
      79,    80,    81,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    32,    88,    89,    90,    91,    92,    16,
       1,    29,   195,     0,    91,    30,    86,    93,    94,   124,
     195,    36,    95,     8,     9,    10,    12,    13,    16,    82,
      96,    97,    98,    99,   100,   101,   107,   111,   112,   119,
     120,   121,   122,   123,   124,   125,   195,    37,    98,    36,
     105,    32,    36,   114,   126,    30,    34,   108,   109,   110,
     113,    38,     1,     5,     6,     7,    11,    14,    15,    17,
      21,    22,    23,    24,    25,    26,    27,    30,    32,    38,
      72,    73,    76,    77,    78,    79,    80,    81,    84,    85,
     106,   119,   126,   127,   128,   129,   130,   131,   132,   134,
     135,   136,   137,   138,   139,   141,   146,   148,   149,   157,
     158,   159,   161,   162,   177,   178,   180,   181,   182,   183,
     184,   185,   186,   187,   194,   196,   197,   198,   199,     6,
       7,   127,    38,    35,    31,    32,    34,    40,   102,   103,
     104,   119,    32,    37,   124,    38,    74,    38,    32,    38,
      38,    32,     1,   132,    38,    38,    38,    64,    67,    68,
     153,   160,   161,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   187,   190,   196,   160,   176,   184,   196,
     176,    38,    38,   127,    30,   108,    37,   129,    32,    32,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   163,    72,    73,    74,    34,    34,    38,    74,
      37,   102,   109,    35,    36,   115,   118,   160,    39,    31,
     110,    38,   160,   188,   189,   199,   188,   160,   160,    26,
     131,   137,   151,   152,   156,   160,   119,   120,   123,   176,
     176,   176,    32,    52,    54,    53,    55,    56,    57,    58,
      59,     4,    60,    61,    62,    63,    65,    66,    75,    67,
      68,    69,    70,    71,    40,    39,   199,   199,    37,   160,
     199,   160,   160,   188,   199,    39,   116,   117,   118,   104,
     188,    39,    31,    38,    39,    39,    39,    38,    32,    31,
      39,    39,    39,   160,   166,   167,   168,   169,   170,   171,
     171,   123,   172,   172,   172,   172,   173,   173,   173,   174,
     174,   176,   176,   176,     5,   191,    39,    39,    38,    35,
      35,    39,    37,    31,    39,   160,   188,    21,    25,    26,
     132,   133,   134,   140,   147,   150,    36,   142,   160,   153,
     137,   132,   176,   179,    33,   120,   124,   188,   118,    39,
      38,    38,    38,    20,    18,    19,   143,   144,   145,    39,
      32,   164,    34,   192,   193,   193,    39,   160,   151,   160,
     132,   160,    33,    37,   145,    32,   154,   155,   156,   160,
     193,    39,    32,    39,    33,   128,    39,    35,   133,   153,
     133,   128,   132,    20,    32,   133,   154,    39,   133
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
     154,   155,   156,   156,   157,   158,   159,   160,   160,   160,
     161,   162,   162,   162,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     170,   171,   171,   171,   171,   171,   171,   172,   172,   172,
     172,   173,   173,   173,   174,   174,   174,   174,   175,   175,
     176,   176,   176,   176,   176,   177,   178,   179,   179,   179,
     180,   181,   182,   182,   182,   182,   183,   183,   183,   184,
     184,   185,   186,   186,   186,   186,   186,   186,   187,   188,
     188,   189,   189,   190,   191,   191,   192,   192,   193,   194,
     194,   195,   195,   196,   196,   197,   197,   197,   197,   197,
     197,   197,   198,   198,   198,   199
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
       0,     1,     1,     3,     2,     2,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     4,     4,
       1,     1,     2,     2,     1,     2,     2,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     4,     6,     6,     3,
       3,     1,     1,     1,     3,     1,     1,     1,     5,     1,
       0,     1,     3,     3,     3,     3,     1,     2,     3,     4,
       4,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 108 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "parser.y" /* yacc.c:1646  */
    {strcpy(table->name,(yyvsp[-2].sval));}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "parser.y" /* yacc.c:1646  */
    {printList((yyvsp[0].attr)->code);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 141 "parser.y" /* yacc.c:1646  */
    {printList((yyvsp[0].attr)->code);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						 /*strcpy($$->place,$2);
						 strcpy($$->type,$1);
						 p=Insert(table,$2,$1);*/
						 (yyval.attr)->code=NULL;}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
						 strcpy((yyval.attr)->type,(yyvsp[-1].type));
						 p=Insert(table,(yyvsp[0].attr)->place,(yyval.attr)->type,(yyvsp[0].attr)->assign);
						 if(p==NULL){
							fprintf(stderr,"Error: Variable %s redeclared on line %d\n",(yyvsp[0].attr)->place,yylineno);
							exit(1);
							}}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-2].attr);
						 strcpy((yyval.attr)->type,(yyvsp[-3].type));
						 (yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
						 p=Insert(table,(yyvsp[0].attr)->place,(yyval.attr)->type,(yyvsp[0].attr)->assign);
						 if(p==NULL){
							fprintf(stderr,"Error: Variable %s redeclared on line %d\n",(yyvsp[0].attr)->place,yylineno);
							exit(1);
							}}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								(yyval.attr)->code=NULL;	
								(yyval.attr)->assign=false;
								strcpy((yyval.attr)->place,(yyvsp[0].sval));}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
								int l =strlen((yyvsp[-3].type));
								if((yyvsp[-3].type)[l-1]!='2'){
									sprintf(t,", =, %s, %s",(yyvsp[-2].sval),(yyvsp[0].attr)->place);
								(yyval.attr)->code=append((yyval.attr)->code,newList(t));	
								(yyval.attr)->assign=true;	}
								strcpy((yyval.attr)->place,(yyvsp[-2].sval));}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);strcpy(idr,(yyvsp[0].sval));}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-2].sval);
							sprintf((yyvsp[-3].type), "%s2",(yyvsp[-3].type));
							}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
							(yyval.attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);
							if(!ret){
								if(strcmp((yyvsp[-1].attr)->type,"void1")==0){
									sprintf(t,", ret");
									(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
								else{
									fprintf(stderr,"Error: Missing return statement in function %s\n",(yyvsp[-1].attr)->place);
									exit(1);}} 
							table=table->prev;}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								ret=false;
								strcpy((yyval.attr)->place,(yyvsp[0].sval));
								strcpy((yyval.attr)->type,(yyvsp[-1].type));
				 				strcat((yyval.attr)->type,"1");
								sprintf(t,", label, %s",(yyvsp[0].sval));
								(yyval.attr)->code=newList(t);
				  				p=Insert(table,(yyvsp[0].sval),(yyval.attr)->type,true);
							if(p==NULL){
								fprintf(stderr,"Error: Variable %s redeclared on line %d\n",(yyvsp[0].sval),yylineno);
								exit(1);
							}else{
								p->func=(Symtab *)malloc(sizeof(Symtab));
								p->func->prev=table;
								table=p->func;
								strcpy(table->name,(yyvsp[0].sval));}}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-3].sval);}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 249 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[-1].attr);}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);(yyval.attr)->idx[0] = '0';
			sprintf(t, "=, %s[%d], %s", idr,(yyval.attr)->idx[0]-'0', (yyvsp[0].attr)->place);
				(yyval.attr)->code  = append((yyvsp[0].attr)->code, newList(t));
				}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						(yyval.attr)->code = append((yyvsp[-2].attr)->code, (yyvsp[0].attr)->code);
						(yyval.attr)->idx[0] = (yyvsp[-2].attr)->idx[0]+1;
						sprintf(t,"=, %s[%d], %s", idr,(yyval.attr)->idx[0]-'0', (yyvsp[0].attr)->place);
						(yyval.attr)->code  = append((yyval.attr)->code, newList(t));
						}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 273 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 299 "parser.y" /* yacc.c:1646  */
    {sprintf((yyvsp[-2].type), "%s2",(yyvsp[-2].type));}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);
							 (yyval.attr)=(yyvsp[-1].attr);}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 321 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 328 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 329 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 330 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 334 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 339 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 340 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 343 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);
							sprintf(t,", scan, %s",(yyvsp[-1].attr)->place);
							(yyval.attr)->code=newList(t);}
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 350 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);
							sprintf(t,", print, %s",(yyvsp[-1].attr)->place);
							(yyval.attr)->code=newList(t);}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 355 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 358 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 361 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 364 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 366 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
					sprintf(t,", call, %s",(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 372 "parser.y" /* yacc.c:1646  */
    { char end[5];
									  strcpy(end,newLabel());
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 383 "parser.y" /* yacc.c:1646  */
    { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());		
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-4].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-4].attr)->place,else_beg);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  sprintf(t,", goto, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",else_beg);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  
									   	  }
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 401 "parser.y" /* yacc.c:1646  */
    { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-4].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-4].attr)->place,else_beg);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  sprintf(t,", goto, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",else_beg);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t)); }
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 417 "parser.y" /* yacc.c:1646  */
    {  char end[5];
							 	strcpy(end,newLabel());
								(yyval.attr)=(yyvsp[0].attr);
								patchBreak((yyvsp[0].attr)->code,end);
								sprintf(t,", label, %s",end);
								(yyval.attr)->code = append((yyval.attr)->code,newList(t));
								patchSwitch((yyval.attr)->code,(yyvsp[-2].attr)->place);
								}
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 427 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 430 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 431 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 434 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 435 "parser.y" /* yacc.c:1646  */
    {   (yyval.attr)=(yyvsp[-1].attr);
									(yyval.attr)->code= append((yyval.attr)->code,(yyvsp[0].attr)->code);}
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 439 "parser.y" /* yacc.c:1646  */
    { (yyval.attr)=(Attr*)malloc(sizeof(Attr));
								char nexLabel[5];
								strcpy(nexLabel,newLabel());
								sprintf(t,", ifgoto, neq, %s ,        , %s",(yyvsp[-2].attr)->place,nexLabel);
								(yyval.attr)->code=newList(t);
								(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
								sprintf(t,", label, %s",nexLabel);
								(yyval.attr)->code=append((yyval.attr)->code,newList(t));
								(yyval.attr)->code->swt = 1;}
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 449 "parser.y" /* yacc.c:1646  */
    { (yyval.attr)=(Attr*)malloc(sizeof(Attr));
								(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);	}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 453 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());	
                                                                          sprintf(t,", label, %s",begin);
                                                                          (yyval.attr)=(Attr *)malloc(sizeof(Attr));
									  patchBreak((yyvsp[0].attr)->code,end);
									  patchContinue((yyvsp[0].attr)->code,begin);	
       								          (yyval.attr)->code = newList(t);
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", goto, %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 471 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
									  patchBreak((yyvsp[0].attr)->code,end);
									  patchContinue((yyvsp[0].attr)->code,begin);	
                                                                          sprintf(t,", label, %s",begin);
                                                                          (yyval.attr)=(Attr *)malloc(sizeof(Attr));
       								          (yyval.attr)->code = newList(t);
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", goto, %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 489 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
									  patchBreak((yyvsp[-5].attr)->code,end);
									  patchContinue((yyvsp[-5].attr)->code,begin);		
                                                                          sprintf(t,", label, %s",begin);
                                                                          (yyval.attr)=(Attr *)malloc(sizeof(Attr));
       								          (yyval.attr)->code = newList(t);
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-5].attr)->code);
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  sprintf(t,", goto, %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 507 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5],cont[5];
									  			strcpy(begin,newLabel());
									  			strcpy(end,newLabel());
												strcpy(cont,newLabel());
												patchBreak((yyvsp[0].attr)->code,end);
									                        patchContinue((yyvsp[0].attr)->code,cont);	
												(yyval.attr)=(Attr *)malloc(sizeof(Attr));
												(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-6].attr)->code);
												sprintf(t,", label, %s",begin);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-4].attr)->code);
											sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-4].attr)->place,end);
									  			(yyval.attr)->code = append((yyval.attr)->code ,newList(t));
       								          			(yyval.attr)->code = append((yyval.attr)->code , (yyvsp[0].attr)->code);
												sprintf(t,", label, %s",cont);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                      						          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  			sprintf(t,", goto, %s",begin);
       								          		        (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  		        sprintf(t,", label, %s",end);
       								          	                (yyval.attr)->code = append((yyval.attr)->code,newList(t));}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 531 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5],cont[5];
									  			strcpy(begin,newLabel());
									  			strcpy(end,newLabel());
												strcpy(cont,newLabel());
												patchBreak((yyvsp[0].attr)->code,end);
									                        patchContinue((yyvsp[0].attr)->code,cont);	
												(yyval.attr)=(Attr *)malloc(sizeof(Attr));
												(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-6].attr)->code);
												sprintf(t,", label, %s",begin);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-4].attr)->code);
											sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-4].attr)->place,end);
									  			(yyval.attr)->code = append((yyval.attr)->code ,newList(t));
       								          			(yyval.attr)->code = append((yyval.attr)->code , (yyvsp[0].attr)->code);
												sprintf(t,", label, %s",cont);	
                                                                          			(yyval.attr)->code = append((yyval.attr)->code,newList(t));
                      						          			(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  			sprintf(t,", goto, %s",begin);
       								          		        (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  		        sprintf(t,", label, %s",end);
       								          	               (yyval.attr)->code = append((yyval.attr)->code,newList(t));}
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 554 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 555 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 558 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 559 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 562 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 563 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;strcpy((yyval.attr)->place,"");}
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 566 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 567 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 570 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 573 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 574 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);(yyval.attr)=(yyvsp[-2].attr);}
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 577 "parser.y" /* yacc.c:1646  */
    {  (yyval.attr) = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,", goto, ");
					(yyval.attr)->code = newList(t);
					(yyval.attr)->code->br = 1;}
#line 2947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 583 "parser.y" /* yacc.c:1646  */
    {  (yyval.attr) = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,", goto, ");
					(yyval.attr)->code = newList(t);
					(yyval.attr)->code->cont = 1;}
#line 2956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 589 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);
					ret=true;
					if(strcmp((yyvsp[-1].attr)->place,""))
					 	sprintf(t,", ret, %s",(yyvsp[-1].attr)->place);
					else
						strcpy(t,", ret");
					 (yyval.attr)->code=append((yyvsp[-1].attr)->code,newList(t));}
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 598 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 599 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 600 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 604 "parser.y" /* yacc.c:1646  */
    {printf("## %s ##\n",(yyvsp[-2].attr)->place);if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								//exit(1);
							}
						char tr[15];
						int q = 0;
						while((yyvsp[-2].attr)->place[q]!='['){
							tr[q] = (yyvsp[-2].attr)->place[q];
							q++;
							}
						p=look_up(table,tr);
						if(p==NULL){
							fprintf(stderr,"Error on %d: %s undeclared\n",yylineno,(yyvsp[-2].attr)->place);
							//exit(1);
						}	
						else if(flag1 && !(yyvsp[-2].attr)->assign){	
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								//exit(1);
						}
						else{int l = strlen(p->type);
							switch(flag1){
								case 0:sprintf(t,", =, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       (yyvsp[-2].attr)->assign=true;
								       p->assign=true;
								       break;
								case 1:sprintf(t,", *, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 2:sprintf(t,", /, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 3:sprintf(t,", %%, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 4:sprintf(t,", +, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 5:sprintf(t,", -, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 6:sprintf(t,", <<, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 7:sprintf(t,", >>, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 8:sprintf(t,", >>>, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 9:sprintf(t,", &, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
								       break;
								case 10:sprintf(t,", ^, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
									break;
								case 11:sprintf(t,", |, %s, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
									break;}
									
							(yyval.attr)=(yyvsp[-2].attr);
							(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));
						}	}
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 657 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 659 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));sprintf(t, "%s[%s]",(yyvsp[0].attr)->place, (yyvsp[0].attr)->idx);
					strcpy((yyval.attr)->place, t);
					printf("$$ %s $$\n", t);
					(yyval.attr)->assign = 1;
					(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);}
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 668 "parser.y" /* yacc.c:1646  */
    {flag1=0;}
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 669 "parser.y" /* yacc.c:1646  */
    {flag1=1;}
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 670 "parser.y" /* yacc.c:1646  */
    {flag1=2;}
#line 3076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 671 "parser.y" /* yacc.c:1646  */
    {flag1=3;}
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 672 "parser.y" /* yacc.c:1646  */
    {flag1=4;}
#line 3088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 673 "parser.y" /* yacc.c:1646  */
    {flag1=5;}
#line 3094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 674 "parser.y" /* yacc.c:1646  */
    {flag1=6;}
#line 3100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 675 "parser.y" /* yacc.c:1646  */
    {flag1=7;}
#line 3106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 676 "parser.y" /* yacc.c:1646  */
    {flag1=8;}
#line 3112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 677 "parser.y" /* yacc.c:1646  */
    {flag1=9;}
#line 3118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 678 "parser.y" /* yacc.c:1646  */
    {flag1=10;}
#line 3124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 679 "parser.y" /* yacc.c:1646  */
    {flag1=11;}
#line 3130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 682 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 686 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 687 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", ||, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 704 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 705 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", &&, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 722 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 723 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", |, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 740 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 741 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", ^, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 758 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 759 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", &, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 776 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 777 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s == %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 792 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s != %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 809 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 3316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 810 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, lt , %s , %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s, 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 837 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, gt , %s , %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 864 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,",ifgoto, leq , %s , %s ,%s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", goto , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 891 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,",ifgoto, geq, %s, %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 922 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 923 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", <<, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 938 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", >>, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 953 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", >>>, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 971 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 972 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", +, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 987 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", -, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1004 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1005 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1020 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", /, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1035 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)->assign=true;
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", %%, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1056 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1057 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1058 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							strcpy(temp,tempVar());
							sprintf(t,", =, %s, %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1069 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							strcpy(temp,tempVar());
							sprintf(t,", -, %s, 0, %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1080 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1083 "parser.y" /* yacc.c:1646  */
    {sprintf(t,", +, %s, %s, 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1093 "parser.y" /* yacc.c:1646  */
    {sprintf(t,", -, %s, %s, 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1103 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1104 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							strcpy(temp,tempVar());
							sprintf(t,", !, %s, %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1115 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1118 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[-1].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-1].attr)->place);
								exit(1);
							}
							sprintf(temp,"%s",tempVar());
							sprintf(t,", =, %s, %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,", -, %s, %s, 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							}
#line 3740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1133 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							sprintf(temp,"%s",tempVar());
							if(!(yyvsp[-1].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-1].attr)->place);
								exit(1);
							}
							sprintf(t,", =, %s, %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,", +, %s, %s, 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							}
#line 3758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1148 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1149 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1150 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1151 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1154 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-3].attr);}
#line 3788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1155 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1156 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1159 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1160 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1163 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1167 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);(yyval.attr)->assign=true;}
#line 3824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1168 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1169 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 3836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1170 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 3842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1171 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1172 "parser.y" /* yacc.c:1646  */
    {sprintf(t,", =, %s, call, %s",tempVar(),(yyvsp[0].attr)->place);
						(yyval.attr)=(yyvsp[0].attr);
						strcpy((yyval.attr)->place,TEMP);
						(yyval.attr)->code=newList(t);}
#line 3857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1190 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 3863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1193 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);int r;
						p = look_up(table,(yyvsp[-3].attr)->place);
						if(p!=NULL){
							Arr_dim *b = p->arr_dim;
							r = atoi(b->d);
							b = b->next;
							while(b!=NULL){
								r = r*atoi(b->d);
								b = b->next;
								}
							}
						sprintf(t, ", array, %s[%d]", (yyvsp[-3].attr)->place,r);
						(yyval.attr)->code = append((yyval.attr)->code, newList(t));}
#line 3881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1206 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 3887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1209 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 3893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1213 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[-1].attr);p = look_up(table,(yyvsp[(-2) - (3)].attr)->place);
				if(p!=NULL){ Arr_dim *a = (Arr_dim*)malloc(sizeof(Arr_dim));
					strcpy(a->d, (yyvsp[-1].attr)->place);
					Arr_dim *b = p->arr_dim;
					if(b){
					while(b->next!=NULL){
						b = b->next;
						}
					b->next = a;
					}
					else p->arr_dim = a;}
				}
#line 3910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1227 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, (yyvsp[-3].attr)->place);
					(yyval.attr)->code = append((yyvsp[-3].attr)->code, (yyvsp[-1].attr)->code);
					p = look_up(table,(yyvsp[-3].attr)->place);
					printf("$$ %s $$ %s $$\n", (yyvsp[-3].attr)->place, p->lexeme);
					if(p){	
						h = p->arr_dim;
						if(h && h->next){
							strcpy((yyval.attr)->idx,tempVar());
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->idx, h->next->d,(yyvsp[-1].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							h = h->next;
							}
						}	
					}
#line 3930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1242 "parser.y" /* yacc.c:1646  */
    {
						(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						strcpy((yyval.attr)->place, (yyvsp[(-3) - (4)].attr)->place);
						if(h && h->next){
							strcpy((yyval.attr)->idx,tempVar());
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->idx, h->next->d,(yyvsp[-1].attr)->place);
							(yyval.attr)->code=append((yyvsp[-3].attr)->code,newList(t));
							sprintf(t,", +, %s, %s, %s",(yyval.attr)->idx, (yyval.attr)->idx,(yyvsp[-3].attr)->idx);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));		
							}
						else if(h){
							strcpy((yyval.attr)->idx, (yyvsp[-3].attr)->idx);
							sprintf(t,", +, %s, %s, %s",(yyvsp[-3].attr)->idx, (yyvsp[-3].attr)->idx,h->d);
							(yyval.attr)->code=append((yyvsp[-3].attr)->code,newList(t));
							
							}
						h = h->next;
						}
#line 3953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1262 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 3959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1263 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 3965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1266 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1270 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					sprintf((yyval.attr)->place,"%d",(yyvsp[0].ival));
					strcpy((yyval.attr)->type,"int0");
					(yyval.attr)->code=NULL;}
#line 3980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1274 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					sprintf((yyval.attr)->place,"%f",(yyvsp[0].fval));
					strcpy((yyval.attr)->type,"float0");
					(yyval.attr)->code=NULL;}
#line 3989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1278 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,(yyvsp[0].sval));
					strcpy((yyval.attr)->type,"char0");
					(yyval.attr)->code=NULL;}
#line 3998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1282 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,(yyvsp[0].sval));
					strcpy((yyval.attr)->type,"str0");
					(yyval.attr)->code=NULL;}
#line 4007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1286 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,"1");
					strcpy((yyval.attr)->type,"bool0");
					(yyval.attr)->code=NULL;}
#line 4016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1290 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->type,"bool0");
					(yyval.attr)->code=NULL;
					strcpy((yyval.attr)->place,"0");}
#line 4025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1294 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->type,"bool0");
					(yyval.attr)->code=NULL;
					strcpy((yyval.attr)->place,"null");}
#line 4034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1300 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 4040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1301 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 4046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1302 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 4052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1305 "parser.y" /* yacc.c:1646  */
    {SymtabEntry *tempo=look_up(table,(yyvsp[0].sval));
					if(tempo!=NULL){
						(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						strcpy((yyval.attr)->place,(yyvsp[0].sval));
						strcpy((yyval.attr)->type,tempo->type);
						(yyval.attr)->assign=tempo->assign;
						(yyval.attr)->code=NULL;
						}
					else
						yyerrok;}
#line 4067 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4071 "y.tab.c" /* yacc.c:1646  */
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
#line 1316 "parser.y" /* yacc.c:1906  */

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
