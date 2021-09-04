#include "ft_philo.h"

int	ft_usleep(int time)
{
	int	count;

	count = 0;
	while (time > count)
	{
		usleep(50000);
		count += 50;
	}
	usleep(count - time);
	return (0);
}

int	ft_join_thread(t_fork *philo)
{
	t_fork	*el;
	int		numb;

	el = philo;
	numb = el->fork;
	while (el->next->fork != numb)
	{
		pthread_join(el->thread, NULL);
		el = el->next;
	}
	pthread_join(el->thread, NULL);
	return (0);
}

int	ft_check_thread(t_fork *philo, t_common info)
{
	t_fork	*el;

	el = philo;
	while (philo->info->death_flag == 0)
	{
		if (ft_check_live(el, el->timer, info.time_to_die) == 0
			|| (info.number_eating != -1
				&& ft_check_eating(el, info.number_eating) == 1))
			break ;
		el = el->next;
	}
	return (1);
}

int	ft_check_live(t_fork *philo, struct timeval timer, int time_to_die)
{
	struct timeval	current_time;
	long int		how_many_ms;

	if (pthread_mutex_lock(&(philo->info->mutex_eat)) != 0)
		return (0);
	gettimeofday(&current_time, NULL);
	how_many_ms = 1000 * (current_time.tv_sec - timer.tv_sec);
	how_many_ms += (current_time.tv_usec - timer.tv_usec) / 1000;
	if (how_many_ms > (long int) time_to_die)
	{
		ft_put_status(philo, "died\n");
		philo->info->death_flag = 1;
		if ((pthread_mutex_unlock(&(philo->info->mutex)) != 0)
			|| (pthread_mutex_unlock(&(philo->info->mutex_eat)) != 0))
			return (-1);
		return (0);
	}
	if (pthread_mutex_unlock(&(philo->info->mutex_eat)) != 0)
		return (0);
	return (1);
}

int	ft_check_eating(t_fork *philo, int number_eating)
{
	t_fork	*el;
	int		numb;

	el = philo;
	numb = philo->fork;
	while (el->next->fork != numb)
	{
		if (number_eating <= el->number_of_eating)
			el = el->next;
		else
			break ;
	}
	if ((el->next->fork == numb) && (el->number_of_eating >= number_eating))
	{
		philo->info->death_flag = 1;
		return (1);
	}
	return (0);
}
