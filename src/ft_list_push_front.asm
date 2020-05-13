extern	_malloc
extern	___error

section	.data
struc s_list
.data	resq	1
.next	resq	1
endstruc

section .text
global _ft_list_push_front

_ft_list_push_front:
			mov		r9, [rdi]
			push	rdi
			push	rsi
			mov		rdi, s_list_size
			call	_malloc
			cmp		rax, 0
			je		.err
			pop		rsi
			pop		rdi
			mov		qword [rax + s_list.data], rsi
			mov		qword [rax + s_list.next], r9
			mov		[rdi], rax
			ret
.err:
			call	___error
			mov		qword [rax], 12
			ret