#include "../include/philo.h"

int	enough_eat_check(t_info *info)
{
	int	counter;
	int	i;

	i = -1;
	counter = 0;
	pthread_mutex_lock(&info->times_eaten_mutex);
	if (info->times_eaten == -1)
		return (0);
	pthread_mutex_unlock(&info->times_eaten_mutex);
	while(++i < info->count_philo)
	{
		pthread_mutex_lock(&info->times_eaten_mutex);
		if (info->philos[i].times_eaten >= info->times_eaten)
			counter++;
		pthread_mutex_unlock(&info->times_eaten_mutex);
	}
	if (counter == info->count_philo)
	{
		pthread_mutex_lock(&info->exit_mutex);
		info->exit_flag = 1;
		pthread_mutex_unlock(&info->exit_mutex);
		return (1);
	}
	return (0);
}

int	die_check(t_info *info)
{
	int i;

	i = -1;
	while(++i < info->count_philo)
	{
		pthread_mutex_lock(&info->eat_mutex);
		if (get_time() - info->philos[i].last_meal > info->t_die)
		{
			pthread_mutex_unlock(&info->eat_mutex);
			printf("%ld %d philo is dead\n",get_time() - info->start_eat, info->philos[i].id);
			pthread_mutex_lock(&info->exit_mutex);
			info->exit_flag = 1;
			pthread_mutex_unlock(&info->exit_mutex);
			pthread_mutex_unlock(&info->eat_mutex);
			return (1);
		}
		pthread_mutex_unlock(&info->eat_mutex);
	}
	return (0);
}

void	*checker(void *inf)
{
	t_info *info = (t_info *)inf;
	while (1)
	{
		if (enough_eat_check(info) + die_check(info))
			break;
	}
	return (NULL);
}

int bool_exit_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->exit_mutex);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(&philo->info->exit_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->exit_mutex);
	return (0);
}


