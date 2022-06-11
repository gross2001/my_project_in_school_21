/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:17:53 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 12:17:53 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_n;

	lst_n = lst;
	if (lst == NULL)
		return (NULL);
	while (lst_n->next)
		lst_n = lst_n->next;
	return (lst_n);
}
