# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node ;


int   isFirst(node *list);
void  Delete_all(node *list);
void  Insert_at_end(node **list);
void  Display(node* list);
node* Previous(node* list, int e);
node* Search(node* list, int e);
void  Delete(node** list, int e);
void  Delete_element_at_end(node **list);

int main(void)
{
    int e = 0;
    node* list = NULL;
    printf("1 --> Insert\n\
2 --> Delete\n\
3 --> Search\n\
4 --> Display\n\
5 --> Exit\n\n");

    int ch;
    while (1)
    {
        printf("Choice : ");
        scanf("%i", &ch);
        switch (ch)
        {
            case 1:
                printf("Element : ");
                Insert_at_end(&list);
                printf("\n");
                break;
            case 2:
                Delete_element_at_end(&list);
                printf("Last Element deleted!\n");
                printf("\n");
                break;
            case 3:
                printf("Element to search : ");
                scanf("%i", &e);
                node* address = Search(list, e);
                printf("Found at address : %p\n", address);
                printf("\n");
                break;
            case 4:
                Display(list);
                printf("\n");
                break;
            case 5:
                Delete_all(list);
                printf("Exiting ...\n");
                printf("\n");
                return 0;
            default:
                printf("Enter Valid  Choice !!");
                printf("\n");
        }
    }
}

void Delete_element_at_end(node **list){

    node* tmp = *list;
    if (isFirst(tmp)){
        *list = NULL;
        return;
    }

    if (tmp -> next == NULL){
        free(tmp);
        *list = NULL;
        return;
    }
    while (tmp -> next -> next != NULL){
        tmp = tmp -> next;
    }
    free(tmp -> next);
    tmp -> next = NULL;
    return;
}

void Delete(node **list, int e){

    if (*list == NULL){
        printf("NO Element to Delete !!\n");
        return;
    }
    node* tmp = *list;
    if (tmp -> data == e){
        *list = tmp -> next;
        free(tmp);
        tmp = NULL;
    }
    else{
        node* Prev = Previous(*list, e);
        for(tmp = *list; tmp != NULL; tmp = tmp -> next){
            if (tmp -> data == e){
                Prev -> next = tmp -> next;
                free(tmp);
            }
        }
    }
}

node* Previous(node* list, int e){
    for (node* tmp = list; tmp != NULL; tmp = tmp -> next){
        if (tmp -> next != NULL && tmp -> next -> data == e){
            return tmp;
        }
    }
    return 0;
}


node* Search(node* list, int e)
{
    for (node* tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        if (tmp -> data == e){
            return tmp;
        }
    }
    return 0;
}

int isFirst(node *list){
    return list == NULL;
}

void Display(node* list){
    printf("Elements in Linkedlist : ");
    if (list == NULL){
        printf("No Elements\n");
        return;
    }
    for (node* tmp = list; tmp != NULL; tmp = tmp -> next){
        printf("%i ", tmp -> data);
    }
    printf("\n");\
    return;
}


void Insert_at_end(node **list){
    node *n = malloc(sizeof(node));
    if (n == NULL){
        printf("Out of Space !\n");
        return ;
    }
    int e;
    scanf("%i", &e);
    n -> data = e;
    n -> next = NULL;
    if (isFirst(*list)){
        *list = n;
        return;
    }
    node *current = *list;
    while (current -> next != NULL){
        current = current -> next;
    }
    current -> next = n;
    return ;
}
void Delete_all(node *list){
    node* tmp = NULL;
    while(list != NULL){
        tmp = list -> next;
        free(list);
        list = tmp;
    }
    return;
}