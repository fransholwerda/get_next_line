/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:30 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/03/04 17:31:42 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	find_newline(int fd, char *buf, char *temp)
// {
// 	int done;
// 	int i;

// 	while (1)
// 	{
// 		read(fd, buf, BUFFER_SIZE);
// 		i = 0;
// 		while (i < BUFFER_SIZE)
// 		{
// 			if (buf[i] == '\n')

// 		}
// 	}
// }

int	get_next_line(int fd, char **line)
{
	char	*buf;
	char	*temp;

	if(*line != NULL)
	{
		printf("it was not null\n");
		free(line);
	}
	else
	{
		printf("it was null\n");
	}
	// buf = malloc(BUFFER_SIZE * sizeof(char));
	// if (!buf)
	// 	return (NULL);
	// printf("%s", buf);
	// free(buf);
	return (0);
}
