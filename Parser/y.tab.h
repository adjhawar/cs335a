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
    COMMENT = 263,
    BOOL = 264,
    BYTE = 265,
    CHAR = 266,
    T = 267,
    FLOAT = 268,
    INT = 269,
    F = 270,
    N = 271,
    VOID = 272,
    BREAK = 273,
    CASE = 274,
    DEFAULT = 275,
    ELSE = 276,
    IF = 277,
    SWITCH = 278,
    CONT = 279,
    DO = 280,
    FOR = 281,
    WHILE = 282,
    RETURN = 283,
    CONST = 284,
    CID = 285,
    ID = 286,
    SEP = 287,
    TRM = 288,
    COLON = 289,
    ARRAY_S = 290,
    ARRAY_E = 291,
    BLOCK_S = 292,
    BLOCK_E = 293,
    PAREN_S = 294,
    PAREN_E = 295,
    OP_ASS = 296,
    OP_ADD_ASS = 297,
    OP_SUB_ASS = 298,
    OP_DIV_ASS = 299,
    OP_MUL_ASS = 300,
    OP_MOD_ASS = 301,
    OP_LSH_ASS = 302,
    OP_RSH_ASS = 303,
    OP_AND_ASS = 304,
    OP_OR_ASS = 305,
    OP_XOR_ASS = 306,
    OP_ZRSH_ASS = 307,
    OP_CON_Q = 308,
    OP_CON_AND = 309,
    OP_CON_OR = 310,
    OP_OR = 311,
    OP_XOR = 312,
    OP_AND = 313,
    OP_EQ = 314,
    OP_NEQ = 315,
    OP_GRE = 316,
    OP_LES = 317,
    OP_GEQ = 318,
    OP_LEQ = 319,
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
    ERROR = 337,
    IGN = 338,
    PRINT = 339,
    SCAN = 340,
    OP_NEG = 341,
    STRING = 342,
    EXTENDS = 343
  };
#endif
/* Tokens.  */
#define CLASS 258
#define INSTANCEOF 259
#define NEW 260
#define SUPER 261
#define THIS 262
#define COMMENT 263
#define BOOL 264
#define BYTE 265
#define CHAR 266
#define T 267
#define FLOAT 268
#define INT 269
#define F 270
#define N 271
#define VOID 272
#define BREAK 273
#define CASE 274
#define DEFAULT 275
#define ELSE 276
#define IF 277
#define SWITCH 278
#define CONT 279
#define DO 280
#define FOR 281
#define WHILE 282
#define RETURN 283
#define CONST 284
#define CID 285
#define ID 286
#define SEP 287
#define TRM 288
#define COLON 289
#define ARRAY_S 290
#define ARRAY_E 291
#define BLOCK_S 292
#define BLOCK_E 293
#define PAREN_S 294
#define PAREN_E 295
#define OP_ASS 296
#define OP_ADD_ASS 297
#define OP_SUB_ASS 298
#define OP_DIV_ASS 299
#define OP_MUL_ASS 300
#define OP_MOD_ASS 301
#define OP_LSH_ASS 302
#define OP_RSH_ASS 303
#define OP_AND_ASS 304
#define OP_OR_ASS 305
#define OP_XOR_ASS 306
#define OP_ZRSH_ASS 307
#define OP_CON_Q 308
#define OP_CON_AND 309
#define OP_CON_OR 310
#define OP_OR 311
#define OP_XOR 312
#define OP_AND 313
#define OP_EQ 314
#define OP_NEQ 315
#define OP_GRE 316
#define OP_LES 317
#define OP_GEQ 318
#define OP_LEQ 319
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
#define ERROR 337
#define IGN 338
#define PRINT 339
#define SCAN 340
#define OP_NEG 341
#define STRING 342
#define EXTENDS 343

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 401 "parser.y" /* yacc.c:1909  */

	int ival;
	char *sval;
	float fval;

#line 236 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
