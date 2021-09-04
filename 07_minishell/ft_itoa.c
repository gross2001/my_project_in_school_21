#include "minishell.h"

int	checkMinusMemory(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

unsigned int	get_size(long n)
{
	unsigned int	size;

	size = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

void	ft_itoa_dop(int n, int i, char *str)
{
	while (n >= 10)
	{
		str[i--] = (char)(n % 10 + 48);
		n /= 10;
	}
	str[i] = (char)(n % 10 + 48);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + checkMinusMemory(n) + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		size++;
		n = n * (-1);
	}
	i = size - 1;
	ft_itoa_dop(n, i, str);
	str[size] = '\0';
	return (str);
}
