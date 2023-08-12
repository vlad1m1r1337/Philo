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
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}

void	unlock_all(t_philo *philo)
{
	unlock_both_forks(philo);
	pthread_mutex_unlock(&philo->info->last_meal_mutex);
	pthread_mutex_unlock(&philo->info->times_eaten_mutex);
}

void	time_eaten_increase(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->times_eaten_mutex);
	if (philo->times_eaten != -1)
	{
		philo->times_eaten++;
		pthread_mutex_unlock(&philo->info->times_eaten_mutex);
	}
	pthread_mutex_unlock(&philo->info->times_eaten_mutex);
}

void	record_last_meal(t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(&philo->info->last_meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->info->last_meal_mutex);
	time_eaten_increase(philo);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d is eating\n", dif_time, philo->id);
}

void	eating(t_philo *philo)
{
	record_last_meal(philo);
	ft_usleep(philo->info->t_eat);
	unlock_both_forks(philo);
}
