# 42 project : Libasm

## Presentation

The aim of this project is to get familiar with assembly language.

## To_do_list

- [ ] ft_strlen
- [ ] ft_strcpy
- [ ] ft_strcmp
- [ ] ft_write
- [ ] ft_read
- [ ] ft_strdup

## Note

__Macos XNU (BSD / MACH) :__

    syscall.h :

    #define SYS_syscall        0
    #define SYS_exit           1
    #define SYS_fork           2
    #define SYS_read           3
    #define SYS_write          4
    #define SYS_open           5
    #define SYS_close          6
    #define SYS_wait4          7

    If need syscall, use number of syscall.h and add 0x2000000 (Example : SYS_exit -> 0x2000001).