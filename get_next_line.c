/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/03/25 11:26:08 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	cut_used_line(int fd, char **rest_fd, size_t i)
{
	char	*temp_str;
	char	*temp;

	temp_str = rest_fd[fd];
	temp = ft_strdup(&temp_str[i + 1]);
	free(rest_fd[fd]);
	rest_fd[fd] = temp;
}

static int	fill_line(int fd, char **rest_fd, char **line)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (rest_fd[fd][i] != '\n')
	{
		if (rest_fd[fd][i] == '\0')
			return (0);
		i++;
	}
	temp = malloc(sizeof(char) * i + 1);
	*line = temp;
	j = 0;
	while (j <= i)
	{
		temp[j] = rest_fd[fd][j];
		j++;
	}
	cut_used_line(fd, rest_fd, i);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest_fd[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int 		return_value;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while (read(fd, buf, BUFFER_SIZE))
	{
		buf[BUFFER_SIZE] = '\0';
		if (rest_fd[fd] == NULL)
			rest_fd[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(rest_fd[fd], buf);
			free(rest_fd[fd]);
			rest_fd[fd] = temp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return_value = fill_line(fd, rest_fd, line);
	//printf("<><><><><><><>BUFFER: %s<><><><><><><><>\n", rest_fd[fd]);
	return (return_value);
}
