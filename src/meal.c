#include "../include/philo.h"

void	take_left(t_philo *philo)
{
	long	dif_time;

	if (philo->info->exit_flag)
		return ;
	pthread_mutex_lock(philo->left_fork);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a left fork\n", dif_time, philo->id);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
}

void	take_right(t_philo *philo)
{
	long	dif_time;

	if (philo->info->exit_flag)
		return ;
	pthread_mutex_lock(philo->right_fork);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	dif_time = get_time() - philo->info->start_eat;
	printf("%ld %d has taken a right fork\n", dif_time, philo->id);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
}

void	taking_fork(t_philo *philo)
{
	if (philo->info->exit_flag)
		return ;
	if (philo->id % 2)
	{
		take_left(philo);
		take_right(philo);
	}
	else
	{
		take_right(philo);
		take_left(philo);
	}
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
}

void	eating(t_philo *philo)
{
	long	dif_time;
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	dif_time = get_time() - philo->info->start_eat;
	philo->last_meal = get_time();
	printf("%ld %d is eating\n", dif_time, philo->id);
	if (philo->info->exit_flag)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	ft_usleep(philo->info->t_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->info->exit_flag)
		return ;
}
