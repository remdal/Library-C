/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:16:31 by regralin          #+#    #+#             */
/*   Updated: 2025/08/08 10:29:52 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*#include <stdio.h>
int	main(void)
{
	unsigned int	i;

	i = 22;
	char greetings[] = "Hello World!";
	char greet[10];

	greet[0] = 0;
	printf("%i", ft_strcmp(greetings, greetings));
	//printf("%s", greet);
	return (0);
}*/
