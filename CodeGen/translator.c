#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"
#include <ctype.h>

int nline, size;
SymtabEntry *head,*tail;
int *leaders;


SymtabEntry* look_up(char *lex){
	SymtabEntry* temp = head;
	if(strcmp(lex, "0")==0 || strcmp(lex, "0\n")==0 || atoi(lex)) 
		return NULL;
	while(temp!=NULL && strcmp(temp->lexeme,lex))
	{
		temp=temp->next;
	}
	return temp;
}

SymtabEntry* Insert(char* lex)
{
	SymtabEntry *tem = look_up(lex);
	if(tem){
		return tem;
	}
	else
	{
		SymtabEntry *temp =(SymtabEntry *)malloc(sizeof(SymtabEntry));
		temp->liveness = false;
		temp->nextuse = -1;
		strcpy(temp->lexeme,lex);
		if(strcmp(lex, "0")==0 || atoi(lex)) 
			strcpy(temp->type,"const");
		temp->next=NULL;
		temp->add_des.reg_no = -1;
		temp->add_des.mem=false;
		if(head==NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		return temp;
	//}
	
}
}


int main(){
	nline=0;
	size=10;
	head=NULL;
	tail=NULL;
	FILE *fptr = fopen("IL_Program.csv","r");
	ir = (Instruction3AC *) malloc(size * sizeof(Instruction3AC));
	if(fptr==NULL){
		printf("Error in opening IL_Program.csv \n . Aborting....");
		exit(0);
	}
	else {

		char line[1024];
		while (fgets(line, 1024, fptr)){
			if (size == nline) {
				size = 2*size;
				ir = realloc(ir, size * sizeof(Instruction3AC));
			}
			char *token;
			char *rest = strtok(line, "\n");
			char strs[6][100];
			int i = 0;
			while ((token = strtok_r(rest, ", ", &rest))){
				strcpy(strs[i], token);
				i++;
			}
			char *key = strs[1];
			if(strcmp(key,"=")==0 && strchr(strs[2],"[")){
				char *temp;			
				temp= strtok(strs[2], "[");
				ir[nline].out = Insert(temp);
				token = strtok(NULL, "[");
				token = strtok(token,"]");
				ir[nline].typ = Ind_Ass_1;
				ir[nline].in2 = atoi(token);
				ir[nline].in1 = Insert(strs[3]);
			}
			if(strcmp(key,"=")==0 && strchr(strs[3],"[")){
				char *temp;			
				temp= strtok(strs[3], "[");
				ir[nline].in1 = Insert(temp);
				token = strtok(NULL, "[");
				token = strtok(token,"]");
				ir[nline].typ = Ind_Ass_2;
				ir[nline].in2 = atoi(token);
				ir[nline].out = Insert(strs[2]);
			}
			if(strcmp(key,"=")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = assgn;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
                                if(strcmp(strs[3],"call")==0)
				{
				    ir[nline].in2 = Insert(strs[4]);
				    strcpy(ir[nline].in2->type,"label");
				    ir[nline].op = assgn_call;
				}
			}
			else if(strcmp(key,"+")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = add;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
				//printf("%s\n", ir[0].out->lexeme);

			}
			else if(strcmp(key,"-")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = sub;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);

			}
			else if(strcmp(key,"*")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = mul;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"/")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = divi;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"%")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = mod;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"ifgoto")==0){	//relational operators
				ir[nline].typ = ifgoto;
				if(strcmp(strs[2],"eq")==0)
					ir[nline].op=eq;
				else if(strcmp(strs[2],"neq")==0)
					ir[nline].op=ne;
				else if(strcmp(strs[2],"leq")==0)
					ir[nline].op=le;
				else if(strcmp(strs[2],"geq")==0)
					ir[nline].op=ge;
				else if(strcmp(strs[2],"lt")==0)
					ir[nline].op=lt;	
				else if(strcmp(strs[2],"gt")==0)
					ir[nline].op=gt;
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
				ir[nline].target = atoi(strs[5]);
				ir[atoi(strs[5])-1].label=true;
			}
			else if(strcmp(key,"Goto")==0){
				ir[nline].typ = Goto;
				ir[nline].target = atoi(strs[2]);
				ir[atoi(strs[2])-1].label=true;
			}
			else if(strcmp(key,"ret")==0){
				ir[nline].typ = ret;
                                if(strs[2]!=NULL)
                                {
				   ir[nline].in1 = Insert(strs[2]);
                                }
			}
			else if(strcmp(key,"call")==0){
				ir[nline].typ = call;
				ir[nline].in1 = Insert(strs[2]);
				ir[nline].label = true;
				strcpy(ir[nline].in1->type,"label");
			}
			else if(strcmp(key,"label")==0){
				ir[nline].label=true;
				ir[nline].typ = label;
				ir[nline].in1 = Insert(strs[2]);
			}
			else if(strcmp(key,"print")==0){
				ir[nline].typ = print;
				ir[nline].in1 = Insert(strs[2]);
			}
			else if(strcmp(key,"scan")==0){
				ir[nline].typ = scan;
				ir[nline].in1 = Insert(strs[2]);
			}
			else if(strcmp(key,"&&")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = and;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"||")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = or;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"~")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = neg;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
			}
			else if(strcmp(key,">>")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = rsh;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"<<")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = lsh;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,">>>")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = zrsh;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			nline = atoi(strs[0]);
		}
	}
	reg_alloc();
	SymtabEntry* temp=head;            // setting up data regions for global variables
	printf(".data\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->type,"const") && strcmp(temp->type, "label"))
		{
			printf("%s:  .quad  0\n",temp->lexeme);
		}
		temp=temp->next;
	}
        printf("str:   .string \"%%d \\n\"\n");   // for printf
        printf("str1:   .string \"%%d\"\n");      // for scanf  
	printf(" .text\n .globl main \n main:\n");
	int k =0;
	for(int i=0;i<nline;i++){
		if (leaders[i])
		{
			for (int j = 0; j < 14; j++)
			{
				if (reg_des[j]!=NULL)
				{
					printf("\t movq %s %s\n",registers[j],reg_des[j]->lexeme);
    				reg_des[j]->add_des.reg_no =-1;
    				reg_des[j] = NULL;
				}
			}
		}
		getReg(i);
	}
	free(ir);
	free(head);
	free(leaders);
}
