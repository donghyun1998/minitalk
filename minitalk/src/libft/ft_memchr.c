/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:26:04 by donghyk2          #+#    #+#             */
/*   Updated: 2022/10/24 15:45:20 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	ucc;

	ps = (unsigned char *)s;
	ucc = (unsigned char)c;
	while (n--)
	{
		if (*ps == ucc)
			return (ps);
		ps++;
	}
	return (0);
}
