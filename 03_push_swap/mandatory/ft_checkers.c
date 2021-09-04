#include "ft_push_swap.h"

int	ft_check_arg(int argc, char *argv[])
{
	int	i;
	int	n;

	i = 1;
	while (argc > i)
	{
		if (ft_isdigit(argv[i]) == 0 || ft_strlen(argv[i]) > 11)
			break ;
		if (ft_atoi_l(argv[i]) > 2147483647 || ft_atoi_l(argv[i]) < -2147483648)
			break ;
		n = 1;
		while (i > n)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[n]))
				break ;
			n++;
		}
		if (i > n && (ft_atoi(argv[i]) == ft_atoi(argv[n])))
			break ;
		i++;
	}
	if (argc == i)
		return (1);
	else
		return (0);
}

int	ft_how_many_groups(t_list *el)
{
	int	group;

	group = el->group;
	while (el != NULL)
	{
		if (el->group != group)
			return (0);
		el = el->next;
	}
	return (1);
}

int	ft_check_sort(t_list *el)
{
	while (el->next != NULL)
	{
		if (el->number > el->next->number)
			return (0);
		el = el->next;
	}
	return (1);
}
