/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:00:13 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/22 20:11:16 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_digit(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_print_hex(unsigned int n, int fd, char c)
{
	char	*str_upper;
	char	*str_lower;
	char	*dest;

	str_upper = "0123456789ABCDEF";
	str_lower = "0123456789abcdef";
	if (c == 'x')
		dest = str_lower;
	else
		dest = str_upper;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd ('-', fd);
	}
	if (n < 16)
		ft_putchar_fd(dest[n], fd);
	else
	{
		ft_print_hex(n / 16, fd, c);
		ft_print_hex(n % 16, fd, c);
	}
	return (int_digit(n, 16) - 1);
}
