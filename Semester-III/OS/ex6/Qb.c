// SJF

# include <stdio.h>
# include <stdlib.h>

typedef struct{
    int pid;
    int burst;
    int arrival;
}P;

P* sort(P* a, int n);


int main(void){
    int n;

    printf("Number of Processes : ");
    scanf("%i", &n);

    P* arr = (P*)malloc(sizeof(P) * n);   
    int* tracker = (int*)malloc(sizeof(int) * n);
    
    P* start = (P*)malloc(sizeof(P));
    

    int min = 1000;
    for (int i = 0; i < n; i++){
        printf("PID : ");
        scanf("%i", &(arr[i].pid));
        printf("Arrival : ");
        scanf("%i", &(arr[i].arrival));
        printf("Burst : ");
        scanf("%i", &(arr[i].burst));
        //printf("%i %i %i\n", arr[i].pid, arr[i].arrival, arr[i].burst);
    }

    printf("\n");
    arr = sort(arr, n);

    for(int i = 0; i < n; i++) {
        //printf("%i %i\n", arr[i].arrival, arr[i].burst);
        tracker[i] = -1;
    }
    int time = 0;
    int min_burst, count, current_arr;
    printf("\n");
    for (int i = 0; i < n; i++){
        count = 0;
        for (int j = 0; j < n; j++){
            //printf("burst : %i, arrival %i\n",arr[j].burst, arr[j].arrival);
            if ((tracker[j] == -1) && (count == 0)){
                //printf("Inside 1\n");
                start = &arr[j];
                current_arr = arr[j].arrival;
                min_burst = arr[j].burst;
                count = 1;
                tracker[j] = 0;
                //printf("current pid %i, current Arrival %i, min burst %i \n",start->pid, current_arr, min_burst);
                /*printf("tracker: ");
                for(int i = 0; i < n; i++){
                    printf("%i ", tracker[i]);
                }
                printf("\n");*/
            }
            else if ((min_burst > arr[j].burst) && (current_arr == arr[j].arrival) && (tracker[j] == -1)){
                //printf("Inside 2\n");
                tracker[start->pid - 1] = -1;
                start = &arr[j];
                min_burst = arr[j].burst;
                tracker[start->pid - 1] = 0;
                //printf("current pid %i, current Arrival %i, min burst %i \n",start->pid, current_arr, min_burst);
            }
            else if (current_arr != arr[j].arrival){
                //printf("Inside 3\n");
                break;
            }
        }
        /*for(int i = 0; i < n; i++){
            printf("%i ", tracker[i]);
        }
        printf("\n");*/
        if (i == 0) printf("P%i --> %i - %i\n", start->pid, time, time + start -> burst);
        else  printf("P%i --> %i - %i\n", start->pid, time + 1, time + start -> burst);
        printf("\n");
        time += start -> burst;
    }

    return 1;
}

P* sort(P* a, int n){
    int tmp;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j].arrival > a[j + 1].arrival){
                tmp = a[j].arrival;
                a[j].arrival = a[j+1].arrival;
                a[j+1].arrival = tmp;
            }
        }
    }
    return a;
}