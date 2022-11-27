#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    printf("Processes : ");
    scanf("%i", &n);
    printf("A B\n");
    int arrival[n], burst[n], b[n], start[n], end[n], vis[n], total_time, t=0, tt=0;
    for (int i = 0; i < n; i++){
        scanf("%i %i", &arrival[i], &burst[i]);
        b[i] = burst[i];
        start[i] = -1; end[i] = -1;
        total_time += burst[i];
        vis[i] = 0;
    }

    int j, id, prev_t=-1;
    while(t != total_time){
        int burst = 100000;
        int j = -1;
        for (int i = 0; i < n; i++){
            if (arrival[i] <= t && burst > b[i] && !vis[i]){
                burst = b[i];
                j = i;
            }
        }

        id = j;
        tt = b[j];

        if (t != prev_t) printf("%i\t", t);
        prev_t = t;
        
        while(1){
            int shorter = 100000;
            for (int i = 0; i < n; i++){
                if (arrival[i] < (t + tt)  &&  shorter > arrival[i] && burst > b[i] && !vis[i]){
                    shorter = arrival[i];
                    id = i;
                }
            }

            if (start[j] == -1) start[j] = t;
            //printf("P%i\n", j); //To print process
            if (id == j) break;
            
            
            int tmp =  arrival[id] - t;
            b[j] = b[j] -  tmp;
            t += tmp;

            if (t != prev_t) printf("%i\t", t);
            prev_t = t;

            tt = b[id];
            burst = b[id];
            j = id;
        }
        vis[id] = 1;
        t += b[id];
        end[id] = t;
    }
    printf("%i\n", t);
    printf("PID Start End\n");
     for(int i=0;i<n;i++)
     {
         printf("%3d %5d %3d\n",i+1,start[i],end[i]);
     }
    
 }


// int main()
// {
//     printf("Enter n : ");
//     int n; scanf("%d",&n);
    
//     int id[n],a[n],b[n];
//     int vis[n];
    
//     int start[n],end[n];
//     int b_temp[n];
//     int tot_time = 0;
    
//     printf("A B\n");
//     for(int i=0;i<n;i++)
//     {
//         id[i] = i+1;
//         scanf("%d %d",&a[i],&b[i]);
        
//         vis[i] = 0;
//         b_temp[i] = b[i];
        
//         start[i] = -1;
//         end[i] = -1;
        
//         tot_time += b[i];
//     }
    
//     int t = 0;
    
//     while(t != tot_time)
//     {
//         int burst = 1000000;
//         int j = -1;
        
//         for(int i=0;i<n;i++)
//         {
//             if(a[i] <= t && burst > b[i] && !vis[i])
//             {
//                 //printf("%i\t", i);
//                 burst = b[i];
//                 j = i;
//             }
//         }
        
//         int id = j;
//         int tt = b[j];
        
//         while(1)
//         {
//             int next = 1000000;
            
//             for(int i=0;i<n;i++)
//             {
//                 if(a[i] < (t+tt) && !vis[i] && next > a[i]  &&  burst > b[i] )//&& ((t + tt) - a[i]) > b[i])
//                 {
//                     next = a[i];
//                     id = i;
//                 }
//             }
            
//             if(start[j] == -1) start[j] = t;
//             printf("P%i\n", j);
//             if(id == j) break;
            
            
//             int temp = a[id] - t;
//             b[j] = b[j] - temp;
//             t += temp;
//             tt = b[id];
//             burst = b[id];
//             j = id;
//         }
        
//         vis[id] = 1;
//         t += b[id];
//         end[id] = t;
//     }
    
//     printf("PID Start End\n");
//     for(int i=0;i<n;i++)
//     {
//         printf("%3d %5d %3d\n",i+1,start[i],end[i]);
//     }
    
//     return 0;
// }
