#include <stdbool.h>

extern int maxsize;

typedef struct list3AC{
	char instr[100];
	struct list3AC *next;
}list3AC;

typedef struct Attr{
	char place[50];
	char type[10];
	list3AC *code;
}Attr;

typedef struct Add_des{
	int reg_no;
	bool mem;
}Add_des;

typedef struct SymtabEntry{
	char lexeme[50];
	char type[10];
	Add_des add_des;
	int nextuse;
	bool liveness;
	struct SymtabEntry *next;
}SymtabEntry;

struct Stack{
	int size;
	Attr *attr;
};

extern SymtabEntry *head,*tail;
struct Stack* createIntStack();
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, Attr *attr);
Attr pop(struct Stack* stack);
list3AC* getTail(list3AC *list);
list3AC* append(list3AC* head1, list3AC* head2);
list3AC* newList(char *str);
void printList(list3AC *list);
SymtabEntry* look_up(char *lex);
SymtabEntry* Insert(char* lex, char *type);
