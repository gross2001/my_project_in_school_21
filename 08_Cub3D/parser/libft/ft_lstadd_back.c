/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:17:28 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:17:28 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_stct;

	if (lst && new)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			last_stct = ft_lstlast(*lst);
			last_stct->next = new;
		}
	}
}
