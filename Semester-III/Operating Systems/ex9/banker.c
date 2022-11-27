# include <stdio.h>


int main(void){
	int n, r;
	printf("# Process : ");
	scanf("%i", &n);

	printf("Resource : ");
	scanf("%i", &r);

	int allocated[n][r], max[n][r], need[n][r], finished[n], available[r];
	printf("A1 A2 A3 M1 M2 M3\n");
	for (int i = 0; i < n; i++){
		scanf("%i %i %i %i %i %i", &allocated[i][0], &allocated[i][1],&allocated[i][2], &max[i][0], &max[i][1],&max[i][2]);
		need[i][0] = max[i][0] - allocated[i][0];
		need[i][1] = max[i][1] - allocated[i][1];
		need[i][2] = max[i][2] - allocated[i][2];
		finished[i] = 0;
	}
  
	for (int i = 0; i < r; i++){
		scanf("%i", &available[i]);
	}
	int flag = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (finished[j]) continue;
			//printf("%i\n", j);
			flag = 0;
			for (int k = 0; k < r; k++){
				if (need[j][k] > (available[k])){
					flag = 1;
					//printf("%i", i);
					break;
				}
			}
			if (flag == 1) continue;
			for (int k = 0; k < r; k++){
				available[k] = available[k] - need[j][k] + max[j][k];
				//printf("%i-", available[k]);
			}
			finished[j] = 1;
			printf("P%i\n", j);
		}
	}
}
