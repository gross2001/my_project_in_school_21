#include "ft_philo.h"

int	ft_initiate_mutex(t_fork **philo)
{
	t_fork	*el;
	int		i;
	int		n;

	el = *philo;
	i = 0;
	n = (*philo)->info->number_of_philo;
	while (i < n)
	{
		if (pthread_mutex_init(&(el->fork_mutex), NULL) != 0)
			return (0);
		el = el->next;
		i++;
	}
	return (1);
}

int	ft_initial_info(int argc, char *argv[], t_common *info)
{
	if (argc != 5 && argc != 6)
		return (printf("Incorrect number of arguments\n"));
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->death_flag = 0;
	info->print_numb = 0;
	info->limit_to_print = (info->number_of_philo) * 18 / 2;
	info->to_print = (char *) malloc (sizeof(char)
			* (30 + info->limit_to_print));
	if (info->to_print == 0)
		return (1);
	info->to_print[0] = 0;
	if (argc == 6)
		info->number_eating = ft_atoi(argv[5]);
	else
		info->number_eating = -1;
	if (info->number_of_philo <= 0 || info->number_of_philo > 200
		|| info->time_to_die <= 0 || info->time_to_eat <= 0
		|| info->time_to_sleep <= 0 || (argc == 6 && info->number_eating <= 0))
		return (printf("Incorrect initial data, please check\n"));
	return (0);
}

int	ft_initial_fork(t_fork **philo, t_common *info)
{
	t_fork	*el;
	int		i;	

	i = 0;
	el = (t_fork *) malloc(sizeof(t_fork));
	if (el == NULL)
		return (0);
	*philo = el;
	while (i < info->number_of_philo)
	{
		el->fork = i + 1;
		el->info = info;
		el->number_of_eating = 0;
		if ((i + 1) < info->number_of_philo)
		{
			el->next = (t_fork *) malloc(sizeof(t_fork));
			if (el->next == NULL)
				return (0);
			el = el->next;
		}
		else
			el->next = *philo;
		i++;
	}
	return (1);
}

int	ft_create_thread(t_fork *philo, t_common info)
{
	t_fork	*el;
	int		i;

	i = 0;
	while (i < info.number_of_philo)
	{
		el = philo;
		while (el->fork != (i + 1))
			el = el->next;
		if (pthread_create(&(el->thread), NULL, ft_routine, el) != 0)
			return (0);
		i = i + 1;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_common	info;
	t_fork		*philo;

	philo = NULL;
	if (ft_initial_info(argc, argv, &info) != 0)
		return (0);
	if (ft_initial_fork(&philo, &info) == 0)
		return (0);
	if (pthread_mutex_init(&info.mutex, NULL) != 0
		|| ft_initiate_mutex(&philo) == 0
		|| pthread_mutex_init(&info.mutex_eat, NULL) != 0)
		return (0);
	gettimeofday(&info.initial_time, NULL);
	if (ft_create_thread(philo, info) == 0)
		return (0);
	usleep(7000);
	ft_check_thread(philo, info);
	ft_join_thread(philo);
	ft_lstdel(philo);
	return (0);
}
