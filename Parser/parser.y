%{
void yyerror (char *s);
extern int yylex();
extern int yyparse();
extern FILE *yyin;
#include <stdio.h>
#include <stdlib.h>
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
%token ID SEP TRM COLON
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

compilation_unit	: type_declarations_e
			;

type_declarations_e	: type_declarations
			| /* empty */
			;

type_declarations	: type_declaration
			| type_declarations type_declaration
			;

type_declaration	: class_declaration
			|  TRM
			;

class_declaration	: CLASS identifier super_e class_body
			;

super_e			: supers
			| /* empty */
			;

supers			: EXTENDS class_tye
			;

class_body		: class_body_decl_e
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

const_declarator	: simple_type_name PAREN_S formal_para_list_e PAREN_E
			;

formal_para_list_e	: formal_para_list
			| /* empty */
			;

formal_para_list	: formal_para
			| formal_para_list SEP formal_para
			;

formal_para		: type var_dec_id
			;

const_body		: explicit_const_invo_e	bl_statements_e
			;

explicit_const_invo_e	: explicit_const_invo
			| /* empty */
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

var_init		: expr
			| array_init
			;

method_decl		: method_header method_body
			;

method_header		: result_type method_declarator
			;

result_type		: type
			| VOID
			;

method_declarator	: ID PAREN_S formal_para_list_e PAREN_E
			;

method_body		: block
			|  TRM
			;

constant_decl		: CONST type var_declarator
			;

var_init_e		: var_inits
			| /* empty */
			;

var_inits		: var_init
			| var_inits SEP var_init
			;

var_init		: expr

type		: primitive_type
		| reference_type
		;

primitive_type  : numeric_type
		| boolean
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

block		: bl_statements_e
		;

bl_statements_e	: block_statements
		| /* empty */
		;

bl_statements	: block_statement
		| bl_statements block_statement
		;

block_statement	: loc_var_dec_st
		| statement
		;

loc_var_dec_st	: loc_var_dec  TRM
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

st_expr		: assignment
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

switch_block	: switch_block_st_gr_e
		| labels_e
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

switch_label	: CASE const_expr COLON
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

lhs		: expr_name
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
				| unary_expr
				| OP_NEG unary_expr
				| cast_expr
				;

postdec_expr	: postfix_expr OP_DEC
		;

postinc_expr	: postinc_expr OP_INC
		;

postfix_expr	: primary
		| expr_name
		| postinc_expr
		| postdec_expr
		;

method_invo	: method_name PAREN_S arg_list_e PAREN_E 
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

array_access	: expr_name ARRAY_S expr ARRAY_E
		| primary_no_new_array ARRAY_S expr ARRAY_E
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
}

void yyerror(char *s) {
	fprintf (stderr, "%s\n", s);
} 
