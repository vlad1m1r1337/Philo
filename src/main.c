#include "../include/philo.h"

void	init_forks(t_info *info)
{
	int i;

	i = 0;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->count_philo);
	if (!info->forks)
		return ;
	while (i < info->count_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;
	struct timeval time;

	gettimeofday(&time, NULL);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->count_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->start_eat = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (argc == 6)
		info->times_eaten = ft_atoi(argv[5]);
	else
		info->times_eaten = -1;
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->eat_mutex, NULL);
	pthread_mutex_init(&info->death_mutex, NULL);
	init_forks(info);
	return (info);
}

void	init_philo(int id_arr, t_info *info)
{
	info->philos[id_arr].id = id_arr + 1;
	info->philos[id_arr].last_meal = 0;
	info->philos[id_arr].times_eaten = 0;
	info->philos[id_arr].left_fork = &info->forks[(id_arr + 1) % info->count_philo];
	info->philos[id_arr].right_fork = &info->forks[id_arr];
	info->philos[id_arr].info = info;
}

t_philo		*init_philos(t_info *info)
{
	int id_arr;

	id_arr = 0;
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

void	taking_fork(t_philo *philo) {
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

//	if(!(philo->id % 2))
//		usleep(300);
	while (1)
	{
		taking_fork(philo);
		dif_time = get_time() - philo->info->start_eat;
		printf("%ld %d is eating\n", dif_time, philo->id);
		ft_usleep(philo->info->t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_usleep(philo->info->t_sleep);
	}
	return NULL;
}

//void	*checking()
//{
//
//}

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
	i = 0;
	while (i < info->count_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	//pthread_create(&check, NULL, &checking, NULL);
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
