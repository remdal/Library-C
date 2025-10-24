/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:32:29 by regralin          #+#    #+#             */
/*   Updated: 2025/08/13 17:52:16 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*aloc;
	int		i;

	i = 0;
	aloc = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!aloc)
		return (NULL);
	while (src[i])
	{
		aloc[i] = src[i];
		i++;
	}
	aloc[i] = '\0';
	return (aloc);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[11] = "Coucou free";

	printf("%s\n", ft_strdup(src));
	printf("%s\n", strdup(src));
	return (0);
}*/
