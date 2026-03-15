.text

.global _start

_start:
    ldr sp, =4096
    //ldr sp, =0x40000000

led_4_5:
    mov r0, #4
    bl led_on

    ldr r0, =100000
    bl delay

    mov r0, #5
    bl led_on

    ldr r0, =100000
    bl delay

    b led_4_5

halt:
    b halt
