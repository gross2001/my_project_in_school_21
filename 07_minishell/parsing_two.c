#include "minishell.h"

int	parsing_main_if1(int i, int q, int *count)
{
	int	len;

	len = 0;
	while (g_var.str[*count + len] != ' ' \
		&& g_var.str[*count + len] && g_var.str[*count + len] != '|')
		len++;
	g_var.shell[i].arg[q] = malloc(sizeof(char) * len + 2);
	len = 1;
	g_var.shell[i].arg[q][0] = '2';
	while (g_var.str[*count] != ' ' && \
		g_var.str[*count] && g_var.str[*count] != '|')
		g_var.shell[i].arg[q][len++] = g_var.str[count[0]++];
	g_var.shell[i].arg[q][len] = 0;
	if (g_var.str[*count] == 0 || g_var.str[*count] == '|')
		return (1);
	return (0);
}

int	parsing_main_if2(int i, int q, int *count)
{
	char	c;
	int		len;

	len = 0;
	c = g_var.str[*count];
	count[0]++;
	while (g_var.str[*count + len] != c && g_var.str[*count + len])
		len++;
	g_var.shell[i].arg[q] = malloc(sizeof(char) * len + 2);
	len = 1;
	if (c == 34)
		g_var.shell[i].arg[q][0] = '1';
	else
		g_var.shell[i].arg[q][0] = '0';
	while (g_var.str[*count] != c && g_var.str[*count])
		g_var.shell[i].arg[q][len++] = g_var.str[count[0]++];
	g_var.shell[i].arg[q][len] = 0;
	if (g_var.str[*count] == 0)
		return (1);
	else
		count[0]++;
	return (0);
}

void	parsing_main(int i)
{
	int		count;
	char	*clear;
	int		q;

	count = (q = 0);
	g_var.shell[i].arg = malloc(sizeof(char *) \
		* (1 + (g_var.shell[i].len_arg = count_arg())));
	while (g_var.str[count] != '|' && g_var.str[count])
	{	
		if (g_var.str[count] != ' ' \
			&& g_var.str[count] != 34 && g_var.str[count] != 39)
			if (parsing_main_if1(i, q++, &count))
				break ;
		if (g_var.str[count] == 34 || g_var.str[count] == 39)
			if (parsing_main_if2(i, q++, &count))
				break ;
		count++;
	}
	clear = g_var.str;
	g_var.str = ft_strdup(&clear[++count]);
	parsing_final(i);
	free(clear);
	g_var.shell[i].arg[g_var.shell[i].len_arg] = NULL;
}
