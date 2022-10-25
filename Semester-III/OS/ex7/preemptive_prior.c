# include <stdio.h>
# include <stdlib.h>


int main(void){
    int n;
    printf("Total Processes : ");
    scanf("%i", &n);

    int arr[n][4];
    int finished[n];
    int total_time = 0;
    int start = -1;
    int min = 1000;
    int priority = 1000;
    for (int i = 0; i < n; i++){
        printf("Arrival time, burst time, priority : ");
        scanf("%i %i %i", &arr[i][1],&arr[i][2],&arr[i][3]);
        arr[i][0] = i + 1;
        finished[i] = 0;
        if (arr[i][1] < min){
            min = arr[i][1];
            start = i;
            priority = arr[i][3];
        }
        total_time += arr[i][2];
    }
    int tt = 0;

    while(tt <= total_time){
        for (int i = 0; i < n; i++){
            if (!finished && (arr[i][3] < priority) && (arr[i][1] < tt + arr[start][2])){
                
            }
        }
    }

    return 0;
}