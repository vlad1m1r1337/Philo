#include "../include/philo.h"

void	*routine(void *phil)
{
	t_philo *philo = (t_philo *)phil;
	long	dif_time;

	while (1)
	{
		if (philo->info->exit_flag)
			break ;
		taking_fork(philo);
		if (philo->info->exit_flag)
			break ;
		eating(philo);
		if (philo->info->exit_flag)
			break ;
		ft_usleep(philo->info->t_sleep);
		if (philo->info->exit_flag)
			break ;
//		if (ate(philo))
//			break;
		if (philo->times_eaten != -1)
			philo->times_eaten++;
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
