/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:51:45 by regralin          #+#    #+#             */
/*   Updated: 2025/08/27 12:03:38 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_addition(int a, int b)
{
	int	c;

	c = a + b;
	return (c);
}

int	ft_multiplication(int a, int b)
{
	return (a * b);
}

int	ft_division(int a, int b)
{
	a = a / b;
	return (a);
}

int	ft_modulo(int a, int b)
{
	a = a % b;
	return (a);
}

int	ft_subtraction(int a, int b)
{
	a = a - b;
	return (a);
}
