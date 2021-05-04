; ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
;
; %rax result register
; %rbx miscellaneous register
; %rcx fourth argument register
; %rdx third argument register
; %rsi second argument register
; %rdi first argument register
; %rsp stack pointer
; %rbp frame pointer

section .text		; code

global _ft_write	; function name ft_write

_ft_write:
	mov	rax, 0x2000004
	syscall
	ret