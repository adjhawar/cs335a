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
SymtabEntry *head,*tail, *p;
Attr* attr1;
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
%}

%locations

%union{
	int ival;
	char *sval;
	float fval;
}
%error-verbose
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

field_decl		: type var_declarators  TRM 	 {p = Insert(attr_stack->attr[attr_stack->size-1].place); 						strcpy(p->type,attr_stack->attr[attr_stack->size-2].type);}				
			;

var_declarators		: var_declarator 							
			| var_declarators SEP var_declarator 					
			;

var_declarator		: var_decl_id 								
			| var_decl_id OP_ASS var_init 						
			;

var_decl_id		: identifier 								
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

type		: primitive_type 							
		| reference_type 							
		| VOID 	{strcpy(attr->type, "void");push(attr_stack,attr);}							
		| STRING	{strcpy(attr->type, "string");push(attr_stack,attr);}							
		;

primitive_type  : numeric_type 							
		| BOOL 	{strcpy(attr->type, "bool");push(attr_stack,attr);}							
		;

numeric_type	: integer_type 							
		| FLOAT 	{strcpy(attr->type, "float");push(attr_stack,attr);}						
		;

integer_type	: BYTE 	{strcpy(attr->type, "byte");push(attr_stack,attr);}							
		| CHAR 	{strcpy(attr->type, "char");push(attr_stack,attr);}							
		| INT 	{strcpy(attr->type, "int");push(attr_stack,attr);}									
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

preinc_expr	: OP_INC unary_expr			{Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s++",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}	
		;

predec_expr	: OP_DEC unary_expr			{Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s++",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}	
		;

unary_expr_not_plus_minus	: postfix_expr		
				| OP_NEG unary_expr	{Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s++",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}	
				| cast_expr		
				;

postdec_expr	: postfix_expr OP_DEC			{Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s++",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}	
		;

postinc_expr	: postfix_expr OP_INC			{Attr *attr=(Attr *)malloc(sizeof(Attr));
						strcpy(attr->place,tempVar());
						Attr temp=pop(attr_stack);
						attr->code=append(attr->code,temp.code);
						char t[100];
						sprintf(t,"%s = %s++",attr->place,temp.place);
						attr->code=append(attr->code,newList(t));
						push(attr_stack,attr);
						free(attr);}	
		;

postfix_expr	: primary		
		| name		
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

name			: identifier			
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

identifier		: ID			{pushStr(lexeme,$1);
				  SymtabEntry *p=look_up($1);
				  Attr *attr=(Attr *)malloc(sizeof(Attr));
				  if(p!=NULL){
					  strcpy(attr->place,p->lexeme);
					  push(attr_stack,attr);
				  }else
					  yyerrok;
				  free(attr);
			  }
			;
%%
struct StackStr* str4;
int main(int argc, char** argv){
//	s1 = createIntStack();
	//s2 = createIntStack();
	lexeme = createCharStack();
    str1 = createCharStack();
    str2= createCharStack();
    str4= createCharStack();

    //push(s1,0);
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
        
       // free(s1);
       // free(s2);
        free(str1);
        free(str2);
        free(str4);
        free(lexeme);
        fclose(fptr);
        fclose(out);
	return 0;
}
