#include "../include/philo.h"

void	take_left(t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(philo->left_fork);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a left fork\n", dif_time, philo->id);
}

void	take_right(t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(philo->right_fork);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a right fork\n", dif_time, philo->id);
}

void	taking_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		take_left(philo);
		take_right(philo);
	}
	else
	{
		take_right(philo);
		take_left(philo);
	}
}

void	*routine(void *phil)
{
	t_philo *philo = (t_philo *)phil;
	long	dif_time;

	while (1)
	{
		if (philo->info->dead_flag)
			break;
		taking_fork(philo);
		dif_time = get_time() - philo->info->start_eat;
		philo->last_meal = get_time();
		printf("%ld %d is eating\n", dif_time, philo->id);
		if (philo->times_eaten != -1)
				philo->times_eaten++;
		ft_usleep(philo->info->t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_usleep(philo->info->t_sleep);
		if (philo->times_eaten == philo->info->times_eaten)
			break;
		if (philo->info->dead_flag)
			break ;
	}

	return NULL;
}

void	pthread_live(t_info *info, t_philo *philo)
{
	int			i;
	pthread_t	check;

	i = 0;
	while (i < info->count_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	pthread_create(&check, NULL, &checker, info);
	i = 0;
	while (i < info->count_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(check, NULL);
}

int	main(int argc, char **argv)
{
	t_info *info;
	t_philo *philo;

	if (validation(argc, argv))
	{
		putstr_err("Error: invalid arguments\n");
		return (1);
	}
	info = init_info(argc, argv);
	philo = init_philos(info);
	pthread_live(info, philo);
	return (0);
}
