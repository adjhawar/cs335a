#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum InstrType{ Assignment , Function ,Jump , Pointer , Indexed_Ass};
enum TACkeywords{add , sub , mul , divi , mod , gt , lt , ge , le , ne , eq , assgn , AND , OR , NEG , ifgoto , Goto , ret , call , label , print , scan };


//Data structure to hold symbol table
typedef struct SymtabEntry{
	char label[100],type[10];
	struct SymtabEntry *next;
}SymtabEntry;


//Data structure to hold 3ac instruction
typedef struct Instruction3AC{
enum InstrType typ; // assign, goto...
SymtabEntry *in1;
SymtabEntry *in2;
SymtabEntry *out;
int target; // jump target
enum TACkeywords op;
} Instruction3AC;

//To store IL code 
Instruction3AC *ir;

int main(){
	FILE *fptr = fopen("IL_Program.csv","r");
	if(fptr==NULL){
		printf("Error in opening IL_Program.csv . Aborting....");
		exit(0);
	}
	else {
		int nline = 0;
		char line[1024];
		while (fgets(line, 1024, fptr)){
    //ir[nline] =(Instruction3AC) malloc(sizeof(Instruction3AC));
			char *token;
			char *rest = line;
			char strs[6][100];
			int i = 0;
			while ((token = strtok_r(rest, ", ", &rest))){
				strcpy(strs[i], token);
				i++;
			}
			nline = atoi(strs[0]);
			char *key = strs[1];
			if(strcmp(key,"=")==0)
				
		}
	}
}
