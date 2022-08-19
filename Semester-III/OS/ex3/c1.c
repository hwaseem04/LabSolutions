#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){

	int fd;
	//printf("Chatbot 1\n");
	char arr2[100];
	while(1){
		scanf("%[^\n]", arr2);
		fflush(stdin);
		//read(0, arr2,sizeof(arr2));
		fd = open("myfifo", O_WRONLY);
		write(fd, arr2,100);
		//close(fd);
	}
}



