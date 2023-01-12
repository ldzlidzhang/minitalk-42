/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:13:42 by lidanzhang        #+#    #+#             */
/*   Updated: 2022/12/15 17:20:56 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_hex(unsigned int n, int fd, char c);
int		ft_print_pointer(unsigned long int n, int fd, char c);
int		ft_printstr(char *s, int fd);
void	ft_printnbr(int n, int fd, int *t);
void	ft_unsigned_nbr(unsigned int n, int fd, int *len);

#endif
