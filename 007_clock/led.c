
void delay(volatile int time)
{
    while(time--);
}

int main()
{
    unsigned int *p_GPFCON = (unsigned int *)0x56000050;
    unsigned int *p_GPFDAT = (unsigned int *)0x56000054;
    int val = 1;

    //GPF 456配置输出
    *p_GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));   //按位清0
    *p_GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));   //设置成01
    
    //输出0
    while(1)
    {
        *p_GPFDAT |= (7 << 4);
        *p_GPFDAT &= ~(val << 4);
        val = val << 1;
        delay(100000*10);
        if(val == 8)
        {
            val = 1;
        }
    }

    return 0;
}

