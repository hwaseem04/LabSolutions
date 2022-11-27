# include <stdio.h>
# include <stdlib.h>

typedef struct queue{
    int data;
    struct queue* next;
}queue;

queue *front = NULL;
queue *rear = NULL;

void Display();
void enqueue();
void dequeue();
void peek();
int isFull();
int isEmpty();

int e, size = 5, members = 0;

int main(void){
    printf("1 --> Enqueue\n\
2 --> Dequeue\n\
3 --> peek\n\
4 --> Display\n\
5 --> Exit\n\n");
    int ch;
    while(1){
        printf("Choice : ");
        scanf("%i", &ch);

        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Queue : ");
                Display();
                printf("\n");
                break;
            case 5:
                printf("Exiting!!\n");
                return 0;
            default:
                printf("Enter Valid choice !!\n");
        }
    }
}
void Display(){
    if (isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    queue* tmp = front;
    while (tmp != NULL){
        printf("%i ", tmp -> data);
        tmp = tmp -> next;
    }
    return;
}

void enqueue(){
    if (isFull()){
        printf("Queue is Full\n");
        return;
    }
    printf("Element : ");
    scanf("%i", &e);

    queue* n = malloc(sizeof(queue));
    n -> data = e;
    n -> next = NULL;

    if (front == NULL){
        front = n;
        rear = n;
        members ++;
        return;
    }

    rear -> next = n;
    rear = n;
    members++;
    return;
}

void dequeue(){
    if (isEmpty()){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        free(front);
        front = NULL;
        rear = NULL;
        members = 0;
    }
    else{
        queue* tmp = front;
        front = front -> next;
        free(tmp);
        members--;
    }
    return;
}

void peek(){
    if (isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Peek element is %i\n", front -> data);
    return;
}

int isEmpty(){
    return members == 0;
}

int isFull(){
    return members == size;
}