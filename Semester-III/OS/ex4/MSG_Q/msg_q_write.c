# include <stdio.h>
# include <sys/msg.h>
# include <string.h>
# define MAX 10


struct msg_buffer{
	long msg_type;
	char data[100];
}msg1;

int main(void){
	key_t key;  // Key
	int msg_id; // Identifier
	key = ftok("prac.c", 65);

	msg_id = msgget(key, 0666 | IPC_CREAT);

	//msg1.msg_type = 1;
	//strcpy(msg1.data,"Hello Waseem");
	
	while(1){
		printf("Msg type : ");
		scanf("%li", &msg1.msg_type);
		fflush(stdin);
		printf("TO write : ");
		scanf("%[^\n]s", (msg1.data));
		//fflush(stdin);
		msgsnd(msg_id, &msg1, sizeof(msg1), 0);
		printf("Data Sent : %s\n", msg1.data);
	}
	//msgsnd(msg_id, &msg1, sizeof(msg1), 0);
	//printf("Data Sent : %s\n", msg1.data);

	return 0;
}















