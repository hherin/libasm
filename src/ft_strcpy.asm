
			section	.text
			global	_ft_strcpy
_ft_strcpy:
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
