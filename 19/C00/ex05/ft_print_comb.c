/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:04:29 by regralin          #+#    #+#             */
/*   Updated: 2025/08/05 13:48:32 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				ft_putchar(i + 48);
				ft_putchar(j + 48);
				ft_putchar(k + 48);
				write(1, ", ", 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
    ft_print_comb();
    return (0);
}
