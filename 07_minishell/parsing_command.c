#include "minishell.h"

void	command_exit(int i)
{
	int	count;

	count = 0;
	free_var();
	if (g_var.shell[i].len_arg == 1)
	{
		freendom();
		exit(g_var.ret);
	}
	while (g_var.shell[i].arg[1][count])
	{
		if (g_var.shell[i].arg[1][count] < 48 \
			|| g_var.shell[i].arg[1][count] > 57)
		{
			printf("minishell: exit: %s: numeric argument required\n", \
				g_var.shell[i].arg[1]);
			freendom();
			exit(255);
		}
		count++;
	}
	count = ft_atoi(g_var.shell[i].arg[1]);
	freendom();
	exit(count);
}

int	command_pwd(void)
{
	char	*str;

	if (find_var("PWD", 2) != -1)
	{
		str = ft_strchr(g_var.vars[find_var("PWD", 2)], '=');
		printf("%s\n", &str[1]);
		return (0);
	}
	str = getcwd(NULL, 12000);
	printf("%s\n", str);
	free(str);
	return (0);
}

int	ft_check_builtin(void)
{
	if (!ft_strcmp("exit", g_var.shell[0].arg[0])
		|| (!ft_strcmp("pwd", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("cd", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("env", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("unset", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("export", g_var.shell[0].arg[0]))
		|| (!ft_strcmp("echo", g_var.shell[0].arg[0])))
		return (1);
	return (-1);
}

int	parsing_command(int count)
{
	if (!ft_strcmp("exit", g_var.shell[count].arg[0]))
		command_exit(count);
	if (!ft_strcmp("pwd", g_var.shell[count].arg[0]))
		return (command_pwd());
	if (!ft_strcmp("cd", g_var.shell[count].arg[0]))
		return (command_cd(count));
	if (!ft_strcmp("env", g_var.shell[count].arg[0]))
		return (command_env());
	if (!ft_strcmp("unset", g_var.shell[count].arg[0]))
		return (command_unset(count));
	if (!ft_strcmp("export", g_var.shell[count].arg[0]))
		return (!command_export(count));
	if (!ft_strcmp("echo", g_var.shell[count].arg[0]))
		return (!command_echo(count));
	return (-1);
}
