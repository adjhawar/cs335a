#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

char registers[14][5] = { "%rax","%rbx","%rcx","%rdx","%rsi","%rdi","%r8","%r9","%r10","%r11","%r12","%r13","%r14","%r15" };
int R_x,R_y,R_z;
SymtabEntry *currentTable; 
int parCounter=0;
  
void getReg(int i)
{
	int r;
	SymtabEntry * var;
	if(ir[i].typ==func)
	{	printf(".globl %s\n",ir[i].target);
		printf("%s:\t",ir[i].target);
		currentTable = look_up(mainTable, ir[i].target);
		printf("\n\t pushq %%rbp \n\t movq %%rsp, %%rbp ");
		if(look_up(mainTable, ir[i].target)->nargs>0)
			printf("\n\t pushq %%rdi");
		if(look_up(mainTable, ir[i].target)->nargs>1)
			printf("\n\t pushq %%rsi");
		if(look_up(mainTable, ir[i].target)->nargs>2)
			printf("\n\t pushq %%rdx");
		printf("\n\t subq $%d, %%rsp\n",look_up(mainTable, ir[i].target)->offset - look_up(mainTable, ir[i].target)->nargs*8 );
		printf("\n\t pushq %%rbx \n\t pushq %%r12 \n\t pushq %%r13 \n\t pushq %%r14 \n\t pushq %%r15 \n");
	}
	else if(ir[i].typ==label)
		printf("%s:\t",ir[i].target);
	if(ir[i].typ==Ind_Ass_1){
		if(ir[i].out->add_des.reg_no==-1){
			r=empty_reg(i);
			if(var=look_upTable(currentTable->func, ir[i].out->lexeme)){
				printf("\t movq %%rbp,%s\n",registers[r]);
				printf("\t subq $%d,%s\n",var->offset,registers[r]);	
			}
			else
				printf("\t movq $%s,%s\n",ir[i].out->lexeme,registers[r]);
			reg_des[r]=ir[i].out;
			ir[i].out->add_des.reg_no=r;}
		if(strcmp(ir[i].in2->type,"const")==0){
			if(strcmp(ir[i].in1->type,"const")==0){
				printf("\tmovq $%d,%d(%s)\n",atoi(ir[i].in1->lexeme),atoi(ir[i].in2->lexeme)*8,registers[r]);
			}
			else if(ir[i].in1->add_des.reg_no!=-1)
				printf("\tmovq %s,%d(%s)\n",registers[ir[i].in1->add_des.reg_no],atoi(ir[i].in2->lexeme)*8,registers[r]);
			else{
				int temp=empty_reg(i);
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp]);
				else
					printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[temp]);
				reg_des[temp]=ir[i].in1;
				ir[i].in1->add_des.reg_no=temp;
				printf("\t movq %s,%d(%s)\n",registers[temp],atoi(ir[i].in2->lexeme)*8,registers[r]);}
		}
		else if(ir[i].in2->add_des.reg_no!=-1){
			if(strcmp(ir[i].in1->type,"const")==0)
				printf("\t movq $%d,(%s,%s,8)\n",atoi(ir[i].in1->lexeme),registers[r],registers[ir[i].in2->add_des.reg_no]);
			else if(ir[i].in1->add_des.reg_no!=-1)
				printf("\t movq %s,(%s,%s,8)\n",registers[ir[i].in1->add_des.reg_no],registers[r],registers[ir[i].in2->add_des.reg_no]);
			else{
				int temp=empty_reg(i);
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp]);
				else
					printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[temp]);
				reg_des[temp]=ir[i].in1;
				ir[i].in1->add_des.reg_no=temp;
				printf("\t movq %s,(%s,%s,8)\n",registers[temp],registers[r],registers[ir[i].in2->add_des.reg_no]);
			}}
		else {
			int temp1=empty_reg(i);
			if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
				printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp1]);
			else
				printf("\t movq %s,%s\n",ir[i].in2->lexeme,registers[temp1]);
			reg_des[temp1]=ir[i].in2;
			ir[i].in2->add_des.reg_no=temp1;
			if(strcmp(ir[i].in1->type,"const")==0)
				printf("\t movq $%d,(%s,%s,8)\n",atoi(ir[i].in1->lexeme),registers[r],registers[temp1]);
			else if(ir[i].in1->add_des.reg_no!=-1)
				printf("\t movq %s,(%s,%s,8)\n",registers[ir[i].in1->add_des.reg_no],registers[r],registers[temp1]);
			else{
				int temp=empty_reg(i);
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp]);
				else
					printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[temp]);
				reg_des[temp]=ir[i].in1;
				ir[i].in1->add_des.reg_no=temp;
				printf("\t movq %s,(%s,%s,8)\n",registers[temp],registers[r],registers[temp1]);}
		}}
	else if(ir[i].typ==Ind_Ass_2){
		if(ir[i].in1->add_des.reg_no==-1){
			r=empty_reg(i);
			if(var=look_upTable(currentTable->func, ir[i].in1->lexeme)){
				printf("\t movq %%rbp,%s\n",registers[r]);
				printf("\t subq $%d,%s\n",var->offset,registers[r]);	
			}
			else
				printf("\t movq $%s,%s\n",ir[i].in1->lexeme,registers[r]);
			reg_des[r]=ir[i].in1;
			ir[i].out->add_des.reg_no=r;}
		if(strcmp(ir[i].in2->type,"const")==0){
			if(ir[i].out->add_des.reg_no!=-1)
				printf("\tmovq %d(%s),%s\n",atoi(ir[i].in2->lexeme)*8,registers[r],registers[ir[i].out->add_des.reg_no]);
			else{
				int temp=empty_reg(i);
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp]);
				else
					printf("\t movq %s,%s\n",ir[i].out->lexeme,registers[temp]);
				reg_des[temp]=ir[i].out;
				ir[i].out->add_des.reg_no=temp;
				printf("\t movq %d(%s),%s\n",atoi(ir[i].in2->lexeme)*8,registers[r],registers[temp]);}
		}
		else if(ir[i].in2->add_des.reg_no!=-1){
			if(ir[i].out->add_des.reg_no!=-1)
				printf("\tmovq (%s,%s,8),%s\n",registers[r],registers[ir[i].in2->add_des.reg_no],registers[ir[i].out->add_des.reg_no]);
			else{
				int temp=empty_reg(i);
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp]);
				else
					printf("\t movq %s,%s\n",ir[i].out->lexeme,registers[temp]);
				reg_des[temp]=ir[i].out;
				ir[i].out->add_des.reg_no=temp;
				printf("\tmovq (%s,%s,8),%s\n",registers[r],registers[ir[i].in2->add_des.reg_no],registers[ir[i].out->add_des.reg_no]);
			}}
		else{
			int temp1=empty_reg(i);
			if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
				printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp1]);
			else
				printf("\t movq %s,%s\n",ir[i].in2->lexeme,registers[temp1]);
			reg_des[temp1]=ir[i].in2;
			ir[i].in2->add_des.reg_no=temp1;
			if(ir[i].out->add_des.reg_no!=-1)
				printf("\tmovq (%s,%s,8),%s\n",registers[r],registers[temp1],registers[ir[i].out->add_des.reg_no]);
			else{
				int temp=empty_reg(i);
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[temp]);
				else
					printf("\t movq %s,%s\n",ir[i].out->lexeme,registers[temp]);
				reg_des[temp]=ir[i].out;
				ir[i].out->add_des.reg_no=temp;
				printf("\tmovq (%s,%s,8),%s\n",registers[r],registers[temp1],registers[ir[i].out->add_des.reg_no]);}}

		if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
			printf("\t movq %s,-%d(%%rbp)\n",registers[ir[i].out->add_des.reg_no],var->offset);
		else
			printf("\t movq %s,%s\n",registers[ir[i].out->add_des.reg_no],ir[i].out->lexeme);
	}
	else if(ir[i].typ==Assignment)
	{
		if(ir[i].op==assgn){
			if(strcmp(ir[i].in1->type,"const")==0){
				//printf("%s\n",ir[i].in1->lexeme);
				if(ir[i].out->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq $%d,-%d(%%rbp)\n",atoi(ir[i].in1->lexeme),var->offset);
					else
						printf("movq $%d,%s\n",atoi(ir[i].in1->lexeme),ir[i].out->lexeme);
				}
				else{
					ir[i].out->add_des.mem=true;
					printf("movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[ir[i].out->add_des.reg_no]);
				}}
			else if(ir[i].out->add_des.reg_no!=-1)
			{	//			printf("1%s\n",ir[i].in1->lexeme);
				if(ir[i].in1->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[ir[i].out->add_des.reg_no]);
					else
						printf("movq %s,%s\n",ir[i].in1->lexeme,registers[ir[i].out->add_des.reg_no]);
				}
				else
					printf("movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[ir[i].out->add_des.reg_no]);
			}else{		//printf("2%s\n",ir[i].in1->lexeme);		
				if(ir[i].in1->add_des.reg_no==-1){
					r=empty_reg(i);
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[r]);
					else
						printf("movq %s,%s\n",ir[i].in1->lexeme,registers[r]);

					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq -%d(%%rbp),%s\n",var->offset,registers[r]);
					else
						printf("movq %s,%s\n",registers[r],ir[i].out->lexeme);

					ir[i].in1->add_des.reg_no=r;
					reg_des[r]=ir[i].in1;}	
				else

					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq %s,-%d(%%rbp)\n",registers[ir[i].in1->add_des.reg_no],var->offset);
					else
						printf("movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],ir[i].out->lexeme);

				}}		 
		else if(ir[i].op==add)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{        //to do: add condition for constants  
				r=empty_reg(i) ; //this function returns a empty registers
				if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
				else{
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
					else
						printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				}
			} //make for every operator
			else{
				r=ir[i].in1->add_des.reg_no;
			//	printf("\t movq %s,%s\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=-1;
				reg_des[r]=NULL;
			}
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t addq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1){

				if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
					printf("\t addq -%d(%%rbp),%s\n",var->offset,registers[r]);
				else
					printf("\t addq %s,%s\n",ir[i].in2->lexeme,registers[r]);
			}
			else
				printf("\t addq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq  %s,-%d(%%rbp)\n",registers[r],var->offset);
					else
						printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
				ir[i].out->add_des.reg_no=r;
				reg_des[r]=ir[i].out;}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
		else if(ir[i].op==sub)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{        //to do: add condition for constants  
				r=empty_reg(i) ; //this function returns a empty registers
				if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
				else{
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
					else
						printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				}
			} //make for every operator
			else{
				r=ir[i].in1->add_des.reg_no;
			//	printf("\t movq %s,%s\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=-1;
				reg_des[r]=NULL;
			}
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t subq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1){

				if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
					printf("\t subq -%d(%%rbp),%s\n",var->offset,registers[r]);
				else
					printf("\t subq %s,%s\n",ir[i].in2->lexeme,registers[r]);
			}
			else
				printf("\t subq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq  %s,-%d(%%rbp)\n",registers[r],var->offset);
					else
						printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
				ir[i].out->add_des.reg_no=r;
				reg_des[r]=ir[i].out;}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
		else if(ir[i].op==and)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{        //to do: add condition for constants  
				r=empty_reg(i) ; //this function returns a empty registers
				if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
				else{
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
					else
						printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				}
			} //make for every operator
			else{
				r=ir[i].in1->add_des.reg_no;
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq %s,-%d(%%rbp)\n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=-1;
				reg_des[r]=NULL;
			}
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t andq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
					printf("\t andq -%d(%%rbp),%s\n",var->offset,registers[r]);
				else
					printf("\t andq %s,%s\n",ir[i].in2->lexeme,registers[r]);
			else
				printf("\t andq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq %s,-%d(%%rbp)\n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
				ir[i].out->add_des.reg_no=r;
				reg_des[r]=ir[i].out;}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
		else if(ir[i].op==or)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{        //to do: add condition for constants  
				r=empty_reg(i) ; //this function returns a empty registers
				if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
				else{
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
					else
						printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				}
			} //make for every operator
			else{
				r=ir[i].in1->add_des.reg_no;
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq %s,-%d(%%rbp)\n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=-1;
				reg_des[r]=NULL;
			}
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t orq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
					printf("\t orq -%d(%%rbp),%s\n",var->offset,registers[r]);
				else
					printf("\t orq %s,%s\n",ir[i].in2->lexeme,registers[r]);
			else
				printf("\t orq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq %s,-%d(%%rbp)\n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
				ir[i].out->add_des.reg_no=r;
				reg_des[r]=ir[i].out;}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
		else if(ir[i].op==mul)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{        //to do: add condition for constants  
				r=empty_reg(i) ; //this function returns a empty registers
				if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
				else{
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
					else
						printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				}
			} //make for every operator
			else{
				r=ir[i].in1->add_des.reg_no;
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq %s,-%d(%%rbp) \n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].in1->lexeme);
				ir[i].in1->add_des.reg_no=-1;
				reg_des[r]=NULL;
			}
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t imulq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				{
					if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
						printf("\t imulq -%d(%%rbp), %s\n",var->offset,registers[r]);
					else
						printf("\t imulq %s,%s\n",ir[i].in2->lexeme,registers[r]);
				}
			else
				printf("\t imulq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq %s,-%d(%%rbp) \n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
				ir[i].out->add_des.reg_no=r;
				reg_des[r]=ir[i].out;}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
		else if(ir[i].op==divi || ir[i].op==mod)  //mul needs to be changed as div
		{
			if(reg_des[0]){
				if(var=look_upTable(currentTable->func, reg_des[0]->lexeme))
					printf("\t movq %%rax,-%d(%%rbp) \n",var->offset);
				else
					printf("\t movq %%rax,%s\n",reg_des[0]->lexeme);
				reg_des[0]->add_des.reg_no=-1;}	
			if(reg_des[3]){
				if(var=look_upTable(currentTable->func, reg_des[3]->lexeme))
					printf("\t movq %%rdx,-%d(%%rbp) \n",var->offset);
				else
					printf("\t movq %%rdx,%s\n",reg_des[3]->lexeme);
				reg_des[3]->add_des.reg_no=-1;}
			reg_des[3]=ir[i].out;
			reg_des[0]=ir[i].out;
			printf("\t movq $0,%%rdx\n");
			if(strcmp(ir[i].in1->type,"const")==0)
				printf("\t movq $%d,%%rax\n",atoi(ir[i].in1->lexeme));	
			else if(ir[i].in1->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%%rax \n",var->offset);
				else
					printf("\t movq %s,%%rax\n",ir[i].in1->lexeme);
			}
			else
				printf("\t movq %s,%%rax\n",registers[ir[i].in1->add_des.reg_no]);
			if(ir[i].op==divi){
				if(strcmp(ir[i].in2->type,"const")==0){
					r=empty_reg(i);
					if(reg_des[r])
						printf("It is not null. How was it sent. %s\n",reg_des[r]->lexeme);
					printf("\t movq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
					printf("\t idiv %s\n",registers[r]);}
				else if(ir[i].in2->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
						printf("\t idivq -%d(%%rbp) \n",var->offset);
					else
						printf("\t idivq %s\n",ir[i].in2->lexeme);
				}
				else
					printf("\t idivq %s\n",registers[ir[i].in2->add_des.reg_no]);
				reg_des[3]=NULL;
				if(ir[i].out->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq %%rax,-%d(%%rbp) \n",var->offset);
					else
						printf("\t movq %%rax,%s\n",ir[i].out->lexeme);
					ir[i].out->add_des.reg_no=0;}
				else{
					reg_des[0]=NULL;
					printf("\t movq %%rax,%s\n",registers[ir[i].out->add_des.reg_no]);}}
			if(ir[i].op==mod){
				if(strcmp(ir[i].in2->type,"const")==0){
					r=empty_reg(i);
					printf("\t movq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
					printf("\t idiv %s\n",registers[r]);}
				else if(ir[i].in2->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
						printf("\t idivq -%d(%%rbp) \n",var->offset);
					else
						printf("\t idivq %s\n",ir[i].in2->lexeme);
				}
				else
					printf("\t idivq %s\n",registers[ir[i].in2->add_des.reg_no]);
				reg_des[0]=NULL;
				if(ir[i].out->add_des.reg_no==-1){
					if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
						printf("\t movq %%rdx,-%d(%%rbp) \n",var->offset);
					else
						printf("\t movq %%rdx,%s\n",ir[i].out->lexeme);
					ir[i].out->add_des.reg_no=3;}
				else{
					reg_des[3]=NULL;
					printf("\t movq %%rdx,%s\n",registers[ir[i].out->add_des.reg_no]);}}
		}
		else if(ir[i].op==assgn_call)
		{
			printf("\t call %s\n",ir[i].in2->lexeme);
			if(ir[i].out->add_des.reg_no==-1)
			{
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq %s,-%d(%%rbp) \n",registers[0],var->offset);
				else
					printf("movq %s,%s\n",registers[0],ir[i].out->lexeme);
				ir[i].out->add_des.reg_no = 0;
			}
			else
			{
				printf("movq %s,%s\n",registers[0],registers[ir[i].out->add_des.reg_no]);
			}
			parCounter=0;

		}
		else if(ir[i].op==lsh){
			r=empty_reg(i);
			if(ir[i].in1->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
				else
					printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
			}
			else
				printf("\t movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[r]);
			printf("\t shlq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq %s,-%d(%%rbp) \n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
			}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
		else if(ir[i].op==rsh){
			r=empty_reg(i);
			if(ir[i].in1->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
				else
					printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
			}
			else
				printf("\t movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[r]);
			printf("\t shrq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[r]);
			if(ir[i].out->add_des.reg_no==-1){
				if(var=look_upTable(currentTable->func, ir[i].out->lexeme))
					printf("\t movq %s,-%d(%%rbp) \n",registers[r],var->offset);
				else
					printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
			}
			else
				printf("\t movq %s,%s\n",registers[r],registers[ir[i].out->add_des.reg_no]);
		}
	}
	else if(ir[i].typ==call){
		
		printf("\t call %s\n",ir[i].target);
		parCounter=0;
	}
	else if(ir[i].typ==Goto)
		printf("\t jmp %s\n",ir[i].target);
	else if(ir[i].typ==ifgoto){
		//implement the cmp call
		if(ir[i].in1->add_des.reg_no==-1)
		{
			r=empty_reg(i) ; //this function returns a empty registers
			if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
				printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[r]);
			else
				printf("\t mov %s,%s\n",ir[i].in1->lexeme,registers[r]);
			ir[i].in1->add_des.reg_no=r;
			reg_des[r]=ir[i].in1;
		}
		if(strcmp(ir[i].in2->type,"const")==0)
			printf("\t cmpq $%d,%s\n",atoi(ir[i].in2->lexeme),registers[ir[i].in1->add_des.reg_no]);
		else if(ir[i].in2->add_des.reg_no==-1){
			if(var=look_upTable(currentTable->func, ir[i].in2->lexeme))
				printf("\t cmpq -%d(%%rbp), %s\n",var->offset,registers[ir[i].in1->add_des.reg_no]);
			else
				printf("\t cmpq %s,%s\n",ir[i].in2->lexeme,registers[ir[i].in1->add_des.reg_no]);
		}
		else
			printf("\t cmpq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[ir[i].in1->add_des.reg_no]);
		if(ir[i].op==eq)
			printf("\t je %s\n",ir[i].target);
		else if(ir[i].op==ne)
			printf("\t jne %s\n",ir[i].target);
		else if(ir[i].op==ge)
			printf("\t jge %s\n",ir[i].target);
		else if(ir[i].op==le)
			printf("\t jle %s\n",ir[i].target);
		else if(ir[i].op==gt)
			printf("\t jg %s\n",ir[i].target);
		else if(ir[i].op==lt)
			printf("\t jl %s\n",ir[i].target);
	}
	else if(ir[i].typ==Ret){
		if(ir[i].in1!=NULL)
		{
			if(reg_des[0]!=NULL)
			{
				if(var=look_upTable(currentTable->func, reg_des[0]->lexeme))
					printf("\t movq %s,-%d(%%rbp) \n",registers[0],var->offset);
				else
					printf("movq %s,%s\n",registers[0],reg_des[0]->lexeme);
				reg_des[0]->add_des.reg_no =-1;
				reg_des[0] = NULL;

			}
			if(strcmp(ir[i].in1->type,"const")!=0)
			{
				if(ir[i].in1->add_des.reg_no==-1)
				{
					if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
						printf("\t movq -%d(%%rbp), %s\n",var->offset,registers[0]);
					else
						printf("movq %s,%s\n",ir[i].in1->lexeme,registers[0]);
					ir[i].in1->add_des.reg_no=0;
				}
				else
					printf("movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[0]);
			}
			else
				printf("movq $%d,%s",atoi(ir[i].in1->lexeme),registers[0]);
		}
			printf("   \n\t popq %%r15  \n\t popq %%r14\n\t popq %%r13\n\t popq %%r12\n\t popq %%rbx");	
			printf("\n\tmovq %%rbp,%%rsp \n\t popq %%rbp \n");
			printf("\t ret\n");}
	else if(ir[i].typ==print)
	{
		if(reg_des[5]){
			if(var=look_upTable(currentTable->func, reg_des[5]->lexeme))
				printf("\t movq %%rdi,-%d(%%rbp)\n",var->offset);
			else
				printf("movq %%rdi,%s\n",reg_des[5]->lexeme);
			reg_des[5]->add_des.reg_no=-1;
			reg_des[5]=NULL;
		}
		if(reg_des[4]){
			if(var=look_upTable(currentTable->func, reg_des[4]->lexeme))
				printf("\t movq %%rsi,-%d(%%rbp)\n",var->offset);
			else
				printf("movq %%rsi,%s\n",reg_des[4]->lexeme);
			reg_des[4]->add_des.reg_no=-1;
			reg_des[4]=NULL;
		}
		if(reg_des[0]){
			if(var=look_upTable(currentTable->func, reg_des[0]->lexeme))
				printf("\t movq %%rax,-%d(%%rbp)\n",var->offset);
			else
				printf("movq %%rax,%s\n",reg_des[0]->lexeme);
			reg_des[0]->add_des.reg_no=-1;
			reg_des[0]=NULL;
		}
		if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
		printf("movq $str,%%rdi\n movq -%d(%%rbp),%%rsi\n movq $0,%%rax\n",var->offset);
		else
		printf("movq $str,%%rdi\n movq %s,%%rsi\n movq $0,%%rax\n",ir[i].in1->lexeme);
		printf("pushq %%r10 \n pushq %%r11 \n call printf \n popq %%r11 \n popq %%r10 \n");	 
	}
	else if(ir[i].typ==scan)
	{
		if(reg_des[0]){
			if(var=look_upTable(currentTable->func, reg_des[0]->lexeme))
				printf("\t movq %%rax,-%d(%%rbp)\n",var->offset);
			else
				printf("movq %%rax,%s\n",reg_des[0]->lexeme);
			reg_des[0]=NULL;
			reg_des[0]->add_des.reg_no=-1;
		}
		if(reg_des[4]){
			if(var=look_upTable(currentTable->func, reg_des[4]->lexeme))
				printf("\t movq %%rsi,-%d(%%rbp)\n",var->offset);
			else
				printf("movq %%rsi,%s\n",reg_des[4]->lexeme);
			reg_des[4]=NULL;
			reg_des[4]->add_des.reg_no=-1;
		}
		if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
			printf("\n movq $0, %%rax  \n movq $str1, %%rdi  \n movq %%rbp,%%rbx \n subq $%d,%%rbx \n movq  %%rbx,%%rsi  \n call scanf \n",var->offset);
		else
			printf(" \nmovq $0, %%rax  \n movq $str1, %%rdi  \n movq $%s, %%rsi  \n call scanf \n",ir[i].in1->lexeme);
	}
	else if(ir[i].typ == params){
		switch(parCounter)
		{
			case 0 : if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%%rdi\n",atoi(ir[i].in1->lexeme));
				else if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%%rdi\n",var->offset);
				else
					printf("movq %s,%%rdi\n",ir[i].in1->lexeme);
				break;
			case 1 : if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%%rsi\n",atoi(ir[i].in1->lexeme));
				else if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%%rsi\n",var->offset);
				else
					printf("movq %s,%%rsi\n",ir[i].in1->lexeme);
				break;
			case 2 : if(strcmp(ir[i].in1->type,"const")==0)
					printf("\t movq $%d,%%rdx\n",atoi(ir[i].in1->lexeme));
				else if(var=look_upTable(currentTable->func, ir[i].in1->lexeme))
					printf("\t movq -%d(%%rbp),%%rdx\n",var->offset);
				else
					printf("movq %s,%%rdx\n",ir[i].in1->lexeme);
				
		}
		parCounter++;
	}
}

int empty_reg(int lineno)
{
    for(int i=0;i<14;i++)
    {
      if(reg_des[i] == NULL)
        return i;
    }
    int max = reg_des[0]->nextuse;
    int l = 0;
    for (int i=0; i<14; i++){
      if(max < reg_des[i]->nextuse){
        max = reg_des[i]->nextuse;
        l = i;
      }
    }
    if (reg_des[l] != NULL){
//    printf("movq %s %s\n",registers[l],reg_des[l]->lexeme);
    reg_des[l]->add_des.reg_no =-1;
    reg_des[l] = NULL;
	}
    return l;
}
