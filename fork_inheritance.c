#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
  pid_t son_pid1 = -1;
  pid_t son_pid2 = -1;
  const char *kingdom = "none";

  kingdom="Alderaan";

  printf("I'm Obi-wan kenobi, PID(%d), PPID(%d). My kingdom is %s.\n",
	 getpid(), getppid(), kingdom);
  
  son_pid1 = fork();

  if(son_pid1 != 0){
    son_pid2 = fork();
    if(son_pid2 == 0){
      printf("I'm Anakin Skywalker, PID(%d), PPID(%d). My kingdom is %s.\n",
	     getpid(), getppid(), kingdom);
      kingdom = "the Death Star";
      printf("But call me Dark Vader, PID (%d), PPID(%d). My kingdom is %s.\n",
	     getpid(), getppid(), kingdom);
    }
  } else {
    printf("I'm Luke Shywalker, PID(%d), PPID(%d). My kingdom is %s.\n",
	   getpid(), getppid(), kingdom);
    kingdom = "Tatooine";
    printf("I'm now a Jedi, PID(%d), PPID(%d). My new kingdom is %s.\n",
	   getpid(), getppid(), kingdom);
  }
  wait(NULL);
  wait(NULL);
  exit(EXIT_SUCCESS);
}
