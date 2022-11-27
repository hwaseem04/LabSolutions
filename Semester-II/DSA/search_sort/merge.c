#include <stdio.h>

int n;

void Display(int* arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int* arr, int beg, int end, int mid){
    int i = beg;
    int j = mid + 1;

    int tmp[end - beg + 1];
    int k = 0;
    while(i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }
        else if(arr[j] < arr[i]){
            tmp[k++] = arr[j++];
        }
    }
    while (i <= mid){
        tmp[k++] = arr[i++];
    }
    while (j <= end){
        tmp[k++] = arr[j++];
    }

    for(i = beg, k = 0; i <= end; i++, k++){
        arr[i] = tmp[k];
    }
    return;
}


void mergeSort(int* arr, int beg, int end){
    int mid = (beg + end )/ 2;
    if(beg < end){    //Until one element is reached
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1, end);
        merge(arr,beg,end,mid);
    }
    return;
}


int main() {
    printf("Enter size : ");
    scanf("%i", &n);
    int arr[n] ;
    printf("Elements : ");
    for(int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }
    Display(arr, n);
    mergeSort(arr, 0, n - 1);
    Display(arr, n);
}