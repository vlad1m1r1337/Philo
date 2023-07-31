#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

//typedef struct s_philo
//{
//	int				id;
//	int				is_eating;
//	int				times_eaten;
//	pthread_mutex_t	*left_fork;
//	pthread_mutex_t	*right_fork;
//	pthread_mutex_t	*print_mutex;
//	pthread_mutex_t	*eat_mutex;
//	pthread_mutex_t	*death_mutex;
//	struct timeval	last_meal;
//}	t_philo;

typedef struct s_philo
{
	int id;
	int	t_die;
	int t_eat;
	int t_sleep;
	int times_eaten;
} t_philo;

int	ft_atoi(const char *str);

int	ft_strlen(char *str);

void putstr_err(char* str);

#endif