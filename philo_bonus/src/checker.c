/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:47:31 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:43:49 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	enough_eat_check(t_info *info)
{
	int	counter;
	int	i;

	i = -1;
	counter = 0;
	pthread_mutex_lock(&info->times_eaten_mutex);
	if (info->times_eaten == -1)
	{
		pthread_mutex_unlock(&info->times_eaten_mutex);
		return (0);
	}
	pthread_mutex_unlock(&info->times_eaten_mutex);
	while (++i < info->count_philo)
	{
		pthread_mutex_lock(&info->times_eaten_mutex);
		if (info->philos[i].times_eaten >= info->times_eaten)
			counter++;
		pthread_mutex_unlock(&info->times_eaten_mutex);
		if (counter == info->count_philo)
			exit(0);
	}
	return (0);
}

void	kill_all(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count_philo)
		kill(info->pid[i], SIGKILL);
}

int	die_check(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count_philo)
	{
		pthread_mutex_lock(&info->last_meal_mutex);
		if (get_time() - info->philos[i].last_meal > info->t_die)
		{
			printf("%ld %d philo is dead\n", \
			get_time() - info->start_eat, info->philos[i].id);
			kill_all(info);
			exit(0);
		}
		pthread_mutex_unlock(&info->last_meal_mutex);
	}
	return (0);
}

void	*checker(void *inf)
{
	t_info	*info;

	info = (t_info *)inf;
	while (1)
	{
		if (enough_eat_check(info) + die_check(info))
			break ;
	}
	return (NULL);
}

