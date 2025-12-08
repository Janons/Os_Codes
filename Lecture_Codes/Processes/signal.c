
#include <signal.h>
#include <stdio.h>
#include <unistd.h>


//basic functions to handle a signal

void handle(int sig){
    printf("Recieved signal %d  ", sig);
    printf("Are we even here?");
    exit(1);
}


int main(){
    int i = 0;
    while (1){
        
        //signal decleration
        signal(SIGINT, handle);
        sleep(2);

        //increase the counter
        i+= 1;
        printf("Loop iteration: %d\n", i);

        //the condition
        if (i == 4){ 

            raise(SIGTSTP);

        }


    }

    return 0;
}