# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

void* func(void*);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
int counter = 0;

int main(void){

    pthread_t t1, t2, t3;
    char* msg = "Hello Threads";
    pthread_create(&t1, NULL, func, (void*)msg);
    pthread_create(&t2, NULL, func, (void*)msg);
    //pthread_create(&t3, NULL, func, (void*)msg);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    //pthread_join(t3, NULL);
    //printf("%i\n", counter);
    return 0;
}

void* func(void* c){
    
    pthread_mutex_lock( &mutex1 );
    
    if (counter == 0){
        counter ++;
        printf("Waiting by %ld\n", pthread_self());
        pthread_cond_wait( &cond1, &mutex1 );
        printf("After Wait \n");
        printf("Thread %ld running in IF \n",pthread_self()); 
    }    
    else if (counter == 1){
        printf("Going to send signal in 3 seconds\n");
        /*printf("3...");
        sleep(1);
        printf("2...");
        sleep(1);
        printf("1...");
        sleep(1);*/
        pthread_cond_signal( &cond1 );
    }
    printf("Thread %ld running\n",pthread_self()); 
    pthread_mutex_unlock( &mutex1 );
}
    
    
    /*
    //pthread_mutex_lock( &mutex1 );
    //printf("Thread id : %ld\n", pthread_self());
    //char* msg = (char*) c;
    //printf("%s\n", msg);
    counter ++;
    printf("Counter : %i\n", counter);
    //pthread_mutex_unlock( &mutex1 );
    return NULL; 
    */






