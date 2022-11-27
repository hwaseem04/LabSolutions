//FCFS

# include <stdio.h>

int main(void){
    int n;
    printf("processes : ");
    scanf("%i", &n);

    int arrival[n], burst[n], start[n], id[n], end[n];
    printf("A B\n");
    for (int i = 0; i < n; i++){
        scanf("%i %i", &arrival[i], &burst[i]);
        start[i] = -1;
        end[i] = -1;
        id[i] = i;
    }
    int tmp;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arrival[j] > arrival[j + 1]){
                tmp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j+1] = tmp;

                tmp = burst[j];
                burst[j] = burst[j + 1];
                burst[j+1] = tmp;

                tmp = id[j];
                id[j] = id[j + 1];
                id[j+1] = tmp;
            }
        }
    }
    printf("\n");
    int t = 0;
    for (int i = 0; i < n; i++){
        start[i] = t;
        //printf("P%i\n", i);// To print process order
        printf("%i\t", t); // For gant chart
        t += burst[i];
        end[i] = t;
    }
    printf("%i\n", t); // For Gant chart
    for (int i = 0; i < n; i++)printf("start : %i, end : %i\n", start[i],end[i]);
    float wT = 0;
    float tT = 0;
    float rT = 0;
    float tp = 0; //Turn - burst ;
                            
    for (int i = 0; i < n; i++){
        rT += (start[i] - arrival[i]);
        tp = (end[i] - arrival[i]);
        tT += tp;
        wT += (tp - burst[i]);
    }
    printf("wT : %f, tT : %f, rT : %f\n", wT/n, tT/n, rT/n);
}







// # include <stdio.h>
// # include <stdlib.h>

// typedef struct{
//     int pid;
//     int burst;
//     int arrival;
// }P;


// P* sort(P* a, int n);

// int main(void){
//     int n;

//     printf("Number of Processes : ");
//     scanf("%i", &n);

//     P* arr = (P*)malloc(sizeof(int) * n);

//     for (int i = 0; i < n; i++){
//         printf("PID : ");
//         scanf("%i", &(arr[i].pid));
//         printf("Arrival : ");
//         scanf("%i", &(arr[i].arrival));
//         printf("Burst : ");
//         scanf("%i", &(arr[i].burst));
//     }

//     arr = sort(arr, n);

//     int time = 0;
//     for (int i = 0; i < n; i++){
//         if (i == 0) printf("P%i --> %i - %i\n", i + 1, time, time + arr[i].burst);
//         else printf("P%i --> %i - %i\n", i + 1, time + 1, time + arr[i].burst);
//         time += arr[i].burst;
//     }
// }

// P* sort(P* a, int n){
//     int tmp;
//     for (int i = 0; i < n - 1; i++){
//         for (int j = 0; j < n - i - 1; j++){
//             if (a[j].arrival > a[j + 1].arrival){
//                 tmp = a[j].arrival;
//                 a[j].arrival = a[j+1].arrival;
//                 a[j+1].arrival = tmp;
//             }
//         }
//     }
//     return a;
// }