#include "minishell.h"

int	check_syn(void)
{
	int	count;

	count = 0;
	while (g_var.str[count + 2])
	{
		if ((g_var.str[count] == '>' || g_var.str[count] == '<') \
			&& (g_var.str[count + 1] == '>' || g_var.str[count + 1] == '<') \
			&& (g_var.str[count + 2] == '>' || g_var.str[count + 2] == '<'))
		{
			g_var.ret = 258;
			return (printf("parse error near `<>'\n"));
		}
		if ((g_var.str[count] == '>' && g_var.str[count + 1] == '<') || \
			(g_var.str[count] == '<' && g_var.str[count + 1] == '>'))
		{
			g_var.ret = 258;
			return (printf("parse error near `<>'\n"));
		}
		count++;
	}
	return (0);
}

int	count_shell(void)
{
	int		count;
	int		result;
	char	c;

	count = (result = 0);
	while (g_var.str[count])
	{
		if (g_var.str[count] == 39 || g_var.str[count] == 34)
		{
			c = g_var.str[count++];
			while (g_var.str[count] != c && g_var.str[count])
				count++;
		}
		if (g_var.str[count] == '|')
		{
			count++;
			while (g_var.str[count] == ' ' && g_var.str[count])
				count++;
			if (g_var.str[count] == 0)
				break ;
			result++;
		}
		count++;
	}
	return (result + 1);
}

int	check_parse_error(void)
{
	int	count;

	count = 0;
	while (g_var.str[count + 1])
	{
		if (g_var.str[count] == '|' && g_var.str[count + 1] == '|')
			g_var.ret = 258;
		if (g_var.str[count] == '|')
		{
			count++;
			while (g_var.str[count] == ' ' && g_var.str[count])
				count++;
			if (g_var.str[count] == '|')
				g_var.ret = 258;
		}
		count++;
	}
	return (0);
}

void	freendom(void)
{
	int	count1;
	int	count2;

	count2 = 0;
	while (count2 < g_var.len_shell)
	{
		count1 = 0;
		while (count1 < g_var.shell[count2].len_arg)
		{
			free(g_var.shell[count2].arg[count1]);
			count1++;
		}
		free(g_var.shell[count2].arg);
		count2++;
	}
	free(g_var.shell);
}

void	parsing(void)
{
	int	count;

	count = 0;
	if (check_parse_error() || check_syn())
	{
		freendom();
		return ;
	}
	ft_add_space_for_redirect(&g_var.str);
	if (!(ft_strlen(g_var.str) - count_char(g_var.str, ' ')))
		return ;
	g_var.shell = malloc(sizeof(t_shell) * (g_var.len_shell = count_shell()));
	while (count < g_var.len_shell)
		parsing_main(count++);
	if (ft_error_redirect() == -1)
	{
		freendom();
		return ;
	}
	ft_open_pipe();
	freendom();
}
