/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:46:05 by regralin          #+#    #+#             */
/*   Updated: 2025/08/06 13:51:15 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}
/*#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 19;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("%i %i", a, b);
	return (0);
}*/
