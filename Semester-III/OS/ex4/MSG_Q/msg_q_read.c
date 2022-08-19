# include <stdio.h>
# include <sys/msg.h>
# define MAX 10


struct msg_buffer{
    long msg_type;
    char data[100];
}msg1;

int main(void){
    key_t key;  // Key 
    key = ftok("prac.c", 65);

    int msgid = msgget(key, 0666 | IPC_CREAT);
	
    printf("This program is going to read only msg type of 1\n");
    while(1){
    	msgrcv(msgid, &msg1,sizeof(msg1), 1, 0);
   	printf("Data read : %s\n", msg1.data);
    }
    return 0;
}

