/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:54:58 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/22 20:18:40 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	long_digit(unsigned long int n, int base)
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

int	ft_print_pointer(unsigned long int n, int fd, char c)
{
	char	*m;
	char	*t;
	char	*s;

	m = "0123456789ABCDEF";
	t = "0123456789abcdef";
	if (c == 'x')
		s = t;
	else
		s = m;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd ('-', fd);
	}
	if (n < 16)
		ft_putchar_fd(s[n], fd);
	else
	{
		ft_print_pointer(n / 16, fd, c);
		ft_print_pointer(n % 16, fd, c);
	}
	return (long_digit(n, 16) - 1);
}
