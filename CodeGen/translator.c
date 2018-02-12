#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "global.h"
#include <ctype.h>

int nline, size;
SymtabEntry *head,*tail;

SymtabEntry* look_up(char *lex){
	SymtabEntry *temp = head;
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
		printf("The token already exists in the Symbol table %s\n", tem->lexeme);
		return tem;
	}
	else
	{
		SymtabEntry *temp = malloc(sizeof(SymtabEntry));
		temp->liveness = false;
		temp->nextuse = -1;
		strcpy(temp->lexeme,lex);
		if(strcmp(lex, "0")==0 || atoi(lex)) 
			strcpy(temp->type,"const");
		temp->next=NULL;
		temp->add_des.reg_no = -1;
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
	}
	
}


int main(){
	/*int nline=0, size=0;
	SymtabEntry *head=NULL,*tail=NULL;*/
	nline=0;
	size=10;
	head=NULL;
	tail=NULL;
	FILE *fptr = fopen("IL_Program.csv","r");
	ir = malloc(size * sizeof(Instruction3AC));
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
			nline = atoi(strs[0]);
			char *key = strs[1];
			ir[nline].label=false;
			if(strcmp(key,"=")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = assgn;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
			}
			else if(strcmp(key,"+")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = add;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
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
				if(!strcmp(strs[2],"=="))
					ir[nline].op=eq;
				else if(!strcmp(strs[2],"!="))
					ir[nline].op=ne;
				else if(!strcmp(strs[2],"<="))
					ir[nline].op=le;
				else if(!strcmp(strs[2],">="))
					ir[nline].op=ge;
				else if(!strcmp(strs[2],"<"))
					ir[nline].op=lt;	
				else if(!strcmp(strs[2],">"))
					ir[nline].op=gt;
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
				ir[nline].target = atoi(strs[5]);
				ir[nline].label=true;
			}
			else if(strcmp(key,"Goto")==0){
				ir[nline].typ = Goto;
				ir[nline].target = atoi(strs[2]);
				ir[atoi(strs[2])].label=true;
			}
			else if(strcmp(key,"ret")==0){
				ir[nline].typ = ret;
			}
			else if(strcmp(key,"call")==0){
				ir[nline].typ = call;
				ir[nline].in1 = Insert(strs[2]);
				ir[nline].label = true;
			}
			else if(strcmp(key,"label")==0){
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
			else if(strcmp(key,"&")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = and;
				ir[nline].out = Insert(strs[2]);
				ir[nline].in1 = Insert(strs[3]);
				ir[nline].in2 = Insert(strs[4]);
			}
			else if(strcmp(key,"|")==0){
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
		}
	}
	SymtabEntry* temp=head;            // setting up data regions for global variables
	while(temp!=NULL)
	{
          printf(".DATA\n");
	  if(strcmp(temp->type,"const"))
	  {
	    printf("%s  DD ?\n",temp->lexeme);
	  }
	temp=temp->next;
	}
	for(int i=0;i<nline;i++)
		getReg(i);
}
