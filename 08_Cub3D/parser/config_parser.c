/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:52:09 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:52:12 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

static void	check_txt(int i, t_all *a)
{
	if (i >= 0 && i <= 3)
	{
		if (a->tx_ok[i])
			ft_error("Error\nSome texture line is duplicated\n", a);
		else
			a->tx_ok[i] = 1;
	}
}

static void	get_txt(t_all *a, char *str, int i)
{
	int	fd;

	while (*str == ' ' || *str == '\t')
		str++;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nInvalid texture path\n", a);
	close(fd);
	if (ft_strncmp(str + ft_strlen(str) - 4, ".xpm", 4))
		ft_error("Error\nInvalid texture file extension\n", a);
	if (i >= 0 && i <= 3)
		a->tx[i].path = str;
	check_txt(i, a);
}

void	rft_add_clr_c(t_all *a, char *str)
{
	a->fcolor = get_color(&str[1], a, 'c');
	a->c_clr_0 = a->c_clr[0];
	a->c_clr_1 = a->c_clr[1];
	a->c_clr_2 = a->c_clr[2];
}

void	rft_add_clr_f(t_all *a, char *str)
{
	a->ccolor = get_color(&str[1], a, 'f');
	a->f_clr_0 = a->f_clr[0];
	a->f_clr_1 = a->f_clr[1];
	a->f_clr_2 = a->f_clr[2];
}

int	config_checker(t_all *a, char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		get_txt(a, &str[2], 0);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		get_txt(a, &str[2], 1);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		get_txt(a, &str[2], 2);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		get_txt(a, &str[2], 3);
	else if (str[0] == 'F' && str[1] == ' ')
		rft_add_clr_c(a, str);
	else if (str[0] == 'C' && str[1] == ' ')
		rft_add_clr_f(a, str);
	else if (str[0] == '0' || str[0] == '1')
		return (0);
	else if (str[0])
		ft_error("Error\nSome error in config file\n", a);
	return (1);
}
