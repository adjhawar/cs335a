#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"

int nline,size;
int *leaders;
liveTable *head,*tail;
extern Symtab *mainTable;
// upadate liveness and nextuse of variables for a basic block
void update(int i, int j){
	for (int k = i; k>=j ; k--){
		liveTable *out;
		liveTable *in1;
		liveTable *in2;
		if(ir[k].typ != Goto && ir[k].typ !=Ret){
			if(ir[k].typ==Assignment){
				out = ir[k].out;
			}
			if (ir[k].typ != label && ir[k].typ != call && ir[k].typ != Ret && strcmp(ir[k].in1->type,"const")){
				in1 = ir[k].in1;
			}
			
			if(ir[k].op != assgn && ir[k].typ != Ret && ir[k].typ != call && ir[k].typ != label && ir[k].typ != print && ir[k].typ != scan && ir[k].op != neg && strcmp(ir[k].in2->type,"const")){
				in2 = ir[k].in2;
			}
			if(ir[k].typ==Assignment){
				ir[k].out_liveness = out->liveness;
				ir[k].out_nextuse = out->nextuse;
			}
			if (ir[k].typ != label && ir[k].typ != call && ir[k].typ != Ret && strcmp(ir[k].in1->type,"const")){
				ir[k].in1_liveness = in1->liveness;
				ir[k].in1_nextuse = in1->nextuse;
			}
			if(ir[k].op != assgn && ir[k].typ != Ret && ir[k].typ != call && ir[k].typ != label && ir[k].typ != print && ir[k].typ != scan && ir[k].op != neg && strcmp(ir[k].in2->type,"const")){
				ir[k].in2_liveness = in2->liveness;
				ir[k].in2_nextuse = in2->nextuse;
			}
			if(ir[k].typ==Assignment){
				out->liveness = false;
				out->nextuse = -1;
			}
			if (ir[k].typ != label && ir[k].typ != call && ir[k].typ != Ret && strcmp(ir[k].in1->type,"const")){
				in1->liveness = true;
				in1->nextuse = k;
			}
			if(ir[k].op != assgn && ir[k].typ != Ret && ir[k].typ != call && ir[k].typ != label && ir[k].typ != print && ir[k].typ != scan && ir[k].op != neg && strcmp(ir[k].in2->type,"const")){
				in2->liveness = true;
				in2->nextuse = k;	
			}
		}
	}
}

void reg_alloc(){
	leaders = (int *) calloc(nline,sizeof(int));
	leaders[0] = 1;
	for (int i=1; i<nline; i++){
		if(ir[i].typ == label)
			leaders[i] = 1;
		else if (i+1<nline && (ir[i].typ == Goto || ir[i].typ == ifgoto)){
			leaders[i+1] = 1;
			//leaders[ir[i].target-1] = 1;
		}
		else if(i+1 < nline && (ir[i].typ == call || ir[i].typ == Ret)){
			leaders[i+1] = 1;
		}
	}
	int i = nline-1,j = nline-2;
	while(i>=0 && j>=0){
		while(j>=0 && leaders != NULL && leaders[j]!=1){
			j--;
		}
		//update(i,j);
		i = j-1;
		j--;
	}
	//free(leaders);
}

