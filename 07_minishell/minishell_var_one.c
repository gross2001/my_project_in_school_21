#include "minishell.h"

int	find_var(char *str, int flag)
{
	int		count;
	char	**vars;
	char	*ch;

	if (flag == 1)
		vars = g_var.all_vars;
	else
		vars = g_var.vars;
	count = 0;
	while (vars[count])
	{
		ch = ft_strchr(vars[count], '=');
		if (ch != NULL)
			*ch = 0;
		if (!ft_strcmp(vars[count], str))
		{	
			if (ch != NULL)
				*ch = '=';
			return (count);
		}
		if (ch != NULL)
			*ch = '=';
		count++;
	}
	return (-1);
}

void	del_all(char *str)
{
	int		point;
	int		count1;
	int		count2;
	char	**change;

	count1 = (count2 = 0);
	point = find_var(str, 1);
	if (point == -1)
		return ;
	change = malloc(sizeof(char *) * count_vars(g_var.all_vars));
	if (!change)
		exit(g_var.ret);
	while (g_var.all_vars[count2])
	{
		if (count2 != point)
		{
			change[count1] = g_var.all_vars[count2];
			count1++;
		}
		count2++;
	}
	change[count1] = NULL;
	free(g_var.all_vars[point]);
	free(g_var.all_vars);
	g_var.all_vars = change;
}

void	del_var(char *str)
{
	int		point;
	int		count1;
	int		count2;
	char	**change;

	count1 = (count2 = 0);
	point = find_var(str, 2);
	if (point == -1)
		return ;
	change = malloc(sizeof(char *) * count_vars(g_var.vars));
	if (!change)
		exit(g_var.ret);
	while (g_var.vars[count2])
	{
		if (count2 != point)
		{
			change[count1] = g_var.vars[count2];
			count1++;
		}
		count2++;
	}
	change[count1] = NULL;
	free(g_var.vars[point]);
	free(g_var.vars);
	g_var.vars = change;
}

void	add_var(char *str)
{
	int		count;
	char	**change;

	change = malloc(sizeof(char *) * (count_vars(g_var.vars) + 2));
	if (!change)
		exit(g_var.ret);
	count = 0;
	while (g_var.vars[count] != NULL)
	{
		change[count] = g_var.vars[count];
		count++;
	}
	change[count] = ft_strdup(str);
	count++;
	change[count] = NULL;
	free(g_var.vars);
	g_var.vars = change;
}

void	add_all(char *str)
{
	int		count;
	char	**change;

	if ((find_var(str, 0) != -1) && (count_char(str, '=') == 0))
		return ;
	change = malloc(sizeof(char *) * (count_vars(g_var.all_vars) + 2));
	if (!change)
		exit(g_var.ret);
	count = 0;
	while (g_var.all_vars[count] != NULL)
	{
		change[count] = g_var.all_vars[count];
		count++;
	}
	change[count] = ft_strjoin("declare -x ", str);
	change[++count] = NULL;
	free(g_var.all_vars);
	g_var.all_vars = change;
}
