#include "ft_printf.h"

int	ft_conversion(va_list ap, const char *format)
{
	int	width;
	int	precision;
	int	result;

	result = 0;
	width = ft_width(format);
	precision = ft_precision(format);
	if (width == -2)
		width = va_arg(ap, int);
	if (precision == -2)
		precision = va_arg(ap, int);
	if (precision < 0)
		precision = -1;
	result = ft_add_arg(ap, format, width, precision);
	return (result);
}

int	ft_add_arg(va_list ap, const char *format, int width, int precision)
{
	int	result;

	if (ft_conv_type(format) == 's')
		result = ft_strprint(va_arg(ap, char *), format, width, precision);
	if (ft_conv_type(format) == 'd' || ft_conv_type(format) == 'i')
		result = ft_intprint(va_arg(ap, int), format, width, precision);
	if (ft_conv_type(format) == 'c')
		result = ft_charprint(va_arg(ap, int), format, width);
	if (ft_conv_type(format) == 'u' || ft_conv_type(format) == 'x'
		|| ft_conv_type(format) == 'X')
		result = ft_unint(va_arg(ap, unsigned), format, width, precision);
	if (ft_conv_type(format) == 'p')
		result = ft_adrpr(va_arg(ap, unsigned long long), format, width);
	if (ft_conv_type(format) == '%')
		result = ft_charprint('%', format, width);
	if (result == (-1))
		return (-1);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			result += ft_putchar(format[i]);
		else
		{
			result += ft_conversion(ap, &format[i]);
			i = ft_pass_flags(i, &format[i]);
		}
		i++;
	}
	va_end(ap);
	return (result);
}
