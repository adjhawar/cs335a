%{
#include "y.tab.h"
#include <string.h>
int yylineno;
int yynerrs;
%}

%%
"class"			return CLASS;
"instanceof"		return INSTANCEOF;
"new"			return NEW;
"super"			return SUPER;
"this"			return THIS;
"extends"		return EXTENDS;

"boolean"		return BOOL;
"byte"			return BYTE;
"char"			return CHAR;
"true"			return T;
"float"			return FLOAT;
"int"			return INT;
"false"			return F;
"null"			return N;
"String"		return STRING;
"void"			return VOID;

"break"			return BREAK;
"case"			return CASE;
"default"		return DEFAULT;
"else"			return ELSE;
"if"			return IF;
"switch"		return SWITCH;

"continue"		return CONT;
"do"			return DO;
"for"			return FOR;
"while"			return WHILE;

"return"		return RETURN;

"final"			return CONST;

"print"			return PRINT;
"scan"			return SCAN;
[\/][\/].*		;

[$](([a-zA-Z$][a-zA-Z0-9_]*)|(_[a-zA-Z0-9_]+))	{yylval.sval=strdup(yytext);return CID;}
([a-zA-Z$][a-zA-Z0-9_]*)|(_[a-zA-Z0-9_]+)	{yylval.sval=strdup(yytext);return ID;}
;			return TRM;
,			return SEP;
:			return COLON;

[{]			return BLOCK_S;
[}]			return BLOCK_E;
\[			return ARRAY_S;
\]			return ARRAY_E;
\(			return PAREN_S;
\)			return PAREN_E;

"+="			return OP_ADD_ASS;
"-="			return OP_SUB_ASS;
"*="			return OP_MUL_ASS;
"/="			return OP_DIV_ASS;
"%="			return OP_MOD_ASS;
"<<="			return OP_LSH_ASS;
">>="			return OP_RSH_ASS;
"&="			return OP_AND_ASS;
"|="			return OP_OR_ASS;
"^="			return OP_XOR_ASS;
">>>="			return OP_ZRSH_ASS;
=			return OP_ASS;

[?]			return OP_CON_Q;
"&&"			return OP_CON_AND;
"||"			return OP_CON_OR;

\|			return OP_OR;
\^			return OP_XOR;
&			return OP_AND;
==			return OP_EQ;
!=			return OP_NEQ;
[>]=			return OP_GEQ;
[<]=			return OP_LEQ;
[>]			return OP_GRE;
[<]			return OP_LES;
!			return OP_NEG;

">>"			return OP_RSH;
"<<"			return OP_LSH;
[+]			return OP_ADD;
-			return OP_SUB;
\*			return OP_MUL;
\/			return OP_DIV;
\%			return OP_MOD;
"\+\+"			return OP_INC;
"--"			return OP_DEC;
\.			return OP_DOT;
">>>"			return OP_ZRSH;

\"([\\][\"]|[^\"\n])*\" 	{yylval.sval=strdup(yytext);return STR_LIT;}
\'[\\]?.[\']			{yylval.sval=strdup(yytext);return CHAR_LIT;}
\'.|\"[^\"\n]*		return ERROR;
([0-9]*[.][0-9]*([eE][+-]?[0-9]+)?)|([0-9]+[eE][+-]?[0-9]+)		{int i,l=strlen(yytext),n=0;
						 float f;
						 char *s;
						 for(i=0;i<l;i++)
							if(yytext[i]=='e' || yytext[i]=='E')
								break;
						 if(i<l)
							n=atoi(yytext+i+1);
						 s=(char *)malloc(sizeof(char)*(i));
						 strncpy(s,yytext,i);
						 f=atof(s);
						 if(n>0)
						 	for(i=1;i<=n;i++)
								f=f*10;
						 else if(n<0)
							for(i=1;i<=-n;i++)
								f=f/10;
						 free(s);
						 yylval.fval=f;
  						 return FLOAT_LIT;}
[0][xX][0-9a-fA-F]+				{yylval.ival=atoi(yytext);return INT_LIT_H;}
[0][0-7]+					{yylval.ival=atoi(yytext);return INT_LIT_O;}
[0-9]+						{yylval.ival=atoi(yytext);return INT_LIT_D;}

\n			{yylineno++;}
[\t\r\f]|" "		;
.			return ERROR;


%%

int yywrap(void){
	return 1;
}

void yyerror(const char *s){
	fprintf(stderr,"Error in Line: %d %s\n",yylineno,s);
}
