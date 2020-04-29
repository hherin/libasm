
			section	.text
			global	_ft_write
			extern	___error
_ft_write:
			mov		rbx, rdx
			mov		rdx, 0				; check with size 0
			mov		eax, 0x2000004
			syscall
			cmp		rax, 0
			jne		.error
			cmp		rbx, 0
			je		.end
			mov		rdx, 1				; check with size 1
			mov		eax, 0x2000004
			syscall
			cmp		rax, 1
			jne		.error
			cmp		rbx, rax
			je		.end
			mov		rdx, rbx			; do with good size
			dec		rdx
			inc		rsi
			mov		eax, 0x2000004
			syscall
			inc		rax
			ret
.end:
			ret
.error:
			mov		rcx, rax
			push	rcx
			call	___error
			pop		rcx
			mov		[rax], rcx
			mov		rax, -1
			ret

