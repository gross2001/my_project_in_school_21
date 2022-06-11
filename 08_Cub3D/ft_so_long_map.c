/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:12:15 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:12:15 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

char	ft_check_content(t_list *base, float x, float y)
{
	char	content;
	t_data	*elem;

	content = 0;
	elem = base->map;
	if (x <= (float)1 || y <= (float)1 || x >= (float)(base->width - 1)
		|| y >= (float)(base->height - 1))
		return ('1');
	while (elem != NULL)
	{
		if ((elem->x == (int) x) && (elem->y == (int) y))
		{
			content = elem->content;
			break ;
		}
		elem = elem->next;
	}
	return (content);
}

int	ft_find_position(t_list *base)
{
	t_data	*map;

	map = base->map;
	while (map != NULL)
	{
		if (map->content == 'N' || map->content == 'S'
			|| map->content == 'W' || map->content == 'E')
		{
			base->new_pos.x_pos = map->x + 0.5;
			base->new_pos.y_pos = map->y + 0.5;
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

t_data	*ft_create_map(int fd, t_list *base, char **mape, t_all *a)
{
	t_data	*map;
	char	*line;
	int		x;
	int		y;

	(void)fd;
	(void)mape;
	(void)a;
	map = NULL;
	line = NULL;
	x = 0;
	y = 0;
	while (y < a->map.map_height)
	{
		x = 0;
		while (mape[y][x])
		{
			ft_lstadd_back(&map, ft_lstnew(x, y, mape[y][x]));
			x++;
		}
		y++;
	}
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
		if (lst->content != '1' && lst->content != '0' && lst->content != 'N'
			&& lst->content != 'S' && lst->content != 'E'
			&& lst->content != 'W')
			return (-1);
		if (((lst->x == 0) || (lst->y == 0) || (lst->x == base->width)
				|| (lst->y == base->height)) && lst->content != '1')
			return (-2);
		if ((lst->content != 'N' || lst->content != 'S'
				|| lst->content != 'E' || lst->content != 'W')
			&& base->is_map_checked == 1)
			(base->position_numb)++;
		lst = lst->next;
	}
	return (0);
}
