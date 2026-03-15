.text

.global _start

_start:
    ldr sp, =4096
    //ldr sp, =0x40000000
    bl main

halt:
    b halt
