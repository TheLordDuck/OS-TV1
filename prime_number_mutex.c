#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdbool.h>

int pos=0;
int *primeNumbers;
pthread_mutex_t mutex;

struct prime *prime_struct;

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
      //lock mutex
      pthread_mutex_lock(&mutex);
      primeNumbers = realloc(primeNumbers, (pos+1) * sizeof primeNumbers);
      primeNumbers[pos]=i;
      pos++;
      pthread_mutex_unlock(&mutex);
      //unlock mutex
    }
  }
  return 0;
}

int main()
{
  pthread_t th[10];
  pthread_mutex_init(&mutex, NULL);
  int id=1;
  int start=1;
  int inc=10;
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
  //join
  for(int i = 0; i < 10; i++){
    pthread_join(th[i], NULL);
  }
  //printing the array that i got from threads filling it with prime numbers
  for(int i = 0; i < pos; i++){
    printf("%d ",primeNumbers[i]);
  }
  pthread_mutex_destroy(&mutex);
  //algorithm that orders the numbers in the array - parent does the ordenation,
  //but array was filled with thread finding each prime number.
  
  return 0;
}
