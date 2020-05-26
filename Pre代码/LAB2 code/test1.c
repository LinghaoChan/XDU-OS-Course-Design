#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t myPid, myParentId;
	gid_t myGid;
	uid_t myUid;
	myPid = getpid();
	myParentId = getppid();
	myGid = getgid();
	myUid = getuid();

	printf("my process id is   %d\n", myPid);
	printf("my parent's process id is   %d\n", myParentId);
	printf("my group id is   %d\n", myGid);
	printf("my user id is   %d\n", myUid);
	return 0;
}
