#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}


int    ft_printf(const char *s, ...)
{
    int i;
    va_list ap;
    char *name;
    unsigned int days;
    va_start(ap, s);
    i = 0;

    while(s[i])
    {
        if (s[i] == '%' && s[i + 1])
        {
            i++;
            if (s[i] == 's')
            {
                name = va_arg(ap, char *);
                ft_putstr(name);
            }
            else if (s[i] == 'd')
            {
                days = va_arg(ap, int);
                ft_putnbr(days);
            }
        }
        else if (s[i] != '%')
            ft_putchar(s[i]);
        i++;
    }
    va_end(ap);
    return(0);
}


int main(void)
{
    //ft_printf("Hello %s, you have 10 days left.", "Shura"); //check if (null) //%csdiuxXp
    int i = 255;
    
    printf("\n");
    printf("the number is %x", i);
	//printf("Hello %s, you have 10 days left!\n", "Shura");
}