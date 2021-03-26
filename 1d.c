#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  // fork() Create a child process
  int pid, pid2, pid3, pid4, pid5, pid6, pid7;
  pid = fork();
  pid2 = fork();

  if(pid == 0 && pid2 > 0){
    //we are in p2
    pid3 = fork();
    if(pid3 == 0){
      //we are in p5
      printf("Process p5 (%d) terminated, with parent p2 (%d).\n", getpid(), getppid());
    } else if(pid3 > 0){
      wait(NULL);
      wait(NULL);
      printf("Process p2 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
    }
  } else if(pid > 0 && pid2 == 0){
    //we are in p3
    pid4 = fork();
    pid5 = fork();
    if(pid4 > 0 && pid5 == 0){
      //we are in p7
      pid7 = fork();
      if(pid7 == 0){
	//we are in p10
	printf("Process p10 (%d) terminated, with parent p7 (%d).\n", getpid(), getppid());
      } else if(pid7 > 0){
	wait(NULL);
	printf("Process p7 (%d) terminated, with parent p3 (%d).\n", getpid(), getppid());
      }
    } else if(pid4 == 0 && pid5 > 0){
      //we are in p6
      pid6 = fork();
      if(pid6 == 0){
	//we are in p9
	printf("Process p9 (%d) terminated, with parent p6 (%d).\n", getpid(), getppid());
      } else if(pid6 > 0){
	wait(NULL);
	wait(NULL);
	printf("Process p6 (%d) terminated, with parent p3 (%d).\n", getpid(), getppid());
      }
    } else if(pid4 == 0 && pid5 == 0){
      //we are in p8
      printf("Process p8 (%d) terminated, with parent p6 (%d).\n", getpid(), getppid());
    } else if(pid4 > 0 && pid5 > 0){
      wait(NULL);
      wait(NULL);
      printf("Process p3 (%d) terminated, with parent p1 (%d).\n", getpid(), getppid());
    }
  } else if(pid == 0 && pid2 == 0){
    //we are in p4
    printf("Process p4 (%d) terminated, with parent p2 (%d).\n", getpid(), getppid());
  } else if(pid > 0 && pid2 > 0){
    //we are in parent process p1
    wait(NULL);
    wait(NULL);
    printf("Parent process p1 (%d) terminated.\n",getpid());
  }
  
  return 0;
}
