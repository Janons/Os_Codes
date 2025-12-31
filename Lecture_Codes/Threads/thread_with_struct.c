#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


#define NUM_THREADS	4

char *messages[NUM_THREADS];

struct thread_data {
   int thread_id;
   int sum;
   char *message;
};


//this prevents the race condition from happening
struct thread_data thread_array[NUM_THREADS];



//hello function for threads
void *PrintChar(void *threadarg){

}


// Function to interactively read input from stdin
char* getStdin(char *array) {
    int i = 0;
   
    //standard way to read from the terminal
    char *line = NULL;
    size_t len = 0;
    ssize_t read =0;

    printf("Please enter input for %d threads.\n", NUM_THREADS);

    // Keep asking for input until we reach the maximum number of threads
    while (i < NUM_THREADS) {
        printf("Enter string for thread %d: ", i);
 
        // Read a string from standard input
        read = getline(&line, &len,stdin);
        if (read == -1){
            break;
        }
        print("line = %s", line);
        array[i] = line;
        i++;
    }
    free(line);
    return array;
}


//main function

int main(int argc, char*argv){
    //to prevent the race condition
    pthread_t thread[NUM_THREADS];
    struct thread_data v[NUM_THREADS];
    int i, rc, sum;

   
    if (argc<2){
        perror("Number of arguments insufficnet");
        exit(EXIT_FAILURE);
    }

    //array to hold the values from the stdin
    char *ptr = (char*)malloc(sizeof(char) * NUM_THREADS);

    ptr = getStdin(ptr);

    //for loop to create the threads
    for (i = 0; i<NUM_THREADS; i++){
        thread_array[i].thread_id = i;
        thread_array[i].message = ptr[i];

        //initiating the thread
        rc = pthread_create(&thread[i],NULL, PrintChar, (void*)&thread_array[i]);
        
        
        
    }

    pthread_exit(NULL);

}