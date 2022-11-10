# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define left Pi
# define right (Pi + 1) % 5

int S[5];
pthread_mutex_t mutex[5];
pthread_cond_t cond[5];

void drop(int Pi){
    pthread_mutex_lock( &mutex[Pi] );
    S[Pi]++;
    pthread_mutex_unlock( &mutex[Pi] );
}

void pick(int Pi){
    while(S[Pi] <= 0);
    pthread_mutex_lock( &mutex[Pi] );
    S[Pi] --;
    pthread_mutex_unlock( &mutex[Pi] );
}

void* philosopher(void* P){
    int Pi = *(int*)P;
    printf("%i\n", Pi);
    printf("Philosopher %i Waiting for left chopstick\n", Pi);
    pick(left);
    printf("Philosopher %i Picked  left chopstick\n", Pi);
    
    printf("Philosopher %i Waiting for right chopstick\n", Pi);
    pick(right);
    printf("Philosopher %i Picked  right chopstick\n", Pi);
    
    sleep(2);
    printf("P%i COMPLETED\n", Pi);
    drop(right);
    drop(left);
}

int main(void){
    pthread_t T[5];
    int n[5];
    for (int i = 0; i < 5; i++){
        S[i] = 1;
    }
    for (int i = 0; i < 5; i++){
        n[i] = i;
        pthread_create( &T[i], NULL, philosopher, (void*)&n[i]);
    }
    for (int i = 0; i < 5; i++){
        pthread_join ( T[i], NULL);
    }
}

// # include <stdio.h>
// # include <pthread.h>
// # include <stdlib.h>
// # include <unistd.h>

// # define LEFT (Pi)
// # define RIGHT ((Pi + 1) % 5)

// pthread_mutex_t mutex[5] ;
// pthread_cond_t  cond[5] ;

// int* S;

// void Wait(int Pi){
//     // if (*(S + Pi) <= 0){
//     //     printf("IN- %i\n", Pi);
//     //     pthread_cond_wait( &cond[Pi], &mutex[Pi]);
//     //     printf("OUT- %i\n", Pi);
//     // }

//     while(*(S + Pi) <= 0) ; 
//     pthread_mutex_lock(&mutex[Pi]);
//     *(S + Pi) -= 1;  
//     pthread_mutex_unlock(&mutex[Pi]);
// }

// void Signal(int Pi){
//     //pthread_cond_signal( &cond[Pi]);
//     pthread_mutex_lock(&mutex[Pi]);
//     *(S + Pi) += 1;
//     pthread_mutex_unlock(&mutex[Pi]);
// }

// void* philosopher(void* i){
    
//     // Thinking
    
//     int Pi = *(int*)i;

//     //pthread_mutex_lock(&mutex[Pi]);
//     printf("%i\n", Pi);

//     //Hungry
//     printf("Philosopher %i Waiting for left chopstick\n", Pi);
//     Wait(LEFT);
//     printf("Philosopher %i PICKS left chopstick\n", Pi);
//     printf("Philosopher %i Waiting for right chopstick\n", Pi);
//     Wait(RIGHT);
//     printf("Philosopher %i PICKS right chopstick\n", Pi);
//     //pthread_mutex_unlock(&mutex[Pi]);
//     //Eat
//     printf("Philosopher %i started eating\n", Pi);

//     // Completed eating
//     sleep(2); //Meanwhile others try to eat, if say P1 eats then P0 and P2 cant eat, but P3,P4,P5 can eat

//     printf("Philosopher %i Completed eating\n", Pi);
//     // Give chopsticks back
//     Signal(LEFT);
//     Signal(RIGHT);

//     //Thinking starts
    
//     return NULL;
// }

// int main(void){
//     pthread_t t[5];
//     int n[5];
//     S = (int*)malloc(sizeof(int) * 5);
//     for (int i = 0; i < 5; i++){
//         *(S + i) = 1;
//     }
//     for (int i = 0; i < 5; i++){
//         n[i] = i;
//         pthread_create(&t[i], NULL, philosopher, (void*)(&n[i]));  // Cant use &i
//     }
//     for (int i = 0; i < 5; i++){
//         pthread_join( t[i], NULL);
//     }
//     return 0;
// }