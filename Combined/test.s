.data
str:   .string "%d \n"
str1:   .string "%d"
 .text
.globl main
main:	
	 pushq %rbp 
	 movq %rsp, %rbp 
	 pushq %rdi 
	 pushq %rsi 
	 pushq %rdx
	 subq $16, %rsp
	 movq $0,-8(%rbp)
	 movq -8(%rbp), %rax
	 addq $2,%rax
	 movq  %rax,-16(%rbp)
	 movq %rax,-8(%rbp)
	 movq %rax,-16(%rbp)
movq $str,%rdi
 movq -8(%rbp),%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	movq %rbp,%rsp 
	 popq %rbp 
	 ret
