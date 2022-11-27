# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

# define size 4

int buffer[size];
int top = -1;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER, mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1=PTHREAD_COND_INITIALIZER, cond2 = PTHREAD_COND_INITIALIZER;

void* produce(void* dummy){
	for (int i = 0; i < 5; i++){
		pthread_mutex_lock( &mutex1 );
		sleep(1);
		if (top == size - 1)
			pthread_cond_wait( &cond1, &mutex1 );

		top++;
		printf("Produced %i by %li\n", top, (long)pthread_self());

		pthread_mutex_unlock( &mutex1 );
		pthread_cond_signal(&cond1);
		
	}
	return NULL;
}
void* consume(void* dummy){
	for (int i = 0; i < 5; i++){
		pthread_mutex_lock( &mutex1);
		sleep(1);
		if (top < 0)pthread_cond_wait( &cond1, &mutex1 );

		printf("Consumed %i by %li\n", top, (long)pthread_self());
		top --;

		pthread_mutex_unlock( &mutex1 );
		pthread_cond_signal(&cond1);
	}
	return NULL;
}

int main(void){	
	pthread_t t[6];

	pthread_create( &t[0], NULL, produce, NULL);
	pthread_create( &t[3], NULL, consume, NULL);
	pthread_create( &t[1], NULL, produce, NULL);
	pthread_create( &t[4], NULL, consume, NULL);
	pthread_create( &t[2], NULL, produce, NULL);
	pthread_create( &t[5], NULL, consume, NULL);

	pthread_join( t[0], NULL);
	pthread_join( t[1], NULL);
	pthread_join( t[2], NULL);
	pthread_join( t[3], NULL);
	pthread_join( t[4], NULL);
	pthread_join( t[5], NULL);
}

