# include <stdio.h>
# include <sys/shm.h>


int main(void){
	key_t key = ftok("shmread.c", 123);
	int id = shmget(key, 1024, 0666 | IPC_CREAT);
	char* memory = shmat(id, 0, 0);
	
	printf("Data read : %s\n", memory);
}
