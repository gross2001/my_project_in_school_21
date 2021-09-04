#include "ft_philo.h"

int	ft_lstdel(t_fork *philo)
{
	t_fork	*el;

	free((philo->info->to_print));
	if (philo->info->number_of_philo == 1)
	{
		free(philo);
		return (1);
	}
	while (philo->fork != philo->info->number_of_philo)
	{
		el = philo;
		philo = philo->next;
		free(el);
		el = NULL;
	}
	free(philo);
	return (1);
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
