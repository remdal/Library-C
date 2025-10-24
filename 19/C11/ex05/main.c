/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:56:24 by regralin          #+#    #+#             */
/*   Updated: 2025/08/27 13:36:22 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_sanitize(int av3, char av2, char av0)
{
	if ((av2 != 43 && av2 != 45 && av2 != 37 && av2 != 42 && av2 != 47) \
			&& av0 != '\0')
		return (ft_putchar(48), 0);
	if (av2 == 47 && av3 == 0)
		return (ft_putstr("Stop : division by zero"), 0);
	if (av2 == 37 && av3 == 0)
		return (ft_putstr("Stop : modulo by zero"), 0);
	return (1);
}

void	ft_array(int av1, int av3, char av)
{
	int		(*operator[5])(int, int);

	if (av || av1 || av3)
	{
		operator[0] = ft_division;
		operator[1] = ft_multiplication;
		operator[2] = ft_subtraction;
		operator[3] = ft_addition;
		operator[4] = ft_modulo;
	}
}

/*void	ft_jsp(int av1, int av3, char av, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (tab_op[i] == )
			ft_putnbr(f(av1, av3));*/

/*int	ft_find(char *str)
{
	while (*str)
	{
		if (*str == 57)
			return (1);
		str++;
	}
	return (0);
}

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (i + 1);
		i++;
	}
	return (0);
}*/

void	ft_parsing(int av1, int av3, char av2, void (*f)(int))
{
	int	i;

	i = 0;
	if (ft_strcmp(av2, "+") == 1)
		i = ft_addition(av1, av3);
	if (ft_strcmp(av2, "-") == 1)
		i = ft_subtraction(av1, av3);
	if (ft_strcmp(av2, "/") == 1)
		i = ft_division(av1, av3);
	if (ft_strcmp(av2, "*") == 1)
		i = ft_multiplication(av1, av3);
	if (ft_strcmp(av2, "%") == 1)
		i = ft_modulo(av1, av3);
	f(i);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	av1;
	int	av3;

	i = 0;
	av1 = 0;
	av3 = 0;
	if (argc == 4)
	{
		av1 = ft_atoi(argv[1]);
		av3 = ft_atoi(argv[3]);
		if (ft_sanitize(av3, argv[2][0], argv[2][1]))
			ft_parsing(av1, av3, argv[2][0], &ft_putnbr);
	}
	return (0);
}
