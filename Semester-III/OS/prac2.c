# include <stdio.h>
# include <unistd.h>


int main(void){
	char name[100]; 
	int fd[2];		
	pipe(fd);

	int pid = fork();
	if (pid > 0){
		sleep(2);
		write(fd[1],"This is from parent ",100);
	}
	else{
		printf("OOO\n");	
		read(fd[0],name, 100);
		printf("%s\n", name);
	}
	//write(1,"\n",1);
	return 0;
}










