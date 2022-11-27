# include <stdio.h>
# include <unistd.h>


int main(void){
	char str1[10] = "Hello\n";
	
	int fd12[2];
	int fd21[2];

	pipe(fd12);
	pipe(fd21);

	int pid = fork();

	if (pid > 0){
		write(fd12[1], str1, sizeof(str1));
		read(fd21[0], str1, sizeof(str1));
		printf("Received : %s\n", str1);
	}
	else{
		char str2[10] = "";
		read(fd12[0], str2, sizeof(str2));
		str2[0] = '-';
		printf("Written : %s\n", str2);
		write(fd21[1], str2, sizeof(str2));
	}
}


