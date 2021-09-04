#include "minishell.h"

int	ft_check_absolute_path(int count)
{
	char	*path;
	char	*home;
	int		i;

	if (g_var.shell[count].arg[0][0] == '~')
	{
		home = ft_strjoin("/home/", getenv("USER"));
		path = ft_strjoin(home, &g_var.shell[count].arg[0][1]);
		free(home);
		free(g_var.shell[count].arg[0]);
		g_var.shell[count].arg[0] = path;
	}
	i = 0;
	while (g_var.shell[count].arg[0][i])
	{
		if (g_var.shell[count].arg[0][i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_join_path(int count, char *split)
{
	struct stat		check_file;
	char			*add_slash;
	char			*path;

	add_slash = ft_strjoin(split, "/");
	path = ft_strjoin(add_slash, g_var.shell[count].arg[0]);
	if (stat(path, &check_file) == 0)
	{
		free(add_slash);
		free(g_var.shell[count].arg[0]);
		g_var.shell[count].arg[0] = path;
		return (1);
	}
	free(add_slash);
	free(path);
	return (0);
}

void	ft_correct_path(int count)
{
	char			*path;
	char			**split_path;
	int				i;

	if (ft_check_absolute_path(count) == 1)
		return ;
	if (find_var("PATH", 2) == -1)
		return ;
	i = 0;
	path = &g_var.vars[find_var("PATH", 2)][5];
	split_path = ft_split(path, ':');
	while (split_path[i] != NULL)
	{
		if (ft_check_join_path(count, split_path[i]) == 1)
			break ;
		else
			i++;
	}
	ft_free_malloc(split_path);
}
