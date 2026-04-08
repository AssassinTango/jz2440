#include "s3c2440_soc.h"

void uart0_init()
{
    /* GPIO设置为UART， GPH2-TXD GPH3-RXD */
    GPHCON &= ~(3 << 4 | 3 << 6);
    GPHCON |= (2 << 4 | 2 << 6);

    /* pull up */
    GPHUP &= ~(1 << 2 | 1 << 3);

    /* 初始化UART，数据位，停止位，校验位 */
    UCON0 |= (2 << 10 | 1 << 2 | 1 << 0); //PCLK, interrupt mode

    ULCON0 |= (3 << 0); //8n1

    /* 波特率 */
    UBRDIV0 = 26;   //115200

    
}

int putchar(int c)
{
    while(!(UTRSTAT0 & (1 << 2)))
    {
        ;
    }

    UTXH0 = (unsigned char)c;
    return 0;
}

int getchar(void)
{
    while(!(UTRSTAT0 & (1 << 0)))
    {
        ;
    }
    return URXH0;
}

int puts(const char *s)
{
    while(*s)
    {
        putchar(*s);
        s++;
    }
}

