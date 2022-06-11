/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:54:36 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:54:52 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

int	*rf_reg_ok(char c, t_all *a)
{
	if (c == 'f')
		return (&a->f_ok);
	else
		return (&a->c_ok);
}

int	ft_reg_ok1(int i, char *str, int *m_ok)
{
	if (*(str) != ',' && i < 2)
		return (-1);
	else
		return (*m_ok);
}

int	*rft_get_clr(char c, t_all *a)
{
	if (c == 'f')
		return (a->f_clr);
	else
		return (a->c_clr);
}

unsigned int	rft_get_color(char c, t_all *a)
{
	if (c == 'f')
		return (a->fcolor);
	else
		return (a->ccolor);
}
