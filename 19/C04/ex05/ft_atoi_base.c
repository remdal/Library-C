/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:38:38 by regralin          #+#    #+#             */
/*   Updated: 2025/08/10 16:20:56 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base [j] || base[i] < ' ' || base[j] < ' '
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

int	skip(int *pn, char *str)
{
	int	i;

	i = 0;
	*pn = 1;
	while (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*pn *= -1;
		i++;
	}
	return (i);
}

int	atoi_alternative(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int				pn;
	int				i;
	long long int	value;

	value = 0;
	i = skip(&pn, str);
	if (!is_valid_base(base) || ft_strlen(base) < 2)
		return (0);
	while (str[i])
	{
		if (atoi_alternative(str[i], base) == -1)
			return (value * pn);
		value *= ft_strlen(base);
		value += atoi_alternative(str[i], base);
		i++;
	}
	return (value * pn);
}

#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
	int		k;
	char	*base;
	char	*binaire;
	char	*poneyvif;
	char	integer[2] = "16";
	char	testeur[33] = "1942alitleponeyvifisinmypwd26ABC"; // 32 char

	i = 16;
	j = 2;
	k = 8;
	base = "0123456789ABCDEF";
	binaire = "01";
	poneyvif = "poneyvif";
	printf("%i\n", ft_atoi_base(testeur, base));
	printf("%i\n", ft_atoi_base(testeur, binaire));
	printf("%i\n", ft_atoi_base(testeur, poneyvif));
	printf("%i\n", ft_atoi_base(integer, binaire));
	printf("%i\n", ft_atoi_base(integer, base));
	return (0);
}
