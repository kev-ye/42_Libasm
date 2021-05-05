; size_t ft_strlen(const char *str)
;
; %rax result register
; %rbx miscellaneous register
; %rcx fourth argument register
; %rdx third argument register
; %rsi second argument register
; %rdi first argument register
; %rsp stack pointer
; %rbp frame pointer

section .text			; code

global _ft_strlen		; function name ft_strlen	

_ft_strlen:
	mov	rax, rdi		; tmp = str

_loop:
	cmp	byte[rax], 0	; if *tmp == '\0'
	jz	_return			; jump to _return if true
	inc	rax				; tmp++
	jmp	_loop			; loop

_return:
	sub	rax, rdi		; tmp = tmp - str
	ret					; return tmp