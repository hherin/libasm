default rel
			section	.text
			global	_ft_write
_ft_write:
			mov		eax, 0x2000004
			syscall
			ret

