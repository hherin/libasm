			section	.text
			global	_ft_strlen
_ft_strlen:
			xor		rcx, rcx
.loop:
			cmp		byte [rdi + rcx], 0
			je		.end
			inc		rcx
			jne		.loop
.end:
			mov		rax, rcx
			ret
