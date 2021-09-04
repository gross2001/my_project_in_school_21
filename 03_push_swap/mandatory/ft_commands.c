#include "ft_push_swap.h"

int	ft_s(t_list **lst, char ch)
{
	int	buf;

	buf = (*lst)->next->number;
	(*lst)->next->number = (*lst)->number;
	(*lst)->number = buf;
	if (ch == 'a')
		write(1, "sa\n", 3);
	if (ch == 'b')
		write(1, "sb\n", 3);
	return (1);
}

int	ft_rr(t_list **lst, char ch)
{
	t_list	*buf;
	t_list	*el;

	ft_lstadd_front(lst, ft_lstcopy(ft_lstlast(*lst)));
	el = *lst;
	while (el->next->next)
		el = el->next;
	buf = el->next;
	el->next = NULL;
	free(buf);
	if (ch == 'a')
		write(1, "rra\n", 4);
	if (ch == 'b')
		write(1, "rrb\n", 4);
	return (1);
}

int	ft_r(t_list **lst, char ch)
{
	t_list	*buf;
	t_list	*el;

	ft_lstadd_back(lst, ft_lstcopy((*lst)));
	el = *lst;
	buf = el->next;
	free(el);
	if (ch == 'a')
		write(1, "ra\n", 3);
	if (ch == 'b')
		write(1, "rb\n", 3);
	*lst = buf;
	return (1);
}

int	ft_p(t_list **lsta, t_list **lstb, char ch)
{
	t_list	*buf;
	t_list	*el;

	ft_lstadd_front(lstb, ft_lstcopy((*lsta)));
	el = *lsta;
	buf = el->next;
	free(el);
	*lsta = buf;
	if (ch == 'a')
		write(1, "pb\n", 3);
	if (ch == 'b')
		write(1, "pa\n", 3);
	return (1);
}
