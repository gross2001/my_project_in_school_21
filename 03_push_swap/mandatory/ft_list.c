#include "ft_push_swap.h"

t_list	*ft_lstnew(int number)
{
	t_list	*el;

	el = (t_list *) malloc(sizeof(t_list));
	if (el == NULL)
		return (el);
	el->number = number;
	el->group = 0;
	el->next = NULL;
	return (el);
}

t_list	*ft_lstcopy(t_list *lst)
{
	t_list	*el;

	el = (t_list *) malloc(sizeof(t_list));
	if (el == NULL)
		return (el);
	el->number = lst->number;
	el->group = lst->group + 1;
	el->min_number = lst->min_number;
	el->max_number = lst->max_number;
	el->next = NULL;
	return (el);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*el;

	el = lst;
	if (!el)
		return (el);
	while (el->next)
		el = el->next;
	return (el);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
	{
		*lst = new;
		return ;
	}
	last->next = new;
	return ;
}
