#include "minishell.h"

int	command_cd_if(char **str, int count)
{
	char	*clear;

	if (count >= 0)
	{
		*str = ft_strjoin("/Users/", getenv("USER"));
		clear = *str;
		*str = ft_strjoin(*str, &g_var.shell[count].arg[1][1]);
		free(clear);
		return (0);
	}
	*str = ft_strjoin("/Users/", getenv("USER"));
	chdir(*str);
	free(*str);
	g_var.ret = 0;
	return (0);
}

void	ft_set_pwd(void)
{
	int		i;
	char	buf[4096];

	g_var.ret = 0;
	i = find_var("PWD", 2);
	if (i == -1)
		return ;
	if (getcwd(buf, 4096) == NULL)
		printf("minishell: getcwd: %s\n", strerror(errno));
	else
	{
		free(g_var.vars[i]);
		g_var.vars[i] = ft_strjoin("PWD=", buf);
	}
}

int	command_cd(int count)
{
	char	*str;

	if (g_var.shell[count].len_arg == 1)
		return (command_cd_if(&str, -1));
	if (g_var.shell[count].arg[1][0] == '~')
		command_cd_if(&str, count);
	else
		str = ft_strdup(g_var.shell[count].arg[1]);
	if (chdir(str) == -1)
	{
		g_var.ret = 1;
		printf("minishell: cd: %s: %s\n", g_var.shell[count].arg[1],
			strerror(errno));
	}
	else
		ft_set_pwd();
	free(str);
	return (0);
}

int	command_open(int count)
{
	char	*shlvl;
	char	*str;
	int		level;

	if (find_var("SHLVL", 2) != -1)
	{
		shlvl = find_var_result("SHLVL");
		level = ft_atoi(shlvl) + 1;
		str = ft_itoa(level);
		g_var.vars[find_var("SHLVL", 2)] = ft_strjoin("SHLVL=", str);
		free(str);
	}
	execve(g_var.shell[count].arg[0], g_var.shell[count].arg, g_var.vars);
	printf("minishell: %s: %s\n", g_var.shell[count].arg[0],
		strerror(errno));
	exit(-1);
}
