#include "../include/philo.h"

int	enough_eat_check(t_info *info)
{
	int	counter;
	int	i;

	i = -1;
	counter = 0;
	if (info->times_eaten == -1)
		return (0);
	while(++i < info->count_philo)
	{
		if (info->philos[i].times_eaten >= info->times_eaten)
			counter++;
	}
	if (counter == info->count_philo)
		return (1);
	return (0);
}

void	forks_destroyer(t_info *info)
{
	//puts("fd");
	int i = -1;
	while(++i < info->count_philo)
		pthread_mutex_destroy(&info->forks[i]);
}

int	die_check(t_info *info)
{
	int i;
	int counter;

	i = -1;
	while(++i < info->count_philo)
	{
		if (get_time() - info->philos[i].last_meal > info->t_die)
		{
			printf("%d philo dead\n", info->philos[i].id);
			info->dead_flag = 1;
			return (1);
		}
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
