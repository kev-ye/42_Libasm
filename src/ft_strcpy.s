; char	*ft_strcpy(char * dst, const char * src);
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

global _ft_strcpy		; function name ft_strcpy

_ft_strcpy:
	mov rax, rdi		; tmp_dst = dst
	mov rdx, rsi		; tmp_src = src

_loop:
	mov cl, byte [rdx]	; c = *tmp_src
	cmp cl, 0			; if *tmp_src == '\0'
	jz _return			; jump to _return if true
	mov byte [rax], cl	; *tmp_dst = c
	inc rax				; tmp_dst++
	inc rdx				; tmp_src++
	jmp _loop			; loop

_return:
	mov byte[rax], 0	; *tmp_dst = '\0'
	mov rax, rdi		; tmp_dst = dst
	ret					; return dst