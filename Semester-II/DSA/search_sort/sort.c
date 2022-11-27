# include <stdio.h>


void bubble(int,int*);
void insertion(int,int*);
void selection(int,int*);
void display(int,int*);

int main(void){
    int n;
    printf("Size of array : ");
    scanf("%i", &n);
    int arr[n];
    printf("Enter elements : ");
    for(int i = 0; i < n; i++)
        scanf("%i", &arr[i]);

    display(n,arr);
    bubble(n,arr);
    //insertion(n,arr);
    //selection(n,arr);
    display(n,arr);
    return 0;
}




void selection(int n, int* arr){
    int min, min_idx, j;
    for (int i = 0; i < n - 1; i++){
        min = arr[i];
        min_idx = i;
        j = i + 1;
        while(j < n){
            if (arr[j] < min){
                min = arr[j];
                min_idx = j;
            }
            j += 1;
        }
        arr[min_idx] = arr[i];
        arr[i] = min;
    }
    return;
}

void insertion(int n, int* arr){
    int  key,j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && (arr[j] > key)){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    return;
}

void bubble(int n, int* arr){
    int  tmp;
    int swapped = 0;
    for (int i = 0; i < n - 1; i++){
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swapped = 1;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (swapped == 0)
            return;
    }
    return;
}

void display(int n, int* arr){
    for (int i = 0; i < n; i++){
        printf("%i ", arr[i]);
    }
    printf("\n");
}