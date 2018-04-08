	==============================================Group 10========================================================== 

			• Name: Aditya Jhawar -150050 -adjhawar@iitk.ac.in
			• Name: Hariom Panthi -150263 -phari@iitk.ac.in
			• Name: Raj Kumar Meena-150553 -rajku@iitk.ac.in

To build binaries run "make" from asgn4 and to clean binaries run "make clean" from asgn4.

To test run the following commands:
	• cd assgn4
	• make
	• bin/irgen test/test1.java

Files :
	• lexer.l  :- Lexer for our language using lex.
	• parser.y :- Parser for our language using yacc containing the semantic meaning of expressions using attributes
	• symtab.c :- Contains symbol table functions like insert and lookup
	• list.h   :- Header file containing declarations of all used functions
	• list.c   :- Contains list functions which create, append and print lists.	

Important :
	• Class name should start from "$" (to resolve conflict) 
	• Undeclared and unassigned variables are reported and execution is stopped
	• Missing return statements are reported
	• All shown syntax error may not be correct error
	• Function arguments are treated as class  variables
	• Labels are used in place of line numbers (slight modififcation in the 3AC)
	• Labels for functions are treated separately than other labels
