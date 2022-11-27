# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main(void){
  char str2[100];

  int fd = open("myfifo", O_WRONLY);
  while(1){
    printf("Data write : ");
    scanf("%s", str2);
    write(fd, str2, sizeof(str2));
  }
}
  

