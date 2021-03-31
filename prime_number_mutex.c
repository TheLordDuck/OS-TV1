#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdbool.h>

//global variables to make use of mutex
//pos is the pos where i put the elements in the variable array, because then its easier for the parent to order them one he has the array from the threads.
//primeNumbers is the pointer of our actual array where we are going to put our values found by the threads
int pos=0;
int *primeNumbers;
//mutex variable to use mutex_lock and unlock
pthread_mutex_t mutex;

//struct to pass it to the function of the pthread_create, so every threads knows his id, where to start and where to end
struct args{
  int id;
  int start;
  int end;
};

//function that returns true if n is a prime number or false if its not
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

//function used by the pthread_create function, when a thread is created
void* calculatePrime(void *arguments){
  struct args *args = arguments;
  int id=args->id;
  int start=args->start;
  int end=args->end;
  for(int i = start; i <= end; i++){
    if(isPrimeNumber(i)){
      printf("Thread with id (%d) has found a prime number (%d).\n", id, i);
      //lock mutex - because we are changing the global variables
      pthread_mutex_lock(&mutex);
      primeNumbers = realloc(primeNumbers, (pos+1) * sizeof primeNumbers);
      primeNumbers[pos]=i;
      pos++;
      pthread_mutex_unlock(&mutex);
      //unlock mutex - releasing the mutex for other threads to come
    }
  }
  return 0;
}

//main function
int main()
{
  //create 10 threads
  pthread_t th[10];
  //create the mutex
  pthread_mutex_init(&mutex, NULL);
  //values for the threads
  int id=1;
  int start=1;
  int inc=1000000;
  int end = inc;
  //creation of the 10 threads with diferent id, values to start and end values.
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
    //create each thread with same function, but different args pointer with his information, id, number of start, and end
    pthread_create(&th[i], NULL, calculatePrime, (void *)args);
  }
  //join - i join them because i want to make it paralel so i dont put every join in the main for, ecause it wont be parallel if i put it where the create is.
  for(int i = 0; i < 10; i++){
    pthread_join(th[i], NULL);
  }
  //printing the arrays i got from threads
  //printing the array that i got from threads filling it with prime numbers
  for(int i = 0; i < pos; i++){
    printf("%d ",primeNumbers[i]);
  }
  //printing the number of values in the arrray, notice that every execution its going to have the same number because of the mutex part we put
  printf("Values in the array: %d.\n", pos);
  //we destroy the mutex because we dont use it anymore
  pthread_mutex_destroy(&mutex);
  //algorithm that orders the numbers in the array - parent does the ordenation,
  //but array was filled with thread finding each prime number.
  for(int i = 0; i < pos; i++){
    for(int j = i+1; j < pos; j++){
      if(primeNumbers[i] > primeNumbers[j]){
	int tmp = primeNumbers[i];
	primeNumbers[i] = primeNumbers[j];
	primeNumbers[j] = tmp;
      }
    }
  }
  //once its ordered, we print it again
  //show ordered numbers in array
  printf("\n");
  for(int i = 0; i < pos; i++){
    printf("%d ",primeNumbers[i]);
  }
  return 0;
}
