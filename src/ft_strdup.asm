
				section	.text
				global	_ft_strdup
				extern	_malloc
				extern	_ft_strcpy
				extern	_ft_strlen
				extern	___error
_ft_strdup:
				xor		rax, rax
				call	_ft_strlen
				push	rdi				; save string for malloc
				inc		rax				; size + 1
				mov		rdi, rax ; parameter for malloc
				call	_malloc
				test	rax, rax
				je		.error
				pop		rsi				; string back
				mov		rdi, rax
				call	_ft_strcpy
				ret

.error:
				call	___error
				mov		qword [rax], 12
				ret