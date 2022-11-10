# include <stdio.h>

int main(void){
    int n;
    printf("Processes : ");
    scanf("%i", &n);

    int arrival[n], burst[n], b[n], start[n], end[n, vis[n]];
    int total_time;
    printf("A B\n");
    for (int i = 0; i < n; i++){
        scanf("%i %i", &arrival[i], &burst[i]);
        start[i] = -1;
        end[i] = -1;
        b[i] = burst[i];
        total_time += burst[i];
        vis[i] = 0;
    }
    int id, j, tmp;
    int t;
    int tt;
    int min_time, temp_min_arr;
    while(t != total_time){
        min_time = 10000;
        for (int i = 0; i < n; i++){
            if (arrival[i] <= t && min_time > b[i] && !vis[i]){
                min_time = b[i];
                j = i;
            }
        }
        tt = min_time
        id = j;
        while(1){
            temp_min_arr = 10000;
            for (int i = 0; i < n; i++){
                if (arrival[i] < t + tt && !vis[i] && b[i] < (tt - (arrival[i] - t)) && temp_min_arr > arrival[i]){
                    temp_min_arr = arrival[i];
                    id = i;
                }
            }
            if (start[j] == -1) start[j] = t;

            if (id == j)break;
            tmp = arrival[i] - t;
            b[id] -= tmp;

            t += tmp;
            tt = b[id];
            j = id;
        }
        t += b[id];
        end[id] = t
        vis[id] = 1;
    }
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