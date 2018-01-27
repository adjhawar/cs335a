%{
#include "java_to_token.h"
%}

%%
"class"			return CLASS;
"instanceof"		return INSTANCEOF;
"new"			return NEW;
"super"			return SUPER;
"this"			return THIS;

"boolean"		return BOOL;
"byte"			return BYTE;
"char"			return CHAR;
"double"		return DOUBLE;
"float"			return FLOAT;
"int"			return INT;
"long"			return LONG;
"short"			return SHORT;
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

[a-zA-Z_$][a-zA-Z0-9_]*	return ID;
;			return TRM;
,			return SEP;
:			return COLON;

[{]			return BLOCK_S;
[}]			return BLOCK_E;
\[			return ARRAY_S;
\]			return ARRAY_E;
\(			return PAREN_S;
\)			return PAREN_E;

=			return OP_ASS;
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

[?]			return OP_CON_Q;
"&&"			return OP_CON_AND;
"||"			return OP_CON_OR;

|			return OP_OR;
^			return OP_XOR;
&			return OP_AND;
==			return OP_EQ;
!=			return OP_NEQ;
>=			return OP_GEQ;
<=			return OP_LEQ;
>			return OP_GRE;
<			return OP_LES;


">>"			return OP_RSH;
"<<"			return OP_LSH;
\+			return OP_ADD;
-			return OP_SUB;
*			return OP_MUL;
/			return OP_DIV;
\%			return OP_MOD;
"\+\+"			return OP_INC;
"--"			return OP_DEC;
\.			return OP_DOT;
">>>"			return OP_ZRSH;



%%

int yywrap(void){
	return 1;
}
