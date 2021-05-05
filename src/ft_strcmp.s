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
; int		ft_strcmp(const char *s1, const char *s2);

section .text				; code

global _ft_strcmp			; function name ft_strcmp

_ft_strcmp:
	xor rax, rax			; init rax

_loop:
	mov al, byte[rdi]		; char = *s1
	cmp al, byte[rsi]		; char ? *s2
	jne _return				; *s1 != *s2 -> _return
	cmp byte[rdi], 0		; *s1 ? '\0'
	jz _return				; *s1 == '\0' -> _return
	cmp byte[rsi], 0		; *s2 ? '\0'
	jz _return				; *s2 == '\0' -> _return
	inc rdi					; s1++
	inc rsi					; s2++
	jmp _loop				; loop

_return:
	sub eax, dword[rsi]		; int1 = int1 - int2
	ret						; return int1
