#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int n = 0;
    printf("n : ");
    scanf("%i", &n);
    int num[n];
    int used[n];
    for (int i = 0; i < n; i++)
        used[i] = 0;
    srand(time(NULL));
    int tmp = 0;
    int flag = 0;
    clock_t begin = clock();
    int i = 0;
    while (i < n){
        tmp = rand() % n;
        if (used[tmp - 1] == 0){
            used[tmp - 1] = 1;
            num[i] = tmp + 1;
            i++;
        }
    }
    printf("{");
    for(i = 0; i < n; i++)
        printf("%i ", num[i]);
    printf("}");
    clock_t end = clock();
    printf("\n\nThe elapsed time is %f seconds\n", ((double)(end - begin) )/ CLOCKS_PER_SEC  );
    return 0;
}