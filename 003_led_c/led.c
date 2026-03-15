
int main()
{
    unsigned int *p_GPFCON = (unsigned int *)0x56000050;
    unsigned int *p_GPFDAT = (unsigned int *)0x56000054;

    /* GPF4 out */
    *p_GPFCON = 0x100;
    
    /* GFP4 输出0 */
    *p_GPFDAT = 0x0;
    return 0;
}
