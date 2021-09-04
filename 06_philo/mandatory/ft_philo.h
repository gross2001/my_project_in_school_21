#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_common
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_eat;
	struct timeval	initial_time;
	char			*to_print;
	int				print_numb;
	int				limit_to_print;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_eating;
	int				death_flag;

}	t_common;

typedef struct s_fork
{
	pthread_mutex_t		fork_mutex;
	struct timeval		timer;	
	struct s_fork		*next;
	pthread_t			thread;
	t_common			*info;
	int					fork;
	int					number_of_eating;
}	t_fork;

void	*ft_routine(void *argc);
void	ft_strjoin(t_fork *philo, int time, int fork, char *status);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_initiate_mutex(t_fork **philo);
int		ft_initial_info(int argc, char *argv[], t_common *info);
int		ft_initial_fork(t_fork **philo, t_common *info);
int		ft_check_thread(t_fork *philo, t_common info);
int		ft_check_live(t_fork *philo, struct timeval timer, int time_to_die);
int		ft_check_eating(t_fork *philo, int number_eating);
int		ft_put_status(t_fork *philo, char *status);
int		ft_create_thread(t_fork *philo, t_common info);
int		ft_lstdel(t_fork *philo);
int		ft_join_thread(t_fork *philo);
int		ft_pthread_mutex_lock(pthread_mutex_t *mutex, t_common *info);
int		ft_pthread_mutex_unlock(pthread_mutex_t *mutex, t_common *info);
int		ft_part_of_routine(t_fork *philo);
int		ft_usleep(int time);

#endif
