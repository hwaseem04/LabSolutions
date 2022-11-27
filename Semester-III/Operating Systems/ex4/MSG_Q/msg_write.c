# include <stdio.h>
# include <sys/msg.h>

struct buffer{
  long type;
  char data[100];
}msg;

int main(void){
	key_t key = ftok("msg_read.c", 123);
  int msgid = msgget(key, 0666 | IPC_CREAT);
  printf("Data write : \n");
  while(1){
		printf("ID : ");
		scanf("%li", &msg.type);
		printf("Data : ");
		scanf("%s", msg.data);
    msgsnd(msgid, &msg, sizeof(msg), 0);
  }
}


