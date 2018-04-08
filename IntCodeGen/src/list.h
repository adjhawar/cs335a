#include <stdbool.h>

extern int maxsize;

typedef struct list3AC{
	char instr[100];
        int cont,br,swt,swt_len;
	struct list3AC *next;
}list3AC;

typedef struct Arr_dim
{
	char d[15];
	struct Arr_dim *next;
}Arr_dim;

typedef struct Attr{
	char place[50];
	char type[15];
	char idx[10];
	bool assign;
	list3AC *code;
}Attr;

typedef struct Add_des{
	int reg_no;
	bool mem;
}Add_des;

typedef struct SymtabEntry{
	char lexeme[50];
	char type[15];
	Arr_dim *arr_dim;
	bool arr;
	struct SymtabEntry *next;
	struct Symtab *func;
	Add_des add_des;
	int nextuse;
	bool liveness;
	bool assign;
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
SymtabEntry* Insert(Symtab *table, char* lex, char *type, bool assign);
void printSymtab(Symtab *table);
void patchBreak(list3AC* list, char* z);
void patchContinue(list3AC* list, char* z);
void patchSwitch(list3AC* list, char* z);
