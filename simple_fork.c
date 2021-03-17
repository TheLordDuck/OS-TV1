#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
  pid_t pid_fils = -1;
  pid_fils = fork();
  if(pid_fils == -1){
    perror("Fork failure\n");
    exit(EXIT_FAILURE);
  }
  printf("(%d) All you need is emacs.\n", getpid());
  sleep(1);
  printf("(%d) I miss my daddy! my father is (%d).\n", getpid(), getppid());
  sleep(10);
  exit(EXIT_SUCCESS);
}
