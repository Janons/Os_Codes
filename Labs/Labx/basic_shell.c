#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
  

//function declerations
void lsh_loop(void);
char *line(void);

//the main function
int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}


//loop of the shell
//gets the line
//splits into arguments
//executes

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

//File getting
char *line(void){
    char *line = NULL;
    ssize_t line_len = 0;


    if (getline(&line, &line_len,stdin)!= -1){
        line[line_len -1] = '\0';

        printf("line = %s", line);

    }
    else{
        if (feof(stdin)){
            exit(EXIT_SUCCESS);
        }
        else{
             puts("ERRRORRRRRRRRRRRRRRR");
        }
       
    }


    return line;

}