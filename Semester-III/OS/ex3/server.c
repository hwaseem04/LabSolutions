#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	int fd;
	char arr[100];
	
	mkfifo("myfifo", 0777);
	while(1){
		fd=open("myfifo", O_RDONLY);	
		read(fd, arr, 100);
		printf("%s\n", arr);
	}
}


