# include <stdio.h>
# include <sys/ipc.h>
# include <sys/shm.h>


int main(void){
	key_t Key = ftok("test2", 42);
	int shmid = shmget(Key, 1024, 0777 | IPC_CREAT);
	char* sh = (char*)shmat(shmid, 0, 0);
	//fflush(stdin);
	scanf("%s",sh);
	return 0;
}



























