#include<stdio.h>
#include<stdlib.h>

typedef struct list3AC{
	char instr[100];
	struct list3AC *next;
}list3AC;

//returns the tail of the list
list3AC* getTail(list3AC *list){
	while(list->next)
		list=list->next;
	return list;
}

//join two lists
list3AC* append(list3AC* head1, list3AC* head2){
	list3AC* tail1=getTail(head1);
	tail1->next=head2;	
	return head1;
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

/*
int main(){
	int i=0;
	list3AC *head=newList("a");
	list3AC *head1=newList("1");
	list3AC *t=head;
	for(i=0;i<10;i++){
		if(i==9)
			t->next=newList("c");
		else
			t->next=newList("b");
		t=t->next;
		t->next=NULL;
	}
	t=head1;
	for(i=0;i<10;i++){
		if(i==9)
			t->next=newList("3");
		else
			t->next=newList("2");
		t=t->next;
		t->next=NULL;
	}
	head=append(head1,head);
	printList(head);
	return 0;
}	*/
