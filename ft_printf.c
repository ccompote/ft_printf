/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:20:57 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/11 18:30:33 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
        count += ft_point(va_arg(ap, unsigned int));
    else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(ap, int));
    else if (c == 'u')
        count += ft_uint(va_arg(ap, unsigned int));
    else if (c == 'x' || c == 'X')
        count += ft_hex(va_arg(ap, unsigned int), c);
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
    char *point;
    int hex;

    hex = 500;
    ft_printf("%c is the char\n", 'K');
    ft_printf("%s is the string\n", "Anna");
    ft_printf("%p is the pointer\n", point);
    ft_printf("%d is the digit\n", 10);
    ft_printf("%i is the integer\n", 15);
    ft_printf("%u is the unsigned integer\n", 1000000);
    ft_printf("%x is the hex\n", hex);
    ft_printf("%X is the hex\n", hex);
    ft_printf("%% is the percent\n");
    printf("%c is the char\n", 'K');
    printf("%s is the string\n", "Anna");
    printf("%p is the pointer\n", point);
    printf("%d is the digit\n", 10);
    printf("%i is the integer\n", 15);
    printf("%u is the unsigned integer\n", 1000000);
    printf("%x is the hex\n", hex);
    printf("%X is the hex\n", hex);
    printf("%% is the percent\n");
    return(0);
}