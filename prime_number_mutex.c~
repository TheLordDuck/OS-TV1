#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdbool.h>

struct args{
  int id;
  int start;
  int end;
};

bool isPrimeNumber(int n){
  int flag=0;
  for(int i = 2; i <= n / 2; i++){
    if(n % i == 0){
      flag = 1;
      break;
    }
  }

  if(flag==0){
    return true;
  } else {
    return false;
  }
}

void* calculatePrime(void *arguments){
  struct args *args = arguments;
  int id=args->id;
  int start=args->start;
  int end=args->end;
  for(int i = start; i <= end; i++){
    if(isPrimeNumber(i)){
      printf("Thread with id (%d) has found a prime number (%d).\n", id, i);
    }
  }
  return 0;
}

int main()
{
  pthread_t th[10];
  int id=1;
  int start=1;
  int inc=1000000;
  int end = inc;
  for(int i = 0; i < 10; i++){
    struct args *args = (struct args *)malloc(sizeof(struct args));
    if(i==0){
      args->id = id;
      args->start = start;
      args->end = inc;
    } else {
      id=id+1;
      start=start+inc;
      end=end+inc;
      args->id = id;
      args->start = start;
      args->end = end;
    }
    pthread_create(&th[i], NULL, calculatePrime, (void *)args);
  }
  //joins
  for(int i = 0; i < 10; i++){
    pthread_join(th[i], NULL);
  }
  return 0;
}
