/********************************/
// File: msq_server.c
// Server process creates MSQ and adds two number from the message

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* exit */
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
  int msq_id, l;
  struct request my_request;
  struct answer my_answer;

  // message queue creation
  if ((msq_id = msgget((key_t)KEY, 0750|IPC_CREAT|IPC_EXCL)) == -1) {
    perror("msgget");
    exit(1);
  }

  while(1) { // busy waiting
    // read the request of type 1  with no options
    if ((l = msgrcv(msq_id, &my_request, sizeof(struct request)-4, 1, 0)) == -1) {
      perror("msgrcv");
      exit(2);
    }
    my_answer.result = my_request.nb1 + my_request.nb2;
    my_answer.type = my_request.pid;  // message type is the client pid
    
    if (msgsnd(msq_id, &my_answer, sizeof(struct answer)-4,0) == -1)  {
      perror("msgsnd");
      exit(3);
    }
  }
  exit(0);
}
    
 
