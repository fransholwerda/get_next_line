/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/03/11 16:24:24 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(int fd, char *buf, char **templine)
{
	size_t	i;
	char	*buf;
	char	*temp;

	buf = malloc(BUFFER_SIZE);
	temp = malloc(BUFFER_SIZE);
	while (1)
	{
		read(fd, buf, BUFFER_SIZE);
		i = 0;
		while (i < BUFFER_SIZE)
		{
			temp[i] = buf[i];
			if (buf[i] == '\0')
			{
				ft_strjoin(*templine, temp);
				return (0);
			}
			else if (buf[i] == '\n')
			{
				ft_strjoin(*templine, temp);
				return (1);
			}
			i++;
		}
		ft_strjoin(*templine, temp);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*rest_fd[OPEN_MAX];
	char		*buf;
	char		*temp;

	if (*line && fd)
	{
		buf = malloc(BUFFER_SIZE + 1);
		while (read(fd, buf, BUFFER_SIZE))
		{

		}
	}
	return (-1);
}
