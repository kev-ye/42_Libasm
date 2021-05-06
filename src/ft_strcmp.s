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
;	int		ft_strcmp(const char *s1, const char *s2);

section .text				; code

global _ft_strcmp			; function name ft_strcmp

_ft_strcmp:
	xor rax, rax			; set rax to 0

_loop:
	mov al, byte[rdi]		; get the current *s1 value
	cmp al, byte[rsi]		; compare *s2 value with *s1 value
	jne _return				; if false, turn to _return
	cmp byte[rdi], 0		; compare *s1 value with '\0'
	jz _return				; if true, turn to _return
	cmp byte[rsi], 0		; compare *s2 value with '\0'
	jz _return				; if true, turn to _return
	inc rdi					; s1++
	inc rsi					; s2++
	jmp _loop				; loop

_return:
	sub eax, dword[rsi]		; set the result of *s1 - *s2 to return value
	ret
