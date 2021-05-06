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
;	r9	; fifth argument register
;	r9	; sixth argument register
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
;	char	*ft_strdup(const char *s1);

extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text			; code

global _ft_strdup		; function name ft_strdup

_ft_strdup:
	xor rax, rax
	mov rax, rdi

_cpy:
	mov rsi, rdi
	call _ft_strlen
	add rax, 1
	mov rdx, rax
	call _malloc
	mov rcx, rax
	call _ft_strcpy
	ret

; _return:
; 	ret