#ifndef		 FT_PRINTF_H
# define	 FT_PRINTF_H

# include	<unistd.h>
# include	<stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_conversion(va_list ap, const char *format);
int		ft_add_arg(va_list ap, const char *format, int width, int argument);
int		ft_flag(const char *format, int *width, int precision);
int		ft_width(const char *format);
int		ft_precision(const char *format);
int		ft_pass_flags(int i, const char *format);
int		ft_strprint(char *string, const char *format, int width, int precision);
int		ft_intprint(int number, const char *format, int width, int precision);
int		ft_charprint(int char_numb, const char *format, int width);
int		ft_unint(unsigned int n, const char *format, int width, int precision);
int		ft_adrpr(unsigned long long address, const char *format, int width);
int		ft_putwidth(int width, int flag);
int		ft_putchar(char c);
int		ft_putchar_ntimes(char c, int n);
int		ft_putstr(char *s);
int		ft_putnbr(unsigned int n, unsigned int digit, char first_char);
int		ft_putnbr_ll(unsigned long long c, int digit, char first_char);
int		ft_max(int a, int b);
int		ft_atoi(const char *str);
int		ft_count_digit(unsigned int number, unsigned int digit);
int		ft_count_digit_ll(unsigned long long number, int digit);
size_t	ft_strlen(const char *s);
char	ft_conv_type(const char *format);

#endif
