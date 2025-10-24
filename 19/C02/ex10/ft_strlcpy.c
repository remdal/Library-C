/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:35:44 by regralin          #+#    #+#             */
/*   Updated: 2025/08/07 11:55:48 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = ft_strlen(src);
	if (size == 0)
		return (i);
	while (*src && size - 1)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned int	i;

	i = 22;
	char greetings[] = "Hello World!";
	char greet[10];

	greet[0] = 0;
	printf("%i", ft_strlcpy(greet, greetings, i));
	printf("%s", greet);
	return (0);
}*/
