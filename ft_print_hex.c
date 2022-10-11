/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:29:31 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/11 18:29:52 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_hex(unsigned int x, int c)
{
    if (x >= 16)
    {
        ft_print_hex(x / 16, c);
        ft_print_hex(x % 16, c);
    }
    else
    {
        if (x <= 9)
            ft_putchar(x + '0');
        else if (c == 'x')
            ft_putchar(x - 10 + 'a'); 
        else
            ft_putchar(x - 10 + 'A');
    }
}

int ft_hex(unsigned int ui, int c)
{
    int count;
    unsigned int dub;

    count = 0;
    dub = ui;
    if (dub == 0)
        count++;
    while (dub > 0)
    {
        dub /=16;
        count++;
    }
    ft_print_hex(ui, c);
    return(count);    
}