/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:56:20 by regralin          #+#    #+#             */
/*   Updated: 2025/08/24 23:11:12 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_separator(int n, char **numbers)
{
	int		i;
	char	*buff;

	i = 0;
	buff = malloc(n + 2);
	if (!buff)
		return ;
	if (n < 3)
		return ;
	buff[i++] = 49;
	while (i <= n)
		buff[i++] = 48;
	buff[i] = '\0';
	ft_find(buff, numbers);
	free(buff);
}

void	ft_fill(char *box, char *src, int n)
{
	int	i;

	i = 0;
	while (i < 3)
		box[i++] = 0;
	i = 0;
	while (i < n)
	{
		box[i] = *(src + i);
		i++;
	}
}

int	ft_box_ten(char *box, char *buff, int i, char **numbers)
{
	if (box[i] == 49)
	{
		buff[0] = box[i];
		buff[1] = box[i + 1];
		ft_find(buff, numbers);
		return (0);
	}
	else if (box[i] != 48)
	{
		buff[0] = box[i];
		buff[1] = 48;
		ft_find(buff, numbers);
		return (1);
	}
	return (1);
}

void	ft_read_box(char *box, int n, char **numbers)
{
	int		i;
	int		res;
	char	buff[3];

	i = 0;
	buff[2] = '\0';
	if (n == 3)
	{
		if (box[i] != 48)
		{
			ft_find_char(box[i], numbers);
			ft_find("100", numbers);
		}
		i++;
		n--;
	}
	if (n == 2)
	{
		res = ft_box_ten(box, buff, i, numbers);
		if (res && ++i)
			n--;
	}
	if (n == 1 && (box[i] != 48 || i == 0))
		ft_find_char(box[i], numbers);
}

void	ft_print_solution(char *src, char **numbers)
{
	int		i;
	int		size;
	char	box[3];

	i = 0;
	size = ft_number_size(src);
	if (size % 3)
	{
		ft_fill(box, src, size % 3);
		ft_read_box(box, size % 3, numbers);
		if (box[size % 3] != 48)
			ft_put_separator(size - (size % 3), numbers);
		i = i + (size % 3);
	}
	while (i < size)
	{
		ft_fill(box, src + i, 3);
		ft_read_box(box, 3, numbers);
		if (box[0] != 48 || box[1] != 48 || box[2] != 48)
			ft_put_separator(size - 3 - i, numbers);
		i += 3;
	}
}
