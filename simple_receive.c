#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ 128

typedef struct msgbuf {
	long mtype;
	char mtext [MSGSZ];
} message_buf;

int main(){

	int msqid;
	key_t key;
	message_buf rbuf;

	key = 1234;
	if( (msqid = msgget(key, 0666)) < 0){
		perror("msgget");
		exit(1);
	}
	while(1){
		if(msgrcv(msqid, &rbuf, sizeof(message_buf), 1, 0) < 0){
			perror("msgrcv");
		}
		printf("%s\n", rbuf.mtext);
//		sleep(1);
	}
	return 0;
}
