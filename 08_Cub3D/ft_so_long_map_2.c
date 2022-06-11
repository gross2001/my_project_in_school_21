/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_map_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:12:10 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:12:11 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

void	ft_copy_position(t_list *base)
{
	base->old_pos.x_pos = base->new_pos.x_pos;
	base->old_pos.y_pos = base->new_pos.y_pos;
	base->old_pos.angle_pos = base->new_pos.angle_pos;
	base->old_pos.dx_pos = base->new_pos.dx_pos;
	base->old_pos.dy_pos = base->new_pos.dy_pos;
}

void	ft_return_position(t_list *base)
{
	base->new_pos.x_pos = base->old_pos.x_pos;
	base->new_pos.y_pos = base->old_pos.y_pos;
	base->new_pos.angle_pos = base->old_pos.angle_pos;
	base->new_pos.dx_pos = base->old_pos.dx_pos;
	base->new_pos.dy_pos = base->old_pos.dy_pos;
}

int	ft_check_around(t_list *base)
{
	float	x;
	float	y;

	x = base->new_pos.x_pos;
	y = base->new_pos.y_pos;
	if (ft_check_content(base, x, y) == '1'
		|| ft_check_content(base, x, y) == '-'
		|| ft_check_content(base, x, y) == ' '
		|| ft_check_content(base, x + 0.3, y) == '1'
		|| ft_check_content(base, x + 0.3, y) == '-'
		|| ft_check_content(base, x + 0.3, y) == ' '
		|| ft_check_content(base, x - 0.3, y) == '1'
		|| ft_check_content(base, x - 0.3, y) == '-'
		|| ft_check_content(base, x - 0.3, y) == ' '
		|| ft_check_content(base, x, y + 0.3) == '1'
		|| ft_check_content(base, x, y + 0.3) == '-'
		|| ft_check_content(base, x, y + 0.3) == ' '
		|| ft_check_content(base, x, y - 0.3) == '1'
		|| ft_check_content(base, x, y - 0.3) == '-'
		|| ft_check_content(base, x, y - 0.3) == ' ')
		return (-1);
	return (1);
}
