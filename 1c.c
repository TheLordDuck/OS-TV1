#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  // fork() Create a child process
  int pid, pid2, pid3, pid4;
  pid = fork();
  pid2 = fork();

  if(pid == 0 && pid2 > 0){
    //we are in p2
    pid3 = fork();
    if(pid3 == 0){
      //we are in p6
      printf("Process p6 (%d) terminated, with parent p2 (%d).\n", getpid(), getppid());
    } else if (pid2 > 0 && pid3 > 0){
	wait(NULL);
	wait(NULL);
	printf("Process p2 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
    }
  } else if(pid == 0 && pid2 == 0){
    //we are in p5
    printf("Process p5 (%d) terminated, with parent p2 (%d).\n", getpid(), getppid());
  } else if(pid > 0 && pid2 == 0){
    //we are in p3
    printf("Process p3 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
  } else if(pid > 0 && pid2 > 0){
    //we are in p1
    pid4 = fork();
    if(pid4 == 0){
      //we are in p4
      printf("Process p4 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
    } else {
      wait(NULL);
      wait(NULL);
      wait(NULL);
      printf("Parent process p1 (%d) terminated.\n",getpid());
    }
  }
  
  return 0;
}
