%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
FILE *out;
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
	case 81: strcpy(str, "cond_and_expr"); break;
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
	case 112: strcpy(str, "identifier");	break;
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
	case 6 : strcpy(str, ";"); break;
	case 7 : strcpy(str, "class type_name super_e class_body"); break;
	case 8 : strcpy(str, "supers"); break;
	case 9 : strcpy(str, "extends class_type"); break;
	case 10 : strcpy(str, "{ class_body_decl_e }"); break;
	case 11 : strcpy(str, "class_body_decls"); break;
	case 12 : strcpy(str, "class_body_decl"); break;
	case 13 : strcpy(str, "class_body_decls class_body_decl"); break;
	case 14 : strcpy(str, "class_mem_decl"); break;
	case 15 : strcpy(str, "const_decl"); break;
	case 16 : strcpy(str, "field_decl"); break;
	case 17 : strcpy(str, "method_decl"); break;
	case 18 : strcpy(str, "const_declarator const_body"); break;
	case 19 : strcpy(str, "type_name ( formal_para_list_e )"); break;
	case 20 : strcpy(str, "formal_para_list"); break;
	case 21 : strcpy(str, "formal_para"); break;
	case 22 : strcpy(str, "formal_para_list , formal_para"); break;
	case 23 : strcpy(str, "type var_decl_id"); break;
	case 24 : strcpy(str, "{ explicit_const_invo bl_statements_e }"); break;
	case 25 : strcpy(str, "{ bl_statements_e }"); break;
	case 26 : strcpy(str, "this ( arg_list_e )"); break;
	case 27 : strcpy(str, "super ( arg_list_e )"); break;
	case 28 : strcpy(str, "type var_declarators  ;"); break;
	case 29 : strcpy(str, "var_declarator"); break;
	case 30 : strcpy(str, "var_declarators , var_declarator"); break;
	case 31 : strcpy(str, "var_decl_id"); break;
	case 32 : strcpy(str, "var_decl_id = var_init"); break;
	case 33 : strcpy(str, "identifier"); break;
	case 34 : strcpy(str, "var_decl_id [ ]"); break;
	case 35 : strcpy(str, "method_header method_body"); break;
	case 36 : strcpy(str, "type method_declarator"); break;
	case 37 : strcpy(str, "identifier ( formal_para_list_e )"); break;
	case 38 : strcpy(str, "block"); break;
	case 39 : strcpy(str, ";"); break;
	case 40 : strcpy(str, "{ var_init_e }"); break;
	case 41 : strcpy(str, "var_inits"); break;
	case 42 : strcpy(str, "var_init"); break;
	case 43 : strcpy(str, "var_inits , var_init"); break;
	case 44 : strcpy(str, "expr"); break;
	case 45 : strcpy(str, "array_init"); break;
	case 46 : strcpy(str, "primitive_type"); break;
	case 47 : strcpy(str, "reference_type"); break;
	case 48 : strcpy(str, "void"); break;
	case 49 : strcpy(str, "numeric_type"); break;
	case 50 : strcpy(str, "boolean"); break;
	case 51 : strcpy(str, "integer_type"); break;
	case 52 : strcpy(str, "float"); break;
	case 53 : strcpy(str, "byte"); break;
	case 54 : strcpy(str, "char"); break;
	case 55 : strcpy(str, "int"); break;
	case 56 : strcpy(str, "class_type"); break;
	case 57 : strcpy(str, "array_type"); break;
	case 58 : strcpy(str, "type_name"); break;
	case 59 : strcpy(str, "type [ ]"); break;
	case 60 : strcpy(str, "{ bl_statements_e }"); break;
	case 61 : strcpy(str, "bl_statements"); break;
	case 62 : strcpy(str, "block_statement"); break;
	case 63 : strcpy(str, "bl_statements block_statement"); break;
	case 64 : strcpy(str, "loc_var_dec_st"); break;
	case 65 : strcpy(str, "statement"); break;
	case 66 : strcpy(str, "loc_var_dec ;"); break;
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
	case 85 : strcpy(str, ";"); break;
	case 86 : strcpy(str, "st_expr ;"); break;
	case 87 : strcpy(str, "assgn"); break;
	case 88 : strcpy(str, "preinc_expr"); break;
	case 89 : strcpy(str, "postinc_expr"); break;
	case 90 : strcpy(str, "predec_expr"); break;
	case 91 : strcpy(str, "postdec_expr"); break;
	case 92 : strcpy(str, "method_invo"); break;
	case 93 : strcpy(str, "object_expr"); break;
	case 94 : strcpy(str, "if ( expr ) statement"); break;
	case 95 : strcpy(str, "if ( expr ) st_no_short_if else statement"); break;
	case 96 : strcpy(str, "if ( expr ) st_no_short_if else st_no_short_if"); break;
	case 97 : strcpy(str, "switch ( expr ) switch_block"); break;
	case 98 : strcpy(str, "{ switch_block_st_gr_e }"); break;
	case 99 : strcpy(str, "switch_block_st_grps"); break;
	case 100 : strcpy(str, "switch_block_st_grp"); break;
	case 101 : strcpy(str, "switch_block_st_grps switch_block_st_grp"); break;
	case 102 : strcpy(str, "switch_labels bl_statements"); break;
	case 103 : strcpy(str, "switch_label"); break;
	case 104 : strcpy(str, "switch_labels switch_label"); break;
	case 105 : strcpy(str, "case expr :"); break;
	case 106 : strcpy(str, "default :"); break;
	case 107 : strcpy(str, "while ( expr ) statement"); break;
	case 108 : strcpy(str, "while ( expr ) st_no_short_if"); break;
	case 109 : strcpy(str, "do statement while ( expr )  ;"); break;
	case 110 : strcpy(str, "for ( for_init_e  ; expr_e  ; for_update_e  ; ) statement"); break;
	case 111 : strcpy(str, "for ( for_init_e  ; expr_e  ; for_update_e  ; ) st_no_short_if"); break;
	case 112 : strcpy(str, "for_init"); break;
	case 113 : strcpy(str, "st_expr_list"); break;
	case 114 : strcpy(str, "loc_var_dec"); break;
	case 115 : strcpy(str, "expr"); break;
	case 116 : strcpy(str, "for_update"); break;
	case 117 : strcpy(str, "st_expr_list"); break;
	case 118 : strcpy(str, "st_expr"); break;
	case 119 : strcpy(str, "st_expr_list , st_expr"); break;
	case 120 : strcpy(str, "break ;"); break;
	case 121 : strcpy(str, "continue ;"); break;
	case 122 : strcpy(str, "return expr_e  ;"); break;
	case 123 : strcpy(str, "cond_expr"); break;
	case 124 : strcpy(str, "assgn"); break;
	case 125 : strcpy(str, "lhs assgn_op expr"); break;
	case 126 : strcpy(str, "name"); break;
	case 127 : strcpy(str, "field_access"); break;
	case 128 : strcpy(str, "array_access"); break;
	case 129 : strcpy(str, "="); break;
	case 130 : strcpy(str, "*="); break;
	case 131 : strcpy(str, "/="); break;
	case 132 : strcpy(str, "\%="); break;
	case 133 : strcpy(str, "+="); break;
	case 134 : strcpy(str, "-="); break;
	case 135 : strcpy(str, "<<="); break;
	case 136 : strcpy(str, ">>="); break;
	case 137 : strcpy(str, ">>>="); break;
	case 138 : strcpy(str, "&="); break;
	case 139 : strcpy(str, "^="); break;
	case 140 : strcpy(str, "|="); break;
	case 141 : strcpy(str, "cond_or_expr"); break;
	case 142 : strcpy(str, "cond_or_expr ? expr : cond_expr"); break;
	case 143 : strcpy(str, "cond_and_expr"); break;
	case 144 : strcpy(str, "cond_or_expr || cond_and_expr"); break;
	case 145 : strcpy(str, "incl_or_expr"); break;
	case 146 : strcpy(str, "cond_and_expr && incl_or_expr"); break;
	case 147 : strcpy(str, "excl_or_expr"); break;
	case 148 : strcpy(str, "and_expr"); break;
	case 149 : strcpy(str, "excl_or_expr ^ and_expr"); break;
	case 150 : strcpy(str, "equality_expr"); break;
	case 151 : strcpy(str, "and_expr & equality_expr"); break;
	case 152 : strcpy(str, "rel_expr"); break;
	case 153 : strcpy(str, "equality_expr == rel_expr"); break;
	case 154 : strcpy(str, "equality_expr != rel_expr"); break;
	case 155 : strcpy(str, "shift_expr"); break;
	case 156 : strcpy(str, "rel_expr < shift_expr"); break;
	case 157 : strcpy(str, "rel_expr > shift_expr"); break;
	case 158 : strcpy(str, "rel_expr <= shift_expr"); break;
	case 159 : strcpy(str, "rel_expr >= shift_expr"); break;
	case 160 : strcpy(str, "rel_expr instanceof reference_type"); break;
	case 161 : strcpy(str, "add_expr"); break;
	case 162 : strcpy(str, "shift_expr << add_expr"); break;
	case 163 : strcpy(str, "shift_expr >> add_expr"); break;
	case 164 : strcpy(str, "shift_expr >>> add_expr"); break;
	case 165 : strcpy(str, "mul_expr"); break;
	case 166 : strcpy(str, "add_expr + mul_expr"); break;
	case 167 : strcpy(str, "add_expr - mul_expr"); break;
	case 168 : strcpy(str, "unary_expr"); break;
	case 169 : strcpy(str, "mul_expr * unary_expr"); break;
	case 170 : strcpy(str, "mul_expr / unary_expr"); break;
	case 171 : strcpy(str, "mul_expr \% unary_expr"); break;
	case 172 : strcpy(str, "( primitive_type ) unary_expr"); break;
	case 173 : strcpy(str, "( reference_type ) unary_expr_not_plus_minus"); break;
	case 174 : strcpy(str, "preinc_expr"); break;
	case 175 : strcpy(str, "predec_expr"); break;
	case 176 : strcpy(str, "+ unary_expr"); break;
	case 177 : strcpy(str, "- unary_expr"); break;
	case 178 : strcpy(str, "unary_expr_not_plus_minus"); break;
	case 179 : strcpy(str, "++ unary_expr"); break;
	case 180 : strcpy(str, "-- unary_expr"); break;
	case 181 : strcpy(str, "postfix_expr"); break;
	case 182 : strcpy(str, "! unary_expr"); break;
	case 183 : strcpy(str, "cast_expr"); break;
	case 184 : strcpy(str, "postfix_expr --"); break;
	case 185 : strcpy(str, "postfix_expr ++"); break;
	case 186 : strcpy(str, "primary"); break;
	case 187 : strcpy(str, "name"); break;
	case 188 : strcpy(str, "postinc_expr"); break;
	case 189 : strcpy(str, "postdec_expr"); break;
	case 190 : strcpy(str, "name ( arg_list_e ) "); break;
	case 191 : strcpy(str, "primary . identifier ( arg_list_e )"); break;
	case 192 : strcpy(str, "super . identifier ( arg_list_e )"); break;
	case 193 : strcpy(str, "primary . identifier"); break;
	case 194 : strcpy(str, "super . identifier"); break;
	case 195 : strcpy(str, "primary_no_new_array"); break;
	case 196 : strcpy(str, "array_creat_expr"); break;
	case 197 : strcpy(str, "literal"); break;
	case 198 : strcpy(str, "this"); break;
	case 199 : strcpy(str, "( expr )"); break;
	case 200 : strcpy(str, "object_expr"); break;
	case 201 : strcpy(str, "field_access"); break;
	case 202 : strcpy(str, "method_invo"); break;
	case 203 : strcpy(str, "array_access"); break;
	case 204 : strcpy(str, "new class_type ( arg_list_e )"); break;
	case 205 : strcpy(str, "argument_list"); break;
	case 206 : strcpy(str, "expr"); break;
	case 207 : strcpy(str, "argument_list , expr"); break;
	case 208 : strcpy(str, "new primitive_type dim_expr"); break;
	case 209 : strcpy(str, "new class_type dim_expr"); break;
	case 210 : strcpy(str, "[ expr ]"); break;
	case 211 : strcpy(str, "[ ]"); break;
	case 212 : strcpy(str, "name [ expr ]"); break;
	case 213 : strcpy(str, "primary_no_new_array [ expr ]"); break;
	case 214 : strcpy(str, popStr(lexeme)); break;
	case 215 : strcpy(str, "identifier"); break;
	case 216 : strcpy(str, "name . identifier"); break;
	case 217 : strcpy(str, "int_literal"); break;
	case 218 : strcpy(str, popStr(lexeme)); break;
	case 219 : strcpy(str, popStr(lexeme)); break;
	case 220 : strcpy(str, popStr(lexeme)); break;
	case 221 : strcpy(str, "true"); break;
	case 222 : strcpy(str, "false"); break;
	case 223 : strcpy(str, "null"); break;
	case 224 : strcpy(str, popStr(lexeme)); break;
	case 225 : strcpy(str, popStr(lexeme)); break;
	case 226 : strcpy(str, popStr(lexeme)); break;
	case 227 : strcpy(str, popStr(lexeme)); break;
	case 228 : strcpy(str, "scan ( identifier )"); break;
	case 229 : strcpy(str, "print ( var_inits )"); break;
	}
	return str;
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
%token <sval>CID ID
%token SEP TRM COLON
%token ARRAY_S ARRAY_E BLOCK_S BLOCK_E PAREN_S PAREN_E
%token OP_ASS OP_ADD_ASS OP_SUB_ASS OP_DIV_ASS OP_MUL_ASS OP_MOD_ASS OP_LSH_ASS OP_RSH_ASS OP_AND_ASS OP_OR_ASS OP_XOR_ASS OP_ZRSH_ASS
%token OP_CON_Q OP_CON_AND OP_CON_OR
%token OP_OR OP_XOR OP_AND OP_EQ OP_NEQ OP_GRE OP_LES OP_GEQ OP_LEQ
%token OP_RSH OP_LSH OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_INC OP_DEC OP_DOT OP_ZRSH
%token <ival>INT_LIT_D INT_LIT_O INT_LIT_H
%token <fval>FLOAT_LIT
%token <sval>CHAR_LIT STR_LIT
%token ERROR
%token PRINT SCAN OP_NEG STRING
%token EXTENDS

/*%type*/

%%

compilation_unit	: type_declarations_e 							{push(s1,1);push(s2,1);}
			;

type_declarations_e	: type_declarations 							{push(s1,2);push(s2,2);}	
			| /* empty */								{push(s1,2);push(s2,0);}
			;

type_declarations	: type_declaration 							{push(s1,3);push(s2,3);}
			| type_declarations type_declaration 					{push(s1,3);push(s2,4);}
			;

type_declaration	: class_declaration 							{push(s1,4);push(s2,5);}
			| TRM 									{push(s1,4);push(s2,6);}
			;

class_declaration	: CLASS type_name super_e class_body 						{push(s1,5);push(s2,7);}
			;

super_e			: supers 								{push(s1,6);push(s2,8);}
			| /* empty */								{push(s1,6);push(s2,0);}
			;

supers			: EXTENDS class_type 							{push(s1,7);push(s2,9);}
			;

class_body		: BLOCK_S class_body_decl_e BLOCK_E 					{push(s1,8);push(s2,10);}
			;

class_body_decl_e	: class_body_decls 							{push(s1,9);push(s2,11);}
			| /* empty */ 								{push(s1,9);push(s2,0);}
			;

class_body_decls	: class_body_decl 							{push(s1,10);push(s2,12);}
			| class_body_decls class_body_decl 					{push(s1,10);push(s2,13);}
			;

class_body_decl		: class_mem_decl 							{push(s1,11);push(s2,14);}
			| const_decl 								{push(s1,11);push(s2,15);}
			;

class_mem_decl		: field_decl 								{push(s1,12);push(s2,16);}
			| method_decl 								{push(s1,12);push(s2,17);}
			;

const_decl		: const_declarator const_body						{push(s1,13);push(s2,18);}
			;

const_declarator	: type_name PAREN_S formal_para_list_e PAREN_E 				{push(s1,14);push(s2,19);}
			;

formal_para_list_e	: formal_para_list 							{push(s1,15);push(s2,20);}
			| /* empty */								{push(s1,15);push(s2,0);}
			;

formal_para_list	: formal_para 								{push(s1,16);push(s2,21);}
			| formal_para_list SEP formal_para 					{push(s1,16);push(s2,22);}
			;

formal_para		: type var_decl_id							{push(s1,17);push(s2,23);}
			;

const_body		: BLOCK_S explicit_const_invo bl_statements_e BLOCK_E 			{push(s1,18);push(s2,24);}
			| BLOCK_S bl_statements_e BLOCK_E 					{push(s1,18);push(s2,25);}
			;

explicit_const_invo	: THIS PAREN_S arg_list_e PAREN_E					{push(s1,19);push(s2,26);}
			| SUPER PAREN_S arg_list_e PAREN_E					{push(s1,19);push(s2,27);}
			;

field_decl		: type var_declarators  TRM 						{push(s1,20);push(s2,28);}
			;

var_declarators		: var_declarator 							{push(s1,21);push(s2,29);}
			| var_declarators SEP var_declarator 					{push(s1,21);push(s2,30);}
			;

var_declarator		: var_decl_id 								{push(s1,22);push(s2,31);}
			| var_decl_id OP_ASS var_init 						{push(s1,22);push(s2,32);}
			;

var_decl_id		: identifier 									{push(s1,23);push(s2,33);}
			| var_decl_id ARRAY_S ARRAY_E 						{push(s1,23);push(s2,34);}
			;

method_decl		: method_header method_body 						{push(s1,24);push(s2,35);}
			;	

method_header		: type method_declarator 						{push(s1,25);push(s2,36);}
			;

method_declarator	: identifier PAREN_S formal_para_list_e PAREN_E 				{push(s1,26);push(s2,37);}
			;

method_body		: block 								{push(s1,27);push(s2,38);}
			| TRM 									{push(s1,27);push(s2,39);}
			;

array_init		: BLOCK_S var_init_e BLOCK_E 						{push(s1,28);push(s2,40);}
			;

var_init_e		: var_inits 								{push(s1,29);push(s2,41);}
			| /* empty */								{push(s1,29);push(s2,0);}
			;

var_inits		: var_init 								{push(s1,30);push(s2,42);}
			| var_inits SEP var_init 					{push(s1,30);push(s2,43);}
			;

var_init		: expr 									{push(s1,31);push(s2,44);}
			| array_init 								{push(s1,31);push(s2,45);}
			;

type		: primitive_type 							{push(s1,32);push(s2,46);}
		| reference_type 								{push(s1,32);push(s2,47);}
		| VOID 											{push(s1,32);push(s2,48);}
		;

primitive_type  : numeric_type 							{push(s1,33);push(s2,49);}
		| BOOL 											{push(s1,33);push(s2,50);}
		;

numeric_type	: integer_type 							{push(s1,34);push(s2,51);}
		| FLOAT 										{push(s1,34);push(s2,52);}
		;

integer_type	: BYTE 									{push(s1,35);push(s2,53);}
		| CHAR 											{push(s1,35);push(s2,54);}
		| INT 											{push(s1,35);push(s2,55);}
		;

reference_type	: class_type 							{push(s1,36);push(s2,56);}
		| array_type 									{push(s1,36);push(s2,57);}
		;

class_type	: type_name									{push(s1,37);push(s2,58);}
		;

array_type	: type ARRAY_S ARRAY_E 						{push(s1,38);push(s2,59);}
		;

block		: BLOCK_S bl_statements_e BLOCK_E 			{push(s1,39);push(s2,60);}
		;

bl_statements_e	: bl_statements 						{push(s1,40);push(s2,61);}
		| /* empty */ 									{push(s1,40);push(s2,0);}
		;

bl_statements	: block_statement						{push(s1,41);push(s2,62);}
		| bl_statements block_statement 				{push(s1,41);push(s2,63);}
		;

block_statement	: loc_var_dec_st 						{push(s1,42);push(s2,64);}
		| statement 									{push(s1,42);push(s2,65);}
		;

loc_var_dec_st	: loc_var_dec TRM 						{push(s1,43);push(s2,66);}
		;

loc_var_dec	: type var_declarators 						{push(s1,44);push(s2,67);}
		;

statement	: st_wo_tsub 								{push(s1,45);push(s2,68);}
		| if_then_st 									{push(s1,45);push(s2,69);}
		| if_then_else_st 								{push(s1,45);push(s2,70);}
		| while_st 										{push(s1,45);push(s2,71);}
		| for_st 										{push(s1,45);push(s2,72);}
		;

st_no_short_if	: st_wo_tsub 							{push(s1,46);push(s2,73);}
		| if_then_else_no_short_if_st 					{push(s1,46);push(s2,74);}
		| while_st_no_short_if 							{push(s1,46);push(s2,75);}
		| for_st_no_short_if 							{push(s1,46);push(s2,76);}
		;

st_wo_tsub	: block 									{push(s1,47);push(s2,77);}
		| empty_st 										{push(s1,47);push(s2,78);}
		| expr_st 										{push(s1,47);push(s2,79);}
		| switch_st 									{push(s1,47);push(s2,80);}
		| do_st 										{push(s1,47);push(s2,81);}
		| break_st 										{push(s1,47);push(s2,82);}
		| continue_st 									{push(s1,47);push(s2,83);}
		| return_st 									{push(s1,47);push(s2,84);}
		| SCAN PAREN_S identifier PAREN_E						{push(s1,47);push(s2,228);}
		| PRINT PAREN_S var_inits PAREN_E							{push(s1,47);push(s2,229);}
		;

empty_st	:  TRM 										{push(s1,48);push(s2,85);}
		;

expr_st		: st_expr  TRM 								{push(s1,49);push(s2,86);}
		;

st_expr		: assgn 									{push(s1,50);push(s2,87);}
		| preinc_expr 									{push(s1,50);push(s2,88);}
		| postinc_expr 									{push(s1,50);push(s2,89);}
		| predec_expr 									{push(s1,50);push(s2,90);}
		| postdec_expr 									{push(s1,50);push(s2,91);}
		| method_invo 									{push(s1,50);push(s2,92);}
		| object_expr 									{push(s1,50);push(s2,93);}
		;

if_then_st	: IF PAREN_S expr PAREN_E statement 		{push(s1,51);push(s2,94);}
		;

if_then_else_st	: IF PAREN_S expr PAREN_E st_no_short_if ELSE statement 	{push(s1,52);push(s2,95);}
		;

if_then_else_no_short_if_st	: IF PAREN_S expr PAREN_E st_no_short_if ELSE st_no_short_if  	{push(s1,53);push(s2,96);}
		;

switch_st	: SWITCH PAREN_S expr PAREN_E switch_block 	{push(s1,54);push(s2,97);}
		;

switch_block	: BLOCK_S switch_block_st_gr_e BLOCK_E 	{push(s1,55);push(s2,98);}
		;

switch_block_st_gr_e	: switch_block_st_grps 			{push(s1,56);push(s2,99);}
			| /* empty */ 								{push(s1,56);push(s2,0);}
			;

switch_block_st_grps	: switch_block_st_grp 			{push(s1,57);push(s2,100);}
			| switch_block_st_grps switch_block_st_grp 	{push(s1,57);push(s2,101);}
			;

switch_block_st_grp	: switch_labels bl_statements 		{push(s1,58);push(s2,102);}
			;

switch_labels	: switch_label 							{push(s1,59);push(s2,103);}
		| switch_labels switch_label 					{push(s1,59);push(s2,104);}
		;

switch_label	: CASE expr COLON 					{push(s1,60);push(s2,105);}
		| DEFAULT COLON 					{push(s1,60);push(s2,106);}
		;

while_st	: WHILE PAREN_S expr PAREN_E statement 			{push(s1,61);push(s2,107);}
		;

while_st_no_short_if	: WHILE PAREN_S expr PAREN_E st_no_short_if	{push(s1,62);push(s2,108);}
			;

do_st		: DO statement WHILE PAREN_S expr PAREN_E  TRM		{push(s1,63);push(s2,109);}
		;

for_st		: FOR PAREN_S for_init_e TRM expr_e TRM for_update_e TRM PAREN_E statement	{push(s1,64);push(s2,110);}
		;

for_st_no_short_if	: FOR PAREN_S for_init_e TRM expr_e TRM for_update_e TRM PAREN_E st_no_short_if	{push(s1,65);push(s2,111);}
		;

for_init_e	: for_init	{push(s1,66);push(s2,112);}
		| /* empty */	{push(s1,66);push(s2,0);}
		;

for_init	: st_expr_list	{push(s1,67);push(s2,113);}
		| loc_var_dec	{push(s1,67);push(s2,114);}
		;

expr_e		: expr		{push(s1,68);push(s2,115);}
		| /* empty */	{push(s1,68);push(s2,0);}
		;

for_update_e	: for_update	{push(s1,69);push(s2,116);}
		| /* empty */	{push(s1,69);push(s2,0);}
		;

for_update	: st_expr_list	{push(s1,70);push(s2,117);}
		;

st_expr_list	: st_expr			{push(s1,71);push(s2,118);}
		| st_expr_list SEP st_expr	{push(s1,71);push(s2,119);}
		;

break_st	: BREAK TRM	{push(s1,72);push(s2,120);}
		;

continue_st	: CONT TRM	{push(s1,73);push(s2,121);}
		;

return_st	: RETURN expr_e TRM	{push(s1,74);push(s2,122);}
		;

expr		: cond_expr	{push(s1,75);push(s2,123);}
		| assgn		{push(s1,75);push(s2,124);}
		;

assgn		: lhs assgn_op expr	{push(s1,76);push(s2,125);}
		;

lhs		: name		{push(s1,77);push(s2,126);}
		| field_access	{push(s1,77);push(s2,127);}
		| array_access	{push(s1,77);push(s2,128);}
		;

assgn_op	: OP_ASS	{push(s1,78);push(s2,129);}
		| OP_MUL_ASS	{push(s1,78);push(s2,130);}
		| OP_DIV_ASS	{push(s1,78);push(s2,131);}
		| OP_MOD_ASS	{push(s1,78);push(s2,132);}
		| OP_ADD_ASS	{push(s1,78);push(s2,133);}
		| OP_SUB_ASS	{push(s1,78);push(s2,134);}
		| OP_LSH_ASS	{push(s1,78);push(s2,135);}
		| OP_RSH_ASS	{push(s1,78);push(s2,136);}
		| OP_ZRSH_ASS	{push(s1,78);push(s2,137);}
		| OP_AND_ASS	{push(s1,78);push(s2,138);}
		| OP_XOR_ASS	{push(s1,78);push(s2,139);}
		| OP_OR_ASS	{push(s1,78);push(s2,140);}
		;

cond_expr	: cond_or_expr					{push(s1,79);push(s2,141);}
		| cond_or_expr OP_CON_Q expr COLON cond_expr	{push(s1,79);push(s2,142);}
		;

cond_or_expr	: cond_and_expr					{push(s1,80);push(s2,143);}
		| cond_or_expr OP_CON_OR cond_and_expr		{push(s1,80);push(s2,144);}
		;

cond_and_expr	: incl_or_expr					{push(s1,81);push(s2,145);}
		| cond_and_expr OP_CON_AND incl_or_expr		{push(s1,81);push(s2,146);}
		;

incl_or_expr	: excl_or_expr					{push(s1,82);push(s2,147);}
		;

excl_or_expr	: and_expr					{push(s1,83);push(s2,148);}
		| excl_or_expr OP_XOR and_expr			{push(s1,83);push(s2,149);}
		;

and_expr 	: equality_expr					{push(s1,84);push(s2,150);}
		| and_expr OP_AND equality_expr			{push(s1,84);push(s2,151);}
		;

equality_expr	: rel_expr					{push(s1,85);push(s2,152);}
		| equality_expr OP_EQ rel_expr			{push(s1,85);push(s2,153);}
		| equality_expr OP_NEQ rel_expr			{push(s1,85);push(s2,154);}
		;

rel_expr	: shift_expr					{push(s1,86);push(s2,155);}
		| rel_expr OP_LES shift_expr			{push(s1,86);push(s2,156);}
		| rel_expr OP_GRE shift_expr			{push(s1,86);push(s2,157);}
		| rel_expr OP_LEQ shift_expr			{push(s1,86);push(s2,158);}
		| rel_expr OP_GEQ shift_expr			{push(s1,86);push(s2,159);}
		| rel_expr INSTANCEOF reference_type		{push(s1,86);push(s2,160);}
		;

shift_expr	: add_expr					{push(s1,87);push(s2,161);}
		| shift_expr OP_LSH add_expr			{push(s1,87);push(s2,162);}
		| shift_expr OP_RSH add_expr			{push(s1,87);push(s2,163);}
		| shift_expr OP_ZRSH add_expr			{push(s1,87);push(s2,164);}
		;

add_expr	: mul_expr					{push(s1,88);push(s2,165);}
		| add_expr OP_ADD mul_expr			{push(s1,88);push(s2,166);}
		| add_expr OP_SUB mul_expr			{push(s1,88);push(s2,167);}
		;

mul_expr	: unary_expr			{push(s1,89);push(s2,168);}
		| mul_expr OP_MUL unary_expr		{push(s1,89);push(s2,169);}
		| mul_expr OP_DIV unary_expr		{push(s1,89);push(s2,170);}
		| mul_expr OP_MOD unary_expr		{push(s1,89);push(s2,171);}
		;

cast_expr	: PAREN_S primitive_type PAREN_E unary_expr		{push(s1,90);push(s2,172);}
		| PAREN_S reference_type PAREN_E unary_expr_not_plus_minus		{push(s1,90);push(s2,173);}
		;

unary_expr	: preinc_expr		{push(s1,91);push(s2,174);}
		| predec_expr		{push(s1,91);push(s2,175);}
		| OP_ADD unary_expr		{push(s1,91);push(s2,176);}
		| OP_SUB unary_expr		{push(s1,91);push(s2,177);}
		| unary_expr_not_plus_minus		{push(s1,91);push(s2,178);}
		;

preinc_expr	: OP_INC unary_expr		{push(s1,92);push(s2,179);}
		;

predec_expr	: OP_DEC unary_expr		{push(s1,93);push(s2,180);}
		;

unary_expr_not_plus_minus	: postfix_expr		{push(s1,94);push(s2,181);}
				| OP_NEG unary_expr		{push(s1,94);push(s2,182);}
				| cast_expr		{push(s1,94);push(s2,183);}
				;

postdec_expr	: postfix_expr OP_DEC		{push(s1,95);push(s2,184);}
		;

postinc_expr	: postfix_expr OP_INC		{push(s1,96);push(s2,185);}
		;

postfix_expr	: primary		{push(s1,97);push(s2,186);}
		| name		{push(s1,97);push(s2,187);}
		| postinc_expr		{push(s1,97);push(s2,188);}
		| postdec_expr		{push(s1,97);push(s2,189);}
		;

method_invo	: name PAREN_S arg_list_e PAREN_E 		{push(s1,98);push(s2,190);}
		| primary OP_DOT identifier PAREN_S arg_list_e PAREN_E		{push(s1,98);push(s2,191);}
		| SUPER OP_DOT identifier PAREN_S arg_list_e PAREN_E		{push(s1,98);push(s2,192);}
		;

field_access	: primary OP_DOT identifier		{push(s1,99);push(s2,193);}
		| SUPER OP_DOT identifier		{push(s1,99);push(s2,194);}
		;

primary		: primary_no_new_array		{push(s1,100);push(s2,195);}
		| array_creat_expr		{push(s1,100);push(s2,196);}
		;

primary_no_new_array	: literal		{push(s1,101);push(s2,197);}
			| THIS			{push(s1,101);push(s2,198);}
			| PAREN_S expr PAREN_E	{push(s1,101);push(s2,199);}
			| object_expr		{push(s1,101);push(s2,200);}
			| field_access		{push(s1,101);push(s2,201);}
			| method_invo		{push(s1,101);push(s2,202);}
			| array_access		{push(s1,101);push(s2,203);}
			;

object_expr	: NEW class_type PAREN_S arg_list_e PAREN_E		{push(s1,102);push(s2,204);}
		;

arg_list_e	: argument_list		{push(s1,103);push(s2,205);}
		| /* empty */		{push(s1,103);push(s2,0);}
		;

argument_list	: expr				{push(s1,104);push(s2,206);}
		| argument_list SEP expr	{push(s1,104);push(s2,207);}
		;

array_creat_expr	: NEW primitive_type dim_expr		{push(s1,105);push(s2,208);}
			| NEW class_type dim_expr		{push(s1,105);push(s2,209);}
			;

dim_expr	: ARRAY_S expr ARRAY_E		{push(s1,106);push(s2,210);}
		| ARRAY_S ARRAY_E		{push(s1,106);push(s2,211);}
		;

array_access	: name ARRAY_S expr ARRAY_E				{push(s1,107);push(s2,212);}
		| primary_no_new_array ARRAY_S expr ARRAY_E		{push(s1,107);push(s2,213);}
		;

type_name		: CID			{push(s1,108);push(s2,214);pushStr(lexeme,$1);}
			;

name			: identifier			{push(s1,109);push(s2,215);}
			| name OP_DOT identifier	{push(s1,109);push(s2,216);}
			;

literal			: int_literal		{push(s1,110);push(s2,217);}
			| FLOAT_LIT		{push(s1,110);push(s2,218);char ch[20];sprintf(ch,"%f",$1);pushStr(lexeme,ch);}
			| CHAR_LIT		{push(s1,110);push(s2,219);pushStr(lexeme,$1);}
			| STR_LIT		{push(s1,110);push(s2,220);pushStr(lexeme,$1);}
			| T			{push(s1,110);push(s2,221);}
			| F			{push(s1,110);push(s2,222);}
			| N			{push(s1,110);push(s2,223);}
			;

int_literal		: INT_LIT_H		{push(s1,111);push(s2,224);char ch[20];sprintf(ch,"%d",$1);pushStr(lexeme,ch);}
			| INT_LIT_O		{push(s1,111);push(s2,225);char ch[20];sprintf(ch,"%d",$1);pushStr(lexeme,ch);}
			| INT_LIT_D		{push(s1,111);push(s2,226);char ch[20];sprintf(ch,"%d",$1);pushStr(lexeme,ch);}
			;

identifier		: ID			{push(s1,112);push(s2,227);pushStr(lexeme,$1);}
			;
%%
struct StackStr* str4;
int main(int argc, char** argv){
	s1 = createIntStack();
	s2 = createIntStack();
	lexeme = createCharStack();
         str1 = createCharStack();
         str2= createCharStack();
         str4= createCharStack();
         push(s1,0);
	FILE *fptr = fopen(argv[1], "r");
	char ext[6];
	strcpy(ext, ".html");
	char *temp;
	char *outputfile = strtok(argv[1], ".");
	temp = strtok_r(outputfile, "/", &outputfile);
	strcat(outputfile,ext);
	out = fopen(outputfile, "w");
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
	return 0;
}

void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}
void printCode()
{
	char c[50],b[100],a[50];
	char final[200][100];
	char trav[200][100];
	int i=0,j=0;
	sprintf(a,"%s","compilation_unit");  
	pushStr(str1,a); 
	fprintf(out,"<html> <head> <title> Rightmost derivation </title> </head> <body bgcolor='#E6E6FA'> \n");
	fprintf(out,"<h2> Rightmost Derivation of the code</h2>\n");
	do
	{	
	strcpy(a,find1(pop(s1)));
		while(!isEmptyStr(str1))
		{
			strcpy(final[i],popStr(str1)); 
			i++;
		}
		while(i>0)
		{	i--;
			if(!strcmp(final[i],a)){
				fprintf(out, "<b style = color:red> %s </b>", final[i]);
			}
			else
				fprintf(out,"%s ",final[i]);
			pushStr(str1,final[i]);
		}
		fprintf(out,"</br>\n");
		while(!isEmptyStr(str1))
		{
			strcpy(trav[j],popStr(str1));
			if(strcmp(trav[j++],a)==0)
			{
				strcpy(b,find2(pop(s2)));
				char *token = (char*)malloc(50*sizeof(char));
				char* rest=b;
				while ((token = strtok_r(rest," ",&rest)))
				{
					pushStr(str1,token); 
				}
				free(token);
				break;
			} 
		}
		j--;
		while(j>0)
			pushStr(str1,final[--j]);
	}while(!isEmpty(s1)); 
	fprintf(out,"</body></html>");
}
