/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:19:52 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:19:53 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_start(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

static int	ft_check_end(char c, const char *set)
{
	int	len_set;

	len_set = ft_strlen(set) - 1;
	while (set[len_set])
	{
		if (set[len_set] == c)
			return (1);
		len_set--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	len = ft_strlen(s1) - 1;
	while (s1[i] && ft_check_start(s1[i], set))
		i++;
	while (ft_check_end(s1[len], set))
	{
		len--;
	}
	if (i >= len)
		return (ft_strdup(""));
	str = ft_substr(s1, i, len - i + 1);
	return (str);
}
