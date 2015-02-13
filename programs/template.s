	.global	array
	.data
	.align	2
	.type	array, %object
	.size	array, 40
num1:
	.word 0x03
	.word 0x04
	.word 0x01
	.word 0x7FFFFFFE
	.word 0x80000000
	.word 0xFF
	.word 0xEF
	.word 0xFFFFFFFF
	.word 0x07
	.word 0x09
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@loading the address of the array num1 into register r4
	ldr r4, .L6 @ Or This :  ldr r4,=num1
	@r4 has the address of the 1st word in num1 array which is 0x03
	
	@start your code here
	mov r0,#0
	mov r2,#0
	mov r3,#0
	mov r6,#0
	mov r7,#0
	mov r9,#0
	mov r10,#0
	mov r11,#0
mysum:
	ldr r5,[r4,r6]
	add r7,r7,r5
	add r6,r6,#4
	add r9,r9,#1
	cmp r9,r2
	bne mysum
	bl avg
reg:
	bl myScan
	cmp r1,#-1
	beq mysum
	str r1,[r4,r0]
	add r0,r0,#4
	add r2,r2,#1
	b reg


max:	
	cmp r3,#0
	ldreq r5,[r4,#0]
	ldreq r8,[r4,#0]
	addeq r10,r10,#1
	addeq r3,r3,#4
	beq max
	ldr r6,[r4,r3]
	cmp r5,r6
	movgt r5,r6
	cmp r8,r6
	movlt r8,r6
	add r3,r3,#4
	add r10,r10,#1
	cmp r10,r2
	beq final
	b max
avg:
	cmp r7,r2
	blt max
	sub r7,r7,r2
	add r11,r11,#1
	bl avg
final:
	mov r1,r8
	bl myPrint
	mov r1,r5
	bl myPrint
	mov r1,r11
	bl myPrint
	bl exit
	@end you code here

.L6:
	.word num1
.global	myPrint
myPrint:
	@prints an integer present in r1
	stmfd	sp!,{r0,r1,r2,r3,r7, lr}
	add	r7, sp, #0
	adr 	r0, .LC0
	bl	printf
	mov	r0, #0
	ldmfd	sp!,{r0,r1,r2,r3,r7, pc}


.global myScan
myScan:
	@scans an integer and returns it in r1
	stmfd   sp!, {r0,r2,r3,r7, lr}
	sub 	sp, sp, #8
	add     r7, sp, #0
	adr     r0, .LC1
	add	r1, sp, #4
	bl      scanf
	ldr	r1, [sp, #4]
	mov     r0, #0
	add	sp, sp, #8
	ldmfd	sp!,{r0,r2,r3,r7, pc}


.LC0:
	.ascii	"%d\012\000"
	.align 2
.LC1:
	.ascii "%d\000"
	.align 2
