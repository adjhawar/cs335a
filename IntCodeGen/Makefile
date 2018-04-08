all : binary

binary :
	lex lexer.l
	yacc -d parser.y
	gcc -o parser y.tab.c lex.yy.c symtab.c list.c

clean :
	rm lex.yy.c
	rm parser
	rm y.tab.c
	rm y.tab.h
