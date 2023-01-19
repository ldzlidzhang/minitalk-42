/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:41:39 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/19 09:40:26 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define WAIT_US  100 // usleep()

# include "libft/libft.h" // ft_atoi(), ft_strlen(), ft_putstr(), ft_putnbr()
# include <unistd.h> // getpid(), write()
# include <signal.h> // sigemptyset(), sigaction()
# include <stdlib.h> // exit()

typedef struct s_protocol
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}			t_protocol;

void	configure_sigaction_signals(struct sigaction *sa);
void	send_int(pid_t pid, int num);
void	send_char(pid_t pid, char c);
void	send_bit(pid_t pid, char bit, char flag_to_pause);

#endif
