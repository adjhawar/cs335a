#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "java_to_token.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

struct category {
		char* lexeme ;
		struct category* next ;
	} ;
struct category* add(struct category *head,int *count)
{
        struct category* temp = head;
	struct category* curr = (struct category*)malloc(sizeof(struct category));
        curr->lexeme = (char *)malloc(15*sizeof(char));
	strcpy(curr->lexeme,yytext);
	curr->next=NULL;
	if(head==NULL) {
		head=curr;
		(*count)++;
		return head;
	}
	else
	{
		while(head->next!=NULL && strcmp(head->lexeme,yytext))
		{
			head=head->next;
		}
		if(strcmp(head->lexeme,yytext)){
		 	head->next=curr;
			(*count)++;
		}
	}
        return temp ;
}

void Print_lex(struct category *head)
{
	printf("%-24s \n",head->lexeme);
	while(head->next!=NULL)
	{
		head=head->next;
		printf(" \t \t\t        %s \n",head->lexeme);
	}

}

int main(void){

	int ntoken,vtoken, occur[83]={0};

	struct category *Id=NULL, *Lit_d=NULL,*Lit_o=NULL,*Lit_h=NULL,*Flo=NULL,*Cha=NULL,*Str=NULL,*Err=NULL;
	char tokens[83][15] = {"null", "CLASS" , "INSTANCEOF" , "NEW", "SUPER", "THIS", "BOOL", "BYTE" ,"CHAR", "TRUE" , "FLOAT", "INT", "FALSE", "NULL", "VOID", "BREAK", "CASE", "DEFAULT", "ELSE", "IF", "SWITCH", "CONT", "DO", "FOR", "WHILE", "RETURN", "CONST", "ID", "SEP", "TRM", "COLON", "ARRAY_S", "ARRAY_E", "BLOCK_S", "BLOCK_E", "PAREN_S", "PAREN_E", "OPP_ASS", "OPP_ADD_ASS", "OP_SUB_ASS", "OP_DIV_ASS", "OP_MUL_ASS", "OP_MOD_ASS", "OP_LSH_ASS", "OP_RSH_ASS", "OP_AND_ASS", "OP_OR_ASS", "OP_XOR_ASS", "OP_ZRSH_ASS", "OP_CON_Q", "OP_CON_AND", "OP_CON_OR", "OP_OR", "OP_XOR", "OP_AND", "OP_EQ", "OP_NEQ", "OP_GRE", "OP_LES", "OP_GEQ", "OP_LEQ", "OP_RSH", "OP_LSH", "OP_ADD", "OP_SUB", "OP_MUL","OP_DIV","OP_MOD","OP_INC","OP_DEC","OP_DOT","OP_ZRSH","INT_LIT_D","INT_LIT_O","INT_LIT_H","FLOAT_LIT","CHAR_LIT","STR_LIT","ERROR","IGN","PRINT","SCAN","OP_NEG"} ;


	char lexeme[83][15] = {"","class", "instanceof", "new" , "super" , "this", "boolean", "byte", "char", "true","float","int","false","null","void","break","case","default","else","if","switch","continue","do","for","while","return","final","",",",";",":","[","]","{","}","(",")","=","+=","-=","/=","*=","%=","<<=",">>=","&=","=","^=",">>>=","?","&&","||","|","^","&","==","=",">","<",">=","<=",">>","<<","+","-","*","/","%","++","--",".",">>>","","","","","","","","","print","scan","!"};
	ntoken=yylex();
	while(ntoken){
		if(lexeme[ntoken][0]=='\0') {
			switch(ntoken)
			{
				case 27 : Id=add(Id,&occur[ntoken]); break;
				case 72 : Lit_d=add(Lit_d,&occur[ntoken]);break;
				case 73 : Lit_o=add(Lit_o,&occur[ntoken]);break;
				case 74 : Lit_h=add(Lit_h,&occur[ntoken]); break;
				case 75 : Flo=add(Flo,&occur[ntoken]);break;
				case 76 : Cha=add(Cha,&occur[ntoken]);break;
				case 77 : Str=add(Str,&occur[ntoken]);break;
				case 78 : Err=add(Err,&occur[ntoken]);break;
				default : ;
			}
			//printf("%s hello\n",yytext);
                   }
		else
			occur[ntoken]++;
		ntoken=yylex();
	}
        printf("Tokens \t    Occurrances       Lexemes \n"); 
	for(int i=1;i<83 ; i++)
	{
		if(occur[i]>0)
		{
			printf("%-15s %-15d",tokens[i],occur[i]);
			if(lexeme[i][0]=='\0')
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
					case 78	: Print_lex(Err);break;
					case 79 :	
					default : ;
				}
			}
			else
			{
				printf("%-24s \n",lexeme[i]);  

			}

		}
	}     
	return 0;
}

