	.file	"rand.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	strtol
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L3:
	call	rand
	movl	%eax, %edx
	movl	$.LC0, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cltq
	cmpq	-8(%rbp), %rax
	jl	.L3
	movl	$0, %eax
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
