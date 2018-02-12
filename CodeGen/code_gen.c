#include<stdio.h>
#include<stdlib.h>
#include<global.h>
char register[6][4] = { "EAX","EBX","ECX","EDX","ESI","EDI"};
int R_x,R_y,R_z;
void main()
{
for(int i=0;i<nline;i++)
{
  if(ir[i].typ==Assignment)
  {
      if(ir[i].op!=assgn)
      {
        getReg(i);
/*        if(strcmp(reg_des[R_y]->lexeme,ir[i].in1->lexeme))
        {
          printf("mov %s,[%s]\n",register[R_y],ir[i].in1->lexeme);
        }
        if(strcmp(reg_des[R_z]->lexeme,ir[i].in2->lexeme))
        {
          printf("mov %s,[%s]\n",register[R_z],ir[i].in2->lexeme);
        }
        switch(op)
        {
          case add : printf("add %s,%s\n",register[R_y],register[R_z]);
                     break; 
          case sub : printf("sub %s,%s\n",register[R_y],register[R_z]);
                     break; 
          case mul : printf("imul %s,%s\n",register[R_y],register[R_z]);
                     break;
          case divi : printf("idiv %s\n",register[R_z]);
                     break; 
          case mod : printf("idiv %s\n",register[R_z]);
                     break; 


        
        
        
        }*/
        
        printf("mov %s,%s\n",register[R_x],register[R_y]);     
      }
  
  
  }



}
  
void getReg(int i)
{
	int r;
	if(ir[i].typ==Assignment)
	{
		if(ir[i].op==add || ir[i].op==sub || ir[i].op==and || ir[i].op==or || ir[i].op==xor)
		{
			if(ir[i]->out->add_des.reg_no==-1)
				{
					r=empty_reg() ; //this function returns a empty register
					printf("mov %s,[%s]\n",register[r],ir[i]->out->lexeme);
					ir[i]->out->add_des.reg_no=r;
					reg_des[r]=ir[i]->out;
				} //make for every operator
			
			if(strcmp(ir[i]->in1->type,"const")==0)
				printf("add %s,%d\n",register[ir[i]->out->add_des.reg_no],atoi(ir[i]->in1->lexeme));
			else if(ir[i]->in1->add_des.reg_no==-1)
				printf("add %s,[%s]\n",register[ir[i]->out->add_des.reg_no],ir[i]->in1->lexeme);
			else
				printf("add %s.%s\n",register[ir[i]->out->add_des.reg_no],register[ir[i]->in1->add_des.reg_no]);
			
			if(strcmp(ir[i]->in1->type,"const")==0)
				printf("add %s,%d\n",register[ir[i]->out->add_des.reg_no],atoi(ir[i]->in1->lexeme));
			else if(ir[i]->in2->add_des.reg_no==-1)
				printf("add %s,[%s]\n",register[ir[i]->out->add_des.reg_no],ir[i]->in2->lexeme);
			else
				printf("add %s.%s\n",register[ir[i]->out->add_des.reg_no],register[ir[i]->in2->add_des.reg_no]);
			}
		else if(ir[i].op==div){
			//left
		}
	}
		}

}

 int empty_reg()
 {
   for(int i=0;i<6;i++)
   {
     if(reg_des[i]==NULL)
     {
       return i;
     }
   }
   for(int i=0;i<6;i++)
   {
     if(reg_des[i]->add_des->mem)
     {
       return i;
     }
   }
   printf("mov [%s],%s",reg_des[1]->lexexe,register[reg_des[1]->add_des.reg_no]) // empty the register no 1 
   return 1;
 }
  
  
  
  
  
  }
  







}
