/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacques <njacques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:12:19 by njacques          #+#    #+#             */
/*   Updated: 2021/10/24 14:12:20 by njacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_so_long.h"

void	ft_putchar(char c)
{
	int	a;

	a = write(1, &c, 1);
	a++;
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_len(n);
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0 && n != -2147483648)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
