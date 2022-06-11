/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:17:36 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:17:36 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr_lst;

	if (*lst || *del)
	{
		while (*lst)
		{
			ptr_lst = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = ptr_lst;
		}
	}
	return ;
}
