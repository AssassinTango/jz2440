/* 点亮LED GPF5 */
.text
.global _start

_start:

/* 配置GPF5为输出引脚 */
    ldr r0, =0x56000050
    ldr r1, =0x400
    str r1, [r0]

/* GPF5输出低电平 */
    ldr r0, =0x56000054
    ldr r1, =0
    str r1, [r0]

halt:
    b halt
