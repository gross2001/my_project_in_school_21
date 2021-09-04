#include "minishell.h"

int	command_env(void)
{
	g_var.ret = 0;
	return (show_var(g_var.vars, 0));
}

int	command_unset(int count)
{
	int		count1;
	char	*str;

	count1 = 1;
	while (count1 < g_var.shell[count].len_arg)
		del_var(g_var.shell[count].arg[count1++]);
	count1 = 1;
	while (count1 < g_var.shell[count].len_arg)
	{
		str = ft_strjoin("declare -x ", g_var.shell[count].arg[count1]);
		del_all(str);
		free(str);
		count1++;
	}
	g_var.ret = 0;
	return (0);
}

int	check_name_var(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '_')
		return (0);
	else
	{
		g_var.ret = 1;
		printf("minishell: export: not a valid identifier\n");
		return (1);
	}
}

void	delite_vars(char *s)
{
	char	*str;
	char	*ch;

	ch = ft_strchr(s, '=');
	if (ch != NULL)
		delite_vars_dop(ch, s);
	if ((find_var(s, 0) != -1) && (count_char(s, '=') == 0))
		return ;
	ch = ft_strchr(s, '=');
	if (ch != NULL)
		*ch = 0;
	str = ft_strdup(s);
	if (ch != NULL)
		*ch = '=';
	ch = str;
	str = ft_strjoin("declare -x ", str);
	free(ch);
	if (find_var(str, 1) != -1)
		del_all(str);
	free(str);
}

int	command_export(int i)
{
	int		count;
	char	*str;

	count = 1;
	g_var.ret = 0;
	if (g_var.shell[i].len_arg == 1)
		return (show_var(g_var.all_vars, 1));
	while (count < g_var.shell[i].len_arg)
	{	
		str = g_var.shell[i].arg[count];
		if (!check_name_var(str[0]))
		{
			delite_vars(str);
			if (count_char(str, '=') > 0)
				add_var(str);
			add_all(str);
		}
		count++;
	}
	return (0);
}
