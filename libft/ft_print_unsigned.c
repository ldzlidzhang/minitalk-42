/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:58:01 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/22 20:00:52 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_nbr(unsigned int n, int fd, int *len)
{
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_unsigned_nbr(n / 10, fd, len);
		ft_unsigned_nbr(n % 10, fd, len);
		*len += 1;
	}
}
