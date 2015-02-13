.include "io.h"

.data
@read the input string into the following array
instring: .space 20 
.align 2 
@the toggled string has to be stored in the following array
outstring: .space 20

.text
.global main

@Using getstr read a string from terminal. Toggle the letter case.
@Then the print the string back onto the terminal.

main:
 	getstr instring
		ldr r0,=instring
		mov r2,#0
		loop:
			ldrb r1,[r0,r2]
			cmp r1,#0
			beq loop2
			cmp r1,#90
			addls r1,r1,#32
			subhi r1,r1,#32
			strb r1,[r0,r2]
			add r2,r2,#1
			b loop
		loop2:
			putstr instring
@int sys_exit(int status)
        mov r0, #0      @ Return code
        mov r7, #1      @ sys_exit
        svc 0x00000000
 
