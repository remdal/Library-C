/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:38:38 by regralin          #+#    #+#             */
/*   Updated: 2025/08/10 16:20:56 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "unistd.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
    char    *aloc;
    int     i;

    i = 0;
    aloc = malloc(ft_strlen(src) + 1);
    if (!aloc)
        return (NULL);
    while (src[i])
    {
        aloc[i] = src[i];
        i++;
    }
    aloc[i] = '\0';
    return (aloc);
}

int char_in_base(char c, const char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
    if (ft_strlen(base) < 2)
        return (0);
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

void    ft_putnbr_base(int nbr, char *base)
{
    long long int    nb;

    nb = (long long int)nbr;
    if (nbr == 0)
    {
        ft_putchar(base[0]);
        return ;
    }
    if (!is_valid_base(base))
        return ;
    if (nb < 0)
    {
        ft_putchar(45);
        nb = -(nb);
    }
    if (nb / ft_strlen(base) != 0)
        ft_putnbr_base(nb / ft_strlen(base), base);
    ft_putchar(base[nb % ft_strlen(base)]);
}

int    skip(int *pn, char *str)
{
    int    i;

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

int    atoi_alternative(char c, char *base)
{
    int    i;

    i = 0;
    while (base[i])
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int    ft_atoi_base(char *str, char *base)
{
    int             pn;
    int             i;
    long long int   value;

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

void    itoa(int nb, char *str)
{
    int     i;
    int     is_neg;
    int     len;
    int     j;
    char    temp;

    i = 0;
    j = 0;
    is_neg = 0;
    len = ft_strlen(str);
    if (nb < 0)
    {
        is_neg = 1;
        nb = -(nb);
    }
    while (nb > 0)
    {
        str[i++] = nb % 10 + 48;
        nb /= 10;
    }
    if (is_neg)
        str[i++] = '-';
    str[i] = '\0';
    while (j < len / 2)
    {
        temp = str[j];
        str[j] = str[len - 1 - j];
        str[len - 1 - j] = temp;
        j++;
    }
}

char*	convert_base(const char *nbr, const char *base_from, const char *base_to)
{
	int     i;
	int     base_from_len;
	long	decimal;
    int     digit;
    int     base_to_len;
    char    buffer[65] = {0}; // Taille max pour un long en binaire à malloc
    int     index;

	i = 0;
    index = sizeof(buffer) - 2;
	decimal = 0;
	base_from_len = ft_strlen(base_from); // this is a convertor to décimal.
    base_to_len = ft_strlen(base_to); // to
	if (!base_from || !base_to || ft_strlen(base_from) < 2 || ft_strlen(base_to) < 2)
		return (NULL);
	while (nbr[i])
	{
        digit = char_in_base(nbr[i], base_from);
        if (digit == -1)
            return (NULL);
        decimal = decimal * base_from_len + digit;
        i++;
    }
    if (decimal == 0)
    {
        buffer[index] = base_to[0];
        index--;
    } else {
        while (decimal > 0)
        {
            buffer[index] = base_to[decimal % base_to_len];
            decimal /= base_to_len;
            index--;
        }
        index++;
    }
    return (ft_strdup(buffer + index + 1));
}

// Fonction principale de test
int	main(void)
{
	const char	*binary = "01";
    char    *binari = "01";
	const char	*decimal = "0123456789";
	const char	*hex = "0123456789ABCDEF";
    char    *hexa = "0123456789ABCDEF";
	const char *my_base = "oO0";
	char *result;
    char    *poneyvif;
    int num = 7;

    char ascii = num + '0'; // '7'
    
    // Conversion hexadécimal vers décimal
    result = convert_base("FF", hex, decimal);
    printf("FF (hex) -> %s (dec)\n", result);
    free(result);
    
    // Conversion binaire vers hexadécimal
    result = convert_base("10101111", binary, hex);
    printf("10101111 (bin) -> %s (hex)\n", result);
    free(result);
    
    // Conversion avec base personnalisée
    result = convert_base("O0O", my_base, decimal);
    printf("O0O (my_base) -> %s (dec)\n", result);
    free(result);
    
    // Recherche de caractère dans une base
    char test_char = 'A';
    int pos = char_in_base(test_char, hex);
    if (pos != -1) {
        printf("'%c' trouvé dans la base hex à la position %d\n", test_char, pos);
    } else {
        printf("'%c' non trouvé dans la base hex\n", test_char);
    }
    char    testeur[33] = "1942alitleponeyvifisinmypwd26ABC"; // 32 char
    poneyvif = "poneyvif";
    char    integer[2] = "16";
    printf("%i\n", ft_atoi_base(testeur, hexa));
    printf("%i\n", ft_atoi_base(testeur, binari));
    printf("%i\n", ft_atoi_base(testeur, poneyvif));
    printf("%i\n", ft_atoi_base(integer, binari));
    printf("%i\n", ft_atoi_base(integer, hexa));
    
    return 0;
}
