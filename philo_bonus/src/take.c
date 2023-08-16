/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:33:20 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:37:25 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	taking_fork(t_philo *philo)
{
	long	dif_time;

	sem_wait(philo->info->forks);
	dif_time = get_time() - philo->info->start_eat;
	sem_wait(philo->info->last_meal_sem);
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
	sem_post(philo->info->print_sem);
	sem_wait(philo->info->forks);
	dif_time = get_time() - philo->info->start_eat;
	sem_wait(philo->info->last_meal_sem);
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
	sem_post(philo->info->print_sem);
}
