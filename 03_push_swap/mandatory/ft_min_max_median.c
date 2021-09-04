#include "ft_push_swap.h"

int	ft_find_min(t_list *lst)
{
	int	min_number;
	int	group;

	group = lst->group;
	min_number = lst->number;
	while (lst != NULL && lst->group == group)
	{
		if (lst->number < min_number)
			min_number = lst->number;
		lst = lst->next;
	}
	return (min_number);
}

int	ft_find_max(t_list *lst)
{
	int	max_number;
	int	group;

	group = lst->group;
	max_number = lst->number;
	while (lst != NULL && lst->group == group)
	{
		if (lst->number > max_number)
			max_number = lst->number;
		lst = lst->next;
	}
	return (max_number);
}

float	ft_update_min_max(t_list **lst)
{
	t_list	*el;
	int		group;
	int		min_number;
	int		max_number;

	el = *lst;
	while ((el != NULL) && (el->next != NULL))
	{
		group = el->group;
		min_number = ft_find_min(el);
		max_number = ft_find_max(el);
		while (((el) != NULL) && ((el)->group == group))
		{
			(el)->min_number = min_number;
			(el)->max_number = max_number;
			(el) = (el)->next;
		}
	}
	if (((el) != NULL) && ((el)->next == NULL))
	{
		(el)->min_number = (el)->number;
		(el)->max_number = (el)->number;
	}
	return ((float)(*lst)->min_number / 2 + (float)(*lst)->max_number / 2);
}

int	ft_find_closest(t_list *el, float numb, int dir)
{
	float	diff;
	int		result;
	int		group;

	group = el->group;
	result = el->number;
	diff = (float)(ft_find_max(el)) - numb;
	while ((el != NULL) && (el->group == group))
	{
		if (dir < 0 && (el->number - numb) < diff && (el->number - numb) > 0)
		{
			result = el->number;
			diff = (float)el->number - numb;
		}
		if (dir > 0 && (numb - el->number) < diff && (numb - el->number) > 0)
		{
			result = el->number;
			diff = numb - (float)el->number;
		}
		el = el->next;
	}
	return (result);
}

float	ft_find_median(t_list *el, float median)
{
	t_list	*elem;
	int		group;
	int		n;
	int		count;

	if (el == NULL)
		return (median);
	elem = el;
	group = el->group;
	n = 0;
	count = 0;
	while ((elem != NULL) && (elem->group == group) && (++count))
	{
		if (elem->number > median)
			n++;
		if (elem->number < median)
			n--;
		elem = elem->next;
	}
	if (n == 0)
		return (median);
	if (n == 1 && count % 2 == 0)
		return (median + 0.5);
	median = ft_find_median(el, ft_find_closest(el, median, -n));
	return (median);
}
