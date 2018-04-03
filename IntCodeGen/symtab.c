#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//Data structure to hold symbol table
SymtabEntry* look_up(Symtab *table, char *lex){
	SymtabEntry* temp = table->entry;
	if(strcmp(lex, "0")==0 || strcmp(lex, "0\n")==0 || atoi(lex)) 
		return NULL;
	while(temp!=NULL && strcmp(temp->lexeme,lex))
		temp=temp->next;
	if(temp)
		return temp;
	else if (table->prev)
		return look_up(table->prev,lex);
	else
		return NULL;
}

SymtabEntry* Insert(Symtab *table, char* lex, char *type)
{
	SymtabEntry *tem = look_up(table,lex);
	if(tem){
		return tem;
	}
	else
	{
		SymtabEntry *temp =(SymtabEntry *)malloc(sizeof(SymtabEntry));
		temp->liveness = false;
		temp->nextuse = -1;
		strcpy(temp->lexeme,lex);
		strcpy(temp->type,type);
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
}
}
