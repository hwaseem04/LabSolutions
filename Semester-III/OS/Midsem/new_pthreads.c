# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <time.h>

int*  fill_array(int);
void* local_sum(void*);
void  print_array();

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;
int index_t = 0;
int n = 0;
int* arr;
int* map;
int GSUM;
pthread_t* Thread_Arr;
int* Thread_id;

int NumElems_to_Thread(int N, int j, int T){
    return (floor(N * (j + 1)/T) - floor(N * j/T));
}

int main(void){

    printf("Size of array : ");
    scanf("%i", &n);

    arr = (int*)malloc(sizeof(int) * n);
    arr = fill_array(n);
    printf("Array : ");
    print_array();

    Thread_id = (int*)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
        Thread_id[i] = i + 1;

    map = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < 5; i++){
        map[i] = NumElems_to_Thread(n, i, 5);
        printf("MAP : %i\n", map[i]);
    }
    printf("\n");

    Thread_Arr = (pthread_t*)malloc(sizeof(pthread_t) * 5);

    for (int i = 0; i < 5; i++){
        pthread_create(&Thread_Arr[i], NULL, local_sum, NULL);
    }
    for (int i = 0; i < 5; i++){
        pthread_join(Thread_Arr[i], NULL);
    }
    printf("Global SUM : %i\n", GSUM);

    free(map);
    free(arr);
    return 0;
}

void* local_sum(void* dummy){
    int start, end;
    //printf("%d\n", index_t);
    pthread_mutex_lock( &m2 );
    start = counter;
    counter += map[index_t];
    index_t++;
    end = counter - 1;
    pthread_mutex_unlock( &m2 );

    int local_sum = 0;
    int range =  end - start;
    for (int i = start; i <=  end; i++){
        local_sum += arr[i];
        //printf("Thread id : %i, local add : %i\n", Thread_id[index_t - 1], arr[i]);
    }
    
    printf("Local Sum : %i\n\n", local_sum);

    pthread_mutex_lock( &m1 );
    GSUM += local_sum;
    pthread_mutex_unlock( &m1 );
    return NULL;
}

int* fill_array(int n){
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        //*(arr + i) = (rand() % 10) + 1;
        *(arr + i) = i + 1;
    }
    return arr;
}

void print_array(){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
    printf("]\n");
}