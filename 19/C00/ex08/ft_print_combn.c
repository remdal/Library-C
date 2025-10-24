/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:41:44 by regralin          #+#    #+#             */
/*   Updated: 2025/08/06 11:18:04 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int n, char tab[])
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(tab[i++]);
	if (tab[0] != '9' + 1 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_help_me(char tab[], int n)
{
	int	j;

	j = 0;
	while (tab[0] <= '9' + 1 - n)
	{
		ft_print_tab(n, tab);
		j = n - 1;
		if (tab[j] < '9')
			tab[j]++;
		else
		{
			while (tab[j] == '9' - (n - j - 1) && j > 0)
				j--;
			if (j >= 0)
			{
				tab[j]++;
				while (++j < n)
					tab[j] = tab[j - 1] + 1;
			}
		}
	}
}

void	ft_print_combn(int n)
{
	char	tab[12];
	int		i;

	i = 0;
	tab[0] = '0';
	if (n == 1)
	{
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
		return ;
	}
	while (++i < n)
		tab[i] = '0' + i;
	ft_help_me(tab, n);
}
