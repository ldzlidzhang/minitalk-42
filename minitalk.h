/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:41:39 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/12 21:24:51 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define WAIT_US  100 // usleep()

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_protocol
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}			t_protocol;

void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);

#endif
