#include "minishell.h"

void	ft_run_child(int fd_in, int fd_out, int count, int p[])
{
	if (g_var.shell[count].fd_output == -1 || g_var.shell[count].fd_input == -1)
	{
		p[0] = close(p[0]) + close(p[1]);
		exit(EXIT_FAILURE);
	}
	if (g_var.shell[count].fd_output != 1)
		fd_out = g_var.shell[count].fd_output;
	else
		if ((count + 1) != g_var.len_shell)
			fd_out = p[1];
	if (fd_in != 0)
		dup2(fd_in, 0);
	if (fd_out != 1)
		dup2(fd_out, 1);
	close(p[0]);
	close(p[1]);
	if (fd_out != p[1] && fd_out != 1)
		close(fd_out);
	if (fd_in != p[0] && fd_in != 0)
		close(fd_in);
	if (parsing_command(count) != -1)
		exit(EXIT_SUCCESS);
	ft_correct_path(count);
	command_open(count);
	exit(-1);
}

void	ft_run_parent(int *count, int *fd_in, int *p)
{
	close(p[1]);
	if (*fd_in != 0)
		close(*fd_in);
	if (g_var.shell[*count].fd_output != 1)
		close(g_var.shell[*count].fd_output);
	*fd_in = dup(p[0]);
	close(p[0]);
	(*count)++;
	if (*count < g_var.len_shell && g_var.shell[*count].fd_input != 0)
	{
		close(*fd_in);
		*fd_in = g_var.shell[*count].fd_input;
	}
}

void	ft_last_status(int *status)
{
	if (*status == 65280)
		g_var.ret = 127;
	else
		g_var.ret = *status >> 8;
}

void	ft_do_commands(int count)
{
	pid_t	pid[100];
	int		p[2];
	int		fd_in;
	int		status;

	fd_in = g_var.shell[0].fd_input;
	while (count < g_var.len_shell)
	{
		pipe(p);
		pid[count] = fork();
		if (pid[count] == -1)
			exit(EXIT_FAILURE);
		if (pid[count] == 0)
			ft_run_child(fd_in, 1, count, p);
		else
			ft_run_parent(&count, &fd_in, p);
	}
	waitpid(pid[count - 1], &status, 0);
	close(fd_in);
	ft_last_status(&status);
	count = 0;
	while (count < g_var.len_shell)
		kill(pid[count++], SIGKILL);
}

void	ft_open_pipe(void)
{
	int		count;

	count = 0;
	while (count < g_var.len_shell)
	{
		ft_def_input(count);
		ft_def_output(count);
		count++;
	}
	ft_correct_order(0);
	if (g_var.len_shell == 1 && ft_check_builtin() == 1)
		ft_do_one_command();
	else
		ft_do_commands(0);
}
