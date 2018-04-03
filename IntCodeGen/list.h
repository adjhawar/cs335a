#include <stdbool.h>

extern int maxsize;

typedef struct list3AC{
	char instr[100];
	struct list3AC *next;
}list3AC;

typedef struct Attr{
	char place[50];
	char type[15];
	list3AC *code;
}Attr;

typedef struct Add_des{
	int reg_no;
	bool mem;
}Add_des;

typedef struct SymtabEntry{
	char lexeme[50];
	char type[15];
	struct SymtabEntry *next;
	struct Symtab *func;
	Add_des add_des;
	int nextuse;
	bool liveness;
}SymtabEntry;

typedef struct Symtab{
	SymtabEntry *head;
	SymtabEntry *tail;
	char name[10];
	struct Symtab *prev;	
}Symtab;

list3AC* getTail(list3AC *list);
list3AC* append(list3AC* head1, list3AC* head2);
list3AC* newList(char *str);
void printList(list3AC *list);
SymtabEntry* look_up(Symtab *table, char *lex);
SymtabEntry* look_upTable(Symtab *table, char *lex);
SymtabEntry* Insert(Symtab *table, char* lex, char *type);
void printSymtab(Symtab *table);
