/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:16:51 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:16:51 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mas;

	mas = malloc(nmemb * size);
	if (!(mas))
		return (NULL);
	ft_memset(mas, 0, nmemb * size);
	return (mas);
}
