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

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->info->print_mutex);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	take_right(t_philo *philo)
{
	long	dif_time;

	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->info->print_mutex);
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a fork\n", dif_time, philo->id);
	pthread_mutex_unlock(&philo->info->print_mutex);
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
	if (philo->id % 2)
		take_odd_with_check(philo);
	else
		take_even_with_check(philo);
}
