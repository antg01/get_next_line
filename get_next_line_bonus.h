/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angerard <angerard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:16:33 by angerard          #+#    #+#             */
/*   Updated: 2024/05/28 13:05:55 by angerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE > 10000000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# include <sys/syslimits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_FD OPEN_MAX

char	*get_next_line(int fd);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	is_in_str(char *s, char c);

#endif
