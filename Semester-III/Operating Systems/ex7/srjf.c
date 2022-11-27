#include <stdio.h>
// 2 6 
// 5 2
// 1 8
// 0 3
// 4 4
int main(){
    int n;
    printf("Process : ");
    scanf("%i", &n);
    int cont = 0;
    printf("A B\n");
    int arrival[n], burst[n], b[n], start[n], end[n], vis[n], total_time, t=0, tt=0, id;
    for (int i = 0; i < n; i++){
        scanf("%i %i", &arrival[i], &burst[i]);
        start[i] = -1; end[i] = -1; vis[i] = 0;
        b[i] = burst[i];
        total_time += burst[i];
    }

    while(t != total_time){
        int burst = 10000;
        int j = -1;
        for (int i = 0; i < n; i++){
            if (arrival[i] <= t && b[i] < burst && !vis[i]){
                burst = b[i];
                j = i;
            }
        }

        tt = b[j];
        id = j;
        
        while(1){
            int next = 10000;
            for (int i = 0; i < n; i++){
                if (arrival[i] < (t + tt) && next > arrival[i] && burst > b[i] && !vis[i]){
                    next = arrival[i];
                    id = i;
                }
            }
            cont ++;
            if (cont >= 10) break;
            if (start[j] == -1) start[j] = t ;
            printf("j : %i, id : %i\n", j, id);
            if (id == j) break;
            
            int tmp = arrival[id] - t;
            b[j] -= tmp;
            t += tmp;

            burst = b[id];
            tt = b[id];
            j = id; 
        }
        t += b[id];
        vis[id] = 1;
        end[id] = t;
    }
}