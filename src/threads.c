#include "../include/philo.h"
// -------------------------------------------------------
typedef pthread_mutex_t t_mutex;

struct s_data
{
	t_mutex *p_mutex;
	int *num;
};

void *ft_run(void *arg)
{
	struct s_data *thread_data = (struct s_data *)arg;
	int *i = thread_data->num;
	pthread_mutex_lock(thread_data->p_mutex);
	while (*i < 1000000)
	{
		pthread_mutex_unlock(thread_data->p_mutex);
		pthread_mutex_lock(thread_data->p_mutex);
		*i  += 1;
		pthread_mutex_unlock(thread_data->p_mutex);
		pthread_mutex_lock(thread_data->p_mutex);
		printf("sub %d\n", *i);
		pthread_mutex_unlock(thread_data->p_mutex);
	}
	pthread_mutex_unlock(thread_data->p_mutex);
	return NULL;
}

int main()
{
	int tmp = 0;
	pthread_t id;
	t_mutex mutex;
	struct s_data data;
	data.p_mutex = &mutex;
	data.num = &tmp;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&id, NULL, ft_run, &data);
	pthread_mutex_lock(&mutex);
	while (tmp < 1000000)
	{
		pthread_mutex_unlock(&mutex);
		pthread_mutex_lock(&mutex);
		tmp++;
		pthread_mutex_unlock(&mutex);
		pthread_mutex_lock(&mutex);
		printf("main %d\n", tmp);
		pthread_mutex_unlock(&mutex);
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&mutex);
	pthread_join(id, NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}

// -------------------------------------------------------
