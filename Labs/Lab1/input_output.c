#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 1024

int main(
    int argc,
    char *argv[])
{
    FILE *fs, *fd;
    int c;
    char name[SIZE], buffer[SIZE];

    
    fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
   
    // open the source
    fs = fopen(argv[1], "r");
    if (fs == 0){
        fprintf(stderr, "error opening source '%s': %s\n", argv[1], strerror(errno));
        return EXIT_FAILURE;
    }

    // open the destination (create/overwrite)
    fd = fopen(argv[2], "w");
    if (fd == 0){
        fprintf(stderr, "error opening destination '%s': %s\n", argv[2], strerror(errno));
        fclose(fs);
        return EXIT_FAILURE;
    }

    //start copying
    while ((c = fgetc(fs)) != EOF) {
        fputc(c, fd);
    }

    //close the files
    fclose(fs);
    fclose(fd);
    return EXIT_SUCCESS;


    /*
    same code could have been written like this
    // Solution 3
  sprintf (name, "%s.3", argv[2]);
  fs = fopen (argv[1], "r");
  fd = fopen (name, "w");
  while (fgets (buffer, 132, fs) != NULL) {
    fputs (buffer, fd);
  }
  fclose(fs);
  fclose(fd);

  return (0);*/
}