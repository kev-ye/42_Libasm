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
	xor rcx, rcx			; init rcx

_loop:
	mov al, byte[rdi]		; char1 = *s1
	mov cl, byte[rsi]		; char2 = *s2 
	cmp al, cl				; char1 ? char2
	jne _return				; char1 != char2 -> _return
	cmp al, 0				; char1 ? '\0'
	jz _return				; char1 == '\0' -> _return
	cmp cl, 0				; char2 ? '\0'
	jz _return				; char2 == '\0' -> _return
	inc rdi					; s1++
	inc rsi					; s2++
	jmp _loop				; loop

_return:
	sub eax, ecx			; int1 = int1 - int2
	ret						; return int1
