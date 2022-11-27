# include <stdio.h>
# include <unistd.h>


int main(void){
	int n = 5;
	
	int fd12[2];
	int fd21[2];
	pipe(fd12);
	pipe(fd21);

	int pid = fork();

	if (pid > 0){
		int arr[5] = {4,2,3,5,6};
		write(fd12[1], &arr, sizeof(arr));
		int sum = 0;
		for (int i = 0; i < n/2; i++)
		{
			sum += arr[i];
		}
		int sum2;
		read(fd21[0], &sum2, sizeof(sum2));
		printf("Total sum : %i\n", sum + sum2);
	}
	else{
		int arr[n];
		read(fd12[0], arr, sizeof(arr));
		int sum=0;
		for (int i = n/2; i < n; i++){
			sum += arr[i];
		}
		write(fd21[1], &sum, sizeof(sum));
	}
}
