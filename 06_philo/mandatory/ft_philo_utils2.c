#include "ft_philo.h"

void	ft_strjoin(t_fork *philo, int time, int fork, char *status)
{
	char	*bufer;
	int		count;
	int		i;
	char	*s1;

	count = philo->info->print_numb;
	s1 = philo->info->to_print;
	bufer = ft_itoa(time);
	i = 0;
	while (bufer[i])
		s1[count++] = bufer[i++];
	free(bufer);
	s1[count++] = 32;
	bufer = ft_itoa(fork);
	i = 0;
	while (bufer[i])
		s1[count++] = bufer[i++];
	free(bufer);
	s1[count++] = 32;
	i = 0;
	while (status[i])
		s1[count++] = status[i++];
	s1[count] = 0;
	philo->info->print_numb = count;
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
