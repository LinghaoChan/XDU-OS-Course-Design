#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
void catch_ctlc(int sig_num){
	printf("Caught Control-C\n");
	fflush(stdout);
}
int main(){
	signal(SIGINT, catch_ctlc);
	printf("Go ahead, make my day\n");
	pause();
	return 0;
}
