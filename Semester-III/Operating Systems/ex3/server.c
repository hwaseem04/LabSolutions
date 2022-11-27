# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

// create myfifo in terminal with command "mkfifo myfifo"

int main(void){
	printf("Reading data(Server) : \n");

	int fd = open("myfifo", O_RDONLY);
	char str[100];
	while(1){
		read(fd, str, sizeof(str));
		printf("Data : %s\n", str);
	}
}


