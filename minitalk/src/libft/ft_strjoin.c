/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:28:33 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/07 20:08:20 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	reslen;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	reslen = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * reslen);
	if (!res)
		return (0);
	i = -1;
	while (++i < reslen - 1)
	{
		if (*s1)
			res[i] = *s1++;
		else
			res[i] = *s2++;
	}
	res[i] = '\0';
	return (res);
}
