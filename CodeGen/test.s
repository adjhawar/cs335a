.data
a:  .quad  0
b:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
 .globl main 
 main:
movq $2,a
L2:		 movq 3,%rax
	 subq $3,%rax
	 movq %rax,b
	 movq a,%rbx
	 addq %rax,%rbx
	 movq %rbx,a
	 cmp $50,%rbx
	 jle L2
L5:		 call foo
	 ret
foo:	push %rbp 
 movq $0, %rax  
 movq $str1, %rdi  
 movq $a, %rsi  
 call scanf 
 pop %rbp
movq $str,%rdi
 movq a,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 CALL printf 
 popq %r11 
 popq %r10 
	 ret
