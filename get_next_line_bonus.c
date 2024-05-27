/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:28:00 by angerard          #+#    #+#             */
/*   Updated: 2024/05/27 15:27:49 by angerard         ###   ########.fr       */
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

static char	*handle_residual_data(char *line)
{
	char	*txt_left;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	txt_left = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (txt_left && *txt_left == '\0')
		ft_free(&txt_left);
	if (line[i + 1] != '\0')
		line[i + 1] = '\0';
	return (txt_left);
}

static char	*read_line_from_file(int fd, char *stash, char *buffer_txt)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer_txt, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(&stash), ft_free(&buffer_txt), NULL);
		else if (bytes_read == 0)
			break ;
		buffer_txt[bytes_read] = '\0';
		if (!stash)
			stash = init_empty_string();
		tmp = stash;
		stash = ft_strjoin(tmp, buffer_txt);
		if (!stash)
			return (ft_free(&tmp), ft_free(&buffer_txt), NULL);
		ft_free(&tmp);
		if (ft_strchr(buffer_txt, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*buffer_txt;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffer_txt = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_txt)
		return (NULL);
	if (read(fd, buffer_txt, 0) < 0)
		return (ft_free(&stash[fd]), ft_free(&buffer_txt), NULL);
	line = read_line_from_file(fd, stash[fd], buffer_txt);
	ft_free(&buffer_txt);
	if (!line || line[0] == '\0')
	{
		ft_free(&stash[fd]);
		return (NULL);
	}
	stash[fd] = handle_residual_data(line);
	return (line);
}
