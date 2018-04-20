.data
x:	.quad 11
str:   .string "%d \n"
str1:   .string "%d"
 .text
.globl main
main:	
	 pushq %rbp 
	 movq %rsp, %rbp 
	 subq $40, %rsp
	 movq $7,-8(%rbp)
	 movq $5,-16(%rbp)
	 movq $1,-16(%rbp)
L2:		 movq -16(%rbp), %rax
	 cmpq $10,%rax
	 jl L1
	 movq $0,-24(%rbp)
	 jmp L0
L1:		 movq $1,-24(%rbp)
L0:		 movq -24(%rbp), %rax
	 cmpq $0,%rax
	 je L3
	 movq -8(%rbp), %rax
	 addq $1,%rax
	 movq  %rax,-40(%rbp)
	 movq %rax,-8(%rbp)
L4:		 movq -16(%rbp), %rax
	 addq $1,%rax
	 movq  %rax,-32(%rbp)
	 movq %rax,-16(%rbp)
	 jmp L2
L3:	movq $str,%rdi
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
