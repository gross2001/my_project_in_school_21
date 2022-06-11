/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:18:40 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:18:40 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;

	i = 0;
	dest_ptr = dst;
	src_ptr = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (src_ptr > dest_ptr)
	{
		while (i < len)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			dest_ptr[len] = src_ptr[len];
	}
	return (dst);
}
