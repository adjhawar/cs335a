

   =======================================================Group10================================================
							
							• Name: Aditya Jhawar -150050 -adjhawar@iitk.ac.in
							• Name: Hariom Panthi -150263 -phari@iitk.ac.in
							• Name: Raj Kumar Meena-150553 -rajku@iitk.ac.in

1) translator.c -  This file reads the Intermediate language. First it break each line into it's respective parameters, operations etc. For each line it creates an enrty in the IR array which is a array of structure for Three address code. This Three address code structure has several fields. It creates an entry in Symbol table for each distinct variable and also saves liveness and nextuse of a variable. And it also store instruction type, operator, label and target(if it is a jump instruction). Symbol table data structure has name of variable, type, nextuse, liveness. Symbol table is a list and  uses fixed size for each lexeme. After this it calls reg_alloc function which update liveness and nextuse of the variable correctly.We also saves context when a basic block ends and empty register descriptor. getReg function is being called for each line which generates assembly code.  

2) reg_alloc.c - This file calls reg_alloc function which finds leaders and store in the array "leaders" and using this array we can keep track of basic blocks. reg_alloc function calls update function which sets liveness and nextuse of the variables for each basic block.

3) code_gen.c - This file  implements getReg function which generates assembly code for x86. This file also implements empty_reg function which gives a register to use. It uses liveness and nextuse to find appropriate register. 

4) global.h - This file defines all global variables.