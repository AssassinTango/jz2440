
void delay(volatile int time)
{
    while(time--);
}

int led_on(int which)
{
    unsigned int *p_GPFCON = (unsigned int *)0x56000050;
    unsigned int *p_GPFDAT = (unsigned int *)0x56000054;

    if(which == 4)
    {
        /* GPF4 out */
        *p_GPFCON = 0x100;
    }
    else if(which == 5)
    {
        /* GPF5 out */
        *p_GPFCON = 0x400;
    }
    
    /* 输出0 */
    *p_GPFDAT = 0x0;
    return 0;
}

