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
	pthread_t		thread;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int					count_philo;
	long					t_die;
	long					t_eat;
	long					t_sleep;
	long				times_eaten;
	long 				start_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		death_mutex;
	struct s_philo		*philos;
}						t_info;

int		ft_atoi(const char *str);

int		ft_strlen(char *str);

void	putstr_err(char *str);

int		validation(int argc, char **argv);

void	ft_usleep(t_info *info);

#endif