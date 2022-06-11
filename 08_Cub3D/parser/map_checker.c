/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:52:47 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:53:07 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

static void	config_is_ok(t_all *a)
{
	if (!(a->f_ok))
		ft_error("Error\nFloor color in config file\n", a);
	if (!(a->c_ok))
		ft_error("Error\nCeil color in config file\n", a);
	if (!a->tx_ok[0] || !a->tx_ok[1] || !a->tx_ok[2])
		ft_error("Error\nWrong textures/sprites path in config file\n", a);
}

static int	calc_map_height(char **maplines, t_all *a)
{
	int	i;
	int	count;
	int	empty;

	i = -1;
	count = 0;
	empty = 0;
	while (maplines[++i])
	{
		if (ft_strlen(maplines[i]) > 0)
			count++;
		else
			empty++;
	}
	if (empty >= 2)
		ft_error("Error\nMany empty lines in map\n", a);
	return (count);
}

static int	calc_map_width(char **maplines)
{
	int	i;
	int	j;
	int	len;
	int	max_len;

	i = 0;
	j = 0;
	max_len = 0;
	while (maplines[i])
	{
		len = 0;
		j = -1;
		while (maplines[i][++j])
			len++;
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

void	create_and_check_map(t_all *a, char **cropped_map)
{
	config_is_ok(a);
	a->map.map_height = calc_map_height(cropped_map, a);
	a->map.map_width = calc_map_width(cropped_map);
	init_map(a, cropped_map, -1);
	check_player(a);
	check_map_horizontally(a);
	check_map_vertically(a);
}
