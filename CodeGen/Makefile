all : binary

binary : 
		gcc *.c 
		./a.out > test.s
		gcc test.s -o test
		./test