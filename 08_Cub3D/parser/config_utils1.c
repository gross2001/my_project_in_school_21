/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:51:35 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:51:37 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

static int	check_color_trash(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || ft_isdigit(*str) || *str == ',')
			str++;
		else
		{
			i++;
			break ;
		}
	}
	return (i);
}

static int	check_color_value(char *str, t_all *a)
{
	int	num;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32 || *str == '\t')
		str++;
	if (numlen(str) > 3)
		ft_error("Error\nWrong color value\n", a);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != ',')
			ft_error("Error\nWrong color value\n", a);
		if (ft_isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		else
			break ;
	}
	if (num < 0 || num > 255)
		ft_error("Error\nWrong color value\n", a);
	return (num);
}

static void	check_color_digits(char *str, t_all *a)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	i = -1;
	len = ft_strlen(str);
	if (check_color_trash(str) > 0)
		ft_error("Error\nInvalid color value\n", a);
	while (++i <= len)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_isdigit(str[i]))
			count++;
		while (ft_isdigit(str[i]))
			i++;
	}
	if (count != 3)
		ft_error("Error\nInvalid color value\n", a);
}

static void	check_color_virgule(char *str, t_all *a)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	if (i > 2)
		ft_error("Error\nInvalid color value\n", a);
}

unsigned int	get_color(char *str, t_all *a, char c)
{
	int				i;
	int				*m_ok;
	int				*m_rgb;
	unsigned int	m_color;

	i = -1;
	m_ok = rf_reg_ok(c, a);
	m_rgb = rft_get_clr(c, a);
	m_color = rft_get_color(c, a);
	if (*m_ok)
		ft_error("Error\nSome color line is duplicated\n", a);
	check_color_virgule(str, a);
	check_color_digits(str, a);
	while (++i < 3)
	{
		m_rgb[i] = check_color_value(str, a);
		while (ft_isdigit(*str) || *str == ' ' || *str == '\t')
			str++;
		*m_ok = ft_reg_ok1(i, str++, m_ok);
	}
	if (m_rgb[0] == -1 || m_rgb[1] == -1 || m_rgb[2] == -1 || *m_ok == -1)
		ft_error("Error\nInvalid color value\n", a);
	m_color = ((m_rgb[0] << 16) + (m_rgb[1] << 8) + m_rgb[2]);
	*m_ok = 1;
	return (m_color);
}
