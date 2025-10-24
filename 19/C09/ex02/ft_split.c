/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:58:57 by regralin          #+#    #+#             */
/*   Updated: 2025/08/26 00:48:00 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_gnw(int *idx, char *str, char *charset)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (ft_find(charset, str[*idx]))
		(*idx)++;
	while (str[*idx + j] && !ft_find(charset, str[*idx + j]))
		j++;
	word = malloc(j + 1);
	if (!word)
		return (NULL);
	while (i < j)
	{
		word[i++] = str[*idx];
		*idx += 1;
	}
	word[i] = 0;
	return (word);
}

int	ft_get_malloc(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_find(charset, str[i]))
			i++;
		if (str[i])
		{
			count++;
			while (!ft_find(charset, str[i]) && str[i])
				i++;
		}
	}
	return (count + 1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = 0;
	k = ft_get_malloc(str, charset);
	res = malloc(k * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < k - 1)
		res[i++] = ft_gnw(&j, str, charset);
	res[i] = NULL;
	return (res);
}
