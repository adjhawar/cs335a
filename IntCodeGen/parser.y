%{
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
%}

%locations

%union{
	int ival;
	char *sval;
	float fval;
	char *type;
	struct Attr *attr;
}
%error-verbose
%start compilation_unit

%token CLASS INSTANCEOF NEW SUPER THIS
%token <sval>BOOL BYTE CHAR T FLOAT INT F N VOID
%token BREAK CASE DEFAULT ELSE IF SWITCH
%token CONT DO FOR WHILE
%token RETURN
%token CONST
%token <sval>CID ID
%token SEP TRM COLON
%token ARRAY_S ARRAY_E BLOCK_S BLOCK_E PAREN_S PAREN_E
%token OP_ASS OP_ADD_ASS OP_SUB_ASS OP_DIV_ASS OP_MUL_ASS OP_MOD_ASS OP_LSH_ASS OP_RSH_ASS OP_AND_ASS OP_OR_ASS OP_XOR_ASS OP_ZRSH_ASS
%token OP_CON_Q OP_CON_AND OP_CON_OR
%token OP_OR OP_XOR OP_AND OP_EQ OP_NEQ OP_GRE OP_LES OP_GEQ OP_LEQ OP_NEG
%token OP_RSH OP_LSH OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_INC OP_DEC OP_DOT OP_ZRSH
%token <ival>INT_LIT_D INT_LIT_O INT_LIT_H
%token <fval>FLOAT_LIT
%token <sval>CHAR_LIT STR_LIT STRING
%token ERROR
%token PRINT SCAN
%token EXTENDS

%type <type>error integer_type reference_type primitive_type array_type class_type numeric_type type_name type
%type <sval>var_decl_id var_declarator 
%type <attr>var_declarators
%type <attr>assgn lhs expr identifier
%type <attr>cond_expr name array_access field_access 
%type <attr>cond_or_expr cond_and_expr incl_or_expr excl_or_expr and_expr equality_expr rel_expr shift_expr add_expr mul_expr
%type <attr>unary_expr preinc_expr predec_expr unary_expr_not_plus_minus postdec_expr postinc_expr postfix_expr cast_expr
%type <attr>primary array_creat_expr primary_no_new_array
%%

compilation_unit	: type_declarations_e 							
 			;

type_declarations_e	: type_declarations 								
			| /* empty */								
			;

type_declarations	: type_declaration 							
			| type_declarations type_declaration 					
			| error VOID						{yyerrok;}
			;

type_declaration	: class_declaration 							
			| TRM 									
			;

class_declaration	: CLASS type_name super_e class_body 					
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

field_decl		: type var_declarators TRM			
			;

var_declarators		: var_declarator 		{$$=(Attr *)malloc(sizeof(Attr));
						 strcpy($$->place,$1);
						 strcpy($$->type,$<type>0);
						 p=Insert($1,$$->type);}

			| var_declarators SEP var_declarator 			{$$=(Attr *)malloc(sizeof(Attr));
						 strcpy($$->place,$3);
						 strcpy($$->type,$<type>0);
						 p=Insert($3,$$->type);}	
			;

var_declarator		: var_decl_id 			{$$=strdup($$);}			
			| var_decl_id OP_ASS var_init 	{$$=strdup($1);}					
			;

var_decl_id		: ID 				{$$=strdup($1);}
			| var_decl_id ARRAY_S ARRAY_E 						
			;

method_decl		: method_header method_body 						
			;	

method_header		: type method_declarator 						
			;

method_declarator	: identifier PAREN_S formal_para_list_e PAREN_E 			
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

type		: primitive_type	{$$=strdup($1);} 							
		| reference_type 	{$$=strdup($1);}						
		| VOID 			{$$=strdup($1);}							
		| STRING		{$$=strdup($1);}							
		;

primitive_type  : numeric_type 	{$$=strdup($1);}						
		| BOOL 		{$$=strdup($1);}							
		;

numeric_type	: integer_type 	{$$=strdup($1);}						
		| FLOAT 	{$$=strdup($1);}						
		;

integer_type	: BYTE 	{$$=strdup($1);}		
		| CHAR 	{$$=strdup($1);}					
		| INT 	{$$=strdup($1);}					
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
		| error TRM									{yyerrok;}
		| error BLOCK_E 								{yyerrok;}
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
		| SCAN PAREN_S identifier PAREN_E						
		| PRINT PAREN_S var_inits PAREN_E						
		;

empty_st	:  TRM 										
		;

expr_st		: st_expr  TRM 								
		;

st_expr		: assgn 	{printList($1->code);}								
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

for_st		: FOR PAREN_S for_init_e TRM expr_e TRM for_update_e  PAREN_E statement	
		;

for_st_no_short_if	: FOR PAREN_S for_init_e TRM expr_e TRM for_update_e  PAREN_E st_no_short_if	
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

break_st	: BREAK TRM	
		;

continue_st	: CONT TRM	
		;

return_st	: RETURN expr_e TRM	
		;

expr		: cond_expr	
		| assgn		
		;

assgn		: lhs assgn_op expr			{switch(flag1){
						case 0:sprintf(t,"%s = %s",$1->place,$3->place);
							break;
						case 1:sprintf(t,"%s = %s * %s",$1->place,$1->place,$3->place);
							break;
						case 2:sprintf(t,"%s = %s / %s",$1->place,$1->place,$3->place);
							break;
						case 3:sprintf(t,"%s = %s %% %s",$1->place,$1->place,$3->place);
							break;
						case 4:sprintf(t,"%s = %s + %s",$1->place,$1->place,$3->place);
							break;
						case 5:sprintf(t,"%s = %s - %s",$1->place,$1->place,$3->place);
							break;
						case 6:sprintf(t,"%s = %s << %s",$1->place,$1->place,$3->place);
							break;
						case 7:sprintf(t,"%s = %s >> %s",$1->place,$1->place,$3->place);
							break;
						case 8:sprintf(t,"%s = %s >>> %s",$1->place,$1->place,$3->place);
							break;
						case 9:sprintf(t,"%s = %s & %s",$1->place,$1->place,$3->place);
							break;
						case 10:sprintf(t,"%s = %s ^ %s",$1->place,$1->place,$3->place);
							break;
						case 11:sprintf(t,"%s = %s | %s",$1->place,$1->place,$3->place);
							break;}
						$$=$3;
						$$->code=append($3->code,newList(t));
						}	
		;

lhs		: name		{$$=$1;}
		| field_access	
		| array_access	
		;

assgn_op	: OP_ASS		{flag1=0;}	
		| OP_MUL_ASS		{flag1=1;}
		| OP_DIV_ASS		{flag1=2;}
		| OP_MOD_ASS		{flag1=3;}
		| OP_ADD_ASS		{flag1=4;}
		| OP_SUB_ASS		{flag1=5;}
		| OP_LSH_ASS		{flag1=6;}
		| OP_RSH_ASS		{flag1=7;}
		| OP_ZRSH_ASS		{flag1=8;}
		| OP_AND_ASS		{flag1=9;}
		| OP_XOR_ASS		{flag1=10;}
		| OP_OR_ASS		{flag1=11;}
		;

cond_expr	: cond_or_expr					{$$=$1;}			
		| cond_or_expr OP_CON_Q expr COLON cond_expr	
		;

cond_or_expr	: cond_and_expr					{$$=$1;}		
		| cond_or_expr OP_CON_OR cond_and_expr		{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s || %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

cond_and_expr	: incl_or_expr						{$$=$1;}
		| cond_and_expr OP_CON_AND incl_or_expr		{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s && %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

incl_or_expr	: excl_or_expr	{$$=$1;}
		| incl_or_expr OP_OR excl_or_expr		{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s | %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}			
		;

excl_or_expr	: and_expr			{$$=$1;}			
		| excl_or_expr OP_XOR and_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s ^ %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

and_expr 	: equality_expr					{$$=$1;}	
		| and_expr OP_AND equality_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s & %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

equality_expr	: rel_expr						{$$=$1;}
		| equality_expr OP_EQ rel_expr	{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					sprintf(t,"%s = %s == %s",$$->place,$1->place,$3->place);
					$$->code=append($$->code,newList(t));}
							
		| equality_expr OP_NEQ rel_expr	{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					sprintf(t,"%s = %s != %s",$$->place,$1->place,$3->place);
					$$->code=append($$->code,newList(t));}		
		;


rel_expr	: shift_expr			{$$ = $1;}
		| rel_expr OP_LES shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					sprintf(t,"%s = %s < %s",$$->place,$1->place,$3->place);
					$$->code=append($$->code,newList(t));}
							
		| rel_expr OP_GRE shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					sprintf(t,"%s = %s > %s",$$->place,$1->place,$3->place);
					$$->code=append($$->code,newList(t));}
								
		| rel_expr OP_LEQ shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					sprintf(t,"%s = %s <= %s",$$->place,$1->place,$3->place);
					$$->code=append($$->code,newList(t));}
								
		| rel_expr OP_GEQ shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					sprintf(t,"%s = %s >= %s",$$->place,$1->place,$3->place);
					$$->code=append($$->code,newList(t));}
								
		| rel_expr INSTANCEOF reference_type		
		;


shift_expr	: add_expr						{$$=$1;}
		| shift_expr OP_LSH add_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s & %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		| shift_expr OP_RSH add_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s >> %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		| shift_expr OP_ZRSH add_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s >>> %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		;


add_expr	: mul_expr						{$$=$1;}
		| add_expr OP_ADD mul_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s + %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		| add_expr OP_SUB mul_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s - %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		;
mul_expr	: unary_expr				{$$=$1;}
		| mul_expr OP_MUL unary_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s * %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		| mul_expr OP_DIV unary_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s / %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		| mul_expr OP_MOD unary_expr			{$$=(Attr *)malloc(sizeof(Attr));
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,"%s = %s %% %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

cast_expr	: PAREN_S primitive_type PAREN_E unary_expr		
		| PAREN_S reference_type PAREN_E unary_expr_not_plus_minus		
		;

unary_expr	: preinc_expr			{$$=$1;}
		| predec_expr			{$$=$1;}
		| OP_ADD unary_expr				{char temp[10];
							strcpy(temp,tempVar());
							Attr temp1=pop(attr_stack);
							sprintf(t,"%s = + %s",temp,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(temp1.place,"%s",temp);
							push(attr_stack,&temp1);
							}
		| OP_SUB unary_expr				{char temp[10];
							strcpy(temp,tempVar());
							Attr temp1=pop(attr_stack);
							sprintf(t,"%s = - %s",temp,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(temp1.place,"%s",temp);
							push(attr_stack,&temp1);
							}
		| unary_expr_not_plus_minus	
		;

preinc_expr	: OP_INC unary_expr				{Attr temp1=pop(attr_stack);
							sprintf(t,"%s = %s + 1",temp1.place,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							push(attr_stack,&temp1);
							}	
		;

predec_expr	: OP_DEC unary_expr				{Attr temp1=pop(attr_stack);
							sprintf(t,"%s = %s - 1",temp1.place,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							push(attr_stack,&temp1);
							}	
		;

unary_expr_not_plus_minus	: postfix_expr		{$$ = $1;}
				| OP_NEG unary_expr		{char temp[10];
							strcpy(temp,tempVar());
							Attr temp1=pop(attr_stack);
							sprintf(t,"%s = ! %s",temp,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(temp1.place,"%s",temp);
							push(attr_stack,&temp1);
							}	
				| cast_expr		
				;

postdec_expr	: postfix_expr OP_DEC				{Attr temp1=pop(attr_stack);
							char temp[10];
							sprintf(temp,"%s",tempVar());
							sprintf(t,"%s = %s",temp,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(t,"%s = %s - 1",temp1.place,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(temp1.place,"%s",temp);
							push(attr_stack,&temp1);
							}	
		;

postinc_expr	: postfix_expr OP_INC				{Attr temp1=pop(attr_stack);
							char temp[10];
							sprintf(temp,"%s",tempVar());
							sprintf(t,"%s = %s",temp,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(t,"%s = %s + 1",temp1.place,temp1.place);
							temp1.code=append(temp1.code,newList(t));
							sprintf(temp1.place,"%s",temp);
							push(attr_stack,&temp1);
							}							
		;

postfix_expr	: primary		
		| name			{$$=$1;}		
		| postinc_expr		
		| postdec_expr		
		;

method_invo	: name PAREN_S arg_list_e PAREN_E 		
		| primary OP_DOT identifier PAREN_S arg_list_e PAREN_E		
		| SUPER OP_DOT identifier PAREN_S arg_list_e PAREN_E		
		;

field_access	: primary OP_DOT identifier		
		| SUPER OP_DOT identifier		
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

type_name		: CID			{pushStr(lexeme,$1);}
			| error ID	
			;

name			: identifier		{$$=$1;}		
			| name OP_DOT identifier	
			;

literal			: int_literal		
			| FLOAT_LIT		{char ch[20];sprintf(ch,"%f",$1);pushStr(lexeme,ch);}
			| CHAR_LIT		{pushStr(lexeme,$1);}
			| STR_LIT		{pushStr(lexeme,$1);}
			| T			
			| F			
			| N			
			;

int_literal		: INT_LIT_H		{char ch[20];sprintf(ch,"%d",$1);pushStr(lexeme,ch);}
			| INT_LIT_O		{char ch[20];sprintf(ch,"%d",$1);pushStr(lexeme,ch);}
			| INT_LIT_D		{char ch[20];sprintf(ch,"%d",$1);pushStr(lexeme,ch);}
			;

identifier		: ID			{SymtabEntry *tempo=look_up($1);
					if(tempo!=NULL){
						$$=(Attr *)malloc(sizeof(Attr));
						strcpy($$->place,$1);
						strcpy($$->type,tempo->type);
						$$->code=NULL;
						}
					else
						yyerrok;}
			;
%%
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
