/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:54:06 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:54:30 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

void	player_direction(char side, t_all *a, int y, int x)
{
	if (side == 'N')
	{
		a->plr.dir_x = -1;
		a->plr.plane_y = 0.66;
	}
	else if (side == 'S')
	{
		a->plr.dir_x = 1;
		a->plr.plane_y = -0.66;
	}
	else if (side == 'E')
	{
		a->plr.dir_y = 1;
		a->plr.plane_x = 0.66;
	}
	else if (side == 'W')
	{
		a->plr.dir_y = -1;
		a->plr.plane_x = -0.66;
	}
	a->plr.pos_x = x + 0.5;
	a->plr.pos_y = y + 0.5;
	a->plr.dir = side;
	if (a->plr.dir == ' ')
		ft_error("Error\nNo player\n", a);
}

static int	player_search(char c, int y, int x, t_all *a)
{
	if (c == 'S' || c == 'W' || c == 'E' || c == 'N')
	{
		a->plr.charak = c;
		init_player(y, x, c, a);
		return (1);
	}
	return (0);
}

void	check_player(t_all *a)
{
	int	i;
	int	j;

	i = -1;
	a->plr.pos = 0;
	while (++i <= a->map.map_height)
	{
		j = -1;
		while (++j <= a->map.map_width)
			a->plr.pos += player_search(a->map.map[i][j], i, j, a);
	}
	if (a->plr.pos == 0)
		ft_error("Error:\nNo player\n", a);
}
