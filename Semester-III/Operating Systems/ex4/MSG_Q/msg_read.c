# include <stdio.h>
# include <sys/msg.h>

struct buffer{
	long type;
	char data[100];
}msg;

int main(void){
	key_t key = ftok("msg_read.c", 123);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	printf("Data read : \n");
	while(1){
		msgrcv(msgid, &msg, sizeof(msg), 1, 0);
		printf("Data : %s\n", msg.data);
	}
}
