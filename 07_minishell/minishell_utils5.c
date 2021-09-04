#include "minishell.h"

char	*ft_strdup(char *s)
{
	char	*str;
	int		count;

	count = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[count])
	{
		str[count] = s[count];
		count++;
	}
	str[count] = 0;
	return (str);
}

void	delite_vars_dop(char *ch, char *s)
{	
	char	*str;

	*ch = 0;
	str = ft_strdup(s);
	*ch = '=';
	if (find_var(str, 2) != -1)
		del_var(str);
	free(str);
}

int	show_var(char **vars, int flag)
{
	int		count;
	char	*str;
	char	c;

	count = (int)(c = 34) - 34;
	if (flag != 1)
	{
		while (vars[count])
			printf("%s\n", vars[count++]);
		return (0);
	}
	while (vars[count])
	{
		str = ft_strchr(vars[count], '=');
		if (str != NULL)
			*str = 0;
		printf("%s", vars[count++]);
		if (str != NULL)
		{
			printf("=%c%s%c", c, &str[1], c);
			*str = '=';
		}
		printf("\n");
	}
	return (0);
}

int	count_vars(char **vars)
{
	int	count;

	count = 0;
	while (vars[count])
		count++;
	return (count);
}

char	*find_var_result(char *str)
{
	int		check;
	char	*s;

	if (!ft_strcmp(str, "?"))
		return (ft_itoa(g_var.ret));
	check = find_var(str, 2);
	if (check == -1)
		return ("");
	s = ft_strchr(g_var.vars[find_var(str, 2)], '=');
	return (&s[1]);
}
