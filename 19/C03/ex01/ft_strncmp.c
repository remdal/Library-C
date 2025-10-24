/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:13:12 by regralin          #+#    #+#             */
/*   Updated: 2025/08/08 10:22:27 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && n > i && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <stdio.h>
int	main(void)
{
	unsigned int	i;

	i = 5;
	char greetings[] = "Hello World!";
	char greetins[] = "Hella Warlr";
	char greet[10];

	greet[0] = 0;
	printf("%i", ft_strncmp(greetins, greetings, i));
	//printf("%s", greet);
	return (0);
}*/
