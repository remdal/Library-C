/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:22:12 by regralin          #+#    #+#             */
/*   Updated: 2025/08/27 20:36:28 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2 && *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_swap_str(char **a1, char **a2)
{
	char	*temp;

	temp = *a1;
	*a1 = *a2;
	*a2 = temp;
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	while (i < j - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap_str(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
/*#include <unistd.h>
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

int	main(void)
{
	int	i;

	i = 0;
	char	*tab[] = { "2", "22", "2216820", "9", "0", "1", "1", "8", \
		"1", "b", "k", NULL };
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	while (tab[i])
		ft_putstr(tab[i++]);
	return (0);
}*/
