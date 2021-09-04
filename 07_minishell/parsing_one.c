#include "minishell.h"

int	count_arg_if(int *count, int *result, int flag)
{
	char	c;

	if (flag == 1)
	{
		while (g_var.str[*count] != ' ' \
			&& g_var.str[*count] && g_var.str[*count] != '|')
			*count += 1;
		*result += 1;
		if (g_var.str[*count] == 0 || g_var.str[*count] == '|')
			return (2);
		return (0);
	}
	c = g_var.str[*count];
	*count += 1;
	while (g_var.str[*count] != c && g_var.str[*count])
		*count += 1;
	*result += 1;
	if (g_var.str[*count] == 0)
		return (2);
	else
		count[0]++;
	return (0);
}

int	count_arg(void)
{
	int	count;
	int	result;

	count = (result = 0);
	while (g_var.str[count] != '|' && g_var.str[count])
	{	
		if (g_var.str[count] != ' ' \
			&& g_var.str[count] != 34 && g_var.str[count] != 39)
		{
			if (count_arg_if(&count, &result, 1))
				break ;
		}
		if (g_var.str[count] == 34 || g_var.str[count] == 39)
		{	
			if (count_arg_if(&count, &result, 2))
				break ;
		}
		count++;
	}
	return (result);
}
