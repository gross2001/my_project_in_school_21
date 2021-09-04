#include "ft_printf.h"

int	ft_strprint(char *string, const char *format, int width, int precision)
{
	int	result;
	int	i;
	int	flag;

	result = 0;
	if (string == NULL)
	{
		result += ft_strprint("(null)", format, width, precision);
		return (result);
	}
	flag = ft_flag(format, &width, precision);
	i = 0;
	if (precision > (int) ft_strlen(string) || (precision == -1))
		precision = (int) ft_strlen(string);
	width -= precision;
	if (flag != 2)
		result += ft_putwidth(width, flag);
	while ((precision - (i++)) > 0)
		result += ft_putchar(string[i - 1]);
	if (flag == 2)
		result += ft_putwidth(width, flag);
	return (result);
}

int	ft_intprint(int number, const char *format, int width, int precision)
{
	int	result;
	int	flag;

	flag = ft_flag(format, &width, precision);
	result = 0;
	if (number >= 0)
		width -= ft_max(precision, ft_count_digit(number, 10));
	else
		width -= ft_max(precision + 1, ft_count_digit(number * (-1), 10) + 1);
	if ((number == 0) && (precision == 0))
		      width++;
	if (flag == 0)
		result += ft_putwidth(width, flag);
	if (number < 0)
		result += ft_putchar('-');
	if (number < 0)
		number = number * (-1);
	if (flag == 1)
		result += ft_putwidth(width, flag);
	result += ft_putchar_ntimes('0', precision - ft_count_digit(number, 10));
	if ((number != 0) || (precision != 0))
		result += ft_putnbr(number, 10, 'a');
	if (flag == 2)
		result += ft_putwidth(width, flag);
	return (result);
}

int	ft_charprint(int char_numb, const char *format, int width)
{
	unsigned char	c;
	int				result;
	int				flag;

	flag = ft_flag(format, &width, -1);
	result = 0;
	c = (unsigned char) char_numb;
	if ((flag != 2) && (width > 0))
		result += ft_putwidth(width - 1, flag);
	result += ft_putchar(c);
	if ((flag == 2) && (width > 0))
		result += ft_putwidth(width - 1, flag);
	return (result);
}

int	ft_unint(unsigned int n, const char *format, int width, int precision)
{
	char	first_char;
	int		digit;
	int		result;
	int		flag;

	flag = ft_flag(format, &width, precision);
	first_char = 'a';
	digit = 16;
	if (ft_conv_type(format) == 'u')
		digit = 10;
	if (ft_conv_type(format) == 'X')
		first_char = 'A';
	result = 0;
	width -= ft_max(precision, ft_count_digit(n, digit));
	if ((n == 0) && (precision == 0))
		width++;
	if (flag != 2)
		result += ft_putwidth(width, flag);
	result += ft_putchar_ntimes('0', precision - ft_count_digit(n, digit));
	if ((n != 0) || (precision != 0))
		result += ft_putnbr(n, digit, first_char);
	if (flag == 2)
		result += ft_putwidth(width, flag);
	return (result);
}

int	ft_adrpr(unsigned long long address, const char *format, int width)
{
	int	result;
	int	flag;

	flag = ft_flag(format, &width, -1);
	result = 0;
	if (address)
		width -= ft_count_digit_ll(address, 16) + 2;
	else
		width -= 3;
	if (flag != 2)
		result += ft_putwidth(width, flag);
	if (address)
	{
		result += ft_putstr("0x");
		result += ft_putnbr_ll(address, 16, 'a');
	}
	else
		result += ft_putstr("0x0");
	if (flag == 2)
		result += ft_putwidth(width, flag);
	return (result);
}
