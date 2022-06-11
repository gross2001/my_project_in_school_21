/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:11:43 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:11:44 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

int	ft_load_images_error(t_list *base)
{
	if (base->north.img == NULL || base->south.img == NULL
		|| base->east.img == NULL || base->west.img == NULL)
	{
		perror("Base of images");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	ft_load_images(t_list *base, t_all *a)
{
	base->north.img = mlx_xpm_file_to_image(base->mlx, a->tx[0].path,
			&base->north.width, &base->north.height);
	base->north.addr = mlx_get_data_addr(base->north.img,
			&base->north.bits_per_pixel, &base->north.line_length,
			&base->north.endian);
	base->south.img = mlx_xpm_file_to_image(base->mlx, a->tx[1].path,
			&base->south.width, &base->south.height);
	base->south.addr = mlx_get_data_addr(base->south.img,
			&base->south.bits_per_pixel, &base->south.line_length,
			&base->south.endian);
	base->east.img = mlx_xpm_file_to_image(base->mlx, a->tx[2].path,
			&base->east.width, &base->east.height);
	base->east.addr = mlx_get_data_addr(base->east.img,
			&base->east.bits_per_pixel, &base->east.line_length,
			&base->east.endian);
	base->west.img = mlx_xpm_file_to_image(base->mlx,
			a->tx[3].path, &base->west.width, &base->west.height);
	base->west.addr = mlx_get_data_addr(base->west.img,
			&base->west.bits_per_pixel, &base->west.line_length,
			&base->west.endian);
	ft_load_images_error(base);
	return (1);
}
