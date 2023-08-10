#include "../include/philo.h"

void unlock_both_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_left(t_philo *philo)
{
	long	dif_time;

	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	dif_time = get_time() - philo->info->start_eat;
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	printf("%ld %d has taken a left fork\n", dif_time, philo->id);
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
}

void	take_right(t_philo *philo)
{
	long	dif_time;

	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	dif_time = get_time() - philo->info->start_eat;
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	printf("%ld %d has taken a right fork\n", dif_time, philo->id);
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
}

void	taking_fork(t_philo *philo)
{
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	if (philo->id % 2)
	{
		if (bool_exit_check(philo))
		{
			unlock_both_forks(philo);
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return ;
		}
		take_left(philo);
		if (bool_exit_check(philo))
		{
			unlock_both_forks(philo);
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return ;
		}
		take_right(philo);
	}
	else
	{
		if (bool_exit_check(philo))
		{
			unlock_both_forks(philo);
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return ;
		}
		take_right(philo);
		if (bool_exit_check(philo))
		{
			unlock_both_forks(philo);
			pthread_mutex_unlock(&philo->info->eat_mutex);
			return ;
		}
		take_left(philo);
	}
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
}

void record_last_meal(t_philo *philo)
{
	long	dif_time;
	dif_time = get_time() - philo->info->start_eat;
	pthread_mutex_lock(&philo->info->eat_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->info->eat_mutex);
	printf("%ld %d is eating\n", dif_time, philo->id);
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
}

void	eating(t_philo *philo)
{
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	record_last_meal(philo);
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	ft_usleep(philo->info->t_eat);
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
	unlock_both_forks(philo);
	if (bool_exit_check(philo))
	{
		unlock_both_forks(philo);
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return ;
	}
}
