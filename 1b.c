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
  pid2 = fork();
  
  if (pid == 0 && pid2 > 0){
    //we are in process p3
    wait(NULL);
    printf("Process p3 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
  } else if (pid == 0 && pid2 == 0){
    //we are in process p5
    printf("Process p5 (%d) terminated, with parent p3 (%d).\n", getpid(), getppid());
  } else if (pid > 0 && pid2 == 0){
    //we are in p2
    printf("Process p2 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
  } else if (pid > 0 && pid2 > 0){
    //we are in the parent process
    pid3 = fork();
    if(pid3 == 0){
      //we are in process p4
      sleep(10);
      printf("Process p4 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
    } else if (pid3 > 0){
      //we are in the parent
      wait(NULL);
      wait(NULL);
      printf("Parent process p1 (%d) terminated.\n", getpid());
    }
  }
  return 0;
}
