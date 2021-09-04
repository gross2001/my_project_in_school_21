#include  "ft_so_long.h"

char	ft_is_it_allowed(t_data *map, int x, int y)
{
	char	content;

	content = 0;
	while (map != NULL)
	{
		if ((map->x == x) && (map->y == y))
		{
			content = map->content;
			break ;
		}
		map = map->next;
	}
	return (content);
}

int	ft_change_content(t_data **map, int x, int y)
{
	t_data	*el;

	el = *map;
	while (el != NULL)
	{
		if ((el->x == x) && (el->y == y))
		{
			el->content = '0';
			break ;
		}
		el = el->next;
	}
	return (0);
}
