#include <stdio.h>
#include<stdlib.h>
#include "java_to_token.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

struct category {
		char* lexeme ;
		struct category* next ;
	} ;

void add(struct category *head)
{
	struct category* curr = (struct category *)malloc(sizeof(struct category));
	curr->lexeme = yytext;
	curr->next=NULL;
	if(head==NULL)
		head=curr;
	else
	{
		struct category *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=curr;
	}
}

void Print_lex(struct category *head)
{
	printf("%s",head->lexeme);
	while(head->next!=NULL)
	{
		head=head->next;
		printf("\n %s",head->lexeme);
	}

}

int main(void){

	int ntoken,vtoken, occur[82]={0};

	struct category *Id=NULL, *Lit_d=NULL,*Lit_o=NULL,*Lit_h=NULL,*Flo=NULL,*Cha=NULL,*Str=NULL,*Err=NULL;
	char tokens[82][15] = {"null", "CLASS" , "INSTANCEOF" , "NEW", "SUPER", "THIS", "BOOL", "BYTE" ,"CHAR", "DOUBLE" , "FLOAT", "INT", "LONG", "SHORT", "VOID", "BREAK", "CASE", "DEFAULT", "ELSE", "IF", "SWITCH", "CONT", "DO", "FOR", "WHILE", "RETURN", "CONST", "ID", "SEP", "TRM", "COLON", "ARRAY_S", "ARRAY_E", "BLOCK_S", "BLOCK_E", "PAREN_S", "PAREN_E", "OPP_ASS", "OPP_ADD_ASS", "OP_SUB_ASS", "OP_DIV_ASS", "OP_MUL_ASS", "OP_MOD_ASS", "OP_LSH_ASS", "OP_RSH_ASS", "OP_AND_ASS", "OP_OR_ASS", "OP_XOR_ASS", "OP_ZRSH_ASS", "OP_CON_Q", "OP_CON_AND", "OP_CON_OR", "OP_OR", "OP_XOR", "OP_AND", "OP_EQ", "OP_NEQ", "OP_GRE", "OP_LES", "OP_GEQ", "OP_LEQ", "OP_RSH", "OP_LSH", "OP_ADD", "OP_SUB", "OP_MUL","OP_DIV","OP_MOD","OP_INC","OP_DEC","OP_DOT","OP_ZRSH","INT_LIT_D","INT_LIT_O","INT_LIT_H","FLOAT_LIT","CHAR_LIT","STR_LIT","ERROR","IGN","PRINT","SCAN"} ;

	char lexeme[82][15] = {"", "class", "instanceof", "new" , "super" , "this", "boolean", "byte", "char", "double", "float", "int", "long", "short","void","break","case","default","else","if","switch","continue","do","for","while","return","final","",",",";",":","[","]","{",
		"}","(",")","=","+=","-=","/=","*=","%=","<<=",">>=","&=","=","^=",">>>=","?","&&","||","|","^","&","==","=",">","<",">=","<=",">>","<<","+","-","*","/","%","++","--",".",">>>","","","","","","","","","print","scan"};
	ntoken=yylex();
	while(ntoken){
		if(lexeme[ntoken]==""){
			switch(ntoken)
			{
				case 27 : add(Id); break;
				case 72 : add(Lit_d);break;
				case 73 : add(Lit_o);break;
				case 74 : add(Lit_h); break;
				case 75 : add(Flo);break;
				case 76 : add(Cha);break;
				case 77 : add(Str);break;
				case 80 : add(Err);break;
				default : ;break;
			}}
		occur[ntoken]++ ;
		ntoken=yylex();
	}
	for(int i=1;i<82 ; i++)
	{
		if(occur[i]>0)
		{
			printf("%s  %d ",tokens[i],occur[i]);
			if(lexeme[i]=="")

			{
				switch(i)
				{
					case 27 : Print_lex(Id); break;
					case 72 : Print_lex(Lit_d);break;
					case 73 : Print_lex(Lit_o);break;
					case 74 : Print_lex(Lit_h); break;
					case 75 : Print_lex(Flo);break;
					case 76 : Print_lex(Cha);break;
					case 77 : Print_lex(Str);break;
					case 80	: Print_lex(Err);break;
					default : ;
				}
			}
			else
			{
				printf("%s \n",lexeme[i]);  

			}

		}
	}     
	return 0;
}
