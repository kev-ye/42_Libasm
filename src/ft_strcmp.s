; int		ft_strcmp(const char *s1, const char *s2);
;
; %rax result register
; %rbx miscellaneous register
; %rcx fourth argument register
; %rdx third argument register
; %rsi second argument register
; %rdi first argument register
; %rsp stack pointer
; %rbp frame pointer

section .text

global _ft_strcmp

_ft_strcmp:
	xor rax, rax

_loop:
	mov cl, byte[rdi]
	cmp cl, byte[rsi]
	jne _return
	cmp byte[rdi], 0
	jz _return
	cmp byte[rsi], 0
	jz _return
	inc rdi
	inc rsi
	jmp _loop

_return:
	mov al, cl
	sub al, byte[rsi]
	ret
