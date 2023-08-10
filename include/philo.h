#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				times_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int						count_philo;
	int 					exit_flag;
	long					t_die;
	long					t_eat;
	long					t_sleep;
	int						times_eaten;
	long 					start_eat;
	pthread_mutex_t			*forks;
	pthread_mutex_t			times_eaten_mutex;
	pthread_mutex_t			eat_mutex;
	pthread_mutex_t			exit_mutex;
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

t_philo		*init_philos(t_info *info);

//checker

void	*checker(void *inf);

int		die_check(t_info *info);

int bool_exit_check(t_philo *philo);

//meal

void	take_left(t_philo *philo);

void	take_right(t_philo *philo);

void	taking_fork(t_philo *philo);

int	ate(t_philo *philo);

void	eating(t_philo *philo);

#endif