
# include <stdio.h>
# include <unistd.h>
//# include <sys/wait.h>

int main(void){
	int fd_12[2];
	int fd_21[2];
	char s1[100] = "This is C";
	char s2[100];
	pipe(fd_12);
	pipe(fd_21);
	int pid = fork();

	if (pid > 0){
		close(fd_12[0]);
		close(fd_21[1]);
		write(fd_12[1], s1, 100);
		printf("Written to child: %s\n", s1);
		read(fd_21[0], s2, 100);
		printf("Read from child : %s\n", s2);
	}
	else{
		close(fd_12[1]);
		close(fd_21[0]);
		read(fd_12[0], s2, 100);
		s2[4] = '-';
		write(fd_21[1], s2, 100);
	}	
	return 0;
}








