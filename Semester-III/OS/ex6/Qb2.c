//SJF
# include <stdio.h>
# include <stdlib.h>


int main(void){
    int n;
    printf("Total processes : ");
    scanf("%i", &n);
    int arr[n][3];
    int finished[n];
    int start = -1;
    int min_arrival = 1000;
    for(int i = 0;i < n; i++){
        printf("Arrival, Burst time for process %i : ", i + 1);
        scanf("%i %i", &arr[i][1], &arr[i][2]);
        arr[i][0] = i + 1;
        finished[i] = 0;
        if (min_arrival > arr[i][1]){
            min_arrival = arr[i][1];
            start = i;
        }
    }
    int tt = 0;
    finished[start] = 1;
    printf("P%i --> 0 - %i\n", start + 1, arr[start][2]);

    tt += arr[start][2];
    int min_burst = 1000;
    for (int i = 0; i < n - 1; i++){
        min_burst = 1000;
        for (int j = 0; j < n; j++){
            if (!finished[j] && min_burst > arr[j][2]){
                start = j;
                min_burst = arr[j][2];
            }
        }
        finished[start] = 1;
        printf("P%i --> %i - %i\n", start + 1, tt, tt + arr[start][2]);
        tt += arr[start][2];
    }    

    return 0;
}
