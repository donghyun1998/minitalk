/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:05:43 by donghyk2          #+#    #+#             */
/*   Updated: 2022/10/22 21:20:45 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*all;
	size_t	tmp;

	tmp = count * size;
	if ((size != 0) && (count != tmp / size))
		return (0);
	all = malloc(tmp);
	if (!all)
		return (0);
	return (ft_memset(all, 0, count * size));
}
