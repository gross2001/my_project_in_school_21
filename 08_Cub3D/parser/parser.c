/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:53:19 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 14:26:49 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

static char	**maplines_malloc(t_all *a, char **maplines, int i)
{
	maplines = malloc((i + 1) * sizeof(char *));
	if (!maplines)
	{
		ft_error("Error\nMalloc error. maplines", a);
	}
	return (maplines);
}

static char	**config_parser(t_all *a, char **lines)
{
	int	i;
	int	j;

	i = -1;
	while (lines[++i])
	{
		j = 0;
		while (lines[i][j] == ' ' || lines[i][j] == '\t')
		{
			j++;
		}
		if (!config_checker(a, lines[i]))
		{
			return (&lines[i]);
		}
	}
	ft_error("Error\nInvalid or empty map in config file\n", a);
	return (lines);
}

char	**get_maplines(char **maplines, int fd, t_all *a, int i)
{
	int		gnl_ret;

	gnl_ret = 1;
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &a->str);
		if (gnl_ret < 0)
			ft_error("Error\nCan't read config file\n", a);
		a->tmp = maplines;
		a->j = 0;
		maplines = maplines_malloc(a, maplines, i);
		if (a->tmp)
		{
			while (a->tmp[a->j])
			{
				maplines[a->j] = a->tmp[a->j];
				a->j++;
			}
		}
		free(a->tmp);
		maplines[a->j++] = a->str;
		maplines[a->j] = (NULL);
		i++;
	}
	return (maplines);
}

void	parse_cub(t_all *a, char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nConfig file does not exist\n", a);
	if (ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4))
		ft_error("Error\nInvalid map file type\n", a);
	a->maplines = NULL;
	a->maplines = get_maplines(a->maplines, fd, a, 1);
	close(fd);
	init_config(a);
	init_screen_size(a);
	create_and_check_map(a, config_parser(a, a->maplines));
}
