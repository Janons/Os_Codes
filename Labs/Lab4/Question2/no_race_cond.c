
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


//function definition
static void signalParent(int);
static void signalChild(int);


//child and the parent signal handlers
void signalChild(int signum){
     fprintf (stdout, "Child pid = %d\n", getpid());
}

void signalParent (
  int signum
  )
{
  fprintf (stdout, "Parent pid = %d\n", getpid());
}


//child and parent behaviours
int child(int sec){
    fprintf(stdout,"Child %d: SLEEPPS\n", getpid());
    sleep(sec);
    fprintf(stdout, "The child woke up");

    return 0;
}



int father(int sec){

    int status;
    fprintf(stdout, "PARENT: I'm the parent %d!\n", getpid());
    fprintf(stdout, "PARENT: Sleep!\n");
    sleep(sec);
    fprintf(stdout, "PARENT: Waited child  %d\n",wait(&status));
    fprintf(stdout, "PARENT: Finish!\n");

  return 0;


}


int main(int argc, char *argv[]){

    //parameters
    int t_c,t_p;
    pid_t pid; //tracking the pid of the process

    t_c = atoi(argv[1]);
    t_p = atoi(argv[2]);

    //creating the processes
    pid = fork();
    if (pid == 0){
         //child
        fprintf (stdout, "Child pid = %d\n", getpid());
        
        //the signal
        signal (SIGUSR1, signalChild);
        //synchronization
        pause();
        //child bejhaviour
        child(t_c);
        

    }
    else{
        fprintf (stdout, "Parent pid = %d\n", getpid());
        signal(SIGUSR1, signalParent);
         pause();
        fprintf (stdout, "Breakpoint line.\n");
        father(t_p);

    }


    return 0;
}