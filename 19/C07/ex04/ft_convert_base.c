/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:44:33 by regralin          #+#    #+#             */
/*   Updated: 2025/08/21 20:47:04 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
//#include <stdio.h>

int	ft_strlen(char *str);
int	is_valid_base(char *base);
int	skip(int *pn, char *str);
int	atoi_alternative(char c, char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_boring(char *base_to)
{
	char	*str;

	str = malloc(2);
	str[0] = base_to[0];
	str[1] = 0;
	return (str);
}

void	ft_rev_tab(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*llc;

	i = 0;
	llc = malloc(ft_strlen(str) + 1);
	if (!llc)
		return (NULL);
	while (str[i])
	{
		llc[i] = str[i];
		i++;
	}
	llc[i] = '\0';
	return (llc);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int			i;
	int			pn;
	char		buff[33];

	pn = 1;
	i = 0;
	if (nbr < 0)
	{
		pn *= -1;
		nbr = -nbr;
	}
	while (nbr)
	{
		buff[i++] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
	}
	if (pn == -1)
		buff[i++] = '-';
	buff[i] = 0;
	ft_rev_tab(buff, ft_strlen(buff));
	return (ft_strdup(buff));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		b10;
	char	*str;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	b10 = ft_atoi_base(nbr, base_from);
	if (b10 == 0)
		return (ft_boring(base_to));
	str = malloc(ft_strlen(ft_itoa_base(b10, base_to)) + 1);
	if (!str)
		return (NULL);
	str = ft_itoa_base(b10, base_to);
	return (str);
}
/*int	main(void)
{
	int		i;
	int		j;
	int		k;
	char	*base;
	char	*binaire;
	char	*poneyvif;
	char	integer[2] = "16";
	char	testeur[33] = "1942alitleponeyvifisinmypwd26ABC"; // 32 char
	char	*nb = "1942";
	char	*int_max = "2147483647";
//	char	long_binary[65] = {0};

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
	printf("\n%i\n", ft_atoi_base(nb, base));
	printf("%i\n", ft_atoi_base(nb, binaire));
	printf("%s\n", ft_convert_base(nb, base, binaire));
	printf("%s\n", ft_convert_base(int_max, base, binaire));
	return (0);
}*/
