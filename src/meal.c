/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:09:40 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:37:25 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	unlock_both_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	unlock_all(t_philo *philo)
{
	unlock_both_forks(philo);
	pthread_mutex_unlock(&philo->info->eat_mutex);
	pthread_mutex_unlock(&philo->info->times_eaten_mutex);
}

void	record_last_meal(t_philo *philo)
{
	long	dif_time;

	dif_time = get_time() - philo->info->start_eat;
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	printf("%ld %d is eating\n", dif_time, philo->id);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
}

void	eating(t_philo *philo)
{
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	record_last_meal(philo);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	ft_usleep(philo->info->t_eat);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	unlock_both_forks(philo);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
}
