/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:11:28 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 15:38:32 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

int	ft_cross_horizontal(t_list *base)
{
	while (ft_check_content(base, base->new_pos.x_pos + 1.0001 * base->ray.rx_h,
			base->new_pos.y_pos + 1.0001 * base->ray.ry_h) != '1')
	{
		base->ray.rx_h += base->ray.x0;
		base->ray.ry_h += base->ray.y0;
	}
	base->ray.rx = base->ray.rx_h;
	base->ray.ry = base->ray.ry_h;
	base->ray.distance = sqrtf(powf(base->ray.rx_h, 2)
			+ powf(base->ray.ry_h, 2));
	return (0);
}

int	ft_check_horizontal(t_list *base)
{
	if (base->ray.ra == 0 || base->ray.ra == base->Pi)
	{
		base->ray.distance = base->width * base->height;
		return (0);
	}
	if (base->ray.ra < base->Pi)
	{
		base->ray.ry_h = (int) base->new_pos.y_pos - base->new_pos.y_pos;
		base->ray.rx_h = (-1) * base->ray.ry_h / tan(base->ray.ra);
		base->ray.y0 = -1;
		base->ray.x0 = (-1) * base->ray.y0 / tan(base->ray.ra);
	}
	if (base->ray.ra > base->Pi)
	{
		base->ray.ry_h = (int)(base->new_pos.y_pos + 1) - base->new_pos.y_pos;
		base->ray.rx_h = (-1) * base->ray.ry_h / tan(base->ray.ra);
		base->ray.y0 = 1;
		base->ray.x0 = (-1) * base->ray.y0 / tan(base->ray.ra);
	}
	ft_cross_horizontal(base);
	return (0);
}

int	ft_cross_vertical(t_list *base)
{
	float	distance;

	while (ft_check_content(base, base->new_pos.x_pos + 1.0001 * base->ray.rx_v,
			base->new_pos.y_pos + 1.0001 * base->ray.ry_v) != '1')
	{
		base->ray.rx_v += base->ray.x0;
		base->ray.ry_v += base->ray.y0;
	}
	distance = sqrtf(powf(base->ray.rx_v, 2) + powf(base->ray.ry_v, 2));
	if (distance < base->ray.distance)
	{
		base->ray.rx = base->ray.rx_v;
		base->ray.ry = base->ray.ry_v;
		base->ray.distance = distance;
		base->ray.hor_or_ver = 1;
	}
	return (0);
}

int	ft_check_vertical(t_list *base)
{
	if (base->ray.ra == base->Pi_div_2 || base->ray.ra == base->Pi_mul_15
		|| (int)(base->ray.ra * (180 / base->Pi)) == 89
		|| (int)(base->ray.ra * (180 / base->Pi)) == 90)
		return (0);
	if (base->ray.ra < (base->Pi_div_2) || base->ray.ra > (base->Pi_mul_15))
	{
		base->ray.rx_v = (int)(base->new_pos.x_pos + 1) - base->new_pos.x_pos;
		base->ray.ry_v = (-1) * base->ray.rx_v * tan(base->ray.ra);
		base->ray.x0 = 1;
		base->ray.y0 = (-1) * base->ray.x0 * tan(base->ray.ra);
	}
	else if (base->ray.ra > (base->Pi_div_2)
		&& base->ray.ra < (base->Pi_mul_15))
	{
		base->ray.rx_v = (int)base->new_pos.x_pos - base->new_pos.x_pos;
		base->ray.ry_v = (-1) * base->ray.rx_v * tan(base->ray.ra);
		base->ray.x0 = -1;
		base->ray.y0 = (-1) * base->ray.x0 * tan(base->ray.ra);
	}
	ft_cross_vertical(base);
	return (0);
}

int	ft_check_crossing(t_list *base)
{
	int		r;
	float	coef;

	r = 0;
	base->ray.ra = base->new_pos.angle_pos + base->Pi / 6;
	while (r < (base->scr_resol_x / base->pixel_per_stripe))
	{
		base->ray.hor_or_ver = 0;
		ft_check_horizontal(base);
		ft_check_vertical(base);
		coef = 20 / (base->ray.distance
				* cos(base->new_pos.angle_pos - base->ray.ra));
		ft_prepare_for_stripe(base);
		ft_take_stripe(base, base->ray.first_pixel, base->pixel_per_stripe);
		base->coef_stripe.width = base->stripe.width;
		ft_add_stripe(base, coef);
		base->cur_pix_to_push += base->pixel_per_stripe;
		r++;
		base->ray.ra -= base->Pi_div_3600 * (base->pixel_per_stripe);
		if (base->ray.ra >= base->Pi_mul_2)
			base->ray.ra -= base->Pi_mul_2;
		if (base->ray.ra < 0)
			base->ray.ra += base->Pi_mul_2;
	}
	return (0);
}
