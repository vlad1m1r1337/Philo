#include "../include/philo.h"
// -------------------------------------------------------
typedef pthread_mutex_t t_mutex;

struct s_data
{
	t_mutex *p_mutex;
	int *num1;
	int *num2;
};

void *ft_run(void *arg)
{
	struct s_data *thread_data = (struct s_data *)arg;
	int *i = thread_data->num1;
	int *j = thread_data->num2;
	pthread_mutex_lock(thread_data->p_mutex);
	while (*i < 1000000 || *j < 1000000)
	{
		printf("i = %d, j = %d\n", *i, *j);
		if (*i < 1000000)
			(*i)++;
		if (*j < 1000000)
			(*j)++;
	}
	pthread_mutex_unlock(thread_data->p_mutex);
	return NULL;
}

int main()
{
	pthread_t id1, id2;
	t_mutex mutex;
	struct s_data data;
	data.p_mutex = &mutex;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&id1, NULL, ft_run, &data);
	pthread_create(&id2, NULL, ft_run, &data);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}

// -------------------------------------------------------
