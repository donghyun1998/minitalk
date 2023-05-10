/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:43:59 by donghyk2          #+#    #+#             */
/*   Updated: 2023/03/09 17:51:42 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	bit;
	static char	tmp;

	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
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
	print_pid(getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
}
