# include <stdio.h>


void search(int* arr,int e,int beg,int end){
    int mid = (beg + end)/2;
    if (beg > end){
        printf("Element is not found\n");
        return;
    }
    else if (e == arr[mid]){
        printf("Element found at index %i\n", mid);
        return;
    }
    else if (e < arr[mid]){
        end = mid - 1;
        search(arr,e,beg,end);
        return;
    }
    else if (e > arr[mid]){
        beg = mid + 1;
        search(arr,e,beg,end);
        return;
    }
}


int main(void){
    int arr[5] = {1,2,3,4,5};
    int e;
    printf("Element to search : ");
    scanf("%i", &e);
    int beg = 0;
    int end = 4;
    search(arr,e,beg,end);
    return 0;
}

