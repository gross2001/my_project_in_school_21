#include "minishell.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	int		i;
	size_t	size;

	i = 0;
	if (!src)
		return (0);
	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	while ((dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (size);
}

char	**ft_free_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_numb_sep(char *s, char c)
{
	int	i;
	int	numb_sep;

	if (s[0] == '\0')
		return (0);
	i = 0;
	numb_sep = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			numb_sep++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		numb_sep++;
	return (numb_sep);
}

static void	ft_get_str(char **next_str, int *next_str_len, char c)
{
	int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	char	*next_str;
	int		next_str_len;
	int		i;

	 if (!s)
		 return (NULL);
	tab = (char **) malloc(sizeof(char *) * (ft_numb_sep(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < ft_numb_sep(s, c))
	{
		ft_get_str(&next_str, &next_str_len, c);
		tab[i] = (char *) malloc(sizeof(char) * (next_str_len + 1));
		if (tab[i] == NULL)
			return (ft_free_malloc(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
