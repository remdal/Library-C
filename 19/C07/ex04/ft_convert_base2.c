/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:38:38 by regralin          #+#    #+#             */
/*   Updated: 2025/08/21 20:43:22 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_boring(char *base_to);
void	ft_rev_tab(char *tab, int size);
char	*ft_strdup(char *str);
char	*ft_itoa_base(int nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base [j] || base[i] < ' ' || base[j] < ' '
				|| base[i] == '+' || base[j] == '-'
				|| base[j] == '+' || base[i] == '-'
				|| base[i] == 127 || base[j] == 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	skip(int *pn, char *str)
{
	int	i;

	i = 0;
	*pn = 1;
	if (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*pn *= -1;
		i++;
	}
	return (i);
}

int	atoi_alternative(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	pn;
	int	i;
	int	value;

	value = 0;
	i = skip(&pn, str);
	if (!is_valid_base(base) || ft_strlen(base) < 2)
		return (0);
	while (str[i])
	{
		if (atoi_alternative(str[i], base) == -1)
			return (value * pn);
		value *= ft_strlen(base);
		value += atoi_alternative(str[i], base);
		i++;
	}
	return (value * pn);
}
