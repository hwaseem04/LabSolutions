# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>



int main(void){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int n1 = 10/2;
	int  fd21[2];
	pipe(fd21);
	int sum = 0;
	int pid = fork();
	if (pid > 0){
		int sum2[1];
		for (int i = 0; i < n1; i++){
			sum += arr[i];
		}
		printf("Sum calculated in Parent : %i\n", sum);
		read(fd21[0], sum2, 1);
		sum += sum2[0];
		printf("Total sum is : %i\n", sum);
			
	}
	else{
		int sum2[1];
		for(int i = n1; i < 10; i++){
			sum2[0] += arr[i];
		}
		printf("Sum calculated in child : %i\n", sum2[0]);
		write(fd21[1], sum2, 1);
	}
	
	return 0;
}



