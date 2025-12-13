#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


int main(int argc, char* argv[]){


    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *args[64];


    if (argc < 2) { //safety check
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%s\n", argv[1]);

    fp = fopen(argv[1], "r");
    if (fp == NULL){
        perror("Error opening the file");
        exit(EXIT_FAILURE);
        
    }


    while((read = getline(&line, &len,fp))!= -1){

        int i = 0;

        //removing the "ends" 
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        //forking
        pid_t pid = fork();


        if (pid == 0){

            //if we are in the child

            char * token = strtok(line, " ");
            while(token != NULL){
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

              //execute
        execvp(args[0], args);

        }

    else{
        // --- PARENT PROCESS ---
        wait(NULL); // Wait for the child to finish
        sleep(3);   // Pause for 3 seconds as requested

    }
}
}