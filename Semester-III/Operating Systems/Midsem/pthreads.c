# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <time.h>

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
int GSUM = 0;

typedef struct Elem{
    int id;
    int start;
    int end;
    int* arr;
}Elem;

int*  fill_array(int);
void* local_sum(void*);
void  print_array(int*, int);

// T : Number of threads
// N : Number of Elements
// j : jth Thread
int NumElems_to_Thread(int N, int j, int T){
    return (floor(N * (j + 1)/T) - floor(N * j/T));
}

int main(void){
    srand(time(NULL));
    int n;
    printf("Enter Elements in array : ");
    scanf("%i", &n);

    //Elem* Struct_arr[5];
    Elem** Struct_arr = (Elem**)malloc(sizeof(Elem*) * 5);

    for (int i = 0; i < 5; i++){
        Struct_arr[i] = (Elem*)malloc(sizeof(Elem));
    }

    int map[5];
    for (int i = 0; i < 5; i++)
        map[i] = NumElems_to_Thread(n, i, 5);

    pthread_t Thread_Arr[5];
    int* main_arr = fill_array(n);
    printf("\nArray : ");
    print_array(main_arr, n);
    printf("\n");

    int count = 0;
    for(int i = 0; i < 5; i++){
        Struct_arr[i] -> id = i + 1;
        Struct_arr[i] -> start = count;
        count += map[i];
        Struct_arr[i] -> end = count - 1;
        Struct_arr[i] -> arr = main_arr;
    }

    for (int i = 0; i < 5; i++){
        pthread_create(&Thread_Arr[i], NULL, local_sum, (void*)Struct_arr[i]);
    }
    for (int i = 0; i < 5; i++){
        pthread_join(Thread_Arr[i], NULL);
    }
    printf("Global SUM : %i\n", GSUM);

    free(Struct_arr);
    free(main_arr);

    return 0;
}

void* local_sum(void* S){
    pthread_mutex_lock( &m1 );

    Elem* S_local = (Elem*)S;
    int local_sum = 0;
    int range = S_local -> end - S_local -> start;
    for (int i = S_local -> start; i <= S_local -> end; i++){
        local_sum += S_local -> arr[i];
        printf("Thread id : %i, local add : %i\n", S_local -> id, S_local ->arr[i]);
    }
    
    printf("Local Sum : %i\n\n", local_sum);
    GSUM += local_sum;
    pthread_mutex_unlock( &m1 );
    return NULL;
}

int* fill_array(int n){
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        *(arr + i) = (rand() % 10) + 1;
    }
    return arr;
}

void print_array(int* arr, int n){
    printf("[");
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
    printf("]\n");
}