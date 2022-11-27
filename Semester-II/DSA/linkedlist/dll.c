# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

void insert_beg(void);
void insert_end(void);
void Display(void);
void Delete(void);
void search();
void display_back();

node* head = NULL;
int e;

int main(void){
        printf("1 --> Insert\n\
2 --> Search\n\
3 --> Display\n\
4 --> Delete\n\
5 --> Exit\n\n");
    int ch;
    while (1){
        printf("Choice : ");
        scanf("%i", &ch);

        switch(ch){
            case 1:
                printf("1) Insert Beg 2) Insert End : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        insert_beg();
                        break;
                    case 2:
                        insert_end();
                        break;
                    default:
                        break;
                }
                printf("\n");
                break;
            case 2:
                search();
                printf("\n");
                break;
            case 3:
                printf("1) Display from front 2) Display from end : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        Display();
                        break;
                    case 2:
                        display_back();
                        break;
                }
                printf("\n");
                break;
            case 4:
                Delete();
                printf("\n");
                break;
            case 5:
                printf("Ending !!\n");
                return 0;
        }

    }
}
void search(){
    printf("Element to search : ");
    scanf("%i", &e);
    int i = 1;
    int flag = 0;
    if (head == NULL){
        printf("Element not found\n");
        return;
    }
    node* tmp = head;
    while(tmp != NULL){
        if (tmp -> data == e){
            flag = 1;
            break;
        }
        tmp = tmp -> next;
        i++;
    }
    if (flag == 1){
        printf("Element found at position %i\n", i);
    }
    else{
        printf("Element Not found\n");
    }
    return;
}

void Delete(){
    if (head == NULL){
        return;
    }
    if (head -> next == NULL){
        free(head);
        head = NULL;
        return;
    }
    node* tmp = head;
    while(tmp -> next -> next != NULL){
        tmp = tmp -> next;
    }
    free(tmp -> next);
    tmp -> next = NULL;
    return;
}

void display_back(){
    node* tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }

    while(tmp != NULL){
        printf("%i ", tmp -> data);
        tmp = tmp -> prev;
    }
    printf("\n");
    return;
}


void Display(){
    if (head == NULL){
        printf("Empty !!\n");
        return;
    }

    node* tmp = head;
    while(tmp != NULL){
        printf("%i ", tmp -> data);
        tmp = tmp -> next;
    }
    return;
}

void insert_beg(){
    node* n = malloc(sizeof(node));
    n -> next = n -> prev = NULL;

    printf("Element : ");
    scanf("%i", &e);
    n -> data = e;

    if (head == NULL){
        head = n;
        return;
    }
    head -> prev = n;
    n -> next = head;
    head = n;
    return;
}

void insert_end(){
    node* n = malloc(sizeof(node));
    n -> next = n -> prev = NULL;

    printf("Element : ");
    scanf("%i", &e);
    n -> data = e;

    if (head == NULL){
        head = n;
        return;
    }

    node* tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }

    tmp -> next = n;
    n -> prev = tmp;
    return ;
}