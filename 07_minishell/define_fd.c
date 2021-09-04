#include "minishell.h"

void	ft_def_output(int n)
{
	int		i;

	g_var.shell[n].fd_output = (i = 0) + 1;
	while (g_var.shell[n].len_arg > i && (g_var.shell[n].fd_output != -1))
	{
		if (g_var.shell[n].arg[i] && g_var.shell[n].arg[i][0] == '>')
		{
			if (g_var.shell[n].fd_output != 1)
				close (g_var.shell[n].fd_output);
			if (g_var.shell[n].arg[i][1] == '>')
				g_var.shell[n].fd_output = open(g_var.shell[n].arg[i + 1],
						O_CREAT | O_APPEND | O_WRONLY, S_IRWXU);
			else
				g_var.shell[n].fd_output = open(g_var.shell[n].arg[i + 1],
						O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
			if (g_var.shell[n].fd_output == -1)
				printf("minishell: %s: %s\n", g_var.shell[n].arg[i + 1],
					strerror(errno));
			free(g_var.shell[n].arg[i]);
			g_var.shell[n].arg[i] = NULL;
			free(g_var.shell[n].arg[i + 1]);
			g_var.shell[n].arg[1 + i++] = NULL;
		}
		i++;
	}
}

void	ft_double_input(int count, int i)
{
	char	*str_to_stop;
	char	*buf;

	buf = "string";
	g_var.shell[count].fd_input = open(".buf_fo_redirect",
			O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	str_to_stop = ft_strjoin(g_var.shell[count].arg[i + 1], "");
	while (ft_strcmp(buf, str_to_stop) != 0)
	{
		buf = readline(">");
		if (!ft_strcmp(buf, str_to_stop))
			break ;
		write(g_var.shell[count].fd_input, buf, ft_strlen(buf));
		write(g_var.shell[count].fd_input, "\n", 1);
		free(buf);
	}
	free(buf);
	free(str_to_stop);
	close(g_var.shell[count].fd_input);
	g_var.shell[count].fd_input = open(".buf_fo_redirect", O_RDONLY, S_IRWXU);
}

void	ft_def_input(int n)
{
	int		i;

	i = 0;
	g_var.shell[n].fd_input = 0;
	while (g_var.shell[n].len_arg > i && (g_var.shell[n].fd_input != -1))
	{
		if (g_var.shell[n].arg[i] && g_var.shell[n].arg[i][0] == '<')
		{
			if (g_var.shell[n].fd_input != 0)
				close (g_var.shell[n].fd_input);
			if (g_var.shell[n].arg[i][1] == '<')
				ft_double_input(n, i);
			else
				g_var.shell[n].fd_input = open(g_var.shell[n].arg[i + 1],
						O_RDONLY);
			if (g_var.shell[n].fd_input == -1)
				printf("minishell: %s: %s\n", g_var.shell[n].arg[i + 1],
					strerror(errno));
			free(g_var.shell[n].arg[i]);
			g_var.shell[n].arg[i] = NULL;
			free(g_var.shell[n].arg[i + 1]);
			g_var.shell[n].arg[i + 1] = NULL;
		}
		i++;
	}
}
