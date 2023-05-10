/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:23:42 by donghyk2          #+#    #+#             */
/*   Updated: 2022/11/12 16:20:15 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;

	slen = ft_strlen(s);
	if (!s)
		return (0);
	if (slen < start)
		return (ft_strdup(""));
	if (slen < start + len)
		len = slen - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	s += start;
	ft_strlcpy(res, s, len + 1);
	return (res);
}
