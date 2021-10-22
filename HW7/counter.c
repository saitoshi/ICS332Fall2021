#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//Create a global mutex lock in order to use the thread function which will be the first added line
pthread_mutex_t threadLock ;

//This is where the typedef structure is declared as it keeps track of two variables
typedef struct {
  //The first variable is called counter which is an integer
  volatile int counter;
  //The second variable is called iterations which is an integer vairable keeping track of the iterations.
  int iterations;
} myarg_t;

// Function declaration where the threads are kept
void * thread(void * arg) {
  //create an instance called myarg_t structure with the parameter's struct variable
  myarg_t * my_args = (myarg_t *) arg;
  //Initiate the critical section allowing only one thread to execute a code at a time
  //Add the second line
  pthread_mutex_lock(&threadLock);
  /**
  Initiate a for loop where the counter i is initialized to 0.
  Keep on incrementing i depending on what is passed as a parameter
  */
  for(int i=0; i<my_args->iterations; i++) {
    //Increment the counter for given number of iteration.
    my_args->counter++;
  }
  //After exiting from the loop it will unlock and grant entry to the next thread
  //The insertion of the third line
  pthread_mutex_unlock(&threadLock);
  //After exiting from the for loop it will return NULL
  return NULL;
}

//The main area where inputs
int main(int argc, char ** argv) {

  int num_threads;
  myarg_t my_args;

  //If the argument count is not equal to 3 then print the following statement
  if( argc != 3 ) {
    //print the following statement
    fprintf(stderr, "Usage: ./counter <number of threads> <number of iterations>\n");
    //Then return 1
    return 1;
  }
  //Assign the first argument from the terminal to the number of threads using atoi which allows to convert input from terminal to an integer value
  num_threads = atoi(argv[1]);
  //Assign the second arugment from the terminal to number of interation using atoi which allows to convert terminal from input to integer values
  my_args.iterations = atoi(argv[2]);

  //Create an array to hold the numbers of threads from input
  pthread_t threads[num_threads];
  //set the my_args variable into 0
  my_args.counter = 0;

  /**
  Initiate a for loop where i is a counter initialized to 0.
  While i is less than the number of num_threads
  The specified number of threads are given from the thread array and is created and started.
  Then increment i.
  */

  for (int i=0; i<num_threads; i++) {
    pthread_create(&threads[i], NULL, thread, &my_args);
  }
  /**
  Initiate a for loop where i is a counter initialzied to 0
  Then wait for the completion of the thread currently running.
  */
  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  //Then delete the global lock
  pthread_mutex_destroy(&threadLock);
  
  //Display the user the expected counter value
  printf("expected counter value: %d\n", my_args.iterations * num_threads);
  //Display the counter value which is the actual value.
  printf("counter value: %d\n", my_args.counter);
  //Exit the program by returning 0
  return 0;
}
