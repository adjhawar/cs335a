.data
a:  .quad  0
b:  .quad  0
r:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
 .globl main 
 main:
movq $14,a
movq $8,b
L3:		 call gcd
movq $str,%rdi
 movq b,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 ret
movq b,%rax
gcd:		 movq $0,%rdx
	 movq a,%rax
	 idivq %rax
	 movq %rdx,r
movq $str,%rdi
 movq r,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
	 cmp $0,%rax
	 je L13
	 movq %rdx, r
movq %rax,a
movq r,%rax
L12:		 call gcd
L13:		 ret
movq gcd,%rax
