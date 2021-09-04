#include "ft_printf.h"

int	ft_max(int a, int b)
{
	int	c;

	if (a >= b)
		c = a;
	if (a < b)
		c = b;
	return (c);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (size);
	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	result;

	result = 0;
	minus = 1;
	while (*str && ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r')))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		result = *str + 10 * result - '0';
		str++;
	}
	return (result * minus);
}

int	ft_count_digit(unsigned int number, unsigned int digit)
{
	int	count;

	count = 1;
	while (number > (digit - 1))
	{
		number = number / digit;
		count++;
	}
	return (count);
}

int	ft_count_digit_ll(unsigned long long number, int digit)
{
	int	count;

	count = 1;
	while (number > (unsigned long long)(digit - 1))
	{
		number = number / (unsigned long long) digit;
		count++;
	}
	return (count);
}
