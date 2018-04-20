#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include <ctype.h>

int nline, size;
SymtabEntry *head,*tail;
int *leaders;
/*
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

SymtabEntry* look_up(table,char* lex)
{
	SymtabEntry *tem = look_up(lex);
	if(tem){
		return tem;
	}
	else
	{
		SymtabEntry *temp =(SymtabEntry *)malloc(sizeof(SymtabEntry));
		
		strcpy(temp->lexeme,lex);
		if(strcmp(lex, "0")==0 || atoi(lex)) 
			strcpy(temp->type,"const");
		temp->next=NULL;
		
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

*/
void translator(list3AC *list){
	nline=0;
	size=200;
	head=NULL;
	tail=NULL; 
	Symtab *table=mainTable;
	ir = (Instruction3AC *) malloc(size * sizeof(Instruction3AC));
	char line[1024];
	while (list!=NULL){
		char *token,*rest;
		if (size == nline) {
			size = 2*size;
			ir = realloc(ir, size * sizeof(Instruction3AC));
		}
		rest=(char *)malloc(sizeof(char)*(strlen(list->instr)+3));
		sprintf(rest,"%d%s",nline+1,list->instr);
		list=list->next;
		printf("%s\n",rest);
		char strs[6][100];
		int i = 0;
		while ((token = strtok_r(rest, ", ", &rest))){
			strcpy(strs[i], token);
			i++;
		}
		char *key = strs[1];
		if(strcmp(key,"=")==0 && strchr(strs[2],(int)'[')){
			char *temp;			
			temp= strtok(strs[2], "[");
			ir[nline].out = look_up(table,temp);
			temp = strtok(NULL, "[");
			temp = strtok(temp,"]");
			ir[nline].typ = Ind_Ass_1;
			ir[nline].in2 = look_up(table,temp);
			ir[nline].in1 = look_up(table,strs[3]);
		}
		else if(strcmp(key,"=")==0 && strchr(strs[3],(int)'[')){
			char *temp;
			temp= strtok(strs[3], "[");
			ir[nline].in1 = look_up(table,temp);
			temp = strtok(NULL, "[");
			temp = strtok(temp,"]");
			ir[nline].typ = Ind_Ass_2;
			ir[nline].in2 = look_up(table,temp);
			ir[nline].out = look_up(table,strs[2]);
		}
		else if(strcmp(key,"=")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = assgn;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			if(strcmp(strs[3],"call")==0)
			{
				ir[nline].in2 = look_up(table,strs[4]);
				ir[nline].op = assgn_call;
			}
		}
		else if(strcmp(key,"+")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = add;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"-")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = sub;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"*")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = mul;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"/")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = divi;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"%")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = mod;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"ifgoto")==0){
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
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
			strcpy(ir[nline].target,strs[5]);
		}
		else if(strcmp(key,"Goto")==0){
			ir[nline].typ = Goto;
			strcpy(ir[nline].target,strs[2]);
		}
		else if(strcmp(key,"ret")==0){
			ir[nline].typ = Ret;
			if(i==3)
				ir[nline].in1 = look_up(table,strs[2]);
			table=table->prev;
		}
		else if(strcmp(key,"call")==0){
			ir[nline].typ = call;
			strcpy(ir[nline].target,strs[2]);
			ir[nline].label = true;
		}
		else if(strcmp(key,"label")==0){
			ir[nline].label=true;
			ir[nline].typ = label;
			strcpy(ir[nline].target,strs[2]);
		}
		else if(strcmp(key,"func")==0){
			ir[nline].typ = func;
			strcpy(ir[nline].target,strs[2]);
			SymtabEntry *temp=look_up(table,strs[2]);
			table=temp->func;
		}
		else if(strcmp(key,"print")==0){
			ir[nline].typ = print;
			ir[nline].in1 = look_up(table,strs[2]);
		}
		else if(strcmp(key,"scan")==0){
			ir[nline].typ = scan;
			ir[nline].in1 = look_up(table,strs[2]);
		}
		else if(strcmp(key,"&")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = and;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"|")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = or;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"~")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = neg;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
		}
		else if(strcmp(key,">>")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = rsh;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		else if(strcmp(key,"<<")==0){
			ir[nline].typ = Assignment;
			ir[nline].op = lsh;
			ir[nline].out = look_up(table,strs[2]);
			ir[nline].in1 = look_up(table,strs[3]);
			ir[nline].in2 = look_up(table,strs[4]);
		}
		nline++;
	}
	printSymtab(mainTable);
		/*reg_alloc();
		
		SymtabEntry *temp=mainTable->head;            // setting up data regions for global variables
		printf(".data\n");
		int k =0;
		while(ir[k].typ!=func){
			printf("%s:	.quad %s\n",ir[k].out->lexeme,ir[k].in1->lexeme);
			k++;
		}
		printf("str:   .string \"%%d \\n\"\n");   // for printf
		printf("str1:   .string \"%%d\"\n");      // for scanf  
		printf(" .text\n");
		for(int i=k;i<nline;i++){
			if (leaders[i])
			{
				for (int j = 0; j < 14; j++)
				{
					if (reg_des[j]!=NULL)
					{
						//				printf("\t movq %s, %s\n",registers[j],reg_des[j]->lexeme);
						reg_des[j]->add_des.reg_no =-1;
						reg_des[j] = NULL;
					}
				}
			}
			getReg(i);
		}

		free(ir);
		free(leaders);*/
	}

