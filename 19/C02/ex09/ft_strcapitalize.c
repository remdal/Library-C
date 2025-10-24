/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:10:21 by regralin          #+#    #+#             */
/*   Updated: 2025/08/07 14:44:30 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_not_alpha_or_numeric(char c)
{
	if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
		return (1);
	else
		return (0);
}

int	ft_is_lowercase(char c)
{
	if (c > 96 && c < 123)
		return (1);
	return (0);
}

int	ft_is_uppercase(char c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_is_uppercase(str[i]))
			str[i] += 32;
		i++;
	}
	if (ft_is_lowercase(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (ft_is_not_alpha_or_numeric(str[i - 1]) && ft_is_lowercase(str[i]))
		{
            str[i] -= 32;
            i++;
		}
		i++;
	}
	return (str);
}
/*#include <stdio.h>

int	main(void)
{
	char greetings[] = "HoWd hi,   y, got \"su? 42s fy-to; y+ad+oe  TGr";
	printf("%s", ft_strcapitalize(greetings));
}*/
