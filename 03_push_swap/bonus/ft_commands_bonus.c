#include "ft_push_swap_bonus.h"

int	ft_s_bonus(t_list **lst)
{
	int	buf;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return (1);
	buf = (*lst)->next->number;
	(*lst)->next->number = (*lst)->number;
	(*lst)->number = buf;
	return (1);
}

int	ft_rr_bonus(t_list **lst)
{
	t_list	*buf;
	t_list	*el;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return (1);
	ft_lstadd_front(lst, ft_lstcopy(ft_lstlast(*lst)));
	el = *lst;
	while (el->next->next)
		el = el->next;
	buf = el->next;
	el->next = NULL;
	free(buf);
	return (1);
}

int	ft_r_bonus(t_list **lst)
{
	t_list	*buf;
	t_list	*el;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return (1);
	ft_lstadd_back(lst, ft_lstcopy((*lst)));
	el = *lst;
	buf = el->next;
	free(el);
	*lst = buf;
	return (1);
}

int	ft_p_bonus(t_list **lsta, t_list **lstb)
{
	t_list	*buf;
	t_list	*el;

	if ((*lsta) == NULL)
		return (1);
	ft_lstadd_front(lstb, ft_lstcopy((*lsta)));
	el = *lsta;
	buf = el->next;
	free(el);
	*lsta = buf;
	return (1);
}
