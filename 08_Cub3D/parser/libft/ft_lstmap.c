/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:17:56 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:17:56 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_new;
	t_list	*ptr_lst;

	ptr_lst = NULL;
	while (lst)
	{
		ptr_new = ft_lstnew((*f)(lst->content));
		if (!ptr_new)
		{
			ft_lstclear(&ptr_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&ptr_lst, ptr_new);
		lst = lst->next;
	}
	return (ptr_lst);
}
