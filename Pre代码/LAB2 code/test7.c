#include <pthread.h>
#include <stdio.h>
#include <assert.h>
pthread_mutex_t cntr_mutex = PTHREAD_MUTEX_INITIALIZER;
long protVariable = 0L;

void *myThread(void *arg){
	int i, ret;
	for(i=0; i<10000; i++){
		ret = pthread_mutex_lock( &cntr_mutex );
		assert( ret == 0 );
		protVariable++;
		ret = pthread_mutex_unlock( &cntr_mutex );
		assert( ret == 0 );
	}
	pthread_exit(NULL);
}

#define MAX_THREADS 10

int main(){
	int ret, i;
	pthread_t threadIds[MAX_THREADS];
	for(i=0; i<MAX_THREADS; i++){
		ret = pthread_create( &threadIds[i], NULL, myThread, NULL);
		if(ret != 0){
			printf("Error creating thread %d\n", (int)threadIds[i]);
		}
	}
	for(i = 0; i<MAX_THREADS; i++){
		ret = pthread_join( threadIds[i], NULL);
		if(ret != 0){
			printf("Error joining thread %d\n", (int)threadIds[i]);
		}
	}
	printf("The protected variable value is %ld\n", protVariable);
	ret = pthread_mutex_destroy( & cntr_mutex );
	if(ret != 0 ){
		printf("Could not destroy the mutex\n");
	}
	return 0;
}
