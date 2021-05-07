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
; ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

%define SYS_DARWIN_WRITE 0x2000004
%define SYS_LINUX_WRITE 0x1

extern ___error						; include errno

section .text						; code

global _ft_write					; function name ft_write

_ft_write:
	mov	rax, SYS_DARWIN_WRITE
	syscall
	jc _errno						; jump to _errno if error at syscall
	ret

_errno:
	mov r10, rax					; save the errno value to r10 (a free register)
	call ___error					; call errno, get result in rax register
	mov qword[rax], r10				; put the errno value in rax register
	mov rax, -1						; set -1 as the return value
	ret