/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:25:44 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/11 18:26:55 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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


int	ft_putnbr(int n)
{
	int count;
    char *line;

    count = 0;
    line = ft_itoa(n);
    count = ft_putstr(line);
    free(line);
    return(count);
}