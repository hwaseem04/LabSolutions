# include <stdio.h>

void display(int n, int* arr){
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}

int main(void){
    int n = 5;

    int arr[] = {5,3,2,8,6};


    display(n,arr);
    //insertion(n,arr);
    //selection(n,arr);
    display(n,arr);
    return 0;
}
