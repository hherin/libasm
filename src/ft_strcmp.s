			section	.text
			global	ft_strcmp
ft_strcmp:
			xor		rdx, rdx

.loop:
			xor		rax, rax
			mov		al, byte [rdi]
			mov		dl, byte [rsi]
			sub		rax, rdx
			jz		.zero
			jnz		.end

.zero:
			cmp		byte [rsi], 0
			mov		rax, 0
			je		.end
			inc		rdi
			inc		rsi
			jne		.loop

.end:
			ret