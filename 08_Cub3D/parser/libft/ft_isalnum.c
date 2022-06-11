/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:16:54 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:16:55 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int s)
{
	if ((s >= '0' && s <= '9')
		|| ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')))
		return (1);
	else
		return (0);
}
