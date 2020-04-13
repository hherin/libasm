			section	.text
			global	_ft_strlen
_ft_strlen:
			xor		rcx, rcx
			xor		rax, rax
.loop:
			cmp		byte [rdi + rcx], 0
			je		.end
			inc		rcx
			jne		.loop
.end:
			add		rax, rcx
			ret
