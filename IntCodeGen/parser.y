%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "list.h"

extern int yylex();
extern int yyparse();
extern int yylineno;
extern FILE *yyin;
FILE *out;
void yyerror(const char *s);
char TEMP[7];
char LABEL[5];
char t[100];
int flag1;
SymtabEntry *p;
Arr_dim *h;
Symtab *mainTable,*table;

/*
	type is int:	normal variable of int type
	type is int0:	integer literal
	type is int1:	function that returns an integer value
	type is int2:	array of int type
*/
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

%type <type>error integer_type reference_type primitive_type array_type class_type numeric_type type
%type <sval>var_decl_id method_declarator type_name
%type <ival>int_literal 
%type <attr>var_declarators var_declarator formal_para method_header
%type <attr>assgn lhs expr identifier
%type <attr>cond_expr name array_access field_access 
%type <attr>cond_or_expr cond_and_expr incl_or_expr excl_or_expr and_expr equality_expr rel_expr shift_expr add_expr mul_expr
%type <attr>unary_expr preinc_expr predec_expr unary_expr_not_plus_minus postdec_expr postinc_expr postfix_expr cast_expr
%type <attr>primary array_creat_expr primary_no_new_array st_expr expr_st expr_e literal
%type <attr>block block_statement bl_statements bl_statements_e statement st_no_short_if st_wo_tsub
%type <attr>if_then_st if_then_else_st for_st while_st empty_st do_st switch_st break_st continue_st return_st
%type <attr>if_then_else_no_short_if_st while_st_no_short_if for_st_no_short_if 
%type <attr>switch_block_st_gr_e switch_block_st_grps for_init_e for_init st_expr_list loc_var_dec for_update_e for_update loc_var_dec_st
%type <attr>var_inits var_init var_init_e
%type <attr>class_body_decls class_body_decl class_body field_decl method_decl class_mem_decl method_body
%type <attr>method_invo
%type <attr> switch_block switch_block_st_grp 
%type <attr> dim_expr array_init dim_exprs
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

class_declaration	: CLASS type_name super_e class_body 			{strcpy(table->name,$2);}	
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

class_mem_decl		: field_decl 			{$$=$1;printList($1->code);}						
			| method_decl 			{$$=$1;printList($1->code);}			
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

formal_para		: type var_decl_id			{$$=(Attr *)malloc(sizeof(Attr));
						 /*strcpy($$->place,$2);
						 strcpy($$->type,$1);
						 p=Insert(table,$2,$1);*/
						 $$->code=NULL;}
			;

const_body		: BLOCK_S explicit_const_invo bl_statements_e BLOCK_E 			
			| BLOCK_S bl_statements_e BLOCK_E 					
			;

explicit_const_invo	: THIS PAREN_S arg_list_e PAREN_E					
			| SUPER PAREN_S arg_list_e PAREN_E					
			;

field_decl		: type var_declarators TRM	{$$=$2;}			
			;

var_declarators		: var_declarator 		{$$=$1;
						 strcpy($$->type,$<type>0);
						 p=Insert(table,$1->place,$$->type,$1->assign);
						 if(p==NULL){
							fprintf(stderr,"Error: Variable %s redeclared on line %d\n",$1->place,yylineno);
							exit(1);
							}}

			| var_declarators SEP var_declarator 	{$$=$1;
						 strcpy($$->type,$<type>0);
						 $$->code=append($1->code,$3->code);
						 p=Insert(table,$3->place,$$->type,$3->assign);
						 if(p==NULL){
							fprintf(stderr,"Error: Variable %s redeclared on line %d\n",$3->place,yylineno);
							exit(1);
							}}	
			;

var_declarator		: var_decl_id 			{$$=(Attr *)malloc(sizeof(Attr));
								$$->code=NULL;	
								$$->assign=false;
								strcpy($$->place,$1);}			
			| var_decl_id OP_ASS var_init 	{$$=$3;
								sprintf(t,", =, %s, %s",$1,$3->place);
								$$->code=append($$->code,newList(t));	
								$$->code=append(NULL,newList(t));
								$$->assign=true;	
								strcpy($$->place,$1);}					
			;

var_decl_id		: ID 					{$$=$1;}
			| var_decl_id ARRAY_S ARRAY_E 		{$$=$1;}					
			;

method_decl		: method_header method_body 	{$$=$2;$$->code=append($1->code,$2->code);table=table->prev;}
			;	

method_header		: type method_declarator 	{$$=(Attr *)malloc(sizeof(Attr));
								strcpy($$->place,$2);
								strcpy($$->type,$1);
				 				strcat($$->type,"1");
								sprintf(t,", label, %s",$2);
								$$->code=newList(t);
				  				p=Insert(table,$2,$$->type,true);
							if(p==NULL){
								fprintf(stderr,"Error: Variable %s redeclared on line %d\n",$2,yylineno);
								exit(1);
							}else{
								p->func=(Symtab *)malloc(sizeof(Symtab));
								p->func->prev=table;
								table=p->func;
								strcpy(table->name,$2);}}
			;

method_declarator	: ID PAREN_S formal_para_list_e PAREN_E 	{$$=$1;}			;

method_body		: block 		{$$=$1;}						
			| TRM 			{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}					
			;

array_init		: BLOCK_S var_init_e BLOCK_E 						
			;

var_init_e		: var_inits 		{$$=$1;}						
			| /* empty */		{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}					
			;

var_inits		: var_init 		{$$=$1;}						
			| var_inits SEP var_init 					
			;

var_init		: expr 			{$$=$1;}				
			| array_init 	{$$=$1;}							
			;

type		: primitive_type	{$$=$1;} 							
		| reference_type 					
		| VOID 			{$$=$1;}							
		| STRING		{$$=$1;}							
		;

primitive_type  : numeric_type 	{$$=$1;}						
		| BOOL 		{$$=$1;}							
		;

numeric_type	: integer_type 	{$$=$1;}						
		| FLOAT 	{$$=$1;}						
		;

integer_type	: BYTE 	{$$=$1;}		
		| CHAR 	{$$=$1;}					
		| INT 	{$$=$1;}					
		;

reference_type	: class_type 							
		| array_type 							
		;

class_type	: type_name							
		;

array_type	: type ARRAY_S ARRAY_E 						
		;					

block		: BLOCK_S bl_statements_e BLOCK_E 	{$$=$2;}		
		;

bl_statements_e	: bl_statements 	{$$=$1;}					
		| /* empty */ 		{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}					
		;

bl_statements	: block_statement	{$$=$1;}				
		| bl_statements block_statement 	{$1->code=append($1->code,$2->code);
							 $$=$1;}
		;

block_statement	: loc_var_dec_st 	{$$=$1;}					
		| statement 		{$$=$1;}					
		;

loc_var_dec_st	: loc_var_dec TRM 	{$$=$1;}						
		;

loc_var_dec	: type var_declarators 	{$$=$2;}		
		;

statement	: st_wo_tsub 		{$$=$1;}					
		| if_then_st 		{$$=$1;}					
		| if_then_else_st 	{$$=$1;}					
		| while_st		{$$=$1;}
		| for_st 		{$$=$1;}											
		| error TRM		{yyerrok;}
		| error BLOCK_E 	{yyerrok;}
		;

st_no_short_if	: st_wo_tsub 			{$$=$1;}						
		| if_then_else_no_short_if_st 	{$$=$1;}					
		| while_st_no_short_if 		{$$=$1;}			
		| for_st_no_short_if 		{$$=$1;}					
		;

st_wo_tsub	: block 	{$$=$1;}							
		| empty_st 	{$$=$1;}								
		| expr_st 	{$$=$1;}								
		| switch_st 	{$$=$1;}								
		| do_st 	{$$=$1;}								
		| break_st 	{$$=$1;}								
		| continue_st 	{$$=$1;}								
		| return_st 	{$$=$1;}								
		| SCAN PAREN_S identifier PAREN_E						
		| PRINT PAREN_S var_inits PAREN_E						
		;

empty_st	: TRM 		{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}								
		;

expr_st		: st_expr TRM 			{$$=$1;}					
		;

st_expr		: assgn 			{$$=$1;}								
		| preinc_expr 			{$$=$1;}							
		| postinc_expr 			{$$=$1;}						
		| predec_expr 			{$$=$1;}						
		| postdec_expr 			{$$=$1;}						
		| method_invo 			{$$=$1;
					sprintf(t,", call, %s",$1->place);
					$$->code=append($1->code,newList(t));}							
		| object_expr 									
		;

if_then_st	: IF PAREN_S expr PAREN_E statement 		        { char end[5];
									  strcpy(end,newLabel());
									  $$=(Attr *)malloc(sizeof(Attr));	
                      						          $$->code = append($$->code , $3->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",$3->place,end);
									  $$->code = append($$->code ,newList(t));
									  $$->code = append($$->code,$5->code);
									  sprintf(t,", label, %s",end);
       								          $$->code = append($$->code,newList(t));  }
		;

if_then_else_st	: IF PAREN_S expr PAREN_E st_no_short_if ELSE statement { char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());		
									  $$=(Attr *)malloc(sizeof(Attr));	
                      						          $$->code = append($$->code , $3->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",$3->place,else_beg);
									  $$->code = append($$->code ,newList(t));
									  $$->code = append($$->code,$5->code);
									  sprintf(t,", goto, %s",end);
       								          $$->code = append($$->code,newList(t));
									  sprintf(t,", label, %s",else_beg);
       								          $$->code = append($$->code,newList(t));
									  $$->code = append($$->code,$7->code);
									  sprintf(t,", label, %s",end);
       								          $$->code = append($$->code,newList(t));  
									   	  }
		;

if_then_else_no_short_if_st	: IF PAREN_S expr PAREN_E st_no_short_if ELSE st_no_short_if  
									{ char end[5],else_beg[5];
									  strcpy(end,newLabel()); strcpy(else_beg,newLabel());
									  $$=(Attr *)malloc(sizeof(Attr));	
                      						          $$->code = append($$->code , $3->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",$3->place,else_beg);
									  $$->code = append($$->code ,newList(t));
									  $$->code = append($$->code,$5->code);
									  sprintf(t,", goto, %s",end);
       								          $$->code = append($$->code,newList(t));
									  sprintf(t,", label, %s",else_beg);
       								          $$->code = append($$->code,newList(t));
									  $$->code = append($$->code,$7->code);
									  sprintf(t,", label, %s",end);
       								          $$->code = append($$->code,newList(t)); }	
		;

switch_st	: SWITCH PAREN_S expr PAREN_E switch_block   {  char end[5];
							 	strcpy(end,newLabel());
								$$=$5;
								patchBreak($5->code,end);
								sprintf(t,", label, %s",end);
								$$->code = append($$->code,newList(t));
								patchSwitch($$->code,$3->place);
								}
		;

switch_block	: BLOCK_S switch_block_st_gr_e BLOCK_E 	 {$$=$2;}
		;

switch_block_st_gr_e	: switch_block_st_grps 		{$$=$1;}	
			| /* empty */ 			{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}	
			;

switch_block_st_grps	: switch_block_st_grp 	 	{$$=$1;}		     
			| switch_block_st_grps switch_block_st_grp  {   $$=$1;
									$$->code= append($$->code,$2->code);} 	
			;

switch_block_st_grp	: CASE expr COLON bl_statements       { $$=(Attr*)malloc(sizeof(Attr));
								char nexLabel[5];
								strcpy(nexLabel,newLabel());
								sprintf(t,", ifgoto, neq, %s ,        , %s",$2->place,nexLabel);
								$$->code=newList(t);
								$$->code = append($$->code,$4->code);
								sprintf(t,", label, %s",nexLabel);
								$$->code=append($$->code,newList(t));
								$$->code->swt = 1;}
	
			| DEFAULT COLON bl_statements	  	{ $$=(Attr*)malloc(sizeof(Attr));
								$$->code = append($$->code,$3->code);	}
			;

while_st	: WHILE PAREN_S expr PAREN_E statement 			{ char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());	
                                                                          sprintf(t,", label, %s",begin);
                                                                          $$=(Attr *)malloc(sizeof(Attr));
									  patchBreak($5->code,end);
									  patchContinue($5->code,begin);	
       								          $$->code = newList(t);
                      						          $$->code = append($$->code , $3->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",$3->place,end);
									  $$->code = append($$->code ,newList(t));
									  $$->code = append($$->code,$5->code);
									  sprintf(t,", goto, %s",begin);
       								          $$->code = append($$->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          $$->code = append($$->code,newList(t));  }
		;

while_st_no_short_if	: WHILE PAREN_S expr PAREN_E st_no_short_if	{ char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
									  patchBreak($5->code,end);
									  patchContinue($5->code,begin);	
                                                                          sprintf(t,", label, %s",begin);
                                                                          $$=(Attr *)malloc(sizeof(Attr));
       								          $$->code = newList(t);
                      						          $$->code = append($$->code , $3->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",$3->place,end);
									  $$->code = append($$->code ,newList(t));
									  $$->code = append($$->code,$5->code);
									  sprintf(t,", goto, %s",begin);
       								          $$->code = append($$->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          $$->code = append($$->code,newList(t));  }
			;
 
do_st		: DO statement WHILE PAREN_S expr PAREN_E  TRM          { char begin[5],end[5];
									   strcpy(begin,newLabel());
									   strcpy(end,newLabel());
									  patchBreak($2->code,end);
									  patchContinue($2->code,begin);		
                                                                          sprintf(t,", label, %s",begin);
                                                                          $$=(Attr *)malloc(sizeof(Attr));
       								          $$->code = newList(t);
									  $$->code = append($$->code,$2->code);
                      						          $$->code = append($$->code , $5->code);
									  sprintf(t,", ifgoto, eq, %s, 0, %s",$5->place,end);
									  $$->code = append($$->code ,newList(t));
									  sprintf(t,", goto, %s",begin);
       								          $$->code = append($$->code,newList(t));
									  sprintf(t,", label, %s",end);
       								          $$->code = append($$->code,newList(t));  }		
		;

for_st		: FOR PAREN_S for_init_e TRM expr_e TRM for_update_e PAREN_E statement	       { char begin[5],end[5],cont[5];
									  			strcpy(begin,newLabel());
									  			strcpy(end,newLabel());
												strcpy(cont,newLabel());
												patchBreak($9->code,end);
									                        patchContinue($9->code,cont);	
												$$=(Attr *)malloc(sizeof(Attr));
												$$->code = append($$->code,$3->code);
												sprintf(t,", label, %s",begin);	
                                                                          			$$->code = append($$->code,newList(t));
                                                                          			$$->code = append($$->code,$5->code);
											sprintf(t,", ifgoto, eq, %s, 0, %s",$5->place,end);
									  			$$->code = append($$->code ,newList(t));
       								          			$$->code = append($$->code , $9->code);
												sprintf(t,", label, %s",cont);	
                                                                          			$$->code = append($$->code,newList(t));
                      						          			$$->code = append($$->code,$7->code);
									  			sprintf(t,", goto, %s",begin);
       								          		        $$->code = append($$->code,newList(t));
									  		        sprintf(t,", label, %s",end);
       								          	                $$->code = append($$->code,newList(t));}	 
		;

for_st_no_short_if	: FOR PAREN_S for_init_e TRM expr_e TRM for_update_e  PAREN_E st_no_short_if
												{ char begin[5],end[5],cont[5];
									  			strcpy(begin,newLabel());
									  			strcpy(end,newLabel());
												strcpy(cont,newLabel());
												patchBreak($9->code,end);
									                        patchContinue($9->code,cont);	
												$$=(Attr *)malloc(sizeof(Attr));
												$$->code = append($$->code,$3->code);
												sprintf(t,", label, %s",begin);	
                                                                          			$$->code = append($$->code,newList(t));
                                                                          			$$->code = append($$->code,$5->code);
											sprintf(t,", ifgoto, eq, %s, 0, %s",$5->place,end);
									  			$$->code = append($$->code ,newList(t));
       								          			$$->code = append($$->code , $9->code);
												sprintf(t,", label, %s",cont);	
                                                                          			$$->code = append($$->code,newList(t));
                      						          			$$->code = append($$->code,$7->code);
									  			sprintf(t,", goto, %s",begin);
       								          		        $$->code = append($$->code,newList(t));
									  		        sprintf(t,", label, %s",end);
       								          	               $$->code = append($$->code,newList(t));}	 			
		;

for_init_e	: for_init	{$$=$1;}
		| /* empty */	{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}
		;

for_init	: st_expr_list	{$$=$1;}
		| loc_var_dec	{$$=$1;}
		;

expr_e		: expr		{$$=$1;}
		| /* empty */	{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;strcpy($$->place,"");}
		;

for_update_e	: for_update	{$$=$1;}
		| /* empty */	{$$=(Attr *)malloc(sizeof(Attr));$$->code=NULL;}
		;

for_update	: st_expr_list	{$$=$1;}
		;

st_expr_list	: st_expr 	{$$=$1;}	
		| st_expr_list SEP st_expr	{$1->code=append($1->code,$3->code);$$=$1;}
		;

break_st	: BREAK TRM          {  $$ = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,", goto, ");
					$$->code = newList(t);
					$$->code->br = 1;}	
		;

continue_st	: CONT TRM	      {  $$ = (Attr *)malloc(sizeof(Attr));
				     	sprintf(t,", goto, ");
					$$->code = newList(t);
					$$->code->cont = 1;}	
		;

return_st	: RETURN expr_e TRM	{$$=$2;
					if(strcmp($2->place,""))
					 	sprintf(t,", ret, %s",$2->place);
					else
						strcpy(t,", ret");
					 $$->code=append($2->code,newList(t));}
		;

expr		: cond_expr	{$$=$1;}
		| assgn		{$$=$1;}
		;


assgn		: lhs assgn_op expr			{if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
						p=look_up(table,$1->place);
						if(p==NULL){
							fprintf(stderr,"Error on %d: %s undeclared\n",yylineno,$1->place);
							exit(1);
						}	
						else if(flag1 && !$1->assign){	
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
						}
						else{
							switch(flag1){
								case 0:sprintf(t,", =, %s, %s",$1->place,$3->place);
								       $1->assign=true;
								       p->assign=true;
								       break;
								case 1:sprintf(t,", *, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 2:sprintf(t,", /, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 3:sprintf(t,", %%, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 4:sprintf(t,", +, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 5:sprintf(t,", -, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 6:sprintf(t,", <<, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 7:sprintf(t,", >>, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 8:sprintf(t,", >>>, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 9:sprintf(t,", &, %s, %s, %s",$1->place,$1->place,$3->place);
								       break;
								case 10:sprintf(t,", ^, %s, %s, %s",$1->place,$1->place,$3->place);
									break;
								case 11:sprintf(t,", |, %s, %s, %s",$1->place,$1->place,$3->place);
									break;}
							$$=$1;
							$$->code=append($3->code,newList(t));
						}}	
		;

lhs		: name		{$$=$1;}
		| field_access	
		| array_access	{$$=$1;sprintf(t, "%s[%s]",$1->place, $1->idx);
					strcpy($$->place, t);}
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
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", ||, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

cond_and_expr	: incl_or_expr						{$$=$1;}
		| cond_and_expr OP_CON_AND incl_or_expr		{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", &&, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

incl_or_expr	: excl_or_expr	{$$=$1;}
		| incl_or_expr OP_OR excl_or_expr		{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", |, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}			
		;

excl_or_expr	: and_expr			{$$=$1;}			
		| excl_or_expr OP_XOR and_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", ^, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

and_expr 	: equality_expr					{$$=$1;}	
		| and_expr OP_AND equality_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", &, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

equality_expr	: rel_expr						{$$=$1;}
		| equality_expr OP_EQ rel_expr	{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, eq , %s , %s , %s ",$1->place,$3->place,begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 0",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", goto, %s",end);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s, 1",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",end);
					$$->code=append($$->code,newList(t));}
							
		| equality_expr OP_NEQ rel_expr	{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, neq , %s , %s , %s ",$1->place,$3->place,begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 0",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", goto, %s",end);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s, 1",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",end);
					$$->code=append($$->code,newList(t));}		
		;


rel_expr	: shift_expr			{$$ = $1;}
		| rel_expr OP_LES shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, lt , %s , %s , %s ",$1->place,$3->place,begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 0",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", goto, %s",end);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s, 1",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",end);
					$$->code=append($$->code,newList(t));}
							
		| rel_expr OP_GRE shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,", ifgoto, gt , %s , %s , %s ",$1->place,$3->place,begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 0",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", goto, %s",end);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 1",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",end);
					$$->code=append($$->code,newList(t));}
								
		| rel_expr OP_LEQ shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,",ifgoto, leq , %s , %s ,%s ",$1->place,$3->place,begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 0",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", goto , %s",end);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 1",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",end);
					$$->code=append($$->code,newList(t));}
								
		| rel_expr OP_GEQ shift_expr	{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
					strcpy($$->place, tempVar());
					$$->code=append($1->code,$3->code);
					char end[5],begin[5];
					strcpy(end,newLabel()); strcpy(begin,newLabel());
					sprintf(t,",ifgoto, geq, %s, %s , %s ",$1->place,$3->place,begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 0",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", goto, %s",end);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",begin);
					$$->code=append($$->code,newList(t));
					sprintf(t,", = , %s , 1",$$->place);
					$$->code=append($$->code,newList(t));
					sprintf(t,", label , %s",end);
					$$->code=append($$->code,newList(t));}
								
		| rel_expr INSTANCEOF reference_type		
		;


shift_expr	: add_expr				{$$=$1;}
		| shift_expr OP_LSH add_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", <<, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		| shift_expr OP_RSH add_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", >>, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		| shift_expr OP_ZRSH add_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", >>>, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		;


add_expr	: mul_expr				{$$=$1;}
		| add_expr OP_ADD mul_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", +, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		| add_expr OP_SUB mul_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", -, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}		
		;

mul_expr	: unary_expr				{$$=$1;}
		| mul_expr OP_MUL unary_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", *, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		| mul_expr OP_DIV unary_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", /, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		| mul_expr OP_MOD unary_expr			{$$=(Attr *)malloc(sizeof(Attr));
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							if(!$3->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$3->place);
								exit(1);
							}
							$$->assign=true;
							strcpy($$->place,tempVar());
							$$->code=append($1->code,$3->code);
							sprintf(t,", %%, %s, %s, %s",$$->place,$1->place,$3->place);
							$$->code=append($$->code,newList(t));
							}
		;

cast_expr	: PAREN_S primitive_type PAREN_E unary_expr		
		| PAREN_S reference_type PAREN_E unary_expr_not_plus_minus		
		;

unary_expr	: preinc_expr			{$$=$1;}
		| predec_expr			{$$=$1;}
		| OP_ADD unary_expr				{char temp[10];
							if(!$2->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$2->place);
								exit(1);
							}
							strcpy(temp,tempVar());
							sprintf(t,", =, %s, %s",temp,$2->place);
							$2->code=append($2->code,newList(t));
							sprintf($2->place,"%s",temp);
							$$=$2;
							}
		| OP_SUB unary_expr				{char temp[10];
							if(!$2->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$2->place);
								exit(1);
							}
							strcpy(temp,tempVar());
							sprintf(t,", -, %s, 0, %s",temp,$2->place);
							$2->code=append($2->code,newList(t));
							sprintf($2->place,"%s",temp);
							$$=$2;
							}
		| unary_expr_not_plus_minus	{$$=$1;}
		;

preinc_expr	: OP_INC unary_expr				{sprintf(t,", +, %s, %s, 1",$2->place,$2->place);
							if(!$2->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$2->place);
								exit(1);
							}
							$2->code=append($2->code,newList(t));
							$$=$2;
							}	
		;

predec_expr	: OP_DEC unary_expr				{sprintf(t,", -, %s, %s, 1",$2->place,$2->place);
							if(!$2->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$2->place);
								exit(1);
							}
							$2->code=append($2->code,newList(t));
							$$=$2;
							}	
		;

unary_expr_not_plus_minus	: postfix_expr		{$$=$1;}
				| OP_NEG unary_expr		{char temp[10];
							if(!$2->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$2->place);
								exit(1);
							}
							strcpy(temp,tempVar());
							sprintf(t,", !, %s, %s",temp,$2->place);
							$2->code=append($2->code,newList(t));
							sprintf($2->place,"%s",temp);
							$$=$2;
							}	
				| cast_expr		
				;

postdec_expr	: postfix_expr OP_DEC				{char temp[10];
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							sprintf(temp,"%s",tempVar());
							sprintf(t,", =, %s, %s",temp,$1->place);
							$1->code=append($1->code,newList(t));
							sprintf(t,", -, %s, %s, 1",$1->place,$1->place);
							$1->code=append($1->code,newList(t));
							sprintf($1->place,"%s",temp);
							$$=$1;
							}	
		;

postinc_expr	: postfix_expr OP_INC				{char temp[10];
							sprintf(temp,"%s",tempVar());
							if(!$1->assign){
								fprintf(stderr,"Error on %d: %s not assigned\n",yylineno,$1->place);
								exit(1);
							}
							sprintf(t,", =, %s, %s",temp,$1->place);
							$1->code=append($1->code,newList(t));
							sprintf(t,", +, %s, %s, 1",$1->place,$1->place);
							$1->code=append($1->code,newList(t));
							sprintf($1->place,"%s",temp);
							$$=$1;
							}							
		;

postfix_expr	: primary		{$$=$1;}
		| name			{$$=$1;}		
		| postinc_expr		{$$=$1;}
		| postdec_expr		{$$=$1;}
		;

method_invo	: name PAREN_S arg_list_e PAREN_E 			{$$=$1;}
		| primary OP_DOT identifier PAREN_S arg_list_e PAREN_E		
		| SUPER OP_DOT identifier PAREN_S arg_list_e PAREN_E		
		;

field_access	: primary OP_DOT identifier		
		| SUPER OP_DOT identifier		
		;

primary		: primary_no_new_array		{$$=$1;}	
		| array_creat_expr		{$$ = $1;}
		;

primary_no_new_array	: literal			{$$=$1;$$->assign=true;}
			| THIS			
			| PAREN_S expr PAREN_E		{$$=$2;}	
			| object_expr		
			| field_access		
			| method_invo			{sprintf(t,", =, %s, call, %s",tempVar(),$1->place);
						$$=$1;
						strcpy($$->place,TEMP);
						$$->code=newList(t);}	
			;

object_expr	: NEW class_type PAREN_S arg_list_e PAREN_E		
		;

arg_list_e	: argument_list		
		| /* empty */		
		;

argument_list	: expr				
		| argument_list SEP expr	
		;

array_creat_expr	: NEW primitive_type dim_exprs		{$$ = $3;int r;
						p = look_up(table,$<attr>0->place);
						if(p!=NULL){
							Arr_dim *b = p->arr_dim;
							r = atoi(b->d);
							b = b->next;
							while(b!=NULL){
								r = r*atoi(b->d);
								b = b->next;
								}
							}
						sprintf(t, "array, %s[%d]", $<attr>0->place,r);
						$$->code = append($$->code, newList(t));}
			| NEW class_type dim_expr	{$$ = $3;}	
			;

dim_exprs  : 	dim_expr				{$$ = $1;}
		| dim_exprs dim_expr			
		;		

dim_expr	: ARRAY_S expr ARRAY_E		{$$ = $2;p = look_up(table,$<attr>-2->place);
				if(p!=NULL){ Arr_dim *a = (Arr_dim*)malloc(sizeof(Arr_dim));
					strcpy(a->d, $2->place);
					Arr_dim *b = p->arr_dim;
					if(b){
					while(b->next!=NULL){
						b = b->next;
						}
					b->next = a;
					}
					else p->arr_dim = a;}
				}		
		;

array_access	: name ARRAY_S expr ARRAY_E	{$$=(Attr *)malloc(sizeof(Attr));
					$$->code = append($1->code, $3->code);
					p = look_up(table,$1->place);
					if(p){	
						h = p->arr_dim;
						if(h && h->next){
							strcpy($$->idx,tempVar());
							sprintf(t,", *, %s, %s, %s",$$->idx, h->next->d,$3->place);
							$$->code=append($$->code,newList(t));
							h = h->next;
							}
						}	
					}			
		| array_access ARRAY_S expr ARRAY_E		{
						$$=(Attr *)malloc(sizeof(Attr));
						strcpy($$->place, $<attr>-3->place);
						if(h && h->next){
							strcpy($$->idx,tempVar());
							sprintf(t,", *, %s, %s, %s",$$->idx, h->next->d,$3->place);
							$$->code=append($1->code,newList(t));
							sprintf(t,", +, %s, %s, %s",$$->idx, $$->idx,$1->idx);
							$$->code=append($$->code,newList(t));		
							}
						else if(h){
							strcpy($$->idx, $1->idx);
							sprintf(t,", +, %s, %s, %s",$1->idx, $1->idx,h->d);
							$$->code=append($1->code,newList(t));
							
							}
						h = h->next;
						}
		;

type_name		: CID			{$$=$1;}	
			| error ID	
			;

name			: identifier		{$$=$1;}		
			| name OP_DOT identifier	
			;

literal			: int_literal		{$$=(Attr *)malloc(sizeof(Attr));
					sprintf($$->place,"%d",$1);
					strcpy($$->type,"int0");
					$$->code=NULL;}
			| FLOAT_LIT		{$$=(Attr *)malloc(sizeof(Attr));
					sprintf($$->place,"%f",$1);
					strcpy($$->type,"float0");
					$$->code=NULL;}
			| CHAR_LIT		{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place,$1);
					strcpy($$->type,"char0");
					$$->code=NULL;}
			| STR_LIT		{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place,$1);
					strcpy($$->type,"str0");
					$$->code=NULL;}
			| T			{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->place,"1");
					strcpy($$->type,"bool0");
					$$->code=NULL;}	
			| F			{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->type,"bool0");
					$$->code=NULL;
					strcpy($$->place,"0");}	
			| N			{$$=(Attr *)malloc(sizeof(Attr));
					strcpy($$->type,"bool0");
					$$->code=NULL;
					strcpy($$->place,"null");}	
			;

int_literal		: INT_LIT_H		{$$=$1;}
			| INT_LIT_O		{$$=$1;}
			| INT_LIT_D		{$$=$1;}
			;

identifier		: ID			{SymtabEntry *tempo=look_up(table,$1);
					if(tempo!=NULL){
						$$=(Attr *)malloc(sizeof(Attr));
						strcpy($$->place,$1);
						strcpy($$->type,tempo->type);
						$$->assign=tempo->assign;
						$$->code=NULL;
						}
					else
						yyerrok;}
			;
%%
int main(int argc, char** argv){
	p=(SymtabEntry *)malloc(sizeof(SymtabEntry));
	mainTable=(Symtab *)malloc(sizeof(Symtab));
	mainTable->prev=NULL;
	table=mainTable;
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
	printSymtab(mainTable);
	free(p);
	free(mainTable);
	fclose(fptr);
	return 0;
}
