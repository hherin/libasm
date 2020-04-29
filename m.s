	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%edi, %edi
	movl	$0, -4(%rbp)
	leaq	L_.str(%rip), %rsi
	movl	$1, %edx
	callq	_write
	movl	%eax, %edi
	movl	%edi, -8(%rbp)
	callq	___error
	xorl	%edi, %edi
	movl	(%rax), %ecx
	movl	%ecx, -12(%rbp)
	movl	%edi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"b"


.subsections_via_symbols
