/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:28:00 by angerard          #+#    #+#             */
/*   Updated: 2024/05/27 12:50:57 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

static char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

static char	*handle_residual_data(char *line_buffer)
{
	char	*txt_left;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	txt_left = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (txt_left && *txt_left == '\0')
		ft_free(&txt_left);
	if (line_buffer[i + 1] != '\0')
		line_buffer[i + 1] = '\0';
	return (txt_left);
}

static char	*read_line_from_file(int fd, char *txt_left, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&txt_left), ft_free(&buffer), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!txt_left)
			txt_left = ft_strdup("");
		tmp = txt_left;
		txt_left = ft_strjoin(tmp, buffer);
		if (!txt_left)
			return (ft_free(&tmp), ft_free(&buffer), NULL);
		ft_free(&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (txt_left);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
		return (ft_free(&stash[fd]), ft_free(&buffer), NULL);
	line = read_line_from_file(fd, stash[fd], buffer);
	ft_free(&buffer);
	if (!line)
	{
		ft_free(&stash[fd]);
		return (NULL);
	}
	stash[fd] = handle_residual_data(line);
	return (line);
}
