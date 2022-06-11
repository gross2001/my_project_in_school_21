/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:52:20 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:52:21 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

void	init_screen_size(t_all *a)
{
	a->screen.w = 2560;
	a->screen.h = 1440;
}

void	init_config(t_all *a)
{
	a->resolution_ok = 0;
	a->f_clr[0] = -1;
	a->f_clr[1] = -1;
	a->f_clr[2] = -1;
	a->f_ok = 0;
	a->fcolor = 0;
	a->c_clr[0] = -1;
	a->c_clr[1] = -1;
	a->c_clr[2] = -1;
	a->c_ok = 0;
	a->ccolor = 0;
	a->tx_ok[0] = 0;
	a->tx_ok[1] = 0;
	a->tx_ok[2] = 0;
}

int	init_player(int x, int y, char side, t_all *a)
{
	if (side != 'N' && side != 'S' && side != 'E' && side != 'W')
		ft_error("Error\nInvalid item in map\n", a);
	if (a->plr.pos > 0)
		ft_error("Error\nMore 1 player in map\n", a);
	if (side == 'N' || side == 'S' || side == 'E' || side == 'W')
		player_direction(side, a, y, x);
	a->plr.forward = 0;
	a->plr.backward = 0;
	a->plr.left = 0;
	a->plr.right = 0;
	a->plr.rrotate = 0;
	a->plr.lrotate = 0;
	return (1);
}

void	init_map(t_all *a, char **s, int i)
{
	int	j;

	rft_get_malloc(a);
	while (++i <= a->map.map_height)
	{
		rft_get_malloc_i(a, i);
		j = -1;
		while (++j < a->map.map_width)
		{
			if (i == a->map.map_height)
				break ;
			if (s[i][j] == '\0')
			{
				j--;
				while (++j < a->map.map_width)
					a->map.map[i][j] = '-';
				break ;
			}
			else
				a->map.map[i][j] = s[i][j];
		}
		a->map.map[i][j] = '\0';
		check_cropped_map_line(s[i], a);
	}
}
