#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"
int nline,size;
SymtabEntry *head,*tail;
// upadate liveness and nextuse of variables for a basic block
void update(int i, int j){
	for (int k = j; k<=i ; k--){
		SymtabEntry *out = ir[k].out;
		SymtabEntry *in1 = ir[k].in1;
		SymtabEntry *in2 = ir[k].in2;
		ir[k].out_liveness = out->liveness;
		ir[k].out_nextuse = out->nextuse;
		ir[k].in1_liveness = in1->liveness;
		ir[k].in1_nextuse = in1->nextuse;
		ir[k].in2_liveness = in2->liveness;
		ir[k].in2_nextuse = in2->nextuse;
		out->liveness = false;
		out->nextuse = -1;
		in1->liveness = true;
		in1->nextuse = k;
		in2->liveness = true;
		in2->nextuse = k;		

	}
}

void reg_alloc(){
	int *leaders = (int *) calloc(nline, sizeof(int));
	leaders[0] = 1;
	for (int i=1; i<nline; i++){
		if(ir[i].typ == label)
			leaders[i] = 1;
		else if (i+1<nline && (ir[i].typ == Goto || ir[i].typ == ifgoto)){
			leaders[i+1] = 1;
			leaders[ir[i].target] = 1;
		}
		else if(i+1 < nline && (ir[i].typ == call || ir[i].typ == ret)){
			leaders[i+1] = 1;
		}
	}
	int i = 0,j = 1;
	while(i<nline){
		while(leaders[j]!=1){
			j++;
		}
		//update(j-1,i);
		i = j;
		j++;
	}
}
