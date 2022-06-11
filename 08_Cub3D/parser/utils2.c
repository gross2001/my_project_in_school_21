/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:55:15 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:56:28 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

void	check_cropped_map_line(char *str, t_all *a)
{
	if (str != NULL)
	{
		while (*str)
		{
			if ((ft_isdigit(*str) && (*str == '1' || *str == '0'))
				|| *str == 'S' || *str == 'W' || *str == 'E' || *str == 'N'
				|| *str == ' ')
				str++;
			else
				ft_error("Error\nInvalid symbols on map\n", a);
		}
	}
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}
