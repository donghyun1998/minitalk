/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:12:44 by donghyk2          #+#    #+#             */
/*   Updated: 2022/10/24 17:12:41 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (dst < src)
	{
		while (len--)
			*(pdst++) = *(psrc++);
	}
	else
	{
		pdst += len - 1;
		psrc += len - 1;
		while (len--)
			*(pdst--) = *(psrc--);
	}
	return (dst);
}
