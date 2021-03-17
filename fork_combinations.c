#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
  pid_t process_id;
  int status;

  if(fork() == 0){
    if(fork() == 0){
      printf("A");
    } else {
      process_id = wait(&status);
      printf("B");
    }
  } else {
    if(fork() == 0){
      printf("C");
      exit(0);
    }
    printf("D");
  }
  printf("0");
  return (0);
}
