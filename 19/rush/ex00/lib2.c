/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadli <jadli@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:41:40 by abahbah           #+#    #+#             */
/*   Updated: 2025/08/24 23:10:12 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcat(char	*dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && i + 1 < n)
	{
        i++;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_atoa(char *str)
{
	while ((*str >= 9 && *str <= 13) || (*str == ' ' && *str))
		str++;
	if (*str == 43)
		str++;
	if (*str == 45 || !*str)
		return (NULL);
	while (*str == 48)
	{
		str++;
		if (!*str || !(*str > 47 && *str < 58))
			return ("0");
	}
	return (str);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_dict_error(void)
{
	write(2, "Dict Error\n", 11);
}
