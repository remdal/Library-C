/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:01:14 by regralin          #+#    #+#             */
/*   Updated: 2025/08/10 13:36:35 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] < ' ' || base[j] < ' '
				|| base[i] == '+' || base[j] == '-'
				|| base[j] == '+' || base[i] == '-'
				|| base[i] == 127 || base[j] == 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long int	nb;

	nb = (long long int)nbr;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (!is_valid_base(base))
		return ;
	if (nb < 0)
	{
		ft_putchar(45);
		nb = -(nb);
	}
	if (nb / ft_strlen(base) != 0)
		ft_putnbr_base(nb / ft_strlen(base), base);
	ft_putchar(base[nb % ft_strlen(base)]);
}

int	main(void)
{
	int		i;
	int		j;
	int		k;
	char	*base;
	char	*binaire;
	char	*poneyvif;
    int l = 2142456;

	i = 16;
	j = 2;
	k = 8;
	base = "0123456789ABCDEF";
	binaire = "01";
	poneyvif = "poneyvif"; // base 8
	ft_putnbr_base(i, base);
	ft_putchar('\n');
	ft_putnbr_base(j, binaire);
	ft_putchar('\n');
	ft_putnbr_base(k, poneyvif); // op
    ft_putchar('\n');
    ft_putnbr_base(l, binaire);
    ft_putchar('\n');
    ft_putnbr_base(l, poneyvif);
    ft_putchar('\n');
    ft_putnbr_base(l, base);
    ft_putchar('\n');
	return (0);
}
