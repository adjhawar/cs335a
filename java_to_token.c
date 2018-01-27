#include <stdio.h>
#include "java_to_token.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void){
	int ntoken,vtoken;
        char tokens[80][10] = {"null", "CLASS" , "INSTANCEOF" , "NEW", "SUPER", "THIS", "BOOL", "BYTE" ,"CHAR", "DOUBLE" , "FLOAT", "INT", "LONG", "SHORT", "VOID", "BREAK", "CASE", "DEFAULT", "ELSE", "IF", "SWITCH", "CONT", "DO", "FOR", "WHILE", "RETURN", "CONST", "ID", "SEP", "TRM", "COLON", "ARRAY_S", "ARRAY_E", "BLOCK_S", "BLOCK_E", "PAREN_S", "PAREN_E", "OPP_ASS", "OPP_ADD_ASS", "OP_SUB_ASS", "OP_DIV_ASS", "OP_MUL_ASS", "OP_MOD_ASS", "OP_LSH_ASS", "OP_RSH_ASS", "OP_AND_ASS", "OP_OR_ASS", "OP_XOR_ASS", "OP_ZRSH_ASS", "OP_CON_Q", "OP_CON_AND", "OP_CON_OR", "OP_OR", "OP_XOR", "OP_AND", "OP_EQ", "OP_NEQ", "OP_GRE", "OP_LES", "OP_GEQ", "OP_LEQ", "OP_RSH", "OP_LSH", "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_INC", "OP_DEC", "OP_DOT","OP_ZRSH"} ;
	ntoken=yylex();
	while(ntoken){
		printf("%s",tokens[ntoken]);
                
		ntoken=yylex();
	}
	return 0;
}

