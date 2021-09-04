#include "minishell.h"

int	command_echo(int i)
{
	int	count;
	int	flag;

	count = (flag = 1);
	while (count < g_var.shell[i].len_arg)
	{
		if (ft_strcmp("-n", g_var.shell[i].arg[count]))
			write(1, g_var.shell[i].arg[count], \
				ft_strlen(g_var.shell[i].arg[count]));
		else
			flag = 0;
		if ((count + 1) != g_var.shell[i].len_arg
			&& ft_strcmp("-n", g_var.shell[i].arg[count]))
			write(1, " ", 1);
		count++;
	}
	if (flag == 1)
		printf("\n");
	g_var.ret = 0;
	return (0);
}
