# 42 project : Libasm

## __Index__

* [Presentation](#Presentation)
* [To do list](#To_do_list)
* [Register](#Register)
* [Syscall](#Syscall)
* [NASM command](#NASM_command)

## Presentation

The aim of this project is to get familiar with assembly language.

## To_do_list

- [x] ft_strlen
- [x] ft_strcpy
- [ ] ft_strcmp
- [ ] ft_write
- [ ] ft_read
- [ ] ft_strdup

## __Register__
[__Original__](https://www.codenong.com/cs109851814/)

* [Memory Data Register](#Memory_Data_Register) : AX, BX, CX, DX  
	* [High H & low L](#High_H_and_low_L) : AH, BH, CH, DH & AL, BL, CL, DL  
	* [32bit & 64bit](#32bit_and_64bit) : EAX, EBX, ECX, EDX & RAX, RBX, RCX, RDX  
* [Segment Register](#Segment_Register) : CS, DS, SS, ES, FS ,GS
* [Pointer Register](#Pointer_Register) : IP, SP, BP
	* 32bit : EIP, ESP, EBP
* [Index Registrer](Index_Registrer) : SI, DI
* [Control register](Control_register) : IP, FLAGS

### Memory_Data_Register

	Data storage. Common registers are AX, BX, CX, DX

>AX (Accumlator)
>>Usually used to save the operands for calculating intermediate value, and also to transfer data to peripherals when interacting with I/O devices.  

>BX (Base)
>>Usually used to store the address base during memory addressing, and can cooperate with DI and SI to provide more complex addressing modes.

>CX (Counter)
>>Usyally used to save the number of loop (used by the loop instruction), and can also be used to save parameters for arithmetic operations and bit operations(multipliersm shift numbers. etc).

>DX (Data)
>> Usually used to store data, and occasionally it forms an operand with AX when multiplying and dividing large numbers.

#### High_H_and_low_L
	The four 16-bit registers can be split in to high 8-bits and low 8-bits, namely AH, BH, CH and AL, BL, CL, DL.
	
	these 8 registers are not new registers, but take part of the contents of the corresponding 16-bit registers. Take the actual storage situation of AX as an example.

	HIGH-------------> AX (16-bit) <---------------LOW
	|                       |                       |
	|15|  |  |  |  |  |  | 8| 7|  |  |  |  |  |  | 0|
	|                       |                       |
	|---> AH (HH 8-bit) <---|---> AL (LW 8-bit) <---|

#### 32bit_and_64bit
	At the same time, NASM also supports us to write 32-bit or 64-bit general register size, which are EAX, EBX, ECX, EDX and RAX, RBX, RCX, RDX.

	For example, the original AX is the lower 16-bit of EAX as follows.

	|---------------> RAX (16-bit) <-----------------|
	|                        |--------> EAX <--------|
	|          63~32         |   31~16   |    15~0   |
	|                                    |---> AX <--|

### Segment_Register
	the second one we will introduce the segment registerm because manyu other registers needs to be used together with the segment register. There are 4+2 types of segment registers defined by NASM (the latter two are more after 80386, providing more choices).

>CS (Code)
>>

>DS (Data)
>>

>SS (Stack)
>>

>ES (Extra)
>>

>FS, GS
>>

### Pointer_Register

### Index Registrer

### Control register

## __Syscall__

__Macos XNU (BSD / MACH) :__

	syscall.h :

	SYS_syscall	: 0
	SYS_exit	: 1
	SYS_fork	: 2
	SYS_read	: 3
	SYS_write	: 4
	SYS_open	: 5
	SYS_close	: 6
	SYS_wait4	: 7
	...

	Add 0x2000000 (Example : SYS_exit -> 0x2000001).

__Linux 64-bit :__  
[__More_info__](https://filippo.io/linux-syscall-table/)

	syscall.h :

	SYS_exit	: 60
	SYS_fork	: 57
	SYS_read	: 0
	SYS_write	: 1
	SYS_open	: 2
	SYS_close	: 3
	SYS_wait4	: 61
	...


## __NASM_command__
