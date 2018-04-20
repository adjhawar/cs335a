#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "list.h"
#include "y.tab.h"

//returns the tail of the list
list3AC* getTail(list3AC *list1){
	list3AC *list=list1;
	if(list){
	while(list->next)
		list=list->next;}
	return list;
}

//join two lists
list3AC* append(list3AC* head1, list3AC* head2){
	if(head1){
		list3AC* tail1=getTail(head1);
		tail1->next=head2;
		return head1;}
	else
		return head2;
}

//creates a new list node and returns its pointer
list3AC* newList(char *str){
	list3AC* head=(list3AC *)malloc(sizeof(list3AC));
	sprintf(head->instr,"%s",str);
        head->cont = 0;
        head->br = 0;
	head->swt=0;
	head->swt_len=19;
	head->next=NULL;
	return head;
}

//prints the list
void printList(list3AC *list1){
	static int count=1;
	list3AC *list=list1;
	while(list){
		printf("%d %s\n",count++,list->instr);
		list=list->next;
	}
}

//back patches jump target on break statements
void patchBreak(list3AC *list1, char* z)
{
	list3AC *list = list1;
	while(list){
		if(list->br)
			{ strcat(list->instr, z);
                          list->br=0;}
		list=list->next;
}       
} 	

//back patches jump target on continue statements
void patchContinue(list3AC *list1, char* z)
{
	list3AC *list = list1;
	while(list){
		if(list->cont)
			{ strcat(list->instr, z);
                          list->cont=0;}
		list=list->next;
}      
 
} 	

//back patches expr of switch into cases
void patchSwitch(list3AC* list1, char* z){
	list3AC *list = list1;
        char str[50];
	while(list){
		if(list->swt){
   			strncpy(str,list->instr,list->swt_len);
			str[list->swt_len]='\0';
			strcat(str,z);
			strcat(str,list->instr+list->swt_len);
			strcpy(list->instr,str);
			list->swt=0;
			}				
		list=list->next;			
	}
}
