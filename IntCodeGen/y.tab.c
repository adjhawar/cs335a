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
SymtabEntry *head,*tail, *p,*p1;
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

char* newLabel(){
	static int z=0;
	sprintf(LABEL,"L%d",z);
	z++;
	return LABEL;
}

struct StackStr* lexeme;
struct StackStr* str1 ;
struct StackStr* str2;
struct Stack* attr_stack;

#line 151 "y.tab.c" /* yacc.c:339  */

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
#line 88 "parser.y" /* yacc.c:355  */

	int ival;
	char *sval;
	float fval;
	char *type;
	struct Attr *attr;

#line 371 "y.tab.c" /* yacc.c:355  */
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

#line 402 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   1514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  247
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  407

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
       0,   130,   130,   133,   134,   137,   138,   139,   142,   143,
     146,   149,   150,   153,   156,   159,   160,   163,   164,   167,
     168,   171,   172,   175,   178,   181,   182,   185,   186,   189,
     192,   193,   196,   197,   200,   203,   208,   214,   215,   218,
     219,   222,   225,   228,   231,   232,   235,   238,   239,   242,
     243,   246,   247,   250,   251,   252,   253,   256,   257,   260,
     261,   264,   265,   266,   269,   270,   273,   276,   279,   282,
     283,   286,   287,   291,   292,   295,   298,   301,   302,   303,
     304,   305,   306,   307,   310,   311,   312,   313,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   328,   331,
     334,   335,   336,   337,   338,   339,   340,   343,   346,   349,
     352,   355,   358,   359,   362,   363,   366,   369,   370,   373,
     374,   377,   394,   397,   400,   403,   406,   407,   410,   411,
     414,   415,   418,   419,   422,   425,   426,   429,   432,   435,
     438,   439,   442,   472,   473,   474,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   491,   492,
     495,   496,   504,   505,   513,   514,   522,   523,   531,   532,
     540,   541,   547,   555,   556,   562,   568,   574,   580,   584,
     585,   591,   597,   606,   607,   613,   620,   621,   627,   633,
     641,   642,   645,   646,   647,   654,   661,   664,   670,   676,
     677,   684,   687,   698,   709,   710,   711,   712,   715,   716,
     717,   720,   721,   724,   725,   728,   729,   730,   731,   732,
     733,   734,   737,   740,   741,   744,   745,   748,   749,   752,
     753,   756,   757,   760,   761,   764,   765,   768,   769,   770,
     771,   772,   773,   774,   777,   778,   779,   782
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

#define YYPACT_NINF -354

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-354)))

#define YYTABLE_NINF -248

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,    19,    28,  -354,    51,  -354,    18,  -354,  -354,  -354,
       8,  -354,   -14,  -354,  -354,  -354,    28,    39,  -354,  -354,
    -354,    31,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
      44,   125,  -354,  -354,  -354,    76,  -354,  -354,    85,   106,
    -354,  -354,  -354,  -354,  -354,  -354,    49,  -354,  -354,   969,
    -354,  -354,  1051,  -354,  -354,    92,   116,    38,  -354,    -6,
    -354,   135,    70,   131,   262,   -18,   152,  -354,  -354,  -354,
     137,   158,   167,   174,   537,   170,   172,  1433,  -354,  -354,
    1433,  1433,  1433,  -354,  -354,  -354,  -354,  -354,  -354,   178,
     183,  1051,   109,  -354,   181,  1133,  -354,  -354,   190,  -354,
    -354,  -354,  -354,   195,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,   821,  -354,  -354,    75,   103,   113,
      34,   886,   156,   197,    53,  -354,   898,   806,  -354,  -354,
    -354,   159,  -354,   198,  -354,   204,  -354,   202,  1353,    70,
     199,   208,  -354,   109,  -354,  -354,   207,    89,  1433,   210,
    1433,  -354,  1433,  1433,  -354,    16,   217,  1333,  1433,  1251,
    1433,  1433,  1433,   212,  -354,  -354,  -354,    36,   193,   196,
     192,   203,    86,    96,   -39,   111,   124,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,   113,  -354,  -354,   211,  -354,  -354,
    -354,   -15,  -354,  1353,   210,   222,  -354,   230,  -354,  -354,
    -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,  -354,  -354,  -354,  1433,  -354,  -354,   210,  1433,  1433,
    1433,   210,  -354,  -354,  -354,  1353,  -354,  -354,  -354,   214,
    -354,   216,   228,  1389,  -354,  1433,  -354,  -354,   226,   235,
     229,   234,   237,   238,   240,  -354,  -354,   247,  -354,   250,
     243,   249,   245,   248,  -354,  -354,  -354,  -354,  1433,  1433,
    1433,  1433,  1433,  1433,  1433,  1433,   216,  1433,  1433,  1433,
    1433,  1433,  1433,  1433,  1433,  1433,  1433,  1433,  1433,  -354,
      93,  -354,   251,  -354,  -354,   255,   253,   254,   256,  -354,
     257,   265,  -354,  -354,  -354,   264,   261,  -354,  1433,  1433,
    -354,  1215,   266,  1433,  1433,   642,   537,  1433,   721,   270,
     193,   196,   192,   203,    86,    96,    96,   252,   -39,   -39,
     -39,   -39,   111,   111,   111,   124,   124,  -354,  -354,  -354,
    1353,  -354,  -354,  1433,  -354,  -354,  -354,  -354,  -354,  -354,
    -354,   267,   269,   272,   273,  -354,   285,   292,  -354,  -354,
    -354,   180,  -354,   274,   282,  -354,  -354,  -354,  -354,  1433,
    -354,   279,  -354,  1433,  1333,  1433,   537,  1433,   286,   287,
     180,  -354,   887,  -354,   290,   642,  -354,  -354,   291,   293,
     295,  -354,   298,  -354,  -354,  -354,   805,  -354,  -354,   297,
    -354,   250,  1215,  1433,  1215,  -354,   537,   312,   307,  -354,
    -354,  1215,   642,  -354,   301,  1215,  -354
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     2,     3,     5,     8,     7,
       0,   233,    12,     1,     6,   234,     0,     0,    11,    13,
      66,     0,    10,    58,    61,    62,    60,    63,    55,    56,
       0,     0,    17,    19,    20,     0,    21,    22,     0,     0,
      53,    57,    59,    54,    64,    65,    66,    14,    18,     0,
      23,    45,     0,    41,    44,    39,     0,     0,    35,    37,
      42,     0,     0,     0,     0,     0,   216,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   131,   247,    98,
       0,     0,     0,   246,   245,   244,   238,   239,   240,     0,
       0,     0,     0,    88,     0,     0,    71,    73,     0,    74,
      77,    89,    90,     0,    78,    79,    91,    80,    92,    81,
      93,    94,    95,   100,     0,   101,   103,   104,   102,     0,
     220,   219,   204,   213,   218,   214,   221,   205,   215,   237,
     235,     0,   216,     0,    67,     0,    34,     0,     0,     0,
       0,    25,    27,     0,    82,    83,     0,     0,   224,     0,
     224,   137,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   141,   140,   158,   160,   162,
     164,   166,   168,   170,   173,   179,   183,   201,   186,   192,
     193,   196,   207,   206,   199,   220,   218,     0,   197,   219,
     221,   205,   198,     0,     0,     0,    39,    76,    31,    72,
      75,    99,   146,   150,   151,   148,   147,   149,   152,   153,
     155,   157,   156,   154,     0,   203,   202,     0,     0,     0,
     224,     0,    68,    36,    40,    48,    52,    38,    51,     0,
      24,     0,    29,     0,   227,   224,   228,   225,     0,   223,
     212,     0,     0,     0,     0,   129,   135,     0,   126,   128,
       0,     0,    53,    54,   200,   194,   195,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,    49,     0,    30,   142,   211,     0,     0,     0,   236,
       0,    47,    43,    28,   230,     0,     0,    33,     0,   224,
      32,     0,     0,     0,   131,     0,     0,     0,     0,     0,
     161,   163,   165,   167,   169,   171,   172,   178,   175,   174,
     177,   176,   181,   180,   182,   184,   185,   187,   188,   189,
       0,    97,    96,   224,   232,   231,   208,    46,   229,   222,
     226,     0,     0,     0,     0,   107,     0,    77,    85,    86,
      87,   113,   110,     0,     0,   136,   121,   190,   191,     0,
      50,     0,   210,     0,     0,     0,     0,     0,     0,     0,
     112,   114,     0,   117,     0,   133,   159,   209,     0,     0,
       0,   108,     0,   120,   111,   115,     0,   118,   123,     0,
     132,   134,     0,   131,     0,   119,     0,     0,     0,   122,
     124,     0,   133,   109,     0,     0,   125
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -354,  -354,  -354,  -354,   335,  -354,  -354,  -354,  -354,  -354,
    -354,   311,  -354,  -354,  -354,   205,  -354,   115,  -354,  -354,
    -354,   258,   213,   215,  -354,  -354,  -354,  -354,  -354,  -354,
     126,  -133,   -17,   -54,  -354,  -354,  -152,    -3,  -354,   316,
     -28,   -12,   -94,  -354,  -149,    27,  -276,  -290,  -354,  -354,
    -155,  -354,  -354,  -354,  -354,  -354,  -354,  -354,    -9,  -354,
     -10,  -354,  -354,  -354,  -354,  -354,     2,  -354,  -286,   -32,
    -354,  -353,  -354,  -354,  -354,   387,   -49,  -354,  -354,    12,
    -354,   114,   112,   121,   129,   120,   -64,   -86,  -106,   -71,
    -354,   -65,   -37,     3,    66,    15,    79,    97,   128,   366,
    -354,  -354,   206,  -144,  -354,  -354,   239,   434,    72,   501,
    -354,  -354,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    17,    18,    22,    30,
      31,    32,    33,    34,    35,   140,   141,   142,    50,    91,
      36,    57,    58,    59,    37,    38,    60,    53,   226,   290,
     280,   281,    92,    40,    41,    42,    43,    44,    45,    93,
      94,    95,    96,    97,    98,    99,   346,   100,   101,   102,
     103,   104,   105,   348,   106,   352,   369,   370,   371,   372,
     373,   107,   349,   108,   109,   350,   247,   248,   163,   389,
     390,   249,   110,   111,   112,   237,   165,   114,   214,   166,
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
     113,   199,   246,   113,    39,   227,   241,   253,   245,    61,
     146,   347,   115,    19,    39,   115,   188,   192,   354,   219,
     148,     2,   391,   220,   133,   113,   271,   272,   137,    10,
      -4,     1,    10,     2,   138,     9,   273,   115,    15,    23,
      24,    25,   113,    26,    27,   143,   113,    28,   144,   391,
       3,    13,   116,   145,   115,   116,   149,    11,   115,   221,
      11,   147,     3,   195,   117,  -105,  -105,   117,   -16,   135,
     136,    10,    16,  -105,    12,    21,   288,   116,    23,    24,
      25,    47,    26,    27,  -106,  -106,    28,    62,   258,   117,
     259,   296,  -106,    46,   116,   254,   255,   256,   116,    11,
     266,   156,   347,    46,   347,   252,   117,   398,   113,   -26,
     117,   347,    49,    29,   317,   347,   397,    51,   399,   240,
     115,    52,   143,   233,   330,   403,    10,   235,   118,   406,
    -247,   118,   331,    23,    24,    25,    55,    26,    27,   196,
      56,    28,   251,    56,   264,   265,   119,  -207,  -207,   119,
     355,   134,    29,   118,    11,   341,   267,   268,   269,   270,
     116,    15,   -15,   144,   282,   322,   323,   324,   145,   151,
     118,   119,   117,   139,   118,  -206,  -206,   120,   274,   275,
     120,   318,   319,   320,   321,   215,   216,   285,   119,   361,
     150,   289,   119,   276,   277,   278,   152,   360,   367,   368,
     315,   316,   120,   325,   326,   153,   154,    29,   157,   246,
     158,   327,   328,   329,   143,   245,   193,    10,   198,   120,
     246,   194,   200,   120,    23,    24,    25,   201,    26,    27,
     217,   218,    28,   149,   196,   222,   118,   224,   230,   231,
      78,   233,   357,   244,   257,    11,   260,   246,   262,   251,
     279,   261,   113,   292,   119,   124,   113,   113,   124,   283,
     263,   135,   137,    10,   115,   297,   298,   299,   115,   115,
      23,    24,    25,   300,    26,    27,   301,   302,   303,   304,
     124,   305,   306,    56,   307,   120,   -54,   308,   334,   335,
     332,    11,   199,   333,   337,   336,   330,   124,    29,   338,
     339,   124,   351,   359,   116,   366,   362,   363,   116,   116,
     364,   365,   -84,   374,   375,   113,   117,   113,   377,   383,
     117,   117,   388,   113,   384,   393,   113,   115,   345,   115,
     392,   395,   401,   356,   394,   115,   396,   113,   115,   402,
     405,    14,    48,   113,   229,   113,   293,   113,   223,   115,
     197,   291,   113,   113,    54,   115,   113,   115,   232,   115,
     386,   385,   387,   124,   115,   115,   379,   116,   115,   116,
     404,   376,   311,   310,   358,   116,     0,     0,   116,   117,
     118,   117,   312,   314,   118,   118,   236,   117,     0,   116,
     117,   313,     0,   381,     0,   116,     0,   116,   119,   116,
       0,   117,   119,   119,   116,   116,     0,   117,   116,   117,
       0,   117,     0,     0,     0,     0,   117,   117,     0,   345,
     117,   356,     0,   400,     0,     0,     0,     0,   381,   120,
       0,     0,   400,   120,   120,     0,     0,     0,     0,     0,
       0,     0,     0,   118,     0,   118,     0,   189,   189,     0,
       0,   118,     0,     0,   118,     0,     0,     0,     0,     0,
       0,   119,     0,   119,   164,   118,     0,   187,     0,   119,
       0,   118,   119,   118,     0,   118,     0,     0,     0,     0,
     118,   118,     0,   119,   118,     0,     0,     0,     0,   119,
       0,   119,   120,   119,   120,     0,     0,     0,   119,   119,
     120,     0,   119,   120,     0,     0,     0,   124,     0,     0,
       0,   124,   124,     0,   120,   190,   190,     0,     0,     0,
     120,     0,   120,     0,   120,   228,   189,   189,   189,   120,
     120,     0,     0,   120,     0,     0,     0,     0,   155,   242,
     243,     0,    64,   131,   132,   250,   187,     0,    67,     0,
       0,    68,    69,     0,    70,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    78,     0,    79,
     124,     0,   124,    52,     0,    80,     0,     0,   124,     0,
     228,   124,   191,   191,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,   190,   190,   190,     0,   124,     0,
     124,   284,   124,     0,     0,   286,   287,   124,   124,    81,
      82,   124,   228,    83,    84,    85,    86,    87,    88,     0,
     295,    89,    90,     0,     0,   189,   189,   189,   189,   189,
     189,   189,     0,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   309,     0,    64,   131,   132,
       0,     0,     0,    67,     0,     0,    68,    69,     0,     0,
       0,   191,   191,   191,     0,     0,     0,     0,     0,     0,
       0,     0,    78,   189,   189,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,   340,     0,     0,     0,     0,
     353,   164,     0,   190,   190,   190,   190,   190,   190,   190,
       0,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,     0,    81,    82,     0,   228,    83,    84,
      85,    86,    87,    88,     0,   189,    64,   131,   132,     0,
       0,     0,    67,     0,     0,    68,    69,     0,     0,     0,
       0,   190,   190,     0,     0,     0,     0,     0,     0,     0,
     378,    78,   380,     0,   382,     0,     0,     0,     0,   159,
     191,   191,   191,   191,   191,   191,   191,     0,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     164,     0,     0,     0,     0,   160,     0,     0,     0,     0,
       0,     0,     0,   190,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    63,     0,   191,   191,
      64,   131,   132,    23,    24,    25,    67,    26,    27,    68,
      69,    28,    70,  -116,  -116,     0,    71,    72,    73,    74,
      75,    76,    77,     0,    11,    78,     0,    79,     0,     0,
     219,    52,  -116,    80,   220,     0,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,     0,     0,
     191,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,     0,     0,    81,    82,     0,
     221,    83,    84,    85,    86,    87,    88,    29,    63,    89,
      90,     0,    64,   131,   132,    23,    24,    25,    67,    26,
      27,    68,    69,    28,    70,   367,   368,     0,    71,    72,
      73,    74,    75,    76,    77,     0,    11,    78,     0,    79,
       0,     0,     0,    52,     0,    80,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      82,     0,     0,    83,    84,    85,    86,    87,    88,    29,
      63,    89,    90,     0,    64,    65,    66,    23,    24,    25,
      67,    26,    27,    68,    69,    28,    70,     0,     0,     0,
      71,    72,    73,    74,    75,    76,    77,     0,    11,    78,
       0,    79,     0,     0,     0,    52,   -70,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,    83,    84,    85,    86,    87,
      88,    29,    63,    89,    90,     0,    64,   131,   132,    23,
      24,    25,    67,    26,    27,    68,    69,    28,    70,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,     0,
      11,    78,     0,    79,     0,     0,     0,    52,   -70,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,    83,    84,    85,
      86,    87,    88,    29,    63,    89,    90,     0,    64,   131,
     132,    23,    24,    25,    67,    26,    27,    68,    69,    28,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,     0,    11,    78,     0,    79,     0,     0,     0,    52,
     -69,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,     0,    83,
      84,    85,    86,    87,    88,    29,   155,    89,    90,     0,
      64,   131,   132,     0,     0,     0,    67,     0,     0,    68,
      69,     0,    70,     0,     0,     0,   342,    72,    73,    74,
     343,   344,    77,     0,     0,    78,     0,    79,     0,     0,
       0,    52,    10,    80,     0,     0,    64,   131,   132,    23,
      24,    25,    67,    26,    27,    68,    69,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    78,     0,     0,     0,     0,     0,    81,    82,   159,
       0,    83,    84,    85,    86,    87,    88,     0,     0,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,     0,     0,   161,   162,
       0,     0,     0,    81,    82,     0,     0,    83,    84,    85,
      86,    87,    88,    29,    10,     0,     0,     0,    64,   131,
     132,    23,    24,    25,    67,    26,    27,    68,    69,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    64,   131,
     132,     0,    11,    78,    67,  -127,     0,    68,    69,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,   225,
       0,   159,     0,     0,    64,   131,   132,     0,     0,     0,
      67,     0,     0,    68,    69,    81,    82,     0,     0,    83,
      84,    85,    86,    87,    88,    29,     0,   160,     0,    78,
     161,   162,     0,     0,   294,    81,    82,   159,     0,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    64,   131,
     132,     0,     0,     0,    67,     0,     0,    68,    69,     0,
       0,     0,     0,   160,     0,     0,   161,   162,     0,     0,
       0,    81,    82,    78,     0,    83,    84,    85,    86,    87,
      88,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,     0,     0,
     161,   162,     0,     0,     0,    81,    82,     0,     0,    83,
      84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      49,    95,   157,    52,    21,   138,   150,   159,   157,    39,
      64,   301,    49,    16,    31,    52,    81,    82,   304,    34,
      38,     3,   375,    38,    52,    74,    65,    66,    34,     1,
       0,     1,     1,     3,    40,    16,    75,    74,    30,     8,
       9,    10,    91,    12,    13,    62,    95,    16,    32,   402,
      32,     0,    49,    37,    91,    52,    74,    29,    95,    74,
      29,    64,    32,    91,    49,    31,    32,    52,    37,    31,
      32,     1,    86,    39,     2,    36,   220,    74,     8,     9,
      10,    37,    12,    13,    31,    32,    16,    38,    52,    74,
      54,   235,    39,    21,    91,   160,   161,   162,    95,    29,
       4,    74,   392,    31,   394,   159,    91,   393,   157,    39,
      95,   401,    36,    82,   266,   405,   392,    32,   394,   149,
     157,    36,   139,    34,    31,   401,     1,    38,    49,   405,
      38,    52,    39,     8,     9,    10,    30,    12,    13,    30,
      34,    16,   159,    34,    58,    59,    49,    72,    73,    52,
     305,    35,    82,    74,    29,   299,    60,    61,    62,    63,
     157,    30,    37,    32,   194,   271,   272,   273,    37,    32,
      91,    74,   157,    38,    95,    72,    73,    49,    67,    68,
      52,   267,   268,   269,   270,    72,    73,   217,    91,   333,
      38,   221,    95,    69,    70,    71,    38,   330,    18,    19,
     264,   265,    74,   274,   275,    38,    32,    82,    38,   364,
      38,   276,   277,   278,   231,   364,    38,     1,    37,    91,
     375,    38,    32,    95,     8,     9,    10,    32,    12,    13,
      74,    34,    16,    74,    30,    37,   157,    35,    39,    31,
      30,    34,   307,    26,    32,    29,    53,   402,    56,   266,
      39,    55,   301,    39,   157,    49,   305,   306,    52,    37,
      57,    31,    34,     1,   301,    39,    31,    38,   305,   306,
       8,     9,    10,    39,    12,    13,    39,    39,    38,    32,
      74,    31,    39,    34,    39,   157,    34,    39,    35,    35,
      39,    29,   386,    38,    37,    39,    31,    91,    82,    35,
      39,    95,    36,    33,   301,    20,    39,    38,   305,   306,
      38,    38,    20,    39,    32,   364,   301,   366,    39,    33,
     305,   306,    32,   372,    37,    32,   375,   364,   301,   366,
      39,    33,    20,   306,    39,   372,    39,   386,   375,    32,
      39,     6,    31,   392,   139,   394,   231,   396,   135,   386,
      92,   225,   401,   402,    38,   392,   405,   394,   143,   396,
     372,   370,   372,   157,   401,   402,   364,   364,   405,   366,
     402,   359,   260,   259,   308,   372,    -1,    -1,   375,   364,
     301,   366,   261,   263,   305,   306,   147,   372,    -1,   386,
     375,   262,    -1,   366,    -1,   392,    -1,   394,   301,   396,
      -1,   386,   305,   306,   401,   402,    -1,   392,   405,   394,
      -1,   396,    -1,    -1,    -1,    -1,   401,   402,    -1,   392,
     405,   394,    -1,   396,    -1,    -1,    -1,    -1,   401,   301,
      -1,    -1,   405,   305,   306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   364,    -1,   366,    -1,    81,    82,    -1,
      -1,   372,    -1,    -1,   375,    -1,    -1,    -1,    -1,    -1,
      -1,   364,    -1,   366,    77,   386,    -1,    80,    -1,   372,
      -1,   392,   375,   394,    -1,   396,    -1,    -1,    -1,    -1,
     401,   402,    -1,   386,   405,    -1,    -1,    -1,    -1,   392,
      -1,   394,   364,   396,   366,    -1,    -1,    -1,   401,   402,
     372,    -1,   405,   375,    -1,    -1,    -1,   301,    -1,    -1,
      -1,   305,   306,    -1,   386,    81,    82,    -1,    -1,    -1,
     392,    -1,   394,    -1,   396,   138,   160,   161,   162,   401,
     402,    -1,    -1,   405,    -1,    -1,    -1,    -1,     1,   152,
     153,    -1,     5,     6,     7,   158,   159,    -1,    11,    -1,
      -1,    14,    15,    -1,    17,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    -1,    32,
     364,    -1,   366,    36,    -1,    38,    -1,    -1,   372,    -1,
     193,   375,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   386,    -1,   160,   161,   162,    -1,   392,    -1,
     394,   214,   396,    -1,    -1,   218,   219,   401,   402,    72,
      73,   405,   225,    76,    77,    78,    79,    80,    81,    -1,
     233,    84,    85,    -1,    -1,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   258,    -1,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    -1,    14,    15,    -1,    -1,
      -1,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,   307,   308,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,
     303,   304,    -1,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,    -1,    72,    73,    -1,   330,    76,    77,
      78,    79,    80,    81,    -1,   359,     5,     6,     7,    -1,
      -1,    -1,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     363,    30,   365,    -1,   367,    -1,    -1,    -1,    -1,    38,
     259,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     393,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   359,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,    -1,    -1,     1,    -1,   307,   308,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    -1,    32,    -1,    -1,
      34,    36,    37,    38,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
     359,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    72,    73,    -1,
      74,    76,    77,    78,    79,    80,    81,    82,     1,    84,
      85,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    -1,    38,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
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
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,     1,    84,    85,    -1,
       5,     6,     7,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    36,     1,    38,    -1,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    72,    73,    38,
      -1,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    67,    68,
      -1,    -1,    -1,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,     1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,    -1,    29,    30,    11,    32,    -1,    14,    15,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,
      11,    -1,    -1,    14,    15,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    -1,    64,    -1,    30,
      67,    68,    -1,    -1,    35,    72,    73,    38,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,     5,     6,
       7,    -1,    -1,    -1,    11,    -1,    -1,    14,    15,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    67,    68,    -1,    -1,
      -1,    72,    73,    30,    -1,    76,    77,    78,    79,    80,
      81,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      67,    68,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81
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
     113,   199,    38,     1,     5,     6,     7,    11,    14,    15,
      17,    21,    22,    23,    24,    25,    26,    27,    30,    32,
      38,    72,    73,    76,    77,    78,    79,    80,    81,    84,
      85,   106,   119,   126,   127,   128,   129,   130,   131,   132,
     134,   135,   136,   137,   138,   139,   141,   148,   150,   151,
     159,   160,   161,   163,   164,   179,   180,   182,   183,   184,
     185,   186,   187,   188,   189,   192,   194,   196,   197,   198,
     199,     6,     7,   127,    35,    31,    32,    34,    40,    38,
     102,   103,   104,   119,    32,    37,   120,   124,    38,    74,
      38,    32,    38,    38,    32,     1,   132,    38,    38,    38,
      64,    67,    68,   155,   162,   163,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   189,   162,   178,   186,
     194,   196,   178,    38,    38,   127,    30,   108,    37,   129,
      32,    32,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   165,    72,    73,    74,    34,    34,
      38,    74,    37,   109,    35,    36,   115,   118,   162,   102,
      39,    31,   110,    34,   193,    38,   193,   162,   190,   191,
     199,   190,   162,   162,    26,   131,   137,   153,   154,   158,
     162,   119,   120,   123,   178,   178,   178,    32,    52,    54,
      53,    55,    56,    57,    58,    59,     4,    60,    61,    62,
      63,    65,    66,    75,    67,    68,    69,    70,    71,    39,
     117,   118,   199,    37,   162,   199,   162,   162,   190,   199,
     116,   117,    39,   104,    35,   162,   190,    39,    31,    38,
      39,    39,    39,    38,    32,    31,    39,    39,    39,   162,
     168,   169,   170,   171,   172,   173,   173,   123,   174,   174,
     174,   174,   175,   175,   175,   176,   176,   178,   178,   178,
      31,    39,    39,    38,    35,    35,    39,    37,    35,    39,
     162,   190,    21,    25,    26,   132,   133,   134,   140,   149,
     152,    36,   142,   162,   155,   137,   132,   178,   181,    33,
     118,   190,    39,    38,    38,    38,    20,    18,    19,   143,
     144,   145,   146,   147,    39,    32,   166,    39,   162,   153,
     162,   132,   162,    33,    37,   145,   128,   147,    32,   156,
     157,   158,    39,    32,    39,    33,    39,   133,   155,   133,
     132,    20,    32,   133,   156,    39,   133
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
     167,   167,   168,   168,   169,   169,   170,   170,   171,   171,
     172,   172,   172,   173,   173,   173,   173,   173,   173,   174,
     174,   174,   174,   175,   175,   175,   176,   176,   176,   176,
     177,   177,   178,   178,   178,   178,   178,   179,   180,   181,
     181,   181,   182,   183,   184,   184,   184,   184,   185,   185,
     185,   186,   186,   187,   187,   188,   188,   188,   188,   188,
     188,   188,   189,   190,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   197,
     197,   197,   197,   197,   198,   198,   198,   199
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
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       4,     4,     1,     1,     2,     2,     1,     2,     2,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     4,     6,
       6,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     5,     1,     0,     1,     3,     3,     3,     3,
       2,     4,     4,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 139 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						 strcpy((yyval.attr)->place,(yyvsp[0].sval));
						 strcpy((yyval.attr)->type,(yyvsp[-1].type));
						 p=Insert((yyvsp[0].sval),(yyval.attr)->type);}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						 strcpy((yyval.attr)->place,(yyvsp[0].sval));
						 strcpy((yyval.attr)->type,(yyvsp[-3].type));
						 p=Insert((yyvsp[0].sval),(yyval.attr)->type);}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=strdup((yyval.sval));}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=strdup((yyvsp[-2].sval));}
#line 2163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.sval)=strdup((yyvsp[0].sval));}
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].type));}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].type));}
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 256 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].type));}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 257 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].type));}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.type)=strdup((yyvsp[0].sval));}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 282 "parser.y" /* yacc.c:1646  */
    {printList((yyvsp[0].attr)->code);}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							(yyval.attr)->code=append((yyvsp[-1].attr)->code,(yyvsp[0].attr)->code);}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 306 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 307 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 331 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[-1].attr);}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 334 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 337 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 377 "parser.y" /* yacc.c:1646  */
    { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
										//	printf("%s %s",begin,end);	
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
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 438 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 439 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 442 "parser.y" /* yacc.c:1646  */
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
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 472 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 477 "parser.y" /* yacc.c:1646  */
    {flag1=0;}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 478 "parser.y" /* yacc.c:1646  */
    {flag1=1;}
#line 2415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 479 "parser.y" /* yacc.c:1646  */
    {flag1=2;}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 480 "parser.y" /* yacc.c:1646  */
    {flag1=3;}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 481 "parser.y" /* yacc.c:1646  */
    {flag1=4;}
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 482 "parser.y" /* yacc.c:1646  */
    {flag1=5;}
#line 2439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 483 "parser.y" /* yacc.c:1646  */
    {flag1=6;}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 484 "parser.y" /* yacc.c:1646  */
    {flag1=7;}
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 485 "parser.y" /* yacc.c:1646  */
    {flag1=8;}
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 486 "parser.y" /* yacc.c:1646  */
    {flag1=9;}
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 487 "parser.y" /* yacc.c:1646  */
    {flag1=10;}
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 488 "parser.y" /* yacc.c:1646  */
    {flag1=11;}
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 491 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 495 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 496 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s || %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 504 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 505 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s && %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 513 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 514 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s | %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 522 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 523 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s ^ %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 531 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 532 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s & %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 540 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 541 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s == %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 547 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s != %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 555 "parser.y" /* yacc.c:1646  */
    {(yyval.attr) = (yyvsp[0].attr);}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 556 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s < %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 2608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 562 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s > %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 568 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s <= %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 574 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
					strcpy((yyval.attr)->place, tempVar());
					(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
					sprintf(t,"%s = %s >= %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
					(yyval.attr)->code=append((yyval.attr)->code,newList(t));}
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 584 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 585 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s & %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 591 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s >> %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 597 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s >>> %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 606 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 607 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s + %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 613 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s - %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 620 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 621 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s * %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 627 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s / %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 633 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(Attr *)malloc(sizeof(Attr));
							strcpy((yyval.attr)->place,tempVar());
							(yyval.attr)->code=append((yyvsp[-2].attr)->code,(yyvsp[0].attr)->code);
							sprintf(t,"%s = %s %% %s",(yyval.attr)->place,(yyvsp[-2].attr)->place,(yyvsp[0].attr)->place);
							(yyval.attr)->code=append((yyval.attr)->code,newList(t));
							}
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 645 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 646 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 647 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							strcpy(temp,tempVar());
							sprintf(t,"%s = + %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 654 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							strcpy(temp,tempVar());
							sprintf(t,"%s = - %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 664 "parser.y" /* yacc.c:1646  */
    {sprintf(t,"%s = %s + 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 2789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 670 "parser.y" /* yacc.c:1646  */
    {sprintf(t,"%s = %s - 1",(yyvsp[0].attr)->place,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 676 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 677 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							strcpy(temp,tempVar());
							sprintf(t,"%s = ! %s",temp,(yyvsp[0].attr)->place);
							(yyvsp[0].attr)->code=append((yyvsp[0].attr)->code,newList(t));
							sprintf((yyvsp[0].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[0].attr);
							}
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 687 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							sprintf(temp,"%s",tempVar());
							sprintf(t,"%s = %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,"%s = %s - 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 698 "parser.y" /* yacc.c:1646  */
    {char temp[10];
							sprintf(temp,"%s",tempVar());
							sprintf(t,"%s = %s",temp,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf(t,"%s = %s + 1",(yyvsp[-1].attr)->place,(yyvsp[-1].attr)->place);
							(yyvsp[-1].attr)->code=append((yyvsp[-1].attr)->code,newList(t));
							sprintf((yyvsp[-1].attr)->place,"%s",temp);
							(yyval.attr)=(yyvsp[-1].attr);
							}
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 710 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 760 "parser.y" /* yacc.c:1646  */
    {pushStr(lexeme,(yyvsp[0].sval));}
#line 2856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 764 "parser.y" /* yacc.c:1646  */
    {(yyval.attr)=(yyvsp[0].attr);}
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 769 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%f",(yyvsp[0].fval));pushStr(lexeme,ch);}
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 770 "parser.y" /* yacc.c:1646  */
    {pushStr(lexeme,(yyvsp[0].sval));}
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 771 "parser.y" /* yacc.c:1646  */
    {pushStr(lexeme,(yyvsp[0].sval));}
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 777 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%d",(yyvsp[0].ival));pushStr(lexeme,ch);}
#line 2886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 778 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%d",(yyvsp[0].ival));pushStr(lexeme,ch);}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 779 "parser.y" /* yacc.c:1646  */
    {char ch[20];sprintf(ch,"%d",(yyvsp[0].ival));pushStr(lexeme,ch);}
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 782 "parser.y" /* yacc.c:1646  */
    {SymtabEntry *tempo=look_up((yyvsp[0].sval));
					if(tempo!=NULL){
						(yyval.attr)=(Attr *)malloc(sizeof(Attr));
						strcpy((yyval.attr)->place,(yyvsp[0].sval));
						strcpy((yyval.attr)->type,tempo->type);
						(yyval.attr)->code=NULL;
						}
					else
						yyerrok;}
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2916 "y.tab.c" /* yacc.c:1646  */
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
#line 792 "parser.y" /* yacc.c:1906  */

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
	//	printf("%s,%s\n",temp->lexeme,temp->type);
		temp=temp->next;
	}
	while(!isEmpty(attr_stack))
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
