/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgraling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:14:56 by rgraling          #+#    #+#             */
/*   Updated: 2024/09/11 18:51:41 by rgraling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isprint(char c)
{
	if (c < ' ' || c == 127)
		return (1);
	else
		return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_convert(char c)
{
	char	*base;
	char	output[2];

	base = "0123456789abcdef";
	output[0] = base[(c >> 4) & 0xF];
	output[1] = base[c & 0xF];
	write(1, output, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isprint(str[i]))
		{
			ft_putchar(str[i]);
		}
		if (ft_isprint(str[i]))
		{
			ft_putchar(92);
			ft_convert(str[i]);
		}
		i++;
	}
}
int	main(void)
{
	char str[] = "J'aime les kiwis \n \t\n";
	ft_putstr_non_printable(str);
	return(0);
}
