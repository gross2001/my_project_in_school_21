#include "minishell.h"

int	dop_if_final(char *str, int count)
{
	int	len;

	len = 0;
	while (str[count + len] && str[count + len] != \
		' ' && str[count + len] != '$')
		len++;
	return (len);
}

char	*change_str(char *var, char *str)
{
	char	*s;
	char	*result;
	char	*find_var;

	find_var = find_var_result(var);
	s = ft_strdup(find_var);
	result = ft_strjoin(str, s);
	free(s);
	if (!ft_strcmp(var, "?"))
		free (find_var);
	return (result);
}

void	parsing_final_if(int i, int next)
{
	int		count;
	char	*str;
	char	*var;
	char	*clear;
	int		len;

	count = (len = 0);
	str = ft_strdup(g_var.shell[i].arg[next]);
	while (str[count] != '$' && str[count])
		count++;
	str[count++] = 0;
	var = malloc(dop_if_final(str, count) + 1);
	while (str[count] && str[count] != ' ' && str[count] != '$' \
		&& str[count] != ':')
		var[len++] = str[count++];
	var[len] = 0;
	clear = str;
	str = change_str(var, str);
	free(clear);
	free(var);
	clear = str;
	str = ft_strjoin(str, &g_var.shell[i].arg[next][count]);
	free(clear);
	free(g_var.shell[i].arg[next]);
	g_var.shell[i].arg[next] = str;
}

int	parsing_final(int i)
{
	int		count;
	char	*clear;
	int		next;

	next = 0;
	while (next < g_var.shell[i].len_arg)
	{
		count = 0;
		while (g_var.shell[i].arg[next][count])
		{
			if ((g_var.shell[i].arg[next][0] == '1' \
				|| g_var.shell[i].arg[next][0] == '2')
				&& g_var.shell[i].arg[next][count] == '$' \
				&& g_var.shell[i].arg[next][count + 1] != ' ' \
				&& g_var.shell[i].arg[next][count + 1] != 0)
				parsing_final_if(i, next);
			count++;
		}
		clear = g_var.shell[i].arg[next];
		g_var.shell[i].arg[next] = ft_strdup(&g_var.shell[i].arg[next][1]);
		free(clear);
		next++;
	}
	return (0);
}
