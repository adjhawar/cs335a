/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 48 "parser.y" /* yacc.c:1909  */

	int ival;
	char *sval;
	float fval;
	char *type;
        struct Attr *attr;

#line 234 "y.tab.h" /* yacc.c:1909  */
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
