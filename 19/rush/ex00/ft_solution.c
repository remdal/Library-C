/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:43:23 by regralin          #+#    #+#             */
/*   Updated: 2025/08/24 23:09:48 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print(char *str)
{
	while (*str > 47 && *str < 58)
		str++;
	while (*(str) == 32)
		str++;
	if (*str)
		str++;
	while (*str == 32)
		str++;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	ft_putchar(32);
}

void	ft_find(char *str, char **numbers)
{
	int	size;

	size = ft_number_size(str);
	while (*numbers)
	{
		if (!ft_strncmp(str, *numbers, size) && (*(*numbers + size) == 32
				|| *(*numbers + size) == 58))
			ft_print(*numbers);
		numbers++;
	}
}

void	ft_find_char(char c, char **numbers)
{
	while (*numbers)
	{
		if (**numbers == c && (*(*numbers + 1) == 32
				|| *(*numbers + 1) == 58))
			ft_print(*numbers);
		numbers++;
	}
}
