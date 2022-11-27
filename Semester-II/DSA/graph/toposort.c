# include <stdio.h>


int v;

int iszero(int* indegree){
    for (int i = 0; i < v; i++){
        if (indegree[i] != 0)
            return 0;
    }
    return 1;
}

void toposort(int graph[][v]){
    int indegree[v];
    for (int i = 0; i < v; i++) indegree[i] = 0;
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            if (graph[i][j]){
                indegree[j] ++;
            }
        }
    }
    int stack[v];
    int top = -1;

    for (int i = 0; i < v; i++){
        if (indegree[i] == 0){
            stack[++top] = i;
        }
    }
    while (!iszero(indegree)){

        int t = stack[top--];
        printf("%i ", t);
        for (int i = 0; i < v; i++){
            if (graph[t][i] && indegree[i]){
                indegree[i] --;
                if (indegree[i] == 0)
                    stack[++top] = i;
            }
        }
    }
    while (top != -1)
        printf("%i ", stack[top--]);
    printf("\n");
    return;
}

int main(void){
    printf("# of Vertices : ");
    scanf("%i", &v);
    int graph[v][v];
    printf("Adjacency matrix : ");
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            scanf("%i", &(graph[i][j]));
        }
    }
    printf("Order : ");
    toposort(graph);
    return 0;
}