// NON pre-emptive priority scheduling

# include <stdio.h>

int main(void){
    int n;
    printf("processes : ");
    scanf("%i", &n);

    int arrival[n], burst[n], priority[n], start[n], id[n], end[n], vis[n];
    printf("A B P\n");

    int arr=1000, next;
    for (int i = 0; i < n; i++){
        scanf("%i %i %i", &arrival[i], &burst[i], &priority[i]);
        start[i] = -1;
        end[i] = -1;
        id[i] = i;
        vis[i] = 0;
        if (arr > arrival[i]){
            arr = arrival[i]; 
            next = i; 
        } 
        else if (arr == arrival[i]){ 
            if (priority[i] < priority[next] )
                next = i; 
        } 
    }

    printf("\n");
    int t = 0;
    start[next] = t; 
    //printf("P%i\n", next); // For process order
    printf("%i\t", t);
    t += burst[next];
    end[next] = t;
    vis[next] = 1;
    int count = 0;
    while(count < n - 1){
        int min_prior = 1000;
        for (int i = 0; i < n; i++){
            if (!vis[i] && min_prior > priority[i] && arrival[i] < t){
                min_prior = priority[i];
                next = i;
            }
        }
        start[next] = t;
        //printf("P%i\n", next); // For process order
        printf("%i\t", t);
        t += burst[next];
        end[next] = t;
        vis[next] = 1;
        count ++;
    }
    printf("%i\n", t);
}




// # include <stdlib.h>

// typedef struct{
//     int pid;
//     int arrival;
//     int burst;
//     int priority;
//     int duration[2];
// }P;


// //P check_arrival(P a[], int count, int n);
// int* arrived(P a[], int* tracker, int duration, int n);
// P* priority(P a[], int* tracker, int n);

// int main(void){
//     int n;
//     printf("Total Processes : ");
//     scanf("%i", &n);

//     P arr[n];
//     int* tracker; //-1 for not arrived, 1 for arrived, 0 for completed executing
//     tracker = (int*)malloc(sizeof(int) * n);
//     for(int i = 0; i < n; i++)tracker[i] = -1;

//     int pid, burst, arrival;
//     int starting_arrival = 10000;
//     P* start = NULL;

//     for (int i = 0; i < n; i++){
//         printf("PID, Arrival, Burst, Priority : ");
//         scanf("%i %i %i %i", &(arr[i].pid), &(arr[i].arrival), &(arr[i].burst), &(arr[i].priority));
//     }
//     int duration = 0;
//     for(int i = 0; i < n; i++){

//         tracker = arrived(arr, tracker, duration, n);
//         start = priority(arr, tracker, n);

//         start -> duration[0] = duration;

//         duration = duration + start->burst;

//         start -> duration[1] = duration;

//         tracker[start -> pid - 1] = 0;

//         printf("P%i --> %i - %i\n", start -> pid, start -> duration[0], start -> duration[1]);
//     }
//     free(tracker);
//     return 0;
// }

// int* arrived(P a[], int* tracker, int duration, int n){
//     for (int i = 0; i < n; i++){
//         if ((tracker[i] != 0) && (duration >= a[i].arrival)){
//             tracker[i] = 1;
//         }
//     }
//     return tracker;
// }
// P* priority(P a[], int* tracker, int n){
//     P*  next;
//     int priority = 1000;
//     for (int i = 0; i < n; i++){
//         if ( (tracker[i] == 1) && (priority > a[i].priority) ){
//             priority = a[i].priority;
//             next = &a[i];
//         }
//     }
//     return next;
// }