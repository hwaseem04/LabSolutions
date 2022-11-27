# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* tail = NULL;
int e;

void insert_end();
void insert_beg();
void display();
void delete_end();
void delete_beg();
void delete_all();
void search();

int main(void)
{
    printf("1 --> Insert\n\
2 --> Delete\n\
3 --> Search\n\
4 --> Display\n\
5 --> Exit\n\n");
    int ch;
    while(1){
        printf("Enter Choice : ");
        scanf("%i", &ch);

        switch(ch){
            case 1:
                printf("1)End 2) Beginning : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        insert_end();
                        break;
                    case 2:
                        insert_beg();
                        break;
                    default:
                        break;
                }

                printf("\n");
                break;
            case 2:
                printf("1)End 2) Beginning : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        delete_end();
                        break;
                    case 2:
                        delete_beg();
                        break;
                    default:
                        break;
                }
                printf("\n");
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                printf("\n\n");
                break;
            case 5:
                delete_all();
                printf("Exiting !...\n");
                return 0;
            default:
                printf("Enter valid choice !\n");
        }
    }
}

void search(){
    printf("Enter element to search : ");
    scanf("%i", &e);
    int flag = 0;
    if(tail == NULL){
        printf("Element is not present\n");
        return;
    }
    node* tmp = tail -> next;
    do{
        if (tmp -> data == e){
            flag = 1;
            break;
        }
        tmp = tmp -> next;
    }while(tmp != tail -> next);
    if (flag == 1){
        printf("Element is present\n");
    }
    else{
        printf("Element is not present\n");
    }
    return;
}

void delete_all(){
    if(tail == NULL){
        printf("Already empty\n");
        return;
    }
    while(tail != NULL){
        delete_beg();
    }
}
void delete_beg(){
    if(tail == NULL){
        printf("Already empty\n");
        return;
    }
    //One element case
    if(tail -> next == tail){
        free(tail);
        tail = NULL;
        return;
    }
    node* tmp = tail -> next;
    tail -> next = tmp -> next;
    free(tmp);
    return;
}
void delete_end(){
    if(tail == NULL){
        printf("Already empty\n");
        return;
    }

    //One element case
    if(tail -> next == tail){
        free(tail);
        tail = NULL;
        return;
    }

    node* tmp = tail -> next;
    while(tmp -> next != tail){
        tmp = tmp -> next;
    }
    tmp -> next = tail -> next;
    free(tail);
    tail = tmp;
    return;
}


void display(){
    if(tail == NULL){
        printf("No elements \n");
        return;
    }
    node* tmp = tail -> next;
    do{
        printf("%i ", tmp -> data);
        tmp = tmp -> next;
    }while(tmp != tail -> next);

    return;
}
void insert_beg(){
    node* n = malloc(sizeof(node));
    n -> next = NULL;

    printf("Element : ");
    scanf("%i", &e);
    n -> data = e;

    if (tail == NULL){
        tail = n;
        tail -> next = n;
        return;
    }

    n -> next = tail -> next;
    tail -> next = n;
    return;
}
void insert_end(){
    node* n = malloc(sizeof(node));
    n -> next = NULL;

    printf("Element : ");
    scanf("%i", &e);
    n -> data = e;

    if (tail == NULL){
        tail = n;
        tail -> next = n;
        return;
    }

    n -> next = tail -> next;
    tail -> next = n;
    tail = n;
    return;
}





