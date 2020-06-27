			section	.text
			extern	ft_strlen
			global	ft_atoi_base

ft_checkbase:
			xor		rax, rax
			cmp		byte [rdi], 0		; end string character
			je		.ret
			cmp		byte [rdi], 33		; last space
			jle		.err
			cmp		byte [rdi], 45		; plus
			je		.err
			cmp		byte [rdi], 43		; minus
			je		.err
			jmp		.ret
.err:
			mov		rax, 1
			ret
.ret:
			mov		rax, 0
			ret

ft_double_base:
			xor		rdx, rdx				; i = 0
			mov		rbx, rdx
			inc		rbx						; j = 1
.loop1:
			cmp		byte [rdi + rdx], 0		; end of 1st while
			je		.end_loop
			cmp		byte [rdi + rbx], 0		; end of 2nd while
			je		.loop2
			mov		ch, byte [rdi + rdx]
			mov		cl, byte [rdi + rbx]
			cmp		ch, cl
			je		.ret_z					; error
			inc		rbx
			jmp		.loop1
.loop2:
			inc		rdx
			mov		rbx, rdx
			inc		rbx
			jmp		.loop1
.end_loop:
			mov		rax, 0
			ret
.ret_z:
			mov		rax, 1
			ret

ft_error_base:
			mov		r8, rdi
			cmp		rdi, 0
			je		.error
			call	ft_strlen
			cmp		rax, 2
			jl		.error
			call	ft_double_base
			cmp		rax, 1
			je		.error
.while:
			cmp		byte [rdi], 0
			je		.end_while
			call	ft_checkbase
			cmp		rax, 1
			je		.error
			inc		rdi
			jmp		.while
.end_while:
			mov		rdi, r8
			mov		rax, 0
			ret
.error:
			mov		rdi, r8
			mov		rax, 1
			ret

ft_inbase:
			xor		rcx, rcx
			xor		rbx, rbx
.loop:
			cmp		byte [rsi + rcx], 0
			je		.ret_err
			mov		rbx, [rdi]
			mov		bh, byte [rsi + rcx]
			cmp		bh, bl
			je		.ret
			inc		rcx
			jmp		.loop
.ret:
			mov		rax, rcx
			ret
.ret_err:
			mov		rax, -1
			ret

ft_atoi_base:
			mov		r9, rdi
			mov		rdi, rsi
			call	ft_error_base
			cmp		rax, 1
			je		.error
			call	ft_strlen
			mov		r11, rax				; size of base
			mov		rsi, rdi
			mov		rdi, r9
			xor		r9, r9					; return value
.space:
			cmp		byte [rdi], 0
			je		.ret
			cmp		byte [rdi], 33
			mov		rax, 1					; set the sign
			jge		.sign
			inc		rdi
			jmp		.space
.sign:
			cmp		byte [rdi], 43
			je		.positiv
			cmp		byte [rdi], 45
			je		.negativ
			mov		r10, rax
			jne		.convert
.positiv:
			imul	rax, 1
			inc		rdi
			jmp		.sign
.negativ:
			imul	rax, -1
			inc		rdi
			jmp		.sign
.convert:
			cmp		byte [rdi], 0
			je		.ret
			call	ft_inbase
			cmp		rax, -1
			je		.ret
			mov		rcx, rax
			mov		rax, r11
			imul	rax, r9
			add		rax, rcx
			mov		r9, rax
			inc		rdi
			jmp		.convert
.error:
			mov		rax, 0
			ret
.ret:
			mov		rax, r9
			imul	rax, r10
			ret