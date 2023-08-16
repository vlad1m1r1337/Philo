/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:09 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/11 13:14:14 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sleeping(t_philo *philo)
{
	long	dif_time;

	dif_time = get_time() - philo->info->start_eat;
	sem_wait(philo->info->print_sem);
	printf("%ld %d is sleeping\n", dif_time, philo->id);
	sem_post(philo->info->print_sem);
	ft_usleep(philo->info->t_sleep);
}

void	thinking(t_philo *philo)
{
	long	dif_time;

	dif_time = get_time() - philo->info->start_eat;
	sem_wait(philo->info->print_sem);
	printf("%ld %d is thinking\n", dif_time, philo->id);
	sem_post(philo->info->print_sem);
}
