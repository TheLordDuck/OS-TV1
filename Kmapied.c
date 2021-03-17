#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
  int i;
  for (i=1;i<30;i++){
    printf("(%d) %d km a pied, ça use, ça use. %d km a pies, ça use les souliers. \n", getpid(), i ,i);
    sleep(1);
  }
  return (EXIT_SUCCESS);
}
