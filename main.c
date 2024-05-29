/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:40:09 by angerard          #+#    #+#             */
/*   Updated: 2024/05/29 08:44:32 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// void	test_get_next_line(const char *file_path)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(file_path, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return ;
// 	}
// 	printf("Reading file: %s\n", file_path);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	printf("\n");
// }

// int	main(void)
// {
// 	test_get_next_line("tests/files/1char");
// 	printf("\n");
// 	test_get_next_line("tests/files/empty");
// 	printf("\n");
// 	test_get_next_line("tests/files/nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/41_no_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/41_with_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/42_no_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/42_with_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/43_no_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/43_with_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/multiple_nlx5");
// 	printf("\n");
// 	test_get_next_line("tests/files/multiple_line_no_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/multiple_line_with_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/alternate_line_nl_no_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/alternate_line_nl_with_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/big_line_no_nl");
// 	printf("\n");
// 	test_get_next_line("tests/files/big_line_with_nl");
// 	return (0);
// }

void	test_get_next_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}

int	main(void)
{
	int fd1, fd2, fd3;
	fd1 = open("tests/files/41_no_nl", O_RDONLY);
	fd2 = open("tests/files/41_with_nl", O_RDONLY);
	fd3 = open("tests/files/42_no_nl", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Reading from tests/files/41_no_nl:\n");
	test_get_next_line(fd1);
	printf("\n");
	printf("\nReading from tests/files/41_with_nl:\n");
	test_get_next_line(fd2);
	printf("\n");
	printf("\nReading from tests/files/42_no_nl:\n");
	test_get_next_line(fd3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
