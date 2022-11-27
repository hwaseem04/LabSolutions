# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int vertex;
    struct node* next;
}node;

int v;

void bfs(node* list[]){
    node* queue[v];
    int front = -1, rear = -1;

    int s;
    printf("Start vertex : ");
    scanf("%i", &s);

    queue[++rear] = list[s - 1];
    front++;

    int visited[v];
    for(int i = 0; i < v; i++) visited[i] = 0;
    visited[(list[s - 1] -> vertex) - 1] = 1;

    node* tmp;
    printf("BFS : ");
    while (front <= rear){
        tmp = queue[front++];
        printf("%i ", tmp -> vertex);
        while(tmp != NULL){
            if (visited[(tmp -> vertex) - 1] != 1){
                queue[++rear] = list[(tmp -> vertex) - 1];
                visited[(tmp -> vertex) - 1] = 1;
            }
            tmp = tmp -> next;
        }
    }
    printf("\n");
    return;
}

void display(node* list[]){
    for(int i = 0; i < v; i++){
        node* tmp = list[i];
        while (tmp != NULL){
            printf("%i ", tmp -> vertex);
            tmp = tmp -> next;
        }
        printf("\n");
    }
    return;
}

void create_adj_list(node* list[]){
    int v1,v2,n;
    printf("Enter # of edges : ");
    scanf("%i", &n);

    node *New = NULL,*tmp = NULL;
    for (int i = 1 ;i <= n; i++){
        printf("Edge (from to) : ");
        scanf("%i %i", &v1, &v2);
        New = malloc(sizeof(node*));
        New -> vertex = v2;
        New -> next = NULL;

        tmp = list[v1 - 1];
        while (tmp -> next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = New;

        // for undirected
        New = malloc(sizeof(node*));
        New -> vertex = v1;
        New -> next = NULL;

        tmp = list[v2 - 1];
        while (tmp -> next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = New;
    }
}

int main(void){

    printf("# of vertices : ");
    scanf("%i",&v);

    node* adj_list[v];


    for(int i = 1; i <= v; i++){
        adj_list[i - 1] = malloc(sizeof(node*));
        adj_list[i - 1] -> vertex = i;
        adj_list[i - 1] -> next = NULL;
    }

    create_adj_list(adj_list);
    display(adj_list);
    bfs(adj_list);
    return 0;
}

