# include <stdio.h>

int size = 5;
int deque[5];
int rear = -1, front = -1, e,r;

void inject();
void eject();
void push();
void pop();
void Display();

int main(void){
    printf("1 --> push\n\
2 --> pop\n\
3 --> inject\n\
4 --> eject\n\
5 --> Display\n\
6 --> Exit\n\n");
    int ch;
    while(1){
        printf("Choice : ");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                inject();
                break;
            case 4:
                eject();
                break;
            case 5:
                Display();
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Enter valid choice !!\n");
        }
    }
    return 0;
}
void push(){
    printf("(Push)");
    if ((front == 0 && rear == size - 1) || (rear == front - 1)){
        printf("Overflow!!\n");
        return;
    }
    printf("Element : ");
    scanf("%i", &e);
    if (front == -1 && rear == -1){
        front++;
        rear ++;
    }
    else if(front == 0){
        front = size - 1;
    }
    else{
        front --;
    }
    deque[front] = e;
}
void pop(){
    printf("(POP)");
    if (front == -1 && rear == -1){
        printf("Deque is empty!\n");
        return;
    }

    else if (front == rear){
        r = deque[front];
        front = -1;
        rear = -1;
    }
    else{
        r = deque[front];
        front = (front + 1) % size ;
    }
    printf("Popped element is %i\n", r);
    return;
}

void Display(){
    printf("Deque : ");
    if (front == -1 && rear == -1){
        printf("Deque is empty!\n");
        return;
    }
    else if (front > rear){
        for (int i = front; i < size; i++){
            printf("%i ", deque[i]);
        }
        for (int i = 0; i <= rear; i++){
            printf("%i ", deque[i]);
        }
        printf("\n");
    }
    else{
        for (int i = front; i <= rear; i++){
            printf("%i ", deque[i]);
        }
        printf("\n");
    }
}

void inject(){
    printf("(INJECT)");
    if ((front == 0 && rear == size - 1) || (rear == front - 1)){
        printf("Deque Overflow!!\n");
        return;
    }

    printf("Element : ");
    scanf("%i", &e);


    if(front == -1 && rear == -1){
        rear ++;
        front ++;
        deque[rear] = e;
    }
    else{
        rear = (rear + 1) % size;
        deque[rear] = e;
    }
    return;
}


void eject(){
    printf("(EJECT)");
    if (front == -1 && rear == -1){
        printf("Deque is empty!\n");
        return;
    }
    else if(rear == front){
        r = deque[rear];
        front = -1;
        rear = -1;
    }
    else if(rear == 0){
        r = deque[rear];
        rear = size - 1;
    }
    else{
        r = deque[rear];
        rear --;
    }
    printf("Ejected element is %i\n", r);
    return;
}