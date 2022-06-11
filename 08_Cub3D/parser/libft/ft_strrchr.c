/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:19:44 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:19:44 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s) - 1;
	if ((char)c == '\0')
		return ((char *)s + (len + 1));
	while (len >= i)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		--len;
	}
	return (0);
}
