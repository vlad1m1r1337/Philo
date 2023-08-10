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

	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	dif_time = get_time() - philo->info->start_eat;
	pthread_mutex_lock(&philo->info->times_eaten_mutex);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	printf("%ld %d has taken a left fork\n", dif_time, philo->id);
	pthread_mutex_unlock(&philo->info->times_eaten_mutex);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
}

void	take_right(t_philo *philo)
{
	long	dif_time;

	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	dif_time = get_time() - philo->info->start_eat;
	pthread_mutex_lock(&philo->info->times_eaten_mutex);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	printf("%ld %d has taken a right fork\n", dif_time, philo->id);
	pthread_mutex_unlock(&philo->info->times_eaten_mutex);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
}

void	take_odd_with_check(t_philo *philo)
{
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	take_left(philo);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	take_right(philo);
}

void	take_even_with_check(t_philo *philo)
{
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	take_right(philo);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	take_left(philo);
}

void	taking_fork(t_philo *philo)
{
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
	if (philo->id % 2)
		take_odd_with_check(philo);
	else
		take_even_with_check(philo);
	if (bool_exit_check(philo))
	{
		unlock_all(philo);
		return ;
	}
}
