#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <string.h>
#include <unistd.h>
#include <errno.h>

//micros

#define MAX_COUNT 200
#define BUF_SIZE 100


void main(void){

    pid_t pid;

    //here we are checking if we are dealing with
    //a child process
    if (pid == 0){
        ChildProcess();
    }
    else{
    ParentProcess();
    }
}



void ChildProcess(void){
    int i;

    for (i = 1; i<MAX_COUNT;i++){

        printf("This line is from the child, value = %d\n",i);
        
    }
    printf("*** Child process is done");
}



void ParentProcess(void){

    int i;

    for (i=1 ; i< MAX_COUNT;i++){
        printf("This line is from parent \n");
    }
    printf("*** Parent is done*** \n");
}