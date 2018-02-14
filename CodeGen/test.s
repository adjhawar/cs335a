.data
a:  .quad  0
d:  .quad  0
b:  .quad  0
c:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
 .globl main 
 main:
movq $400,a
movq $4,d
	 movq $0,%rdx
	 movq a,%rax
	 movq $4,%rbx
	 idiv %rbx
	 movq %rax,b
movq %rax,b
movq $str,%rdi
 movq b,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 movq $0,%rdx
	 movq b,%rax
	 idivq d
	 movq %rdx,c
movq $str,%rdi
 movq c,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 ret
movq %rax,%rax
