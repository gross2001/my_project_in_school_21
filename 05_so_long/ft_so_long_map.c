#include  "ft_so_long.h"

int	ft_find_position(t_list *base)
{
	t_data	*map;

	map = base->map;
	while (map != NULL)
	{
		if (map->content == 'P')
		{
			base->x_pos = map->x;
			base->y_pos = map->y;
			break ;
		}
		map = map->next;
	}
	return (1);
}

int	ft_find_size_map(t_list *base)
{
	t_data	*map;
	int		i;
	int		max_x_in_row;

	i = 0;
	max_x_in_row = 0;
	map = base->map;
	while (map != NULL)
	{
		if (map->y == i)
			max_x_in_row++;
		if (map->y != i)
		{
			if (max_x_in_row != base->width)
				break ;
			i++;
			max_x_in_row = 1;
		}
		map = map->next;
	}
	if (map != NULL)
		return (-1);
	return (0);
}

t_data	*ft_create_map(int fd, t_list *base)
{
	t_data	*map;
	char	*line;
	int		x;
	int		y;

	map = NULL;
	line = NULL;
	x = 0;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		while (line[x])
		{
			ft_lstadd_back(&map, ft_lstnew(x, y, line[x]));
			x++;
		}
		y++;
		free (line);
		line = NULL;
	}
	free (line);
	base->width = x;
	base->height = y;
	return (map);
}

int	ft_check_map(t_data *lst, t_list *base)
{
	if (base->is_map_checked == 0)
		(base->is_map_checked)++;
	while (lst != NULL)
	{
		if (lst->content != '1' && lst->content != '0' && lst->content != 'C'
			&& lst->content != 'E' && lst->content != 'P')
			return (-1);
		if (((lst->x == 0) || (lst->y == 0) || (lst->x == base->width)
				|| (lst->y == base->height)) && lst->content != '1')
			return (-2);
		if (lst->content == 'E' && base->is_map_checked == 1)
			(base->exit_numb)++;
		if (lst->content == 'C' && base->is_map_checked == 1)
			(base->collect_numb)++;
		if (lst->content == 'P' && base->is_map_checked == 1)
			(base->position_numb)++;
		lst = lst->next;
	}
	if (base->exit_numb == 0 || base->collect_numb == 0
		|| base->position_numb == 0)
		return (-3);
	return (0);
}

int	ft_images_to_map(t_data *lst, t_list *base)
{
	int	a;
	int	x;
	int	y;

	a = 32;
	while (lst != NULL)
	{
		x = a * lst->x;
		y = a * lst->y;
		if (lst->content == '1')
			mlx_put_image_to_window(base->mlx, base->window, base->wall, x, y);
		if (lst->content == '0')
			mlx_put_image_to_window(base->mlx, base->window, base->space, x, y);
		if (lst->content == 'C')
			mlx_put_image_to_window(base->mlx,
				base->window, base->collect, x, y);
		if (lst->content == 'E')
			mlx_put_image_to_window(base->mlx,
				base->window, base->map_exit, x, y);
		if (lst->content == 'P')
			mlx_put_image_to_window(base->mlx,
				base->window, base->position, x, y);
		lst = lst->next;
	}
	return (0);
}
