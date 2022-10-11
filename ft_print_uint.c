/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:30:19 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/11 18:30:38 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_uitoa(unsigned int n)
{
    char	*str;
	int		len;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (char)((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}

int ft_uint(unsigned int n)
{
    char *line;
    int count;

    count = 0;
    if (n == 0)
        count += write(1, "0", 1);
    else
    {
        line = ft_uitoa(n);
        count = ft_putstr(line);
        free(line);
    }
    return(count);
}