/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:43:13 by regralin          #+#    #+#             */
/*   Updated: 2025/08/26 01:56:14 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}
/* + proto putchar, putnbr
int	main(void)
{
	int	tab[1337];

	ft_foreach(tab, 1337, &ft_putnbr);
	return (0);
}*/
