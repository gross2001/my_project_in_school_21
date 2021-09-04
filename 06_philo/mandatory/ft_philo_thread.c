#include "ft_philo.h"

void	*ft_routine(void *argc)
{
	t_fork	*philo;

	philo = (t_fork *) argc;
	gettimeofday(&(philo->timer), NULL);
	if (philo->next->fork % 2 == 1 && philo->info->number_of_philo != 1)
		ft_usleep(3);
	while (philo->info->death_flag == 0)
	{
		if (pthread_mutex_lock(&(philo->fork_mutex)) != 0)
		{
			philo->info->death_flag = 1;
			return (0);
		}
		ft_put_status(philo, "has taken a fork\n");
		if (philo->info->number_of_philo == 1)
		{
			pthread_mutex_unlock(&(philo->next->fork_mutex));
			break ;
		}
		ft_part_of_routine(philo);
	}
	return (0);
}

int	ft_part_of_routine(t_fork *philo)
{
	if (pthread_mutex_lock(&(philo->next->fork_mutex)) != 0)
	{
		philo->info->death_flag = 1;
		return (0);
	}
	ft_put_status(philo, "has taken a fork\n");
	if (ft_pthread_mutex_lock(&(philo->info->mutex_eat), philo->info) != 0)
		return (0);
	ft_put_status(philo, "is eating\n");
	gettimeofday(&(philo->timer), NULL);
	if (ft_pthread_mutex_unlock(&(philo->info->mutex_eat), philo->info) != 0)
		return (0);
	ft_usleep(philo->info->time_to_eat);
	(philo->number_of_eating)++;
	if (ft_pthread_mutex_unlock(&(philo->next->fork_mutex), philo->info) != 0
		|| ft_pthread_mutex_unlock(&(philo->fork_mutex), philo->info) != 0)
		return (0);
	ft_put_status(philo, "is sleeping\n");
	ft_usleep(philo->info->time_to_sleep);
	ft_put_status(philo, "is thinking\n");
	return (0);
}

int	ft_pthread_mutex_lock(pthread_mutex_t *mutex, t_common *info)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		info->death_flag = 1;
		return (-1);
	}
	return (0);
}

int	ft_pthread_mutex_unlock(pthread_mutex_t *mutex, t_common *info)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		info->death_flag = 1;
		return (-1);
	}
	return (0);
}

int	ft_put_status(t_fork *philo, char *status)
{
	struct timeval	current_time;
	long int		how_many_ms;

	gettimeofday(&current_time, NULL);
	how_many_ms = (current_time.tv_sec - philo->info->initial_time.tv_sec)
		* 1000;
	how_many_ms += (current_time.tv_usec - philo->info->initial_time.tv_usec)
		/ 1000;
	if (pthread_mutex_lock(&(philo->info->mutex)) != 0)
		return (-1);
	if (philo->info->death_flag == 0)
	{
		ft_strjoin(philo, (int) how_many_ms, philo->fork, status);
		if ((status[0] == 'd')
			|| (philo->info->print_numb > philo->info->limit_to_print))
		{
			printf("%s", philo->info->to_print);
			philo->info->to_print[0] = 0;
			philo->info->print_numb = 0;
		}
	}
	if (status[0] != 'd')
		if (pthread_mutex_unlock(&(philo->info->mutex)) != 0)
			return (-1);
	return (1);
}
