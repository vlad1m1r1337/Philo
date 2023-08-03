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
	int				is_eating;
	int				times_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*death_mutex;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int id;
	int	t_die;
	int t_eat;
	int t_sleep;
	int times_eaten;
	struct  s_philo 		*philos;
} t_info;

int	ft_atoi(const char *str);

int	ft_strlen(char *str);

void putstr_err(char* str);

#endif