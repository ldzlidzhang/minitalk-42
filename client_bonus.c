/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:36:03 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/19 10:09:38 by lidzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	c_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\e[33m > ACK signal received from server\n\e[0m",
			1);
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\e[92m > end of message signal received from server\n\e[0m",
			1);
		exit(EXIT_SUCCESS);
	}
}

static void	c_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	{
		ft_putstr_fd("\n\e[92m > sending length = [", 1);
		ft_putnbr_fd(ft_strlen(str), 1);
		ft_putstr_fd("]\n\e[0m", 1);
		send_int(server_pid, ft_strlen(str));
		ft_putstr_fd("\e[92m > sending message\n\e[0m", 1);
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		ft_putstr_fd("\e[92m > sending null string terminator\n\e[0m", 1);
		send_char(server_pid, '\0');
	}
}

int	main(int argc, char **argv)
{	
	struct sigaction	s_client;

	if (argc != 3)
	{
		ft_putstr_fd("\e[31m## error - incorrect syntax ##\n\e[0m", 1);
		ft_putstr_fd(
			"\e[92m./client <the server PID> <the string to send>\n\e[0m",
			1);
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(argv[1]), 0) < 0)
	{
		ft_putstr_fd("\e[31m## error - PID is invalid ##\n\e[0m", 1);
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = c_handler;
	configure_sigaction_signals(&s_client);
	ft_putstr_fd("client [PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]", 1);
	c_send_message(ft_atoi(argv[1]), argv[2]);
	return (EXIT_SUCCESS);
}
