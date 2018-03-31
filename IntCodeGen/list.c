#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "list.h"
#include "y.tab.h"

int maxsize = 100;
struct Stack* createIntStack(){
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->size = -1;
	stack->attr = (Attr*) malloc(maxsize * sizeof(Attr));
	return stack;
}

int isFull(struct Stack* stack){
   return stack->size == maxsize - 1; 
}
 
int isEmpty(struct Stack* stack){
   return stack->size == -1;
}

void push(struct Stack* stack, Attr *attr){
    if (stack == NULL){
        printf("Invalid argument. stack pointer is NULL.\n");
    }
    else if (stack->attr == NULL) {
        printf("Stack not initialized.\n");
            return;
    }
    else if (stack->size == maxsize) {
        printf("Stack is full\n");
        return;
    }
    else{
    	stack->size += 1; 
	strcpy(stack->attr[stack->size].place, attr->place);
	stack->attr[stack->size].code = attr->code;
	}
}

Attr pop(struct Stack* stack){
    if (isEmpty(stack))
        printf("Empty stack\n");
    return stack->attr[stack->size--];
}
 

//returns the tail of the list
list3AC* getTail(list3AC *list){
	while(list->next)
		list=list->next;
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
void printList(list3AC *list){
	while(list){
		printf("%s\n",list->instr);
		list=list->next;
	}
}
