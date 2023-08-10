/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:47:31 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:50:03 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->info->count_philo == 1)
		ft_usleep(philo->info->t_die * 11 / 10);
	while (1)
	{
		if (bool_exit_check(philo))
			break ;
		taking_fork(philo);
		if (bool_exit_check(philo))
			break ;
		eating(philo);
		if (bool_exit_check(philo))
			break ;
		ft_usleep(philo->info->t_sleep);
		if (bool_exit_check(philo))
			break ;
		pthread_mutex_lock(&philo->info->times_eaten_mutex);
		if (philo->times_eaten != -1)
			philo->times_eaten++;
		pthread_mutex_unlock(&philo->info->times_eaten_mutex);
	}
	return (NULL);
}

void	pthread_live(t_info *info, t_philo *philo)
{
	int			i;
	pthread_t	check;

	i = 0;
	while (i < info->count_philo)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i++;
	}
	pthread_create(&check, NULL, &checker, info);
	i = 0;
	while (i < info->count_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(check, NULL);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	if (validation(argc, argv))
	{
		putstr_err("Error: invalid arguments\n");
		return (1);
	}
	info = init_info(argc, argv);
	philo = init_philos(info);
	pthread_live(info, philo);
	return (0);
}
