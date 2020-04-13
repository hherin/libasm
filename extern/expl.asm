	section .text
	global _foo
_foo:
			mov rax, 0x2000004
			mov rdi, 1
			mov rdx, 3
			syscall
	mov rax,3
	ret



				section	.text
			global	_ft_strcmp
_ft_strcmp:
			xor		rdx, rdx
			xor		rax, rax
			xor		rcx, rcx
			mov		r8, rdi
			mov		r9, rsi


.loop:
			mov		rax, [rdi + rcx]
			mov		rdx, [rsi + rcx]
			cmp		rax, 0
			je		.end
			cmp		rdx, 0
			je		.end
			cmp		rax, rdx
			jne		.end
			inc		rcx
			je		.loop

.end:
			sub		rax, rdx
			ret