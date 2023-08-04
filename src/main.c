#include "../include/philo.h"

void	init_forks(t_info *info)
{
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->count_philo);
	if (!info->forks)
		return ;
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->count_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->times_eaten = ft_atoi(argv[5]);
	else
		info->times_eaten = -1;
	init_forks(info);
	return (info);
}

void	init_philo(int id_arr, t_info *info)
{
	info->philos[id_arr].id = id_arr + 1;
	info->philos[id_arr].is_eating = 0;
	info->philos[id_arr].times_eaten = 0;
	info->philos->left_fork = &info->forks[(id_arr + 1) % info->count_philo];
	info->philos->right_fork = &info->forks[id_arr];
}

t_philo *init_philos(t_info *info)
{
	int id_arr = 0;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->count_philo);
	if (!info->philos)
		return (NULL);
	while (id_arr < info->count_philo)
	{
		init_philo(id_arr, info);
		id_arr++;
	}
	return (info->philos);
}

void	executor(t_info *info, t_philo *philo)
{
	(void)info;
	(void)philo;
	//printf("%d\n", info->philos[1].is_eating);
	printf("executing\n");
}

int main(int argc, char **argv)
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
	executor(info, philo);
}
