/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:13:27 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:13:28 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

int	ft_initialize_img(t_list *base)
{
	base->push.img = mlx_new_image(base->mlx,
			base->scr_resol_x, base->scr_resol_y);
	base->push.addr = mlx_get_data_addr(base->push.img,
			&base->push.bits_per_pixel, &base->push.line_length,
			&base->push.endian);
	base->stripe.img = mlx_new_image(base->mlx, base->pixel_per_stripe,
			base->scr_resol_y);
	base->stripe.addr = mlx_get_data_addr(base->stripe.img,
			&base->stripe.bits_per_pixel, &base->stripe.line_length,
			&base->stripe.endian);
	base->coef_stripe.img = mlx_new_image(base->mlx, base->pixel_per_stripe,
			7 * base->scr_resol_y);
	base->coef_stripe.addr = mlx_get_data_addr(base->coef_stripe.img,
			&base->coef_stripe.bits_per_pixel, &base->coef_stripe.line_length,
			&base->coef_stripe.endian);
	return (0);
}

int	ft_initialize_mlx(t_list *base)
{
	base->mlx = mlx_init();
	if (base->mlx == NULL)
	{
		perror("mlx_init");
		exit (EXIT_FAILURE);
	}
	base->window = mlx_new_window(base->mlx,
			1200, 650, "Cub3D");
	if (base->window == NULL)
	{
		perror("mlx_window");
		exit (EXIT_FAILURE);
	}
	ft_initialize_img(base);
	return (0);
}

int	ft_initialize_base(int argc, t_list *base)
{
	if (argc != 2)
	{
		ft_putstr("Incorrect number of arguments\n");
		exit (EXIT_FAILURE);
	}
	base->Pi = 3.14159;
	base->Pi_mul_15 = base->Pi * 1.5;
	base->Pi_mul_2 = base->Pi * 2;
	base->Pi_div_2 = base->Pi / 2;
	base->Pi_div_3600 = base->Pi / 3600;
	base->scr_resol_x = 1200;
	base->scr_resol_y = 650;
	base->pixel_per_stripe = 1;
	base->map = NULL;
	base->new_pos.angle_pos = rft_init_angle_pos(base);
	base->new_pos.dx_pos = 0;
	base->new_pos.dy_pos = 0;
	base->new_pos.dx_pos = 1 * cos(base->new_pos.angle_pos);
	base->new_pos.dy_pos = 1 * sin(base->new_pos.angle_pos);
	base->width = 0;
	base->height = 0;
	base->is_map_checked = 0;
	return (0);
}

static void	start_all(t_all *a, int argc, char **argv)
{
	(void)argc;
	parse_cub(a, argv[1]);
}

int	main(int argc, char *argv[])
{
	t_list	base;
	t_all	a;
	int		fd;

	fd = 0;
	start_all(&a, argc, argv);
	base.a = &a;
	ft_initialize_base(argc, &base);
	rft_init_angle_pos(&base);
	base.map = ft_create_map(fd, &base, a.map.map, &a);
	fd = ft_find_position(&base) + ft_initialize_mlx(&base);
	ft_load_images(&base, &a);
	ft_built_view(&base, &a);
	mlx_key_hook(base.window, key_hook, &base);
	mlx_hook(base.window, 17, 1L << 0, ft_close, &base);
	mlx_loop(base.mlx);
	return (0);
}
