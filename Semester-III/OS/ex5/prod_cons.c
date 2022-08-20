# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

# define MAX 4

int buffer[MAX];
int front = -1, rear = -1;
int counter = 0;
int flag = 0;

void* produce(void*);
void* consume(void*);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond1  = PTHREAD_COND_INITIALIZER;

int isempty(){
    if (front == -1 && rear == -1) return 1;
    else return 0;
}
int isfull(){
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) return 1;
    else return 0;
}

void enqueue(int e){
    if (isempty()){
        rear ++;
        buffer[++front] = e;
    }
    else if(!isfull()){
        rear = (rear + 1) % MAX;
        buffer[rear] = e;
    }
}

int dequeue(){
    /*if (isempty()){
        return -1;
    }*/
    if(rear == front){
        int d = buffer[rear];
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
    
    pthread_t p1,p2,p3,p4,p5, c1,c2,c3,c4,c5;
    pthread_create( &p1, NULL, produce, NULL );
    /*pthread_create( &p2, NULL, produce, NULL );
    pthread_create( &p3, NULL, produce, NULL );
    pthread_create( &p4, NULL, produce, NULL );
    pthread_create( &p5, NULL, produce, NULL );
    
    pthread_create( &c1, NULL, consume, NULL );
    pthread_create( &c2, NULL, consume, NULL );
    pthread_create( &c3, NULL, consume, NULL );
    pthread_create( &c4, NULL, consume, NULL );*/
    pthread_create( &c5, NULL, consume, NULL );
    
    pthread_join(p1, NULL);
    /*pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    pthread_join(p5, NULL);
    
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
    pthread_join(c3, NULL);
    pthread_join(c4, NULL);*/
    pthread_join(c5, NULL);
    
    return 0;
} 

void* produce(void* dummy){
    while(counter < 20){
        pthread_mutex_lock( &mutex1 );
        
        if (isfull()){
            flag = 1;
            pthread_cond_wait( &cond1, &mutex1 );
            enqueue(counter++);
            printf("Produced (After Wait) %i\n", buffer[rear]);
        }
        else if(flag == 2){
            flag = 0;
            enqueue(counter++);
            printf("Produced (coz of empty) %i\n", buffer[rear]);
            pthread_cond_signal( &cond1 );
        }
        else{
            enqueue(counter++);
            printf("Produced %i\n", buffer[rear]);
        }
        pthread_mutex_unlock( &mutex1 );
    }
}

void* consume(void* dummy){
    while(counter < 20){
        pthread_mutex_lock( &mutex1 );
        
        if (flag == 1){
            flag = 0;
            printf("Consumed (coz of full) %i\n", dequeue());
            pthread_cond_signal( &cond1 );
        }
        else if ( isempty() ){
            flag = 2;
            pthread_cond_wait( &cond1, &mutex1 );
            printf("Consumed (After wait) %i\n", dequeue());
        }
        else{
            printf("Consumed %i\n", dequeue());
        }
        pthread_mutex_unlock( &mutex1 );
    }
}





















