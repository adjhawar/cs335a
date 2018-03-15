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
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(char *s);
int maxsize = 1000;
struct Stack{
    int size;
    int* array;
};

struct StackStr{
	int size;
	char **array;
};
void printStack(struct StackStr* str3);
void printCode();
struct Stack* createIntStack(){
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->size = -1;
	stack->array = (int*) malloc(maxsize * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack){
   return stack->size == maxsize - 1; 
}
 
int isEmpty(struct Stack* stack){
   return stack->size == -1;
}

void push(struct Stack* stack, int item){
	//printf("%d\n",stack->size);
    stack->array[++stack->size] = item;
}

int pop(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->size--];
}
 
struct StackStr* createCharStack(){
	struct StackStr* stack= (struct StackStr*)malloc(sizeof(struct StackStr));
	stack->size = -1;
	stack->array = (char**) malloc(maxsize * sizeof(char *));
        for(int i=0;i< maxsize; i++)
        {
            stack->array[i]=(char*)malloc(50 * sizeof(char ));
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
    strcpy(stack->array[++stack->size],item);
}

char* popStr(struct StackStr* stack){
    if (isEmptyStr(stack))
        return NULL;
    return stack->array[stack->size--];
}

struct Stack* s1;
struct Stack* s2;
struct StackStr* lexeme;
struct StackStr* str1 ;
struct StackStr* str2;

char *find1(int k){
	char *str;
	str=(char *)malloc(30*sizeof(char));
	switch(k){
	case 1: strcpy(str, "compilation_unit"); break;   
	case 2: strcpy(str, "type_declarations_e"); break;
	case 3: strcpy(str, "type_declarations"); break;
	case 4: strcpy(str, "type_declaration"); break;
	case 5: strcpy(str, "class_declaration"); break;
	case 6: strcpy(str, "super_e"); break;
	case 7: strcpy(str, "supers"); break;
	case 8: strcpy(str, "class_body"); break;
	case 9: strcpy(str, "class_body_decl_e"); break;
	case 10: strcpy(str, "class_body_decls"); break;
	case 11: strcpy(str, "class_body_decl"); break;
	case 12: strcpy(str, "class_mem_decl"); break;
	case 13: strcpy(str, "const_decl"); break;
	case 14: strcpy(str, "const_declarator"); break;
	case 15: strcpy(str, "formal_para_list_e"); break;
	case 16: strcpy(str, "formal_para_list"); break;
	case 17: strcpy(str, "formal_para"); break;
	case 18: strcpy(str, "const_body"); break;
	case 19: strcpy(str, "explicit_const_invo"); break;
	case 20: strcpy(str, "field_decl"); break;
	case 21: strcpy(str, "var_declarators"); break;
	case 22: strcpy(str, "var_declarator"); break;
	case 23: strcpy(str, "var_decl_id"); break;
	case 24: strcpy(str, "method_decl"); break;
	case 25: strcpy(str, "method_header"); break;
	case 26: strcpy(str, "method_declarator"); break;
	case 27: strcpy(str, "method_body"); break;
	case 28: strcpy(str, "array_init"); break;
	case 29: strcpy(str, "var_init_e"); break;
	case 30: strcpy(str, "var_inits"); break;
	case 31: strcpy(str, "var_init"); break;
	case 32: strcpy(str, "type"); break;
	case 33: strcpy(str, "primitive_type"); break;
	case 34: strcpy(str, "numeric_type"); break;
	case 35: strcpy(str, "integer_type"); break;
	case 36: strcpy(str, "reference_type"); break;
	case 37: strcpy(str, "class_type"); break;
	case 38: strcpy(str, "array_type"); break;
	case 39: strcpy(str, "block"); break;
	case 40: strcpy(str, "bl_statements_e"); break;
	case 41: strcpy(str, "bl_statements"); break;
	case 42: strcpy(str, "block_statement"); break;
	case 43: strcpy(str, "loc_var_dec_st"); break;
	case 44: strcpy(str, "loc_var_dec"); break;
	case 45: strcpy(str, "statement"); break;
	case 46: strcpy(str, "st_no_short_if"); break;
        case 47: strcpy(str, "st_wo_tsub"); break;
	case 48: strcpy(str, "empty_st"); break;
	case 49: strcpy(str, "expr_st"); break;
	case 50: strcpy(str, "st_expr"); break;
	case 51: strcpy(str, "if_then_st"); break;
	case 52: strcpy(str, "if_then_else_st"); break;
	case 53: strcpy(str, "if_then_else_no_short_if_st"); break;
	case 54: strcpy(str, "switch_st"); break;
	case 55: strcpy(str, "switch_block"); break;
	case 56: strcpy(str, "switch_block_st_gr_e"); break;
	case 57: strcpy(str, "switch_block_st_grps"); break;
	case 58: strcpy(str, "switch_block_st_grp"); break;
	case 59: strcpy(str, "switch_labels"); break;
	case 60: strcpy(str, "switch_label"); break;
	case 61: strcpy(str, "while_st"); break;
	case 62: strcpy(str, "while_st_no_short_if"); break;
	case 63: strcpy(str, "do_st"); break;
	case 64: strcpy(str, "for_st"); break;
	case 65: strcpy(str, "for_st_no_short_if"); break;
	case 66: strcpy(str, "for_init_e"); break;
	case 67: strcpy(str, "for_init"); break;
	case 68: strcpy(str, "expr_e"); break;
	case 69: strcpy(str, "for_update_e"); break;
	case 70: strcpy(str, "for_update"); break;
	case 71: strcpy(str, "st_expr_list"); break;
	case 72: strcpy(str, "break_st"); break;
	case 73: strcpy(str, "continue_st"); break;
	case 74: strcpy(str, "return_st"); break;
	case 75: strcpy(str, "expr"); break;
	case 76: strcpy(str, "assgn"); break;
	case 77: strcpy(str, "lhs"); break;
	case 78: strcpy(str, "assgn_op"); break;
	case 79: strcpy(str, "cond_expr"); break;
	case 80: strcpy(str, "cond_or_expr"); break;
	case 81: strcpy(str, "cond__and_expr"); break;
	case 82: strcpy(str, "incl_or_expr"); break;
	case 83: strcpy(str, "excl_or_expr"); break;
	case 84: strcpy(str, "and_expr"); break;
	case 85: strcpy(str, "equality_expr"); break;
	case 86: strcpy(str, "rel_expr"); break;
	case 87: strcpy(str, "shift_expr"); break;
	case 88: strcpy(str, "add_expr"); break;
	case 89: strcpy(str, "mul_expr"); break;
	case 90: strcpy(str, "cast_expr"); break;
	case 91: strcpy(str, "unary_expr"); break;
	case 92: strcpy(str, "preinc_expr"); break;
	case 93: strcpy(str, "predec_expr"); break;
	case 94: strcpy(str, "unary_expr_not_plus_minus"); break;
	case 95: strcpy(str, "postdec_expr"); break;
	case 96: strcpy(str, "postinc_expr"); break;
	case 97: strcpy(str, "postfix_expr"); break;
	case 98: strcpy(str, "method_invo"); break;
	case 99: strcpy(str, "field_access"); break;
	case 100: strcpy(str, "primary"); break;
	case 101: strcpy(str, "primary_no_new_array"); break;
	case 102: strcpy(str, "object_expr"); break;
	case 103: strcpy(str, "arg_list_e"); break;
	case 104: strcpy(str, "argument_list"); break;
	case 105: strcpy(str, "array_creat_expr"); break;
	case 106: strcpy(str, "dim_expr"); break;
	case 107: strcpy(str, "array_access"); break;
	case 108: strcpy(str, "type_name"); break;
	case 109: strcpy(str, "name"); break;
	case 110: strcpy(str, "literal"); break;
	case 111: strcpy(str, "int_literal");	 break;
	}
	return str;
}

char *find2(int k){
	char *str;
	str=(char *)malloc(100*sizeof(char));
	switch(k){
	case 0 : strcpy(str, ""); break;
	case 1 : strcpy(str, "type_declarations_e"); break;
	case 2 : strcpy(str, "type_declarations"); break;
	case 3 : strcpy(str, "type_declaration"); break;
	case 4 : strcpy(str, "type_declarations type_declaration"); break;
	case 5 : strcpy(str, "class_declaration"); break;
	case 6 : strcpy(str, "TRM"); break;
	case 7 : strcpy(str, "CLASS CID super_e class_body"); break;
	case 8 : strcpy(str, "supers"); break;
	case 9 : strcpy(str, "EXTENDS class_type"); break;
	case 10 : strcpy(str, "BLOCK_S class_body_decl_e BLOCK_E"); break;
	case 11 : strcpy(str, "class_body_decls"); break;
	case 12 : strcpy(str, "class_body_decl"); break;
	case 13 : strcpy(str, "class_body_decls class_body_decl"); break;
	case 14 : strcpy(str, "class_mem_decl"); break;
	case 15 : strcpy(str, "const_decl"); break;
	case 16 : strcpy(str, "field_decl"); break;
	case 17 : strcpy(str, "method_decl"); break;
	case 18 : strcpy(str, "const_declarator const_body"); break;
	case 19 : strcpy(str, "type_name PAREN_S formal_para_list_e PAREN_E"); break;
	case 20 : strcpy(str, "formal_para_list"); break;
	case 21 : strcpy(str, "formal_para"); break;
	case 22 : strcpy(str, "formal_para_list SEP formal_para"); break;
	case 23 : strcpy(str, "type var_decl_id"); break;
	case 24 : strcpy(str, "BLOCK_S explicit_const_invo bl_statements_e BLOCK_E"); break;
	case 25 : strcpy(str, "BLOCK_S bl_statements_e BLOCK_E"); break;
	case 26 : strcpy(str, "THIS PAREN_S arg_list_e PAREN_E"); break;
	case 27 : strcpy(str, "SUPER PAREN_S arg_list_e PAREN_E"); break;
	case 28 : strcpy(str, "type var_declarators  TRM"); break;
	case 29 : strcpy(str, "var_declarator"); break;
	case 30 : strcpy(str, "var_declarators SEP var_declarator"); break;
	case 31 : strcpy(str, "var_decl_id"); break;
	case 32 : strcpy(str, "var_decl_id OP_ASS var_init"); break;
	case 33 : strcpy(str, "ID"); break;
	case 34 : strcpy(str, "var_decl_id ARRAY_S ARRAY_E"); break;
	case 35 : strcpy(str, "method_header method_body"); break;
	case 36 : strcpy(str, "type method_declarator"); break;
	case 37 : strcpy(str, "ID PAREN_S formal_para_list_e PAREN_E"); break;
	case 38 : strcpy(str, "block"); break;
	case 39 : strcpy(str, "TRM"); break;
	case 40 : strcpy(str, "BLOCK_S var_init_e BLOCK_E"); break;
	case 41 : strcpy(str, "var_inits"); break;
	case 42 : strcpy(str, "var_init"); break;
	case 43 : strcpy(str, "var_inits SEP var_init"); break;
	case 44 : strcpy(str, "expr"); break;
	case 45 : strcpy(str, "array_init"); break;
	case 46 : strcpy(str, "primitive_type"); break;
	case 47 : strcpy(str, "reference_type"); break;
	case 48 : strcpy(str, "VOID"); break;
	case 49 : strcpy(str, "numeric_type"); break;
	case 50 : strcpy(str, "BOOL"); break;
	case 51 : strcpy(str, "integer_type"); break;
	case 52 : strcpy(str, "FLOAT"); break;
	case 53 : strcpy(str, "BYTE"); break;
	case 54 : strcpy(str, "CHAR"); break;
	case 55 : strcpy(str, "INT"); break;
	case 56 : strcpy(str, "class_type"); break;
	case 57 : strcpy(str, "array_type"); break;
	case 58 : strcpy(str, "type_name"); break;
	case 59 : strcpy(str, "type ARRAY_S ARRAY_E"); break;
	case 60 : strcpy(str, "BLOCK_S bl_statements_e BLOCK_E"); break;
	case 61 : strcpy(str, "bl_statements"); break;
	case 62 : strcpy(str, "block_statement"); break;
	case 63 : strcpy(str, "bl_statements block_statement"); break;
	case 64 : strcpy(str, "loc_var_dec_st"); break;
	case 65 : strcpy(str, "statement"); break;
	case 66 : strcpy(str, "loc_var_dec TRM"); break;
	case 67 : strcpy(str, "type var_declarators"); break;
	case 68 : strcpy(str, "st_wo_tsub"); break;
	case 69 : strcpy(str, "if_then_st"); break;
	case 70 : strcpy(str, "if_then_else_st"); break;
	case 71 : strcpy(str, "while_st"); break;
	case 72 : strcpy(str, "for_st"); break;
	case 73 : strcpy(str, "st_wo_tsub"); break;
	case 74 : strcpy(str, "if_then_else_no_short_if_st"); break;
	case 75 : strcpy(str, "while_st_no_short_if"); break;
	case 76 : strcpy(str, "for_st_no_short_if"); break;
	case 77 : strcpy(str, "block"); break;
	case 78 : strcpy(str, "empty_st"); break;
	case 79 : strcpy(str, "expr_st"); break;
	case 80 : strcpy(str, "switch_st"); break;
	case 81 : strcpy(str, "do_st"); break;
	case 82 : strcpy(str, "break_st"); break;
	case 83 : strcpy(str, "continue_st"); break;
	case 84 : strcpy(str, "return_st"); break;
	case 85 : strcpy(str, "TRM"); break;
	case 86 : strcpy(str, "st_expr TRM"); break;
	case 87 : strcpy(str, "assgn"); break;
	case 88 : strcpy(str, "preinc_expr"); break;
	case 89 : strcpy(str, "postinc_expr"); break;
	case 90 : strcpy(str, "predec_expr"); break;
	case 91 : strcpy(str, "postdec_expr"); break;
	case 92 : strcpy(str, "method_invo"); break;
	case 93 : strcpy(str, "object_expr"); break;
	case 94 : strcpy(str, "IF PAREN_S expr PAREN_E statement"); break;
	case 95 : strcpy(str, "IF PAREN_S expr PAREN_E st_no_short_if ELSE statement"); break;
	case 96 : strcpy(str, "IF PAREN_S expr PAREN_E st_no_short_if ELSE st_no_short_if"); break;
	case 97 : strcpy(str, "SWITCH PAREN_S expr PAREN_E switch_block"); break;
	case 98 : strcpy(str, "BLOCK_S switch_block_st_gr_e BLOCK_E"); break;
	case 99 : strcpy(str, "switch_block_st_grps"); break;
	case 100 : strcpy(str, "switch_block_st_grp"); break;
	case 101 : strcpy(str, "switch_block_st_grps switch_block_st_grp"); break;
	case 102 : strcpy(str, "switch_labels bl_statements"); break;
	case 103 : strcpy(str, "switch_label"); break;
	case 104 : strcpy(str, "switch_labels switch_label"); break;
	case 105 : strcpy(str, "CASE expr COLON"); break;
	case 106 : strcpy(str, "DEFAULT COLON"); break;
	case 107 : strcpy(str, "WHILE PAREN_S expr PAREN_E statement"); break;
	case 108 : strcpy(str, "WHILE PAREN_S expr PAREN_E st_no_short_if"); break;
	case 109 : strcpy(str, "DO statement WHILE PAREN_S expr PAREN_E  TRM"); break;
	case 110 : strcpy(str, "FOR PAREN_S for_init_e  TRM expr_e  TRM for_update_e  TRM PAREN_E statement"); break;
	case 111 : strcpy(str, "FOR PAREN_S for_init_e  TRM expr_e  TRM for_update_e  TRM PAREN_E st_no_short_if"); break;
	case 112 : strcpy(str, "for_init"); break;
	case 113 : strcpy(str, "st_expr_list"); break;
	case 114 : strcpy(str, "loc_var_dec"); break;
	case 115 : strcpy(str, "expr"); break;
	case 116 : strcpy(str, "for_update"); break;
	case 117 : strcpy(str, "st_expr_list"); break;
	case 118 : strcpy(str, "st_expr"); break;
	case 119 : strcpy(str, "st_expr_list SEP st_expr"); break;
	case 120 : strcpy(str, "BREAK TRM"); break;
	case 121 : strcpy(str, "CONT TRM"); break;
	case 122 : strcpy(str, "RETURN expr_e  TRM"); break;
	case 123 : strcpy(str, "cond_expr"); break;
	case 124 : strcpy(str, "assgn"); break;
	case 125 : strcpy(str, "lhs assgn_op expr"); break;
	case 126 : strcpy(str, "name"); break;
	case 127 : strcpy(str, "field_access"); break;
	case 128 : strcpy(str, "array_access"); break;
	case 129 : strcpy(str, "OP_ASS"); break;
	case 130 : strcpy(str, "OP_MUL_ASS"); break;
	case 131 : strcpy(str, "OP_DIV_ASS"); break;
	case 132 : strcpy(str, "OP_MOD_ASS"); break;
	case 133 : strcpy(str, "OP_ADD_ASS"); break;
	case 134 : strcpy(str, "OP_SUB_ASS"); break;
	case 135 : strcpy(str, "OP_LSH_ASS"); break;
	case 136 : strcpy(str, "OP_RSH_ASS"); break;
	case 137 : strcpy(str, "OP_ZRSH_ASS"); break;
	case 138 : strcpy(str, "OP_AND_ASS"); break;
	case 139 : strcpy(str, "OP_XOR_ASS"); break;
	case 140 : strcpy(str, "OP_OR_ASS"); break;
	case 141 : strcpy(str, "cond_or_expr"); break;
	case 142 : strcpy(str, "cond_or_expr OP_CON_Q expr COLON cond_expr"); break;
	case 143 : strcpy(str, "cond_and_expr"); break;
	case 144 : strcpy(str, "cond_or_expr OP_CON_OR cond_and_expr"); break;
	case 145 : strcpy(str, "incl_or_expr"); break;
	case 146 : strcpy(str, "cond_and_expr OP_CON_AND incl_or_expr"); break;
	case 147 : strcpy(str, "excl_or_expr"); break;
	case 148 : strcpy(str, "and_expr"); break;
	case 149 : strcpy(str, "excl_or_expr OP_XOR and_expr"); break;
	case 150 : strcpy(str, "equality_expr"); break;
	case 151 : strcpy(str, "and_expr OP_AND equality_expr"); break;
	case 152 : strcpy(str, "rel_expr"); break;
	case 153 : strcpy(str, "equality_expr OP_EQ rel_expr"); break;
	case 154 : strcpy(str, "equality_expr OP_NEQ rel_expr"); break;
	case 155 : strcpy(str, "shift_expr"); break;
	case 156 : strcpy(str, "rel_expr OP_LES shift_expr"); break;
	case 157 : strcpy(str, "rel_expr OP_GRE shift_expr"); break;
	case 158 : strcpy(str, "rel_expr OP_LEQ shift_expr"); break;
	case 159 : strcpy(str, "rel_expr OP_GEQ shift_expr"); break;
	case 160 : strcpy(str, "rel_expr INSTANCEOF reference_type"); break;
	case 161 : strcpy(str, "add_expr"); break;
	case 162 : strcpy(str, "shift_expr OP_LSH add_expr"); break;
	case 163 : strcpy(str, "shift_expr OP_RSH add_expr"); break;
	case 164 : strcpy(str, "shift_expr OP_ZRSH add_expr"); break;
	case 165 : strcpy(str, "mul_expr"); break;
	case 166 : strcpy(str, "add_expr OP_ADD mul_expr"); break;
	case 167 : strcpy(str, "add_expr OP_SUB mul_expr"); break;
	case 168 : strcpy(str, "unary_expr"); break;
	case 169 : strcpy(str, "mul_expr OP_MUL unary_expr"); break;
	case 170 : strcpy(str, "mul_expr OP_DIV unary_expr"); break;
	case 171 : strcpy(str, "mul_expr OP_MOD unary_expr"); break;
	case 172 : strcpy(str, "PAREN_S primitive_type PAREN_E unary_expr"); break;
	case 173 : strcpy(str, "PAREN_S reference_type PAREN_E unary_expr_not_plus_minus"); break;
	case 174 : strcpy(str, "preinc_expr"); break;
	case 175 : strcpy(str, "predec_expr"); break;
	case 176 : strcpy(str, "OP_ADD unary_expr"); break;
	case 177 : strcpy(str, "OP_SUB unary_expr"); break;
	case 178 : strcpy(str, "unary_expr_not_plus_minus"); break;
	case 179 : strcpy(str, "OP_INC unary_expr"); break;
	case 180 : strcpy(str, "OP_DEC unary_expr"); break;
	case 181 : strcpy(str, "postfix_expr"); break;
	case 182 : strcpy(str, "OP_NEG unary_expr"); break;
	case 183 : strcpy(str, "cast_expr"); break;
	case 184 : strcpy(str, "postfix_expr OP_DEC"); break;
	case 185 : strcpy(str, "postfix_expr OP_INC"); break;
	case 186 : strcpy(str, "primary"); break;
	case 187 : strcpy(str, "name"); break;
	case 188 : strcpy(str, "postinc_expr"); break;
	case 189 : strcpy(str, "postdec_expr"); break;
	case 190 : strcpy(str, "name PAREN_S arg_list_e PAREN_E "); break;
	case 191 : strcpy(str, "primary OP_DOT ID PAREN_S arg_list_e PAREN_E"); break;
	case 192 : strcpy(str, "SUPER OP_DOT ID PAREN_S arg_list_e PAREN_E"); break;
	case 193 : strcpy(str, "primary OP_DOT ID"); break;
	case 194 : strcpy(str, "SUPER OP_DOT ID"); break;
	case 195 : strcpy(str, "primary_no_new_array"); break;
	case 196 : strcpy(str, "array_creat_expr"); break;
	case 197 : strcpy(str, "literal"); break;
	case 198 : strcpy(str, "THIS"); break;
	case 199 : strcpy(str, "PAREN_S expr PAREN_E"); break;
	case 200 : strcpy(str, "object_expr"); break;
	case 201 : strcpy(str, "field_access"); break;
	case 202 : strcpy(str, "method_invo"); break;
	case 203 : strcpy(str, "array_access"); break;
	case 204 : strcpy(str, "NEW class_type PAREN_S arg_list_e PAREN_E"); break;
	case 205 : strcpy(str, "argument_list"); break;
	case 206 : strcpy(str, "expr"); break;
	case 207 : strcpy(str, "argument_list SEP expr"); break;
	case 208 : strcpy(str, "NEW primitive_type dim_expr"); break;
	case 209 : strcpy(str, "NEW class_type dim_expr"); break;
	case 210 : strcpy(str, "ARRAY_S expr ARRAY_E"); break;
	case 211 : strcpy(str, "ARRAY_S ARRAY_E"); break;
	case 212 : strcpy(str, "name ARRAY_S expr ARRAY_E"); break;
	case 213 : strcpy(str, "primary_no_new_array ARRAY_S expr ARRAY_E"); break;
	case 214 : strcpy(str, "CID"); break;
	case 215 : strcpy(str, "ID"); break;
	case 216 : strcpy(str, "name OP_DOT ID"); break;
	case 217 : strcpy(str, "int_literal"); break;
	case 218 : strcpy(str, "FLOAT_LIT"); break;
	case 219 : strcpy(str, "CHAR_LIT"); break;
	case 220 : strcpy(str, "STR_LIT"); break;
	case 221 : strcpy(str, "T"); break;
	case 222 : strcpy(str, "F"); break;
	case 223 : strcpy(str, "N"); break;
	case 224 : strcpy(str, "INT_LIT_H"); break;
	case 225 : strcpy(str, "INT_LIT_O"); break;
	case 226 : strcpy(str, "INT_LIT_D"); break;
	}
	return str;
}

#line 504 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
#line 439 "parser.y" /* yacc.c:355  */

	int ival;
	char *sval;
	float fval;

#line 726 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 743 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  238
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

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
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   468,   468,   471,   472,   475,   476,   479,   480,   483,
     486,   487,   490,   493,   496,   497,   500,   501,   504,   505,
     508,   509,   512,   515,   518,   519,   522,   523,   526,   529,
     530,   533,   534,   537,   540,   541,   544,   545,   548,   549,
     552,   555,   558,   561,   562,   565,   568,   569,   572,   573,
     576,   577,   580,   581,   582,   585,   586,   589,   590,   593,
     594,   595,   598,   599,   602,   605,   608,   611,   612,   615,
     616,   619,   620,   623,   626,   629,   630,   631,   632,   633,
     636,   637,   638,   639,   642,   643,   644,   645,   646,   647,
     648,   649,   652,   655,   658,   659,   660,   661,   662,   663,
     664,   667,   670,   673,   676,   679,   682,   683,   686,   687,
     690,   693,   694,   697,   698,   701,   704,   707,   710,   713,
     716,   717,   720,   721,   724,   725,   728,   729,   732,   735,
     736,   739,   742,   745,   748,   749,   752,   755,   756,   757,
     760,   761,   762,   763,   764,   765,   766,   767,   768,   769,
     770,   771,   774,   775,   778,   779,   782,   783,   786,   789,
     790,   793,   794,   797,   798,   799,   802,   803,   804,   805,
     806,   807,   810,   811,   812,   813,   816,   817,   818,   821,
     822,   823,   824,   827,   828,   831,   832,   833,   834,   835,
     838,   841,   844,   845,   846,   849,   852,   855,   856,   857,
     858,   861,   862,   863,   866,   867,   870,   871,   874,   875,
     876,   877,   878,   879,   880,   883,   886,   887,   890,   891,
     894,   895,   898,   899,   902,   903,   906,   909,   910,   913,
     914,   915,   916,   917,   918,   919,   922,   923,   924
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "INSTANCEOF", "NEW", "SUPER",
  "THIS", "COMMENT", "BOOL", "BYTE", "CHAR", "T", "FLOAT", "INT", "F", "N",
  "VOID", "BREAK", "CASE", "DEFAULT", "ELSE", "IF", "SWITCH", "CONT", "DO",
  "FOR", "WHILE", "RETURN", "CONST", "CID", "ID", "SEP", "TRM", "COLON",
  "ARRAY_S", "ARRAY_E", "BLOCK_S", "BLOCK_E", "PAREN_S", "PAREN_E",
  "OP_ASS", "OP_ADD_ASS", "OP_SUB_ASS", "OP_DIV_ASS", "OP_MUL_ASS",
  "OP_MOD_ASS", "OP_LSH_ASS", "OP_RSH_ASS", "OP_AND_ASS", "OP_OR_ASS",
  "OP_XOR_ASS", "OP_ZRSH_ASS", "OP_CON_Q", "OP_CON_AND", "OP_CON_OR",
  "OP_OR", "OP_XOR", "OP_AND", "OP_EQ", "OP_NEQ", "OP_GRE", "OP_LES",
  "OP_GEQ", "OP_LEQ", "OP_RSH", "OP_LSH", "OP_ADD", "OP_SUB", "OP_MUL",
  "OP_DIV", "OP_MOD", "OP_INC", "OP_DEC", "OP_DOT", "OP_ZRSH", "INT_LIT_D",
  "INT_LIT_O", "INT_LIT_H", "FLOAT_LIT", "CHAR_LIT", "STR_LIT", "ERROR",
  "IGN", "PRINT", "SCAN", "OP_NEG", "STRING", "EXTENDS", "$accept",
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
  "literal", "int_literal", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

#define YYPACT_NINF -335

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-335)))

#define YYTABLE_NINF -201

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,    15,  -335,    26,  -335,    16,  -335,  -335,   -40,  -335,
    -335,    33,    14,  -335,  -335,  -335,  -335,    77,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,    37,    77,  -335,  -335,  -335,
      44,  -335,  -335,    -4,     1,  -335,  -335,  -335,  -335,  -335,
    -335,    20,  -335,  -335,  1046,  -335,  -335,  1123,  -335,  -335,
      32,    53,    66,  -335,   -13,  -335,    77,   128,   -21,    67,
    -335,  -335,  -335,    68,    80,    87,    75,  1152,    93,   101,
     873,  -335,  -335,   873,   873,   873,  -335,  -335,  -335,  -335,
    -335,  -335,  1123,     9,  -335,    72,  1123,  -335,  -335,   119,
    -335,  -335,  -335,  -335,   121,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,   577,  -335,  -335,    57,    62,
      71,   113,   598,    96,   131,   117,  -335,   620,   511,  -335,
    -335,    98,  -335,   133,    77,  -335,   144,  -335,   140,   779,
     138,   147,  -335,     9,   146,    22,   873,   149,   873,  -335,
     873,   873,  -335,   155,  1264,   873,   759,   873,   873,   873,
     151,  -335,  -335,  -335,    40,   134,  -335,   137,   127,    97,
      21,    -1,    92,    34,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,    71,  -335,  -335,   150,  -335,  -335,  -335,   -18,  -335,
     157,  -335,   164,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,   873,
    -335,  -335,   156,   873,   873,   873,   167,  -335,   159,  -335,
    -335,   779,  -335,  -335,  -335,  -335,    77,   165,   856,  -335,
     873,  -335,  -335,   162,   172,   166,   168,   170,   171,   176,
    -335,  -335,   174,  -335,   185,   178,   184,   181,   182,  -335,
    -335,  -335,  -335,   873,   873,   873,   873,   873,   873,   873,
      77,   873,   873,   873,   873,   873,   873,   873,   873,   873,
     873,   873,   873,  -335,  -335,  -335,   187,   191,   193,   183,
    -335,  -335,   192,   199,  -335,  -335,  -335,   196,   194,  -335,
     873,   873,  -335,  1229,   200,   873,   873,  1211,  1152,   873,
     891,   202,   134,  -335,   127,    97,    21,    21,   198,    -1,
      -1,    -1,    -1,    92,    92,    92,    34,    34,  -335,  -335,
    -335,   873,  -335,  -335,  -335,  -335,   779,  -335,  -335,  -335,
     205,   201,   203,   207,  -335,   217,   226,  -335,  -335,  -335,
     145,  -335,   208,   216,  -335,  -335,  -335,  -335,   873,   210,
    -335,  -335,   873,  1264,   873,  1152,   873,   218,   215,   145,
    -335,   969,  -335,   221,  1211,  -335,  -335,   219,   224,   220,
    -335,   227,  -335,  -335,  -335,  1123,  -335,  -335,   225,  -335,
     185,  1229,   873,  1229,  -335,   222,   243,   232,  -335,  1152,
    1229,  1211,  -335,  -335,   233,   229,  1229,  -335
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     8,     0,     2,     3,     5,     7,    11,     1,
       6,     0,     0,    10,   226,    12,    64,    15,     9,    56,
      59,    60,    58,    61,    54,     0,    14,    16,    18,    19,
       0,    20,    21,     0,     0,    52,    55,    57,    53,    62,
      63,    64,    13,    17,    68,    22,    44,    68,    40,    43,
      38,     0,     0,    34,    36,    41,    25,     0,     0,   209,
     233,   234,   235,     0,     0,     0,     0,     0,     0,     0,
     125,   227,    92,     0,     0,     0,   238,   237,   236,   230,
     231,   232,    68,     0,    84,     0,    67,    69,    71,     0,
      72,    75,    85,    86,     0,    76,    77,    87,    78,    88,
      79,    89,    90,    91,    94,     0,    95,    97,    98,    96,
       0,   213,   212,   197,   206,   211,   207,   214,   198,   208,
     229,     0,   209,     0,    25,    65,     0,    33,     0,     0,
       0,    24,    26,     0,     0,     0,   217,     0,   217,   131,
       0,     0,   132,     0,   121,     0,     0,     0,     0,     0,
       0,   124,   135,   134,   152,   154,   156,   158,   159,   161,
     163,   166,   172,   176,   194,   179,   185,   186,   189,   200,
     199,   192,   213,   211,     0,   190,   212,   214,   198,   191,
       0,    38,    74,    30,    70,    73,    93,   140,   144,   145,
     142,   141,   143,   146,   147,   149,   151,   150,   148,     0,
     196,   195,     0,     0,     0,   217,     0,    66,     0,    35,
      39,    47,    51,    37,    50,    23,     0,    28,     0,   220,
     217,   221,   218,     0,   216,   205,     0,     0,     0,     0,
     123,   129,     0,   120,   122,     0,     0,    52,    53,   187,
     188,   193,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,    29,   136,   204,     0,     0,     0,
     228,    42,     0,    46,    48,    27,   223,     0,     0,    32,
       0,   217,    31,     0,     0,     0,   125,     0,     0,     0,
       0,     0,   155,   157,   160,   162,   164,   165,   171,   168,
     167,   170,   169,   174,   173,   175,   177,   178,   180,   181,
     182,   217,   225,   224,   201,    45,     0,   222,   215,   219,
       0,     0,     0,     0,   101,     0,    75,    81,    82,    83,
     107,   104,     0,     0,   130,   115,   183,   184,     0,     0,
      49,   203,     0,   121,     0,     0,     0,     0,     0,   106,
     108,     0,   111,     0,   127,   153,   202,     0,     0,     0,
     102,     0,   114,   105,   109,   110,   112,   117,     0,   126,
     128,     0,   125,     0,   113,     0,     0,     0,   116,     0,
       0,   127,   118,   103,     0,     0,     0,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -335,  -335,  -335,  -335,   265,  -335,  -335,  -335,  -335,  -335,
    -335,   245,  -335,  -335,  -335,   148,  -335,    59,  -335,  -335,
    -335,   190,   152,   143,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -202,   -15,   -49,  -335,  -335,  -133,     3,  -335,   244,
     -27,   -72,   -85,  -335,  -137,     5,  -334,  -253,  -335,  -335,
    -140,  -335,  -335,  -335,  -335,  -335,  -335,  -335,   -68,  -335,
     -67,  -335,  -335,  -335,  -335,  -335,   -61,  -335,  -270,   -98,
    -335,  -323,  -335,  -335,  -335,   395,   -44,  -335,  -335,   -53,
    -335,    43,    45,  -335,    46,    42,   -87,  -184,  -134,   -90,
    -335,   -69,   -32,   -20,     4,    29,    69,    81,   130,   322,
    -335,  -335,   142,  -128,  -335,  -335,   160,   443,    17,   468,
    -335,  -335
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    12,    13,    18,    25,
      26,    27,    28,    29,    30,   130,   131,   132,    45,    82,
      31,    52,    53,    54,    32,    33,    55,    48,   212,   272,
     273,   213,    83,    35,    36,    37,    38,    39,    40,    84,
      85,    86,    87,    88,    89,    90,   325,    91,    92,    93,
      94,    95,    96,   327,    97,   331,   348,   349,   350,   351,
     352,    98,   328,    99,   100,   329,   232,   233,   150,   368,
     369,   234,   101,   102,   103,   222,   152,   105,   199,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   112,
     113,   114,   173,   223,   224,   116,   219,   117,    16,   118,
     119,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     104,   184,    34,   104,   231,   175,   179,   230,   134,   274,
     226,    34,   106,   238,    15,   106,   333,   204,   136,     1,
     123,   205,   128,   104,   107,   250,     9,   107,   129,    46,
     326,   370,    50,    47,    41,   106,    51,   376,   104,   378,
     181,   133,   104,    41,    51,     8,   383,   107,    11,     2,
     106,    17,   387,   137,   106,   180,   206,   218,   370,    56,
     135,   220,   107,    14,   255,   256,   107,   299,   300,   301,
     302,   124,   143,   108,   257,    42,   108,   269,   239,   240,
     241,    44,   251,   252,   253,   254,    19,    20,    21,   125,
      22,    23,   278,   243,    24,   244,   108,   237,   126,   127,
     104,   139,   377,   260,   261,   262,   138,    14,   142,   133,
     183,   108,   106,   109,   340,   108,   109,   298,   326,   140,
     326,   303,   304,   305,   107,   110,   141,   326,   110,  -200,
    -200,   236,   144,   326,  -199,  -199,   109,    19,    20,    21,
     145,    22,    23,   200,   201,   -99,   -99,   334,   110,  -100,
    -100,   109,   185,   320,   186,   109,   248,   249,    14,   258,
     259,   296,   297,   110,   346,   347,   203,   110,   306,   307,
     202,   207,   137,   108,   111,   181,   210,   111,   215,   216,
     225,   218,   229,   339,   242,   247,   115,   266,   245,   115,
     263,   308,   309,   310,   246,   264,   126,   111,   270,   271,
     128,   133,   279,   231,   280,   281,   230,   286,   282,   115,
     283,   284,   111,   109,   231,   285,   111,   287,   288,    51,
     336,   289,   290,   314,   115,   110,   311,   312,   115,   313,
     315,   316,   317,   -53,   318,   236,   338,   330,   345,   104,
     342,   231,   343,   104,   104,   341,   344,   -80,   353,   354,
     356,   106,   362,   363,   367,   106,   106,   372,   375,   371,
     373,   374,   379,   107,   380,   381,   385,   107,   107,   386,
      10,    43,   208,   182,   111,   275,   217,    49,   209,   365,
     184,   364,   358,   384,   366,   355,   115,   292,   324,   295,
     293,     0,   294,   335,   337,   221,     0,     0,     0,   104,
       0,   104,     0,     0,     0,     0,     0,   104,     0,     0,
     104,   106,   108,   106,     0,     0,   108,   108,     0,   106,
       0,   104,   106,   107,     0,   107,     0,   104,     0,   104,
       0,   107,     0,   106,   107,   104,   104,   104,     0,   106,
       0,   106,   104,     0,     0,   107,     0,   106,   106,   106,
     360,   107,   109,   107,   106,     0,   109,   109,     0,   107,
     107,   107,     0,     0,   110,     0,   107,     0,   110,   110,
       0,     0,   108,     0,   108,     0,   324,     0,   335,     0,
     108,     0,     0,   108,   382,   360,     0,     0,     0,     0,
       0,   382,     0,     0,   108,     0,   176,   176,     0,     0,
     108,     0,   108,     0,     0,     0,     0,     0,   108,   108,
     108,     0,   109,   111,   109,   108,     0,   111,   111,     0,
     109,     0,     0,   109,   110,   115,   110,     0,     0,   115,
     115,     0,   110,     0,   109,   110,     0,     0,     0,     0,
     109,     0,   109,     0,     0,     0,   110,     0,   109,   109,
     109,     0,   110,     0,   110,   109,     0,     0,     0,     0,
     110,   110,   110,     0,     0,   151,     0,   110,   174,   176,
     176,   176,     0,   111,     0,   111,     0,     0,     0,     0,
       0,   111,     0,     0,   111,   115,     0,   115,     0,     0,
       0,     0,     0,   115,     0,   111,   115,     0,     0,     0,
       0,   111,     0,   111,     0,     0,     0,   115,     0,   111,
     111,   111,     0,   115,     0,   115,   111,   177,   177,     0,
       0,   115,   115,   115,   214,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,   227,   228,     0,     0,     0,
     235,   174,   178,   178,     0,     0,   204,     0,     0,     0,
     205,     0,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,     0,     0,   176,   176,   176,   176,
     176,   176,     0,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   206,     0,     0,     0,     0,
     177,   177,   177,     0,   265,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
       0,   176,   176,   277,     0,   178,   178,   178,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,   291,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,     0,     0,   319,     0,     0,     0,     0,
     332,   151,     0,     0,     0,     0,     0,   177,   177,   177,
     177,   177,   177,     0,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,     0,     0,     0,     0,
       0,   214,   178,   178,   178,   178,   178,   178,     0,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,     0,   177,   177,     0,     0,     0,   357,     0,   359,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   178,   178,     0,
       0,     0,     0,     0,    57,   121,   122,   151,    19,    20,
      21,    60,    22,    23,    61,    62,    24,     0,     0,     0,
       0,   177,     0,     0,    57,   121,   122,     0,     0,    14,
      71,    60,     0,     0,    61,    62,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,   178,     0,     0,     0,
      71,     0,     0,     0,     0,     0,   211,     0,   146,     0,
       0,     0,     0,     0,     0,     0,   147,   148,     0,     0,
       0,    74,    75,     0,     0,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,   149,   147,   148,     0,     0,
       0,    74,    75,     0,     0,    76,    77,    78,    79,    80,
      81,    57,   121,   122,     0,   149,     0,     0,    60,     0,
       0,    61,    62,     0,     0,     0,     0,     0,    57,   121,
     122,     0,     0,     0,     0,    60,     0,    71,    61,    62,
       0,     0,   276,     0,     0,   146,    57,   121,   122,     0,
       0,     0,     0,    60,    71,     0,    61,    62,     0,     0,
       0,     0,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,   147,   148,     0,     0,     0,    74,    75,
     146,     0,    76,    77,    78,    79,    80,    81,     0,     0,
     147,   148,   149,     0,     0,    74,    75,     0,     0,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,   149,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,     0,    57,   121,   122,   149,    19,    20,
      21,    60,    22,    23,    61,    62,    24,    63,   346,   347,
       0,    64,    65,    66,    67,    68,    69,    70,     0,    14,
      71,     0,    72,     0,     0,     0,    47,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,     0,     0,    76,    77,    78,    79,    80,
      81,    57,    58,    59,     0,    19,    20,    21,    60,    22,
      23,    61,    62,    24,    63,     0,     0,     0,    64,    65,
      66,    67,    68,    69,    70,     0,    14,    71,     0,    72,
       0,     0,     0,    47,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
       0,     0,    76,    77,    78,    79,    80,    81,    57,   121,
     122,     0,    19,    20,    21,    60,    22,    23,    61,    62,
      24,    63,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,     0,    14,    71,     0,    72,    57,   121,   122,
      47,     0,    73,     0,    60,     0,     0,    61,    62,     0,
      63,     0,     0,     0,    64,    65,    66,    67,    68,    69,
      70,     0,     0,    71,     0,    72,     0,     0,     0,    47,
       0,    73,     0,     0,     0,    74,    75,     0,     0,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,   121,   122,     0,
       0,     0,     0,    60,    74,    75,    61,    62,    76,    77,
      78,    79,    80,    81,    57,   121,   122,     0,     0,     0,
       0,    60,    71,     0,    61,    62,     0,    63,     0,     0,
      73,   321,    65,    66,    67,   322,   323,    70,     0,     0,
      71,     0,    72,     0,     0,     0,    47,     0,    73,    57,
     121,   122,     0,    19,    20,    21,    60,    22,    23,    61,
      62,    24,     0,    74,    75,     0,     0,    76,    77,    78,
      79,    80,    81,     0,    14,    71,     0,     0,     0,     0,
       0,    74,    75,    73,     0,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,     0,     0,
      76,    77,    78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
      44,    86,    17,    47,   144,    74,    75,   144,    57,   211,
     138,    26,    44,   146,    11,    47,   286,    35,    39,     3,
      47,    39,    35,    67,    44,     4,     0,    47,    41,    33,
     283,   354,    31,    37,    17,    67,    35,   371,    82,   373,
      31,    56,    86,    26,    35,    30,   380,    67,    88,    33,
      82,    37,   386,    74,    86,    82,    74,    35,   381,    39,
      57,    39,    82,    30,    65,    66,    86,   251,   252,   253,
     254,    39,    67,    44,    75,    38,    47,   205,   147,   148,
     149,    37,    61,    62,    63,    64,     9,    10,    11,    36,
      13,    14,   220,    53,    17,    55,    67,   146,    32,    33,
     144,    33,   372,    69,    70,    71,    39,    30,    33,   124,
      38,    82,   144,    44,   316,    86,    47,   250,   371,    39,
     373,   255,   256,   257,   144,    44,    39,   380,    47,    72,
      73,   146,    39,   386,    72,    73,    67,     9,    10,    11,
      39,    13,    14,    72,    73,    32,    33,   287,    67,    32,
      33,    82,    33,   281,    33,    86,    59,    60,    30,    67,
      68,   248,   249,    82,    19,    20,    35,    86,   258,   259,
      74,    38,    74,   144,    44,    31,    36,    47,    40,    32,
      31,    35,    27,   311,    33,    58,    44,    31,    54,    47,
      40,   260,   261,   262,    57,    38,    32,    67,    31,    40,
      35,   216,    40,   343,    32,    39,   343,    33,    40,    67,
      40,    40,    82,   144,   354,    39,    86,    32,    40,    35,
     289,    40,    40,    40,    82,   144,    39,    36,    86,    36,
      38,    32,    36,    35,    40,   250,    34,    37,    21,   283,
      39,   381,    39,   287,   288,    40,    39,    21,    40,    33,
      40,   283,    34,    38,    33,   287,   288,    33,    33,    40,
      40,    34,    40,   283,    21,    33,    33,   287,   288,    40,
       5,    26,   124,    83,   144,   216,   133,    33,   126,   351,
     365,   349,   343,   381,   351,   338,   144,   244,   283,   247,
     245,    -1,   246,   288,   290,   135,    -1,    -1,    -1,   343,
      -1,   345,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,
     354,   343,   283,   345,    -1,    -1,   287,   288,    -1,   351,
      -1,   365,   354,   343,    -1,   345,    -1,   371,    -1,   373,
      -1,   351,    -1,   365,   354,   379,   380,   381,    -1,   371,
      -1,   373,   386,    -1,    -1,   365,    -1,   379,   380,   381,
     345,   371,   283,   373,   386,    -1,   287,   288,    -1,   379,
     380,   381,    -1,    -1,   283,    -1,   386,    -1,   287,   288,
      -1,    -1,   343,    -1,   345,    -1,   371,    -1,   373,    -1,
     351,    -1,    -1,   354,   379,   380,    -1,    -1,    -1,    -1,
      -1,   386,    -1,    -1,   365,    -1,    74,    75,    -1,    -1,
     371,    -1,   373,    -1,    -1,    -1,    -1,    -1,   379,   380,
     381,    -1,   343,   283,   345,   386,    -1,   287,   288,    -1,
     351,    -1,    -1,   354,   343,   283,   345,    -1,    -1,   287,
     288,    -1,   351,    -1,   365,   354,    -1,    -1,    -1,    -1,
     371,    -1,   373,    -1,    -1,    -1,   365,    -1,   379,   380,
     381,    -1,   371,    -1,   373,   386,    -1,    -1,    -1,    -1,
     379,   380,   381,    -1,    -1,    70,    -1,   386,    73,   147,
     148,   149,    -1,   343,    -1,   345,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,   354,   343,    -1,   345,    -1,    -1,
      -1,    -1,    -1,   351,    -1,   365,   354,    -1,    -1,    -1,
      -1,   371,    -1,   373,    -1,    -1,    -1,   365,    -1,   379,
     380,   381,    -1,   371,    -1,   373,   386,    74,    75,    -1,
      -1,   379,   380,   381,   129,    -1,    -1,    -1,   386,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   141,    -1,    -1,    -1,
     145,   146,    74,    75,    -1,    -1,    35,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    74,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   199,    -1,    -1,    -1,   203,   204,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,   289,   290,   218,    -1,   147,   148,   149,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,   280,    -1,    -1,    -1,    -1,
     285,   286,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,    -1,    -1,    -1,
      -1,   316,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   289,   290,    -1,    -1,    -1,   342,    -1,   344,
      -1,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,   290,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,   372,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,   338,    -1,    -1,     5,     6,     7,    -1,    -1,    30,
      31,    12,    -1,    -1,    15,    16,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    86,    67,    68,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,     5,     6,     7,    -1,    86,    -1,    -1,    12,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    31,    15,    16,
      -1,    -1,    36,    -1,    -1,    39,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    31,    -1,    15,    16,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    67,    68,    -1,    -1,    -1,    72,    73,
      39,    -1,    76,    77,    78,    79,    80,    81,    -1,    -1,
      67,    68,    86,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,     5,     6,     7,    86,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    33,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    33,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    33,     5,     6,     7,
      37,    -1,    39,    -1,    12,    -1,    -1,    15,    16,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,
      -1,    39,    -1,    -1,    -1,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    72,    73,    15,    16,    76,    77,
      78,    79,    80,    81,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    31,    -1,    15,    16,    -1,    18,    -1,    -1,
      39,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    -1,    33,    -1,    -1,    -1,    37,    -1,    39,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    72,    73,    39,    -1,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    33,    90,    91,    92,    93,    94,    30,     0,
      93,    88,    95,    96,    30,   126,   197,    37,    97,     9,
      10,    11,    13,    14,    17,    98,    99,   100,   101,   102,
     103,   109,   113,   114,   121,   122,   123,   124,   125,   126,
     127,   197,    38,   100,    37,   107,    33,    37,   116,   128,
      31,    35,   110,   111,   112,   115,    39,     5,     6,     7,
      12,    15,    16,    18,    22,    23,    24,    25,    26,    27,
      28,    31,    33,    39,    72,    73,    76,    77,    78,    79,
      80,    81,   108,   121,   128,   129,   130,   131,   132,   133,
     134,   136,   137,   138,   139,   140,   141,   143,   150,   152,
     153,   161,   162,   163,   165,   166,   181,   182,   184,   185,
     186,   187,   188,   189,   190,   191,   194,   196,   198,   199,
     200,     6,     7,   129,    39,    36,    32,    33,    35,    41,
     104,   105,   106,   121,   122,   126,    39,    74,    39,    33,
      39,    39,    33,   134,    39,    39,    39,    67,    68,    86,
     157,   164,   165,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   191,   164,   180,   188,   196,   198,   180,
     129,    31,   110,    38,   131,    33,    33,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   167,
      72,    73,    74,    35,    35,    39,    74,    38,   104,   111,
      36,    37,   117,   120,   164,    40,    32,   112,    35,   195,
      39,   195,   164,   192,   193,    31,   192,   164,   164,    27,
     133,   139,   155,   156,   160,   164,   121,   122,   125,   180,
     180,   180,    33,    53,    55,    54,    57,    58,    59,    60,
       4,    61,    62,    63,    64,    65,    66,    75,    67,    68,
      69,    70,    71,    40,    38,   164,    31,   164,   164,   192,
      31,    40,   118,   119,   120,   106,    36,   164,   192,    40,
      32,    39,    40,    40,    40,    39,    33,    32,    40,    40,
      40,   164,   170,   171,   173,   174,   175,   175,   125,   176,
     176,   176,   176,   177,   177,   177,   178,   178,   180,   180,
     180,    39,    36,    36,    40,    38,    32,    36,    40,   164,
     192,    22,    26,    27,   134,   135,   136,   142,   151,   154,
      37,   144,   164,   157,   139,   134,   180,   183,    34,   192,
     120,    40,    39,    39,    39,    21,    19,    20,   145,   146,
     147,   148,   149,    40,    33,   168,    40,   164,   155,   164,
     134,   164,    34,    38,   147,   130,   149,    33,   158,   159,
     160,    40,    33,    40,    34,    33,   135,   157,   135,    40,
      21,    33,   134,   135,   158,    33,    40,   135
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      95,    95,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   103,   104,   104,   105,   105,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   112,
     113,   114,   115,   116,   116,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   125,   125,   126,   127,   128,   129,   129,   130,
     130,   131,   131,   132,   133,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   138,   139,   139,   139,   139,   139,   139,
     139,   140,   141,   142,   143,   144,   145,   145,   146,   146,
     147,   148,   148,   149,   149,   150,   151,   152,   153,   154,
     155,   155,   156,   156,   157,   157,   158,   158,   159,   160,
     160,   161,   162,   163,   164,   164,   165,   166,   166,   166,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168,   169,   169,   170,   170,   171,   172,
     172,   173,   173,   174,   174,   174,   175,   175,   175,   175,
     175,   175,   176,   176,   176,   176,   177,   177,   177,   178,
     178,   178,   178,   179,   179,   180,   180,   180,   180,   180,
     181,   182,   183,   183,   183,   184,   185,   186,   186,   186,
     186,   187,   187,   187,   188,   188,   189,   189,   190,   190,
     190,   190,   190,   190,   190,   191,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   198,   198,   199,
     199,   199,   199,   199,   199,   199,   200,   200,   200
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     2,     1,     1,     4,
       1,     0,     2,     3,     1,     0,     1,     2,     1,     1,
       1,     1,     2,     4,     1,     0,     1,     3,     2,     4,
       3,     4,     4,     3,     1,     3,     1,     3,     1,     3,
       2,     2,     4,     1,     1,     3,     1,     0,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     0,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     7,     7,     5,     3,     1,     0,     1,     2,
       2,     1,     2,     3,     2,     5,     5,     7,    10,    10,
       1,     0,     1,     1,     1,     0,     1,     0,     1,     1,
       3,     2,     2,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     1,     3,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     4,     4,     1,     1,     2,     2,     1,
       2,     2,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     4,     6,     6,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     5,     1,     0,     1,     3,
       3,     3,     3,     2,     4,     4,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 468 "parser.y" /* yacc.c:1646  */
    {push(s1,1);push(s2,1);}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 471 "parser.y" /* yacc.c:1646  */
    {push(s1,2);push(s2,2);}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 472 "parser.y" /* yacc.c:1646  */
    {push(s1,2);push(s2,0);}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 475 "parser.y" /* yacc.c:1646  */
    {push(s1,3);push(s2,3);}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 476 "parser.y" /* yacc.c:1646  */
    {push(s1,3);push(s2,4);}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 479 "parser.y" /* yacc.c:1646  */
    {push(s1,4);push(s2,5);}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 480 "parser.y" /* yacc.c:1646  */
    {push(s1,4);push(s2,6);}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 483 "parser.y" /* yacc.c:1646  */
    {push(s1,5);push(s2,7);}
#line 2378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 486 "parser.y" /* yacc.c:1646  */
    {push(s1,6);push(s2,8);}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 487 "parser.y" /* yacc.c:1646  */
    {push(s1,6);push(s2,0);}
#line 2390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 490 "parser.y" /* yacc.c:1646  */
    {push(s1,7);push(s2,9);}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 493 "parser.y" /* yacc.c:1646  */
    {push(s1,8);push(s2,10);}
#line 2402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 496 "parser.y" /* yacc.c:1646  */
    {push(s1,9);push(s2,11);}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 497 "parser.y" /* yacc.c:1646  */
    {push(s1,9);push(s2,0);}
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 500 "parser.y" /* yacc.c:1646  */
    {push(s1,10);push(s2,12);}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 501 "parser.y" /* yacc.c:1646  */
    {push(s1,10);push(s2,13);}
#line 2426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 504 "parser.y" /* yacc.c:1646  */
    {push(s1,11);push(s2,14);}
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 505 "parser.y" /* yacc.c:1646  */
    {push(s1,11);push(s2,15);}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 508 "parser.y" /* yacc.c:1646  */
    {push(s1,12);push(s2,16);}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 509 "parser.y" /* yacc.c:1646  */
    {push(s1,12);push(s2,17);}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 512 "parser.y" /* yacc.c:1646  */
    {push(s1,13);push(s2,18);}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 515 "parser.y" /* yacc.c:1646  */
    {push(s1,14);push(s2,19);}
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 518 "parser.y" /* yacc.c:1646  */
    {push(s1,15);push(s2,20);}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 519 "parser.y" /* yacc.c:1646  */
    {push(s1,15);push(s2,0);}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 522 "parser.y" /* yacc.c:1646  */
    {push(s1,16);push(s2,21);}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 523 "parser.y" /* yacc.c:1646  */
    {push(s1,16);push(s2,22);}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 526 "parser.y" /* yacc.c:1646  */
    {push(s1,17);push(s2,23);}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 529 "parser.y" /* yacc.c:1646  */
    {push(s1,18);push(s2,24);}
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 530 "parser.y" /* yacc.c:1646  */
    {push(s1,18);push(s2,25);}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 533 "parser.y" /* yacc.c:1646  */
    {push(s1,19);push(s2,26);}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 534 "parser.y" /* yacc.c:1646  */
    {push(s1,19);push(s2,27);}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 537 "parser.y" /* yacc.c:1646  */
    {push(s1,20);push(s2,28);}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 540 "parser.y" /* yacc.c:1646  */
    {push(s1,21);push(s2,29);}
#line 2528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 541 "parser.y" /* yacc.c:1646  */
    {push(s1,21);push(s2,30);}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 544 "parser.y" /* yacc.c:1646  */
    {push(s1,22);push(s2,31);}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 545 "parser.y" /* yacc.c:1646  */
    {push(s1,22);push(s2,32);}
#line 2546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 548 "parser.y" /* yacc.c:1646  */
    {push(s1,23);push(s2,33);}
#line 2552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 549 "parser.y" /* yacc.c:1646  */
    {push(s1,23);push(s2,34);}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 552 "parser.y" /* yacc.c:1646  */
    {push(s1,24);push(s2,35);}
#line 2564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 555 "parser.y" /* yacc.c:1646  */
    {push(s1,25);push(s2,36);}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 558 "parser.y" /* yacc.c:1646  */
    {push(s1,26);push(s2,37);}
#line 2576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 561 "parser.y" /* yacc.c:1646  */
    {push(s1,27);push(s2,38);}
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 562 "parser.y" /* yacc.c:1646  */
    {push(s1,27);push(s2,39);}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 565 "parser.y" /* yacc.c:1646  */
    {push(s1,28);push(s2,40);}
#line 2594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 568 "parser.y" /* yacc.c:1646  */
    {push(s1,29);push(s2,41);}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 569 "parser.y" /* yacc.c:1646  */
    {push(s1,29);push(s2,0);}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 572 "parser.y" /* yacc.c:1646  */
    {push(s1,30);push(s2,42);}
#line 2612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 573 "parser.y" /* yacc.c:1646  */
    {push(s1,30);push(s2,43);}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 576 "parser.y" /* yacc.c:1646  */
    {push(s1,31);push(s2,44);}
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 577 "parser.y" /* yacc.c:1646  */
    {push(s1,31);push(s2,45);}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 580 "parser.y" /* yacc.c:1646  */
    {push(s1,32);push(s2,46);}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 581 "parser.y" /* yacc.c:1646  */
    {push(s1,32);push(s2,47);}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 582 "parser.y" /* yacc.c:1646  */
    {push(s1,32);push(s2,48);}
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 585 "parser.y" /* yacc.c:1646  */
    {push(s1,33);push(s2,49);}
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 586 "parser.y" /* yacc.c:1646  */
    {push(s1,33);push(s2,50);}
#line 2660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 589 "parser.y" /* yacc.c:1646  */
    {push(s1,34);push(s2,51);}
#line 2666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 590 "parser.y" /* yacc.c:1646  */
    {push(s1,34);push(s2,52);}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 593 "parser.y" /* yacc.c:1646  */
    {push(s1,35);push(s2,53);}
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 594 "parser.y" /* yacc.c:1646  */
    {push(s1,35);push(s2,54);}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 595 "parser.y" /* yacc.c:1646  */
    {push(s1,35);push(s2,55);}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 598 "parser.y" /* yacc.c:1646  */
    {push(s1,36);push(s2,56);}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 599 "parser.y" /* yacc.c:1646  */
    {push(s1,36);push(s2,57);}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 602 "parser.y" /* yacc.c:1646  */
    {push(s1,37);push(s2,58);}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 605 "parser.y" /* yacc.c:1646  */
    {push(s1,38);push(s2,59);}
#line 2714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 608 "parser.y" /* yacc.c:1646  */
    {push(s1,39);push(s2,60);}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 611 "parser.y" /* yacc.c:1646  */
    {push(s1,40);push(s2,61);}
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 612 "parser.y" /* yacc.c:1646  */
    {push(s1,40);push(s2,0);}
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 615 "parser.y" /* yacc.c:1646  */
    {push(s1,41);push(s2,62);}
#line 2738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 616 "parser.y" /* yacc.c:1646  */
    {push(s1,41);push(s2,63);}
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 619 "parser.y" /* yacc.c:1646  */
    {push(s1,42);push(s2,64);}
#line 2750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 620 "parser.y" /* yacc.c:1646  */
    {push(s1,42);push(s2,65);}
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 623 "parser.y" /* yacc.c:1646  */
    {push(s1,43);push(s2,66);}
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 626 "parser.y" /* yacc.c:1646  */
    {push(s1,44);push(s2,67);}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 629 "parser.y" /* yacc.c:1646  */
    {push(s1,45);push(s2,68);}
#line 2774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 630 "parser.y" /* yacc.c:1646  */
    {push(s1,45);push(s2,69);}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 631 "parser.y" /* yacc.c:1646  */
    {push(s1,45);push(s2,70);}
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 632 "parser.y" /* yacc.c:1646  */
    {push(s1,45);push(s2,71);}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 633 "parser.y" /* yacc.c:1646  */
    {push(s1,45);push(s2,72);}
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 636 "parser.y" /* yacc.c:1646  */
    {push(s1,46);push(s2,73);}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 637 "parser.y" /* yacc.c:1646  */
    {push(s1,46);push(s2,74);}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 638 "parser.y" /* yacc.c:1646  */
    {push(s1,46);push(s2,75);}
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 639 "parser.y" /* yacc.c:1646  */
    {push(s1,46);push(s2,76);}
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 642 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,77);}
#line 2828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 643 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,78);}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 644 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,79);}
#line 2840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 645 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,80);}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 646 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,81);}
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 647 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,82);}
#line 2858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 648 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,83);}
#line 2864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 649 "parser.y" /* yacc.c:1646  */
    {push(s1,47);push(s2,84);}
#line 2870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 652 "parser.y" /* yacc.c:1646  */
    {push(s1,48);push(s2,85);}
#line 2876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 655 "parser.y" /* yacc.c:1646  */
    {push(s1,49);push(s2,86);}
#line 2882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 658 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,87);}
#line 2888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 659 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,88);}
#line 2894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 660 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,89);}
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 661 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,90);}
#line 2906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 662 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,91);}
#line 2912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 663 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,92);}
#line 2918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 664 "parser.y" /* yacc.c:1646  */
    {push(s1,50);push(s2,93);}
#line 2924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 667 "parser.y" /* yacc.c:1646  */
    {push(s1,51);push(s2,94);}
#line 2930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 670 "parser.y" /* yacc.c:1646  */
    {push(s1,52);push(s2,95);}
#line 2936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 673 "parser.y" /* yacc.c:1646  */
    {push(s1,53);push(s2,96);}
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 676 "parser.y" /* yacc.c:1646  */
    {push(s1,54);push(s2,97);}
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 679 "parser.y" /* yacc.c:1646  */
    {push(s1,55);push(s2,98);}
#line 2954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 682 "parser.y" /* yacc.c:1646  */
    {push(s1,56);push(s2,99);}
#line 2960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 683 "parser.y" /* yacc.c:1646  */
    {push(s1,56);push(s2,0);}
#line 2966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 686 "parser.y" /* yacc.c:1646  */
    {push(s1,57);push(s2,100);}
#line 2972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 687 "parser.y" /* yacc.c:1646  */
    {push(s1,57);push(s2,101);}
#line 2978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 690 "parser.y" /* yacc.c:1646  */
    {push(s1,58);push(s2,102);}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 693 "parser.y" /* yacc.c:1646  */
    {push(s1,59);push(s2,103);}
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 694 "parser.y" /* yacc.c:1646  */
    {push(s1,59);push(s2,104);}
#line 2996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 697 "parser.y" /* yacc.c:1646  */
    {push(s1,60);push(s2,105);}
#line 3002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 698 "parser.y" /* yacc.c:1646  */
    {push(s1,60);push(s2,106);}
#line 3008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 701 "parser.y" /* yacc.c:1646  */
    {push(s1,61);push(s2,107);}
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 704 "parser.y" /* yacc.c:1646  */
    {push(s1,62);push(s2,108);}
#line 3020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 707 "parser.y" /* yacc.c:1646  */
    {push(s1,63);push(s2,109);}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 710 "parser.y" /* yacc.c:1646  */
    {push(s1,64);push(s2,110);}
#line 3032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 713 "parser.y" /* yacc.c:1646  */
    {push(s1,65);push(s2,111);}
#line 3038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 716 "parser.y" /* yacc.c:1646  */
    {push(s1,66);push(s2,112);}
#line 3044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 717 "parser.y" /* yacc.c:1646  */
    {push(s1,66);push(s2,0);}
#line 3050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 720 "parser.y" /* yacc.c:1646  */
    {push(s1,67);push(s2,113);}
#line 3056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 721 "parser.y" /* yacc.c:1646  */
    {push(s1,67);push(s2,114);}
#line 3062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 724 "parser.y" /* yacc.c:1646  */
    {push(s1,68);push(s2,115);}
#line 3068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 725 "parser.y" /* yacc.c:1646  */
    {push(s1,68);push(s2,0);}
#line 3074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 728 "parser.y" /* yacc.c:1646  */
    {push(s1,69);push(s2,116);}
#line 3080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 729 "parser.y" /* yacc.c:1646  */
    {push(s1,69);push(s2,0);}
#line 3086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 732 "parser.y" /* yacc.c:1646  */
    {push(s1,70);push(s2,117);}
#line 3092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 735 "parser.y" /* yacc.c:1646  */
    {push(s1,71);push(s2,118);}
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 736 "parser.y" /* yacc.c:1646  */
    {push(s1,71);push(s2,119);}
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 739 "parser.y" /* yacc.c:1646  */
    {push(s1,72);push(s2,120);}
#line 3110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 742 "parser.y" /* yacc.c:1646  */
    {push(s1,73);push(s2,121);}
#line 3116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 745 "parser.y" /* yacc.c:1646  */
    {push(s1,74);push(s2,122);}
#line 3122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 748 "parser.y" /* yacc.c:1646  */
    {push(s1,75);push(s2,123);}
#line 3128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 749 "parser.y" /* yacc.c:1646  */
    {push(s1,75);push(s2,124);}
#line 3134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 752 "parser.y" /* yacc.c:1646  */
    {push(s1,76);push(s2,125);}
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 755 "parser.y" /* yacc.c:1646  */
    {push(s1,77);push(s2,126);}
#line 3146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 756 "parser.y" /* yacc.c:1646  */
    {push(s1,77);push(s2,127);}
#line 3152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 757 "parser.y" /* yacc.c:1646  */
    {push(s1,77);push(s2,128);}
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 760 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,129);}
#line 3164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 761 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,130);}
#line 3170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 762 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,131);}
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 763 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,132);}
#line 3182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 764 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,133);}
#line 3188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 765 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,134);}
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 766 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,135);}
#line 3200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 767 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,136);}
#line 3206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 768 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,137);}
#line 3212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 769 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,138);}
#line 3218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 770 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,139);}
#line 3224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 771 "parser.y" /* yacc.c:1646  */
    {push(s1,78);push(s2,140);}
#line 3230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 774 "parser.y" /* yacc.c:1646  */
    {push(s1,79);push(s2,141);}
#line 3236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 775 "parser.y" /* yacc.c:1646  */
    {push(s1,79);push(s2,142);}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 778 "parser.y" /* yacc.c:1646  */
    {push(s1,80);push(s2,143);}
#line 3248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 779 "parser.y" /* yacc.c:1646  */
    {push(s1,80);push(s2,144);}
#line 3254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 782 "parser.y" /* yacc.c:1646  */
    {push(s1,81);push(s2,145);}
#line 3260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 783 "parser.y" /* yacc.c:1646  */
    {push(s1,81);push(s2,146);}
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 786 "parser.y" /* yacc.c:1646  */
    {push(s1,82);push(s2,147);}
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 789 "parser.y" /* yacc.c:1646  */
    {push(s1,83);push(s2,148);}
#line 3278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 790 "parser.y" /* yacc.c:1646  */
    {push(s1,83);push(s2,149);}
#line 3284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 793 "parser.y" /* yacc.c:1646  */
    {push(s1,84);push(s2,150);}
#line 3290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 794 "parser.y" /* yacc.c:1646  */
    {push(s1,84);push(s2,151);}
#line 3296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 797 "parser.y" /* yacc.c:1646  */
    {push(s1,85);push(s2,152);}
#line 3302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 798 "parser.y" /* yacc.c:1646  */
    {push(s1,85);push(s2,153);}
#line 3308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 799 "parser.y" /* yacc.c:1646  */
    {push(s1,85);push(s2,154);}
#line 3314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 802 "parser.y" /* yacc.c:1646  */
    {push(s1,86);push(s2,155);}
#line 3320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 803 "parser.y" /* yacc.c:1646  */
    {push(s1,86);push(s2,156);}
#line 3326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 804 "parser.y" /* yacc.c:1646  */
    {push(s1,86);push(s2,157);}
#line 3332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 805 "parser.y" /* yacc.c:1646  */
    {push(s1,86);push(s2,158);}
#line 3338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 806 "parser.y" /* yacc.c:1646  */
    {push(s1,86);push(s2,159);}
#line 3344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 807 "parser.y" /* yacc.c:1646  */
    {push(s1,86);push(s2,160);}
#line 3350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 810 "parser.y" /* yacc.c:1646  */
    {push(s1,87);push(s2,161);}
#line 3356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 811 "parser.y" /* yacc.c:1646  */
    {push(s1,87);push(s2,162);}
#line 3362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 812 "parser.y" /* yacc.c:1646  */
    {push(s1,87);push(s2,163);}
#line 3368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 813 "parser.y" /* yacc.c:1646  */
    {push(s1,87);push(s2,164);}
#line 3374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 816 "parser.y" /* yacc.c:1646  */
    {push(s1,88);push(s2,165);}
#line 3380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 817 "parser.y" /* yacc.c:1646  */
    {push(s1,88);push(s2,166);}
#line 3386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 818 "parser.y" /* yacc.c:1646  */
    {push(s1,88);push(s2,167);}
#line 3392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 821 "parser.y" /* yacc.c:1646  */
    {push(s1,89);push(s2,168);}
#line 3398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 822 "parser.y" /* yacc.c:1646  */
    {push(s1,89);push(s2,169);}
#line 3404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 823 "parser.y" /* yacc.c:1646  */
    {push(s1,89);push(s2,170);}
#line 3410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 824 "parser.y" /* yacc.c:1646  */
    {push(s1,89);push(s2,171);}
#line 3416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 827 "parser.y" /* yacc.c:1646  */
    {push(s1,90);push(s2,172);}
#line 3422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 828 "parser.y" /* yacc.c:1646  */
    {push(s1,90);push(s2,173);}
#line 3428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 831 "parser.y" /* yacc.c:1646  */
    {push(s1,91);push(s2,174);}
#line 3434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 832 "parser.y" /* yacc.c:1646  */
    {push(s1,91);push(s2,175);}
#line 3440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 833 "parser.y" /* yacc.c:1646  */
    {push(s1,91);push(s2,176);}
#line 3446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 834 "parser.y" /* yacc.c:1646  */
    {push(s1,91);push(s2,177);}
#line 3452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 835 "parser.y" /* yacc.c:1646  */
    {push(s1,91);push(s2,178);}
#line 3458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 838 "parser.y" /* yacc.c:1646  */
    {push(s1,92);push(s2,179);}
#line 3464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 841 "parser.y" /* yacc.c:1646  */
    {push(s1,93);push(s2,180);}
#line 3470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 844 "parser.y" /* yacc.c:1646  */
    {push(s1,94);push(s2,181);}
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 845 "parser.y" /* yacc.c:1646  */
    {push(s1,94);push(s2,182);}
#line 3482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 846 "parser.y" /* yacc.c:1646  */
    {push(s1,94);push(s2,183);}
#line 3488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 849 "parser.y" /* yacc.c:1646  */
    {push(s1,95);push(s2,184);}
#line 3494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 852 "parser.y" /* yacc.c:1646  */
    {push(s1,96);push(s2,185);}
#line 3500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 855 "parser.y" /* yacc.c:1646  */
    {push(s1,97);push(s2,186);}
#line 3506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 856 "parser.y" /* yacc.c:1646  */
    {push(s1,97);push(s2,187);}
#line 3512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 857 "parser.y" /* yacc.c:1646  */
    {push(s1,97);push(s2,188);}
#line 3518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 858 "parser.y" /* yacc.c:1646  */
    {push(s1,97);push(s2,189);}
#line 3524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 861 "parser.y" /* yacc.c:1646  */
    {push(s1,98);push(s2,190);}
#line 3530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 862 "parser.y" /* yacc.c:1646  */
    {push(s1,98);push(s2,191);}
#line 3536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 863 "parser.y" /* yacc.c:1646  */
    {push(s1,98);push(s2,192);}
#line 3542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 866 "parser.y" /* yacc.c:1646  */
    {push(s1,99);push(s2,193);}
#line 3548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 867 "parser.y" /* yacc.c:1646  */
    {push(s1,99);push(s2,194);}
#line 3554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 870 "parser.y" /* yacc.c:1646  */
    {push(s1,100);push(s2,195);}
#line 3560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 871 "parser.y" /* yacc.c:1646  */
    {push(s1,100);push(s2,196);}
#line 3566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 874 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,197);}
#line 3572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 875 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,198);}
#line 3578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 876 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,199);}
#line 3584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 877 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,200);}
#line 3590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 878 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,201);}
#line 3596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 879 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,202);}
#line 3602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 880 "parser.y" /* yacc.c:1646  */
    {push(s1,101);push(s2,203);}
#line 3608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 883 "parser.y" /* yacc.c:1646  */
    {push(s1,102);push(s2,204);}
#line 3614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 886 "parser.y" /* yacc.c:1646  */
    {push(s1,103);push(s2,205);}
#line 3620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 887 "parser.y" /* yacc.c:1646  */
    {push(s1,103);push(s2,0);}
#line 3626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 890 "parser.y" /* yacc.c:1646  */
    {push(s1,104);push(s2,206);}
#line 3632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 891 "parser.y" /* yacc.c:1646  */
    {push(s1,104);push(s2,207);}
#line 3638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 894 "parser.y" /* yacc.c:1646  */
    {push(s1,105);push(s2,208);}
#line 3644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 895 "parser.y" /* yacc.c:1646  */
    {push(s1,105);push(s2,209);}
#line 3650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 898 "parser.y" /* yacc.c:1646  */
    {push(s1,106);push(s2,210);}
#line 3656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 899 "parser.y" /* yacc.c:1646  */
    {push(s1,106);push(s2,211);}
#line 3662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 902 "parser.y" /* yacc.c:1646  */
    {push(s1,107);push(s2,212);}
#line 3668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 903 "parser.y" /* yacc.c:1646  */
    {push(s1,107);push(s2,213);}
#line 3674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 906 "parser.y" /* yacc.c:1646  */
    {push(s1,108);push(s2,214);}
#line 3680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 909 "parser.y" /* yacc.c:1646  */
    {push(s1,109);push(s2,215);}
#line 3686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 910 "parser.y" /* yacc.c:1646  */
    {push(s1,109);push(s2,216);}
#line 3692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 913 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,217);}
#line 3698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 914 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,218);}
#line 3704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 915 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,219);}
#line 3710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 916 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,220);}
#line 3716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 917 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,221);}
#line 3722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 918 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,222);}
#line 3728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 919 "parser.y" /* yacc.c:1646  */
    {push(s1,110);push(s2,223);}
#line 3734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 922 "parser.y" /* yacc.c:1646  */
    {push(s1,111);push(s2,224);}
#line 3740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 923 "parser.y" /* yacc.c:1646  */
    {push(s1,111);push(s2,225);}
#line 3746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 924 "parser.y" /* yacc.c:1646  */
    {push(s1,111);push(s2,226);}
#line 3752 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3756 "y.tab.c" /* yacc.c:1646  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 927 "parser.y" /* yacc.c:1906  */

struct StackStr* str4;
int main(int argc, char** argv){
	s1 = createIntStack();
	s2 = createIntStack();
         str1 = createCharStack();
         str2= createCharStack();
         str4= createCharStack();
	FILE *fptr = fopen(argv[1], "r");
	FILE *out = fopen("out.html", "a");

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
        printCode();
	//printf("$$$$%d$$$$\n",s1->size);
	return 0;
}

void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}
void printCode()
{
	char c[50],b[100],a[50];
	char final[10][100];
	int i=0; 
	//	struct StackStr* str1 = createCharStack();
	//	struct StackStr* str2= createCharStack();
	pushStr(str1,find1(pop(s1)));
	while(!isEmptyStr(str1))
	{
		while(!isEmptyStr(str1))
		{
		//	final[i]=popStr(str1);
                        strcpy(final[i],popStr(str1)); 
			i++;
		}
		while(i>0)
		{
			printf("%s ",final[--i]);
			pushStr(str1,final[i]);
		}
		printf("\n");
		char * aw=popStr(str1);
		while(isupper(c[0]) && (!isEmptyStr(str1)))
		{
			pushStr(str2,c);          
			strcpy(c,popStr(str1));
		}
		strcpy(b,find2(pop(s2)));
		char *token = (char*)malloc(50*sizeof(char));
		char* rest=b;
		while ((token = strtok_r(rest," ",&rest)))
		{
			pushStr(str1,token);
                      //  printf(" token = %s ",token); 
		}
		free(token); 
	} 
}
void printStack(struct StackStr* str3)
{
	char c1[100];
	struct StackStr* str4 = createCharStack();
	while(!isEmptyStr(str3))
	{
		pushStr(str4,popStr(str3));
             
	}
	while(!isEmptyStr(str4))
	{
		strcpy(c1,popStr(str4));
		printf("%s ",c1);
		pushStr(str3,c1);
	}
	printf("\n");
}
