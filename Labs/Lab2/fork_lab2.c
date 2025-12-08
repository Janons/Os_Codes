#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <string.h>
#include <unistd.h>
#include <errno.h>

void create_processes(int n, pid_t pid, pid_t pid2){
    int i =0;
    int status;

    //creates 2^n children
    for (i; i<n;i++){
        pid = fork(); //we create the process here

        if(!pid){
            //child
            fprintf (stdout, "Child : PID=%d; FatherPID=%d; ReturnPID=%d\n",
             getpid(), getppid(), pid);
             sleep(5);
             fprintf(stdout,"child is complete");
             status = 123;
             exit(6);


        }
        else{
            pid2 = fork();

        }
       

        }
}


    




int main(int argc, char* argv[]){
    pid_t pid,cpid

}