# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert(node*);
node* Delete(node*, int);
int   min(node*);
void  inorder(node*);
void  preorder(node*);
void  postorder(node*);
void  levelorder_queue(node*);
void  dequeue(node*);
void  enqueue(node*);
void  check_balance(node*);
int   height(node*);
void  levelorder_ll(node*);
int   check_full_bst(node*);

int   max(node*);
void  inorder_predecessor(node*);

//Global variables
node* n = NULL;
node* queue[100];
int front = -1, rear = -1;
int balanced = 1;
int p, prev;

int main(void){
    node* root = NULL;
    int ch;
    int e,flag;
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
                printf("1) Inorder 2) Preorder 3) Postorder 4)Level order : ");
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
                    case 4:
                        printf("1) Queue 2) Linked List : ");
                        scanf("%i", &ch);
                        switch(ch){
                            case 1:
                                levelorder_queue(root);
                                break;
                            case 2:
                                //levelorder_ll(root);
                                break;
                        }
                    default:
                        break;
                }
                printf("\n");
                break;
            case 4:
                printf("1) Check full BST  2) Inorder predecessor : ");
                scanf("%i", &ch);
                switch(ch){
                    case 1:
                        flag = check_full_bst(root);
                        if (flag == 1)
                            printf("FULL BInary tree\n");
                        else
                            printf("Not a full BInary tree\n");
                        break;
                    case 2:
                        prev = -1;
                        printf("Predecessor of : ");
                        scanf("%i", &p);
                        printf("Predecessor is \n");
                        inorder_predecessor(root);
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                printf("Exiting !!\n");
                return 0;
            default:
                printf("Height of tree is %i\n", height(root) );
                /*balanced = 1;
                check_balance(root);
                if (balanced == 1){
                    printf("Balanced\n");
                }*/
                //printf("ENTER   VALID   CHOICE\n");
        }
    }
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

int min(node* root){
    if (root -> left == NULL){
        return root -> data;
    }
    return min(root -> left);
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

void enqueue(node* root){
    if (root == NULL){
        return;
    }
    if (front == -1 && rear == -1){
        front ++;
        rear ++;
    }
    else{
        rear ++;
    }
    queue[rear] = root;
    return;
}

void dequeue(node* root){
    if (front == -1){
        return;
    }
    else{
        printf("%i ", queue[front] -> data);
        front ++;
    }
    return;
}
void  levelorder_queue(node* root){
    node* tmp = root;
    enqueue(tmp);
    int i = 0;
    while(front <= rear){
        tmp = queue[front];
        enqueue(tmp -> left);
        enqueue(tmp -> right);
        dequeue(tmp);
        i++;
        //printf("%i %i %i\n", front,rear,i);
    }
    return;
}

void check_balance(node* root){
    if (root != NULL){
        int lheight = height(root -> left);
        int rheight = height(root -> right);
        //printf("%i %i\n", lheight, rheight);
        if (abs(lheight - rheight) >= 2){
           printf("Tree is not balanced\n");
           balanced = 0;
           return;
        }
        check_balance(root -> left);
        check_balance(root -> right);
    }
    return;
}
int height(node* root){
    if (root == NULL){
        return -1;
    }
    int lheight = height(root -> left);
    int rheight = height(root -> right);
    if (lheight > rheight){
        return lheight + 1;
    }
    return rheight + 1;
}

void  levelorder_ll(node* root){
    ;
}

int check_full_bst(node* root){
    if (root == NULL)
        return 1;
    else if (root -> right == NULL && root -> left == NULL)
        return 1;
    else if (root -> right != NULL && root -> left != NULL)
        return check_full_bst(root -> left) && check_full_bst(root -> right);
    return 0;
}

int max(node* root){
    while(root -> right != NULL){
        root = root -> right;
    }
    return root -> data;
}

void inorder_predecessor(node* root){
    if (root == NULL){ // If root is NULL , simply return Nothing
        return;
    }
    else{
        if(root -> data == p){ // If root -> data is the element for which predecessor has to be found.

            //If root -> left is NULL return prev.  Here prev can have two values -> -1 or ancestor.
            // -1 is printed when the root hadnt moved right subtree once,
            // If moved to right subtree once and if left node is not there, then the ancestor(the node whose right subtree we are in) is printed
            if (root -> left == NULL){
                printf("%i\n", prev);
                return;
            }
            printf("%i \n", max(root -> left)); //If root -> left is not NULL, then maximum element from left subtree is Predecessor
            return;
        }
        //If root -> data is not the element for which predecessor has to be found
        else if (p < root -> data){
            if (root -> left == NULL){ //If there is no right subtree
                printf("-1\n");
                return;
            }
            inorder_predecessor(root -> left);
        }
        else if (p > root -> data){
            prev = root -> data;  //Once we try to search in right subtree, we have to keep track of ancestor right? Because, say if 'r' is the element in the immediate right subtree of 'prev'
                                  // And if 'r' doesnt have left subtree then its ancestor 'prev' is its predecessor.
            inorder_predecessor(root -> right);
        }
    }
}