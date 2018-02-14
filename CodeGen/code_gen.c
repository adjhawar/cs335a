#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <string.h>

char registers[16][5] = { "%rax","%rbx","%rcx","%rdx","%rsi","%rdi","%rbp","%rsp","%r8","%r9","%r10","%r11","%r12","%r13","%r14","%r15" };
int R_x,R_y,R_z;
  
void getReg(int i)
{
	int r;
	if(ir[i].typ==label)
		printf("%s:\t",ir[i].in1->lexeme);
	else if(ir[i].label==true)
		printf("L%d:\t",i+1);
	if(ir[i].typ==Assignment)
	{
		if(ir[i].op==assgn){
			if(strcmp(ir[i].in1->type,"const")==0){
				if(ir[i].out->add_des.reg_no==-1)
					printf("movq $%d,%s\n",atoi(ir[i].in1->lexeme),ir[i].out->lexeme);
				else{
					ir[i].out->add_des.mem=true;
					printf("movq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[ir[i].out->add_des.reg_no]);
				}}
			else if(ir[i].out->add_des.reg_no!=-1)
			{
				ir[i].out->add_des.mem=true;
				if(ir[i].in1->add_des.reg_no==-1)
					printf("movq %s,%s\n",ir[i].in1->lexeme,registers[ir[i].out->add_des.reg_no]);
				else
					printf("movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[ir[i].out->add_des.reg_no]);
			}else{				
				if(ir[i].in1->add_des.reg_no==-1){
					r=empty_reg(i);
					printf("movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
					printf("movq %s,%s\n",registers[r],ir[i].out->lexeme);
					ir[i].in1->add_des.reg_no=r;
					reg_des[r]=ir[i].in1;}	
				else
					printf("movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],ir[i].out->lexeme);}}		 
		else if(ir[i].op==add)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{        //to do: add condition for constants  
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t addq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t addq %s,%s\n",ir[i].in2->lexeme,registers[r]);
			else
				printf("\t addq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
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
				printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t subq $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t subq %s,%s\n",ir[i].in2->lexeme,registers[r]);
			else
				printf("\t subq %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		if(ir[i].op==mul)  //mul needs to be changed as div
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t imulq %s,$%d\n",registers[r],atoi(ir[i].in1->lexeme));
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t imulq %s,%s\n",registers[r],ir[i].in2->lexeme);
			else
				printf("\t imulq %s,%s\n",registers[r],registers[ir[i].in2->add_des.reg_no]);
			printf("\t movq %s,%s\n",ir[i].out->lexeme,registers[r]);
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		if(ir[i].op==and)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t and $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t and %s,%s\n",ir[i].in2->lexeme,registers[r]);
			else
				printf("\t and %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
		if(ir[i].op==or)
		{
			if(ir[i].in1->add_des.reg_no==-1)
			{
				r=empty_reg(i) ; //this function returns a empty registers
				printf("\t movq %s,%s\n",ir[i].in1->lexeme,registers[r]);
				ir[i].in1->add_des.reg_no=r;
				reg_des[r]=ir[i].in1;
			} //make for every operator
			if(strcmp(ir[i].in2->type,"const")==0)
				printf("\t or $%d,%s\n",atoi(ir[i].in1->lexeme),registers[r]);
			else if(ir[i].in2->add_des.reg_no==-1)
				printf("\t or %s,%s\n",ir[i].in2->lexeme,registers[r]);
			else
				printf("\t or %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[r]);
			printf("\t movq %s,%s\n",registers[r],ir[i].out->lexeme);
			ir[i].in1->add_des.reg_no=-1;
			ir[i].out->add_des.reg_no=r;
			reg_des[r]=ir[i].out;
		}
/*		else if(ir[i].op==divi || ir[i].op==mod){
			//empty the registers edx and eax
			if(ir[i].in1->add_des.reg_no!=0){
				printf("\t mov [%s],EAX\n",reg_des[0]->lexeme);
				reg_des[0]->add_des.reg_no=-1;
				printf("\t mov EAX,[%s]\n",ir[i].in1->lexeme);
			}
			printf("\t mov [%s],EDX\n",reg_des[3]->lexeme);
			reg_des[3]->add_des.reg_no=-1;
			reg_des[3]=NULL;
			printf("\t mov EDX,0\n");
			//store the divisor
			if(ir[i].in2->add_des.reg_no==-1)
				printf("\t idiv [%s]\n",ir[i].in2->lexeme);
			else
				printf("\t idiv %s\n",registers[ir[i].in2->add_des.reg_no]);
			//the result of division is stored in eax and that of modulus is stores in edx
			if(ir[i].op==divi)
				if(ir[i].out->add_des.reg_no==-1)
					printf("\t mov [%s],EAX",ir[i].out);
		else
			printf("\t mov %s
			else
				//store edx in output}*/
                if(ir[i].op==assgn_call)
		{
		    printf("\t call %s\n",ir[i].in2->lexeme);
                    if(ir[i].out->add_des.reg_no==-1)
                    {
			printf("movq %s,%s\n",registers[0],ir[i].out->lexeme);
			ir[i].out->add_des.reg_no = 0;
                    }
    		    else
 		    {
 			printf("movq %s,%s\n",registers[0],registers[ir[i].out->add_des.reg_no]);
		    }
		        
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
			printf("\t mov %s,%s\n",ir[i].in1->lexeme,registers[r]);
			ir[i].in1->add_des.reg_no=r;
			reg_des[r]=ir[i].in1;
		}
		if(strcmp(ir[i].in2->type,"const")==0)
			printf("\t cmp $%d,%s\n",atoi(ir[i].in2->lexeme),registers[ir[i].in1->add_des.reg_no]);
		else if(ir[i].in2->add_des.reg_no==-1)
			printf("\t cmp %s,%s\n",ir[i].in2->lexeme,registers[ir[i].in1->add_des.reg_no]);
		else
			printf("\t cmp %s,%s\n",registers[ir[i].in2->add_des.reg_no],registers[ir[i].in1->add_des.reg_no]);
		if(ir[i].op==eq)
			printf("\t je L%d\n",ir[i].target);
		else if(ir[i].op==ne)
			printf("\t jne L%d\n",ir[i].target);
		else if(ir[i].op==ge)
			printf("\t jge L%d\n",ir[i].target);
		else if(ir[i].op==le)
			printf("\t jle L%d\n",ir[i].target);
		else if(ir[i].op==gt)
			printf("\t jg L%d\n",ir[i].target);
		else if(ir[i].op==lt)
			printf("\t jl L%d\n",ir[i].target);
	}
	else if(ir[i].typ==ret){
		printf("\t ret\n");
		if(ir[i].in1!=NULL)
                {
		   if(reg_des[0]!=NULL)
                     {
                      printf("movq %s,%s\n",registers[0],reg_des[0]->lexeme);
                      reg_des[0]->add_des.reg_no =-1;
                      reg_des[0] = NULL;
                      
}
if(strcmp(ir[i].in1->type,"const")!=0)
{
                if(ir[i].in1->add_des.reg_no==-1)
{
                printf("movq %s,%s\n",ir[i].in1->lexeme,registers[0]);
 		ir[i].in1->add_des.reg_no=0;
}
                else
		printf("movq %s,%s\n",registers[ir[i].in1->add_des.reg_no],registers[0]);
		}
}
else
{
printf("movq $%d,%s",atoi(ir[i].in1->lexeme),registers[0]);
}
        }
        else if(ir[i].typ==print)
        {
	    printf("movq $str,%%rdi\n movq %s,%%rsi\n movq $0,%%rax\n",ir[i].in1->lexeme);
            printf("pushq %%r10 \n pushq %%r11 \n CALL printf \n popq %%r11 \n popq %%r10 \n");	 
        }
        else if(ir[i].typ==scan)
        {
            printf("push %%rbp \n movq $0, %%rax  \n movq $str1, %%rdi  \n movq $%s, %%rsi  \n call scanf \n pop %%rbp\n",ir[i].in1->lexeme);
        }
}

int empty_reg(/*SymtabEntry* a,*/ int lineno)
{
  /*if(ir[lineno].in1 == a){
    if(a.add_des.reg_no != -1 && ir[lineno].in1_nextuse==-1) return a.add_des.reg_no;
  }
  else if(ir[lineno].in2 == a){
    if(a.add_des.reg_no != -1 && ir[lineno].in2_nextuse==-1) return a.add_des.reg_no;
  }
  else{*/
    for(int i=0;i<16;i++)
    {
      if(reg_des[i] == NULL)
        return i;
    }
    int max = reg_des[0]->nextuse;
    int l = 0;
    for (int i=0; i<16; i++){
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
     if(reg_des[i].add_des.mem)
     {
       return i;
     }
   }
   printf("mov [%s],%s",reg_des[1].lexexe,registers[reg_des[1].add_des.reg_no]) // empty the registers no 1 
   return 1;*/


