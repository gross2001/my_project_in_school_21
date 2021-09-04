#include  "ft_so_long.h"

int	ft_close(t_list *base)
{
	mlx_destroy_window(base->mlx, base->window);
	ft_lstfree(&(base->map));
	exit (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_list *base)
{
	int	x;
	int	y;

	if (keycode == 53)
	{
		mlx_destroy_window(base->mlx, base->window);
		ft_lstfree(&(base->map));
		exit (1);
	}
	if (base->finish)
		return (0);
	if (keycode != 0 && keycode != 1 && keycode != 2 && keycode != 13)
		return (0);
	x = base->x_pos;
	y = base->y_pos;
	if (keycode == 0)
		x -= 1;
	if (keycode == 2)
		x += 1;
	if (keycode == 13)
		y -= 1;
	if (keycode == 1)
		y += 1;
	ft_do_move(base, x, y);
	return (0);
}

int	ft_display_move(t_list *base, int x, int y)
{
	char	*string;

	base->number_of_move++;
	string = NULL;
	mlx_put_image_to_window(base->mlx, base->window,
		base->space, 32 * base->x_pos, 32 * base->y_pos);
	mlx_put_image_to_window(base->mlx,
		base->window, base->position, 32 * x, 32 * y);
	string = ft_itoa(base->number_of_move);
	ft_putstr("Your current number of movements is ");
	ft_putstr(string);
	ft_putstr("\n");
	free (string);
	return (0);
}

int	ft_do_move(t_list *base, int x, int y)
{
	char	content;

	content = ft_is_it_allowed(base->map, x, y);
	if (content != '1' && content != 'E')
	{
		ft_display_move(base, x, y);
		base->x_pos = x;
		base->y_pos = y;
	}
	if (content == 'C')
	{
		ft_change_content(&(base->map), x, y);
		(base->i_get_collect)++;
	}
	if (content == 'E' && base->i_get_collect == base->collect_numb)
	{
		ft_display_move(base, x, y);
		mlx_put_image_to_window(base->mlx, base->window,
			base->map_exit, 32 * x, 32 * y);
		base->finish = 1;
	}
	return (0);
}

int	ft_load_images(t_list *base)
{
	int	a;
	int	b;

	base->wall = mlx_xpm_file_to_image(base->mlx,
			"images/cake.xpm", &a, &b);
	base->map_exit = mlx_xpm_file_to_image(base->mlx,
			"images/exit.xpm", &a, &b);
	base->space = mlx_xpm_file_to_image(base->mlx,
			"images/background.xpm", &a, &b);
	base->collect = mlx_xpm_file_to_image(base->mlx,
			"images/banana.xpm", &a, &b);
	base->position = mlx_xpm_file_to_image(base->mlx,
			"images/monster.xpm", &a, &b);
	if (base->wall == NULL || base->map_exit == NULL || base->space == NULL
		|| base->collect == NULL || base->position == NULL)
	{
		perror("Base of images");
		exit(EXIT_FAILURE);
	}
	return (1);
}
