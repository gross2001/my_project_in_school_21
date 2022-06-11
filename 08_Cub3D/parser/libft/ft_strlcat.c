/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:19:21 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:19:21 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		k;
	size_t		len_dst;
	size_t		len_src;

	k = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while ((size > 0) && (len_dst + k) < (size - 1) && src[k] != '\0')
	{
		dst[len_dst + k] = src[k];
		k++;
	}
	dst[len_dst + k] = '\0';
	if (size > len_dst)
		return (len_src + len_dst);
	return (len_src + size);
}
