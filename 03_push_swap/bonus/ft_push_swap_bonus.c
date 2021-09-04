#include "ft_push_swap_bonus.h"

int	ft_is_it_sorted(t_list *el, t_list *elb)
{
	if (elb != NULL)
		write(1, "KO\n", 3);
	if (ft_check_sort(el) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

int	ft_run_commands(char *line, t_list **el, t_list **elb)
{
	int	count;

	count = 0;
	if (ft_strncmp(line, "sa\n") == 0)
		count = ft_s_bonus(el);
	if (ft_strncmp(line, "sb\n") == 0)
		count = ft_s_bonus(elb);
	if (ft_strncmp(line, "ra\n") == 0)
		count = ft_r_bonus(el);
	if (ft_strncmp(line, "rb\n") == 0)
		count = ft_r_bonus(elb);
	if (ft_strncmp(line, "rra\n") == 0)
		count = ft_rr_bonus(el);
	if (ft_strncmp(line, "rrb\n") == 0)
		count = ft_rr_bonus(elb);
	if (ft_strncmp(line, "pa\n") == 0)
		count = ft_p_bonus(elb, el);
	if (ft_strncmp(line, "pb\n") == 0)
		count = ft_p_bonus(el, elb);
	return (count);
}

int	ft_take_line(t_list **el, t_list **elb)
{
	char	*line;
	int		count;

	line = NULL;
	while (get_next_line(0, &line, 5) > 0)
	{
		count = ft_run_commands(line, el, elb);
		free (line);
		line = NULL;
		if (count == 0)
			break ;
	}
	if (line)
		free (line);
	return (count);
}

int	main(int argc, char *argv[])
{
	t_list	*el;
	t_list	*elb;
	int		i;

	el = NULL;
	elb = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	if (ft_check_arg(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argc > ++i)
		ft_lstadd_back(&el, ft_lstnew(ft_atoi(argv[i])));
	if (ft_take_line(&el, &elb) == 0)
	{
		write(1, "Error\n", 6);
		i = ft_lstfree(&el) + ft_lstfree(&elb);
		return (0);
	}
	ft_is_it_sorted(el, elb);
	i = ft_lstfree(&el) + ft_lstfree(&elb);
}
