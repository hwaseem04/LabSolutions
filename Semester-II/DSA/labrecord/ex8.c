# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert(node*);
node* Delete(node*, int);

void  inorder(node*);
void  preorder(node*);
void  postorder(node*);
int   min(node* root);

node* n = NULL;

int main(void){
        printf("1 --> insert\n\
2 --> delete\n\
3 --> display\n\
4 --> Exit\n\n");
    node* root = NULL;
    int ch;
    int e;
    while(1){
        printf("Choice : ");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                printf("Element (insert): ");
                scanf("%i", &e);
                n = malloc(sizeof(node));
                n -> left = n -> right = NULL;
                n -> data = e;
                root = insert(root);
                break;
            case 2:
                printf("Element (delete): ");
                scanf("%i", &e);
                root = Delete(root,e);
                break;
            case 3:
                printf("1) Inorder 2) Preorder 3) Postorder : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        inorder(root);
                        break;
                    case 2:
                        preorder(root);
                        break;
                    case 3:
                        postorder(root);
                        break;
                    default:
                        break;
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting !!\n");
                return 0;
            default:
                printf("ENTER   VALID   CHOICE\n");
        }
    }
}

int min(node* root){
    if (root -> left == NULL){
        return root -> data;
    }
    return min(root -> left);
}

node* insert(node* root){
    if (root == NULL){
        root = n;
    }
    else if (n -> data < root -> data){
        root -> left  = insert(root -> left);
    }
    else if (n -> data > root -> data){
        root -> right = insert(root -> right);
    }
    return root;
}

node* Delete(node* root,int e){
    if (root == NULL){
        return root;
    }
    else if (e < root -> data){
        root -> left  = Delete(root -> left,  e);
    }
    else if (e > root -> data){
        root -> right = Delete(root -> right, e);
    }
    else{
        if (root -> right == NULL && root -> left == NULL){
            free(root);
            return NULL;
        }
        else if (root -> right == NULL && root -> left != NULL){
            node* tmp = root -> left;
            free(root);
            return tmp;
        }
        else if (root -> right != NULL && root -> left == NULL){
            node* tmp = root -> right;
            free(root);
            return tmp;
        }
        else{
            int minimum = min(root -> right);
            root -> data = minimum;
            root -> right = Delete(root -> right, minimum);
        }
    }
    return root;
}
void inorder(node* root){
    if (root != NULL){
        inorder(root -> left);
        printf("%i ", root -> data);
        inorder(root -> right);
    }
    return;
}
void preorder(node* root){
    if (root != NULL){
        printf("%i ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
    return;
}
void postorder(node* root){
    if (root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%i ", root -> data);
    }
    return;
}

