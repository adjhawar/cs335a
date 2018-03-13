%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
%}

%union
%start
%token CLASS INSTANCEOF NEW SUPER THIS
%token BOOL BYTE CHAR T FLOAT INT F N STRING VOID
%token BREAK CASE DEFAULT ELSE IF SWITCH
%token CONT DO FOR WHILE
%token RETURN
%token CONST
%token PRINT
%token SCAN
%token ID TRM SEP COLON
%token BLOCK_S BLOCK_E ARRAY_S ARRAY_E PAREN_S PAREN_E
%token OP_ADD_ASS OP_SUB_ASS OP_MUL_ASS OP_DIV_ASS OP_MOD_ASS OP_LSH_ASS OP_RSH_ASS OP_AND_ASS OP_OR_ASS OP_XOR_ASS OP_ZRSH_ASS OP_ASS
%token OP_CON_Q OP_CON_AND OP_CON_OR
%token OP_OR OP_XOR OP_AND OP_EQ OP_NEQ OP_GEQ OP_LEQ OP_GRE OP_LES OP_NEG
%token OP_RSH OP_LSH OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_INC OP_DEC OP_DOT OP_ZRSH
%token STR_LIT CHAR_LIT FLOAT_LIT INT_LIT_H INT_LIT_O INT_LIT_D 
%token IGN ERROR
%type

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
			| ';'
			;

class_declaration	: class identifier super_e class_body
			;

super_e			: supers
			| /* empty */
			;

supers			: extends class_type
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

const_declarator	: simple_type_name ( formal_para_list_e )
			;

formal_para_list_e	: formal_para_list
			| /* empty */
			;

formal_para_list	: formal_para
			| formal_para_list , formal_para
			;

formal_para		: type var_dec_id
			;

const_body		: explicit_const_invo_e	bl_statements_e
			;

explicit_const_invo_e	: explicit_const_invo
			| /* empty */
			;

explicit_const_invo	: this ( arg_list_e )
			| super ( arg_list_e )
			;

field_decl		: type var_declarators ';'
			;

var_declarators		: var_declarator
			| var_declarators , var_declarator
			;

var_declarator		: var_decl_id
			| var_decl_id = var_init
			;

var_decl_id		: idenitifier
			| var_decl_id []
			;

var_init		: expr
			| array_init
			;

method_decl		: method_header method_body
			;

method_header		: result_type method_declarator
			;

result_type		: type
			| void
			;

method_declarator	: idenitifier ( formal_para_list_e )
			;

method_body		: block
			| ';'
			;

constant_decl		: final type var_declarator
			;

var_init_e		: var_inits
			| /* empty */
			;

var_inits		: var_init
			| var_inits , var_init
			;

var_init		: expr

type		: primitive_type
		| reference_type
		;

primitive_type  : numeric_type
		| boolean
		;

numeric_type	: integer_type
		| float
		;

integer_type	: byte
		| char
		| int
		;

reference_type	: class_type
		| array_type
		;

class_type	: type_name
		;

array_type	: type []
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

loc_var_dec_st	: loc_var_dec ';'
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

empty_st	: ';'
		;

expr_st		: st_expr ';'
		;

st_expr		: assignment
		| preinc_expr
		| postinc_expr
		| predec_expr
		| postdec_expr
		| method_invo
		| object_expr
		;

if_then_st	: if ( expr ) statement
		;

if_then_else_st	: if ( expr ) st_no_short_if else statement
		;

if_then_else_no_short_if_st	: if ( expr ) st_no_short_if else st_no_short_if
		;

switch_st	: switch ( expr ) switch_block
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

switch_label	: case const_expr':'
		| default':'
		;

while_st	: while ( expr ) statement
		;

while_st_no_short_if	: while ( expr ) st_no_short_if
			;

do_st		: do statement while ( expr ) ';'
		;

for_st		: for( for_init_e ';' expr_e ';' for_update_e ';') statement
		;

for_st_no_short_if	: for( for_init_e ';' expr_e ';' for_update_e ';') st_no_short_if
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
		| st_expr_list , st_expr
		;

break_st	: break ';'
		;

continue_st	: continue ';'
		;

return_st	: return expr_e ';'
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

assgn_op	: =
		| *=
		| /=
		| %=
		| +=
		| -=
		| <<=
		| >>=
		| >>>=
		| &=
		| ^=
		| '|'=
		;

cond_expr	: cond_or_expr
		| cond_or_expr ? expr : cond_expr
		;

cond_or_expr	: cond_and_expr
		| cond_or_expr '|''|' cond_and_expr
		;

cond_and_expr	: incl_or_expr
		| cond_and_expr && incl_or_expr
		;

incl_or_expr	: excl_or_expr
		;

excl_or_expr	: and_expr
		| excl_or_expr ^ and_expr
		;

and_expr 	: equality_expr
		| and_expr & equality_expr
		;

equality_expr	: rel_expr
		| equality_expr == rel_expr
		| equality_expr != rel_expr
		;

rel_expr	: shift_expr
		| rel_expr < shift_expr
		| rel_expr > shift_expr
		| rel_expr <= shift_expr
		| rel_expr >= shift_expr
		| rel_expr instanceof reference_type
		;

shift_expr	: add_expr
		| shift_expr << add_expr
		| shift_expr >> add_expr
		| shift_expr >>> add_expr
		;

add_expr	: mul_expr
		| add_expr + mul_expr
		| add_expr - mul_expr
		;

mul_expr	: unary_expr
		| mul_expr * unary_expr
		| mul_expr / unary_expr
		| mul_expr % unary_expr
		;

cast_expr	: ( primitive_type ) unary_expr
		| ( reference_type ) unary_expr_not_plus_minus
		;

unary_expr	: preinc_expr
		| predec_expr
		| + unary_expr
		| - unary_expr
		| unary_expr_not_plus_minus
		;

preinc_expr	: ++ unary_expr
		;

predec_expr	: -- unary_expr
		;

unary_expr_not_plus_minus	: postfix_expr
				| unary_expr
				| ! unary_expr
				| cast_expr
				;

postdec_expr	: postfix_expr --
		;

postinc_expr	: postinc_expr ++
		;

postfix_expr	: primary
		| expr_name
		| postinc_expr
		| postdec_expr
		;

method_invo	: method_name ( arg_list_e ) 
		| primary . identifier ( arg_list_e )
		| super . identifier ( arg_list_e )
		;

field_access	: primary . identifier
		| super . identifier
		;

primary		: primary_no_new_array
		| array_creat_expr
		;

primary_no_new_array	: literal
			| this
			| (expr)
			| object_expr
			| field_access
			| method_invo
			| array_access
			;

object_expr	: new class_type ( arg_list_e )
		;

arg_list_e	: argument_list
		| /* empty */
		;

argument_list	: expr
		| argument_list , expr
		;

array_creat_expr	: new primitive_type dim_expr
			| new class_type dim_expr
			;

dim_expr	: [ expr ]
		| []
		;

array_access	: expr_name [ expr ]
		| primary_no_new_array [ expr ]
		;

%%
