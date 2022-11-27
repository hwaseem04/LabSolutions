# include <stdio.h>
# include <stdlib.h>

# define inf 9999


int v;
void prims(int matrix[][v]){
    //int inf = 9999;
    int min, x, y;

    int selected[v];
    for(int i = 0; i < v; i++) selected[i] = 0;

    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if ((matrix[i][j] < min) && matrix[i][j]){
                min = matrix[i][j];
                y = i;
            }
        }
    }
    int c = 0;

    while(c < v - 1){
        selected[y] = 1;
        min = inf;
        x = 0;
        y = 0;
        for (int i = 0; i< v; i++){
            if (selected[i]){
                for(int j = 0; j < v; j++){
                    if(!selected[j] && matrix[i][j]){
                        if(min > matrix[i][j]){
                           min = matrix[i][j];
                           x = i;
                           y = j;
                        }
                    }
                }
            }
        }
        printf("%i ", min);
        c++;
    }
}
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

void create_graph(int a, int graph[][a]){
    int n;
    printf("# of edges : ");
    scanf("%i", &n);
    int v1,v2,w;
    for(int i = 0; i < n; i++){
        printf("Edge %i (from, to) : ", i + 1);
        scanf("%i %i", &v1,&v2);

        printf("Weight : ");
        scanf("%i", &w);

        graph[v1-1][v2-1] = w;
        graph[v2-1][v1-1] = w;
    }
    return;
}


int main(void){

    v = 7;
    int graph[v][v];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            graph[i][j] = 0;
        }
    }
    create_graph(v,graph);
    display(v,graph);

    prims(graph);
    return 0;
}


/*void prims(int a, int graph[][a]){
    int i = 0;
    int selected[v];
    for(int m = 0; m < v; m++) selected[m] = 0;
    selected[0] = 1;
    int min,x,y;
    while (i < v - 1){
        min = inf;
        x = 0;
        y = 0;
        for(int j = 0; j < v; j++){
            if (selected[j]){
                for(int k = 0; k < v; k++){
                    if(!selected[k] && graph[j][k]){
                        if (min > graph[j][k]){
                            min = graph[j][k];
                            x = j;
                            y = k;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        printf("%i ", graph[x][y]);
        i++;
    }
    printf("\n");
    return;
}*/