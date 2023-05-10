/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:32:35 by donghyk2          #+#    #+#             */
/*   Updated: 2022/10/29 14:03:28 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_nlen(long longn)
{
	int	i;

	i = 0;
	while (longn > 9)
	{
		i++;
		longn /= 10;
	}
	return (++i);
}

static	void	ft_init(char *res, int len, int minus, long longn)
{
	while (len > 0)
	{
		res[len + minus - 1] = longn % 10 + '0';
		longn /= 10;
		len--;
	}
	if (minus)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	longn;
	int		minus;

	longn = (long)n;
	minus = 0;
	if (longn < 0)
	{
		minus = 1;
		longn *= -1;
	}
	len = ft_nlen(longn);
	res = (char *)malloc(sizeof(char) * (len + 1 + minus));
	if (!res)
		return (0);
	res[len + minus] = '\0';
	ft_init(res, len, minus, longn);
	return (res);
}
