#include "minishell.h"

char	*ft_add_char_to_string(char ch_add, char *string, int i)
{
	char	*new_str;
	int		n;

	n = 0;
	if (i > ft_strlen(string))
		return (NULL);
	new_str = (char *) malloc(sizeof(char) * (2 + ft_strlen(string)));
	if (new_str == NULL)
		return (NULL);
	while (i > n)
	{
		new_str[n] = string[n];
		n++;
	}
	new_str[n] = ch_add;
	while (string[n])
	{
		new_str[n + 1] = string[n];
		n++;
	}
	new_str[n + 1] = 0;
	free(string);
	return (new_str);
}

int	ft_skip_quotes(char *str, int i)
{
	if (str[i] == 39)
	{
		i++;
		while (str[i] != 39)
			i++;
		i++;
	}
	if (str[i] == 34)
	{
		i++;
		while (str[i] != 34)
			i++;
		i++;
	}
	return (i);
}

char	*ft_add_space_for_redirect(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		i = ft_skip_quotes(*str, i);
		if ((*str)[i] == '>')
		{
			*str = ft_add_char_to_string(32, *str, i);
			i = i + 2;
			while ((*str)[i] == '>')
				i++;
			*str = ft_add_char_to_string(32, *str, i);
		}
		if ((*str)[i] == '<')
		{
			*str = ft_add_char_to_string(32, *str, i);
			i = i + 2;
			while ((*str)[i] == '<')
				i++;
			*str = ft_add_char_to_string(32, *str, i);
		}
		i++;
	}
	return (*str);
}

int	ft_error_redirect(void)
{
	int		i;
	int		n;

	i = (n = 0);
	while (i < g_var.len_shell)
	{
		while (g_var.shell[i].arg[n] != NULL)
		{
			if ((g_var.shell[i].arg[n][0] == '>'
				|| g_var.shell[i].arg[n][0] == '<')
			&& ((g_var.shell[i].arg[n + 1] == NULL)
			|| (g_var.shell[i].arg[n + 1][0] == '>')
			|| (g_var.shell[i].arg[n + 1][0] == '<')
			|| (g_var.shell[i].arg[n + 1][0] == '|')))
			{
				g_var.ret = 258;
				printf("minishell: syntax error\n");
				return (-1);
			}
			n++;
		}
		i++;
		n = 0;
	}
	return (0);
}
