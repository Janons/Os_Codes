#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <string.h>
#include <unistd.h>
#include <errno.h>




void main(int argc, char *argv[]){

}



void n_fork_creator(int n){
    int i ;

    for (i=0; i<n;i++){
        printf("i:%d\n",i);
        
        if (fork()){
            
        }

    }
}
