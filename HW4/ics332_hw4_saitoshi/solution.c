
/*
 * A function that executes a command using fork and execv
 */
void execute_plain(char *cmd, char *const argv[]) {
  //fprintf(stdout,"Error: %s() is not implemented!\n\n", __FUNCTION__);
  // WRITE CODE HERE
  //declare the PID variable
  pid_t pid;
  //declare the variable for status
  int status = 0;
  //declare the variable for error
  int error;
  //do a fork
  pid = fork();

  /// for the child
  // if the pid is equal to 0
  if (pid == 0) {
    //
    freopen("/dev/null", "w", stderr);
    // set error to execv the command and argv input
    error = execv(cmd, argv);

    //if there is an error
    if (error == -1) {
      //set the exit into 1
      exit(1);
    }
    exit(0);
  }
  //do this for the parent
  else {
    //wait for the child
    wait(&status);

    //if the child ends successfully
    if (status == 0) {
      printf("  ** Command successful **\n");
    }
    //otherwise print failure
    else {
      printf("  ** Command failed **\n");
    }
  }
}

/*
 * A function that executes a command using fork and execv, but
 *  that redirects the command's output to a file
 */
void execute_output_to_file(char *cmd, char *const argv[], char *filename) {
  //fprintf(stdout,"Error: %s() is not implemented!\n\n", __FUNCTION__);
  // WRITE CODE HERE
  //variable declaration
  //application for processor ID
  pid_t pid;
  //variable declaration for status
  int status = 0;
  //int variable declaration for error
  int error;
  //fork
  pid = fork();

  ///CHILD
  if (pid == 0) {
    //open file /tmp/stuff which will be assigned file descriptor 1
    FILE *file = fopen(filename, "w");
    //if it is not the file then exit(1)
    if(!file) {
      exit(1);
    }


    close(1);
    dup(fileno(file));
    //
    freopen("dev/null","w",stderr);
    error = execv(cmd, argv);

    //if there is an error
    if (error == -1) {
      //set the exit into 1
      exit(1);
    }
    //otherwsie set the exit as 0
    exit(0);

  }
  //do this for the parent
  else {
    //wait for the child
    wait(&status);

    //if the child ends successfully
    if (status == 0) {
      printf("  ** Command successful **\n");
    }
    //otherwise print failure
    else {
      printf("  ** Command failed **\n");
    }
  }
}

/*
 * A function that executes a command using fork and execv, but
 *  that redirects the command's output to another command
 */
void execute_output_to_other(char *cmd1, char *const argv1[], char *cmd2_with_argv2) {
  //fprintf(stdout,"Error: %s() is not implemented!\n\n", __FUNCTION__);
  // WRITE CODE HERE
  //declare the PID variable
  pid_t pid;
  //declare the variable for status
  int status = 0;
  //declare the variable for error
  int error;

FILE * file = popen(cmd2_with_argv2, "w");
  //do a fork
  pid = fork();

  // Child
  if (pid == 0){

      // close pipe
      close(1);
      dup(fileno(file));
      // Redirect STDERR
      freopen("/dev/null", "w", stderr);
      error = execv(cmd1, argv1);

      //if the error is -1
      if(error == -1){
        //set the exit into 1
          exit(1);
      }

      exit(0);
  }
  // Parent
  else{
      // wait child
      wait(&status);
      // if child ended fine, status should be 0, else STDERR.
      if(status == 0){
          printf("  ** Command successful  **\n");
      }
      // else, if error STDERR
      else{
          printf(" ** Command failed  **\n");
      }

  }
  //pclose the file 
   pclose(file);

}
