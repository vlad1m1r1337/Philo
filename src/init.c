/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:47:31 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:47:34 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->count_philo);
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
	t_info			*info;
	struct timeval	time;

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
	info->exit_flag = 0;
	pthread_mutex_init(&info->times_eaten_mutex, NULL);
	pthread_mutex_init(&info->last_meal_mutex, NULL);
	pthread_mutex_init(&info->exit_mutex, NULL);
	init_forks(info);
	return (info);
}

void	init_philo(int id_arr, t_info *info)
{
	info->philos[id_arr].id = id_arr + 1;
	info->philos[id_arr].last_meal = get_time();
	info->philos[id_arr].times_eaten = 0;
	info->philos[id_arr].left_fork = &info \
		->forks[(id_arr + 1) % info->count_philo];
	info->philos[id_arr].right_fork = &info->forks[id_arr];
	info->philos[id_arr].info = info;
}

t_philo	*init_philos(t_info *info)
{
	int	id_arr;

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
