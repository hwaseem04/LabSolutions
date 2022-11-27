# include <stdio.h>

int main(void){
    int n;
    printf("Size of array : ");
    scanf("%i", &n);
    int arr[n];
    printf("Enter elements : ");
    for(int i = 0; i < n; i++)
        scanf("%i", &arr[i]);
    int e;
    printf("Element to search : ");
    scanf("%i", &e);

    int flag = 0;
    for(int i = 0; i < n; i++){
        if (arr[i] == e){
            printf("Element found at index %i\n", i);
            flag = 1;
        }
    }
    if (flag == 0){
        printf("Element Not found\n");
    }
    return 0;
}