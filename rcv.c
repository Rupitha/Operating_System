#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<stdlib.h>
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
	msg_buf m2;
	if((msgqid = msgget(key,msgflg))== -1){
		printf("Message queue is not created");
		exit(1);
	}
	printf("Queue is created sucessfully.\n");
	if (msgrcv(msgqid,&m2,msgsz,0,IPC_NOWAIT)== -1){
		printf("Error in message sending:");
		exit(1);
	}
	printf("Message received: %s\n", m2.msg);
	return 0;
}
