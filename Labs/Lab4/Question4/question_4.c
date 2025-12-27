#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h> 


int main(void){

    char word[256];
    char read_word[256];

    pid_t pid;
    int file1[2];
    int file2[2];

    //first pipe the process and see if its working
    if (pipe(file1) == -1) { perror("pipe"); exit(1); }
    //create the first child
     pid = fork();


    if (!pid){
     //we are inside the producer child
     close(file1[0]); //in the child since we are not reading
     //read from keyboard
    if (fgets(word, sizeof(word),stdin)){
            //send data to the parent
        if (write(file1[1],&word, sizeof(word)) == -1){return 2;}
        printf("Wrote %s\n to parent process",word );
        }

    close(file1[1]); //close the writing
    }

    else{
    //parent process

    //sleep a little
    sleep(3);
    close(file1[1]);//unused write end
    read(file1[0],&read_word,sizeof(read_word));
    printf("Read %s\n from parent process", read_word);
    close(file1[0]);
       
        //second pipe with the parent
        if(pipe(file2) == 0){
            pid_t pid2 = fork();
            
            if (pid2== 0){
            //inside the second child
            close(file2[1]);// child 2 only reads
            

            //write to child
            char child2_buffer[256];
            read(file2[0],&child2_buffer,sizeof(child2_buffer));
            close(file2[0]);//done reading

            //turn all the word into uppercase
            char *s = child2_buffer;
            while(*s){
                *s = toupper((unsigned char)*s);
                s++;
            }

            fprintf(stdout, "word is ->>> %s\n", child2_buffer);
            exit(0);

        }
        else {
                // --- INSIDE PARENT ---
                close(file2[0]); // Parent only writes to Child 2, close read end
                
                // Send the data to Child 2
                write(file2[1], &read_word, sizeof(read_word));
                close(file2[1]);

                // Wait for both children
                wait(NULL);
                wait(NULL);
        }
    }
    
}
   return 0; 
}

        



    




/*

Notes
1) I will use single communication methods => half duplex

*/