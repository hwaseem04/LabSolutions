# include <stdio.h>

int v;

void display(int a, int matrix[][a]){
    printf("\t");
    for(int i = 0; i < v; i++) printf("%i\t", i+1);
    printf("\n");
    for (int i = 0; i < v; i++){
        printf("%i\t", i+1);
        for (int j = 0; j < v; j++){
            printf("%i\t", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void dfs(int s, int matrix[][v], int* visited){
    printf("%i ", s);
    visited[s-1] = 1;
    for(int i = 0; i < v; i++){
        if (visited[i] != 1 && matrix[s-1][i])
            dfs(i+1, matrix, visited);
    }
    return;
}


int main(void){

    printf("# of vertices : ");
    scanf("%i", &v);

    int adj_matrix[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            adj_matrix[i][j] = 0;
        }
    }
    int n;
    printf("# of edges : ");
    scanf("%i", &n);

    int v1, v2;
    for (int i = 0; i < n; i++){
        printf("Edge %i (from to) : ", i + 1);
        scanf("%i %i", &v1, &v2);
        v1 --;
        v2 --;
        adj_matrix[v1][v2] = 1;
        //For undirected
        adj_matrix[v2][v1] = 1;
    }
    display(v,adj_matrix);

    int visited[v];
    for(int i = 0; i < v; i++) visited[i] = 0;

    int s;
    printf("Start vertex : ");
    scanf("%i", &s);

    dfs(s,adj_matrix, visited);
    printf("\n");
    return 0;
}