/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:24 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/11/30 12:39:59 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# if BUFFER_SIZE > 2147483646
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define FD_TOTAL 2048

typedef struct s_gnl
{
	char	*rest_fd[FD_TOTAL];
	char	buf[BUFFER_SIZE + 1];
}			t_gnl;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
