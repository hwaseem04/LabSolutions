# include <stdio.h>

int parent[9];
# define inf 999
int v;

int find(int u){
    while(parent[u])
        u = parent[u];
    return u;
}

int uni(int x, int y){
    if (x != y){
        parent[y] = x;
        return 1;
    }
    return 0;
}

void kruskal(int matrix[][v+1]){
    int min, x, y, a, b, c = 0;
    while(c < v - 1){
        min = inf;
        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; j++){
                if (matrix[i][j] < min){
                    min = matrix[i][j];
                    x = a = i;
                    y = b = j;
                }
            }
        }
        a = find(a);
        b = find(b);
        if(uni(a,b)){
            c++;
            printf("%i ", min);
        }
        matrix[x][y] = inf, matrix[y][x] = inf;
    }
    printf("\n");
}

int main(void){
    printf("Enter vertices : ");
    scanf("%i", &v);

    int matrix[v+1][v+1];

    printf("Cost :\n");
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            scanf("%i", &matrix[i][j]);
            if (matrix[i][j] == 0){
                matrix[i][j] = inf;
            }
        }
    }
    printf("Edges : ");
    kruskal(matrix);
    printf("Parent : ");
    for(int i = 1; i <= v; i++) printf("%i ", parent[i]);
    printf("\n");
    return 0;
}





/*
#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main(void)
{
    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    //printf("%i ", min);
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);  //Finding parent
        v = find(v);

        if (uni(u, v)) //Making union if they have different parent
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    printf("Parent : ");
    for(i = 1; i <= n; i++)
        printf("%i ", parent[i]);
    printf("\n");
    return 0;
}

int find(int y)
{
    while (parent[y])
        y = parent[y];
    return y;
}

int uni(int y, int z)
{
    if (y != z)
    {
        parent[z] = y;
        return 1;
    }
    return 0;
}

*/