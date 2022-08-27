// NON pre-emptive priority scheduling

# include <stdio.h>
# include <stdlib.h>

typedef struct{
    int pid;
    int arrival;
    int burst;
    int priority;
    int duration[2];
}P;


//P check_arrival(P a[], int count, int n);
int* arrived(P a[], int* tracker, int duration, int n);
P* priority(P a[], int* tracker, int n);

int main(void){
    int n;
    printf("Total Processes : ");
    scanf("%i", &n);

    P arr[n];
    int* tracker; //-1 for not arrived, 1 for arrived, 0 for completed executing
    tracker = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)tracker[i] = -1;

    int pid, burst, arrival;
    int starting_arrival = 10000;
    P* start = NULL;
    for (int i = 0; i < n; i++){
        printf("PID : ");
        scanf("%i", &(arr[i].pid));
        printf("Arrival : ");
        scanf("%i", &(arr[i].arrival));
        if (arr[i].arrival < starting_arrival)
            start = &arr[i];
            starting_arrival = arr[i].arrival;
        printf("Burst : ");
        scanf("%i", &(arr[i].burst));
        //printf("%i\n", start->burst);
        printf("Priority : ");
        scanf("%i", &(arr[i].priority));
        //printf("%i\n", arr[i].priority);
    }
    int duration = 0;
    for(int i = 0; i < n; i++){
        start -> duration[0] = duration;
        if(i == 0)
            printf("P%i --> %i-", start->pid, duration);
        else
            printf("P%i --> %i-", start->pid, duration + 1);
        duration = duration + start->burst;
        printf("%i\n", duration);
        start -> duration[1] = duration;
        tracker[start -> pid - 1] = 0;

        tracker = arrived(arr, tracker, duration, n);
        start = priority(arr, tracker, n);
        
    }
    free(tracker);
    return 0;
}

int* arrived(P a[], int* tracker, int duration, int n){
    for (int i = 0; i < n; i++){
        if ((tracker[i] != 0) && (duration >= a[i].arrival)){
            tracker[i] = 1;
        }
    }
    return tracker;
}
P* priority(P a[], int* tracker, int n){
    P*  next;
    int priority = 1000;
    for (int i = 0; i < n; i++){
        if ( (tracker[i] == 1) && (priority > a[i].priority) ){
            priority = a[i].priority;
            next = &a[i];
        }
    }
    return next;
}