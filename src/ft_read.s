; ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
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

global _ft_read		; function name ft_read

_ft_read:
	mov	rax, 0x2000003
	syscall
	ret