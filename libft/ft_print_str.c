/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:11:00 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/23 09:55:36 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s, int fd)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i])
			write(fd, &s[i], 1);
	else if (s == NULL)
		return (write(1, "(null)", 6) - 1);
	return (i - 1);
}

void	ft_printnbr(int n, int fd, int *t)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*t += 10;
		return ;
	}
	if (n < 0)
		*t += 1;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd ('-', fd);
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_printnbr(n / 10, fd, t);
		ft_printnbr(n % 10, fd, t);
		*t += 1;
	}
}
