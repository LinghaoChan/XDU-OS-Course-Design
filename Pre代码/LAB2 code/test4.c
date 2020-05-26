#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<signal.h>
void usr1_handler(int sig_num){
	printf("parent (%d) got thr SIGUSR1\n", getpid());
}

int main(){
	pid_t ret;
	int status, role = -1;
	ret = fork();
	if(ret>0){
		printf("Parent: This is the parent process (pid %d)\n", getpid());
		signal(SIGUSR1, usr1_handler);
		role = 0;
		pause();
		printf("Parent: Awaiting child exit\n");
		ret = wait(&status);
	}
	else if(ret == 0){
		printf("Child: This is the child process (pid %d)\n", getpid());
		role = 1;
		sleep(1);
		printf("Child: Sending SIGUSR1 to pid %d\n", getppid());
		kill(getppid(), SIGUSR1);
		sleep(2);
	}else{
		printf("Parent: Error trying to fork() (%d)\n", errno);
	}
	printf("%s Exiting...\n", (( role == 0) ? "Parent" : "Child"));
	return 0;
}
