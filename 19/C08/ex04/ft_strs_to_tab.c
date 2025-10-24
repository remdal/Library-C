/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:12:10 by regralin          #+#    #+#             */
/*   Updated: 2025/08/21 20:22:57 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*llc;

	i = 0;
	llc = malloc(ft_strlen(src) + 1);
	if (!llc)
		return (NULL);
	while (src[i])
	{
		llc[i] = src[i];
		i++;
	}
	llc[i] = 0;
	return (llc);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock_str;

	i = 0;
	if (ac < 1)
		ac = 0;
	stock_str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_str)
		return (NULL);
	while (i < ac)
	{
		stock_str[i].size = ft_strlen(av[i]);
		stock_str[i].str = av[i];
		stock_str[i].copy = ft_strdup(stock_str[i].str);
		i++;
	}
	stock_str[i].str = NULL;
	return (stock_str);
}
