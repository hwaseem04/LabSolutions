# include <stdio.h>
# include <stdlib.h>


int main(void){

    int n, r;
    printf("Total process, Total resource types : ");
    scanf("%i %i", &n, &r);

    int allocated[n][r];
    int maxNeeded[n][r];
    int needed[n][r];
    int finished[n];
    int available[r];

    for (int i = 0; i < n; i++)
        finished[i] = 0;

    for (int i = 0; i < r; i++){
        printf("Total instance for resource %i : ", i + 1);
        scanf("%i", &available[i]);
    }

    for (int i = 0; i < n; i++){
        printf("Number of instances (# # #) Allocated for P%i : ", i);
        scanf("%i %i %i", &allocated[i][0], &allocated[i][1], &allocated[i][2]); 

        for (int j = 0; j < r; j++)
            available[j] -= allocated[i][j];

        printf("Maximum needed resources (# # #) for P%i : ", i);
        scanf("%i %i %i", &maxNeeded[i][0], &maxNeeded[i][1], &maxNeeded[i][2]);

        for (int j = 0; j < r; j++)
            needed[i][j] = maxNeeded[i][j] - allocated[i][j];

        // needed[i][0] = maxNeeded[i][0] - allocated[i][0];
        // needed[i][1] = maxNeeded[i][1] - allocated[i][1];
        // needed[i][2] = maxNeeded[i][2] - allocated[i][2];
    }
    //printf("%i %i %i\n", available[0], available[1],available[2]);

    int flag=0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            flag = 0;
            if (finished[j] == 1) continue;
            for (int k = 0; k < r; k++){
                //printf("%i %i\n", needed[j][k], available[k]);
                if (needed[j][k] > available[k]){
                    flag = 1;
                    break;
                }
            }
            printf("\n");
            if (flag == 0){
                printf("P%i\n", j);
                for (int k = 0; k < r; k++){
                    available[k] = available[k] - needed[j][k] + maxNeeded[j][k]; //allocated[j][k] + available[k];
                    finished[j] = 1;
                }
                break;
            }       
        }
    }
    return 0;
}