/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:20:57 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/06 17:45:22 by ccompote         ###   ########.fr       */
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
		return (0);
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
        ft_putchar(va_arg(ap, int));
    if (c == 's')
        ft_putstr(va_arg(ap, char *));
    //else if (c == 'p')
    else if (c == 'd' || c == 'i')
        ft_putnbr(va_arg(ap, int));
    //else if (c == 'u')
    //else if (c == 'x' || c == 'X')
    else if (c == '%')
        ft_putchar(c);
    return(count);
}

void ft_workstr(const char *s, va_list ap)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == '%' && s[i + 1])
        {
            i++;
            if(ft_check_format(s[i]))
            {
                ft_worktype(s[i], ap);
            }
        }
        else if (s[i] != '%')
            ft_putchar(s[i]);
        i++;
    }
}

int ft_printf(const char *s, ...)
{
    int count;
    va_list ap;
    
    count = 0;
    va_start(ap, s);
    ft_workstr(s, ap);
    va_end(ap); 
    return(count);
}

int main(void)
{
    char *p;
    ft_printf("Hello %s, you\n", "Anna");
    printf("Hello %s, you\n", "Anna");
    printf("%p\n", p);
    return(0);
}