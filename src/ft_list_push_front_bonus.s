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
;	void	ft_list_push_front(t_list **begin_list, void *data);

%ifdef __LINUX__
	%define FT_LIST_PUSH_FRONT ft_list_push_front
	%define MALLOC_CALL malloc

%else
	%define FT_LIST_PUSH_FRONT _ft_list_push_front
	%define MALLOC_CALL _malloc
%endif

; void ft_list_push_front(t_list **begin_list, void *data)
; {
;     t_list *element;

;     if ((element = ft_create_elem(data))) // Verify if all of the element are created.
;     {
;         if (*begin_list)
;             element->next = *begin_list;
;         *begin_list = element;
;     }
; }

section .text					; code

global FT_LIST_PUSH_FRONT		; function name ft_list_push_front

FT_LIST_PUSH_FRONT:
	push rdi					; push (save) **begin_list value to stack
	push rsi					; push (save) *data value to stack

	mov rdi, 16					; malloc 16 bytes
	call MALLOC_CALL
	

.return:
	ret