#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_STRING_SIZE 256

/** Prototypes **/
void execute_plain(char *program, char *const argv[]);

void execute_output_to_file(char *cmd, char *const argv[], 
    char *filename);

void execute_output_to_other(char *cmd1, char *const argv1[], 
    char *cmd2_with_argv2);

/* Simple function to get a string input */
void get_string_input(char *msg, char **string) {
  char input[MAX_STRING_SIZE];

  while(1) {
    fprintf(stdout, "> %s ", msg);  
    char *return_value = fgets(input, MAX_STRING_SIZE, stdin);

    // On EOF (i.e., ^D) exit
    if (return_value == NULL) {
      printf("\n");
      exit(0);
    }

    // Remove trailing newline
    char *newline;
    if ((newline = strchr(input, '\n')) != NULL) {
      *newline = '\0';
    }

    // Break out if input is non-empty
    if (strlen(input) > 0) {
      break;
    }
  }
  *string = strdup(input);
  return;
}

/* Simple function to get a Y/N input */
int get_yes_no_input(char *msg) {

  while(1) {
    fprintf(stdout, "> %s [Y/N] ", msg);  
    // This is a non-portable way of avoiding the need for typing ENTER
    system ("/bin/stty raw");
    int return_value = fgetc(stdin);

    // This is non-portable and ugly (i.e., might change the terminal's behavior
    // after this program completes..)
    system ("/bin/stty cooked");

    printf("\n");

    switch ((unsigned char) return_value) {
      case 13: // CARRIAGE RETURN
        continue;
      case 4: // EOT
        exit(0);
      case 'Y':
      case 'y':
        return 1;
      default:
        return 0;
    }
  }
}

/* Simple function to parse a command string. Returns non-zero on failure */
int parse_cmd_string(char *cmd_string, char **cmd, char **cmd_argv[], char **sanitized_cmd_string) {

  if (sanitized_cmd_string) {
	  *sanitized_cmd_string = strdup("");
  }

  char *ptr;
  int count = 0;
  while ((ptr = strsep(&cmd_string, " \t"))) {
    if (*ptr == '\0') {
      continue;
    }
    count++;

    if (count == 1) {
      *cmd = strdup(ptr);
    }

    if (cmd_argv) {
      *cmd_argv = (char **) realloc(*cmd_argv, count * sizeof(char *));
      (*cmd_argv)[count-1] = strdup(ptr);
    }

    if (sanitized_cmd_string) {
      *sanitized_cmd_string = realloc(*sanitized_cmd_string, 
		                      (strlen(*sanitized_cmd_string) + strlen(ptr) + 2) * sizeof(char));


      strcat(*sanitized_cmd_string, ptr);
      strcat(*sanitized_cmd_string, " ");
    }
  }

  // If no command, return an error
  if (count == 0) {
    return 1;
  }

  // Add the NULL-terminating entry
  if (cmd_argv) {
    *cmd_argv = (char **) realloc(*cmd_argv, (count+1) * sizeof(char *));
    (*cmd_argv)[count] = NULL;
  }

  if (sanitized_cmd_string) {
    *sanitized_cmd_string = realloc(*sanitized_cmd_string, 
		                    (strlen(*sanitized_cmd_string) + 1) * sizeof(char));
    strcat(*sanitized_cmd_string, "");
  }

  return 0;

}


/* Main function */
int main(int argc, char **argv) {

  // Main loop
  while (1) {   
    // Get the command path
    char *cmd = NULL;
    char **cmd_argv = {NULL};
    int output_redirect_to_file = 0;
    char *output_redirect_filepath = NULL;
    int output_redirect_to_other_cmd = 0;
    char *other_cmd = NULL;
    char *other_cmd_with_argv = NULL;

    // Get a command
    char *cmd_string;
    get_string_input("Enter a command you want to run: ", &cmd_string);
    if (parse_cmd_string(cmd_string, &cmd, &cmd_argv, NULL)) {
      fprintf(stdout, "** Invalid command and/or arguments **\n");
      continue;
    }

    // Output redirect to file?
    output_redirect_to_file = get_yes_no_input("Should the output be re-directed to a file?");

    if (output_redirect_to_file) {
      // Get the file name
      get_string_input("Enter the filepath: ", &output_redirect_filepath);
    } else {
      output_redirect_to_other_cmd = get_yes_no_input("Should the output be re-directed to another command?");
      if (output_redirect_to_other_cmd) {
        char *other_cmd_string;
        get_string_input("Enter that other command: ", &other_cmd_string);
        if (parse_cmd_string(other_cmd_string, &other_cmd, NULL, &other_cmd_with_argv)) {
          fprintf(stdout,"Invalid command and/or arguments\n");
          continue;
        }
      }
    }

    // Perform the requested action
    if ((!output_redirect_to_file)  && (!output_redirect_to_other_cmd)) {

      execute_plain(cmd, cmd_argv);

    } else if (output_redirect_to_file) {

      execute_output_to_file(cmd, cmd_argv, output_redirect_filepath);

    } else if (output_redirect_to_other_cmd) {

      execute_output_to_other(cmd, cmd_argv, other_cmd_with_argv);

    } else {

      fprintf(stdout,"** Internal error **\n");
      exit(1);

    }

    // free some memory... so annoying
    free(cmd);
    for (int i=0; cmd_argv[i]; i++) {
	    free(cmd_argv[i]);
    }
    free(cmd_argv);
    free(other_cmd);
    free(other_cmd_with_argv);
    free(output_redirect_filepath);

  }
}

#include "solution.c"

