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

void kruskal(int matrix[][v]){
    int min, x, y, a, b, c = 0;
    while(c < v - 1){
        min = inf;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
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

    int matrix[v][v];

    printf("Cost :\n");
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            scanf("%i", &matrix[i][j]);
            if (matrix[i][j] == 0){
                matrix[i][j] = inf;
            }
        }
    }
    printf("Edges : ");
    kruskal(matrix);
    return 0;
}