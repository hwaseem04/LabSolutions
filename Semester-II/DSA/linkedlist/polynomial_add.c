# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int coeff;
    int Pow;
    struct node* next;
}node;

node* head_p1 = NULL;
node* head_p2 = NULL;
node* head_p3 = NULL;
int c, p, t;

node* insert_end(node* head);
node* create(node* head);
void  display(node* head);
node* insert(node* head, node* New);
void add(void);

int main(void){
    printf("Input for first Polynomial \n");
    head_p1 = create(head_p1);
    printf("\n");

    printf("Input for Second Polynomial \n");
    head_p2 = create(head_p2);
    printf("\n");

    printf("Polynomial 1 : ");
    display(head_p1);
    printf("Polynomial 2 : ");
    display(head_p2);

    printf("\n");

    add();

    printf("Polynomial 3 : ");
    display(head_p3);

    return 0;
}

void add(void){
    node* tmp1 = head_p1;
    node* tmp2 = head_p2;

    while (tmp1 != NULL && tmp2 != NULL){
        if (tmp1 -> Pow == tmp2 -> Pow){
            node* n = malloc(sizeof(node));
            n -> coeff = tmp1 -> coeff + tmp2 -> coeff;
            n -> Pow = tmp1 -> Pow;
            head_p3 = insert(head_p3, n);
            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
        }

        else if (tmp1 -> Pow > tmp2 -> Pow){
            node* n = malloc(sizeof(node));
            n -> coeff = tmp1 -> coeff;
            n -> Pow = tmp1 -> Pow;
            head_p3 = insert(head_p3, n);
            tmp1 = tmp1 -> next;
        }

        else{
            node* n = malloc(sizeof(node));
            n -> coeff = tmp2 -> coeff;
            n -> Pow = tmp2 -> Pow;
            head_p3 = insert(head_p3, n);
            tmp2 = tmp2 -> next;
        }
    }

    if (tmp1 == NULL)
    {
        while(tmp2 != NULL){
            node* n = malloc(sizeof(node));
            n -> coeff = tmp2 -> coeff;
            n -> Pow = tmp2 -> Pow;
            head_p3 = insert(head_p3, n);
            tmp2 = tmp2 -> next;
        }
    }

    else if(tmp2 == NULL)
    {
        while(tmp1 != NULL){
            node* n = malloc(sizeof(node));
            n -> coeff = tmp1 -> coeff;
            n -> Pow = tmp1 -> Pow;
            head_p3 = insert(head_p3, n);
            tmp1 = tmp1 -> next;
        }
    }

    return;
}

node* insert(node* head, node* New){
    if (head == NULL){
        head = New;
        return head;
    }

    node* tmp = head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = New;
    return head;
}


void display(node* head){
    if (head == NULL){
        printf("No Elements!!\n");
        return;
    }

    for (node* tmp = head; tmp != NULL; tmp = tmp -> next){
        printf("%ix^%i ", tmp -> coeff, tmp -> Pow);
    }
    printf("\n");
    return;
}

node* create(node* head){
    printf("Enter terms : ");
    scanf("%i", &t);

    for(int i = 0; i < t; i++){
        head = insert_end(head);
    }
    return head;
}



node* insert_end(node* head){
    node* n = malloc(sizeof(node));
    printf("Coefficient : ");
    scanf("%i", &c);
    printf("Power : ");
    scanf("%i", &p);
    n -> coeff = c;
    n -> Pow = p;
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