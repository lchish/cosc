	.file	"merge-sort.c"
	.text
.globl insertion_sort
	.type	insertion_sort, @function
insertion_sort:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	$1, -12(%rbp)
	jmp	.L2
.L6:
	movl	-12(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.L3
.L5:
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx,%rdx
	salq	$2, %rdx
	addq	-24(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	subl	$1, -4(%rbp)
.L3:
	cmpl	$0, -4(%rbp)
	js	.L4
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-8(%rbp), %eax
	jg	.L5
.L4:
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movl	%edx, (%rax)
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L6
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	insertion_sort, .-insertion_sort
.globl merge
	.type	merge, @function
merge:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	$0, -12(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%rdx,%rax), %eax
	sarl	%eax
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L9
.L13:
	movl	-12(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L10
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-32(%rbp), %rax
	movl	-12(%rbp), %edx
	movslq	%edx,%rdx
	salq	$2, %rdx
	addq	-24(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -12(%rbp)
	jmp	.L11
.L10:
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx,%rdx
	salq	$2, %rdx
	addq	-24(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -8(%rbp)
.L11:
	addl	$1, -4(%rbp)
.L9:
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%rdx,%rax), %eax
	sarl	%eax
	cmpl	-12(%rbp), %eax
	jle	.L19
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L13
	jmp	.L14
.L15:
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-32(%rbp), %rax
	movl	-12(%rbp), %edx
	movslq	%edx,%rdx
	salq	$2, %rdx
	addq	-24(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
	addl	$1, -12(%rbp)
	jmp	.L14
.L19:
	nop
.L14:
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%rdx,%rax), %eax
	sarl	%eax
	cmpl	-12(%rbp), %eax
	jg	.L15
	jmp	.L16
.L17:
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx,%rdx
	salq	$2, %rdx
	addq	-24(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
	addl	$1, -8(%rbp)
.L16:
	movl	-8(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L17
	leave
	ret
	.cfi_endproc
.LFE1:
	.size	merge, .-merge
.globl merge_sort
	.type	merge_sort, @function
merge_sort:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	cmpl	$1, -36(%rbp)
	jle	.L27
.L21:
	cmpl	$42, -36(%rbp)
	jle	.L23
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%rdx,%rax), %eax
	sarl	%eax
	movl	%eax, %edx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	merge_sort
	movl	-36(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%rdx,%rax), %eax
	sarl	%eax
	movl	-36(%rbp), %edx
	subl	%eax, %edx
	movl	-36(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	leal	(%rcx,%rax), %eax
	sarl	%eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	merge_sort
	movl	-36(%rbp), %edx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	merge
	movl	$0, -4(%rbp)
	jmp	.L24
.L25:
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx,%rdx
	salq	$2, %rdx
	addq	-32(%rbp), %rdx
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L24:
	movl	-4(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L25
	jmp	.L26
.L23:
	movl	-36(%rbp), %edx
	movq	-32(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	insertion_sort
	nop
	jmp	.L26
.L27:
	nop
.L26:
	leave
	ret
	.cfi_endproc
.LFE2:
	.size	merge_sort, .-merge_sort
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	subq	$800016, %rsp
	movl	$0, -4(%rbp)
	jmp	.L29
.L31:
	addl	$1, -4(%rbp)
.L29:
	cmpl	$99999, -4(%rbp)
	jg	.L30
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	-400016(%rbp), %rax
	addq	%rdx, %rax
	movl	$.LC0, %edx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	scanf
	cmpl	$1, %eax
	je	.L31
.L30:
	movl	-4(%rbp), %edx
	leaq	-800016(%rbp), %rcx
	leaq	-400016(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	merge_sort
	movl	$0, -8(%rbp)
	jmp	.L32
.L33:
	movl	-8(%rbp), %eax
	cltq
	movl	-400016(%rbp,%rax,4), %edx
	movl	$.LC1, %eax
	movl	%edx, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	addl	$1, -8(%rbp)
.L32:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L33
	movl	$0, %eax
	leave
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
