#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


int main(void){

    char word[256];
    char read_word[256];

    pid_t pid;
    int file1[2];
    int file2[2];

    //first pipe the process and see if its working
    if (pipe(file1)!= 0){


        //create the first child
        pid = fork();


        if (!pid){
        //we are inside the producer child
        //read from keyboard
        if (fgets(word, sizeof(word),stdin)){
            //send data to the parent
            if (write(file1[1],&word, sizeof(word)) == -1){return 2;}
            printf("Wrote %s\n to parent process",word );
        }
    }

    else{
    //parent process
    

    

    //sleep a little
    sleep(3);
    read(file1[0],&read_word,sizeof(read_word));
       
        //second pipe with the parent
        if(pipe(file2) == 0){
        //create the second child

        if (fork() == 0){
            //inside the second child

        }
        }
        
    }
}

        

}

    




/*

Notes
1) I will use single communication methods => half duplex

*/