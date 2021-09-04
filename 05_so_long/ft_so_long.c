#include  "ft_so_long.h"

int	ft_initialize_mlx(t_list *base)
{
	base->mlx = mlx_init();
	if (base->mlx == NULL)
	{
		perror("mlx_init");
		exit (EXIT_FAILURE);
	}
	base->window = mlx_new_window(base->mlx,
			base->width * 32, base->height * 32, "so_long");
	if (base->window == NULL)
	{
		perror("mlx_window");
		exit (EXIT_FAILURE);
	}
	return (0);
}

int	ft_initialize_base(int argc, t_list *base)
{
	if (argc != 2)
	{
		ft_putstr("Incorrect number of arguments\n");
		exit (EXIT_FAILURE);
	}
	base->map = NULL;
	base->x_pos = 0;
	base->y_pos = 0;
	base->number_of_move = -0;
	base->width = 0;
	base->height = 0;
	base->exit_numb = 0;
	base->collect_numb = 0;
	base->position_numb = 0;
	base->i_get_collect = 0;
	base->finish = 0;
	base->is_map_checked = 0;
	return (0);
}

int	ft_map_error(t_list *base)
{
	if (ft_find_size_map(base) != 0 || ft_check_map(base->map, base) != 0)
		ft_putstr("Error\n");
	else
		return (0);
	if (ft_find_size_map(base) == -1)
		ft_putstr("The map isn't rectangular\n");
	if (ft_check_map(base->map, base) == -1)
		ft_putstr("The incorrect symbol is at the map\n");
	if (ft_check_map(base->map, base) == -2)
		ft_putstr("The map isn't surrounded by walls\n");
	if (ft_check_map(base->map, base) == -3)
		ft_putstr("The incorrect number of E, C or P\n");
	ft_lstfree(&(base->map));
	exit(EXIT_FAILURE);
}

int	ft_check_extension(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	if (string[i - 1] != 'r' || string[i - 2] != 'e' || string[i - 3] != 'b'
		|| string[i - 4] != '.')
	{
		ft_putstr("Incorrect extension\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	base;
	int		fd;

	ft_initialize_base(argc, &base);
	ft_check_extension(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Map");
		exit (EXIT_FAILURE);
	}
	base.map = ft_create_map(fd, &base);
	close(fd);
	ft_map_error(&base);
	fd = ft_find_position(&base) + ft_initialize_mlx(&base);
	fd = ft_load_images(&base) + ft_images_to_map(base.map, &base);
	mlx_key_hook(base.window, key_hook, &base);
	mlx_hook(base.window, 17, 1L << 0, ft_close, &base);
	mlx_loop(base.mlx);
	return (0);
}
