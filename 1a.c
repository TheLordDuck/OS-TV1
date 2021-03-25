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

  if (pid == 0){
    //we are in process p2
    pid2 = fork();
    if(pid2 == 0){
      //we are in process p3
      pid3 = fork();
      if(pid3 == 0){
	//we are in process p4
	sleep(10);
	printf("Process p4 (%d) terminated, with parent p3 (%d)", getpid(), getppid());
      } else if (pid3 > 0){
	//wait(NULL);
	printf("Process p3 (%d) terminated, with parent p2 (%d).\n", getpid(), getppid());
      }
    } else if(pid2 > 0){
      wait(NULL);
      printf("Process p2 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
    }
  } else if(pid > 0){
    //we are in process p1
    wait(NULL);
    printf("Parent process terminated p1 (%d).\n", getpid());
  }
  return 0;
}
