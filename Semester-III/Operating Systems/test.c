#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#define LEFT Pi
#define RIGHT (Pi+1)%5
pthread_mutex_t m;
int* s;
void Wait(int x)
{
    while(s[x]<=0);
    pthread_mutex_lock(&m);
    s[x]-=1;
    pthread_mutex_unlock(&m);
}
void Signal(int x)
{
    pthread_mutex_lock(&m);
    s[x]+=1;
    pthread_mutex_unlock(&m);
}
void* philosopher(void *i)
{
    int Pi=*(int*) i;
    printf("P%d is waiting for left chopstick",Pi);
    Wait(LEFT);
    printf("P%d is waiting for right chopstick",Pi);
    Wait(RIGHT);
    printf("P%d is eating",Pi);
    sleep(2);
    Signal(LEFT);
    Signal(RIGHT);
}
int main()
{
    int n[5];
    pthread_t t[5];
    s=(int*) malloc(5*sizeof(int));
    for(int i=0;i<5;i++)
    {
        s[i]=n[i]=1;
        pthread_create(&t[i],NULL,philosopher,(void*)n[i]);
    }
    for(int i=0;i<5;i++) pthread_join(t[i],NULL);
}