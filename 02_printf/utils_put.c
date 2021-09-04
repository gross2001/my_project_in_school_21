#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_ntimes(char c, int n)
{
	int	result;

	result = 0;
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
		result++;
	}
	return (result);
}

int	ft_putstr(char *s)
{
	int	 i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int n, unsigned int digit, char first_char)
{
	int				result;

	result = 0;
	if (n >= digit)
		result += ft_putnbr(n / digit, digit, first_char);
	if ((n % digit) < 10)
		result += ft_putchar(n % digit + '0');
	else
		result += ft_putchar(first_char + (n % digit - 10));
	return (result);
}

int	ft_putnbr_ll(unsigned long long c, int digit, char first_char)
{
	unsigned long long	digit_ll;
	int					result;

	result = 0;
	digit_ll = (unsigned long long) digit;
	if (c >= digit_ll)
		result += ft_putnbr_ll(c / digit_ll, digit, first_char);
	if ((c % digit_ll) < 10)
		result += ft_putchar(c % digit_ll + '0');
	else
		result += ft_putchar(first_char + (c % digit_ll - 10));
	return (result);
}
