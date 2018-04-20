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
	 subq $24, %rsp
	 movq $0,-8(%rbp)
	 movq $5,-16(%rbp)
	 movq -16(%rbp),%rdi
	 call fact
	 movq %rax,-24(%rbp) 
	 movq %rax,-8(%rbp)
	movq %rbp,%rsp 
	 popq %rbp 
	 ret
.globl fact
fact:	
	 pushq %rbp 
	 movq %rsp, %rbp 
	 pushq %rdi 
	 pushq %rsi 
	 pushq %rdx
	 subq $32, %rsp
L2:		 movq -8(%rbp), %rax
	 cmpq $0,%rax
	 jne L1
	 movq $0,-24(%rbp)
	 jmp L0
L1:		 movq $1,-24(%rbp)
L0:		 movq -24(%rbp), %rax
	 cmpq $0,%rax
	 je L3
	 movq -8(%rbp),%rax
	 movq -32(%rbp),%rax
	 subq $1,%rax
	 movq  %rax,-8(%rbp)
	 movq -8(%rbp),%rdi
	 call fact
	 movq %rax,-40(%rbp) 
	 movq %rax,-16(%rbp)
	 movq %rax,-8(%rbp)
movq $str,%rdi
 movq -16(%rbp),%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 jmp L2
L3:		 movq -8(%rbp), %rax
	movq %rbp,%rsp 
	 popq %rbp 
	 ret
