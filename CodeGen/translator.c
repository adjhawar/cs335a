#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum InstrType{ Assignment , Function , Jump , Pointer , Indexed_Ass , Ifgoto , Goto , Ret , Call , Label , Print , Scan};
enum TACkeywords{add , sub , mul , divi , mod , gt , lt , ge , le , ne , eq , assgn , and , or , neg , rsh , lsh , zrsh };
/*Type descriptions as used in the symbol table
C: Constant
F: Function
G: Goto
I: Identifier
L: Label
P: Print
S: Scan */

int size = 10;
//Data structure to hold symbol table
typedef struct SymtabEntry{
	char type,lexeme[100];
	struct SymtabEntry *next;
}SymtabEntry;

SymtabEntry *head=NULL, *tail=NULL;

SymtabEntry* look_up(char *lex){
	SymtabEntry *temp = head;
	while(temp!=NULL && strcmp(temp->lexeme,lex))
	{
		temp=temp->next;
	}
	return temp;
}

SymtabEntry* Insert(char* lex,char type)
{
	SymtabEntry *tem = look_up(lex);
	if(!tem){
		printf(" The token already exists in the Symbol table \n");
		return tem;
	}
	else
	{
		SymtabEntry *temp = malloc(sizeof(SymtabEntry));
		strcpy(temp->lexeme,lex);
		temp->type=type;
		temp->next=NULL;
		if(head==NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		return temp;
	}
	
}

//checks if input string is number or not
int isNumber(char *str){
	int l=strlen(str);
	while(i<l){
		if(str[i]>='0' && str[i]<='9')
			i++;
		else
			return 0;
	}
	return 1;
}

//Data structure to hold 3ac instruction
typedef struct Instruction3AC{
enum InstrType typ; // assign, goto...
SymtabEntry *in1;
SymtabEntry *in2;
SymtabEntry *out;
int target; // jump target
enum TACkeywords op;
} Instruction3AC;


//To store IL code 
Instruction3AC *ir ;


int main(){
	FILE *fptr = fopen("IL_Program.csv","r");
	ir = malloc(size * sizeof(Instruction3AC));
	//reads the csv file and stores the instructions in 3AC formatr
	if(fptr==NULL){
		printf("Error in opening IL_Program.csv \n . Aborting....");
		exit(0);
	}
	else {
		int nline = 0;
		char line[1024];
		while (fgets(line, 1024, fptr)){
			if (size == nline) {
				size = 2*size;
				ir = realloc(ir, size * sizeof(Instruction3AC));
			}
			char *token;
			char *rest = line;
			char strs[6][100];
			int i = 0;
			while ((token = strtok_r(rest, ", ", &rest))){
				strcpy(strs[i], token);
				i++;
			}
			nline = atoi(strs[0]);
			char *key = strs[1];
			if(strcmp(key,"=")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = assgn;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
			}
			else if(strcmp(key,"+")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = add;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');					if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"-")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = sub;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');

			}
			else if(strcmp(key,"*")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = mul;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"/")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = divi;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"%")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = mod;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"ifgoto")==0){	//relational operators
				ir[nline].typ = Ifgoto;
				if(!strcmp(strs[2],"=="))
					ir[nline].op=eq;
				else if(!strcmp(strs[2],"!="))
					ir[nline].op=ne;
				else if(!strcmp(strs[2],"<="))
					ir[nline].op=le;
				else if(!strcmp(strs[2],">="))
					ir[nline].op=ge;
				else if(!strcmp(strs[2],"<"))
					ir[nline].op=lt;	
				else if(!strcmp(strs[2],">"))
					ir[nline].op=gt;
				ir[nline].out = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
				if(isNumber(str[5]))
					ir[nline].in1=Insert(strs[5],'C');
				else
					ir[nline].in1 = Insert(strs[5],'I');
			}
			else if(strcmp(key,"Goto")==0){
				ir[nline].typ = Goto;
				ir[nline].target = atoi(Insert(strs[2],'G'));
			}
			else if(strcmp(key,"ret")==0){
				ir[nline].typ = Ret;
			}
			else if(strcmp(key,"call")==0){
				ir[nline].typ = Call;
				ir[nline].in1 = Insert(strs[2],'F');
			}
			else if(strcmp(key,"label")==0){
				ir[nline].typ = Label;
				ir[nline].in1 = Insert(strs[2],'L');
			}
			else if(strcmp(key,"print")==0){
				ir[nline].typ = Print;
				ir[nline].in1 = Insert(strs[2],'P');
			}
			else if(strcmp(key,"scan")==0){
				ir[nline].typ = Scan;
				ir[nline].in1 = Insert(strs[2],'S');
			}
			else if(strcmp(key,"&&")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = and;
				ir[nline].out = Insert(strs[2],'C');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"||")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = or;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"~")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = neg;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
			}
			else if(strcmp(key,">>")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = rsh;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,"<<")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = lsh;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
			else if(strcmp(key,">>>")==0){
				ir[nline].typ = Assignment;
				ir[nline].op = zrsh;
				ir[nline].out = Insert(strs[2],'I');
				if(isNumber(str[3]))
					ir[nline].in1=Insert(strs[3],'C');
				else
					ir[nline].in1 = Insert(strs[3],'I');
				if(isNumber(str[4]))
					ir[nline].in1=Insert(strs[4],'C');
				else
					ir[nline].in1 = Insert(strs[4],'I');
			}
		}
	}
}
