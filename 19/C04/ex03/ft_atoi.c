/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:46:14 by regralin          #+#    #+#             */
/*   Updated: 2025/08/10 16:09:17 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	pn;
	int	value;

	i = 0;
	pn = 1;
	value = 0;
	while (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pn *= -1;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		value = value * 10 + str[i] - 48;
		i++;
	}
	return (value * pn);
}
/*#include <stdio.h>
int	main(void)
{
	char	testeur[22] = "     ---+-++-1234ab567";
	printf("%i\n", ft_atoi(testeur));
	return (0);
}*/
