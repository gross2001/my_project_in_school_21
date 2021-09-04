#include "minishell.h"

int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*my_join(char *s, char c)
{
	char	*str;
	int		count;

	str = malloc(sizeof(char) * ft_strlen(s) + 2);
	count = 0;
	while (s[count])
	{
		str[count] = s[count];
		count++;
	}
	str[count++] = c;
	str[count] = 0;
	free(s);
	return (str);
}

char	*new_line(void)
{
	char	*str;

	str = malloc(1);
	str[0] = 0;
	return (str);
}

int	count_char(char *str, char c)
{
	int	count;
	int	result;

	result = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			result++;
		count++;
	}
	return (result);
}
