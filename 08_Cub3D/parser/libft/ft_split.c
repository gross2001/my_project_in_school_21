/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:19:07 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:19:07 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *t, char c)
{
	int	i;
	int	count_w;

	i = 0;
	count_w = 0;
	while (t[i])
	{
		while (t[i] == c)
			i++;
		if (t[i])
			count_w++;
		while (t[i] != c && t[i])
			i++;
	}
	return (count_w);
}

static int	ft_count_s(char const *t, char c)
{
	int		len;

	len = 0;
	while (t[len] && t[len] != c)
		len++;
	return (len);
}

static void	ft_free(char ***matrix, int j)
{
	while (j > 0)
	{
		free(*matrix[j]);
		j--;
	}
	free(*matrix);
	*matrix = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	k;
	int		j;
	char	**matrix;

	k = -1;
	j = -1;
	if (!s)
		return (NULL);
	matrix = (char **)malloc(sizeof (char *) * (count_words(s, c)) + 1);
	if (!matrix)
		return (NULL);
	while (s[++k] && ft_strlen(s) > k)
	{
		if (s[k] != c)
		{
			matrix[++j] = ft_substr(s + k, 0, ft_count_s(s + k, c));
			k += ft_strlen(matrix[j]);
			if (matrix[j] == NULL)
				ft_free(&matrix, j - 1);
		}
		while (s[k] && s[k] != c)
			k++;
	}
	matrix[count_words(s, c)] = NULL;
	return (matrix);
}
