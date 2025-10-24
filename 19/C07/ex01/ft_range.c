/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:08:01 by regralin          #+#    #+#             */
/*   Updated: 2025/08/13 17:51:26 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*aloc;

	i = 0;
	if (max <= min)
		return (NULL);
	aloc = malloc((max - min) * sizeof(int));
	if (!aloc)
		return (NULL);
	while (max - min > i)
	{
		aloc[i] = min + i;
		i++;
	}
	return (aloc);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min = 2;
	int	max = 10;
	int	i = 0;
	int	*tab = ft_range(min, max);

	while (tab[i])
	{
		printf("%i\n", tab[i]);
		i++;
	}
	return (0);
}*/
