#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

SymtabEntry* look_up(Symtab *table, char *lex){
	SymtabEntry* temp = table->head;
	if(strcmp(lex, "0")==0 || strcmp(lex, "0\n")==0)
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

SymtabEntry* look_upTable(Symtab *table, char *lex){
	SymtabEntry* temp = table->head;
	if(strcmp(lex, "0")==0 || strcmp(lex, "0\n")==0) 
		return NULL;
	while(temp!=NULL && strcmp(temp->lexeme,lex))
		temp=temp->next;
	return temp;
}

SymtabEntry* Insert(Symtab *table, char* lex, char *type, bool assign)
{
	SymtabEntry *tem = look_upTable(table,lex);
	if(tem){
		return NULL;
	}
	else
	{
		SymtabEntry *temp =(SymtabEntry *)malloc(sizeof(SymtabEntry));
		temp->liveness = false;
		temp->nextuse = -1;
		temp->func=NULL;
		temp->assign=assign;
		temp->arrLength=1;
		strcpy(temp->lexeme,lex);
		strcpy(temp->type,type);
		if(strcmp(lex, "0")==0 || atoi(lex)) 
			strcpy(temp->type,"const");
		temp->next=NULL;
		temp->offset=0;
		temp->add_des.reg_no = -1;
		temp->add_des.mem=false;
		if(table->head==NULL)
		{
			table->head = temp;
			table->tail = temp;
		}
		else
		{
			table->tail->next = temp;
			table->tail = temp;
		}
		return temp;
}
}

void printSymtab(Symtab *table){
	SymtabEntry *temp=table->head;
	printf("%s begins\n",table->name);
	while(temp){
		printf("%s,%s,%d\n",temp->lexeme,temp->type,temp->offset);
		if(temp->func)
			printSymtab(temp->func);
		temp=temp->next;
	}
	printf("%s ends\n",table->name);
}

