/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:52:43 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:52:43 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

static int	check_left_wall(char *str, t_all *a)
{
	int	i;

	i = 0;
	while (*str && *str != '1')
	{
		if (*str == '0')
			ft_error("Error\nMap not closed\n", a);
		else if (*str == a->plr.dir)
			ft_error("Error\nPlayer behind the wall\n", a);
		str++;
		i++;
	}
	return (i);
}

static int	check_right_wall(char *s, int n, t_all *a)
{
	while (n != 0 && s[n] != '1')
	{
		if (s[n] == '0')
			ft_error("Error\nMap not closed\n", a);
		else if (s[n] == a->plr.dir)
			ft_error("Error\nPlayer behind the wall\n", a);
		n--;
	}
	return (n);
}

static void	check_h_middle_wall(char *str, int i, int end, t_all *a)
{
	int	dir;

	dir = a->plr.dir;
	while (i <= end)
	{
		if (str[i] == ' ' && (str[i + 1] == '0' || str[i - 1] == '0'))
			ft_error("Error\nMap not closed\n", a);
		else if (str[i] == ' ' && (str[i + 1] == dir || str[i - 1] == dir))
			ft_error("Error\nPlayer behind the wall\n", a);
		i++;
	}
}

void	check_map_horizontally(t_all *a)
{
	int		i;
	int		left;
	int		right;
	char	**map;

	i = -1;
	map = a->map.map;
	while (++i < a->map.map_height)
	{
		left = check_left_wall(map[i], a);
		right = check_right_wall(map[i], ft_strlen(map[i]), a);
		check_h_middle_wall(map[i], left, right, a);
	}
}
