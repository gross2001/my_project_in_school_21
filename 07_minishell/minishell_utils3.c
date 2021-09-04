#include "minishell.h"

void	free_var(void)
{
	int	count;

	count = 0;
	while (g_var.vars[count])
		free(g_var.vars[count++]);
	count = 0;
	while (g_var.all_vars[count])
		free(g_var.all_vars[count++]);
	free(g_var.vars);
	free(g_var.all_vars);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		count;
	int		i;

	count = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[count])
	{
		result[count] = s1[count];
		count++;
	}
	i = 0;
	while (s2[i])
		result[count++] = s2[i++];
	result[count] = 0;
	return (result);
}

char	*ft_strchr(char *str, char c)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			return (&str[count]);
		count++;
	}
	return (NULL);
}
