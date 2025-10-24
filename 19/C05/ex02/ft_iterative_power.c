/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:40:56 by regralin          #+#    #+#             */
/*   Updated: 2025/08/11 13:41:57 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	while (i <= power)
	{
		j *= nb;
		i++;
	}
	return (j);
}

#include <stdio.h>
int	main(void)
{
	int	i;
	int	j;

	i = 2;
	j = 2;
    printf("%i\n", ft_iterative_power(i , j));
    printf("%i\n", ft_iterative_power(10 , 2));
	printf("%i\n", ft_iterative_power(j , i));
	return (0);
}
