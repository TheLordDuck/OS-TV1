#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
  while(1){
    if(fork() == 0){
      printf("[son] pid (%d) from [parent] pid (%d).\n",getpid(), getppid());
      exit(EXIT_SUCCESS);
    }
  }
  wait(NULL);
}
