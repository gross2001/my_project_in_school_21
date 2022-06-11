/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:18:35 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:18:35 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n-- > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
	}
	return (dest - i);
}
