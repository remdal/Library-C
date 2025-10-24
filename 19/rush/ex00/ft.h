/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:12:54 by abahbah           #+#    #+#             */
/*   Updated: 2025/08/24 23:08:29 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

# define PATH "numbers.dict"

# define BUFFER 255

void	ft_error(void);
void	ft_dict_error(void);
char	*ft_atoa(char *str);
char	*ft_strcat(char	*dest, char *src);
char	**ft_split(char *str, char charset);
int		ft_open(char *str, unsigned long int *i);
void	ft_putchar(char c);
void	multi_free(char **numbers);
int		ft_get_malloc_size(char *buffer, char *pathname);
char	**ft_create_array(char *buffer, int fd, char *str);
char	**ft_malloc_array(char *buffer, char *pathname);
int		ft_modulo(char **numbers);
int		ft_number_size(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_get_next_word(char *str, char charset);
int		ft_count_words(char *str, char charset);
void	ft_find_char(char c, char **numbers);
void	ft_find(char *str, char **numbers);
void	ft_print(char *str);
void	ft_print_solution(char *src, char **numbers);
void	ft_read_box(char *box, int n, char **numbers);
int		ft_box_ten(char *box, char *buff, int i, char **numbers);
void	ft_fill(char *box, char *src, int n);
void	ft_put_separator(int n, char **numbers);

#endif
