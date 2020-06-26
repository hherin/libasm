			section	.text
			global	ft_read
			extern	__errno_location
ft_read:
			mov		rax, 0
			syscall
			cmp		rax, 0
			jl		.error
			ret
.error:
			mov		r9, rax
			call	__errno_location
			neg		r9
			mov		[rax], r9
			mov		rax, -1
			ret