/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 15:49:27 by fholwerd      #+#    #+#                 */
/*   Updated: 2021/03/11 15:47:00 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s12;
	unsigned int	i;
	unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s12 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s12 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s12[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		s12[i + j] = s2[j];
		j++;
	}
	s12[i + j] = '\0';
	return (s12);
}

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	i;

	sdup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
