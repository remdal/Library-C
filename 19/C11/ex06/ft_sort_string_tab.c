/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:58:44 by regralin          #+#    #+#             */
/*   Updated: 2025/08/27 16:20:47 by regralin         ###   ########.fr       */
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

void	ft_swap_str(char **tab1, char **tab2)
{
	char	*temp;

	temp = *tab1;
	*tab1 = *tab2;
	*tab2 = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap_str(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
/*#include <stdio.h>
int	main(void)
{
	int i  = 0;
	char *tab[] = { "Bonjour", "42", "ecole", "bonjour", \
	"a" , "b", "1", "5", NULL };
	ft_sort_string_tab(tab);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}k = sizeof(tab) / sizeof(tab[0]);
	return (0);
}*/
