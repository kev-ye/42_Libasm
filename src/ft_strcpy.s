;	NASM x86_64b
;
;	rax : result register
;	rbx : miscellaneous register
;	rcx : fourth argument register
;	rdx : third argument register
;	rsi : second argument register
;	rdi : first argument register
;	rsp : stack pointer
;	rbp : frame pointer
;
;	|---------------> RAX (16-bit) <-----------------|
;	|                        |--------> EAX <--------|
;	|          63~32         |   31~16   |    15~0   |
;	|                                    |---> AX <--|
;
;	HIGH-------------> AX (16-bit) <---------------LOW
;	|                       |                       |
;	|15|  |  |  |  |  |  | 8| 7|  |  |  |  |  |  | 0|
;	|                       |                       |
;	|---> AH (HH 8-bit) <---|---> AL (LW 8-bit) <---|
;
;
; char	*ft_strcpy(char * dst, const char * src);

section .text				; code

global _ft_strcpy			; function name ft_strcpy

_ft_strcpy:
	mov rax, rdi			; tmp_dst = dst
	mov rdx, rsi			; tmp_src = src

_loop:
	mov cl, byte[rdx]		; char = *tmp_src
	cmp cl, 0				; *tmp_src ? '\0'
	jz _return				; *tmp_src == '\0' -> _return
	mov byte[rax], cl		; *tmp_dst = char
	inc rax					; tmp_dst++
	inc rdx					; tmp_src++
	jmp _loop				; loop

_return:
	mov byte[rax], 0		; *tmp_dst = '\0'
	mov rax, rdi			; tmp_dst = dst
	ret						; return dst