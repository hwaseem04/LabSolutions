# include <stdio.h>
# include <sys/ipc.h>
# include <sys/shm.h>


int main(void){
	key_t Key = ftok("test2", 42);
	int shmid = shmget(Key, 1024, 0777 | IPC_CREAT);
	char* sh = (char*)shmat(shmid, 0, 0);
	
	printf("%s\n", sh);
	return 0;

}















