#include "ft_push_swap.h"

void	ft_to_b(t_list **el, t_list **elb)
{
	float	median;
	int		group;
	int		count;
	int		come_back;

	if ((ft_check_sort(*el) == 1) && ((*elb) == NULL))
		return ;
	group = (*el)->group;
	come_back = 0;
	count = 0;
	median = ft_update_min_max(el);
	median = ft_find_median(*el, median);
	while ((*el) != NULL && (*el)->group == group)
	{
		if ((*el)->next && ((*el)->number > (*el)->next->number)
			&& ((*el)->next->number > median) && group > 3 )
			ft_s(el, 'a');
		if (ft_check_sort(*el) == 1 && count == 0)
			break ;
		if ((*el)->number <= median)
			count += ft_p(el, elb, 'a');
		else
			come_back += ft_r(el, 'a');
	}
	ft_come_back(el, elb, come_back);
}

int	ft_come_back(t_list **el, t_list **elb, int come_back)
{
	while (come_back && (ft_check_sort(*el) != 1)
		&& (ft_how_many_groups(*el) != 1))
	{
		come_back -= ft_rr(el, 'a');
		(*el)->group = ((*el)->group) - 2;
	}
	if ((*el)->next != NULL && (*el)->group == (*el)->next->group
		&& (ft_check_sort(*el) != 1))
		ft_to_b(el, elb);
	else
		if ((*elb) != NULL)
			ft_to_a(el, elb);
	return (0);
}	

void	ft_to_a(t_list **el, t_list **elb)
{
	float	median;
	int		group;
	int		come_back;

	group = (*elb)->group;
	come_back = 0;
	median = ft_update_min_max(elb);
	median = ft_find_median(*elb, median);
	while ((*elb) != NULL && (*elb)->group == group)
	{
		if ((*elb)->next && (*elb)->number < (*elb)->next->number
			&& (*elb)->number > median && group > 3)
			ft_s(elb, 'b');
		if (((*elb)->number) > median || (*elb)->next == NULL
			|| ((*elb)->next->group != group && come_back == 0))
			ft_p(elb, el, 'b');
		else
		{
			ft_update_min_max(elb);
			if ((*elb)->max_number <= median)
				break ;
			come_back += ft_r(elb, 'b');
		}
	}
	ft_come_back_b(el, elb, come_back);
}

int	ft_come_back_b(t_list **el, t_list **elb, int come_back)
{	
	while (come_back && (ft_how_many_groups(*elb) != 1))
	{
		ft_rr(elb, 'b');
		(*elb)->group = ((*elb)->group) - 2;
		come_back--;
	}
	ft_to_b(el, elb);
	return (0);
}

int	ft_small_group(char *argv[])
{
	int	arg[4];

	arg[0] = 0;
	arg[1] = ft_atoi(argv[1]);
	arg[2] = ft_atoi(argv[2]);
	arg[3] = ft_atoi(argv[3]);
	if (arg[1] > arg[2] && arg[2] > arg[3])
		write(1, "sa\nrra\n", 7);
	if (arg[1] < arg[3] && arg[2] > arg[3])
		write(1, "sa\nra\n", 6);
	if (arg[1] > arg[3] && arg[3] > arg[2])
		write(1, "ra\n", 3);
	if (arg[1] > arg[2] && arg[3] > arg[1])
		write(1, "sa\n", 3);
	if (arg[2] > arg[1] && arg[1] > arg[3])
		write(1, "rra\n", 4);
	return (0);
}
