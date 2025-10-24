/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:02:18 by regralin          #+#    #+#             */
/*   Updated: 2025/08/06 16:45:57 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}
/*#include "unistd.h"

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}

void	ft_print_tab(int n, int tab[])
{
	int	i;

	i = 0;
	while (i < n)
		ft_putnbr(tab[i++]);
}
int	main(void)
{
	int	tab[16] = { 1, 2, 3, 5, 6, 88, 10, 55, 88, 20, 45, 4564864, 4, 0, 99 };
	int	size;

	size = 15;
	ft_rev_int_tab(tab, size);
	ft_print_tab(size, tab);
}*/
