/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:03:11 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/11/22 20:19:44 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(va_list *ap, const char *str, int i, int print_len)
{
	print_len = 0;
	if (str[i + 1] == 'c')
		ft_putchar_fd(va_arg(*ap, int), 1);
	else if (str[i + 1] == 's')
		print_len = ft_printstr(va_arg(*ap, char *), 1);
	else if (str[i + 1] == '%')
		ft_putchar_fd('%', 1);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_printnbr(va_arg(*ap, int), 1, &print_len);
	else if (str[i + 1] == 'u')
		ft_unsigned_nbr(va_arg(*ap, unsigned int), 1, &print_len);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		print_len = ft_print_hex(va_arg(*ap, long), 1, str[i + 1]);
	else if (str[i + 1] == 'p')
	{
		ft_printstr("0x", 1);
		print_len = ft_print_pointer(va_arg(*ap, long), 1, 'x') + 2;
	}
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_len;
	int		r;
	va_list	ap;

	print_len = 0;
	i = -1;
	r = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			print_len += format_check(&ap, format, i++, r);
		else
			ft_putchar_fd(format[i], 1);
		print_len++;
	}
	va_end(ap);
	return (print_len);
}
