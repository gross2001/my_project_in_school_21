#include "ft_push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*el;
	t_list	*elb;
	int		i;

	el = NULL;
	elb = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (ft_check_arg(argc, argv) == 0)
		write(1, "Error\n", 6);
	if (ft_check_arg(argc, argv) == 0)
		return (0);
	if (argc == 4)
		ft_small_group(argv);
	if (argc == 4)
		return (0);
	while (argc > i)
	{
		ft_lstadd_back(&el, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_to_b(&el, &elb);
	i = ft_lstfree(&el) + ft_lstfree(&elb);
	return (0);
}
