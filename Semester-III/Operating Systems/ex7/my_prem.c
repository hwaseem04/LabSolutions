# include <stdio.h>

int main(void){
    int n;
    printf("Total processes : ");
    scanf("%i", &n);

    int start[n], end[n], arrival[n], priority[n], burst[n], b[n], vis[n];
    int total_time = 0;
    printf("Arrival Burst Priority\n");
    for(int i = 0; i < n; i++){
        scanf("%i %i %i", &arrival[i], &burst[i], &priority[i]);
        b[i] = burst[i];
        start[i] = -1;
        end[i] = -1;
        total_time += burst[i];
        vis[i] = 0;
    }

    int t = 0;
    int prior, inter;
    int j, id;
    int tt, tmp;
    
    while(t != total_time){
        prior = 100000;
        j = -1;
        for (int i = 0; i < n; i++){
            if (prior > priority[i] && arrival[i] <= t && (!vis[i])){
                prior = priority[i];
                j = i;
            }
        }
        //printf("%i\t", t);
        tt = b[j];
        id = j;
        printf("P%i\n", j); 
        while(1){
            int inter_arr = 100000;
            
            for (int i = 0; i < n; i++){
                if (arrival[i] < t + tt && prior > priority[i] && inter_arr > arrival[i] && (!vis[i])){
                    inter_arr = arrival[i];
                    id = i;
                }
            }
            if (start[j] == -1) start[j] = t;
            printf("P%i\n", j);   // Uncomment this if you want to print process
            if (id == j)break;
            
            tmp = arrival[id] - t;
            b[j] = b[j] - tmp;

            t += tmp;
            //printf("%i\t", t);
            tt = b[id];
            prior = priority[id];
            j = id;
            
        }
        vis[id] = 1;
        t += b[id];
        end[id] = t;
    
    }
    //printf("%i\n", t);
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