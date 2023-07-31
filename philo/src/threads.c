#include "../include/philo.h"
//--------------------------------------------------------------------
//int mails = 0;
//pthread_mutex_t mutex;
//
//
//void	*routine()
//{
//	for (int (i) = 0; (i) < 1000000; ++(i)) {
//		pthread_mutex_lock(&mutex);
//		mails++;
//		pthread_mutex_unlock(&mutex);
//	}
//}
//
//int main(int argc,char *argv[])
//{
//	pthread_t	th[8];
//	int i = 0;
//	pthread_mutex_init(&mutex, NULL);
//	for(i = 0; i < 8; i++) {
//		if (pthread_create(th + i, NULL, &routine, NULL) != 0) {
//			perror("Failed to create thread");
//			return (1);
//		}
//		printf("Thread %d has started\n", i);
////		if (pthread_join(th[i], NULL) != 0)
////			return (2);
//		//printf("Thread %d has finished execution\n", i);
//	}
//	for(i = 0; i < 4; i++) {
//		if (pthread_join(th[i], NULL) != 0)
//			return (2);
//		printf("Thread %d has finished execution\n", i);
//	}
//	pthread_mutex_destroy(&mutex);
//	printf("Number of mails: %d\n", mails);
//	return (0);
//}
//--------------------------------------------------------------------

//#include <time.h>
//
//void*	roll_dice()
//{
//	int value = rand() % 6 + 1;
//	int *result = malloc(sizeof(int));
//	*result = value;
//	//printf("Value: %d\n", value);
//
//	return (void*) result;
//}
//
//
//int main(int argc, char **argv)
//{
//	pthread_t	th;
//	int *res;
//	srand(time(NULL));
//	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
//		perror("Failed to create thread");
//		return (1);
//	}
//	if (pthread_join(th, (void **) &res) != 0)
//		return (2);
//	printf("Result: %d\n", *res);
//	return 0;
//}

//--------------------------------------------------------------------

//int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
//
//void	*routine(void *arg)
//{
//	sleep(1);
//	int index = *(int *) arg;
//	printf("%d ", primes[index]);
//}
//
//int main(int argc, char **argv)
//{
//	pthread_t th[10];
//	int i;
//	for( i = 0; i < 10; i++) {
//		if (pthread_create(&th[i], NULL, &routine, &i) != 0) {
//			perror("Failed to create thread");
//			return (1);
//		}
//	}
//	for( i = 0; i < 10; i++) {
//		if (pthread_join(th[i], NULL) != 0) {
//			perror("Failed to join thread");
//			return (1);
//		}
//	}
//	return (0);
//}