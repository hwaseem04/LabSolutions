# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(void){
    int n = 0;
    printf("n : ");
    scanf("%i", &n);
    int num[n];
    for(int i = 0; i < n; i++){
        num[i] = i + 1;
    }
    clock_t begin = clock();
    int idx_i = 0;
    int idx_f = 0;
    srand(time(NULL));
    idx_i = rand() % n;
    idx_f = rand() % n;
    while (idx_i == idx_f)
        idx_f = rand() % n;
    int tmp = num[idx_i];
    num[idx_i] = num[idx_f];
    num[idx_f] = tmp;
    for (int i = 0; i < n; i++)
        printf("%i ", num[i]);
    clock_t end = clock();
    printf("\nTime Elapsed : %f seconds\n", ((double)(end - begin))/ CLOCKS_PER_SEC );
    return 0;
}