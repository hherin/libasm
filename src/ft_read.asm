			section	.text
			global	_ft_read
			extern	___error
_ft_read:
			xor		rax, rax
			cmp		rdx, 0
			je		.end
			mov		rbx, rdx
			mov		rdx, 0
			mov		eax, 0x2000003
			syscall
			cmp		rax, 0
			jne		.error
			mov		rdx, 1
			mov		eax, 0x2000003
			syscall
			cmp		rax, 1
			jne		.error
			cmp		rbx, rax
			je		.end
			mov		rdx, rbx			; do with good size
			dec		rdx
			mov		eax, 0x2000003
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