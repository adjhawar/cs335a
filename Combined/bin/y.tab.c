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
char idr[15],methodType[10];
char temp[15];
int flag1,flag0=0;	//flag0 checks if array access was used or not in lhs
bool ret;	//to check if function has a return statement or not
SymtabEntry *p,*currFunc;
Arr_dim *h;
Symtab *mainTable,*table;
int offset,totalOff,length=1;
list3AC *finalList;

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

void typeError(int line){
	printf("Type error on line %d\n",line);
	exit(1);
}

#line 119 "y.tab.c" /* yacc.c:339  */

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
#line 56 "parser.y" /* yacc.c:355  */

	int ival;
	char *sval;
	float fval;
	char *type;
        struct Attr *attr;

#line 339 "y.tab.c" /* yacc.c:355  */
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

#line 370 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1713

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  246
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

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
       0,   107,   107,   110,   111,   114,   115,   116,   119,   120,
     123,   126,   127,   130,   133,   136,   137,   140,   141,   144,
     145,   148,   149,   152,   155,   158,   159,   162,   163,   166,
     173,   174,   177,   178,   181,   184,   194,   205,   209,   218,
     219,   224,   237,   261,   263,   264,   267,   270,   271,   274,
     278,   286,   287,   291,   292,   293,   294,   297,   298,   301,
     302,   305,   306,   307,   310,   311,   314,   317,   320,   323,
     324,   327,   328,   332,   333,   336,   339,   342,   343,   344,
     345,   346,   347,   348,   351,   352,   353,   354,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   375,   384,   387,
     390,   391,   392,   393,   394,   395,   398,   399,   402,   413,
     430,   447,   457,   460,   461,   464,   465,   469,   480,   484,
     502,   520,   538,   561,   585,   586,   589,   590,   593,   594,
     597,   598,   601,   604,   605,   608,   614,   620,   640,   641,
     645,   663,   712,   713,   714,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   734,   735,   738,   739,
     764,   765,   790,   791,   816,   817,   842,   843,   868,   869,
     904,   941,   942,   977,  1012,  1047,  1082,  1086,  1087,  1108,
    1131,  1158,  1159,  1183,  1208,  1209,  1232,  1258,  1286,  1287,
    1290,  1291,  1292,  1309,  1326,  1329,  1341,  1353,  1354,  1371,
    1374,  1394,  1414,  1415,  1416,  1417,  1420,  1421,  1422,  1425,
    1426,  1429,  1430,  1443,  1450,  1451,  1452,  1453,  1454,  1468,
    1471,  1472,  1475,  1476,  1479,  1498,  1511,  1514,  1515,  1518,
    1541,  1576,  1611,  1612,  1615,  1616,  1619,  1623,  1627,  1631,
    1635,  1639,  1643,  1649,  1650,  1651,  1654
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
  "arg_list_e", "argument_list", "arr_assgn", "array_creat_expr",
  "dim_exprs", "dim_expr", "array_access", "type_name", "name", "literal",
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

#define YYPACT_NINF -358

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-358)))

#define YYTABLE_NINF -219

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,    27,    29,  -358,    61,  -358,    37,  -358,  -358,  -358,
      42,  -358,    -3,  -358,  -358,  -358,    29,    50,  -358,  -358,
    -358,    19,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
      63,   191,  -358,  -358,  -358,    77,  -358,  -358,    28,    41,
    -358,  -358,  -358,  -358,  -358,  -358,    78,  -358,  -358,  1041,
    -358,  -358,  1123,  -358,  -358,    80,    88,   104,  -358,    40,
    -358,    83,     7,    29,   -27,    89,  -358,  -358,  -358,    79,
      91,    94,   112,  1369,   110,   124,   556,  -358,  -358,   556,
     556,   556,  -358,  -358,  -358,  -358,  -358,  -358,   126,   130,
    1123,    73,  -358,   153,  1205,  -358,  -358,   165,  -358,  -358,
    -358,  -358,   170,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,   555,  -358,  -358,    87,   100,   103,   109,
     811,   152,  -358,   113,  -358,   759,   878,  -358,  -358,  -358,
     156,  -358,   203,    83,  -358,   202,  -358,   207,  1552,   204,
     215,  -358,    73,  -358,  -358,   209,   556,   218,   556,  -358,
     556,   556,  -358,    65,   223,  1532,   556,  1450,   556,   556,
     556,   219,  -358,  -358,   894,  -358,   -29,   199,   198,   200,
     201,   120,   133,    75,   138,   168,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,   103,  -358,  -358,   220,  -358,  -358,   229,
     -12,  -358,   218,   218,   228,  -358,   235,  -358,  -358,  -358,
    -358,  1588,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,   556,  -358,  -358,   218,   556,   556,   556,
     218,  -358,   232,  -358,  -358,  1552,  -358,  -358,  -358,  -358,
      69,   238,   556,  -358,   242,   246,   244,   245,   247,   248,
     250,  -358,  -358,   251,  -358,   254,   252,   255,   257,   258,
    -358,  -358,  -358,  -358,   556,   556,   556,   556,   556,   556,
     556,   556,   556,    69,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,  -358,   259,   261,  -358,
     266,  -358,  -358,  -358,   263,   267,   270,   271,  -358,  -358,
     253,   262,  -358,  -358,   272,  -358,   556,   556,  -358,  1397,
     273,   556,   556,   635,  1369,   556,  1632,   281,   199,   198,
     200,   201,   120,   133,   133,   282,    75,    75,    75,    75,
     138,   138,   138,   168,   168,  -358,  -358,  -358,   274,   283,
     285,    71,   556,  -358,  -358,  -358,  -358,  1552,  -358,  -358,
     284,   286,   287,   288,  -358,   301,   307,  -358,  -358,  -358,
     195,  -358,   289,   298,  -358,  -358,  -358,  -358,   556,  -358,
    -358,   534,   285,  -358,  -358,   292,  -358,  -358,   556,  1532,
     556,  1369,   556,   299,   300,   195,  -358,   308,   635,  -358,
     306,  -358,  -358,   303,   313,   315,  -358,   322,  1287,  -358,
    -358,  -358,   318,  -358,   254,  -358,  1397,   556,  1397,  1287,
     877,  1369,   326,   328,  -358,   959,  -358,  1397,   635,  -358,
     329,  1397,  -358
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     2,     3,     5,     8,     7,
       0,   232,    12,     1,     6,   233,     0,     0,    11,    13,
      66,     0,    10,    58,    61,    62,    60,    63,    55,    56,
       0,     0,    17,    19,    20,     0,    21,    22,     0,     0,
      53,    57,    59,    54,    64,    65,    66,    14,    18,     0,
      23,    45,     0,    41,    44,    39,     0,     0,    35,    37,
      42,     0,     0,     0,     0,   214,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,   129,   246,    98,     0,
       0,     0,   245,   244,   243,   237,   238,   239,     0,     0,
       0,     0,    88,     0,     0,    71,    73,     0,    74,    77,
      89,    90,     0,    78,    79,    91,    80,    92,    81,    93,
      94,    95,   100,     0,   101,   103,   104,   102,     0,   105,
     217,   202,   211,   107,   106,   212,   203,   213,   236,   234,
       0,   214,     0,     0,    67,     0,    34,     0,     0,     0,
      25,    27,     0,    82,    83,     0,   221,     0,   221,   135,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   139,     0,   138,   156,   158,   160,   162,
     164,   166,   168,   171,   177,   181,   199,   184,   190,   191,
     194,   205,   204,   197,   218,   216,     0,   195,   217,   212,
     203,   196,     0,     0,     0,    39,    76,    31,    72,    75,
      99,     0,   148,   149,   146,   145,   147,   150,   151,   153,
     155,   154,   152,     0,   201,   200,     0,     0,     0,   221,
       0,    68,     0,    36,    40,    48,    52,    38,    51,    24,
       0,    29,   221,   222,     0,   220,   210,     0,     0,     0,
       0,   127,   133,     0,   124,   126,     0,     0,    53,    54,
     198,   192,   193,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   215,     0,     0,    30,
       0,   140,   224,   141,   209,     0,     0,     0,   235,    43,
       0,    47,    49,    28,     0,    33,     0,   221,    32,     0,
       0,     0,   129,     0,     0,     0,     0,     0,   159,   161,
     163,   165,   167,   169,   170,   176,   173,   172,   175,   174,
     179,   178,   180,   182,   183,   185,   186,   187,     0,     0,
       0,     0,   221,   231,   230,   206,    46,     0,   219,   223,
       0,     0,     0,     0,   108,     0,    77,    85,    86,    87,
     114,   111,     0,     0,   134,   119,   188,   189,     0,    97,
      96,     0,   225,   227,   226,     0,    50,   208,     0,     0,
       0,     0,     0,     0,     0,   113,   115,     0,   131,   157,
       0,   228,   207,     0,     0,     0,   109,     0,     0,   112,
     116,   121,     0,   130,   132,   229,     0,   129,     0,     0,
       0,     0,     0,     0,   120,     0,   122,     0,   131,   110,
       0,     0,   123
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -358,  -358,  -358,  -358,   361,  -358,  -358,  -358,  -358,  -358,
    -358,   343,  -358,  -358,  -358,   249,  -358,   147,  -358,  -358,
    -358,   290,   256,   275,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -216,   -19,  -149,  -358,  -358,  -144,   -10,  -358,   346,
     -36,  -342,   -93,  -358,  -148,   -63,  -240,  -281,  -358,  -358,
    -151,  -358,  -358,  -358,  -358,  -358,  -358,  -358,    11,  -358,
    -358,  -358,  -358,  -358,    18,  -358,  -287,   -18,  -358,  -357,
    -358,  -358,  -358,   426,   -49,   -35,  -358,    39,  -358,   148,
     159,   137,   150,   158,   -45,   -42,   -60,   -37,  -358,   -13,
       0,    14,   114,    76,    90,   125,   139,   431,  -358,  -358,
     354,  -143,  -358,  -358,  -358,  -358,  -312,   512,   122,   575,
      62,  -358,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    17,    18,    22,    30,
      31,    32,    33,    34,    35,   139,   140,   141,    50,    90,
      36,    57,    58,    59,    37,    38,    60,    53,   226,   290,
     291,   227,    91,    40,    41,    42,    43,    44,    45,    92,
      93,    94,    95,    96,    97,    98,   345,    99,   100,   101,
     102,   103,   104,   347,   105,   351,   374,   375,   376,   106,
     348,   107,   108,   349,   243,   244,   161,   392,   393,   245,
     109,   110,   111,   233,   163,   164,   213,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   120,   121,   122,
     185,   234,   235,   124,   282,   362,   363,   125,    20,   126,
     127,   128,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     112,   198,    39,   112,   242,   237,    19,   241,   248,   292,
     154,   146,    39,   249,   113,   353,   132,   113,   346,   364,
      10,   394,   218,   255,   112,   256,   219,    23,    24,    25,
      10,    26,    27,    -4,     1,    28,     2,    15,   113,   143,
       2,   112,   142,     9,   144,   112,   400,   147,    11,   114,
     381,   394,   114,   145,   194,   113,   -16,   405,    11,   113,
      51,    13,   220,   115,    52,     3,   115,   187,   191,     3,
      10,    55,    15,   114,   137,    56,   287,    23,    24,    25,
     138,    26,    27,    16,    10,    28,    21,   115,   236,   294,
     114,    23,    24,    25,   114,    26,    27,   143,    11,    28,
      47,    29,   144,   195,   115,   361,   112,    56,   115,   232,
     403,   149,    11,    49,   142,   346,    61,   346,   133,   315,
     113,   366,   -26,   134,    12,   116,   346,   148,   116,   150,
     346,   330,   151,   277,   278,   135,   136,   263,   247,   117,
     268,   269,   117,    46,   152,   250,   251,   252,   155,   116,
     270,    29,   354,    46,   340,   114,   402,   284,   404,  -205,
    -205,   288,   156,   117,   192,    29,   116,   409,   193,   115,
     116,   412,  -204,  -204,   118,   214,   215,   118,   261,   262,
     117,  -218,  -218,  -218,   117,  -216,  -216,  -216,   119,   365,
     197,   119,    10,   264,   265,   266,   267,   199,   118,    23,
      24,    25,   200,    26,    27,   271,   272,    28,   320,   321,
     322,   142,   119,   372,   373,   118,   313,   314,   242,   118,
      11,   241,   316,   317,   318,   319,   216,   242,   -15,   119,
     147,   116,   195,   119,   323,   324,   344,   273,   274,   275,
     221,   355,   224,   229,   247,   117,   230,   232,    77,   240,
     112,   253,   257,   258,   112,   112,   259,   242,   260,   276,
     325,   326,   327,   217,   113,   279,   135,    10,   113,   113,
     331,   289,   137,    29,    23,    24,    25,   296,    26,    27,
     118,   295,   297,   302,   298,   303,   299,   300,   301,    56,
     336,   304,   356,   337,   119,    11,   305,   306,   328,   114,
     329,   332,   333,   114,   114,   334,   359,   198,   386,   350,
     335,   338,   198,   115,   358,   360,   -54,   115,   115,   361,
     112,   371,   112,   367,   368,   369,   370,   -84,   377,   112,
     378,   382,   388,   344,   113,   355,   113,   389,   406,   112,
     391,   395,   396,   113,   386,   397,   407,   112,   406,   112,
     112,   112,   112,   113,   398,   399,   112,   401,   112,   112,
     408,   113,   112,   113,   113,   113,   113,    14,   411,   114,
     113,   114,   113,   113,    48,   116,   113,   293,   114,   116,
     116,   196,   222,   115,    54,   115,   390,   384,   114,   117,
     410,   223,   115,   117,   117,   310,   114,   379,   114,   114,
     114,   114,   115,   123,   308,   114,   123,   114,   114,   311,
     115,   114,   115,   115,   115,   115,   309,   231,   312,   115,
     357,   115,   115,   380,   118,   115,     0,   123,   118,   118,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,   119,   119,   123,   116,     0,   116,   123,     0,
       0,     0,     0,     0,   116,     0,     0,     0,     0,   117,
       0,   117,     0,     0,   116,     0,     0,     0,   117,     0,
       0,     0,   116,     0,   116,   116,   116,   116,   117,     0,
       0,   116,     0,   116,   116,     0,   117,   116,   117,   117,
     117,   117,     0,     0,   118,   117,   118,   117,   117,     0,
       0,   117,   162,   118,     0,   186,     0,     0,   119,   123,
     119,   188,   188,   118,     0,     0,     0,   119,     0,     0,
       0,   118,     0,   118,   118,   118,   118,   119,     0,     0,
     118,     0,   118,   118,     0,   119,   118,   119,   119,   119,
     119,     0,     0,     0,   119,    66,   119,   119,    67,    68,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,   130,   131,   228,     0,     0,    66,     0,     0,
      67,    68,     0,     0,     0,     0,   238,   239,     0,     0,
       0,     0,   246,   186,     0,     0,    77,     0,     0,   188,
     188,   188,   189,   189,   157,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
     158,     0,     0,   159,   160,     0,     0,   281,    80,    81,
       0,     0,    82,    83,    84,    85,    86,    87,     0,   283,
      63,   130,   131,   285,   286,     0,    66,     0,     0,    67,
      68,   228,     0,   123,     0,   190,   190,   123,   123,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
     189,   189,   189,    79,     0,     0,     0,     0,     0,     0,
     281,   307,     0,     0,     0,     0,     0,   188,   188,   188,
     188,   188,   188,   188,     0,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,   339,   123,     0,   123,     0,   352,   162,     0,
       0,     0,   123,   190,   190,   190,   188,   188,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     123,     0,   123,   123,   123,   123,     0,     0,     0,   123,
       0,   123,   123,   228,     0,   123,     0,     0,   189,   189,
     189,   189,   189,   189,   189,     0,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,     0,   188,
       0,     0,     0,   217,   383,     0,   385,     0,   387,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,     0,     0,     0,     0,     0,     0,   189,   189,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,   190,   190,   190,   190,   190,   190,   190,     0,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,     0,     0,     0,     0,     0,     0,     0,
     189,     0,     0,     0,     0,     0,     0,     0,    62,     0,
     190,   190,    63,   130,   131,    23,    24,    25,    66,    26,
      27,    67,    68,    28,    69,  -118,  -118,     0,    70,    71,
      72,    73,    74,    75,    76,     0,    11,    77,     0,    78,
       0,     0,   218,    52,  -118,    79,   219,     0,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
       0,     0,     0,   190,   254,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,     0,     0,    80,
      81,     0,   220,    82,    83,    84,    85,    86,    87,    29,
      62,    88,    89,     0,    63,   130,   131,    23,    24,    25,
      66,    26,    27,    67,    68,    28,    69,  -117,  -117,     0,
      70,    71,    72,    73,    74,    75,    76,     0,    11,    77,
       0,    78,     0,     0,     0,    52,  -117,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    29,    62,    88,    89,     0,    63,    64,    65,    23,
      24,    25,    66,    26,    27,    67,    68,    28,    69,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,     0,
      11,    77,     0,    78,     0,     0,     0,    52,   -70,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,    82,    83,    84,
      85,    86,    87,    29,    62,    88,    89,     0,    63,   130,
     131,    23,    24,    25,    66,    26,    27,    67,    68,    28,
      69,     0,     0,     0,    70,    71,    72,    73,    74,    75,
      76,     0,    11,    77,     0,    78,     0,     0,     0,    52,
     -70,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,    82,
      83,    84,    85,    86,    87,    29,    62,    88,    89,     0,
      63,   130,   131,    23,    24,    25,    66,    26,    27,    67,
      68,    28,    69,     0,     0,     0,    70,    71,    72,    73,
      74,    75,    76,     0,    11,    77,     0,    78,     0,     0,
       0,    52,   -69,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,     0,
       0,    82,    83,    84,    85,    86,    87,    29,    62,    88,
      89,     0,    63,   130,   131,    23,    24,    25,    66,    26,
      27,    67,    68,    28,    69,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,     0,    11,    77,     0,    78,
       0,     0,     0,    52,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    29,
     153,    88,    89,     0,    63,   130,   131,     0,     0,     0,
      66,     0,     0,    67,    68,     0,    69,     0,     0,     0,
      70,    71,    72,    73,    74,    75,    76,     0,   153,    77,
       0,    78,    63,   130,   131,    52,     0,    79,    66,     0,
       0,    67,    68,     0,    69,     0,     0,     0,   341,    71,
      72,    73,   342,   343,    76,     0,     0,    77,     0,    78,
       0,     0,     0,    52,     0,    79,     0,     0,     0,     0,
       0,    80,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    10,     0,    88,    89,    63,   130,   131,    23,    24,
      25,    66,    26,    27,    67,    68,    28,     0,     0,    80,
      81,     0,     0,    82,    83,    84,    85,    86,    87,    11,
      77,    88,    89,     0,     0,     0,     0,     0,   157,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,     0,     0,   159,   160,     0,
       0,     0,    80,    81,     0,     0,    82,    83,    84,    85,
      86,    87,    29,    10,     0,     0,     0,    63,   130,   131,
      23,    24,    25,    66,    26,    27,    67,    68,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    63,   130,   131,
       0,    11,    77,    66,  -125,     0,    67,    68,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,   225,     0,
     157,     0,     0,   280,   130,   131,     0,     0,     0,    66,
       0,     0,    67,    68,    80,    81,     0,     0,    82,    83,
      84,    85,    86,    87,    29,     0,   158,     0,    77,   159,
     160,     0,     0,     0,    80,    81,   157,     0,    82,    83,
      84,    85,    86,    87,     0,     0,     0,    63,   130,   131,
       0,     0,     0,    66,     0,     0,    67,    68,     0,     0,
       0,     0,   158,     0,     0,   159,   160,     0,     0,     0,
      80,    81,    77,     0,    82,    83,    84,    85,    86,    87,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      49,    94,    21,    52,   155,   148,    16,   155,   157,   225,
      73,    38,    31,   157,    49,   302,    52,    52,   299,   331,
       1,   378,    34,    52,    73,    54,    38,     8,     9,    10,
       1,    12,    13,     0,     1,    16,     3,    30,    73,    32,
       3,    90,    61,    16,    37,    94,   388,    74,    29,    49,
     362,   408,    52,    63,    90,    90,    37,   399,    29,    94,
      32,     0,    74,    49,    36,    32,    52,    80,    81,    32,
       1,    30,    30,    73,    34,    34,   219,     8,     9,    10,
      40,    12,    13,    86,     1,    16,    36,    73,   147,   232,
      90,     8,     9,    10,    94,    12,    13,    32,    29,    16,
      37,    82,    37,    30,    90,    34,   155,    34,    94,    38,
     397,    32,    29,    36,   133,   396,    38,   398,    38,   263,
     155,   337,    39,    35,     2,    49,   407,    38,    52,    38,
     411,   280,    38,   192,   193,    31,    32,     4,   157,    49,
      65,    66,    52,    21,    32,   158,   159,   160,    38,    73,
      75,    82,   303,    31,   297,   155,   396,   216,   398,    72,
      73,   220,    38,    73,    38,    82,    90,   407,    38,   155,
      94,   411,    72,    73,    49,    72,    73,    52,    58,    59,
      90,    72,    73,    74,    94,    72,    73,    74,    49,   332,
      37,    52,     1,    60,    61,    62,    63,    32,    73,     8,
       9,    10,    32,    12,    13,    67,    68,    16,   268,   269,
     270,   230,    73,    18,    19,    90,   261,   262,   369,    94,
      29,   369,   264,   265,   266,   267,    74,   378,    37,    90,
      74,   155,    30,    94,   271,   272,   299,    69,    70,    71,
      37,   304,    35,    39,   263,   155,    31,    38,    30,    26,
     299,    32,    53,    55,   303,   304,    56,   408,    57,    39,
     273,   274,   275,    34,   299,    37,    31,     1,   303,   304,
     280,    39,    34,    82,     8,     9,    10,    31,    12,    13,
     155,    39,    38,    32,    39,    31,    39,    39,    38,    34,
      37,    39,   305,    31,   155,    29,    39,    39,    39,   299,
      39,    38,    35,   303,   304,    35,    32,   400,   371,    36,
      39,    39,   405,   299,    33,    32,    34,   303,   304,    34,
     369,    20,   371,    39,    38,    38,    38,    20,    39,   378,
      32,    39,    33,   396,   369,   398,   371,    37,   401,   388,
      32,    35,    39,   378,   407,    32,    20,   396,   411,   398,
     399,   400,   401,   388,    39,    33,   405,    39,   407,   408,
      32,   396,   411,   398,   399,   400,   401,     6,    39,   369,
     405,   371,   407,   408,    31,   299,   411,   230,   378,   303,
     304,    91,   133,   369,    38,   371,   375,   369,   388,   299,
     408,   135,   378,   303,   304,   258,   396,   358,   398,   399,
     400,   401,   388,    49,   256,   405,    52,   407,   408,   259,
     396,   411,   398,   399,   400,   401,   257,   142,   260,   405,
     306,   407,   408,   361,   299,   411,    -1,    73,   303,   304,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,    -1,
      -1,    -1,   303,   304,    90,   369,    -1,   371,    94,    -1,
      -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,   369,
      -1,   371,    -1,    -1,   388,    -1,    -1,    -1,   378,    -1,
      -1,    -1,   396,    -1,   398,   399,   400,   401,   388,    -1,
      -1,   405,    -1,   407,   408,    -1,   396,   411,   398,   399,
     400,   401,    -1,    -1,   369,   405,   371,   407,   408,    -1,
      -1,   411,    76,   378,    -1,    79,    -1,    -1,   369,   155,
     371,    80,    81,   388,    -1,    -1,    -1,   378,    -1,    -1,
      -1,   396,    -1,   398,   399,   400,   401,   388,    -1,    -1,
     405,    -1,   407,   408,    -1,   396,   411,   398,   399,   400,
     401,    -1,    -1,    -1,   405,    11,   407,   408,    14,    15,
     411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,   138,    -1,    -1,    11,    -1,    -1,
      14,    15,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,
      -1,    -1,   156,   157,    -1,    -1,    30,    -1,    -1,   158,
     159,   160,    80,    81,    38,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    67,    68,    -1,    -1,   201,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    -1,   213,
       5,     6,     7,   217,   218,    -1,    11,    -1,    -1,    14,
      15,   225,    -1,   299,    -1,    80,    81,   303,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
     158,   159,   160,    38,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,   296,   369,    -1,   371,    -1,   301,   302,    -1,
      -1,    -1,   378,   158,   159,   160,   305,   306,    -1,    -1,
      -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     396,    -1,   398,   399,   400,   401,    -1,    -1,    -1,   405,
      -1,   407,   408,   337,    -1,   411,    -1,    -1,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,    -1,   358,
      -1,    -1,    -1,    34,   368,    -1,   370,    -1,   372,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,   305,   306,    -1,
      -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
     305,   306,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    34,    36,    37,    38,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,   358,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    72,
      73,    -1,    74,    76,    77,    78,    79,    80,    81,    82,
       1,    84,    85,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
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
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,     1,    84,    85,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,     1,    84,
      85,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
       1,    84,    85,    -1,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    15,    -1,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,     1,    30,
      -1,    32,     5,     6,     7,    36,    -1,    38,    11,    -1,
      -1,    14,    15,    -1,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,     1,    -1,    84,    85,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    29,
      30,    84,    85,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,     1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
      -1,    29,    30,    11,    32,    -1,    14,    15,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,    11,
      -1,    -1,    14,    15,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    -1,    64,    -1,    30,    67,
      68,    -1,    -1,    -1,    72,    73,    38,    -1,    76,    77,
      78,    79,    80,    81,    -1,    -1,    -1,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    15,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    67,    68,    -1,    -1,    -1,
      72,    73,    30,    -1,    76,    77,    78,    79,    80,    81,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81
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
     184,   185,   186,   187,   190,   194,   196,   197,   198,   199,
       6,     7,   127,    38,    35,    31,    32,    34,    40,   102,
     103,   104,   119,    32,    37,   124,    38,    74,    38,    32,
      38,    38,    32,     1,   132,    38,    38,    38,    64,    67,
      68,   153,   160,   161,   162,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   187,   160,   176,   184,   194,
     196,   176,    38,    38,   127,    30,   108,    37,   129,    32,
      32,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   163,    72,    73,    74,    34,    34,    38,
      74,    37,   102,   109,    35,    36,   115,   118,   160,    39,
      31,   110,    38,   160,   188,   189,   199,   188,   160,   160,
      26,   131,   137,   151,   152,   156,   160,   119,   120,   123,
     176,   176,   176,    32,    40,    52,    54,    53,    55,    56,
      57,    58,    59,     4,    60,    61,    62,    63,    65,    66,
      75,    67,    68,    69,    70,    71,    39,   199,   199,    37,
       5,   160,   191,   160,   199,   160,   160,   188,   199,    39,
     116,   117,   118,   104,   188,    39,    31,    38,    39,    39,
      39,    38,    32,    31,    39,    39,    39,   160,   166,   167,
     168,   169,   170,   171,   171,   123,   172,   172,   172,   172,
     173,   173,   173,   174,   174,   176,   176,   176,    39,    39,
     120,   124,    38,    35,    35,    39,    37,    31,    39,   160,
     188,    21,    25,    26,   132,   133,   134,   140,   147,   150,
      36,   142,   160,   153,   137,   132,   176,   179,    33,    32,
      32,    34,   192,   193,   193,   188,   118,    39,    38,    38,
      38,    20,    18,    19,   143,   144,   145,    39,    32,   164,
     197,   193,    39,   160,   151,   160,   132,   160,    33,    37,
     145,    32,   154,   155,   156,    35,    39,    32,    39,    33,
     128,    39,   133,   153,   133,   128,   132,    20,    32,   133,
     154,    39,   133
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
     137,   137,   137,   137,   137,   137,   137,   137,   138,   139,
     140,   141,   142,   143,   143,   144,   144,   145,   145,   146,
     147,   148,   149,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   156,   156,   157,   158,   159,   160,   160,
     161,   161,   162,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     170,   171,   171,   171,   171,   171,   171,   172,   172,   172,
     172,   173,   173,   173,   174,   174,   174,   174,   175,   175,
     176,   176,   176,   176,   176,   177,   178,   179,   179,   179,
     180,   181,   182,   182,   182,   182,   183,   183,   183,   184,
     184,   185,   185,   186,   186,   186,   186,   186,   186,   187,
     188,   188,   189,   189,   190,   191,   191,   192,   192,   193,
     194,   194,   195,   195,   196,   196,   197,   197,   197,   197,
     197,   197,   197,   198,   198,   198,   199
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
       1,     1,     1,     1,     1,     1,     5,     5,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       7,     5,     3,     1,     0,     1,     2,     4,     3,     5,
       5,     7,     9,     9,     1,     0,     1,     1,     1,     0,
       1,     0,     1,     1,     3,     2,     2,     3,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     4,     4,
       1,     1,     2,     2,     1,     2,     2,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     4,     6,     6,     3,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     5,
       1,     0,     1,     3,     3,     3,     3,     1,     2,     3,
       4,     4,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 116 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "parser.y" /* yacc.c:1646  */
    {strcpy(table->name,(yyvsp[-2].sval));}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "parser.y" /* yacc.c:1646  */
    {finalList=(yyvsp[0].attr)->code;}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);(yyval.attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);totalOff=0;}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 149 "parser.y" /* yacc.c:1646  */
    {totalOff=0;(yyval.attr)=(yyvsp[0].attr);}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						 /*strcpy($$->place,$2);
						 strcpy($$->type,$1);
						 p=Insert(table,$2,$1);*/
						 (yyval.attr)->code=NULL;}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
						 strcpy((yyval.attr)->type,(yyvsp[-1].type));
						 p=Insert(table,(yyvsp[0].attr)->place,(yyval.attr)->type,(yyvsp[0].attr)->assign);
						 if(p==NULL){
							fprintf(stderr,"Error: Variable %s redeclared on line %d\n",(yyvsp[0].attr)->place,yylineno);
							exit(1);
							}
						totalOff+=offset;
						 p->offset=totalOff;}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-2].attr);
						 strcpy((yyval.attr)->type,(yyvsp[-3].type));
						 (yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
						 p=Insert(table,(yyvsp[0].attr)->place,(yyval.attr)->type,(yyvsp[0].attr)->assign);
						 if(p==NULL){
							fprintf(stderr,"Error: Variable %s redeclared on line %d\n",(yyvsp[0].attr)->place,yylineno);
							exit(1);
							}totalOff+=offset;
						 p->offset=totalOff;}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								(yyval.attr)->code=NULL;	
								(yyval.attr)->assign=false;
								strcpy((yyval.attr)->place,(yyvsp[0].sval));}
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
								int l =strlen((yyvsp[-3].type));
								if((yyvsp[-3].type)[l-1]!='2'){
									sprintf(t,", =, %s, %s",(yyvsp[-2].sval),(yyvsp[0].attr)->place);
								(yyval.attr)->code=append((yyval.attr)->code,newList(t));	
								(yyval.attr)->assign=true;	}
								strcpy((yyval.attr)->place,(yyvsp[-2].sval));}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);strcpy(idr,(yyvsp[0].sval));}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-2].sval);
							sprintf((yyvsp[-3].type), "%s2",(yyvsp[-3].type));
							}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
							(yyval.attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);
							if(!ret){
								if(strcmp((yyvsp[-1].attr)->type,"void1")==0){
									sprintf(t,", ret");
									(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
								else{
									fprintf(stderr,"Error: Missing return statement in function %s\n",(yyvsp[-1].attr)->place);
									exit(1);}}
							currFunc->offset=totalOff;
							table=table->prev;}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
								ret=false;
								strcpy((yyval.attr)->place,(yyvsp[0].sval));
								strcpy((yyval.attr)->type,(yyvsp[-1].type));
				 				strcat((yyval.attr)->type,"1");
								sprintf(t,", func, %s",(yyvsp[0].sval));
								(yyval.attr)->code=newList(t);
				  				p=Insert(table,(yyvsp[0].sval),(yyval.attr)->type,true);
								currFunc=p;
								strcpy(methodType,(yyvsp[-1].type));
							if(strcmp(methodType,"void") && strcmp(methodType,"int")){
								fprintf(stderr,"Error on %d: Invalid method type\n",yylineno);
								exit(1);
							}
							if(p==NULL){
								fprintf(stderr,"Error: Variable %s redeclared on line %d\n",(yyvsp[0].sval),yylineno);
								exit(1);
							}else{
								p->func=(Symtab *)malloc(sizeof(Symtab));
								p->func->prev=table;
								table=p->func;
								strcpy(table->name,(yyvsp[0].sval));}}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-3].sval);}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 267 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[-1].attr);}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);(yyval.attr)->idx[0] = '0';
				  sprintf(t, "=, %s[%d], %s", idr,(yyval.attr)->idx[0]-'0', (yyvsp[0].attr)->place);
				  (yyval.attr)->code  = append((yyvsp[0].attr)->code, newList(t));
			  }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						(yyval.attr)->code = append((yyvsp[-2].attr)->code, (yyvsp[0].attr)->code);
						(yyval.attr)->idx[0] = (yyvsp[-2].attr)->idx[0]+1;
						sprintf(t,"=, %s[%d], %s", idr,(yyval.attr)->idx[0]-'0', (yyvsp[0].attr)->place);
						(yyval.attr)->code  = append((yyval.attr)->code, newList(t));
						}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 293 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].type);}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);offset=1;}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=(yyvsp[0].sval);offset=8;}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 317 "parser.y" /* yacc.c:1646  */
    {sprintf((yyvsp[-2].type),"%s2",(yyvsp[-2].type));}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 323 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 328 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);
							 (yyval.attr)=(yyvsp[-1].attr);}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 332 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 339 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 343 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 347 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 348 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 351 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 352 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 357 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 358 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 359 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 360 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 361 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 364 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-2].attr);
							sprintf(t,", scan, %s",(yyvsp[-2].attr)->place);
							p=look_up(table,(yyvsp[-2].attr)->place);
							if(p==NULL){
								fprintf(stderr,"Error: Variable %s not declared on line %d\n",(yyvsp[-2].attr)->place,yylineno);
								exit(1);}
							p->assign=true;
							(yyvsp[-2].attr)->assign=true;
							(yyval.attr)->code=newList(t);}
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 375 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-2].attr);  p = look_up(table, (yyvsp[-2].attr)->place);
							if(p && p->assign){
								sprintf(t,", print, %s",(yyvsp[-2].attr)->place);
								(yyval.attr)->code=newList(t);}
							else{
								fprintf(stderr,"Error: Variable %s not declared on line %d\n",(yyvsp[-2].attr)->place,yylineno);
								exit(1);}}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 384 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 387 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 390 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 391 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 392 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 393 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 394 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 395 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
					sprintf(t,", call, %s",(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));}
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 398 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 399 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 402 "parser.y" /* yacc.c:1646  */
    { char end[5];
									  strcpy(end,newLabel());
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-2].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-2].attr)->place,end);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 413 "parser.y" /* yacc.c:1646  */
    { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());		
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-4].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-4].attr)->place,else_beg);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  sprintf(t,", Goto, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",else_beg);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  
									   	  }
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 431 "parser.y" /* yacc.c:1646  */
    { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());
									  (yyval.attr)=(Attr *)malloc(sizeof(Attr));	
                      						          (yyval.attr)->code = append((yyval.attr)->code , (yyvsp[-4].attr)->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",(yyvsp[-4].attr)->place,else_beg);
									  (yyval.attr)->code = append((yyval.attr)->code ,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[-2].attr)->code);
									  sprintf(t,", Goto, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",else_beg);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  (yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t)); }
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 447 "parser.y" /* yacc.c:1646  */
    {  char end[5];
							 	strcpy(end,newLabel());
								(yyval.attr)=(yyvsp[0].attr);
								patchBreak((yyvsp[0].attr)->code,end);
								sprintf(t,", label, %s",end);
								(yyval.attr)->code = append((yyval.attr)->code,newList(t));
								patchSwitch((yyval.attr)->code,(yyvsp[-2].attr)->place);
								}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 457 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 460 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 461 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 2795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 464 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 465 "parser.y" /* yacc.c:1646  */
    {   (yyval.attr)=(yyvsp[-1].attr);
									(yyval.attr)->code= append((yyval.attr)->code,(yyvsp[0].attr)->code);}
#line 2808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval.attr)=(Attr*)malloc(sizeof(Attr));
								char nexLabel[5];
								strcpy(nexLabel,newLabel());
								sprintf(t,", ifgoto, neq, %s ,  , %s",(yyvsp[-2].attr)->place,nexLabel);
								(yyval.attr)->code=newList(t);
								(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);
								sprintf(t,", label, %s",nexLabel);
								(yyval.attr)->code=append((yyval.attr)->code,newList(t));
								(yyval.attr)->code->swt = 1;
								(yyval.attr)->code->swt_len += strlen((yyvsp[-2].attr)->place);}
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 480 "parser.y" /* yacc.c:1646  */
    { (yyval.attr)=(Attr*)malloc(sizeof(Attr));
								(yyval.attr)->code = append((yyval.attr)->code,(yyvsp[0].attr)->code);	}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 484 "parser.y" /* yacc.c:1646  */
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
									  sprintf(t,", Goto, %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 502 "parser.y" /* yacc.c:1646  */
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
									  sprintf(t,", Goto, %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 520 "parser.y" /* yacc.c:1646  */
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
									  sprintf(t,", Goto, %s",begin);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          (yyval.attr)->code = append((yyval.attr)->code,newList(t));  }
#line 2893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 538 "parser.y" /* yacc.c:1646  */
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
									  			sprintf(t,", Goto, %s",begin);
       								          		        (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  		        sprintf(t,", label, %s",end);
       								          	                (yyval.attr)->code = append((yyval.attr)->code,newList(t));}
#line 2919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 562 "parser.y" /* yacc.c:1646  */
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
									  			sprintf(t,", Goto, %s",begin);
       								          		        (yyval.attr)->code = append((yyval.attr)->code,newList(t));
									  		        sprintf(t,", label, %s",end);
       								          	               (yyval.attr)->code = append((yyval.attr)->code,newList(t));}
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 585 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 586 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 589 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 590 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 593 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 594 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;strcpy((yyval.attr)->place,"");(yyval.attr)->assign=true;}
#line 2981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 597 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 598 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 601 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 604 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 605 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);(yyval.attr)=(yyvsp[-2].attr);}
#line 3011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 608 "parser.y" /* yacc.c:1646  */
    {  (yyval.attr) = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,", Goto, ");
					(yyval.attr)->code = newList(t);
					(yyval.attr)->code->br = 1;}
#line 3020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 614 "parser.y" /* yacc.c:1646  */
    {  (yyval.attr) = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,", Goto, ");
					(yyval.attr)->code = newList(t);
					(yyval.attr)->code->cont = 1;}
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 620 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);
					ret=true;
					if (!strcmp((yyvsp[-1].attr)->place,"") && !strcmp(methodType,"void"))
						strcpy(t,", ret");
					else if(strcmp((yyvsp[-1].attr)->place,"") || strcmp(methodType,"void")){
						if(!strcmp((yyvsp[-1].attr)->type,"int")) 
					 		sprintf(t,", ret, %s",(yyvsp[-1].attr)->place);
						else if(!strcmp((yyvsp[-1].attr)->type,"int0")) 
					 		sprintf(t,", ret, %s",(yyvsp[-1].attr)->place);
						else{
						fprintf(stderr,"Error %d: Return type mismatch\n",yylineno);
						exit(1);
					}}
					else{
						fprintf(stderr,"Error %d: Return type mismatch\n",yylineno);
						exit(1);
					}
					 (yyval.attr)->code=append((yyvsp[-1].attr)->code,newList(t));}
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 640 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 641 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 645 "parser.y" /* yacc.c:1646  */
    {sprintf(t,", =, %s, %s",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
						(yyval.attr)->code = append((yyvsp[-2].attr)->code, (yyvsp[0].attr)->code);
						char tr[50];
						int q = 0;
						while(q<50 && (yyvsp[-2].attr)->place[q]!='['){
							tr[q] = (yyvsp[-2].attr)->place[q];
							q++;
							}
						p=look_up(table,tr);
						if(p)
							p->assign =true;
						else{
							fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
							exit(1);
						}
						(yyval.attr)->code=append((yyval.attr)->code,newList(t));
						}
#line 3086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 663 "parser.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
						char tr[50];
						int q = 0;
						while(q<50 && (yyvsp[-2].attr)->place[q]!='['){
							tr[q] = (yyvsp[-2].attr)->place[q];
							q++;
							}
						p=look_up(table,tr);
						if(p==NULL){
							fprintf(stderr,"Error on %d: %s undeclared\n",yylineno,(yyvsp[-2].attr)->place);
							exit(1);
						}	
						else if(!p->assign){	
							fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
							exit(1);
						}
						else{
							switch(flag1){
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
						}}
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 712 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 713 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 714 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);sprintf(t, "%s[%s]",(yyvsp[0].attr)->place, (yyvsp[0].attr)->idx);
					strcpy((yyval.attr)->place, t);
					/*$$->code = append($$->code,$1->code);*/}
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 721 "parser.y" /* yacc.c:1646  */
    {flag1=1;}
#line 3164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 722 "parser.y" /* yacc.c:1646  */
    {flag1=2;}
#line 3170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 723 "parser.y" /* yacc.c:1646  */
    {flag1=3;}
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 724 "parser.y" /* yacc.c:1646  */
    {flag1=4;}
#line 3182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 725 "parser.y" /* yacc.c:1646  */
    {flag1=5;}
#line 3188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 726 "parser.y" /* yacc.c:1646  */
    {flag1=6;}
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 727 "parser.y" /* yacc.c:1646  */
    {flag1=7;}
#line 3200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 728 "parser.y" /* yacc.c:1646  */
    {flag1=8;}
#line 3206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 729 "parser.y" /* yacc.c:1646  */
    {flag1=9;}
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 730 "parser.y" /* yacc.c:1646  */
    {flag1=10;}
#line 3218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 731 "parser.y" /* yacc.c:1646  */
    {flag1=11;}
#line 3224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 734 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 738 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 739 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
							p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
							strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", ||, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 764 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 765 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
							p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
							strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", &&, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 790 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 791 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
							p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
							strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", |, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 816 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 817 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
							p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
							strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", ^, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 842 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 843 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
							p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
							strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", &, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 868 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 869 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
					sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
					totalOff+=8;
					p->offset=totalOff;
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, eq , %s , %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", Goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s, 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 904 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
					sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
					totalOff+=8;
					p->offset=totalOff;
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, neq , %s , %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", Goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s, 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 941 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 3490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 942 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
					sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
					totalOff+=8;
					p->offset=totalOff;
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, lt , %s , %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", Goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s, 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 977 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
					sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
					totalOff+=8;
					p->offset=totalOff;
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, gt , %s , %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", Goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1012 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
					sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
					totalOff+=8;
					p->offset=totalOff;
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,",ifgoto, leq , %s , %s ,%s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", Goto , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1047 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
					sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
					totalOff+=8;
					p->offset=totalOff;
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,",ifgoto, geq, %s, %s , %s ",(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place,begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 0",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", Goto, %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",begin);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", = , %s , 1",(yyval.attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));
					sprintf(t,", label , %s",end);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 3646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1086 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1087 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", <<, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1108 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", >>, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1131 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							strcpy((yyval.attr)->place,t);
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", >>>, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1158 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1159 "parser.y" /* yacc.c:1646  */
    {
							(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								/*exit(1);*/
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							sprintf(temp,"%s",tempVar());
							p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
							strcpy((yyval.attr)->place,temp);
							strcpy((yyval.attr)->type,(yyvsp[-2].attr)->type);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", +, %s, %s, %s",temp,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1183 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", -, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1208 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1209 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyval.attr)=(yyvsp[-2].attr);
sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1232 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							else if(atoi((yyvsp[0].attr)->place)==0){
								fprintf(stderr,"Error on line %d: Division by 0\n",yylineno);
								exit(1);}
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", /, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1258 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							if(!(yyvsp[-2].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-2].attr)->place);
								exit(1);
							}
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-2].attr)->type,"int"))
								typeError(yylineno);
							else if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							else if(atoi((yyvsp[0].attr)->place)==0){
								fprintf(stderr,"Error on line %d: Modulus by 0\n",yylineno);
								exit(1);}
							(yyval.attr)=(yyvsp[-2].attr);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[-2].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,", %%, %s, %s, %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 3894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1290 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1291 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1292 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							(yyval.attr)=(yyvsp[0].attr);
							if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[0].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							sprintf(t,", =, %s, %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							}
#line 3928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1309 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							sprintf(temp,"%s",tempVar());
					p=Insert(table,temp,(yyvsp[0].attr)->type,true);
					strcpy((yyval.attr)->place,temp);
							totalOff+=8;
							p->offset=totalOff;
							sprintf(t,", -, %s, 0, %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1326 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1329 "parser.y" /* yacc.c:1646  */
    {sprintf(t,", +, %s, %s, 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1341 "parser.y" /* yacc.c:1646  */
    {sprintf(t,", -, %s, %s, 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 3986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1353 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 3992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1354 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[0].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[0].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[0].attr)->type,"int"))
								typeError(yylineno);
							strcpy(temp,tempVar());
							p=Insert(table,temp,(yyvsp[0].attr)->type,true);
							totalOff+=8;
							p->offset=totalOff;
							strcpy((yyval.attr)->place,temp);
							sprintf(t,", !, %s, %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 4014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1371 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1374 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[-1].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-1].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-1].attr)->type,"int"))
								typeError(yylineno);
							strcpy(temp,tempVar());
							sprintf(t,", =, %s, %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,", -, %s, %s, 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							p=Insert(table,temp,(yyvsp[-1].attr)->type,true);
							totalOff+=8;
							p->offset=totalOff;
							}
#line 4043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1394 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							if(!(yyvsp[-1].attr)->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,(yyvsp[-1].attr)->place);
								exit(1);
							}
							if(strcmp((yyvsp[-1].attr)->type,"int"))
								typeError(yylineno);
							strcpy(temp,tempVar());
							sprintf(t,", =, %s, %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,", -, %s, %s, 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							p=Insert(table,temp,(yyvsp[-1].attr)->type,true);
							totalOff+=8;
							p->offset=totalOff;
							}
#line 4066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1414 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1415 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1416 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1417 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1420 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-3].attr);}
#line 4096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1421 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1422 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1425 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1426 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1429 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1430 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
					char temp[15];
					strcpy(temp,tempVar());
					if(strcmp((yyvsp[0].attr)->type,"int2")==0){strcpy((yyval.attr)->type,"int");}
					if(strcmp((yyvsp[0].attr)->type,"float2")==0){strcpy((yyval.attr)->type,"float");}
					sprintf((yyvsp[0].attr)->place, "%s[%s]",(yyvsp[0].attr)->place,(yyvsp[0].attr)->idx);
					sprintf(t,", =, %s, %s",temp,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));
					strcpy((yyval.attr)->place,temp);
					}
#line 4141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1443 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);(yyval.attr)->assign=true;
							sprintf(t,"%s","const");
							if(!look_up(table,(yyvsp[0].attr)->place))
							p=Insert(table,(yyvsp[0].attr)->place,t,true);
							if(strcmp((yyvsp[0].attr)->type,"int0")==0)
								strcpy((yyval.attr)->type,"int");
							}
#line 4153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1450 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1451 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 4165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1452 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));(yyval.attr)->code=NULL;}
#line 4171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1453 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1454 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);
						if(strcmp((yyvsp[0].attr)->type,"int1"))
							typeError(yylineno);
						sprintf(t,", =, %s, call, %s",tempVar(),(yyvsp[0].attr)->place);
						(yyval.attr)->code=append((yyvsp[0].attr)->code,newList(t));
						strcpy((yyval.attr)->place,TEMP);
						strcpy(t,"int");
						p=Insert(table,TEMP,t,true);
						totalOff+=8;
						p->offset=totalOff;
						strcpy((yyval.attr)->type,t);
						}
#line 4194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1479 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);
							 if((yyvsp[-2].attr)->type[strlen((yyvsp[-2].attr)->type)-1]!='2'){
								fprintf(stderr,"Error on %d: Variable used is not array\n",yylineno);
								exit(1);}
							 p=look_up(table,(yyvsp[-2].attr)->place);
							 if(p)
								p->assign=true;
							 else{
								fprintf(stderr,"Error: Variable %s not declared on line %d\n",(yyvsp[-2].attr)->place, yylineno);
						exit(1);
							}
							p->arrLength=length;
							totalOff+=(length-1)*offset;
							p->offset=totalOff;
							length=1;
							(yyval.attr)->assign=true;
							}
#line 4216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1498 "parser.y" /* yacc.c:1646  */
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
#line 4234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1511 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 4240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1514 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 4246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1518 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[-1].attr);p = look_up(table,(yyvsp[(-2) - (3)].attr)->place);
					if(!(yyvsp[-1].attr)->assign){
						fprintf(stderr,"Error: Index not assigned on line %d\n",yylineno);
						exit(1);
					}
					else if(strcmp((yyvsp[-1].attr)->type,"int0")!=0){
						fprintf(stderr,"Error on line %d: Index is not an integer literal int value \n",yylineno);
						exit(1);
					}
					if(p!=NULL){ Arr_dim *a = (Arr_dim*)malloc(sizeof(Arr_dim));
					strcpy(a->d, (yyvsp[-1].attr)->place);
					Arr_dim *b = p->arr_dim;
					length*=atoi((yyvsp[-1].attr)->place);
					if(b){
					while(b->next!=NULL){
						b = b->next;
						}
					b->next = a;
					}
					else p->arr_dim = a;}
				}
#line 4272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1541 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-3].attr);
					(yyval.attr)->code = append((yyvsp[-3].attr)->code, (yyvsp[-1].attr)->code);
					p = look_up(table,(yyvsp[-3].attr)->place);
					if(!(yyvsp[-1].attr)->assign){
						fprintf(stderr,"Error: Index not assigned on line %d\n",yylineno);
						exit(1);
					}
					if(p){	
						h = p->arr_dim;
						if(h && h->next){
							strcpy(t,"int");
							p=Insert(table,tempVar(),t,true);
							totalOff+=8;
							p->offset=totalOff;
							strcpy((yyval.attr)->idx,TEMP);
							sprintf(t,", =, %s, 1",(yyval.attr)->idx);
							(yyval.attr)->code=append((yyvsp[-3].attr)->code,newList(t));
							Arr_dim *v = h->next;
							while(v){
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->idx, (yyval.attr)->idx,v->d);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							v = v->next;
							}
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->idx, (yyval.attr)->idx,(yyvsp[-1].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							h = h->next;
							}
						else  if(h) strcpy((yyval.attr)->idx, (yyvsp[-1].attr)->place);
						}
					else{
						fprintf(stderr,"Error: Variable %s not declared on line %d\n",(yyvsp[-3].attr)->place,yylineno);
						exit(1);}
					(yyval.attr)->assign=(yyvsp[-3].attr)->assign;
					}
#line 4311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1576 "parser.y" /* yacc.c:1646  */
    {
						(yyval.attr)=(yyvsp[-3].attr);
						if(!(yyvsp[-1].attr)->assign){
							fprintf(stderr,"Error: Index not assigned on line %d\n",yylineno);
							exit(1);
						}
						if(h && h->next){
							strcpy(t,"int");
							p=Insert(table,tempVar(),t,true);
							totalOff+=8;
							p->offset=totalOff;
							strcpy((yyval.attr)->idx,TEMP);
							sprintf(t,", =, %s, 1",(yyval.attr)->idx);
							(yyval.attr)->code=append((yyvsp[-3].attr)->code,newList(t));
							Arr_dim *v = h->next;
							while(v){
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->idx, (yyval.attr)->idx,v->d);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							v = v->next;
							}
							sprintf(t,", *, %s, %s, %s",(yyval.attr)->idx, (yyval.attr)->idx,(yyvsp[-1].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							sprintf(t,", +, %s, %s, %s",(yyval.attr)->idx, (yyval.attr)->idx,(yyvsp[-3].attr)->idx);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));		
							}
						else if(h){
							strcpy((yyval.attr)->idx, (yyvsp[-3].attr)->idx);
							sprintf(t,", +, %s, %s, %s",(yyvsp[-3].attr)->idx, (yyvsp[-3].attr)->idx,(yyvsp[-1].attr)->place);
							(yyval.attr)->code=append((yyvsp[-3].attr)->code,newList(t));
							}
						h = h->next;
						(yyval.attr)->assign=(yyvsp[-3].attr)->assign;
						}
#line 4349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1611 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 4355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1612 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 4361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1615 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 4367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1619 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					sprintf((yyval.attr)->place,"%d",(yyvsp[0].ival));
					strcpy((yyval.attr)->type,"int0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 4376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1623 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					sprintf((yyval.attr)->place,"%f",(yyvsp[0].fval));
					strcpy((yyval.attr)->type,"float0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 4385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1627 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,(yyvsp[0].sval));
					strcpy((yyval.attr)->type,"char0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 4394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1631 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,(yyvsp[0].sval));
					strcpy((yyval.attr)->type,"str0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 4403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1635 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place,"1");
					strcpy((yyval.attr)->type,"bool0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;}
#line 4412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1639 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->type,"bool0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place,"0");}
#line 4421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1643 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->type,"bool0");
					(yyval.attr)->code=NULL;(yyval.attr)->assign=true;
					strcpy((yyval.attr)->place,"null");}
#line 4430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1649 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 4436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1650 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 4442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1651 "parser.y" /* yacc.c:1646  */
    {(yyval.ival)=(yyvsp[0].ival);}
#line 4448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1654 "parser.y" /* yacc.c:1646  */
    {SymtabEntry *tempo=look_up(table,(yyvsp[0].sval));
					if(tempo!=NULL){
						(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						strcpy((yyval.attr)->place,(yyvsp[0].sval));
						strcpy((yyval.attr)->type,tempo->type);
						(yyval.attr)->assign=tempo->assign;
						(yyval.attr)->code=NULL;
						}
					else{
						yyerrok;
						}}
#line 4464 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4468 "y.tab.c" /* yacc.c:1646  */
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
#line 1666 "parser.y" /* yacc.c:1906  */

int main(int argc, char** argv){
	totalOff=0;
	offset=0;
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
	translator(finalList);
	/*printSymtab(mainTable);
	printList(finalList);*/
	free(p);
	free(mainTable);
	fclose(fptr);
	return 0;
}

