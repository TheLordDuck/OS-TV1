#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	// fork() Create a child process
  int pid, pid2, pid3;
	pid = fork();
	if (pid == 0) {
	  printf("Im process p2 (%d), my parent is p1 (%d).\n", getpid(), getppid());
	  sleep(10);
	  printf("Im process p2 (%d), my parent is p1 (%d) 10 seconds later.\n", getpid(), getppid());
	} else if(pid != 0){
	  printf("Im process p1 (%d).\n", getpid());
	  pid2 = fork();
	  if(pid2 == 0){
	    printf("Im process p3 (%d), my parent is p1 (%d).\n", getpid(), getppid());
	    sleep(10);
	    printf("Im process p3 (%d), my parent is p1 (%d) 10 seconds later.\n", getpid(), getppid());
	  } else if(pid3 != 0){
	    sleep(2);
	  }
	}
	return 0;
}
