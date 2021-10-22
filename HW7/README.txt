@assignment ICS 332 Homework 7
@name Shinya Saito
@due date 2021/10/22

EXERCISE 2
Multiple concurrency bugs exist in counter.c. Fix the concurrency bugs in counter.c. In your README.txt, identify all the concurrency bugs you found (refer to line numbers in the original counter.c and also include an explanation of how you fixed them. Include the line numbers of your newly added code in your README.txt file. You should also have comments for your new lines of code in the modified counter.c.

From the given counter.c file the issue occurs around line 40 to 42, when the program runs the written thread function.
Concurrency issues will happen because there is a possibility of context switches between threads that will not save the increments for each iterations.
Therefore, to access within the thread function the global mutex lock was created.
After that within the thread function, a pthread_mutex_lock is invoked to allow only one thread to run the code at a time.
Finally, once the thread finishes the increment counter depending ont the given incremental value, invoke "pthread_mutex_unlock" to allow another thread to enter the critical section.

Below are the list of code I have inserted for the purpose of the exercise.
  -line 6: Created pthread_mutex_t threadLock which is for the global lock variable
  -line 22: pthread_mutex_lock(&threadLock); //inserts the ownership of the specified lock
  -line 33 pthread_mutex_unlock(&threadLock); // releases the lock and grants access to other threads waiting
  -line 75-77
  for (int i = 0; i < num_threads; i++) {
      pthread_join(threads[i], NULL);
    }
    // waits for all the threads to terminate
  - line 80 pthread_mutex_destroy(&threadLock); //deleted global variable
