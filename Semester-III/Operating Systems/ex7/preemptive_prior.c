#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter n : ");
    int n; scanf("%d",&n);
    
    int id[n],a[n],b[n],p[n];
    int vis[n];
    
    int start[n],end[n];
    int b_temp[n];
    int tot_time = 0;
    
    printf("A B P\n");
    for(int i=0;i<n;i++)
    {
        id[i] = i+1;
        scanf("%d %d %d",&a[i],&b[i],&p[i]);
        
        vis[i] = 0;
        b_temp[i] = b[i];
        
        start[i] = -1;
        end[i] = -1;
        
        tot_time += b[i];
    }
    
    int t = 0;
    
    while(t != tot_time)
    {
        int priority = 1000000;
        int j = -1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] <= t && priority > p[i] && !vis[i]) // priority > p[i] doubt --> here & below
            {      
                //printf("Test1\n");
                priority = p[i];
                j = i;
            }
        }

        int id = j;
        int tt = b[j];
        
        while(1)
        {
            int next = 1000000;
            
            for(int i=0;i<n;i++)
            {
                if(a[i] < (t+tt)  && !vis[i] && next > a[i]  &&  priority > p[i]) //Usage of next doubt
                {
                    //printf("Test2\n");
                    next = a[i];
                    id = i;
                }
            }
            
            if(id == j) break;
            
            printf("%d ",j);
            
            int temp = a[id] - t; //Doubt
            b[j] = b[j] - temp;
            t += temp;

            //preempting current process for next process
            tt = b[id];
            priority = p[id];
            j = id;
        }
        vis[id] = 1;
        t += b[id];
        printf("%d ",id);
    }
    
    printf("\n");
    return 0;
}