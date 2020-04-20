extern	_ft_strlen
extern	_ft_write
			section	.text
			global	_ft_atoi_base
;SAVE R8 taille base


_is_good_base:							; this function check if only numbers and letters in base
			cmp		byte [rdi], 48
			jl		.ret_error			; if less than number
			cmp		byte [rdi], 122
			jg		.ret_error			; if more than letter
			cmp		byte [rdi], 57
			jg		.check_between		; between number and letter
			mov		rax, 1
			ret
.check_between:
			cmp		byte [rdi], 65
			jl		.ret_error			; if not a letter
			mov		rax, 1
			ret
.ret_error:
			mov		rax, 0
			ret

_double_base:								; this function check double et call _is_good_base
			mov		r15, 0					; index for current char
.loop_db:
 			add		rdi, r15				; move pointer to check the curent position
			cmp		byte [rdi], 0
			je		.ret_db
			call	_is_good_base
			cmp		rax, 0
			je		.err_db
			sub		rdi, r15				; pointer back to keep initial position of rdi
			mov		rcx, r15				; index for base
			inc		rcx
			mov		bl, byte [rdi + rcx]
			cmp		byte [rdi + r15], bl	; is this char a double ?
			je		.err_db					; return error if same charactere
			inc		r15						; inc counter
			cmp		rcx, r8
			je		.end_loop				; if end of string base go to end_loop
			jmp		.loop_db
.end_loop:
			inc		r15						; inc base counter
			cmp		r15, r8					; compare to size of base
			je		.ret_db					; if all base check go to there
			jmp		.loop_db				; if not all base check
.err_db:
			mov		rax, 1
			ret
.ret_db:
			mov		rax, 0
			ret

_error_base:								; check error for base
			mov		r9, rdi					; save arg1
			mov		rdi, rsi
			call	_ft_strlen
			mov		r8, rax					; save size of base
			cmp		r8, 1					; check size
			jle		.ret_err				; check double in base --- if less go error
			call	_double_base			;check if there is double in base
			cmp		rax, 1
			je		.ret_err
			mov		rax, 0
			ret
.ret_err:
			mov		rax, 1
			ret

_ft_isspace:
			cmp		byte [rdi], 33
			jg		.not_sp
			cmp		byte [rdi], 0
			je		.not_sp
			mov		rax, 1
			ret
.not_sp:
			mov		rax, 0
			ret

_is_inbase:
			xor		rcx, rcx
			mov		rax, -1
.loop_inbase:
			mov		bl, byte [rdi]
			cmp		bl, [rsi + rcx]
			je		.isbase
			inc		rcx
			cmp		r8, rcx
			jne		.loop_inbase
			ret
.isbase:
			mov		rax, rcx
			ret

_ft_atoi_base:
			xor		rcx, rcx		; initialization of return value
			mov		r10, rdi		; save string arg1
			mov		rdi, rsi		; arg1 for error_base
			call	_error_base		; check error of base
			cmp		rax, 1
			je		.end_convert
			mov		rdi, r10		; put arg1 back
			cmp		byte [rdi], 0	; check if string is empty
			jne		.loop_sp
			mov		rax, 0
			ret
.loop_sp:							; move pointer if space
			call	_ft_isspace
			cmp		rax, 0
			je		.loop_sign		; if not space check sign
			inc		rdi
			cmp		byte [rdi], 0
			je		.end_convert
			jmp		.loop_sp
.loop_sign:
			cmp		byte [rdi], 45	; if char is minus
			je		.neg_sign
			cmp		byte [rdi], 43	; if char is plus
			je		.pos_sign
			cmp		byte [rdi], 0	; if end
			je		.end_convert
			jmp		.convert		; if not sign and not end of string go to convert
.neg_sign:
			mov		rbx, -1
			inc		rdi
			jmp		.loop_sign
.pos_sign:
			mov		rbx, 1
			inc		rdi
			jmp		.loop_sign
.convert:
			cmp		byte [rdi], 0	; is end of string ?
			je		.end_convert
			call	_is_inbase		; is number in base ?
			cmp		rax, -1
			je		.end_convert
			imul	rcx, r8			; nb * strlen(base)
			add		rcx, rax		; nb + j  (str[i]=base[j])
			inc		rdi
			jmp		.convert
.end_convert:
			;mov		rcx, r12
			;mul		r12, rbx
			mov		rax, rcx
			imul	rax, rbx
			ret