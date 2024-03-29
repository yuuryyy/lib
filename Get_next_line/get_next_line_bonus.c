/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:39:51 by ychagri           #+#    #+#             */
/*   Updated: 2024/03/11 21:24:07 by ychagri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../Libft/libft.h"

char	*ft_getremainder(char *str, int *i)
{
	char	*rest;
	int		j;

	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (str[j] == '\n')
		rest = malloc(j + 2);
	else
		rest = malloc (j + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (str[j] && str[j] != '\n')
	{
		rest[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		rest[j++] = '\n';
	rest[j] = '\0';
	*i = j;
	return (rest);
}

char	*ft_update(char	*str, int i)
{
	char	*ptr;
	int		j;

	ptr = malloc (ft_strlen(str + i) + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (str[i])
	{
		ptr[j++] = str[i++];
	}
	ptr[j] = '\0';
	free (str);
	return (ptr);
}

char	*currentline(char **str, int fd, int *i, char *buffer)
{
	char	*line;
	int		read_size;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0 && ft_strlen(*str) == 0)
		{
			free(buffer);
			if (*str)
				free(*str);
			return (NULL);
		}
		buffer[read_size] = '\0';
		*str = ft_strjoin2(*str, buffer);
		if (ft_strchr2(*str, '\n'))
			break ;
	}
	free(buffer);
	line = ft_getremainder(*str, i);
	*str = ft_update(*str, *i);
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*str[OPEN_MAX];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || OPEN_MAX <= fd)
		return (NULL);
	if (BUFFER_SIZE == INT_MAX)
		buffer = malloc(BUFFER_SIZE);
	else
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	line = currentline(&str[fd], fd, &i, buffer);
	return (line);
}
