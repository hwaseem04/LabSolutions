# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node ;

node* head = NULL;
int ch;


void reverse();
void display();
void insert_end();


int main(void){
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);
    display();
    reverse();
    display();
    return 0;
}

void reverse(){
    node* prev = NULL;
    node* current = head;
    node* next = head;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


void insert_end(int e){
    node* n = malloc(sizeof(node));
    n -> data = e;
    n -> next = NULL;

    if (head == NULL){
        head = n;
        return;
    }

    node* tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = n;
    return;
}

void display(){
    if (head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    node* tmp = head;
    while(tmp != NULL){
        printf("%i ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");
    return;
}