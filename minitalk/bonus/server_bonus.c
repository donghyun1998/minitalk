/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:18:29 by donghyk2          #+#    #+#             */
/*   Updated: 2023/03/09 18:11:41 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static char	tmp;

	(void)s;
	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 16)
	{
		if (tmp != '\0')
			ft_putchar_fd(tmp, 1);
		else
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		tmp = 0;
	}
}

void	print_pid(pid_t pid)
{
	ft_putstr_fd("PID -> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for a message...\n", 1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = &handler;
	print_pid(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
}
