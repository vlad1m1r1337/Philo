#include "../include/philo.h"

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->id = 0;
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->times_eaten = ft_atoi(argv[5]);
	else
		info->times_eaten = -1;

	return (info);
}

//int main(int argc, char **argv)
//{
//	t_info *info;
//	t_philo *philo;
//
//	if (!validation(argc, argv))
//	{
//		putstr_err("Error: invalid arguments\n");
//		return (1);
//	}
//	info = init_info(argc, argv);
//	if (!info)
//	{
//		putstr_err("Error: malloc failed\n");
//		return (1);
//	}
//	philo = init_philos(info);
//	if (!philo)
//	{
//		putstr_err("Error: malloc failed\n");
//		return (1);
//	}
//	executor(info, philo);
//}
