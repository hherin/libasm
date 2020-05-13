section	.data
struc s_list
.data	resq	1
.next	resq	1
endstruc

section .text
global	_ft_list_size

_ft_list_size:
			xor		rax, rax
.loop:
			cmp		rdi, 0
			je		.ret
			inc		rax
			mov		rdi, [rdi + s_list.next]
			jmp		.loop
.ret:
			ret