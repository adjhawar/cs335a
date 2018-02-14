#include <stdbool.h>
//global variables

enum InstrType{ Assignment , Pointer , Indexed_Ass , ifgoto , Goto , ret , call , label , print , scan};
enum TACkeywords{add , sub , mul , divi , mod , gt , lt , ge , le , ne , eq , assgn ,  and, or , neg , rsh , lsh , zrsh ,assgn_call};

extern int nline;
extern int size;

// Data structure for address descriptor
typedef struct Add_des{
	int reg_no;
	bool mem;
}Add_des;

//Data structure to hold symbol table
typedef struct SymtabEntry{
	char lexeme[100];
	char type[100];
	Add_des add_des;
	int nextuse;
	bool liveness;
	struct SymtabEntry *next;
}SymtabEntry;

//SymtabEntry* look_up(char *lex);

extern SymtabEntry *head;
extern SymtabEntry *tail;
extern int *leaders;

//Data structure to hold 3ac instruction
typedef struct Instruction3AC{
	enum InstrType typ; // assign, goto...
	SymtabEntry *in1;
	bool in1_liveness;
	int in1_nextuse;
	SymtabEntry *in2;
	bool in2_liveness;
	int in2_nextuse;
	SymtabEntry *out;
	bool out_liveness;
	int out_nextuse;
	int target; // jump target
	enum TACkeywords op;
	bool label;
} Instruction3AC;

//Register descriptor
// eax = 0, ebx = 1, ecx = 2, edx = 3, esi = 4 , edi = 5

SymtabEntry *reg_des[14] ; //array of pointers for register descriptor

char registers[14][5];

//To store IL code 
Instruction3AC *ir;

void getReg(int i);
int empty_reg(int i);
void reg_alloc();
void update(int i, int j);
