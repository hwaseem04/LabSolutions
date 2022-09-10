# include <stdio.h>
# include <pthread.h>

# define MAX 4

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
    pthread_t p1, c1, p2, c2;

    pthread_create( &p1, NULL, produce, NULL );
    pthread_create( &c1, NULL, consume, NULL );
    pthread_create( &p2, NULL, produce, NULL );
    pthread_create( &c2, NULL, consume, NULL );

    pthread_join(p1, NULL);
    pthread_join(c1, NULL);
    pthread_join(p2, NULL);
    pthread_join(c2, NULL);

    return 0;
}

void* produce(void* dummy){
    int counter = 0;
    //while (counter < 10){
    pthread_mutex_lock( &mutex1 );
    
    if (isfull()) 
        pthread_cond_wait( &cond1, &mutex1 );

    if (counter < 10)
        enqueue();
    printf("Thread id : %ld produced %i\n", pthread_self() , rear);

    counter ++;

    pthread_mutex_unlock( &mutex1 );

    pthread_cond_signal( &cond1 );
    //}
}

void* consume(void* dummy){
    int counter = 0;
    //while(counter < 10){
    pthread_mutex_lock( &mutex1 );

    if (isempty())
        pthread_cond_wait( &cond1, &mutex1 );
    
    if (counter < 10)
        printf("Thread id : %ld consumed %i\n", pthread_self() , dequeue());

    counter ++;

    pthread_mutex_unlock( &mutex1 );

    pthread_cond_signal( &cond1 );
    //}
}