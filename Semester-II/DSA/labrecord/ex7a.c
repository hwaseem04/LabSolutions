# include <stdio.h>

void Display();
void enqueue();
void dequeue();
void peek();
int isFull();
int isEmpty();

int max = 5;
int queue[5];
int front = -1, rear = -1, e, r;

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
        printf("Queue is empty !! \n");
        return;
    }
    if (front <= rear){
        for (int i = front; i <= rear; i++){
            printf("%i ", queue[i]);
        }
    }
    else if(front > rear){
        for (int i = front; i < max; i++){
            printf("%i ", queue[i]);
        }
        for (int i = 0; i <= rear; i++){
            printf("%i ", queue[i]);
        }
    }
    return;
}

void enqueue(){
    if (isFull()){
        printf("Queue is Full !!\n");
        return;
    }
    printf("Element : ");
    scanf("%i", &e);

    if (front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % max;
    queue[rear] = e;
    return;
}

void dequeue(){
    if (isEmpty()){
        printf("Empty !!\n");
        return;
    }
    if (rear == front){
        r = queue[front];
        rear = -1;
        front = -1;
    }
    else {
        r = queue[front];
        front = (front + 1) % max;
    }
    printf("Dequeued element is : %i\n", r);
    return;
}

void peek(){
    if (!isEmpty())
        printf("Peek element is  : %i\n", queue[front]);
    else
        printf("Empty queue\n");
    return;
}

int isEmpty(){
    return (front == -1 && rear == -1);
}

int isFull(){
    return (front == 0 && rear == max - 1) || (rear == front - 1);
}