.extern printf
.extern scanf
.extern stdout

.data
.Lstrscan: .asciz "%s"
.Lintscan: .asciz "%d"
.align 2
lstdout:
.Lstdout: .word stdout

.macro putstr strparam
        push {r0-r3,r12}

        ldr r0, =\strparam
	bl printf
	ldr r0, =.Lstdout
	ldr r0, [r0]
	ldr r0, [r0]
	bl fflush	
        pop {r0-r3,r12}
.endm

.macro getstr strparam
	push {r0-r3,r12}
	ldr r1, =\strparam
	ldr r0, =.Lstrscan
	bl scanf 
	pop {r0-r3,r12}
.endm
