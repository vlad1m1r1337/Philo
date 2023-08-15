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

void	take_left(t_philo *philo)
{
	long	dif_time;

	sem_wait(philo->info->forks);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
}

void	take_right(t_philo *philo)
{
	long	dif_time;

	sem_wait(philo->info->forks);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
}

void	take_even_with_check(t_philo *philo)
{
	take_right(philo);
	take_left(philo);
}

void	take_odd_with_check(t_philo *philo)
{
	take_left(philo);
	take_right(philo);
}

void	taking_fork(t_philo *philo)
{
	long dif_time;

	sem_wait(philo->info->forks);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a fork\n", dif_time, philo->id);

	sem_wait(philo->info->forks);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
}
