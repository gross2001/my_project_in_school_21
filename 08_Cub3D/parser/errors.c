/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:52:17 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 11:52:18 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../ft_so_long.h"

void	ft_error(char *err, t_all *a)
{
	write(2, err, ft_strlen(err));
	stop_cub(a);
}

void	ft_warning(char *err)
{
	write(2, err, ft_strlen(err));
}
