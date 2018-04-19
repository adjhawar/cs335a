all : binary

binary :
	mkdir -p bin
	rsync -r src/ bin
	cd bin && lex lexer.l && yacc -d parser.y && gcc list.c symtab.c y.tab.c lex.yy.c -o irgen
	mkdir -p bin1
		gcc ./src1/*.c -o codegen
		mv codegen bin1/

clean :
	rm -r bin
	rm -r bin1
