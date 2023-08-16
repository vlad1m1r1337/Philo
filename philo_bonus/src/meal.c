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

void	time_eaten_increase(t_philo *philo)
{
	sem_wait(philo->info->times_eaten_sem);
	if (philo->times_eaten != -1)
	{
		philo->times_eaten++;
		sem_post(philo->info->times_eaten_sem);
	}
	sem_post(philo->info->times_eaten_sem);
}

void	record_last_meal(t_philo *philo)
{
	long	dif_time;

	sem_wait(philo->info->last_meal_sem);
	philo->last_meal = get_time();
	sem_post(philo->info->last_meal_sem);
	time_eaten_increase(philo);
	dif_time = philo->last_meal - philo->info->start_eat;
	sem_wait(philo->info->print_sem);
	printf("%ld %d is eating\n", dif_time, philo->id);
	sem_post(philo->info->print_sem);
}

void	eating(t_philo *philo)
{
	record_last_meal(philo);
	ft_usleep(philo->info->t_eat);
	unlock_both_forks(philo);
}
