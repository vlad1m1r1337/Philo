#include "../include/philo.h"

void *routine()
{
	printf("Hello world\n");
	usleep(6000000);
	printf("Goodbye world\n");
	return (NULL);
}

void	fill_data(t_philo *philo, int argc, char **argv)
{
	(void)argc;
	philo->id = ft_atoi(argv[1]);
	philo->t_die = ft_atoi(argv[2]);
	philo->t_eat = ft_atoi(argv[3]);
	philo->t_sleep = ft_atoi(argv[4]);
	philo->times_eaten = ft_atoi(argv[5]);
}

int main(int argc, char **argv)
{
	t_philo	philo;
	if (argc != 6)
	{
		putstr_err("Error: wrong number of arguments\n");
		return (1);
	}
	fill_data(&philo, argc, argv);
	pthread_t	*ph;
	ph = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));

	int	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&ph[i], NULL, &routine, NULL);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(ph[i], NULL);
		i++;
	}
	return (0);
}
