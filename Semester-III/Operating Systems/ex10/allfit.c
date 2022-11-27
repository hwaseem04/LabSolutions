# include <stdio.h>

int main(void){
	int m;
	printf("# Memory partition : ");
	scanf("%i", &m);

	int p;
	printf("# processes : " );
	scanf("%i", &p);
	
	int arr[m];
	int arr2[p];
	for (int i = 0; i < m; i++){
		scanf("%i", &arr[i]);
	}
	for (int j = 0; j < p; j++){
		scanf("%i", &arr2[j]);
	}

	int vis[m];
	for(int i = 0; i < m; i++)vis[i]=0;
	for (int i = 0; i < p; i++){
		int flag=0;
		for (int j = 0; j < m; j++){
			if (!vis[j]) {
				if (arr[j] >= arr2[i]){
					flag = 1;
					vis[j] = 1;
					printf("%i\n", arr[j]);
					break;
				}
			}
			if (flag == 1) break;
			if ( j == m - 1 && flag == 0) printf("---\n");
		}
	}
	printf("\n");
	for(int i = 0; i < m; i++)vis[i]=0;
	int tmp;
	for (int i = 0; i < m - 1; i++){
		for (int j = 0; j < m - i - 1; j++){
			if (arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}	
	for (int i = 0; i < p; i++){
    int flag=0;
    for (int j = 0; j < m; j++){
      if (!vis[j]) {
        if (arr[j] >= arr2[i]){
          flag = 1;
					vis[j] = 1;
          printf("%i\n", arr[j]);
					break;
        }
      }
			if (flag == 1) break;
      if ( j == m - 1 && flag == 0) printf("---\n");
    }
  }	

	printf("\n");
	for(int i = 0; i < m; i++)vis[i]=0;
  for (int i = 0; i < p; i++){
    int flag=0;
    for (int j = m-1; j >= 0; j--){
      if (!vis[j]) {
        if (arr[j] >= arr2[i]){
          flag = 1;
					vis[j] = 1;
          printf("%i\n", arr[j]);
					break;
        }
      }
			if (flag == 1) break;
      if ( j == 0 && flag == 0) printf("---\n");
    }
  }

}
