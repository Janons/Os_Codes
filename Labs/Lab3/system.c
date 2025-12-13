#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char* argv[]){


    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;


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

        //removing the "ends" 
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        fprintf(stdout, "The code is  %s\n",line );

        system(line);
        sleep(3);
    }

    fclose(fp);
    if (line){
        free(line);
    }
    exit(EXIT_SUCCESS);
}