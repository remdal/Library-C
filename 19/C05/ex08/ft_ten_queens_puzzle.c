/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:31:00 by regralin          #+#    #+#             */
/*   Updated: 2025/08/12 11:01:22 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_valid_position(char *map, int x, int position)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[i] - 48 == position
			|| map[i] - 48 == (position - (x - i))
			|| map[i] - 48 == (position + (x - i)))
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtracking(char *map, int x, int *count)
{
	int	i;

	i = 0;
	if (x == 10)
	{
		while (i < 10)
			ft_putchar(map[i++]);
		ft_putchar('\n');
		(*count)++;
		return ;
	}
	map[x] = '0';
	while (map[x] - 48 < 10)
	{
		if (ft_is_valid_position(map, x, map[x] - 48))
			ft_backtracking(map, x + 1, count);
		map[x]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	map[10];
	int		count;

	count = 0;
	ft_backtracking(map, 0, &count);
    printf("%i", count);
    return (count);
}

int	main(void)
{
	return (ft_ten_queens_puzzle(), 0);
}
