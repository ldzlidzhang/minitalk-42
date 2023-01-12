/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:34:44 by lidanzhang        #+#    #+#             */
/*   Updated: 2023/01/12 21:23:44 by lidanzhang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	response(unsigned int *c_pid)
{
	kill(*c_pid, SIGUSR1);
	*c_pid = 0;
}

/*
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
*/

static void	handler_s(int sig, siginfo_t *siginfo, void *optional)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static unsigned int		c_pid = 0;

	(void)optional;
	if (!c_pid)
		c_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return (response(&c_pid));
		ft_putchar(c);
		c = 0;
		kill(c_pid, SIGUSR2);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	ft_putstr_fd("\e[92mserver [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	sa.sa_sigaction = handler_s;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
