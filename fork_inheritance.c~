#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
  pid_t son_pid1 = -1;
  pid_t son_pid2 = -1;
  pid_t son_pid3 = -1;
  son_pid1 = fork();
  son_pid2 = fork();
  son_pid3 = fork();
  
  printf("(%d) Allors on dance (%d) (%d) (%d)\n", getpid(),
	 son_pid1, son_pid2, son_pid3);
  wait(NULL);
  printf("Et la tu t'dis que cest fini, (%d).\n", getpid());
  wait(NULL);
  wait(NULL);
  exit(EXIT_SUCCESS);
}
