/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:21:49 by regralin          #+#    #+#             */
/*   Updated: 2025/08/13 07:40:20 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j])
			ft_putchar(argv[i + 1][j++]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
