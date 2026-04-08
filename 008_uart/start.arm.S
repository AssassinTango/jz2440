.text

.global _start

_start:
    //close watchdog
    ldr r0, =0x53000000
    mov r1, #0
    str r1, [r0]

    //LOCKTIME(0x4c000000)=0xFFFFFFFF
    ldr r0, =0x4c000000
    ldr r1, =0xFFFFFFFF
    str r1, [r0]

    //CLKDIVN(0x4C000014)=0x5, F:H:P=1:4:8
    ldr r0, =0x4C000014
    ldr r1, =0x5
    str r1, [r0]

    //CPU mode
    mrc p15,0,r0,c1,c0,0
    orr r0,r0, #0xc0000000  //#R1_nF:OR:R1_iA
    mcr p15,0,r0,c1,c0,0

    //MPLLCON(0x4C000004)=0x
    ldr r0, =0x4C000004
    ldr r1, =(0x5c << 12) | (1 << 4) | (1 << 0)
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
