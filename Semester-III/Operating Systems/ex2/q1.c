# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>


int main(void){
	
	char str[10] = "Hello\n";
	int fd[2];
	pipe(fd);
	int pid = fork();

	if (pid == 0){
		char str2[10];
		read(fd[0], str2, sizeof(str2));
		printf("Read from parent : %s\n", str2);
	}
	else{
		write(fd[1], str, sizeof(str));
		wait(NULL);
	}
}
