/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:20:57 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/10 19:41:34 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return(1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
    {
        write(1, "(null)", 6);
        return(6);
    }
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
    return(i);
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

int ft_point(unsigned long long x)
{
/*     if (x == 0)
    {
       write(1, "0", 1);
       return(1);
    } */
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

int ft_hex(unsigned long long x, int c)
{
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
            if (x == 'x')
               ft_putchar(x - 10 + 'a'); 
            else
                ft_putchar(x - 10 + 'A');
    }
    return(0);
}

int ft_uint(unsigned int n)
{
    if (n >= 10)
		ft_uint(n / 10);
	ft_uint(n % 10 + '0');
}

int ft_check_format(char c)
{
    if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
    || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
        return(1);
    return(0);
} 

int ft_worktype(int c, va_list ap)
{
    int count;

    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(ap, int));
    if (c == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if (c == 'p')
        count += ft_hex(va_arg(ap, unsigned long));
    else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(ap, int));
    else if (c == 'u')
        count += ft_uint(va_arg(ap, unsigned int));
    else if (c == 'x' || c == 'X')
        count += ft_hex(va_arg(ap, unsigned int, int c));
    else if (c == '%')
        count += ft_putchar(c);
    return(count);
}

int ft_printf(const char *s, ...)
{
    int count;
    int i;
    va_list ap;
    
    count = 0;
    i = 0;
    va_start(ap, s);
    while(s[i])
    {
        if(s[i] == '%' && s[i + 1])
        {
            i++;
            if(ft_check_format(s[i]))
            {
                count += ft_worktype(s[i], ap);
            }
        }
        else if (s[i] != '%')
            count += ft_putchar(s[i]);
        i++;
    }
    va_end(ap); 
    return(count);
}

int main(void)
{
    char *p;
    ft_printf("Hello %s, you\n", "Anna");
    printf("Hello %s, you\n", "Anna");
    printf("%s\n", p);
    return(0);
}