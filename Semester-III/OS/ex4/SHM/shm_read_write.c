# include <stdio.h>
//# include <sys/ipc.h>
# include <sys/shm.h>
//# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>


// In the program I am accessing child memory with two independent processes.

int main(void){
	key_t Key = ftok("test", 42);
	int shmid = shmget(Key, 1024, 0777 | IPC_CREAT);
	char* sh = (char*)shmat (shmid, 0,0);
	//scanf("%s", sh);
	//printf("%s\n", sh);
	int pid = fork();
	if (pid == 0){
		printf("Child : ");
		scanf("%s", sh);
		return 0;

	}
	else{
		wait(NULL);
		printf("Parent : ");
		printf("%s\n", sh);

	}	
}




