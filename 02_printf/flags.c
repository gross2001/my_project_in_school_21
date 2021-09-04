#include "ft_printf.h"

int	ft_flag(const char *format, int *width, int precision)
{
	int	i;

	i = 1;
	if (*width < 0)
	{
		*width *= (-1);
		return (2);
	}
	if (format[i] == '-' || ((format[i] == '0') && (format[i + 1] == '-')))
		return (2);
	if (format[i] == '0'
		&& ((ft_conv_type(format) != 'd' || ft_conv_type(format) != 'i'
				|| ft_conv_type(format) != 'u' || ft_conv_type(format) != 'x'
				|| ft_conv_type(format) != 'X')
			&& ((ft_precision(format) < 0) && (precision < 0))))
		return (1);
	return (0);
}

int	ft_width(const char *format)
{
	int	i;
	int	n;

	i = 1;
	while ((format[i] == '-') || (format[i] == '0'))
		i++;
	if (format[i] == '*')
		return (-2);
	n = ft_atoi(&format[i]);
	return (n);
}

int	ft_precision(const char *format)
{
	int	i;
	int	n;

	i = 1;
	while ((format[i] == '-' || format[i] == '0'
			|| format[i] == '*')
		|| ((format[i] >= '0') && (format[i] <= '9')))
		i++;
	if (format[i] == '.')
	{
		if (format[i + 1] == '*')
			return (-2);
		n = ft_atoi(&format[i + 1]);
		if (n < 0)
			n = 0;
		return (n);
	}
	return (-1);
}

char	ft_conv_type(const char *format)
{
	int	i;

	i = 1;
	while ((format[i] == '-' || format[i] == '0'
			|| format[i] == '*' || format[i] == '.')
		|| ((format[i] >= '0') && (format[i] <= '9')))
		i++;
	return (format[i]);
}

int	ft_pass_flags(int i, const char *format)
{
	int	n;

	n = 1;
	while ((format[n] == '-' || format[n] == '0'
			|| format[n] == '*' ||format[n] == '.')
		|| ((format[n] >= '0') && (format[n] <= '9')))
		n++;
	return (i + n);
}
