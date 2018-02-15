.data
i:  .quad  0
a:  .quad  0
c:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
 .globl main 
 main:
movq $0,i
	 movq $10,%rax
	 andq $15,%rax
	 movq %rax,a
movq %rax,a
movq $str,%rdi
 movq a,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 movq $10,%rax
	 orq $15,%rax
	 movq %rax,c
movq %rax,c
movq $str,%rdi
 movq c,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 ret
