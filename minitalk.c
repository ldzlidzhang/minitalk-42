/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:27:50 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/19 09:40:24 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup SIGUSR1 ##\n\e[0m",
			1);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putstr_fd("\e[31m## error - could not setup SIGUSR2 ##\n\e[0m",
			1);
		exit(EXIT_FAILURE);
	}
}

void	send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

void	send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR1 ##\n\e[0m",
				1);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putstr_fd("\e[31m## error - sending SIGUSR2 ##\n\e[0m",
				1);
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}
