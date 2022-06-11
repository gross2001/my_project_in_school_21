/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_bckgr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:11:39 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:11:40 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

int	ft_create_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	ft_create_background(t_list *base, t_all *a)
{
	int				i;
	int				max_i;
	unsigned int	color;
	char			*dst;

	(void )a;
	i = 0;
	max_i = base->scr_resol_x * base->scr_resol_y / 2;
	color = ft_create_trgb(256, a->c_clr[0], a->c_clr[1], a->c_clr[2]);
	dst = base->push.addr;
	while (i++ < max_i)
	{
		*(unsigned int *)dst = color;
		dst = dst + 4;
	}
	color = ft_create_trgb(256, a->f_clr[0], a->f_clr[1], a->f_clr[2]);
	max_i *= 2;
	while (i++ < max_i)
	{
		*(unsigned int *)dst = color;
		dst = dst + 4;
	}
	return (0);
}
