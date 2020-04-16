extern	_ft_strlen
			section	.text
			global	_ft_atoi_base
_ft_atoi_base:
			xor		rax, rax
			call	_ft_strlen
			jmp		.error_base

.error_base:
			