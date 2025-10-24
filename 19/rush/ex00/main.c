/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:19:44 by regralin          #+#    #+#             */
/*   Updated: 2025/08/24 23:05:54 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	multi_free(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers[i]);
	free(numbers);
}

int	ft_modulo(char **numbers)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (*numbers)
	{
		if (**numbers == 49)
		{
			i = 1;
			while ((*numbers)[i] == 48)
				i++;
			max = i;
		}
		numbers++;
	}
	return (max);
}

int	ft_number_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] > 47 && str[i] < 58)
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char	*av;
	char	**numbers;
	char	*str;

	numbers = NULL;
	str = NULL;
	str = malloc(BUFFER);
    if (!str)
        return (0);
	if (argc == 3)
	{
		numbers = ft_malloc_array(str, argv[1]);
		av = ft_atoa(argv[2]);
	}
	else if (argc == 2)
	{
		numbers = ft_malloc_array(str, PATH);
		av = ft_atoa(argv[1]);
	}
	else
		return ((ft_error()), 0);
	if (numbers == 0 || av == 0)
		return (ft_error(), 0);
	if (ft_modulo(numbers) + 2 < ft_number_size(av))
		return (ft_dict_error(), 0);
	free(str);
	ft_print_solution(av, numbers);
	multi_free(numbers);
	ft_putchar('\n');
	return (0);
}
