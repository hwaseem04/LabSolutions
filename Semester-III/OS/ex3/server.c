# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

int main(void){
	mkfifo("myfifo", 0777);
	
	char str[100];
	int fd;
	printf("TEST\n");
	fd = open("myfifo", O_RDONLY);
	printf("TEST\n");
	while(1){
		
		printf("TEST\n");
		read(fd, str, sizeof(str));
		printf("%s\n", str);
	}
}

/*
#include <stdio.h>
#include <fcntl.h> //open, O_RDONLY
#include <sys/stat.h> // For mkfifo
#include <unistd.h> // for read, write

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

*/