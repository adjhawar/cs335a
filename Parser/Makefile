all : binary

binary :
	mkdir -p bin
	cp src/lexer.l lexer.l 
	cp src/parser.y parser.y
	yacc -d parser.y
	lex lexer.l
	gcc lex.yy.c y.tab.c -o parser
	mv parser bin/
	rm  lexer.l
	rm parser.y
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	
clean : 
	rm -r bin
