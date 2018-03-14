%{
void yyerror (char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxsize = 10;

struct Stack{
    int size;
    int* array;
};

struct 
struct Stack* createIntStack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->maxsize = maxsize;
    stack->size = -1;
    stack->array = (int*) malloc(stack->maxsize * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack){
   return stack->size == stack->maxsize - 1; 
}
 
int isEmpty(struct Stack* stack){
   return stack->size == -1;
}

void push(struct Stack* stack, int item){
    if (isFull(stack)){
    	maxsize = 2 * maxsize;
        array = realloc(array, maxsize * sizeof(int));
    }
    stack->array[++stack->size] = item;
}

int pop(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->size--];
}
 
struct Stack *s1 = createIntStack();
struct Stack *s2 = createIntStack();

char *find1(int k){
	char *str;
	switch(k){
	case 1: strcpy(str, "compilation_unit");

	}
}

char *find2(int k){
	char *str;
	switch(k){
	case 0 : strcpy(str, "");
	case 1 : strcpy(str, "type_declarations_e");
	case 2 : strcpy(str, "type_declarations");
	case 3 : strcpy(str, "type_declaration");
	case 4 : strcpy(str, "type_declarations type_declaration");
	case 5 : strcpy(str, "class_declaration");
	case 6 : strcpy(str, "TRM");
	case 7 : strcpy(str, "CLASS CID super_e class_body");
	case 8 : strcpy(str, "supers");
	case 9 : strcpy(str, "EXTENDS class_type");
	case 10 : strcpy(str, "BLOCK_S class_body_decl_e BLOCK_E");
	case 11 : strcpy(str, "class_body_decls");
	case 12 : strcpy(str, "class_body_decl");
	case 13 : strcpy(str, "class_body_decls class_body_decl");
	case 14 : strcpy(str, "class_mem_decl");
	case 15 : strcpy(str, "const_decl");
	case 16 : strcpy(str, "field_decl");
	case 17 : strcpy(str, "method_decl");
	case 18 : strcpy(str, "const_declarator const_body");
	case 19 : strcpy(str, "type_name PAREN_S formal_para_list_e PAREN_E");
	case 20 : strcpy(str, "formal_para_list");
	case 21 : strcpy(str, "formal_para");
	case 22 : strcpy(str, "formal_para_list SEP formal_para");
	case 23 : strcpy(str, "type var_decl_id");
	case 24 : strcpy(str, "BLOCK_S explicit_const_invo bl_statements_e BLOCK_E");
	case 25 : strcpy(str, "BLOCK_S bl_statements_e BLOCK_E");
	case 26 : strcpy(str, "THIS PAREN_S arg_list_e PAREN_E");
	case 27 : strcpy(str, "SUPER PAREN_S arg_list_e PAREN_E");
	case 28 : strcpy(str, "type var_declarators  TRM");
	case 29 : strcpy(str, "var_declarator");
	case 30 : strcpy(str, "var_declarators SEP var_declarator");
	case 31 : strcpy(str, "var_decl_id");
	case 32 : strcpy(str, "var_decl_id OP_ASS var_init");
	case 33 : strcpy(str, "ID");
	case 34 : strcpy(str, "var_decl_id ARRAY_S ARRAY_E");
	case 35 : strcpy(str, "method_header method_body");
	case 36 : strcpy(str, "type method_declarator");
	case 37 : strcpy(str, "ID PAREN_S formal_para_list_e PAREN_E");
	case 38 : strcpy(str, "block");
	case 39 : strcpy(str, "TRM");
	case 40 : strcpy(str, "BLOCK_S var_init_e BLOCK_E");
	case 41 : strcpy(str, "var_inits");
	case 42 : strcpy(str, "var_init");
	case 43 : strcpy(str, "var_inits SEP var_init");
	case 44 : strcpy(str, "expr");
	case 45 : strcpy(str, "array_init");
	case 46 : strcpy(str, "primitive_type");
	case 47 : strcpy(str, "reference_type");
	case 48 : strcpy(str, "VOID");
	case 49 : strcpy(str, "numeric_type");
	case 50 : strcpy(str, "BOOL");
	case 51 : strcpy(str, "integer_type");
	case 52 : strcpy(str, "FLOAT");
	case 53 : strcpy(str, "BYTE");
	case 54 : strcpy(str, "CHAR");
	case 55 : strcpy(str, "INT");
	case 56 : strcpy(str, "class_type");
	case 57 : strcpy(str, "array_type");
	case 58 : strcpy(str, "type_name");
	case 59 : strcpy(str, "type ARRAY_S ARRAY_E");
	case 60 : strcpy(str, "BLOCK_S bl_statements_e BLOCK_E");
	case 61 : strcpy(str, "bl_statements");
	case 62 : strcpy(str, "block_statement");
	case 63 : strcpy(str, "bl_statements block_statement");
	case 64 : strcpy(str, "loc_var_dec_st");
	case 65 : strcpy(str, "statement");
	case 66 : strcpy(str, "loc_var_dec TRM");
	case 67 : strcpy(str, "type var_declarators");
	case 68 : strcpy(str, "st_wo_tsub");
	case 69 : strcpy(str, "if_then_st");
	case 70 : strcpy(str, "if_then_else_st");
	case 71 : strcpy(str, "while_st");
	case 72 : strcpy(str, "for_st");
	case 73 : strcpy(str, "st_wo_tsub");
	case 74 : strcpy(str, "if_then_else_no_short_if_st");
	case 75 : strcpy(str, "while_st_no_short_if");
	case 76 : strcpy(str, "for_st_no_short_if");
	case 77 : strcpy(str, "block");
	case 78 : strcpy(str, "empty_st");
	case 79 : strcpy(str, "expr_st");
	case 80 : strcpy(str, "switch_st");
	case 81 : strcpy(str, "do_st");
	case 82 : strcpy(str, "break_st");
	case 83 : strcpy(str, "continue_st");
	case 84 : strcpy(str, "return_st");
	case 85 : strcpy(str, "TRM");
	case 86 : strcpy(str, "st_expr TRM");
	case 87 : strcpy(str, "assgn");
	case 88 : strcpy(str, "preinc_expr");
	case 89 : strcpy(str, "postinc_expr");
	case 90 : strcpy(str, "predec_expr");
	case 91 : strcpy(str, "postdec_expr");
	case 92 : strcpy(str, "method_invo");
	case 93 : strcpy(str, "object_expr");
	case 94 : strcpy(str, "IF PAREN_S expr PAREN_E statement");
	case 95 : strcpy(str, "IF PAREN_S expr PAREN_E st_no_short_if ELSE statement");
	case 96 : strcpy(str, "IF PAREN_S expr PAREN_E st_no_short_if ELSE st_no_short_if");
	case 97 : strcpy(str, "SWITCH PAREN_S expr PAREN_E switch_block");
	case 98 : strcpy(str, "BLOCK_S switch_block_st_gr_e BLOCK_E");
	case 99 : strcpy(str, "switch_block_st_grps");
	case 100 : strcpy(str, "switch_block_st_grp");
	case 101 : strcpy(str, "switch_block_st_grps switch_block_st_grp");
	case 102 : strcpy(str, "switch_labels bl_statements");
	case 103 : strcpy(str, "switch_label");
	case 104 : strcpy(str, "switch_labels switch_label");
	case 105 : strcpy(str, "CASE expr COLON");
	case 106 : strcpy(str, "DEFAULT COLON");
	case 107 : strcpy(str, "WHILE PAREN_S expr PAREN_E statement");
	case 108 : strcpy(str, "WHILE PAREN_S expr PAREN_E st_no_short_if");
	case 109 : strcpy(str, "DO statement WHILE PAREN_S expr PAREN_E  TRM");
	case 110 : strcpy(str, "FOR PAREN_S for_init_e  TRM expr_e  TRM for_update_e  TRM PAREN_E statement");
	case 111 : strcpy(str, "FOR PAREN_S for_init_e  TRM expr_e  TRM for_update_e  TRM PAREN_E st_no_short_if");
	case 112 : strcpy(str, "for_init");
	case 113 : strcpy(str, "st_expr_list");
	case 114 : strcpy(str, "loc_var_dec");
	case 115 : strcpy(str, "expr");
	case 116 : strcpy(str, "for_update");
	case 117 : strcpy(str, "st_expr_list");
	case 118 : strcpy(str, "st_expr");
	case 119 : strcpy(str, "st_expr_list SEP st_expr");
	case 120 : strcpy(str, "BREAK TRM");
	case 121 : strcpy(str, "CONT TRM");
	case 122 : strcpy(str, "RETURN expr_e  TRM");
	case 123 : strcpy(str, "cond_expr");
	case 124 : strcpy(str, "assgn");
	case 125 : strcpy(str, "lhs assgn_op expr");
	case 126 : strcpy(str, "name");
	case 127 : strcpy(str, "field_access");
	case 128 : strcpy(str, "array_access");
	case 129 : strcpy(str, "OP_ASS");
	case 130 : strcpy(str, "OP_MUL_ASS");
	case 131 : strcpy(str, "OP_DIV_ASS");
	case 132 : strcpy(str, "OP_MOD_ASS");
	case 133 : strcpy(str, "OP_ADD_ASS");
	case 134 : strcpy(str, "OP_SUB_ASS");
	case 135 : strcpy(str, "OP_LSH_ASS");
	case 136 : strcpy(str, "OP_RSH_ASS");
	case 137 : strcpy(str, "OP_ZRSH_ASS");
	case 138 : strcpy(str, "OP_AND_ASS");
	case 139 : strcpy(str, "OP_XOR_ASS");
	case 140 : strcpy(str, "OP_OR_ASS");
	case 141 : strcpy(str, "cond_or_expr");
	case 142 : strcpy(str, "cond_or_expr OP_CON_Q expr COLON cond_expr");
	case 143 : strcpy(str, "cond_and_expr");
	case 144 : strcpy(str, "cond_or_expr OP_CON_OR cond_and_expr");
	case 145 : strcpy(str, "incl_or_expr");
	case 146 : strcpy(str, "cond_and_expr OP_CON_AND incl_or_expr");
	case 147 : strcpy(str, "excl_or_expr");
	case 148 : strcpy(str, "and_expr");
	case 149 : strcpy(str, "excl_or_expr OP_XOR and_expr");
	case 150 : strcpy(str, "equality_expr");
	case 151 : strcpy(str, "and_expr OP_AND equality_expr");
	case 152 : strcpy(str, "rel_expr");
	case 153 : strcpy(str, "equality_expr OP_EQ rel_expr");
	case 154 : strcpy(str, "equality_expr OP_NEQ rel_expr");
	case 155 : strcpy(str, "shift_expr");
	case 156 : strcpy(str, "rel_expr OP_LES shift_expr");
	case 157 : strcpy(str, "rel_expr OP_GRE shift_expr");
	case 158 : strcpy(str, "rel_expr OP_LEQ shift_expr");
	case 159 : strcpy(str, "rel_expr OP_GEQ shift_expr");
	case 160 : strcpy(str, "rel_expr INSTANCEOF reference_type");
	case 161 : strcpy(str, "add_expr");
	case 162 : strcpy(str, "shift_expr OP_LSH add_expr");
	case 163 : strcpy(str, "shift_expr OP_RSH add_expr");
	case 164 : strcpy(str, "shift_expr OP_ZRSH add_expr");
	case 165 : strcpy(str, "mul_expr");
	case 166 : strcpy(str, "add_expr OP_ADD mul_expr");
	case 167 : strcpy(str, "add_expr OP_SUB mul_expr");
	case 168 : strcpy(str, "unary_expr");
	case 169 : strcpy(str, "mul_expr OP_MUL unary_expr");
	case 170 : strcpy(str, "mul_expr OP_DIV unary_expr");
	case 171 : strcpy(str, "mul_expr OP_MOD unary_expr");
	case 172 : strcpy(str, "PAREN_S primitive_type PAREN_E unary_expr");
	case 173 : strcpy(str, "PAREN_S reference_type PAREN_E unary_expr_not_plus_minus");
	case 174 : strcpy(str, "preinc_expr");
	case 175 : strcpy(str, "predec_expr");
	case 176 : strcpy(str, "OP_ADD unary_expr");
	case 177 : strcpy(str, "OP_SUB unary_expr");
	case 178 : strcpy(str, "unary_expr_not_plus_minus");
	case 179 : strcpy(str, "OP_INC unary_expr");
	case 180 : strcpy(str, "OP_DEC unary_expr");
	case 181 : strcpy(str, "postfix_expr");
	case 182 : strcpy(str, "OP_NEG unary_expr");
	case 183 : strcpy(str, "cast_expr");
	case 184 : strcpy(str, "postfix_expr OP_DEC");
	case 185 : strcpy(str, "postfix_expr OP_INC");
	case 186 : strcpy(str, "primary");
	case 187 : strcpy(str, "name");
	case 188 : strcpy(str, "postinc_expr");
	case 189 : strcpy(str, "postdec_expr");
	case 190 : strcpy(str, "name PAREN_S arg_list_e PAREN_E ");
	case 191 : strcpy(str, "primary OP_DOT ID PAREN_S arg_list_e PAREN_E");
	case 192 : strcpy(str, "SUPER OP_DOT ID PAREN_S arg_list_e PAREN_E");
	case 193 : strcpy(str, "primary OP_DOT ID");
	case 194 : strcpy(str, "SUPER OP_DOT ID");
	case 195 : strcpy(str, "primary_no_new_array");
	case 196 : strcpy(str, "array_creat_expr");
	case 197 : strcpy(str, "literal");
	case 198 : strcpy(str, "THIS");
	case 199 : strcpy(str, "PAREN_S expr PAREN_E");
	case 200 : strcpy(str, "object_expr");
	case 201 : strcpy(str, "field_access");
	case 202 : strcpy(str, "method_invo");
	case 203 : strcpy(str, "array_access");
	case 204 : strcpy(str, "NEW class_type PAREN_S arg_list_e PAREN_E");
	case 205 : strcpy(str, "argument_list");
	case 206 : strcpy(str, "expr");
	case 207 : strcpy(str, "argument_list SEP expr");
	case 208 : strcpy(str, "NEW primitive_type dim_expr");
	case 209 : strcpy(str, "NEW class_type dim_expr");
	case 210 : strcpy(str, "ARRAY_S expr ARRAY_E");
	case 211 : strcpy(str, "ARRAY_S ARRAY_E");
	case 212 : strcpy(str, "name ARRAY_S expr ARRAY_E");
	case 213 : strcpy(str, "primary_no_new_array ARRAY_S expr ARRAY_E");
	case 214 : strcpy(str, "CID");
	case 215 : strcpy(str, "ID");
	case 216 : strcpy(str, "name OP_DOT ID");
	case 217 : strcpy(str, "int_literal");
	case 218 : strcpy(str, "FLOAT_LIT");
	case 219 : strcpy(str, "CHAR_LIT");
	case 220 : strcpy(str, "STR_LIT");
	case 221 : strcpy(str, "T");
	case 222 : strcpy(str, "F");
	case 223 : strcpy(str, "N");
	case 224 : strcpy(str, "INT_LIT_H");
	case 225 : strcpy(str, "INT_LIT_O");
	case 226 : strcpy(str, "INT_LIT_D");
	}
}
%}

%union{
	int ival;
	char *sval;
	float fval;
}

%start compilation_unit

%token CLASS INSTANCEOF NEW SUPER THIS
%token BOOL BYTE CHAR T FLOAT INT F N VOID
%token BREAK CASE DEFAULT ELSE IF SWITCH
%token CONT DO FOR WHILE
%token RETURN
%token CONST
%token CID ID SEP TRM COLON
%token ARRAY_S ARRAY_E BLOCK_S BLOCK_E PAREN_S PAREN_E
%token OP_ASS OP_ADD_ASS OP_SUB_ASS OP_DIV_ASS OP_MUL_ASS OP_MOD_ASS OP_LSH_ASS OP_RSH_ASS OP_AND_ASS OP_OR_ASS OP_XOR_ASS OP_ZRSH_ASS
%token OP_CON_Q OP_CON_AND OP_CON_OR
%token OP_OR OP_XOR OP_AND OP_EQ OP_NEQ OP_GRE OP_LES OP_GEQ OP_LEQ
%token OP_RSH OP_LSH OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_INC OP_DEC OP_DOT OP_ZRSH
%token INT_LIT_D INT_LIT_O INT_LIT_H FLOAT_LIT CHAR_LIT STR_LIT
%token ERROR IGN
%token PRINT SCAN OP_NEG STRING
%token EXTENDS

/*%type*/

%%

compilation_unit	: type_declarations_e {push(s1,1);push(s2,1);}
			;

type_declarations_e	: type_declarations
			| /* empty */
			;

type_declarations	: type_declaration
			| type_declarations type_declaration
			;

type_declaration	: class_declaration
			| TRM
			;

class_declaration	: CLASS CID super_e class_body
			;

super_e			: supers
			| /* empty */
			;

supers			: EXTENDS class_type
			;

class_body		: BLOCK_S class_body_decl_e BLOCK_E
			;

class_body_decl_e	: class_body_decls
			| /* empty */
			;

class_body_decls	: class_body_decl
			| class_body_decls class_body_decl
			;

class_body_decl		: class_mem_decl
			| const_decl
			;

class_mem_decl		: field_decl
			| method_decl
			;

const_decl		: const_declarator const_body
			;

const_declarator	: type_name PAREN_S formal_para_list_e PAREN_E
			;

formal_para_list_e	: formal_para_list
			| /* empty */
			;

formal_para_list	: formal_para
			| formal_para_list SEP formal_para
			;

formal_para		: type var_decl_id
			;

const_body		: BLOCK_S explicit_const_invo bl_statements_e BLOCK_E
			| BLOCK_S bl_statements_e BLOCK_E
			;

explicit_const_invo	: THIS PAREN_S arg_list_e PAREN_E
			| SUPER PAREN_S arg_list_e PAREN_E
			;

field_decl		: type var_declarators  TRM
			;

var_declarators		: var_declarator
			| var_declarators SEP var_declarator
			;

var_declarator		: var_decl_id
			| var_decl_id OP_ASS var_init
			;

var_decl_id		: ID
			| var_decl_id ARRAY_S ARRAY_E
			;

method_decl		: method_header method_body
			;

method_header		: type method_declarator
			;

method_declarator	: ID PAREN_S formal_para_list_e PAREN_E
			;

method_body		: block
			| TRM
			;

array_init		: BLOCK_S var_init_e BLOCK_E
			;

var_init_e		: var_inits
			| /* empty */
			;

var_inits		: var_init
			| var_inits SEP var_init
			;

var_init		: expr
			| array_init
			;

type		: primitive_type
		| reference_type
		| VOID
		;

primitive_type  : numeric_type
		| BOOL
		;

numeric_type	: integer_type
		| FLOAT
		;

integer_type	: BYTE
		| CHAR
		| INT
		;

reference_type	: class_type
		| array_type
		;

class_type	: type_name
		;

array_type	: type ARRAY_S ARRAY_E
		;

block		: BLOCK_S bl_statements_e BLOCK_E
		;

bl_statements_e	: bl_statements
		| /* empty */
		;

bl_statements	: block_statement
		| bl_statements block_statement
		;

block_statement	: loc_var_dec_st
		| statement
		;

loc_var_dec_st	: loc_var_dec TRM
		;

loc_var_dec	: type var_declarators
		;

statement	: st_wo_tsub
		| if_then_st
		| if_then_else_st
		| while_st
		| for_st
		;

st_no_short_if	: st_wo_tsub
		| if_then_else_no_short_if_st
		| while_st_no_short_if
		| for_st_no_short_if
		;

st_wo_tsub	: block
		| empty_st
		| expr_st
		| switch_st
		| do_st
		| break_st
		| continue_st
		| return_st
		;

empty_st	:  TRM
		;

expr_st		: st_expr  TRM
		;

st_expr		: assgn
		| preinc_expr
		| postinc_expr
		| predec_expr
		| postdec_expr
		| method_invo
		| object_expr
		;

if_then_st	: IF PAREN_S expr PAREN_E statement
		;

if_then_else_st	: IF PAREN_S expr PAREN_E st_no_short_if ELSE statement
		;

if_then_else_no_short_if_st	: IF PAREN_S expr PAREN_E st_no_short_if ELSE st_no_short_if
		;

switch_st	: SWITCH PAREN_S expr PAREN_E switch_block
		;

switch_block	: BLOCK_S switch_block_st_gr_e BLOCK_E
		;

switch_block_st_gr_e	: switch_block_st_grps
			| /* empty */
			;

switch_block_st_grps	: switch_block_st_grp
			| switch_block_st_grps switch_block_st_grp
			;

switch_block_st_grp	: switch_labels bl_statements
			;

switch_labels	: switch_label
		| switch_labels switch_label
		;

switch_label	: CASE expr COLON
		| DEFAULT COLON
		;

while_st	: WHILE PAREN_S expr PAREN_E statement
		;

while_st_no_short_if	: WHILE PAREN_S expr PAREN_E st_no_short_if
			;

do_st		: DO statement WHILE PAREN_S expr PAREN_E  TRM
		;

for_st		: FOR PAREN_S for_init_e  TRM expr_e  TRM for_update_e  TRM PAREN_E statement
		;

for_st_no_short_if	: FOR PAREN_S for_init_e  TRM expr_e  TRM for_update_e  TRM PAREN_E st_no_short_if
		;

for_init_e	: for_init
		| /* empty */
		;

for_init	: st_expr_list
		| loc_var_dec
		;

expr_e		: expr
		| /* empty */
		;

for_update_e	: for_update
		| /* empty */
		;

for_update	: st_expr_list
		;

st_expr_list	: st_expr
		| st_expr_list SEP st_expr
		;

break_st	: BREAK  TRM
		;

continue_st	: CONT  TRM
		;

return_st	: RETURN expr_e  TRM
		;

expr		: cond_expr
		| assgn
		;

assgn		: lhs assgn_op expr
		;

lhs		: name
		| field_access
		| array_access
		;

assgn_op	: OP_ASS
		| OP_MUL_ASS
		| OP_DIV_ASS
		| OP_MOD_ASS
		| OP_ADD_ASS
		| OP_SUB_ASS
		| OP_LSH_ASS
		| OP_RSH_ASS
		| OP_ZRSH_ASS
		| OP_AND_ASS
		| OP_XOR_ASS
		| OP_OR_ASS
		;

cond_expr	: cond_or_expr
		| cond_or_expr OP_CON_Q expr COLON cond_expr
		;

cond_or_expr	: cond_and_expr
		| cond_or_expr OP_CON_OR cond_and_expr
		;

cond_and_expr	: incl_or_expr
		| cond_and_expr OP_CON_AND incl_or_expr
		;

incl_or_expr	: excl_or_expr
		;

excl_or_expr	: and_expr
		| excl_or_expr OP_XOR and_expr
		;

and_expr 	: equality_expr
		| and_expr OP_AND equality_expr
		;

equality_expr	: rel_expr
		| equality_expr OP_EQ rel_expr
		| equality_expr OP_NEQ rel_expr
		;

rel_expr	: shift_expr
		| rel_expr OP_LES shift_expr
		| rel_expr OP_GRE shift_expr
		| rel_expr OP_LEQ shift_expr
		| rel_expr OP_GEQ shift_expr
		| rel_expr INSTANCEOF reference_type
		;

shift_expr	: add_expr
		| shift_expr OP_LSH add_expr
		| shift_expr OP_RSH add_expr
		| shift_expr OP_ZRSH add_expr
		;

add_expr	: mul_expr
		| add_expr OP_ADD mul_expr
		| add_expr OP_SUB mul_expr
		;

mul_expr	: unary_expr
		| mul_expr OP_MUL unary_expr
		| mul_expr OP_DIV unary_expr
		| mul_expr OP_MOD unary_expr
		;

cast_expr	: PAREN_S primitive_type PAREN_E unary_expr
		| PAREN_S reference_type PAREN_E unary_expr_not_plus_minus
		;

unary_expr	: preinc_expr
		| predec_expr
		| OP_ADD unary_expr
		| OP_SUB unary_expr
		| unary_expr_not_plus_minus
		;

preinc_expr	: OP_INC unary_expr
		;

predec_expr	: OP_DEC unary_expr
		;

unary_expr_not_plus_minus	: postfix_expr
				| OP_NEG unary_expr
				| cast_expr
				;

postdec_expr	: postfix_expr OP_DEC
		;

postinc_expr	: postfix_expr OP_INC
		;

postfix_expr	: primary
		| name
		| postinc_expr
		| postdec_expr
		;

method_invo	: name PAREN_S arg_list_e PAREN_E 
		| primary OP_DOT ID PAREN_S arg_list_e PAREN_E
		| SUPER OP_DOT ID PAREN_S arg_list_e PAREN_E
		;

field_access	: primary OP_DOT ID
		| SUPER OP_DOT ID
		;

primary		: primary_no_new_array
		| array_creat_expr
		;

primary_no_new_array	: literal
			| THIS
			| PAREN_S expr PAREN_E
			| object_expr
			| field_access
			| method_invo
			| array_access
			;

object_expr	: NEW class_type PAREN_S arg_list_e PAREN_E
		;

arg_list_e	: argument_list
		| /* empty */
		;

argument_list	: expr
		| argument_list SEP expr
		;

array_creat_expr	: NEW primitive_type dim_expr
			| NEW class_type dim_expr
			;

dim_expr	: ARRAY_S expr ARRAY_E
		| ARRAY_S ARRAY_E
		;

array_access	: name ARRAY_S expr ARRAY_E
		| primary_no_new_array ARRAY_S expr ARRAY_E
		;

type_name		: CID
			;

name			: ID
			| name OP_DOT ID
			;

literal			: int_literal
			| FLOAT_LIT
			| CHAR_LIT
			| STR_LIT
			| T
			| F
			| N
			;

int_literal		: INT_LIT_H
			| INT_LIT_O
			| INT_LIT_D
			;

%%

int main(int argc, char** argv){
	FILE *fptr = fopen(argv[1], 'r');
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
	return 0;
}

void yyerror(char *s) {
	fprintf (stderr, "%s\n", s);
} 
