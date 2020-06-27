extern	malloc
extern	__errno_location

section	.data
struc s_list
.data	resq	1
.next	resq	1
endstruc

section .text
global ft_list_push_front

ft_list_push_front:
			push	rdi
			push	rsi
			mov		rdi, s_list_size
			call	malloc
			cmp		rax, 0
			je		.err
			pop		rsi
			pop		rdi
			mov		r9, [rdi]
			mov		qword [rax + s_list.data], rsi
			mov		qword [rax + s_list.next], r9
			mov		[rdi], rax
			ret
.err:
			call	__errno_location
			mov		qword [rax], 12
			mov		rax, 0
			ret