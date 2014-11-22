#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define msgsz 100
typedef struct message{
long msgtype;
char msg[msgsz];
}msg_buf;

int main(){
	key_t key;
	key = 1234;
	int msgflg = IPC_CREAT|0666;
	int msgqid;
	unsigned int mssz;
	msg_buf m1;
	if((msgqid = msgget(key,msgflg))== -1){
		printf("Message queue is not created");
		exit(1);
	}
	printf("Queue is created sucessfully.\n");
	m1.msgtype = 1;
	strcpy(m1.msg,"Hi");
	mssz = strlen(m1.msg) +1;
	if(msgsnd(msgqid,&m1,mssz,IPC_NOWAIT)== -1){
		printf("Error in message sending:");
		exit(1);
	} 
	printf("Message sent.\n");
	return 0;
}












