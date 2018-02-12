	.file	"reg_alloc.c"
	.text
	.p2align 4,,15
	.globl	fact_dw
	.type	fact_dw, @function
fact_dw:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L2:
	imull	%edx, %eax
	subl	$1, %edx
	testl	%edx, %edx
	jg	.L2
	rep ret
	.cfi_endproc
.LFE0:
	.size	fact_dw, .-fact_dw
	.ident	"GCC: (GNU) 7.1.1 20170621"
	.section	.note.GNU-stack,"",@progbits
