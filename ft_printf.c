/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:12:51 by ccompote          #+#    #+#             */
/*   Updated: 2022/09/24 16:58:34 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    va_list ap;
    char *name;
    unsigned int days;
    va_start(ap, s);
    name = va_arg(ap, char *);
    days = va_arg(ap, unsigned int);

    ft_putstr(name);
    ft_putnbr(days);
    va_end(ap);
    return(0);
}


int main(void)
{
    //ft_printf("Hello %s, you have %u days left!", "Shura", 10);
	printf("%7.3d", -42);
}