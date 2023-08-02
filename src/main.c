#include "../include/philo.h"

//void *routine()
//{
//	printf("Hello world\n");
//	usleep(6000000);
//	printf("Goodbye world\n");
//	return (NULL);
//}
//
//void	init_info(t_info *info, int argc, char **argv)
//{
//	info->id = ft_atoi(argv[1]);
//	info->t_die = ft_atoi(argv[2]);
//	info->t_eat = ft_atoi(argv[3]);
//	info->t_sleep = ft_atoi(argv[4]);
//	info->times_eaten = ft_atoi(argv[5]);
//}
//
//void	init(t_info *info, int argc, char **argv)
//{
//	int i;
//
//	i = 0;
//	init_info(info, argc, argv);
//}

int number_check(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j = 1;
		else
			j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int zero_positive_empty_check(char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) == 0)
			return (1);
		if (argv[i][0] == '\0')
			return (1);
	}
	return (0);
}

int	validation(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (!(number_check(argv) + zero_positive_empty_check(argv)))
		return (1);
	return (0);
}

//int main(int argc, char **argv)
//{
//	t_info *info;
//	t_philo philo;
//
//	if (!validation(argc, argv))
//	{
//		putstr_err("Error: invalid arguments\n");
//		return (1);
//	}
//	info = (t_info)malloc(sizeof(t_info));
//	init(info, argc, argv);
//}
