#include <stdbool.h>

extern int maxsize;
extern int nline;
extern int size;


enum InstrType{ Assignment , Pointer , Ind_Ass_1 , Ind_Ass_2 , ifgoto , Goto , Ret , call , label , print , scan , func};
enum TACkeywords{add , sub , mul , divi , mod , gt , lt , ge , le , ne , eq , assgn ,  and, or , neg , rsh , lsh ,assgn_call};

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
	bool assign;			//checks if an attribute is declared before it is used
}Attr;

typedef struct Add_des{
	int reg_no;
	bool mem;
}Add_des;

typedef struct SymtabEntry{
	char lexeme[50];
	char type[15];
	Arr_dim *arr_dim;
	struct SymtabEntry *next;
	struct Symtab *func;
	bool assign;			//checks if symbol table entry has been declared
	int offset;
	int arrLength;
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

// Data structure for address descriptor

//Data structure to hold 3ac instruction
typedef struct Instruction3AC{
	enum InstrType typ; // assign, goto...
	enum TACkeywords op;
	SymtabEntry *in1;
	bool in1_liveness;
	int in1_nextuse;
	SymtabEntry *in2;
	bool in2_liveness;
	int in2_nextuse;
	SymtabEntry *out;
	bool out_liveness;
	int out_nextuse;
	char target[20]; // jump target
	bool label;
	int l;	//stores the index of the array
} Instruction3AC;

extern Symtab *mainTable;
extern SymtabEntry *currentTable;
SymtabEntry *reg_des[14] ; //array of pointers for register descriptor

char registers[14][5];

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

Instruction3AC *ir;	// to store 3AC

void getReg(int i);
int empty_reg(int i);
void reg_alloc();
void update(int i, int j);
void translator(list3AC *list);
