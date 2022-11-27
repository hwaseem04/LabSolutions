# include <stdio.h>

int v;

void Display(int matrix[][v]){
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
void bfs(int matrix[][v]){
    int visited[v];
    for(int i = 0; i < v; i++) visited[i] = -1;

    int queue[v];
    int front = -1;
    int rear = -1;

    int s;
    printf("Start vertex  : ");
    scanf("%i", &s);

    visited[s - 1] = 1;
    queue[++rear] = s;
    front++;
    while(front <= rear){
        printf("%i ", queue[front]);
        for(int i = 0; i < v; i++){
            if ((matrix[queue[front]-1][i] == 1) && visited[i] == -1 ){
                visited[i] = 1;
                queue[++rear] = i + 1;
            }
        }
        front++;
    }
    printf("\n");
    return;
}

int main(void){
    int e;
    printf("# of vertices : ");
    scanf("%i", &v);

    printf("# of edges : ");
    scanf("%i", &e);

    int v1,v2;
    int matrix[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v;j ++){
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++){
        printf("Edge %i (from to) : ", i+1);
        scanf("%i %i", &v1, &v2);
        matrix[v1-1][v2-1] = 1;
        matrix[v2-1][v1-1] = 1;
    }
    Display(matrix);
    bfs(matrix);
    return 0;
}