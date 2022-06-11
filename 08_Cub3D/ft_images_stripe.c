/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_stripe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:11:14 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 15:38:34 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

void	ft_prepare_for_stripe(t_list *base)
{
	float	coordinate;

	if (base->ray.hor_or_ver == 0)
	{
		if ((base->new_pos.y_pos + base->ray.ry) <= 1 || base->ray.ry < 0)
			base->texture = &(base->north);
		else
			base->texture = &(base->south);
		coordinate = base->new_pos.x_pos + base->ray.rx;
		base->ray.first_pixel = base->texture->width
			* (coordinate - (int)coordinate);
	}
	if (base->ray.hor_or_ver == 1)
	{
		if ((base->new_pos.x_pos + base->ray.rx) <= 1 || base->ray.rx < 0)
			base->texture = &(base->west);
		else
			base->texture = &(base->east);
		coordinate = base->new_pos.y_pos + base->ray.ry;
		base->ray.first_pixel = base->texture->width
			* (coordinate - (int)coordinate);
	}
}

void	ft_resize_stripe(t_list *base, int x, int y)
{
	int		i;
	int		max_i;
	int		save_x;
	int		n;

	i = 0;
	save_x = x;
	n = (base->coef_stripe.height - base->scr_resol_y) / 2;
	max_i = base->coef_stripe.width * base->scr_resol_y;
	y = 0;
	while (i < max_i)
	{
		*(unsigned int*) &(base->push.addr[y * base->push.line_length + x * 4])
		= *(unsigned int*) &(base->coef_stripe.addr[i * 4
			+ n * base->coef_stripe.line_length]);
		i++;
		x++;
		if ((i * 4) % base->coef_stripe.line_length == 0)
		{
			y++;
			x = save_x;
		}
	}
}

void	add_to_background(t_list *base, int x, int y)
{
	int		i;
	int		max_i;
	int		save_x;

	i = 0;
	max_i = base->coef_stripe.width * base->coef_stripe.height;
	save_x = x;
	if (base->coef_stripe.height > base->scr_resol_y)
	{
		ft_resize_stripe(base, x, y);
		return ;
	}
	while (i < max_i)
	{
		*(unsigned int*) &(base->push.addr[y * base->push.line_length + x * 4])
			= *(unsigned int*) &(base->coef_stripe.addr[i * 4]);
		i++;
		x++;
		if ((i * 4) % base->coef_stripe.line_length == 0)
		{
			y++;
			x = save_x;
		}
	}
}

int	ft_take_stripe(t_list *base, int first_pixel, int pixel_per_stripe)
{
	int	i;
	int	max_i;
	int	n;
	int	pixel_count;

	pixel_count = (i = (n = 0));
	base->stripe.width = pixel_per_stripe;
	base->stripe.height = base->texture->height;
	max_i = base->texture->width * base->texture->height;
	while (i < max_i)
	{
		while (pixel_count < pixel_per_stripe)
		{
			if (i % base->texture->width == first_pixel + pixel_count)
			{
				*(unsigned int*)(&base->stripe.addr[n * 4])
					= *(unsigned int*)(&base->texture->addr[i * 4]);
				n++;
			}
			pixel_count++;
		}
		i++;
		pixel_count = 0;
	}
	return (0);
}

void	ft_add_stripe(t_list *base, float coef)
{
	int	i;
	int	n;
	int	max_i;

	i = (n = 0);
	max_i = base->stripe.width * base->stripe.height;
	base->coef_stripe.height = base->stripe.height * coef;
	if (base->coef_stripe.height > (base->scr_resol_y + 2 * coef))
	{
		i = (base->coef_stripe.height - base->scr_resol_y) / (2 * coef) - 1;
		max_i = base->stripe.width * (base->stripe.height - 2 * n);
		base->coef_stripe.height = (base->stripe.height - 2 * n) * coef;
	}
	while (i < max_i)
	{
		while ((float)n < (coef * (float)(i + 1)))
		{
			*(unsigned int *) &(base->coef_stripe.addr[n * 4])
				= *(unsigned int *) &(base->stripe.addr[i * 4]);
			n++;
		}
		i++;
	}
	add_to_background(base, base->cur_pix_to_push,
		(base->scr_resol_y - base->coef_stripe.height) / 2);
}
