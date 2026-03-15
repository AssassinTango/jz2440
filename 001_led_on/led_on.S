/* 点亮LED GPF4 */
.text
.global _start

_start:

/* 配置GPF4为输出引脚, CONF=0x100 */
    ldr r0, =0x56000050
    ldr r1, =0x100
    str r1, [r0]

/* GPF4输出低电平, DATA=0x0 */
    ldr r0, =0x56000054
    ldr r1, =0
    str r1, [r0]

halt:
    b halt
