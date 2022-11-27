# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(int e);
void pop();
void top();
int  isempty();
void free_all();

node* head = NULL;


int main(void){
    int e,ch;
    printf("1)push \n\
2)Pop \n\
3)Top \n\
4)Exit\n\n");
    while(1){
        printf("Choice : ");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                printf("element : ");
                scanf("%i", &e);
                push(e);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4:
                return 0;
            default:
                printf("Enter valid choice!!\n");
        }
    }

}

int isempty(){
    return head == NULL;
}


void top(){
    if (isempty()){
        printf("Stack is empty!!\n");
        return ;
    }
    printf("%i\n", head -> data);
    return;
}
void pop(){
    if (isempty()){
        printf("Stack underflow\n");
        return;
    }
    node* tmp = head;
    head = head -> next;
    free(tmp);
    return;
}


void push(int e){
    node* n = malloc(sizeof(node));
    n -> data  = e;
    n -> next = NULL;
    if(head == NULL){
        head = n;
        return;
    }
    n -> next = head;
    head = n;
    return;
}

void free_all(){
    node* tmp = head;
    while(head != NULL){
        tmp = head -> next;
        free(head);
        head = tmp;
    }
    return;
}