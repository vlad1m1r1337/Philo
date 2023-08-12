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

void	*routine(t_philo *philo)
{
	if (philo->info->count_philo == 1)
		ft_usleep(philo->info->t_die * 11 / 10);
	while (1)
	{
		taking_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	pthread_live(t_info *info, t_philo *philo)
{
	int			i;
	pthread_t	check;

	i = -1;
	pthread_create(&check, NULL, &checker, info);
	while(++i < info->count_philo)
		info->pid[i] = -1;
	i = -1;
	while(++i < info->count_philo)
	{
		info->pid[i] = fork();
		if (!info->pid[i])
			routine(&philo[i]);
	}
//	while(++i < info->count_philo)
//		printf("pids - %d\n", info->pid[i]);
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
