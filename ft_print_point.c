/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:28:33 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/11 18:29:11 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_point(unsigned int x)
{
    if (x >= 16)
    {
        ft_print_point(x / 16);
        ft_print_point(x % 16);
    }
    else
    {
        if (x <= 9)
            ft_putchar(x + '0');
        else
            ft_putchar(x - 10 + 'a');
    }
}

int ft_point(unsigned int x)
{
    int count;
    unsigned int dub;

    count = 0;
    dub = x;
    count += write(1, "0x", 2);
    if (dub == 0)
        count += write(1, "0", 1);
    while (dub > 0)
    {
        dub /= 16;
        count++;
    }
    ft_print_point(x);
    return(count);     
}