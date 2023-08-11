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

void	put_exfl_with_mut(t_info *info)
{
	pthread_mutex_lock(&info->print_mutex);
	pthread_mutex_lock(&info->exit_mutex);
	info->exit_flag = 1;
	pthread_mutex_unlock(&info->exit_mutex);
	pthread_mutex_unlock(&info->print_mutex);
}

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
		{
			put_exfl_with_mut(info);
			return (1);
		}
	}
	return (0);
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
			pthread_mutex_unlock(&info->last_meal_mutex);
			if (!bool_exit_check(&info->philos[i]))
				printf("%ld %d philo is dead\n", \
			get_time() - info->start_eat, info->philos[i].id);
			pthread_mutex_lock(&info->exit_mutex);
			info->exit_flag = 1;
			pthread_mutex_unlock(&info->exit_mutex);
			pthread_mutex_unlock(&info->last_meal_mutex);
			return (1);
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

int	bool_exit_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->exit_mutex);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(&philo->info->exit_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->exit_mutex);
	return (0);
}
