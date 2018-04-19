#include <stdbool.h>
//global variables

enum InstrType{ Assignment , Pointer , Ind_Ass_1 , Ind_Ass_2 , ifgoto , Goto , Ret , call , label , print , scan , func};
enum TACkeywords{add , sub , mul , divi , mod , gt , lt , ge , le , ne , eq , assgn ,  and, or , neg , rsh , lsh ,assgn_call};

extern int nline;
extern int size;
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
	list3AC *code;
	bool assign;
}Attr;

typedef struct SymtabEntry{
	char lexeme[50];
	char type[15];
	Arr_dim *arr_dim;
	struct SymtabEntry *next;
	struct Symtab *func;
	bool assign;
	int offset;
}SymtabEntry;

typedef struct Symtab{
	SymtabEntry *head;
	SymtabEntry *tail;
	char name[10];
	struct Symtab *prev;	
}Symtab;

extern Symtab *mainTable;
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

// Data structure for address descriptor
typedef struct Add_des{
	int reg_no;
	bool mem;
}Add_des;

//Data structure to hold symbol table
typedef struct liveTable{
	char lexeme[100];
	char type[100];
	Add_des add_des;
	int nextuse;
	bool liveness;
	struct liveTable *next;
}liveTable;

//liveTable* look_up(char *lex);

extern liveTable *head;
extern liveTable *tail;
extern int *leaders;

//Data structure to hold 3ac instruction
typedef struct Instruction3AC{
	enum InstrType typ; // assign, goto...
	liveTable *in1;
	bool in1_liveness;
	int in1_nextuse;
	liveTable *in2;
	bool in2_liveness;
	int in2_nextuse;
	liveTable *out;
	bool out_liveness;
	int out_nextuse;
	char target[20]; // jump target
	enum TACkeywords op;
	bool label;
	int l;	//stores the index of the array
} Instruction3AC;

//Register descriptor
// eax = 0, ebx = 1, ecx = 2, edx = 3, esi = 4 , edi = 5

liveTable *reg_des[14] ; //array of pointers for register descriptor

char registers[14][5];

//To store IL code 
Instruction3AC *ir;

void getReg(int i);
int empty_reg(int i);
void reg_alloc();
void update(int i, int j);
