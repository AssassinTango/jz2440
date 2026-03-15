.text

.global _start

_start:
    //close watchdog
    ldr r0, =0x53000000
    mov r1, #0
    str r1, [r0]

    //auto NAND/Nor
    mov r1, #0
    ldr r0, [r1]    //save val[0]
    str r1, [r1]    //write val[0]=0, then read val[0], if val[0]==0, NAND
    ldr r2, [r1]
    cmp r1, r2

    @ nor启动
    ldr sp, =0x40000000+4096

    @ nand启动
    moveq sp, #4096
    streq r0, [r1]  //恢复val[0]原值

    bl main

halt:
    b halt
