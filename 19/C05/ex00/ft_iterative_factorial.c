/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:51:28 by regralin          #+#    #+#             */
/*   Updated: 2025/08/11 11:02:31 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		j *= i;
		i++;
	}
	return (j);
}

#include <stdio.h>
int	main(void)
{
	int	i;

	i = 1;
    printf("%i\n", ft_iterative_factorial(i));
    printf("%i\n", ft_iterative_factorial(4));
    printf("%i\n", ft_iterative_factorial(0));
    printf("%i\n", ft_iterative_factorial(2));
	printf("%i\n", ft_iterative_factorial(3));
	return (0);
}
