#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter n : ");
    int n; scanf("%d",&n);
    int id[n],a[n],b[n];
    int vis[n];
    int start[n],end[n];
    int b_temp[n];
    int tot_time = 0;

    printf("A B\n");
    for(int i=0;i<n;i++){id[i] = i+1;scanf("%d %d",&a[i],&b[i]);vis[i] = 0;b_temp[i] = b[i];start[i] = -1;end[i] = -1;tot_time += b[i];}


    int t = 0;
    while(t != tot_time){
        int burst = 1000000;
        int j = -1;
        for(int i=0;i<n;i++){
            if(a[i] <= t && burst > b[i] && !vis[i]){
                burst = b[i];
                j = i;
            }
        }
        
        int id = j;
        int tt = b[j];
        
        while(1){
            int next = 1000000;
            for(int i=0;i<n;i++){
                if(a[i] < (t+tt) && !vis[i] && next > a[i]  &&  burst > b[i] ){//&& ((t + tt) - a[i]) > b[i]){
                    next = a[i];
                    id = i;
                }
            }
            
            if(start[j] == -1) start[j] = t;
            printf("P%i\n", j);
            if(id == j) break;
            
            int tmp = a[id] - t;
            b[j] = b[j] - tmp;
            t += tmp;
            tt = b[id];
            burst = b[id];
            j = id;
        }
        
        vis[id] = 1;
        t += b[id];
        end[id] = t;
    }
    
    printf("PID Start End\n");
    for(int i=0;i<n;i++)
    {
        printf("%3d %5d %3d\n",i+1,start[i],end[i]);
    }
    
    return 0;
}
// int main(void)
// {
//     printf("Enter Size : ");
//     int n; scanf("%d",&n);

//     int p_id[n+1],a_time[n+1],b_time[n+1],fixed_b[n+1];
//     int start[n+1],end[n+1];
//     int tot_time = 0;
//     int vis[n+1];

//     for(int i=1;i<=n;i++)
//     {
//         p_id[i] = i;
//         scanf("%d %d",&a_time[i],&b_time[i]);

//         start[i] = -1; 
//         end[i] = -1;

//         fixed_b[i] = b_time[i];
//         tot_time += b_time[i];
//         vis[i] = 0;
//     }

//     //Selecting Initial process 

//     int t = 0,tt = 0;
//     int id = -1;
//     int short_time = 1000000; //MAX


//     for(int i=1;i<=n;i++) {
//         if(!vis[i] && a_time[i] <= t && b_time[i] < short_time) {
//             short_time = b_time[i];
//             id = p_id[i];
//         }
//     }

//     tt = b_time[id];
//     int prev = id;

//     while(t != tot_time) 
//     {
//         int temp_tt = 100000;

//         if(start[id] == -1) {
//             start[id] = t;
//         }

//         for(int i=1;i<=n;i++) {
//             if(!vis[i] && a_time[i] < (t + tt) && a_time[i] < temp_tt && b_time[i] < short_time) {
//                 temp_tt = a_time[i];
//                 id = p_id[i];
//             }
//         }

//         if(id == prev) {
//             t += b_time[id];
//             end[id] = t;
//             vis[id] = 1;

//             short_time = 1000000;
//             id = -1;

//             for(int i=1;i<=n;i++) {
//                 if(!vis[i] && a_time[i] <= t && b_time[i] < short_time) {
//                     short_time = b_time[i];
//                     id = p_id[i];
//                 }
//             }

//             if(id == -1) break;

//             prev = id;
//             tt = b_time[id];
//             continue;
//         }

//         int temp = a_time[id] - t;
//         t += temp;
//         b_time[prev] = b_time[prev] - temp;
//         tt = b_time[id];
//         prev = id;
//         short_time = b_time[id];
//     }

//     printf("\nSA ST\n");
//     for(int i=1;i<=n;i++) {
//         printf("%2d %2d\n",start[i],end[i]);
//     }
 
//     printf("\nP_ID WT RT TAT\n");
//     for(int i=1;i<=n;i++) {
//         printf("%4d %2d %2d %3d\n",i,end[i] - a_time[i] - fixed_b[i],start[i] - a_time[i],end[i] - a_time[i]);
//     }

//     float avg_wt = 0,avg_rt = 0,avg_tat = 0;
//     for(int i=1;i<=n;i++) {
//         avg_wt += (end[i] - a_time[i] - fixed_b[i]);
//         avg_rt += (start[i] - a_time[i]);
//         avg_tat += (end[i] - a_time[i]);
//     }

//     printf("\nAverage Waiting time : %.2f\n",avg_wt/n*1.0);
//     printf("Average Response time : %.2f\n",avg_rt/n*1.0);
//     printf("Average Turnaround time : %.2f\n",avg_tat/n*1.0);

//     return 0;
// }

