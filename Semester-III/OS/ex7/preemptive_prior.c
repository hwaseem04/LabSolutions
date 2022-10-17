# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int id;
    int arrT;
    int burT;
    int prior;
}proc;

typedef struct node{
    proc data;
    struct node* next;
}node;

node *head, *n;

int size;
int front = -1;
int rear = -1;

void enqueue(proc e){
    if (front == -1 && rear == -1){
        n = (node*)malloc(sizeof(node));
        n -> data = e;
        n -> next = NULL;
        front ++;
        rear ++;
        head -> next = n;
        return;
    }
    

    if (head -> next == NULL){
        n = (node*)malloc(sizeof(node));
        n -> data = e;
        if (head -> data.prior < e.prior){    
            n -> next = NULL;
            head -> next = n;
        } 
        else{
            n -> next = head;
            head = n;
        }
        return;
    }

    node* tmp = head;
    n = (node*)malloc(sizeof(node));
    n -> data = e;
    while(tmp -> next != NULL){
        if (tmp -> data.prior > e.prior){
            n -> next = tmp ;
            tmp = n;
            return;
        }
        tmp = tmp -> next;
    }
    tmp -> next = n;
    n -> next = NULL;
    return;
}

proc deque(){
    ;
}



int main(void){
    printf("Number of processes : ");
    scanf("%i", &size);

    proc* arr = (proc*)malloc(sizeof(proc) * size);
    head = (node*)malloc(sizeof(node));
    head -> next = NULL;

    for(int i = 0; i < size; i++){
        printf("Arrival Time, Burst Time, Priority : ");
        scanf("%i %i %i", &arr[i].arrT, &arr[i].burT,&arr[i].prior);
        arr[i].id = i + 1;
    }

    int tt = 0;
}