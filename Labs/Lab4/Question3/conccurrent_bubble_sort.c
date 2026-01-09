#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define N 50

int main(int argc, char** argv){

     int i, fd, count, val,j,n;
    int vet[N] = {0, 10, 5, 20, 15, 30, 25, 40, 35, 50, 45, 60};

    pid_t pid; //pid holder



     if (argc != 2) {
    fprintf (stderr, "usage: %s fileName\n", argv[0]);
    exit (-1);}

    //get the argv[2]
    n = atoi(argv[2]);

  /*
   * Write File
   */
  fd = creat(argv[1], 0666);
  if (fd == -1) {
    fprintf(stderr, "Cannot create file %s\n", argv[1]);
    exit (-1); 
  }

  fprintf (stdout, "Reading: ");
  for (i=0; i<N; i++) {
    write (fd, &vet[i], sizeof (int));
    fprintf (stdout, "%2d ", vet[i]);
  }
  fprintf (stdout, "\n");

  close (fd);
  
for (i=0; i<n-1; i++) {
  for (j=0; j<n-1-i; j++) {
    pid = fork();
    //create the father
    if(fork>0){
        /*father must wait for the children*/
        wait((int*) 0);
    }
    else{
        
    }

  }
}
}