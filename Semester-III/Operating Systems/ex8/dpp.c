# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

# define left Pi
# define right (Pi + 1) % 5

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int semaphore[5];

void pick(int Pi){
	while (semaphore[Pi] <= 0);
	pthread_mutex_lock( &mutex1 );
	semaphore[Pi] --;
	pthread_mutex_unlock( &mutex1 );
}

void keep(int Pi){
	pthread_mutex_lock( &mutex1 );
	semaphore[Pi] ++;	
	pthread_mutex_unlock( &mutex1 );
}

void* phil(void* i){
	int Pi = *(int*)i;
	printf("%i\n", Pi);

	printf("P%i waiting LEFT\n", Pi);
	pick(left);
	printf("P%i picked LEFT\n", Pi);

	printf("P%i waiting RIGHT\n", Pi);
	pick(right);
	printf("P%i picked RIGHT\n", Pi);

	printf("P%i EATING\n", Pi);
	sleep(2);

	printf("P%i COMPLETED eating\n", Pi);
	keep(left);
	keep(right);

	return NULL;
}

int main(void){
	pthread_t T[5];

	for (int i = 0; i < 5; i++)semaphore[i] = 1;
	int n[5];
	for (int i = 0; i < 5; i++){
		n[i] = i;
		pthread_create( &T[i], NULL, phil, (void*)&n[i]); 
	}

	for (int i = 0; i < 5; i++) pthread_join(T[i], NULL);
}


