#include "ft_printf.h"

int	ft_putwidth(int width, int flag)
{
	char	c;
	int		result;

	result = 0;
	if (flag == 1)
		c = '0';
	else
		c = ' ';
	while (width > 0)
	{
		result += ft_putchar(c);
		width--;
	}
	return (result);
}
