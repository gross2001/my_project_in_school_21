/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:12:06 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:19:05 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

int	ft_close(t_list *base)
{
	mlx_destroy_window(base->mlx, base->window);
	ft_lstfree(&(base->map));
	exit (EXIT_SUCCESS);
}

int	ft_check_arrow(int keycode, t_list *base)
{
	if (keycode == K_RIGHT_ARROW)
	{
		base->new_pos.angle_pos -= 0.1;
		if (base->new_pos.angle_pos < 0)
			base->new_pos.angle_pos += base->Pi_mul_2;
		base->new_pos.dx_pos = 1 * cos(base->new_pos.angle_pos);
		base->new_pos.dy_pos = 1 * sin(base->new_pos.angle_pos);
	}
	if (keycode == K_LEFT_ARROW)
	{
		base->new_pos.angle_pos += 0.1;
		if (base->new_pos.angle_pos > base->Pi_mul_2)
			base->new_pos.angle_pos -= base->Pi_mul_2;
		base->new_pos.dx_pos = 1 * cos(base->new_pos.angle_pos);
		base->new_pos.dy_pos = 1 * sin(base->new_pos.angle_pos);
	}
	return (1);
}

int	ft_check_key(int keycode, t_list *base)
{
	ft_check_arrow(keycode, base);
	if (keycode == K_LEFT)
	{
		base->new_pos.x_pos -= base->new_pos.dy_pos;
		base->new_pos.y_pos -= base->new_pos.dx_pos;
	}
	if (keycode == K_RIGHT)
	{
		base->new_pos.x_pos += base->new_pos.dy_pos;
		base->new_pos.y_pos += base->new_pos.dx_pos;
	}
	if (keycode == K_DOWN)
	{
		base->new_pos.x_pos -= base->new_pos.dx_pos;
		base->new_pos.y_pos += base->new_pos.dy_pos;
	}
	if (keycode == K_UP)
	{
		base->new_pos.x_pos += base->new_pos.dx_pos;
		base->new_pos.y_pos -= base->new_pos.dy_pos;
	}
	return (0);
}

int	key_hook(int keycode, t_list *base)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(base->mlx, base->window);
		ft_lstfree(&(base->map));
		exit (1);
	}
	if (keycode != K_DOWN && keycode != K_UP && keycode != K_LEFT
		&& keycode != K_RIGHT && keycode != K_LEFT_ARROW
		&& keycode != K_RIGHT_ARROW)
		return (0);
	ft_copy_position(base);
	ft_check_key(keycode, base);
	if (ft_check_around(base) == -1)
		ft_return_position(base);
	ft_built_view(base, base->a);
	return (0);
}
