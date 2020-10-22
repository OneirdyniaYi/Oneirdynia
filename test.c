#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void show(int sig){
	printf("signal is %d!\n",sig);
}

int main(){
	struct sigaction newact,oldact;
	newact.sa_handler = show;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	int count = 0;
	pid_t pid = 0;

	sigaction(SIGINT,&newact,&oldact);

	pid = fork();
	if(pid == 0){
		while(1){
			printf("im child \n");
			sleep(1);
		}
		return 0;
	}

	while(1){
		if(count++ > 3){
			sigaction(SIGINT,&oldact,NULL);
			printf("pid = %d\n",pid);
			kill(pid,SIGKILL);
		}
	printf("im father\n");
	sleep(1);
	}

	return 0;	
}
