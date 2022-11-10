# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main(void){
	char str[100];
	int fd;
	fd = open("myfifo", O_WRONLY);
	while(1){
		
		printf("TEST 2\n");
		scanf("%s", str);
		write(fd, str, sizeof(str));
	}
}	



#include <stdio.h>
// #include <fcntl.h> // open, O_RDONLY
// #include <sys/stat.h> // mkfifo
// #include <unistd.h> // read, write

// int main(void){

// 	int fd;
// 	//printf("Chatbot 1\n");
// 	char arr2[100];
// 	while(1){
// 		//scanf("%[^\n]", arr2);
// 		scanf("%[^\n]s", arr2);
// 		fflush(stdin);
// 		//read(0, arr2,sizeof(arr2));
// 		fd = open("myfifo", O_WRONLY);
// 		write(fd, arr2,100);
// 		//close(fd);
// 	}
// }



