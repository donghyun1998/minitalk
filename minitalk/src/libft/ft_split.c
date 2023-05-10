/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:13:54 by donghyk2          #+#    #+#             */
/*   Updated: 2023/02/12 16:30:21 by donghyk2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**allfree(char **res, int outindex)
{
	int	i;

	i = -1;
	while (++i <= outindex)
	{
		free(res[i]);
		res[i] = 0;
	}
	free(res);
	res = 0;
	return (0);
}

static int	wordnumber(char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static int	wordlen(char *s, char c, int *j)
{
	int	tmp;

	tmp = *j;
	while (s[*j] != c && s[*j])
		(*j)++;
	return (*j - tmp);
}

static void	init(char **res, char *s, char c, int wordn)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	if (wordn == 0)
	{
		res[j] = 0;
		return ;
	}
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			res[j][k++] = s[i++];
		res[j++][k] = '\0';
		while (s[i] == c && s[i])
			i++;
	}
	res[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		wordn;

	if (!s)
		return (0);
	wordn = wordnumber((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (wordn + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	while (++i < wordn)
	{
		if (wordn == 0)
			break ;
		while (s[j] == c && s[j])
			j++;
		res[i] = (char *)malloc(sizeof(char) * (wordlen((char *)s, c, &j) + 1));
		if (!res[i])
			return (allfree(res, i - 1));
	}
	init(res, (char *)s, c, wordn);
	return (res);
}
