			section	.text
			global	_ft_strcmp
_ft_strcmp:
			xor		rax, rax
			cld
.loop:
			cmp		byte [rsi], 0
			jz		.end
			cmp		byte [rdi], 0
			jz		.end
			cmpsb
			jz		.loop

.end:
			mov		rax, [rsi]
			sub		rax, [rdi]
			ret