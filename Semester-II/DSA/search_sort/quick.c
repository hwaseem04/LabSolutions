#include <stdio.h>


void Display(int array[], int size) {
    for (int i = 0; i < size; ++i) {
      printf("%d  ", array[i]);
    }
    printf("\n");
}
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int* arr, int left, int right){
    int loc = left, tmp;
    while(left < right){
        if (loc == left){
            if(arr[loc] <= arr[right]){
                right--;
            }
            else{
                swap(&arr[right],&arr[loc]);
                loc = right;
            }
        }
        else if(loc == right){
            if(arr[loc] >= arr[left]){
                left++;
            }
            else{
                swap(&arr[left],&arr[loc]);
                loc = left;
            }
        }
    }
    return loc;
}

void quickSort(int* arr, int left, int right){
    int p;
    if (left < right){
        p = partition(arr, left, right);
        quickSort(arr,left, p-1);
        quickSort(arr,p+1,right);
    }
    return;
}




int main(){
    int n;
    printf("Enter size : ");
    scanf("%i", &n);
    int arr[n] ;
    printf("Elements : ");
    for(int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }
    Display(arr, n);
    quickSort(arr, 0, n - 1);
    Display(arr, n);
}



/*


int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

*/
