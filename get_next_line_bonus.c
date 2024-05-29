/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:17:01 by angerard          #+#    #+#             */
/*   Updated: 2024/05/29 08:54:47 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

static char	*init_empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static void	extract_nxline(char **buffer, int eol)
{
	char	*tmp;

	tmp = *buffer;
	*buffer = ft_substr(*buffer, eol, ft_strlen(*buffer));
	ft_free(&tmp);
	return ;
}

static ssize_t	read_line_from_file(int fd, char **buffer)
{
	ssize_t	bytes_read;
	char	*read_buff;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	if (!(*buffer))
		*buffer = init_empty_string();
	if (!(*buffer))
		return (0);
	read_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (ft_free(buffer), 0);
	bytes_read = read(fd, read_buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		read_buff[bytes_read] = '\0';
		*buffer = ft_strjoin(*buffer, read_buff);
		if (is_in_str(*buffer, '\n') >= 0)
			break ;
		bytes_read = read(fd, read_buff, BUFFER_SIZE);
	}
	ft_free(&read_buff);
	if (bytes_read < 0)
		return (ft_free(buffer));
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;
	int			eol;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || !read_line_from_file(fd,
			&buffer[fd]))
		return (NULL);
	eol = is_in_str(buffer[fd], '\n');
	if (eol >= 0)
	{
		line = ft_substr(buffer[fd], 0, eol + 1);
		extract_nxline(&buffer[fd], eol + 1);
	}
	else
	{
		line = ft_substr(buffer[fd], 0, ft_strlen(buffer[fd]));
		ft_free(&buffer[fd]);
		buffer[fd] = NULL;
	}
	if (*line == '\0')
		return (ft_free(&line), ft_free(&buffer[fd]), NULL);
	return (line);
}
