# include <stdio.h>

int Index(int arr[], int e, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] == e)
            return i;
    }
    return -1;
}
void Insert(int arr[], int e, int size)
{
    arr[size] = e;
}
int Delete(int arr[], int e, int size){
    
    int idx = Index(arr,e,size);
    //printf("%i\n",idx);
    if (idx == -1){
        return size;
    }
    for(int i = idx; i < size; i++){
        arr[i] = arr[i + 1];
    }
    if (size >= 0)
        size -= 1;
    return size;
}
void Display(int arr[], int size){
    printf("Elements : ");
    for(int i = 0; i < size; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
    return;
}

void Search(int arr[], int e, int size){
    int flag = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == e){
            printf("Found at index %i\n", i);
            flag = 1;
        }
    }
    if (flag == 0){
        printf("Element Not found\n");
    }
}

int  main(void)
{

    int arr[25] = {0};
    printf("\n1 --> Insert Element \n2 --> Delete Element \n3 --> Search Element \n4 --> Display Elements \n5 --> Exit\n");

    int ch = 0;
    int e;
    int i;
    int size = 0;
    while (1){
        printf("Enter Choice : ");
        scanf("%i", &ch);

        switch(ch)
        {
            case 1:
                printf("Element to insert : ");
                scanf("%i", &e);
                Insert(arr, e, size);
                size += 1;
                break;
            case 2:
                printf("Element to delete : ");
                scanf("%i", &e);
                size = Delete(arr, e, size);
                
                break;
            case 3:
                printf("Element to search : ");
                scanf("%i", &e);
                Search(arr, e, size);
                break;
            case 4:
                Display(arr, size);
                break;
            case 5:
                return 0;
            default:
                printf("Enter valid operation\n");
        }
    }
}