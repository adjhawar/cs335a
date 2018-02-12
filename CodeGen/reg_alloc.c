#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"
int nline,size;
SymtabEntry *head,*tail;
// upadate liveness and nextuse of variables for a basic block
void update(int i, int j){
	for (int k = j; k>=i ; k--){
		SymtabEntry *out;
		SymtabEntry *in1;
		SymtabEntry *in2;
		if(ir[k].typ != Goto && ir[k].typ !=ret){
			if(ir[k].typ==Assignment){
				out = ir[k].out;
			}
			in1 = ir[k].in1;
			
			if(ir[k].op != assgn && ir[k].typ != call && ir[k].typ != label && ir[k].typ != print && ir[k].typ != scan && ir[k].op != neg ){
				in2 = ir[k].in2;
			}
			if(ir[k].typ==Assignment){
				ir[k].out_liveness = out->liveness;
				ir[k].out_nextuse = out->nextuse;
			}
			ir[k].in1_liveness = in1->liveness;
			ir[k].in1_nextuse = in1->nextuse;
			if(ir[k].op != assgn && ir[k].typ != call && ir[k].typ != label && ir[k].typ != print && ir[k].typ != scan && ir[k].op != neg ){
				ir[k].in2_liveness = in2->liveness;
				ir[k].in2_nextuse = in2->nextuse;
			}
			if(ir[k].typ==Assignment){
				out->liveness = false;
				out->nextuse = -1;
			}
			in1->liveness = true;
			in1->nextuse = k;
			if(ir[k].op != assgn && ir[k].typ != call && ir[k].typ != label && ir[k].typ != print && ir[k].typ != scan && ir[k].op != neg ){
				in2->liveness = true;
				in2->nextuse = k;	
			}
		}
	}
}

void reg_alloc(){
	int *leaders = (int *) calloc(nline,sizeof(int));
	leaders[0] = 1;
	for (int i=1; i<nline; i++){
		if(ir[i].typ == label)
			leaders[i] = 1;
		else if (i+1<nline && (ir[i].typ == Goto || ir[i].typ == ifgoto)){
			leaders[i+1] = 1;
			leaders[ir[i].target-1] = 1;
		}
		else if(i+1 < nline && (ir[i].typ == call || ir[i].typ == ret)){
			leaders[i+1] = 1;
		}
	}
	for (int i = 0; i < nline; ++i)
	{
		printf("%d ", leaders[i]);
	}
	printf("\n");
	int i = 0,j = 1;
	while(i<nline){
		while(j<nline && leaders != NULL && leaders[j]!=1){
			j++;
		}
		update(i,j-1);
		i = j;
		j++;
	}
	update(4,4);
	free(leaders);
}

