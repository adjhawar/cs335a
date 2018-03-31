extern int maxsize;

typedef struct list3AC{
	char instr[100];
	struct list3AC *next;
}list3AC;

typedef struct Attr{
	char place[50];
	list3AC *code;
}Attr;


struct Stack{
	int size;
	Attr *attr;
};

struct Stack* createIntStack();
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, Attr *attr);
Attr pop(struct Stack* stack);
list3AC* getTail(list3AC *list);
list3AC* append(list3AC* head1, list3AC* head2);
list3AC* newList(char *str);
void printList(list3AC *list);
