# include <stdio.h>

# define size 100

void insert();
void Display();
void find();


int last = 1;
int stack[size] = {[0 ... size - 1] = -1};
int e;



int main(void){
    int ch;
    while(1){
        printf("Choice : ");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                find();
                break;
            case 3:
                Display();
                printf("\n");
                break;
            default:
                printf("Exiting !!..\n");
                return 0;
        }
    }
}

void insert(){
    printf("Element : ");
    scanf("%i", &e);

    int add = 1;
    while (stack[add] != -1){
        if (stack[add] > e){
            add *= 2;
        }
        else{
            add = 2 * add + 1;
        }
    }
    stack[add] = e;
    last = add;
    return;
}

void find(){
    printf("Element to search : ");
    scanf("%i", &e);

    for (int i = 1; i <= last ; i++){
        if(stack[i] == -1){
            continue;
        }
        else{
            if (e == stack[i]){
                printf("Element found at index %i\n", i);
                break;
            }
        }
    }
    return;
}

void Display(){
    for (int i = 1; i <= last ; i++){
        if(stack[i] == -1){
            printf("- ");
        }
        else
            printf("%i ", stack[i]);
    }
}