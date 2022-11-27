#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int n = 0;
    printf("n : ");
    scanf("%i", &n);
    int num[n];
    clock_t begin = clock();
    srand(time(NULL));
    int tmp = 0;
    int flag = 0;
    int i = 0;
    while (i < n){
        tmp = rand() % n;
        for (int j = 0; j < i; j++){
            if (num[j] == tmp + 1){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            num[i] = tmp + 1;
            i++;
        }
        flag = 0;
    }
    printf("{");
    for(i = 0; i < n; i++){
        printf("%i ", num[i]);
    }
    printf("}");
    clock_t end = clock();
    printf("\n\nThe elapsed time is %f seconds", ((double)(end - begin)) / CLOCKS_PER_SEC );
    return 0;
}