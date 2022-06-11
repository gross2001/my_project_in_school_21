/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:11:52 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:13:05 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

int	ft_built_view(t_list *base, t_all *a)
{
	base->cur_pix_to_push = 0;
	ft_create_background(base, a);
	ft_check_crossing(base);
	mlx_put_image_to_window(base->mlx, base->window, base->push.img, 0, 0);
	return (0);
}
