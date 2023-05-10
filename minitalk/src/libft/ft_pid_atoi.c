/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:47:52 by donghyk2          #+#    #+#             */
/*   Updated: 2023/03/09 19:48:20 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pid_atoi(const char *str)
{
	size_t	i;
	int		minus;
	int		result;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (str[i])
		return (-1);
	return (result * minus);
}