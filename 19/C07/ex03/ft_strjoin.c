/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:02:28 by regralin          #+#    #+#             */
/*   Updated: 2025/08/21 16:45:21 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_aloc(int size, char **strs, char *sep)
{
	int	i;
	int	res;

	i = 0;
	res = (size - 1) * ft_strlen(sep);
	while (size > i)
		res += ft_strlen(strs[i++]);
	return (res);
}

char	*ft_fill(int size, char *str, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < size)
	{
		k = 0;
		while (strs[j][k])
			str[i++] = strs[j][k++];
		k = 0;
		while (sep[k] && j < size - 1)
			str[i++] = sep[k++];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;

	if (size <= 0)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(get_aloc(size, strs, sep) + 1);
	if (!str)
		return (NULL);
	return (ft_fill(size, str, strs, sep));
}

/*#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	size = 5;
	char	*sep = "1234";
	char	*final[] = { "", "", "bien?",
				"redoubledetesstsss", "r fg" };

	printf("%s\n", ft_strjoin(size, final, sep));
	return (0);
}*/
