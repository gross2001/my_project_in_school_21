#include "minishell.h"

void	ft_do_one_command(void)
{
	int		buf[2];

	if (g_var.shell[0].fd_output == -1 || g_var.shell[0].fd_input == -1)
		return ;
	if (g_var.shell[0].fd_input != 0)
	{
		buf[0] = dup(STDIN_FILENO);
		dup2(g_var.shell[0].fd_input, STDIN_FILENO);
		close (g_var.shell[0].fd_input);
	}
	if (g_var.shell[0].fd_output != 1)
	{
		buf[1] = dup(STDOUT_FILENO);
		dup2(g_var.shell[0].fd_output, STDOUT_FILENO);
		close(g_var.shell[0].fd_output);
	}
	parsing_command(0);
	if (g_var.shell[0].fd_input != 0)
		dup2(buf[0], STDIN_FILENO);
	if (g_var.shell[0].fd_input != 0)
		close(buf[0]);
	if (g_var.shell[0].fd_output != 1)
		dup2(buf[1], STDOUT_FILENO);
	if (g_var.shell[0].fd_output != 1)
		close(buf[1]);
}

void	ft_correct_order(int count)
{
	int		i;
	int		n;

	i = 0;
	while (g_var.shell[count].len_arg > i)
	{
		if (g_var.shell[count].arg[i] == NULL)
		{
			n = i + 1;
			while (n < g_var.shell[count].len_arg
				&& g_var.shell[count].arg[n] == NULL)
				n++;
			if (n == g_var.shell[count].len_arg)
				break ;
			g_var.shell[count].arg[i] = g_var.shell[count].arg[n];
			g_var.shell[count].arg[n] = NULL;
		}
		i++;
	}
}
