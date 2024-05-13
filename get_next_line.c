/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:37:35 by angerard          #+#    #+#             */
/*   Updated: 2024/05/13 18:49:35 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

static char	*handle_residual_data(char *line_buffer)
{
	char	*txt_left;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
	{
		i++;
	}
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	txt_left = ft_substr(line_buffer, i + i, ft_strlen(line_buffer) - i);
	if (*txt_left == 0)
	{
		free(txt_left);
		txt_left = NULL;
	}
	line_buffer[i + 1] = 0;
	return (txt_left);
}

static char	*read_line_from_file(int fd, char *txt_left, char *buffer)
{
	ssize_t	size_read;
	char	*tmp;

	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(txt_left);
			return (NULL);
		}
		else if (size_read == 0)
			break ;
		buffer[size_read] = 0;
		if (!txt_left)
			txt_left = ft_strdup("");
		tmp = txt_left;
		txt_left = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (txt_left);
}

char	*get_next_line(int fd)
{
	static char	*txt_left;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(txt_left);
		free(buffer);
		txt_left = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_line_from_file(fd, txt_left, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	txt_left = handle_residual_data(line);
	return (line);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	// int		i;
// 	// i = 0;
// 	fd = open("./test_text.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		// printf("[%d]: %s", i, line);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 		// i++;
// 	}
// 	return (0);
// }
