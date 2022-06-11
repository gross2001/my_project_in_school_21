/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchelste <cchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:58:34 by cchelste          #+#    #+#             */
/*   Updated: 2021/10/24 14:58:35 by cchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>

size_t	ft_strlen(const char *s);
int		ft_strjoin(char **s1, char **s2, int line_size);
int		ft_strchr(const char *s);
int		ft_divide(char **temp, char **line);
int		ft_free(char	**pointer);
int		get_next_line(int fd, char **line);

#endif
