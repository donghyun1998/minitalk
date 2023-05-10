/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:18:27 by donghyk2          #+#    #+#             */
/*   Updated: 2023/03/09 19:48:02 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_sig(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Server received message\n", 1);
	exit (0);
}

void	error_mes(void)
{
	ft_putstr_fd("Error: wrong format.\n", 1);
	exit(0);
}

void	send_bit(pid_t pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 16)
	{
		if ((input & 1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_str(pid_t pid, char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		send_bit(pid, input[i]);
	send_bit(pid, '\n');
	send_bit(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	s_pid;
	char	*send_msg;

	signal(SIGUSR1, check_sig);
	s_pid = ft_pid_atoi(argv[1]);
	if (s_pid == -1 || s_pid < 100 || s_pid > 99998)
		error_mes();
	send_msg = argv[2];
	if (argc != 3 || send_msg[0] == '\0')
		error_mes();
	send_str(s_pid, send_msg);
}
