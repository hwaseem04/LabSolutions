# include <stdio.h>

int main(void){
    int n;
    printf("Processes : ");
    scanf("%i", &n);

    printf("A B P\n");
    int arrival[n], burst[n],b[n], priority[n], start[n], end[n], vis[n], tot_time = 0, tt = 0, t = 0, id;
    for (int i = 0; i < n; i++){
        scanf("%i %i %i", &arrival[i], &burst[i], &priority[i]);
        start[i] = -1; end[i] = -1; vis[i] = 0;
        b[i] = burst[i];
        tot_time += burst[i];
    }
    int prev = -1;
    while(t != tot_time){
        int prior = 100000;
        int j = -1;
        for (int i = 0; i < n; i++){
            if (arrival[i] <= t && !vis[i] && prior > priority[i]){
                prior = priority[i];
                j = i;
            }
        }

        tt = b[j];
        id = j;
        //if (prev != t)printf("%i\t", t);
        prev = t;
        printf("P%i\n", j); 
        while(1){
            int next= 100000;
            for (int i = 0; i < n; i++){
                if(!vis[i] && arrival[i] < (t + tt) && prior > priority[i] && next > arrival[i]){
                    next = arrival[i];
                    id = i;
                }
            }

            if (start[j] == -1) start[j] = t;
            printf("P%i\n", j); 
            if (id == j) break;

            //if (prev != t)printf("%i\t", t);
            prev = t;
            int tmp = arrival[id] - t;
            b[j] -= tmp;
            t += tmp;

            tt = b[id];
            j = id;
            prior = priority[id];
        }
        t += b[id];
        end[id] = t;
        vis[id] = 1;
    }
    //printf("%i\n", t);
    //printf("%i\n", t);
    for (int i = 0; i < n; i++)printf("start : %i, end : %i\n", start[i],end[i]);
    int wait, turn, resp;
    for (int i = 0; i < n; i++){
        turn += (end[i] - arrival[i]);
        resp += (start[i] - arrival[i]);
        wait += (end[i] - arrival[i] - burst[i]);
    }
    printf("WT %f\tRT %f\t TT %f\n", wait/(n*1.0), resp/(n*1.0), turn/(n*1.0));
}