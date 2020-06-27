			section	.text
			global	ft_strlen
ft_strlen:
			mov		rcx, 0
			cmp		rdi, 0
			je		.end
.loop:
			cmp		byte [rdi + rcx], 0
			je		.end
			inc		rcx
			jne		.loop
.end:
			mov		rax, rcx
			ret
