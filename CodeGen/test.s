.data
a:  .quad  0
d:  .quad  0
z:  .quad  0
call:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
 .globl main 
 main:
push %rbp 
 movq $0, %rax  
 movq $str1, %rdi  
 movq $a, %rsi  
 call scanf 
 pop %rbp
movq $1,d
	 call foo
movq %rax,z
movq $str,%rdi
 movq z,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 ret
foo:	L7:		 movq d,%rax
	 imulq a,%rax
	 movq %rax,d
	 movq a,%rbx
	 subq $1,%rbx
	 movq %rbx,a
	 cmpq $2,%rbx
	 jge L7
	 movq %rax, d
	 movq %rbx, a
	 ret
movq d,%rax
