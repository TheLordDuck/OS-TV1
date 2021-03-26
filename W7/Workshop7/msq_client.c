/********************************/
// File: msq_server.c
// Client process sends in the MSQ 314

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* exit */
#include <unistd.h>		/* getpid */
#include <sys/msg.h>		/* msq system calls*/ 
#define KEY 314

struct request {
  long type;
  int nb1;int nb2;
  pid_t pid;
};

struct answer {
  long type;
  int result;
};

 

int main(void)
{
  int msq_id, l, nb1, nb2;
  struct request my_request;
  struct answer my_answer;

  // gets the MSQ internal id
  if ((msq_id = msgget((key_t)KEY, 0)) == -1) {
    perror("msgget");
    exit(1);
  }

  // ask for two numbers
  printf(" Please, enter two numbers: ");
  scanf("%d %d", &nb1, &nb2);
  
  //prepares the message and send the request
  my_request.type = 1;
  my_request.nb1 = nb1;
  my_request.nb2 = nb2;
  my_request.pid = getpid();

  if (msgsnd(msq_id, &my_request, sizeof(struct request)-4,0) == -1)  {
    perror("msgsnd");
    exit(2);
  }

  // receive answer from server
  if ((l = msgrcv(msq_id, &my_answer, sizeof(struct answer)-4, getpid(), 0)) ==-1) {
    perror("msgrcv");
    exit(2);
  }
  printf(" addtion of two number is : %d \n", my_answer.result);
  exit(0);
}
    
 
