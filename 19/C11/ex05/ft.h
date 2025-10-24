/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 04:17:23 by regralin          #+#    #+#             */
/*   Updated: 2025/08/27 17:14:09 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_strcmp(char c, char *str);
int		ft_atoi(char *str);
int		ft_addition(int a, int b);
int		ft_multiplication(int a, int b);
int		ft_subtraction(int a, int b);
int		ft_division(int a, int b);
int		ft_modulo(int a, int b);
int		ft_sanitize(int av3, char av2, char av0);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_parsing(int av1, int av3, char av2, void (*f)(int));

#endif
