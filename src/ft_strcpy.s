			section	.text
			global	ft_strcpy
ft_strcpy:
			mov		r9, rdi
			cld
.loop:
			cmp		byte [rsi], 0
			movsb
			je		.end
			jmp		.loop

.end:
			mov		rax, r9
			ret
