/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:18:09 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:18:09 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = n;
	while (n-- > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		if (*(unsigned char *)dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		src++;
	}
	return (NULL);
}
