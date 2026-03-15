#include "s3c2440_soc.h"

void delay(volatile int time)
{
    while(time--);
}

int main()
{
    int val1, val2;

    // 配置GPF0 GPF2 GPG3输入
    GPFCON &= ~((3 << 0) | (3 << 4));   //in 00
    GPGCON &= ~(3 << 6);   //in 00

    //GPF 456配置输出
    GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));   //按位清0
    GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));   //out 01
    
    //输出0
    while(1)
    {
        val1 = GPFDAT;
        val2 = GPGDAT;
        
        if(val1 & (1 << 0)) // s2->d10(gpf0-gfp4) 松开
        {
            GPFDAT |= (1 << 4);
        }
        else    //按下
        {
            GPFDAT &= ~(1 << 4);
        }

        if(val1 & (1 << 2)) // s3->d10(gpf2-gfp5) 松开
        {
            GPFDAT |= (1 << 5);
        }
        else    //按下
        {
            GPFDAT &= ~(1 << 5);
        }

        if(val2 & (1 << 3)) // s4->d10(gpg3-gfp6) 松开
        {
            GPFDAT |= (1 << 6);
        }
        else    //按下
        {
            GPFDAT &= ~(1 << 6);
        }
    }

    return 0;
}

