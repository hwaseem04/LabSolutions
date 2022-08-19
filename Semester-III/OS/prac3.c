# include <stdio.h>
# include <pthread.h>


void* func(void*);

int main(void)[
	
	pthread_t t1, t2;
	char* msg = "Hello Threads";
	pthread_create(&t1, NULL, func, (void*)msg);
	pthread_create(&t2, NULL, func, (void*)msg);
	
	pthread_join(t1);
	pthread_join(t2);

	return 0;
}

void* func(void* c){
	char* msg = (char*) c;
	printf("%s\n", msg);
}





