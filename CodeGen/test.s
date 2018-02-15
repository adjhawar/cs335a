.data
a:  .quad  0
b:  .quad  0
c:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
 .globl main 
 main:
movq $100,a
	 movq a,%rax
	 shlq $2,%rax
	 movq %rax,b
	 movq a,%rax
	 shrq $2,%rax
	 movq %rax,c
movq $str,%rdi
 movq b,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
movq $str,%rdi
 movq c,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 ret
