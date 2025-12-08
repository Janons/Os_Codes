#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *PrintHello(){
    pthread_t tid;

    sleep(2);
    //we ge the thread id here
    tid = pthread_self();

    //thread pringint
    fprintf (stdout, "Thread see thread id (TID, unsigned int?!) = %d\n",
    (unsigned int) tid);

    //exit the thread
    pthread_exit(NULL);


}

int main(int argc, char *argv[]){
    pthread_t tid;
    int rc;

    fprintf(stdout,"Creating the first thread\n");
    //thread creation
    rc = pthread_create(&tid, NULL,PrintHello,NULL);

    //check if the thread was created sucesfully
    if (rc){
        fprintf(stderr, "Errorrrr");
        exit(-1);
    }

     fprintf (stdout, "Main see thread id (TID, unsigned int?!)= %d\n",
    (unsigned int) tid);

  // Check this out: Enable one of the two
  if (argc > 1) {
    //exit (0);
    return (0);
  } else {
    pthread_exit (NULL);
  }




}