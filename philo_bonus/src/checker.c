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

void	kill_all(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->count_philo)
	{
		kill(info->pid[i], SIGKILL);
	}
}

int	enough_eat_check(t_philo *philo)
{
	int	counter;

	counter = 0;
	sem_wait(philo->info->times_eaten_sem);
	if (philo->info->times_eaten == -1)
	{
		sem_post(philo->info->times_eaten_sem);
		return (0);
	}
	sem_post(philo->info->times_eaten_sem);
	sem_wait(philo->info->times_eaten_sem);
	if (philo->times_eaten >= philo->info->times_eaten)
		counter++;
	sem_post(philo->info->times_eaten_sem);
	if (counter)
	{
		unlock_both_forks(philo);
		exit(0);
	}
	return (0);
}

int	die_check(t_philo *philo)
{
	sem_wait(philo->info->last_meal_sem);
	if (get_time() - philo->last_meal > philo->info->t_die)
	{
		sem_wait(philo->info->print_sem);
		printf("%ld %d philo is dead\n", \
		get_time() - philo->info->start_eat, philo->id);
		sem_post(philo->info->last_meal_sem);
		unlock_both_forks(philo);
		exit(1);
	}
	sem_post(philo->info->last_meal_sem);
	return (0);
}

void	wait_kill(t_info *info)
{
	int	status;

	while (waitpid(-1, &status, 0) != -1)
	{
		if (status / 256 == 1)
			kill_all(info);
	}
	sem_post(info->print_sem);
}

void	*checker(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	while (1)
	{
		if (enough_eat_check(philo) + die_check(philo))
			break ;
	}
	return (NULL);
}
