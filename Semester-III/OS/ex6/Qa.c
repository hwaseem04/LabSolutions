//FCFS

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

    P* arr = (P*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        printf("PID : ");
        scanf("%i", &(arr[i].pid));
        printf("Arrival : ");
        scanf("%i", &(arr[i].arrival));
        printf("Burst : ");
        scanf("%i", &(arr[i].burst));
    }

    arr = sort(arr, n);

    int time = 0;
    for (int i = 0; i < n; i++){
        if (i == 0) printf("P%i --> %i - %i\n", i + 1, time, time + arr[i].burst);
        else printf("P%i --> %i - %i\n", i + 1, time + 1, time + arr[i].burst);
        time += arr[i].burst;
    }
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