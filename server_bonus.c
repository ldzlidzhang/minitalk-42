/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:37:22 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/12 15:03:28 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	check_message_finished(
	t_protocol *t_server, int *i, pid_t client_pid)
{
	if (t_server->bits == 8 && t_server->flag == 1)
	{
		t_server->message[*i] = t_server->data;
		(*i)++;
		if (t_server->data == '\0')
		{
			ft_putstr_fd("\e[92mreceived message = [", STDOUT_FILENO);
			ft_putstr_fd(t_server->message, STDOUT_FILENO);
			ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
			free(t_server->message);
			t_server->message = NULL;
			t_server->flag = 0;
			*i = 0;
			send_bit(client_pid, 1, 0);
		}
		t_server->bits = 0;
	}
}

static void	check_str_length_finished(t_protocol *t_server)
{
	if (t_server->bits == sizeof(int) * 8 && t_server->flag == 0)
	{
		t_server->flag = 1;
		ft_putstr_fd("\e[92mreceived length = [", STDOUT_FILENO);
		ft_putnbr_fd(t_server->data, STDOUT_FILENO);
		ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
		t_server->message = ft_calloc(t_server->data + 1, sizeof(char));
		if (t_server->message == NULL)
		{
			ft_putstr_fd("\e[31m## error - ft_calloc() ##\n\e[0m", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		t_server->message[t_server->data] = '\0';
		t_server->bits = 0;
	}
}

static void	server_handler(int num, siginfo_t *info, void *context)
{
	static t_protocol	t_server;
	static int			i;

	usleep(WAIT_US);
	(void)context;
	(void)info;
	if (t_server.bits == 0)
		t_server.data = 0;
	if (num == SIGUSR2 && t_server.flag == 0)
		t_server.data |= 1 << (((sizeof(int) * 8) - 1) - t_server.bits);
	else if (num == SIGUSR2 && t_server.flag == 1)
		t_server.data |= 1 << (((sizeof(char) * 8) - 1) - t_server.bits);
	t_server.bits++;
	check_str_length_finished(&t_server);
	check_message_finished(&t_server, &i, info->si_pid);
	send_bit(info->si_pid, 0, 0);
}

int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&s_server);
	ft_putstr_fd("\e[92mserver [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
