.include "io.h"

.extern initializeData
.extern displayData

.equ size, 10
.data
.align 4
array: .skip size*4      @allocate memory for an array of words

.text
.global main

main:
	ldr r0, =array
	mov r1, #size
	bl initializeData
	ldr r0, =array
	mov r1, #size
	mov r3,#1
	mov r2,#4
mysum:
	ldr r6,[r0,r3]
	mov r4,r2
	sub r4,r4,#4
	ldr r5,[r0,r4]
	add r6,r6,r5
	str r6,[r0,r2]
	add r2,r2,#4
	add r3,r3,#1
	cmp r3,#10
	bne mysum
	ldr r0, =array
	mov r1, #size
	bl displayData
	b exit

@ code for prefix sum goes here	

@int sys_exit(int status)
        mov r0, #0      @ Return code
        mov r7, #1      @ sys_exit
        svc 0x00000000
