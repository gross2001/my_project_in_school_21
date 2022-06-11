/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:58:26 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 14:58:27 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char **pointer)
{
	if ((*pointer) != NULL)
	{
		free(*pointer);
		*pointer = 0;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (size);
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

int	ft_strjoin(char **s1, char **s2, int line_size)
{
	char	*s3;
	int		i;
	int		n;

	i = -1;
	n = -1;
	if (line_size == 0)
	{
		ft_free(s2);
		return (0);
	}
	s3 = (char *) malloc ((ft_strlen(*s1) + ft_strlen(*s2) + 1) * sizeof(char));
	if (!s3)
		return (-1);
	if (*s1)
		while ((*s1)[++i])
			s3[i] = (*s1)[i];
	else
		i++;
	while ((*s2)[++n])
		s3[i + n] = (*s2)[n];
	s3[i + n] = '\0';
	i = ft_free(s1) + ft_free(s2);
	*s1 = s3;
	return (0);
}

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_divide(char **temp, char **line)
{	
	int	i;
	int	j;

	i = -1;
	j = 0;
	*line = (char *) malloc((ft_strlen(*temp) + 1) * sizeof(char));
	if (!(*line))
		return (-1);
	**line = '\0';
	if (!(*temp))
		return (0);
	while ((*temp)[++i] != '\n' && ((*temp)[i] != '\0'))
		(*line)[i] = (*temp)[i];
	(*line)[i] = '\0';
	while ((*temp)[i] != '\0' && (*temp)[j + i + 1])
	{
		(*temp)[j] = (*temp)[i + j + 1];
		j++;
	}
	(*temp)[j] = '\0';
	if (!(**temp))
		ft_free(temp);
	return (0);
}
