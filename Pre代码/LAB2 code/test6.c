#include <pthread.h>
#include <stdio.h>
void *myThread(void *arg){
	printf("Thread %d started\n", (int)arg);
	pthread_exit(arg);
}
#define MAX_THREADS 5
int main(){
	int ret, i, status;
	pthread_t threadIds[MAX_THREADS];
	for(i = 0; i<MAX_THREADS; i++){
		ret = pthread_create(&threadIds[i], NULL, myThread, (void*)i);
		if(ret != 0){
			printf("Error creating thread %d\n", (void*)i);
		}
	}
	for(i = 0; i<MAX_THREADS; i++){
		ret = pthread_join(threadIds[i], (void **)&status);
		if(ret != 0){
			printf("Error joining thread %d\n", (void *)i);
		}
		else{
			printf("Status = %d\n", status);
		}
	}
	return 0;
}
