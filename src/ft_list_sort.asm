section	.data
struc s_list
.data	resq	1
.next	resq	1
endstruc

section .text
global	_ft_list_sort

_ft_swap:
				mov		r9, [rdi]
				mov		r10, [rsi]
				mov		[rdi], r10
				mov		[rsi], r9
				ret

_ft_list_sort:
				mov		rbx, rdi
				mov		rcx, rsi
				mov		rdi, qword [rbx]
				cmp		qword rdi, 0
				je		.ret
.loop:
				cmp		qword [rdi + s_list.next], 0
				je		.ret
				mov		rsi, qword [rdi + s_list.next]
				mov		r9, rdi
				mov		rdi, [rdi]
				mov		rsi, [rsi]
				call	rcx
				cmp		rax, 0
				jg		.if
				mov		rdi, qword [r9 + s_list.next]
				jmp		.loop
.if:
				call	_ft_swap
				mov		rdi, qword [rbx]
				jmp		.loop
.ret:
				mov		rdi, rbx
				ret

