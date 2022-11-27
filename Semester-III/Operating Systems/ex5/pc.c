# include <stdio.h>
# include <pthread.h>

# define MAX 6

int buffer[MAX];
int front = -1, rear = -1;
//int counter = 0;
int flag = 0;
int flag2 = 1;

void* produce(void*);
void* consume(void*);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond1  = PTHREAD_COND_INITIALIZER;

int isempty(){
    if (front == -1 && rear == -1) return 1;
    else return 0;
}
int isfull(){
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1))) return 1;
    else return 0;
}

void enqueue(){
    if (isempty()){
        front ++;
        rear ++;
        buffer[rear] = rear;
    }
    else if(!isfull()){
        rear = (rear + 1) % MAX;
        buffer[rear] = rear;
    }
}

int dequeue(){
    if(rear == front){
        int d = buffer[front];
        front = -1;
        rear = -1;
        return d;
    }
    else{
        int d = buffer[front];
        front = (front + 1) % MAX;
        return d;
    }
}

int main(void){
    pthread_t p1, c1, p2, c2, p3, c3;

    pthread_create( &p1, NULL, produce, NULL );
    pthread_create( &c1, NULL, consume, NULL );
    pthread_create( &p2, NULL, produce, NULL );
    pthread_create( &c2, NULL, consume, NULL );
    pthread_create( &p3, NULL, produce, NULL );
    pthread_create( &c3, NULL, consume, NULL );
    pthread_join(p1, NULL);
    pthread_join(c1, NULL);
    pthread_join(p2, NULL);
    pthread_join(c2, NULL);
    pthread_join(p3, NULL);
    pthread_join(c3, NULL);
    return 0;
}






void* produce(void* dummy){

    pthread_mutex_lock( &mutex1 );
    
    if (isfull()) 
        pthread_cond_wait( &cond1, &mutex1 );

    enqueue();
    printf("Thread id : %li produced %i\n", (long)pthread_self() , rear);

    pthread_mutex_unlock( &mutex1 );

    pthread_cond_signal( &cond1 );
    return NULL;
}

void* consume(void* dummy){
    pthread_mutex_lock( &mutex1 );

    if (isempty())
        pthread_cond_wait( &cond1, &mutex1 );

    printf("Thread id : %li consumed %i\n", (long)pthread_self() , dequeue());

    pthread_mutex_unlock( &mutex1 );

    pthread_cond_signal( &cond1 );
    return NULL;
}