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
	head->next=NULL;
	return head;
}

//prints the list
void printList(list3AC *list1){
	list3AC *list=list1;
	while(list){
		printf("%s\n",list->instr);
		list=list->next;
	}
}	

