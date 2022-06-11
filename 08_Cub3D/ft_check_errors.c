/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:11:34 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:11:36 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_map_error(t_list *base)
{
	if (ft_find_size_map(base) != 0 || ft_check_map(base->map, base) != 0)
		ft_putstr("Error\n");
	else
		return (0);
	if (ft_check_map(base->map, base) == -1)
		ft_putstr("The incorrect symbol is at the map\n");
	if (ft_check_map(base->map, base) == -2)
		ft_putstr("The map isn't surrounded by walls\n");
	if (ft_check_map(base->map, base) == -3)
		ft_putstr("The incorrect number of a position\n");
	ft_lstfree(&(base->map));
	exit(EXIT_FAILURE);
}

int	ft_check_extension(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	if (string[i - 1] != 'b' || string[i - 2] != 'u' || string[i - 3] != 'c'
		|| string[i - 4] != '.')
	{
		ft_putstr("Incorrect extension\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}
