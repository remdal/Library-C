/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 04:11:15 by regralin          #+#    #+#             */
/*   Updated: 2025/08/27 12:04:53 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	ft_strcmp(char c, char *str)
{
	if (*str == c)
		return (1);
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar(45);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	pn;
	int	val;

	i = 0;
	pn = 1;
	val = 0;
	while (str[i] == 32 || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			pn *= -1;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		val = val * 10 + str[i] - 48;
		i++;
	}
	return (val * pn);
}
