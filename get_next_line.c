/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/05/17 14:20:01 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	cut_used_line(int fd, t_gnl *gnl, size_t i)
{
	char	*temp_str;
	char	*temp;

	temp_str = gnl->rest_fd[fd];
	temp = ft_strdup(&temp_str[i + 1]);
	free(gnl->rest_fd[fd]);
	gnl->rest_fd[fd] = temp;
}

static int	fill_line(int fd, t_gnl *gnl, char **line)
{
	size_t	i;
	size_t	j;
	char	*temp;
	int		return_value;

	i = 0;
	return_value = 1;
	while (gnl->rest_fd[fd][i] != '\n')
	{
		if (gnl->rest_fd[fd][i] == '\0')
		{
			return_value = 0;
			break ;
		}
		i++;
	}
	temp = malloc(sizeof(char) * i);
	*line = temp;
	j = 0;
	while (j < i)
	{
		temp[j] = gnl->rest_fd[fd][j];
		j++;
	}
	temp[j] = '\0';
	cut_used_line(fd, gnl, i);
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	char			*temp;
	int 			return_value;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	while (read(fd, gnl.buf, BUFFER_SIZE))
	{
		gnl.buf[BUFFER_SIZE] = '\0';
		if (gnl.rest_fd[fd] == NULL)
			gnl.rest_fd[fd] = ft_strdup(gnl.buf);
		else
		{
			temp = ft_strjoin(gnl.rest_fd[fd], gnl.buf);
			free(gnl.rest_fd[fd]);
			gnl.rest_fd[fd] = temp;
		}
		if (ft_strchr(gnl.buf, '\n'))
			break ;
	}
	return_value = fill_line(fd, &gnl, line);
	return (return_value);
}
