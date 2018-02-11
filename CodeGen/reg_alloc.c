#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <global.h>

// upadate liveness and nextuse of variables for a basic block
void update(int i, int j){
	for (k = j; k<i ; k--){

	}
}

void reg_alloc(){
	int *leaders = (int *) calloc(sizeof(int)*nline);
	leaders[0] = 1;
	for (int i=1; i<nline; i++){
		if(ir[i].typ == label)
			leaders[i] = 1;
		else if (i+1<nline && (ir[i].typ == Goto || ir[i].typ == ifgoto)){
			leaders[i+1] = 1;
			leaders[ir[i].target] = 1;
		}
		else if(i+1 < nline && (ir[i].typ == call || ir[i].typ = ret)){
			leaders[i+1] = 1;
		}
	}
}
