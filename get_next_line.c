/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/01/18 16:45:40 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	cut_used_line(int fd, t_gnl *gnl, size_t i)
{
	char	*temp_str;
	char	*temp;

	if (!gnl->rest_fd[fd][0])
	{
		return (1);
	}
	temp_str = gnl->rest_fd[fd];
	temp = ft_strdup(&temp_str[i]);
	free(gnl->rest_fd[fd]);
	if (!temp)
		return (-1);
	gnl->rest_fd[fd] = temp;
	return (1);
}

static int	fill_line(char *line, size_t i, t_gnl *gnl, int fd)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		line[j] = gnl->rest_fd[fd][j];
		j++;
	}
	line[j] = '\0';
	return (1);
}

static char	*check_line(int fd, t_gnl *gnl)
{
	size_t	i;
	char	*line;

	if (gnl->rest_fd[fd][0] == '\0')
	{
		free(gnl->rest_fd[fd]);
		gnl->rest_fd[fd] = NULL;
		return (NULL);
	}
	i = 0;
	while (gnl->rest_fd[fd][i] != '\n' && gnl->rest_fd[fd][i] != '\0')
		i++;
	if (gnl->rest_fd[fd][i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	if (fill_line(line, i, gnl, fd) == -1)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	if (cut_used_line(fd, gnl, i) == -1)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*temp;
	int				reading;

	if (fd < 0 || fd > FD_TOTAL || BUFFER_SIZE < 1)
		return (NULL);
	if (!gnl.rest_fd[fd])
		gnl.rest_fd[fd] = ft_strdup("\0");
	if (!gnl.rest_fd[fd])
		return (NULL);
	reading = read(fd, gnl.buf, BUFFER_SIZE);
	while (reading > 0)
	{
		gnl.buf[reading] = '\0';
		temp = ft_strjoin(gnl.rest_fd[fd], gnl.buf);
		free(gnl.rest_fd[fd]);
		if (!temp)
			return (NULL);
		gnl.rest_fd[fd] = temp;
		if (ft_strchr(gnl.rest_fd[fd], '\n'))
			break ;
		reading = read(fd, gnl.buf, BUFFER_SIZE);
	}
	return (check_line(fd, &gnl));
}
