#include  "ft_so_long.h"

int	ft_lstfree(t_data **lst)
{
	t_data	*buf;
	t_data	*el;

	el = *lst;
	if (el == NULL)
		return (0);
	while (el)
	{
		buf = el->next;
		free(el);
		el = buf;
	}
	*lst = NULL;
	return (1);
}

t_data	*ft_lstnew(int x, int y, char content)
{
	t_data	*el;

	el = (t_data *) malloc(sizeof(t_data));
	if (el == NULL)
		return (el);
	el->x = x;
	el->y = y;
	el->content = content;
	el->next = NULL;
	return (el);
}

t_data	*ft_lstlast(t_data *lst)
{
	t_data	*el;

	el = lst;
	if (!el)
		return (el);
	while (el->next != NULL)
		el = el->next;
	return (el);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*last;

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
