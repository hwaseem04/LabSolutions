# include <string.h>
# include <ctype.h>

# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node ;

node* head = NULL;
int ch, e;



void  Delete_all(node *list);

//node* Previous(node* list, int e)


void  Delete_element_at_end(node **list);
node* Delete_min(node* list);

node* head_to_tail(node* list);

void insert_end();
void insert_beg();
void insert_pos();

void delete_end();
void delete_pos();

void reverse();
void display();
void free_all();

int main(void)
{

    while(1){
        printf("Choice : ");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                printf("1)Insert_end 2)Insert_beg 3)Insert_pos : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        insert_end();
                        break;
                    case 2:
                        insert_beg();
                        break;
                    case 3:
                        insert_pos();
                        break;
                    default:
                        printf("Invalid\n");
                }
                break;
            case 2:
                printf("1)Delete at end 2)Delete at position : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        delete_end();
                        break;
                    case 2:
                        delete_pos();
                        break;
                    default:
                        printf("Invalid\n");
                }
                break;
            case 3:
                break;
            case 4:
                reverse();
                break;
            case 5:
                display();
                break;
            case 6:
                free_all();
                return 0;
            default:
                head = head_to_tail(head);
                printf("Enter valid choice!!\n");
        }
    }

}

void delete_pos(){
    int pos;

    printf("Position : ");
    scanf("%i", &pos);
    node* tmp = head;
    for(int i = 0; i < pos; i++){
        tmp = tmp -> next;
    }


}


void delete_end(){
    if (head == NULL){
        printf("Empty!!\n");
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


void reverse(){
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return;
}

void insert_pos(){
    printf("***IMPORTANT*** : Insert only in between other elements\n");
    int pos;
    printf("Enter position : ");
    scanf("%i", &pos);

    node* n = malloc(sizeof(node));

    printf("Element : ");
    scanf("%i", &e);

    n -> data = e;
    n -> next = NULL;

    int i = 1;
    node* tmp = head;
    while(tmp -> next != NULL){
        if (i + 1 == pos){
            n -> next = tmp -> next;
            tmp -> next = n;
            break;
        }
        tmp = tmp -> next;
        i++;
    }
    return;

}
void insert_beg(){
    node* n = malloc(sizeof(node));

    printf("Element : ");
    scanf("%i", &e);

    n -> data = e;
    n -> next = NULL;

    if (head == NULL){
        head = n;
        return;
    }

    n -> next = head;
    head = n;
    return;
}

void insert_end(){
    node* n = malloc(sizeof(node));

    printf("Element : ");
    scanf("%i", &e);

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

void free_all(){
    if (head == NULL){
        return;
    }
    node* tmp = head;
    while(tmp != NULL){
        tmp = head -> next;
        free(head);
        head = tmp;
    }
    return;
}


/*
node* reverse(node* list){
    node* prev = NULL;
    node* current = list;
    node* next = NULL;

    while (current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    list = prev;
    return list;
}

node* reverse(node* list)
{
    node* prev   = NULL;
    node* current = list;
    node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
    return list;
}
*/

node* head_to_tail(node* list){
    if (list == NULL){
        return list;
    }
    if (list -> next == NULL){
        return list;
    }
    node* tmp = list;
    /*
    do{
        tmp = tmp -> next ;
    }while(tmp -> next != NULL);
    */
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }

    tmp -> next = list;
    list = list -> next;
    tmp -> next -> next = NULL;
    return list;
}

/*
node* Previous(node* list, int e){

    for (node* tmp = list; tmp != NULL; tmp = tmp -> next){
        if (tmp -> next != NULL && tmp -> next -> data == e){
            return tmp;
        }
    }
    return 0;
}


node* Delete_min(node* list){
    if (list == NULL){
        printf("No Element to Delete!!\n");
        return list;
    }//Works

    if (list -> next == NULL){
        free(list);
        list = NULL;
        return list;
    }//Works

    node* tmp = list;
    int min = list -> data;
    node* Prev = 0;
    while (tmp != NULL){
        if (tmp -> data < min){
            min = tmp -> data;
            Prev = Previous(list, min);
        }
        tmp = tmp -> next;
    }

    if (Prev == 0){
        tmp = list -> next;
        free(list);
        list = tmp;
        return list;
    }
    if (Prev -> next -> next == NULL){
        free(Prev -> next);
        Prev -> next = NULL;
        return list;
    }

    tmp = Prev -> next -> next;

    free(Prev -> next);
    Prev -> next = tmp;
    return list;
}
*/
void Delete_element_at_end(node **list){

    node* tmp = *list;
    if (tmp == NULL){  //Why not *list  ????
        *list = NULL;
        return;
    }

    if (tmp -> next == NULL){
        free(tmp);
        *list = NULL;    //Cannot use tmp = NULL;
        return;
    }
    while (tmp -> next -> next != NULL){
        tmp = tmp -> next;
    }
    free(tmp -> next);
    tmp -> next = NULL;
    return;
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


void Delete_all(node *list){
    node* tmp = NULL;
    while(list != NULL){
        tmp = list -> next;
        free(list);
        list = tmp;
    }
    return;
}



