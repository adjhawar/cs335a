#include "iostream.h"
#include "stdio.h"
enum InstrType{ Assignment , Function ,Jump , Pointer , Indexed_Ass};

//Data structure to hold 3ac instruction
typedef struct {
InstrType typ; // assign, goto...
SymtabEntry *in1;
SymtabEntry *in2
SymtabEntry *out;
int target; // jump target
Operator op
} Instruction3AC;

//Data structure to hold symbol table
FILE *fptr ;
if(fptr = fopen("../IL_Program.txt","r")==NULL)
{
printf("Error in opening IL_Program.txt . Aborting....");
exit(0);
}

