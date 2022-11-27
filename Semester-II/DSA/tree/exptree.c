# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}node;

node* n = NULL;
node* stack[20];
int top = -1;

void push(node* root){
    top ++;
    stack[top] = root;
}

node* pop(){
    top --;
    return stack[top + 1];
}


void inorder(node* root){
    if (root != NULL){
        inorder(root -> left);
        printf("%c ", root -> data);
        inorder(root -> right);
    }
    return;
}

void postorder(node* root){
    if (root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%c ", root -> data);
    }
}
int main(void){
    node* root;
    node* a;
    node* b;
    char* s = "ab*c-de+fg-/+";
    int len = strlen(s);
    //printf("%i", len);
    for (int i = 0; i < len; i++){
        //printf("%c\n", s[i]);
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            b = pop();
            a = pop();
            n = malloc(sizeof(node));
            n -> data = s[i];
            n -> left  = a;
            n -> right = b;
        }
        else{
            n = malloc(sizeof(node));
            n -> data = s[i];
            n -> left = NULL;
            n -> right = NULL;
        }
        push(n);
    }
    root = stack[top];
    printf("INfix : ");
    inorder(root);
    printf("\n");
    printf("POSTfix : ");
    postorder(root);
    printf("\n");
    return 0;
}