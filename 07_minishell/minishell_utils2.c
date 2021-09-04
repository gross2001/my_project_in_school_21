#include "minishell.h"

void	exit_but(void)
{
	if (!ft_strlen(g_var.str))
	{
		printf("\r                 ");
		printf("\rminishell: exit\n");
		free(g_var.str);
		free_var();
		exit(g_var.ret);
	}
	write(0, "  \b\b", 4);
}

int	miss_space(void)
{
	int	count;

	count = 0;
	while (g_var.str[count] == ' ')
		count++;
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (ft_strlen((char *) s1) != ft_strlen((char *) s2))
		return (1);
	while (s1[count])
	{
		if (s1[count] != s2[count])
			return (1);
		count++;
	}
	return (0);
}
