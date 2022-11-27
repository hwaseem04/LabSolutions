# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node* insert();
void display();
void swap();
void free_all();

node* head = NULL;
int e;

int main(void){
    head = insert();
    head = insert();
    head = insert();

    display();
    swap();
    printf("\n");
    display();
    printf("\n");
    free_all();
    return 0;
}

void swap(){
    if (!head || !(head -> next)){
        return;
    }
    node* tail = head;
    while(tail -> next -> next != NULL){
        tail = tail -> next;
    }
    node* tmp = head;
    head = tail -> next;
    tail -> next = tmp;
    head -> next = tmp -> next;
    tmp -> next = NULL;
    return;
}
void display(){
    if (head == NULL){
        printf("No elements !!\n");
        return;
    }

    node* tmp = head;
    while(tmp != NULL){
        printf("%i ", tmp -> data);
        tmp = tmp -> next;
    }
    return;
}
node* insert(){
    node* n = malloc(sizeof(node));
    printf("Enter : ");
    scanf("%i", &e);
    n -> data = e;
    n -> next = NULL;

    if (head == NULL){
        head = n;
        return head;
    }

    node* tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = n;
    return head;
}

void free_all(){
    node* tmp = head;
    while(head != NULL){
        tmp = tmp -> next;
        free(head);
        head = tmp;
    }
    return;
}