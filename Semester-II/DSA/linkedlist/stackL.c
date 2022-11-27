# include <stdio.h>
# include <stdlib.h>


void push(int e);
void pop();
void Top();
void isFULL();
void isEMPTY();

int size = 5;
int stack[5];
int top = -1;

int main(void){
    push(1);
    push(2);
    push(3);
    Top();
    pop();
    Top();
    isEMPTY();
    isFULL();
    pop();
    pop();
    pop();
    isEMPTY();
    return 0;
}

void isEMPTY(){
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

void isFULL(){
    if (top == size - 1){
        printf("Stack is Full\n");
        return;
    }
    printf("Stack is not full\n");
    return;
}
void Top(){
    if(top == -1){
        printf("stack is empty\n");
        return;
    }
    printf("%i\n", stack[top]);
    return;
}

void pop(){
    if (top == -1){
        printf("Underflow\n");
        return ;
    }
    top--;
    printf("Removed element is %i\n", stack[top + 1]);
    return;
}

void push(int e){
    top ++;
    if (top == size){
        printf("Stack Overflow\n");
        return;
    }
    stack[top] = e;
    return;
}

