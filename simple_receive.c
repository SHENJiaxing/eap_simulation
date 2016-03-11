#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ 128

typedef struct msgbuf {
	long mtype;
	char mtext [MSGSZ];
} message_buf;


void print_usage();
int main(int argc, char** argv){
	FILE * fp;
	int msqid;
	key_t key;
	message_buf rbuf;
	int bool_print = 1;
	// printf("%d", argc);
	if (argc < 3){
		print_usage();
		return -1;
	} else {
		key = atoi(argv[1]);
		fp = fopen(argv[2],"a");
		if (argc == 4){
			bool_print = atoi(argv[3]);
		}
	}
	
	if( (msqid = msgget(key, 0666)) < 0){
		perror("msgget");
		exit(1);
	}
	while(1){
		if(msgrcv(msqid, &rbuf, sizeof(message_buf), 1, 0) < 0){
			perror("msgrcv");
		}
		 
		fprintf(fp, "%s\n", rbuf.mtext);
		fflush(fp);
		 
		if (bool_print){
			printf("%s\n", rbuf.mtext);	
		}
//		sleep(1);
	}

	fclose(fp);
	return 0;
}

void print_usage(){
	printf("Usage:\n");
	printf("./rec msg_key out_file [bool_print=1]\n");
	printf("\tmsg_key 1234 for imsi\n");
	printf("\tmsg_key 2234 for probe request\n");
	printf("\tbool_print 0 mute\n");
}