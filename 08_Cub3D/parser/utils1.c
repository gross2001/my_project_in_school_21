/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:54:59 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:55:10 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

int	stop_cub(t_all *a)
{
	if (a->maplines)
		free_map(a->maplines);
	exit(1);
}

int	numlen(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	return (i);
}

void	rft_get_malloc(t_all *a)
{
	a->map.map = malloc((a->map.map_height + 1) * sizeof(char *));
	if (!(a->map.map))
		ft_error("Error\nMalloc error. a->map.map", a);
}

void	rft_get_malloc_i(t_all *a, int i)
{
	a->map.map[i] = malloc((a->map.map_width + 1) * sizeof(char));
	if (!(a->map.map[i]))
		ft_error("Error\nMalloc error. a->map.map[i]", a);
}

float	rft_init_angle_pos(t_list *base)
{
	if (base->a->plr.charak == 'N')
		return (33.0);
	else if (base->a->plr.charak == 'S')
		return (-33.0);
	else if (base->a->plr.charak == 'W')
		return (-3.1);
	else if (base->a->plr.charak == 'E')
		return (0);
	return (0);
}
