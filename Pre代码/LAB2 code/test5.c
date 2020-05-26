#include<stdio.h> 
#include<errno.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
void *myThread(void *arg){
	printf("Thread ran\n");
	pthread_exit(arg);
}
int main(){
	int ret;
	pthread_t mythred;
	ret = pthread_create(&mythred, NULL, myThread, NULL);
	if(ret != 0){
		printf("Can not create pthread (%s)\n", strerror(errno));
		exit(-1);
	}else if (ret == 0){
		printf("Create pthread sucessfully!\n");
	}
	return 0;
}
