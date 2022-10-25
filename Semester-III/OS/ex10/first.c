# include <stdio.h>

int main(void){
    int p;
    printf("Total partitions : ");
    scanf("%i", &p);

    int memory[p];
    printf("Enter size for each partition : ");
    for (int i = 0; i < p; i++)
        scanf("%i", &memory[i]);

    int n;
    printf("Total processes : ");
    scanf("%i", &n);
    int req[n];
    printf("Enter memory requirement for each of the processes : ");
    for (int i = 0; i < n; i++)
        scanf("%i", &req[i]);    

    for (int i = 0; i < n; i++){   
        for (int j = 0; j < p; j++){
            if (memory[j] >= req[i] && memory[j] > 0){
                printf("P%i --> %i\n", i+ 1,memory[j]);
                memory[j] = -1;
                break;
            }
        }
    }
    return 0;
}