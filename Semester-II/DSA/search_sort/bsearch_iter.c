# include <stdio.h>


int main(void){
    int n;
    printf("Size of array : ");
    scanf("%i", &n);
    int array[n];
    printf("Enter elements : ");
    for(int i = 0; i < n; i++)
        scanf("%i", &array[i]);
    int e = 0;
    printf("Element to search : ");
    scanf("%i", &e);
    int beg = 0, end = n-1;
    int mid ;
    while(end - beg >= 0){
        mid = (beg + end)/2;
        if (array[mid] == e){
            printf("Element found at index %i\n", mid);
            break;
        }
        else if (array[mid] > e)
            end = mid - 1;
        else if (array[mid] < e)
            beg = mid + 1;
    }
    return 0;
}


