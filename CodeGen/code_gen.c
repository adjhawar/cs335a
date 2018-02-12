#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <string.h>

char registers[6][4] = { "EAX","EBX","ECX","EDX","ESI","EDI"};
int R_x,R_y,R_z;
  
void getReg(int i)
{
	int r;
	if(ir[i].label==true)
		printf("L%d\t:",ir[i].target);
	if(ir[i].typ==Assignment)
	{
		if(ir[i].op==assgn){
			if(ir[i].in1->add_des.reg_no==-1)	
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} 
			if(ir[i].out->add_des.reg_no==-1)
				printf("\t mov [%s],%s\n",ir[i].out->lexeme,registers[r]);
			else{
				printf("\t mov %s,%s\n",registers[ir[i].out->add_des.reg_no],registers[r]);
				reg_des[ir[i].out->add_des.reg_no]=NULL;
			}
			reg_des[r]=ir[i].out;
			ir[i].out->add_des.reg_no=r;
			ir[i].in1->add_des.reg_no=-1;
		}	
		else if(ir[i].op==add)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t add %s,%d\n",registers[r],atoi(ir[i].in1->lexeme));
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t add %s,[%s]\n",registers[r],ir[i].in2->lexeme);
			else
				printf("\t add %s,%s\n",registers[r],registers[ir[i].in2->add_des.reg_no]);
			printf("\t mov [%s],%s\n"),ir.out->lexeme,registers[r];
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		//division, multiplication,negation,shifts,normal assignemnt
		if(ir[i].op==sub)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t sub %s,%d\n",registers[r],atoi(ir[i].in1->lexeme));
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t sub %s,[%s]\n",registers[r],ir[i].in2->lexeme);
			else
				printf("\t sub %s,%s\n",registers[r],registers[ir[i].in2->add_des.reg_no]);
			printf("\t mov [%s],%s\n"),ir.out->lexeme,registers[r];
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		if(ir[i].op==mul)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t imul %s,%d\n",registers[r],atoi(ir[i].in1->lexeme));
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t imul %s,[%s]\n",registers[r],ir[i].in2->lexeme);
			else
				printf("\t imul %s,%s\n",registers[r],registers[ir[i].in2->add_des.reg_no]);
			printf("\t mov [%s],%s\n"),ir.out->lexeme,registers[r];
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		if(ir[i].op==and)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t and %s,%d\n",registers[r],atoi(ir[i].in1->lexeme));
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t and %s,[%s]\n",registers[r],ir[i].in2->lexeme);
			else
				printf("\t and %s,%s\n",registers[r],registers[ir[i].in2->add_des.reg_no]);
			printf("\t mov [%s],%s\n"),ir.out->lexeme,registers[r];
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		if(ir[i].op==or)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t or %s,%d\n",registers[r],atoi(ir[i].in1->lexeme));
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t or %s,[%s]\n",registers[r],ir[i].in2->lexeme);
			else
				printf("\t or %s,%s\n",registers[r],registers[ir[i].in2->add_des.reg_no]);
			printf("\t mov [%s],%s\n"),ir.out->lexeme,registers[r];
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		else if(ir[i].op==divi){
			;//left
		}
	}
	else if(ir[i].typ==call)
		printf("\t call %s\n",ir[i].in1->lexeme);
	else if(ir[i].typ==Goto)
		printf("\t jmp L%d\n",ir[i].target);
	else if(ir[i].typ==ifgoto){
		//implement the cmp call
		if(ir[i].in1->add_des.reg_no==-1)
		{
			r=empty_reg(i) ; //this function returns a empty registers
			printf("\t mov %s,[%s]\n",registers[r],ir[i].in1->lexeme);
			ir[i].in1->add_des.reg_no=r;
			reg_des[r]=ir[i].in1;
		}
		if(strcmp(ir[i].in2->type,"const")==0)
			printf("\t cmp %s,%d\n",registers[ir[i].in1->add_des.reg_no],atoi(ir[i].in2->lexeme));
		else if(ir[i].in2->add_des.reg_no==-1)
			printf("\t cmp %s,[%s]\n",registers[ir[i].in1->add_des.reg_no],ir[i].in2->lexeme);
		else
			printf("\t cmp %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[ir[i].in2->add_des.reg_no]);
		switch(ir[i].op){
			case eq:printf("\t je L%d\n",ir[i].target);
				break;
			case ne:printf("\t jne L%d\n",ir[i].target);
				break;
			case le:printf("\t jle L%d\n",ir[i].target);
				break;
			case ge:printf("\t jge L%d\n",ir[i].target);
				break;
			case lt:printf("\t jl L%d\n",ir[i].target);
				break;
			case gt:printf("\t jg L%d\n",ir[i].target);
				break;}
	}
	else if(ir[i].typ==ret)
		printf("\t ret\n");
}

int empty_reg(/*SymtabEntry* a,*/ int lineno)
{
	/*if(ir[lineno].in1 == a){
		if(a->add_des.reg_no != -1 && ir[lineno].in1_nextuse==-1) return a->add_des.reg_no;
	}
	else if(ir[lineno].in2 == a){
		if(a->add_des.reg_no != -1 && ir[lineno].in2_nextuse==-1) return a->add_des.reg_no;
	}
	else{*/
		for(int i=0;i<6;i++)
		{
			if(reg_des[i] == NULL)
				return i;
		}
		int max = reg_des[0]->nextuse;
		int l = 0;
		for (int i=0; i<6; i++){
			if(max < reg_des[i]->nextuse){
				max = reg_des[i]->nextuse;
				l = i;
			}
		}
		return l;
	}
//}







   /*for(int i=0;i<6;i++)
   {
     if(reg_des[i]->add_des->mem)
     {
       return i;
     }
   }
   printf("mov [%s],%s",reg_des[1]->lexexe,registers[reg_des[1]->add_des.reg_no]) // empty the registers no 1 
   return 1;*/



