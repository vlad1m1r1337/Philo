/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgribkov <vgribkov@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:47:31 by vgribkov          #+#    #+#             */
/*   Updated: 2023/08/10 18:40:01 by vgribkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				times_eaten;
	pthread_t		thread;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int 					pid[INT_MAX];
	int						count_philo;
	int						exit_flag;
	long					t_die;
	long					t_eat;
	long					t_sleep;
	int						times_eaten;
	long					start_eat;
	sem_t					*forks;
	pthread_mutex_t			times_eaten_mutex;
	pthread_mutex_t			last_meal_mutex;
	struct s_philo			*philos;
}							t_info;

int		ft_atoi(const char *str);

int		ft_strlen(char *str);

void	putstr_err(char *str);

int		validation(int argc, char **argv);

void	ft_usleep(long t_eat);

long	get_time(void);

//init

void	init_forks(t_info *info);

t_info	*init_info(int argc, char **argv);

void	init_philo(int id_arr, t_info *info);

t_philo	*init_philos(t_info *info);

//checker

void	*checker(void *inf);

int		die_check(t_info *info);

int		bool_exit_check(t_philo *philo);

//meal

void	eating(t_philo *philo);

void	unlock_all(t_philo *philo);

void	record_last_meal(t_philo *philo);

void	unlock_both_forks(t_philo *philo);

//take

void	take_left(t_philo *philo);

void	take_right(t_philo *philo);

void	taking_fork(t_philo *philo);

void	take_odd_with_check(t_philo *philo);

void	take_even_with_check(t_philo *philo);

//sleep

void	sleeping(t_philo *philo);

void	thinking(t_philo *philo);

#endif