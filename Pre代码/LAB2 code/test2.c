#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>

int main(){
	pid_t ret;
	int staus, i;
	int role = -1;
	ret = fork();
	if(ret > 0){
		printf("Parent: This the parent process (pid %d)\n", getpid());
		for (int i = 0; i < 6; ++i)
		{
			printf("Parent: At count%d\n", i);
			sleep(1);
		}
		ret = wait(&staus);
		role = 0;
	}
	else
		if(ret == 0){
			printf("Child : This the child process (pid %d)\n", getpid());
			for (int i = 0; i < 6; ++i)
			{
				printf("Child: At count %d\n", i);
				sleep(1);
			}
		}
		else{
			printf("Parent: Error trying to fork() (%d)\n", errno);
		}
	return 0;
}
