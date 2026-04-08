#include "uart.h"
#include "s3c2440_soc.h"

void delay(volatile int time)
{
    while(time--);
}

int main()
{
    unsigned char c = 0;
    uart0_init();
    puts("Hello uart\r\n");

    while(1)
    {
        c = getchar();
        if(c == '\r')
        {
            putchar('\n');
        }
        else if (c == '\n')
        {
            putchar('\r');
        }
        putchar(c);
    }
    return 0;
}

