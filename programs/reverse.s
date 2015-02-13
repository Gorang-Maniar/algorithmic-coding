.include "io.h"

.data
@read the input string into the following array
string: .space 20 
.align 2 

.text
.global main

@Using getstr read a string from terminal. Reverse the string inplace.
@Then the print the string back onto the terminal.

main:
 	getstr string
	ldr r0,=string
	mov r1,#0
	mov r2,#0
	loop:
		ldrb r3,[r0,r1]
		cmp r3,#0
		beq l1
		add r1,r1,#1
		b loop
	l1:
		sub r1,r1,#1
		b l2
	l2:
		cmp r1,r2
		ble end
		ldrb r6,[r0,r2]
		ldrb r3,[r0,r1]
		strb r3,[r0,r2]
		strb r6,[r0,r1]
		add r2,r2,#1
		sub r1,r1,#1
		b l2
	end:
		putstr string

	b exit
@int sys_exit(int status)
        mov r0, #0      @ Return code
        mov r7, #1      @ sys_exit
        svc 0x00000000
 
