# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main(void){
    int pid;
	int x = 1;
	int* p = &x;
    pid = fork();
	if (pid > 0){
        *p = 3;
		//sleep(1);
		printf("Inside parent : pid %i, x address : %p, x value : %i \n", pid, &x,x);
	}
	else{
		//sleep(2);
		printf("Inside child : pid %i, x address : %p, x value : %i \n", pid, &x,x);
	}
    printf("Hello\n");
	if (pid > 0){
		wait(NULL);
    } 
    return 1;
}
