				section	.text
				global	ft_strdup
				extern	malloc
				extern	ft_strcpy
				extern	ft_strlen
				extern	__errno_location
ft_strdup:
				xor		rax, rax
				call	ft_strlen
				push	rdi				; save string for malloc
				inc		rax				; size + 1
				mov		rdi, rax ; parameter for malloc
				call	malloc
				test	rax, rax
				je		.error
				pop		rdi				; string back
				mov		rsi, rdi
				mov		rdi, rax
				call	ft_strcpy
				ret

.error:
				call	__errno_location
				mov		qword [rax], 1
				mov		rax, 0
				ret