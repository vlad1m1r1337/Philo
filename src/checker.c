#include "../include/philo.h"

//void	eat_enough_check(t_info *info)
//{
//	(void)info;
//	if (info->philo->times_eaten == philo->info->times_eaten)
//		;
//	puts("eat_enough_check");
//}

void	*checker(void *inf)
{
	t_info *info = (t_info *)inf;
	die_check(info);
	//eat_enough_check(info);
	return (NULL);
}

void	die_check(t_info *info)
{
	int i;
	long start;
	int counter;

	start = get_time();
	i = -1;
	while (1)
	{
		counter = 0;
		while(++i < info->count_philo)
		{
			if (info->philos[i].times_eaten == info->times_eaten)
				counter++;
			else
				break;
		}
		if (counter == info->times_eaten)
			break ;
		while(++i < info->count_philo)
		{
			if ((get_time() - start) - info->philos[i].last_meal > info->t_die)
			{
				printf("%d philo dead\n", info->philos[i].id);
				info->dead_flag = 1;
				return ;
			}
		}
		i = -1;
	}
}


