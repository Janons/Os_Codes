#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h> /* For wait */
#include <sys/wait.h>

//defining the signal handlers
static void signal_handler(int);



//signal handler
static void signal_handler(int signo){

    if (signo == SIGUSR1){
        printf("Received SIGUSR1\n from P1");
    }

    else if (signo == SIGUSR2){
        printf("Received SIGUSR2\n from P2");
    }

    else{
        printf("Signal %d\n", signo);
    }

}

void P1(pid_t cpid){
    int i = 0;

    if (i > 3){

        kill(cpid,SIGUSR1);
        
        
    }
    i++;
    sleep(1);
    signal(SIGUSR1, signal_handler);

}


void P2(){
    int i = 0;

    if (i > 3){

        kill(getppid,SIGUSR2);
        wait((int *)0);    
    }
    i++;
    sleep(1);
    signal(SIGUSR2, signal_handler);

}





int main(void){

    pid_t pid;

    //instantiaon of signal handlers
    if (signal(SIGUSR1, signal) == SIG_ERR){
        printf("Signal handler error.111 \n");

        return 1;
        
    }

     //instantiaon of signal handlers
    if (signal(SIGUSR2, signal) == SIG_ERR){
        printf("Signal handler error.222 \n");

        return 1;
        
    }

    printf("SCreator\n");

    //do the fork
    pid = fork(); //two processes are created
    if (pid > (pid_t) 0){
        P1(pid);
        wait((int *) 0);
    }
    else{
        P2();
        exit(0);
    }


 
}