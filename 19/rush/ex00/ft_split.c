/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:06:12 by regralin          #+#    #+#             */
/*   Updated: 2025/08/24 23:10:48 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_count_words(char *str, char charset)
{
	int	count;
	int	check;	

	count = 0;
	check = 0;
	while (*str)
	{
		if (*str == charset)
			check = 0;
		else if (!check)
		{
			count++;
			check = 1;
		}
		str++;
	}
	return (count);
}

char	*ft_get_next_word(char *str, char charset)
{
	int		i;
	char	*words;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	words = malloc(i + 1);
	if (!words)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != charset)
		*words++ = str[i++];
	*words = '\0';
	return (words - i);
}

char	**ft_split(char *str, char charset)
{
	int		i;
	int		words;
	char	**numbers;

	i = 0;
	words = ft_count_words(str, charset);
	numbers = malloc((words + 1) * sizeof(char *));
	if (!numbers)
		return (NULL);
	while (*str && i < words)
	{
		while (*str == charset && *str)
			str++;
		if (*str)
			numbers[i++] = ft_get_next_word(str, charset);
		while (*str != charset && *str)
			str++;
	}
	numbers[i] = NULL;
	return (numbers);
}
