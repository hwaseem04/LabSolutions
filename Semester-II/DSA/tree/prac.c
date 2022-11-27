# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;
int height(node* root){
    if (root == NULL){
        return -1;
    }
    else{
        int lheight = height(root -> left);
        int rheight = height(root -> right);
        if (lheight > rheight){
            return lheight + 1;
        }
        return rheight + 1;
    }
}
int balanced ;
void check_balance(node* root){
    if (root == NULL){
        return ;
    }
    else{
        int lheight = height(root -> left);
        int rheight = height(root -> right);
        if(abs(lheight - rheight) < 2){
            check_balance(root -> left);
            check_balance(root -> right);
        }
        else{
            balanced = 1;
        }
    }
    return;
}


int minimum(node* root){
    if (root -> left == NULL){
        return root -> data;
    }
    return minimum(root -> left);
}

int maximum(node* root){
    if (root -> right == NULL){
        return root -> data;
    }
    return maximum(root -> right);
}

node* Delete(node* root, int n){
    if (root == NULL){
        return root;
    }
    else if(root -> data < n){
        root -> right = Delete(root -> right, n);
    }
    else if(root -> data > n){
        root -> left = Delete(root -> left, n);
    }
    else{
        if (root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }
        else if (root -> left == NULL && root -> right != NULL){
            node* tmp = root -> right;
            free(root);
            return tmp;
        }
        else if (root -> left != NULL && root -> right == NULL){
            node* tmp = root -> left;
            free(root);
            return tmp;
        }
        else{
            int Min = minimum(root -> right);
            root -> data = Min;
            root -> right = Delete(root -> right, Min);
        }
    }
    return root;
}

node* insert(node* root, node* n){
    if (root == NULL){
        return n;
    }
    else if(root -> data < n -> data){
        root -> right = insert(root -> right, n);
    }
    else if(root -> data > n -> data){
        root -> left = insert(root -> left, n);
    }
    return root;
}

void inorder(node* root){
    if (root != NULL){
        inorder(root -> left);
        printf("%i ", root -> data);
        inorder(root -> right);
    }
}
int main(void){
    node* root = NULL;

    int ch, e;

    node* n = NULL;
    while(1){
        printf("Choice : ");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                n = malloc(sizeof(node));
                n -> left = n -> right = NULL;
                printf("Enter element : ");
                scanf("%i", &(n -> data));
                root = insert(root, n);
                break;
            case 2:
                printf("Element to delete : ");
                scanf("%i", &e);
                root = Delete(root, e);
                break;
            case 3:
                printf("Maximum : %i\n", maximum(root));
                printf("Minimum : %i\n", minimum(root));
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Height : %i\n", height(root));
                balanced = 0;
                check_balance(root);
                if(balanced == 1){
                    printf("Not Balanced \n");
                }
                else{
                    printf("Balanced\n");
                }

                break;
            case 7:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}

