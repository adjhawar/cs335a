.data
x:  .quad  0
y:  .quad  0
temp0:  .quad  0
temp1:  .quad  0
temp2:  .quad  0
i:  .quad  0
a:  .quad  0
temp3:  .quad  0
j:  .quad  0
temp4:  .quad  0
temp5:  .quad  0
call:  .quad  0
temp6:  .quad  0
str:   .string "%d \n"
str1:   .string "%d"
 .text
.globl comp
comp:	movq $10,x
movq $4,y
	 mov x,%rax
	 cmpq y,%rax
	 jg L1
movq $0,temp0
	 jmp L0
L1:	movq $1,temp0
L0:		 mov temp0,%rax
	 cmpq $0,%rax
	 je L3
	 movq x,%rax
	 subq y,%rax
	 movq %rax,temp1
	 ret
movq %rax,temp1
movq temp1,%rax
	 jmp L2
L3:		 movq y,%rax
	 subq x,%rax
	 movq %rax,temp2
	 ret
movq %rax,temp2
movq temp2,%rax
L2:	.globl main
main:	movq $0,i
movq $6,a
L11:		 mov i,%rax
	 cmpq $10,%rax
	 jl L5
movq $0,temp3
	 jmp L4
L5:	movq $1,temp3
L4:		 mov temp3,%rax
	 cmpq $0,%rax
	 je L12
movq $str,%rdi
 movq a,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
movq $0,j
L8:		 mov j,%rax
	 cmpq $10,%rax
	 jl L7
movq $0,temp4
	 jmp L6
L7:	movq $1,temp4
L6:		 mov temp4,%rax
	 cmpq $0,%rax
	 je L9
movq $str,%rdi
 movq j,%rsi
 movq $0,%rax
pushq %r10 
 pushq %r11 
 call printf 
 popq %r11 
 popq %r10 
L10:		 movq j,%rax
	 addq $1,%rax
	 movq %rax,j
	 jmp L8
L9:		 movq i,%rax
	 addq $1,%rax
	 movq %rax,i
	 jmp L11
L12:		 call comp
movq %rax,temp5
movq %rax,j
	 movq $0,%rax
	 subq $1,%rax
	 movq %rax,temp6
	 ret
movq %rax,temp6
movq temp6,%rax
