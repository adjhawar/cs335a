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
SymtabEntry *head,*tail, *p;
Attr* attr;
struct StackStr{
	int size;
	char **array;
};


struct StackStr* createCharStack(){
	struct StackStr* stack= (struct StackStr*)malloc(sizeof(struct StackStr));
	stack->size = -1;
	stack->array = (char**) malloc(maxsize * sizeof(char *));
        for(int i=0;i< maxsize; i++)
        {
            stack->array[i]=(char*)malloc(100 * sizeof(char ));
	}
	return stack;
}

int isFullStr(struct StackStr* stack){
   return stack->size == maxsize - 1; 
}
 
int isEmptyStr(struct StackStr* stack){
   return stack->size == -1;
}

void pushStr(struct StackStr* stack, char* item){
    if (stack == NULL){
        printf("Invalid argument. p == NULL.\n");
    }
    else if (stack->array == NULL) {
        printf("Stack not initialized.\n");
            return;
    }
    else if (stack->size == maxsize) {
        printf("Stack is full\n");
        return;
    }
    strcpy(stack->array[++stack->size],item);
}

char* popStr(struct StackStr* stack){
    if (isEmptyStr(stack))
        return NULL;
    return stack->array[stack->size--];
}

char* tempVar(){
	static int i=0;
	sprintf(TEMP,"temp%d",i);
	i++;
	return TEMP;
}

struct StackStr* lexeme;
struct StackStr* str1 ;
struct StackStr* str2;
struct Stack* attr_stack;

#line 141 "y.tab.c" /* yacc.c:339  */

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
    OP_RSH = 319,
    OP_LSH = 320,
    OP_ADD = 321,
    OP_SUB = 322,
    OP_MUL = 323,
    OP_DIV = 324,
    OP_MOD = 325,
    OP_INC = 326,
    OP_DEC = 327,
    OP_DOT = 328,
    OP_ZRSH = 329,
    INT_LIT_D = 330,
    INT_LIT_O = 331,
    INT_LIT_H = 332,
    FLOAT_LIT = 333,
    CHAR_LIT = 334,
    STR_LIT = 335,
    ERROR = 336,
    PRINT = 337,
    SCAN = 338,
    OP_NEG = 339,
    STRING = 340,
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
#define OP_RSH 319
#define OP_LSH 320
#define OP_ADD 321
#define OP_SUB 322
#define OP_MUL 323
#define OP_DIV 324
#define OP_MOD 325
#define OP_INC 326
#define OP_DEC 327
#define OP_DOT 328
#define OP_ZRSH 329
#define INT_LIT_D 330
#define INT_LIT_O 331
#define INT_LIT_H 332
#define FLOAT_LIT 333
#define CHAR_LIT 334
#define STR_LIT 335
#define ERROR 336
#define PRINT 337
#define SCAN 338
#define OP_NEG 339
#define STRING 340
#define EXTENDS 341

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 78 "parser.y" /* yacc.c:355  */

	int ival;
	char *sval;
	float fval;

#line 359 "y.tab.c" /* yacc.c:355  */
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

#line 390 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1567

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  246
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  405

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
       0,   110,   110,   113,   114,   117,   118,   119,   122,   123,
     126,   129,   130,   133,   136,   139,   140,   143,   144,   147,
     148,   151,   152,   155,   158,   161,   162,   165,   166,   169,
     172,   173,   176,   177,   180,   184,   185,   188,   189,   192,
     196,   199,   202,   205,   208,   209,   212,   215,   216,   219,
     220,   223,   224,   227,   228,   229,   230,   233,   234,   237,
     238,   241,   242,   243,   246,   247,   250,   253,   256,   259,
     260,   263,   264,   267,   268,   271,   274,   278,   279,   280,
     281,   282,   283,   284,   287,   288,   289,   290,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   305,   308,
     311,   312,   313,   314,   315,   316,   317,   320,   323,   326,
     329,   332,   335,   336,   339,   340,   343,   346,   347,   350,
     351,   354,   357,   360,   363,   366,   369,   370,   373,   374,
     377,   378,   381,   382,   385,   388,   389,   392,   395,   398,
     401,   402,   405,   414,   415,   416,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   433,   434,
     437,   438,   441,   442,   445,   448,   449,   452,   453,   456,
     457,   458,   461,   462,   463,   464,   465,   466,   469,   470,
     481,   492,   505,   506,   517,   530,   531,   544,   555,   568,
     569,   572,   573,   574,   583,   592,   595,   606,   617,   618,
     627,   630,   641,   652,   653,   654,   655,   658,   659,   660,
     663,   664,   667,   668,   671,   672,   673,   674,   675,   676,
     677,   680,   683,   684,   687,   688,   691,   692,   695,   696,
     699,   700,   703,   704,   707,   708,   711,   712,   713,   714,
     715,   716,   717,   720,   721,   722,   725
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
  "OP_GEQ", "OP_LEQ", "OP_RSH", "OP_LSH", "OP_ADD", "OP_SUB", "OP_MUL",
  "OP_DIV", "OP_MOD", "OP_INC", "OP_DEC", "OP_DOT", "OP_ZRSH", "INT_LIT_D",
  "INT_LIT_O", "INT_LIT_H", "FLOAT_LIT", "CHAR_LIT", "STR_LIT", "ERROR",
  "PRINT", "SCAN", "OP_NEG", "STRING", "EXTENDS", "$accept",
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
  "switch_block_st_grps", "switch_block_st_grp", "switch_labels",
  "switch_label", "while_st", "while_st_no_short_if", "do_st", "for_st",
  "for_st_no_short_if", "for_init_e", "for_init", "expr_e", "for_update_e",
  "for_update", "st_expr_list", "break_st", "continue_st", "return_st",
  "expr", "assgn", "lhs", "assgn_op", "cond_expr", "cond_or_expr",
  "cond_and_expr", "incl_or_expr", "excl_or_expr", "and_expr",
  "equality_expr", "rel_expr", "shift_expr", "add_expr", "mul_expr",
  "cast_expr", "unary_expr", "preinc_expr", "predec_expr",
  "unary_expr_not_plus_minus", "postdec_expr", "postinc_expr",
  "postfix_expr", "method_invo", "field_access", "primary",
  "primary_no_new_array", "object_expr", "arg_list_e", "argument_list",
  "array_creat_expr", "dim_expr", "array_access", "type_name", "name",
  "literal", "int_literal", "identifier", YY_NULLPTR
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

#define YYPACT_NINF -356

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-356)))

#define YYTABLE_NINF -247

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     145,    27,    60,  -356,    62,  -356,     8,  -356,  -356,  -356,
      23,  -356,   -26,  -356,  -356,  -356,    60,    48,  -356,  -356,
    -356,    20,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
      86,   172,  -356,  -356,  -356,    59,  -356,  -356,    96,   125,
    -356,  -356,  -356,  -356,  -356,  -356,    69,  -356,  -356,  1037,
    -356,  -356,  1120,  -356,  -356,    88,   115,   108,  -356,     7,
    -356,   119,   204,   -10,   287,   -22,   138,  -356,  -356,  -356,
     140,   141,   151,   179,  1286,   162,   177,  1400,  -356,  -356,
    1400,  1400,  1400,  -356,  -356,  -356,  -356,  -356,  -356,   188,
     196,  1120,   134,  -356,   215,  1203,  -356,  -356,   222,  -356,
    -356,  -356,  -356,   226,  -356,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,   870,  -356,  -356,    98,   120,   126,
      72,   886,   187,   228,   135,  -356,   953,   597,  -356,  -356,
    -356,   192,  -356,   229,  -356,   240,  -356,   239,   782,   204,
     238,   247,  -356,   134,  -356,  -356,   246,   137,  1400,   251,
    1400,  -356,  1400,  1400,  -356,    53,   256,   731,  1400,    58,
    1400,  1400,  1400,   252,  -356,  -356,  -356,   -28,   230,  -356,
     231,   236,   149,    19,    28,   165,   168,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,   126,  -356,  -356,   255,  -356,  -356,
    -356,    10,  -356,   782,   251,   248,  -356,   267,  -356,  -356,
    -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,  -356,
    -356,  -356,  -356,  -356,  1400,  -356,  -356,   251,  1400,  1400,
    1400,   251,  -356,  -356,  -356,   782,  -356,  -356,  -356,   265,
    -356,   263,   268,  1365,  -356,  1400,  -356,  -356,   266,   275,
     271,   272,   273,   278,   276,  -356,  -356,   286,  -356,   279,
     280,   288,   281,   284,  -356,  -356,  -356,  -356,  1400,  1400,
    1400,  1400,  1400,  1400,  1400,   263,  1400,  1400,  1400,  1400,
    1400,  1400,  1400,  1400,  1400,  1400,  1400,  1400,  -356,     0,
    -356,   289,  -356,  -356,   291,   297,   299,   298,  -356,   301,
     308,  -356,  -356,  -356,   305,   303,  -356,  1400,  1400,  -356,
    1314,   310,  1400,  1400,  1487,  1286,  1400,  1476,   311,   230,
    -356,   236,   149,    19,    19,   315,    28,    28,    28,    28,
     165,   165,   165,   168,   168,  -356,  -356,  -356,   782,  -356,
    -356,  1400,  -356,  -356,  -356,  -356,  -356,  -356,  -356,   317,
     320,   321,   322,  -356,   341,   344,  -356,  -356,  -356,   185,
    -356,   329,   337,  -356,  -356,  -356,  -356,  1400,  -356,   332,
    -356,  1400,   731,  1400,  1286,  1400,   339,   340,   185,  -356,
     954,  -356,   346,  1487,  -356,  -356,   342,   347,   343,  -356,
     350,  -356,  -356,  -356,   871,  -356,  -356,   345,  -356,   279,
    1314,  1400,  1314,  -356,  1286,   360,   353,  -356,  -356,  1314,
    1487,  -356,   352,  1314,  -356
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
      42,     0,     0,     0,     0,     0,   215,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   131,   246,    98,
       0,     0,     0,   245,   244,   243,   237,   238,   239,     0,
       0,     0,     0,    88,     0,     0,    71,    73,     0,    74,
      77,    89,    90,     0,    78,    79,    91,    80,    92,    81,
      93,    94,    95,   100,     0,   101,   103,   104,   102,     0,
     219,   218,   203,   212,   217,   213,   220,   204,   214,   236,
     234,     0,   215,     0,    67,     0,    34,     0,     0,     0,
       0,    25,    27,     0,    82,    83,     0,     0,   223,     0,
     223,   137,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   141,   140,   158,   160,   162,
     164,   165,   167,   169,   172,   178,   182,   200,   185,   191,
     192,   195,   206,   205,   198,   219,   217,     0,   196,   218,
     220,   204,   197,     0,     0,     0,    39,    76,    31,    72,
      75,    99,   146,   150,   151,   148,   147,   149,   152,   153,
     155,   157,   156,   154,     0,   202,   201,     0,     0,     0,
     223,     0,    68,    36,    40,    48,    52,    38,    51,     0,
      24,     0,    29,     0,   226,   223,   227,   224,     0,   222,
     211,     0,     0,     0,     0,   129,   135,     0,   126,   128,
       0,     0,    53,    54,   193,   194,   199,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,     0,
      49,     0,    30,   142,   210,     0,     0,     0,   235,     0,
      47,    43,    28,   229,     0,     0,    33,     0,   223,    32,
       0,     0,     0,   131,     0,     0,     0,     0,     0,   161,
     163,   166,   168,   170,   171,   177,   174,   173,   176,   175,
     180,   179,   181,   183,   184,   186,   187,   188,     0,    97,
      96,   223,   231,   230,   207,    46,   228,   221,   225,     0,
       0,     0,     0,   107,     0,    77,    85,    86,    87,   113,
     110,     0,     0,   136,   121,   189,   190,     0,    50,     0,
     209,     0,     0,     0,     0,     0,     0,     0,   112,   114,
       0,   117,     0,   133,   159,   208,     0,     0,     0,   108,
       0,   120,   111,   115,     0,   118,   123,     0,   132,   134,
       0,   131,     0,   119,     0,     0,     0,   122,   124,     0,
     133,   109,     0,     0,   125
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -356,  -356,  -356,  -356,   380,  -356,  -356,  -356,  -356,  -356,
    -356,   358,  -356,  -356,  -356,   253,  -356,   163,  -356,  -356,
    -356,   306,   270,   257,  -356,  -356,  -356,  -356,  -356,  -356,
     176,  -134,   -12,   -50,  -356,  -356,  -149,    22,  -356,   369,
     -35,    41,   -93,  -356,  -156,   128,  -241,  -293,  -356,  -356,
    -152,  -356,  -356,  -356,  -356,  -356,  -356,  -356,    44,  -356,
      43,  -356,  -356,  -356,  -356,  -356,    52,  -356,  -290,    15,
    -356,  -355,  -356,  -356,  -356,   403,   -49,  -356,  -356,    64,
    -356,   158,   159,  -356,   161,   169,   -18,   -44,   -30,   -24,
    -356,   -47,   -37,     3,   116,    26,    70,   104,   144,   420,
    -356,  -356,   195,  -144,  -356,  -356,   277,   448,   110,   568,
    -356,  -356,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    17,    18,    22,    30,
      31,    32,    33,    34,    35,   140,   141,   142,    50,    91,
      36,    57,    58,    59,    37,    38,    60,    53,   226,   289,
     279,   280,    92,    40,    41,    42,    43,    44,    45,    93,
      94,    95,    96,    97,    98,    99,   344,   100,   101,   102,
     103,   104,   105,   346,   106,   350,   367,   368,   369,   370,
     371,   107,   347,   108,   109,   348,   247,   248,   163,   387,
     388,   249,   110,   111,   112,   237,   165,   114,   214,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   121,
     122,   123,   186,   238,   239,   125,   234,   126,    20,   127,
     128,   129,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   245,   199,   113,   227,   246,   241,   345,    61,    39,
     253,     2,   115,   352,   146,   115,   148,   133,   389,    39,
      15,    10,   144,   265,   258,   113,   259,   145,    23,    24,
      25,   328,    26,    27,   188,   192,    28,   115,    19,   329,
       3,   137,   113,     9,   219,   389,   113,   138,   220,    11,
     143,   149,   116,    15,   115,   116,   195,   -16,   115,    10,
      16,    10,    13,    64,   131,   132,    23,    24,    25,    67,
      26,    27,    68,    69,    28,   117,   287,   116,   117,   266,
     267,   268,   269,   221,    21,   144,   147,    11,    78,    11,
     145,   295,   270,   271,   116,    49,   159,   345,   116,   345,
     117,   396,   272,  -105,  -105,    29,   345,    62,   113,   252,
     345,  -105,    12,   254,   255,   256,   315,   117,   240,   118,
     115,   117,   118,    47,   160,   161,  -246,   143,    51,    81,
      82,    46,    52,    83,    84,    85,    86,    87,    88,   135,
     136,    46,   162,    29,   118,    -4,     1,   251,     2,   395,
     134,   397,   353,   119,   339,    55,   119,   139,   401,    56,
     116,   118,   404,   281,   196,   118,  -106,  -106,    56,  -206,
    -206,   233,   151,    10,  -106,   235,   150,     3,   119,   152,
      23,    24,    25,   117,    26,    27,   284,   359,    28,   153,
     288,  -205,  -205,   120,   358,   119,   120,   215,   216,   119,
     157,    11,   156,   365,   366,    10,   245,   263,   264,   -15,
     246,   154,    23,    24,    25,   158,    26,    27,   120,   143,
      28,   246,   316,   317,   318,   319,   193,   118,   325,   326,
     327,   273,   274,    11,   194,   120,   275,   276,   277,   120,
     320,   321,   322,   -26,   124,   313,   314,   124,   246,   323,
     324,   113,   198,   251,   200,   113,   113,    29,   201,   355,
     217,   119,   218,   115,    10,   149,   222,   115,   115,   124,
     196,    23,    24,    25,   224,    26,    27,   230,   231,    28,
     233,    78,   244,   260,   257,   282,   124,   261,    10,    29,
     124,   199,    11,   262,   278,    23,    24,    25,   135,    26,
      27,   120,   137,   116,   291,   296,   297,   116,   116,   298,
     304,   299,   300,   113,   302,   113,    11,   301,   303,   305,
     306,   113,    56,   307,   113,   115,   117,   115,   330,   331,
     117,   117,   332,   115,   333,   113,   115,   334,   335,   328,
     336,   113,   337,   113,   357,   113,   349,   115,    29,   -54,
     113,   113,   124,   115,   113,   115,   360,   115,   361,   362,
     363,   364,   115,   115,   -84,   116,   115,   116,   372,   373,
     118,   375,   381,   116,   118,   118,   116,   382,   386,   391,
     399,   390,   392,   393,   394,   400,    14,   116,   117,    48,
     117,   403,   229,   116,   292,   116,   117,   116,   197,   117,
     232,   290,   116,   116,   119,   223,   116,    54,   119,   119,
     117,   384,   383,   385,   377,   402,   117,   309,   117,   310,
     117,   374,   311,   356,   236,   117,   117,     0,   343,   117,
       0,   312,   118,   354,   118,     0,     0,     0,     0,     0,
     118,     0,     0,   118,   120,     0,     0,     0,   120,   120,
       0,     0,     0,     0,   118,     0,     0,     0,     0,     0,
     118,     0,   118,     0,   118,     0,   119,     0,   119,   118,
     118,     0,     0,   118,   119,     0,     0,   119,     0,     0,
     164,     0,     0,   187,     0,     0,     0,     0,   119,     0,
       0,     0,   379,     0,   119,   124,   119,     0,   119,   124,
     124,   189,   189,   119,   119,     0,   120,   119,   120,     0,
       0,     0,     0,     0,   120,     0,     0,   120,   343,     0,
     354,     0,   398,     0,     0,     0,     0,   379,   120,   190,
     190,   398,     0,     0,   120,     0,   120,     0,   120,     0,
       0,   228,     0,   120,   120,     0,     0,   120,     0,     0,
       0,     0,     0,     0,     0,   242,   243,   124,     0,   124,
       0,   250,   187,     0,     0,   124,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     189,   189,   189,     0,     0,   124,     0,   124,     0,   124,
       0,     0,     0,     0,   124,   124,   228,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,   190,
     190,     0,     0,     0,     0,     0,     0,   283,     0,     0,
       0,   285,   286,     0,     0,     0,     0,     0,   228,     0,
       0,   219,     0,     0,     0,   220,   294,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   191,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     189,   189,   189,   189,   189,     0,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,     0,     0,
     338,     0,     0,     0,     0,   351,   164,   190,   190,   190,
     190,   190,   190,     0,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   189,   189,   191,   191,
     191,   228,    10,     0,     0,     0,    64,   131,   132,    23,
      24,    25,    67,    26,    27,    68,    69,    28,     0,     0,
       0,     0,     0,     0,   190,   190,     0,     0,     0,     0,
      11,    78,     0,  -127,   376,     0,   378,     0,   380,    80,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,   131,   132,
       0,     0,     0,    67,   164,     0,    68,    69,     0,     0,
       0,     0,    81,    82,     0,   190,    83,    84,    85,    86,
      87,    88,    78,     0,     0,     0,    29,     0,   225,     0,
     159,     0,     0,     0,     0,     0,     0,   191,   191,   191,
     191,   191,   191,     0,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,     0,     0,   160,   161,
       0,     0,     0,    81,    82,     0,     0,    83,    84,    85,
      86,    87,    88,     0,     0,     0,   162,     0,     0,     0,
       0,     0,    63,     0,   191,   191,    64,   131,   132,    23,
      24,    25,    67,    26,    27,    68,    69,    28,    70,  -116,
    -116,     0,    71,    72,    73,    74,    75,    76,    77,     0,
      11,    78,     0,    79,     0,     0,     0,    52,  -116,    80,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,     0,     0,   191,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,     0,     0,
       0,     0,    81,    82,     0,     0,    83,    84,    85,    86,
      87,    88,     0,    89,    90,    63,    29,     0,     0,    64,
     131,   132,    23,    24,    25,    67,    26,    27,    68,    69,
      28,    70,   365,   366,     0,    71,    72,    73,    74,    75,
      76,    77,     0,    11,    78,     0,    79,     0,     0,     0,
      52,     0,    80,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,     0,    83,
      84,    85,    86,    87,    88,     0,    89,    90,    63,    29,
       0,     0,    64,    65,    66,    23,    24,    25,    67,    26,
      27,    68,    69,    28,    70,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,     0,    11,    78,     0,    79,
       0,     0,     0,    52,   -70,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,    83,    84,    85,    86,    87,    88,     0,    89,
      90,    63,    29,     0,     0,    64,   131,   132,    23,    24,
      25,    67,    26,    27,    68,    69,    28,    70,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,     0,    11,
      78,     0,    79,     0,     0,     0,    52,   -70,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,    83,    84,    85,    86,    87,
      88,     0,    89,    90,    63,    29,     0,     0,    64,   131,
     132,    23,    24,    25,    67,    26,    27,    68,    69,    28,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,     0,    11,    78,     0,    79,     0,     0,     0,    52,
     -69,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,     0,    83,    84,
      85,    86,    87,    88,     0,    89,    90,   155,    29,     0,
       0,    64,   131,   132,     0,     0,     0,    67,     0,     0,
      68,    69,     0,    70,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    77,     0,   155,    78,     0,    79,    64,
     131,   132,    52,     0,    80,    67,     0,     0,    68,    69,
       0,    70,     0,     0,     0,   340,    72,    73,    74,   341,
     342,    77,     0,     0,    78,     0,    79,     0,     0,     0,
      52,     0,    80,     0,     0,     0,     0,    81,    82,     0,
       0,    83,    84,    85,    86,    87,    88,     0,    89,    90,
      64,   131,   132,     0,     0,     0,    67,     0,     0,    68,
      69,     0,     0,     0,     0,    81,    82,     0,     0,    83,
      84,    85,    86,    87,    88,    78,    89,    90,     0,     0,
     293,     0,     0,   159,     0,    64,   131,   132,     0,     0,
       0,    67,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,   160,   161,     0,     0,     0,    81,    82,   159,     0,
      83,    84,    85,    86,    87,    88,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,    81,    82,     0,     0,    83,    84,    85,    86,    87,
      88,    64,   131,   132,   162,     0,     0,    67,     0,     0,
      68,    69,    64,   131,   132,     0,     0,     0,    67,     0,
       0,    68,    69,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,   159,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,     0,    81,    82,
     162,     0,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      49,   157,    95,    52,   138,   157,   150,   300,    39,    21,
     159,     3,    49,   303,    64,    52,    38,    52,   373,    31,
      30,     1,    32,     4,    52,    74,    54,    37,     8,     9,
      10,    31,    12,    13,    81,    82,    16,    74,    16,    39,
      32,    34,    91,    16,    34,   400,    95,    40,    38,    29,
      62,    73,    49,    30,    91,    52,    91,    37,    95,     1,
      86,     1,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    49,   220,    74,    52,    60,
      61,    62,    63,    73,    36,    32,    64,    29,    30,    29,
      37,   235,    64,    65,    91,    36,    38,   390,    95,   392,
      74,   391,    74,    31,    32,    85,   399,    38,   157,   159,
     403,    39,     2,   160,   161,   162,   265,    91,   149,    49,
     157,    95,    52,    37,    66,    67,    38,   139,    32,    71,
      72,    21,    36,    75,    76,    77,    78,    79,    80,    31,
      32,    31,    84,    85,    74,     0,     1,   159,     3,   390,
      35,   392,   304,    49,   298,    30,    52,    38,   399,    34,
     157,    91,   403,   194,    30,    95,    31,    32,    34,    71,
      72,    34,    32,     1,    39,    38,    38,    32,    74,    38,
       8,     9,    10,   157,    12,    13,   217,   331,    16,    38,
     221,    71,    72,    49,   328,    91,    52,    71,    72,    95,
      38,    29,    74,    18,    19,     1,   362,    58,    59,    37,
     362,    32,     8,     9,    10,    38,    12,    13,    74,   231,
      16,   373,   266,   267,   268,   269,    38,   157,   275,   276,
     277,    66,    67,    29,    38,    91,    68,    69,    70,    95,
     270,   271,   272,    39,    49,   263,   264,    52,   400,   273,
     274,   300,    37,   265,    32,   304,   305,    85,    32,   306,
      73,   157,    34,   300,     1,    73,    37,   304,   305,    74,
      30,     8,     9,    10,    35,    12,    13,    39,    31,    16,
      34,    30,    26,    53,    32,    37,    91,    56,     1,    85,
      95,   384,    29,    57,    39,     8,     9,    10,    31,    12,
      13,   157,    34,   300,    39,    39,    31,   304,   305,    38,
      31,    39,    39,   362,    38,   364,    29,    39,    32,    39,
      39,   370,    34,    39,   373,   362,   300,   364,    39,    38,
     304,   305,    35,   370,    35,   384,   373,    39,    37,    31,
      35,   390,    39,   392,    33,   394,    36,   384,    85,    34,
     399,   400,   157,   390,   403,   392,    39,   394,    38,    38,
      38,    20,   399,   400,    20,   362,   403,   364,    39,    32,
     300,    39,    33,   370,   304,   305,   373,    37,    32,    32,
      20,    39,    39,    33,    39,    32,     6,   384,   362,    31,
     364,    39,   139,   390,   231,   392,   370,   394,    92,   373,
     143,   225,   399,   400,   300,   135,   403,    38,   304,   305,
     384,   370,   368,   370,   362,   400,   390,   259,   392,   260,
     394,   357,   261,   307,   147,   399,   400,    -1,   300,   403,
      -1,   262,   362,   305,   364,    -1,    -1,    -1,    -1,    -1,
     370,    -1,    -1,   373,   300,    -1,    -1,    -1,   304,   305,
      -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,
     390,    -1,   392,    -1,   394,    -1,   362,    -1,   364,   399,
     400,    -1,    -1,   403,   370,    -1,    -1,   373,    -1,    -1,
      77,    -1,    -1,    80,    -1,    -1,    -1,    -1,   384,    -1,
      -1,    -1,   364,    -1,   390,   300,   392,    -1,   394,   304,
     305,    81,    82,   399,   400,    -1,   362,   403,   364,    -1,
      -1,    -1,    -1,    -1,   370,    -1,    -1,   373,   390,    -1,
     392,    -1,   394,    -1,    -1,    -1,    -1,   399,   384,    81,
      82,   403,    -1,    -1,   390,    -1,   392,    -1,   394,    -1,
      -1,   138,    -1,   399,   400,    -1,    -1,   403,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,   153,   362,    -1,   364,
      -1,   158,   159,    -1,    -1,   370,    -1,    -1,   373,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   384,
     160,   161,   162,    -1,    -1,   390,    -1,   392,    -1,   394,
      -1,    -1,    -1,    -1,   399,   400,   193,    -1,   403,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    34,    -1,    -1,    -1,    38,   233,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,    -1,    -1,
     297,    -1,    -1,    -1,    -1,   302,   303,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   306,   307,   160,   161,
     162,   328,     1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   306,   307,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,   361,    -1,   363,    -1,   365,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
      -1,    -1,    -1,    11,   391,    -1,    14,    15,    -1,    -1,
      -1,    -1,    71,    72,    -1,   357,    75,    76,    77,    78,
      79,    80,    30,    -1,    -1,    -1,    85,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,    -1,    -1,    66,    67,
      -1,    -1,    -1,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,     1,    -1,   306,   307,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,   357,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    80,    -1,    82,    83,     1,    85,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    32,    -1,    -1,    -1,
      36,    -1,    38,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,     1,    85,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    82,
      83,     1,    85,    -1,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,     1,    85,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    32,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    82,    83,     1,    85,    -1,
      -1,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,
      14,    15,    -1,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,     1,    30,    -1,    32,     5,
       6,     7,    36,    -1,    38,    11,    -1,    -1,    14,    15,
      -1,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    82,    83,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    30,    82,    83,    -1,    -1,
      35,    -1,    -1,    38,    -1,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    66,    67,    -1,    -1,    -1,    71,    72,    38,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,     5,     6,     7,    84,    -1,    -1,    11,    -1,    -1,
      14,    15,     5,     6,     7,    -1,    -1,    -1,    11,    -1,
      -1,    14,    15,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    71,    72,
      84,    -1,    75,    76,    77,    78,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    32,    88,    89,    90,    91,    92,    16,
       1,    29,   195,     0,    91,    30,    86,    93,    94,   124,
     195,    36,    95,     8,     9,    10,    12,    13,    16,    85,
      96,    97,    98,    99,   100,   101,   107,   111,   112,   119,
     120,   121,   122,   123,   124,   125,   195,    37,    98,    36,
     105,    32,    36,   114,   126,    30,    34,   108,   109,   110,
     113,   199,    38,     1,     5,     6,     7,    11,    14,    15,
      17,    21,    22,    23,    24,    25,    26,    27,    30,    32,
      38,    71,    72,    75,    76,    77,    78,    79,    80,    82,
      83,   106,   119,   126,   127,   128,   129,   130,   131,   132,
     134,   135,   136,   137,   138,   139,   141,   148,   150,   151,
     159,   160,   161,   163,   164,   179,   180,   182,   183,   184,
     185,   186,   187,   188,   189,   192,   194,   196,   197,   198,
     199,     6,     7,   127,    35,    31,    32,    34,    40,    38,
     102,   103,   104,   119,    32,    37,   120,   124,    38,    73,
      38,    32,    38,    38,    32,     1,   132,    38,    38,    38,
      66,    67,    84,   155,   162,   163,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   189,   162,   178,   186,
     194,   196,   178,    38,    38,   127,    30,   108,    37,   129,
      32,    32,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   165,    71,    72,    73,    34,    34,
      38,    73,    37,   109,    35,    36,   115,   118,   162,   102,
      39,    31,   110,    34,   193,    38,   193,   162,   190,   191,
     199,   190,   162,   162,    26,   131,   137,   153,   154,   158,
     162,   119,   120,   123,   178,   178,   178,    32,    52,    54,
      53,    56,    57,    58,    59,     4,    60,    61,    62,    63,
      64,    65,    74,    66,    67,    68,    69,    70,    39,   117,
     118,   199,    37,   162,   199,   162,   162,   190,   199,   116,
     117,    39,   104,    35,   162,   190,    39,    31,    38,    39,
      39,    39,    38,    32,    31,    39,    39,    39,   162,   168,
     169,   171,   172,   173,   173,   123,   174,   174,   174,   174,
     175,   175,   175,   176,   176,   178,   178,   178,    31,    39,
      39,    38,    35,    35,    39,    37,    35,    39,   162,   190,
      21,    25,    26,   132,   133,   134,   140,   149,   152,    36,
     142,   162,   155,   137,   132,   178,   181,    33,   118,   190,
      39,    38,    38,    38,    20,    18,    19,   143,   144,   145,
     146,   147,    39,    32,   166,    39,   162,   153,   162,   132,
     162,    33,    37,   145,   128,   147,    32,   156,   157,   158,
      39,    32,    39,    33,    39,   133,   155,   133,   132,    20,
      32,   133,   156,    39,   133
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
     141,   142,   143,   143,   144,   144,   145,   146,   146,   147,
     147,   148,   149,   150,   151,   152,   153,   153,   154,   154,
     155,   155,   156,   156,   157,   158,   158,   159,   160,   161,
     162,   162,   163,   164,   164,   164,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   166,   166,
     167,   167,   168,   168,   169,   170,   170,   171,   171,   172,
     172,   172,   173,   173,   173,   173,   173,   173,   174,   174,
     174,   174,   175,   175,   175,   176,   176,   176,   176,   177,
     177,   178,   178,   178,   178,   178,   179,   180,   181,   181,
     181,   182,   183,   184,   184,   184,   184,   185,   185,   185,
     186,   186,   187,   187,   188,   188,   188,   188,   188,   188,
     188,   189,   190,   190,   191,   191,   192,   192,   193,   193,
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
       1,     1,     1,     1,     1,     1,     4,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     7,
       5,     3,     1,     0,     1,     2,     2,     1,     2,     3,
       2,     5,     5,     7,     9,     9,     1,     0,     1,     1,
       1,     0,     1,     0,     1,     1,     3,     2,     2,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     3,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     4,
       4,     1,     1,     2,     2,     1,     2,     2,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     4,     6,     6,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     5,     1,     0,     1,     3,     3,     3,     3,     2,
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
#line 119 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 180 "parser.y" /* yacc.c:1646  */
    {p =Insert(attr_stack->attr[attr_stack->size].place);
							strcpy(p->type,attr_stack->attr[attr_stack->size-1].type);}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 192 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
				  strcpy(attr->place,(yyvsp[0].sval));
				  push(attr_stack,attr);
				  free(attr); }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 229 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "void");push(attr_stack,attr);}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 230 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "string");push(attr_stack,attr);}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 234 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "bool");push(attr_stack,attr);}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 238 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "float");push(attr_stack,attr);}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 241 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "byte");push(attr_stack,attr);}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 242 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "char");push(attr_stack,attr);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 243 "parser.y" /* yacc.c:1646  */
    {strcpy(attr->type, "int");push(attr_stack,attr);}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 274 "parser.y" /* yacc.c:1646  */
    {p =Insert(attr_stack->attr[attr_stack->size].place);
							strcpy(p->type,attr_stack->attr[attr_stack->size-1].type);}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 283 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 284 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 405 "parser.y" /* yacc.c:1646  */
    {/*Attr temp=pop(attr_stack);
					Attr temp2=pop(attr_stack);
					char t[100];
					sprintf(t,"%s = %s",temp2.place,temp.place);
					temp2.code=append(temp.code,newList(t));
					push(attr_stack,&temp2);*/
					}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 470 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp2=pop(attr_stack);
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						attr->code=append(attr->code,temp2.code);
						char t[100];
						sprintf(t,"%s = %s << %s",attr->place,temp.place,temp2.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 481 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp2=pop(attr_stack);
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						attr->code=append(attr->code,temp2.code);
						char t[100];
						sprintf(t,"%s = %s >> %s",attr->place,temp.place,temp2.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 492 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						Attr temp2=pop(attr_stack);
						attr->code=append(attr->code,temp2.code);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s >>> %s",attr->place,temp2.place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 506 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						Attr temp2=pop(attr_stack);
						attr->code=append(attr->code,temp2.code);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s + %s",attr->place,temp2.place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 517 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						Attr temp2=pop(attr_stack);
						attr->code=append(attr->code,temp2.code);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s - %s",attr->place,temp2.place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 531 "parser.y" /* yacc.c:1646  */
    {Attr *attr1=(Attr *)malloc(sizeof(Attr));
						strcpy(attr1->place,tempVar());
						printf("%d\n",attr_stack->size);
						Attr temp=pop(attr_stack);
						Attr temp2=pop(attr_stack);
						attr1->code=append(attr1->code,temp2.code);	
						attr1->code=append(attr1->code,temp.code);
						char t[100];
						printf("Error is here\n");
						sprintf(t,"%s = %s * %s",attr1->place,temp2.place,temp.place);
						attr1->code=append(attr1->code,newList(t));
						push(attr_stack,attr1);
						free(attr);}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 544 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						Attr temp2=pop(attr_stack);
						attr->code=append(attr->code,temp2.code);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s / %s",attr->place,temp2.place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 555 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						Attr temp2=pop(attr_stack);
						attr->code=append(attr->code,temp2.code);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s %% %s",attr->place,temp2.place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 574 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = + %s",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 583 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = - %s",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 595 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = ++ %s",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 606 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = -- %s",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 618 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = ! %s",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 630 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s --",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 641 "parser.y" /* yacc.c:1646  */
    {Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s ++",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 703 "parser.y" /* yacc.c:1646  */
    {pushStr(lexeme,(yyvsp[0].sval));}
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 712 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%f",(yyvsp[0].fval));pushStr(lexeme,ch);}
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 713 "parser.y" /* yacc.c:1646  */
    {pushStr(lexeme,(yyvsp[0].sval));}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 714 "parser.y" /* yacc.c:1646  */
    {pushStr(lexeme,(yyvsp[0].sval));}
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 720 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%d",(yyvsp[0].ival));pushStr(lexeme,ch);}
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 721 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%d",(yyvsp[0].ival));pushStr(lexeme,ch);}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 722 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%d",(yyvsp[0].ival));pushStr(lexeme,ch);}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 725 "parser.y" /* yacc.c:1646  */
    {SymtabEntry *p=look_up((yyvsp[0].sval));
				  Attr *attr=(Attr *)malloc(sizeof(Attr));
				  if(p!=NULL){
					  strcpy(attr->place,(yyvsp[0].sval));
					  push(attr_stack,attr);
				  }else
					  yyerrok;
				  free(attr);
			  }
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2508 "y.tab.c" /* yacc.c:1646  */
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
#line 735 "parser.y" /* yacc.c:1906  */

struct StackStr* str4;
int main(int argc, char** argv){
//	s1 = createIntStack();
	p=(SymtabEntry *)malloc(sizeof(SymtabEntry));
	attr_stack = createIntStack();
	lexeme = createCharStack();
    str1 = createCharStack();
    str2= createCharStack();
    str4= createCharStack();
	attr=(Attr *)malloc(sizeof(Attr));
    //push(s1,0);
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
       // free(s1);
       // free(s2);
SymtabEntry *temp=head;
	while(temp){
		printf("%s,%s\n",temp->lexeme,temp->type);
		temp=temp->next;
	}
	printList(pop(attr_stack).code);	
        free(str1);
        free(str2);
        free(str4);
        free(lexeme);
	free(p);
	free(attr_stack);
        fclose(fptr);
	return 0;
}
