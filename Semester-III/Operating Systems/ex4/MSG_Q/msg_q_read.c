# include <stdio.h>
# include <sys/msg.h>

struct buff{
    long type;
    char data[100];
}msg1;

int main(){

    key_t key = ftok("prac2.c", 123);

    int msgid = msgget(key, 0666 | IPC_CREAT);

    
    while(1){
        printf("This program is going to read only msg type of 1\n");
        msgrcv(msgid , &msg1 ,sizeof(msg1), 3,0);
        printf("%s\n", msg1.data);
    }
}




// # include <stdio.h>
// # include <sys/msg.h>
// # define MAX 10


// struct msg_buffer{
//     long msg_type;
//     char data[100];
// }msg1;

// int main(void){
//     key_t key;  // Key 
//     key = ftok("prac.c", 65);

//     int msgid = msgget(key, 0666 | IPC_CREAT);
	
//     printf("This program is going to read only msg type of 1\n");
//     while(1){
//     	msgrcv(msgid, &msg1,sizeof(msg1), 2, 0); // 2 -> msg type, 0 --> flag
//    	    printf("Data read : %s\n", msg1.data);
//     }
//     return 0;
// }

