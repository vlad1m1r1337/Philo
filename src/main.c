#include "../include/philo.h"

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->id = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->times_eaten = ft_atoi(argv[5]);
	else
		info->times_eaten = -1;
	return (info);
}

t_philo *init_philos(t_info *info)
{
	int id;

	id = 1;
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->id);
	if (!info->philos)
		return (NULL);
	info->philos->is_eating = 0;
	info->philos->times_eaten = 0;
	pthread_mutex_init(info->philos->print_mutex, NULL);
	pthread_mutex_init(info->philos->eat_mutex, NULL);
	pthread_mutex_init(info->philos->death_mutex, NULL);
	while (id < info->id)
	{
	}
	return (info->philos);
}

void	executor(t_info *info, t_philo *philo)
{
	(void)info;
	(void)philo;
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
