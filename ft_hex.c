#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int hex(unsigned long long x)
{
    //if (x == 0)
    //{
    //    write(1, "0", 1);
     //   return(1);
    //}
    if (x >= 16)
    {
        hex(x / 16);
        hex(x % 16);
    }
    else
    {
        if (x <= 9)
            ft_putchar(x + '0');
        else
            ft_putchar(x - 10 + 'a');
    }
    return(0);
}

int main(void)
{
    //char *n;
    //printf("%p", n);
    //printf("\n");
    //write(1, "0x", 2);
    unsigned long long k = 4724514853;
    hex(k);
    printf("\n");
    printf("%p\n", k);
    
    //printf("\n");
}