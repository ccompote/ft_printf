/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompote <ccompote@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:23:39 by ccompote          #+#    #+#             */
/*   Updated: 2022/10/11 18:33:32 by ccompote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifdef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int ft_check_format(char c);
int ft_worktype(int c, va_list ap);
int ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
char *ft_uitoa(unsigned int n);
int ft_uint(unsigned int n);
void ft_print_point(unsigned int x);
int ft_point(unsigned int x);
void ft_print_hex(unsigned int x, int c);
int ft_hex(unsigned int ui, int c);
int	ft_len(int n);
int	ft_znak(int n);
char	*ft_nul(int n, char *str);
char	*ft_itoa(int n);

#endif