#include <stdio.h>
#include <time.h>

int main(void)
{
    int n = 0;
    printf("n : ");
    scanf("%i", &n);
    int num[n];
    for (int i = 0; i < n; i++){
        num[i] = i + 1;
    }
    int tmp = 0;
    int k = 0;
    printf("Enter K : ");
    scanf("%i", &k);
    clock_t begin = clock();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++){
            if (num[j] < num[j + 1]) {
                tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
    printf("%i th largest element is : %i\n", k, num[k - 1]);
    clock_t end = clock();
    printf("The elapsed time is %f seconds\n", ((double)(end - begin)) / CLOCKS_PER_SEC);
    return 0;
}