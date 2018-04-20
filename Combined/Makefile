all : binary

binary :
	mkdir -p bin
	rsync -r src/ bin
	cd bin && lex lexer.l && yacc -d parser.y && gcc list.c symtab.c y.tab.c lex.yy.c translator.c reg_alloc.c code_gen.c -o irgen

clean :
	rm -r bin
	rm -r bin1
