/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:52:24 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:52:37 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

static int	check_top_wall(int j, t_all *a)
{
	int		i;
	int		n;
	char	**map;

	n = 0;
	i = -1;
	map = a->map.map;
	while (map[++i][j] && map[i][j] != '1' && i < a->map.map_height)
	{
		if (map[i][j] == '0')
			ft_error("Error\nMap not closed\n", a);
		else if (map[i][j] == a->plr.dir)
			ft_error("Error\nPlayer behind the wall\n", a);
		n++;
	}
	return (n);
}

static int	check_bottom_wall(int j, int n, t_all *a)
{
	char	**map;

	map = a->map.map;
	while (n >= 0 && map[n][j] != '1')
	{
		if (map[n][j] == '0')
			ft_error("Error\nMap not closed\n", a);
		else if (map[n][j] == a->plr.dir)
			ft_error("Error\nPlayer behind the wall\n", a);
		n--;
	}
	return (n);
}

static void	check_v_middle_wall(int i, int end, int j, t_all *a)
{
	int		dir;
	char	**m;

	dir = a->plr.dir;
	m = a->map.map;
	while (i <= end)
	{
		if (m[i][j] == ' ' && (m[i + 1][j] == '0' || m[i - 1][j] == '0'))
			ft_error("Error\nMap not closed\n", a);
		else if (m[i][j] == ' ' && (m[i + 1][j] == dir || m[i - 1][j] == dir))
			ft_error("Error\nPlayer behind the wall\n", a);
		i++;
	}
}

void	check_map_vertically(t_all *a)
{
	int		j;
	int		top;
	int		bottom;

	j = -1;
	while (++j < a->map.map_width)
	{
		top = check_top_wall(j, a);
		bottom = check_bottom_wall(j, a->map.map_height, a);
		check_v_middle_wall(top, bottom, j, a);
	}
}
