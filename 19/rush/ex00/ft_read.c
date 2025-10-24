/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regralin <regralin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:53:59 by regralin          #+#    #+#             */
/*   Updated: 2025/08/24 23:12:04 by regralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_get_malloc_size(char *buffer, char *pathname)
{
	int		i;
	int		fd;
	ssize_t	bytes_read;

	i = 1;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, BUFFER - 1);
	while (bytes_read == BUFFER - 1)
	{
		bytes_read = read(fd, buffer, BUFFER - 1);
		i += BUFFER - 1;
	}
	close(fd);
	i += bytes_read;
	return (i + 1);
}

char	**ft_create_array(char *buffer, int fd, char *str)
{
	char	charset;
	char	**array;
	ssize_t	bytes_read;

	str[0] = 0;
	charset = 10;
	bytes_read = read(fd, buffer, BUFFER - 1);
	while (bytes_read == BUFFER - 1)
	{
		buffer[bytes_read] = 0;
		ft_strcat(str, buffer);
		bytes_read = read(fd, buffer, BUFFER - 1);
	}
	buffer[bytes_read] = 0;
	ft_strcat(str, buffer);
	array = ft_split(str, charset);
	return (array);
}

char	**ft_malloc_array(char *buffer, char *pathname)
{
	int		fd;
	char	*str;
	char	**array;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = malloc(ft_get_malloc_size(buffer, pathname));
	if (str == 0)
	{
		close(fd);
		return (NULL);
	}
	array = ft_create_array(buffer, fd, str);
	close(fd);
	free(str);
	return (array);
}
