/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:08 by regralin          #+#    #+#             */
/*   Updated: 2025/08/21 04:00:09 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find_c(char *str, char c)
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
	while (ft_find_c(charset, str[*idx]))
		(*idx)++;
	while (str[*idx + j] && !ft_find_c(charset, str[*idx + j]))
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

int	ft_get_mllc(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_find_c(charset, str[i]))
			i++;
		if (str[i])
		{
			count++;
			while (!ft_find_c(charset, str[i]) && str[i])
				i++;
		}
	}
	return (count + 1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	**split;

	i = 0;
	j = 0;
	len = ft_get_mllc(str, charset);
//	if (!str || !charset)
//		return (NULL);
	split = malloc(len * sizeof(char *));
	if (!split)
		return (NULL);
	while (i < len - 1)
		split[i++] = ft_gnw(&j, str, charset);
	split[i] = 0;
	return (split);
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		i;
	char	*sep = " _-";
	char	**split = NULL;

	i = 0;
	if (argc > 1)
	{
		split = ft_split(argv[1], sep);
		while (split[i])
		{
			printf("%s\n", split[i]);
			i++;
		}
	}
	free(split);
	return (0);
}
