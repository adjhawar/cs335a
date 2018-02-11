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
        if(strcmp(reg_des[R_y]->lexeme,ir[i].in1->lexeme))
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
          case mod : printf("add %s,%s\n",register[R_y],register[R_z]);
                     break; 


        
        
        
        }
        
        printf("mov %s,%s\n",register[R_x],register[R_z]);     
      }
  
  
  }



}







}
