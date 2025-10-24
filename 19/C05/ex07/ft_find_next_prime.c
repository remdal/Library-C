/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:04:58 by regralin          #+#    #+#             */
/*   Updated: 2025/08/13 11:45:56 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

#include <stdio.h>

int	main(void)
{
	int	i;
	int	j;
	int	k, l, o, p, q;

	i = 2147483647;
	k = 46340;
	l = 46341;
	j = 2;
	o = 0;
	p = 1;
	q = 3;
	// m = 2147483648;
	printf("%i\n", ft_find_next_prime(i));
	printf("%i\n", ft_find_next_prime(j));
	printf("%i\n", ft_is_prime(i));
	printf("%i\n", ft_find_next_prime(k));
        printf("%i\n", ft_find_next_prime(l));
        printf("%i\n", ft_is_prime(j));
	// printf("%i\n", ft_find_next_prime(m));
        printf("%i\n", ft_is_prime(k));
	printf("%i\n", ft_find_next_prime(o));
        printf("%i\n", ft_find_next_prime(p));
        printf("%i\n", ft_is_prime(l));
        printf("%i\n", ft_find_next_prime(q));
        // printf("%i\n", ft_is_prime(m));
        printf("%i\n", ft_is_prime(o));
        printf("%i\n", ft_is_prime(p));
        printf("%i\n", ft_is_prime(q));
	return (0);
}
