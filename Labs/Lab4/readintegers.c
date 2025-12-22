#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <string.h>
#include <unistd.h>
#include <errno.h>


#define MAX_Lines 100
#define MAX_LEN 10


int main(int argc, char* argv[]){

    
    char data[MAX_Lines][MAX_LEN];

    //files
    FILE *infile;
    FILE *even_ptr;
    FILE *odd_ptr;

    //buffer
    unsigned char buffer[5];



    //open the files
    infile = fopen("infile.txt","r");
    odd_ptr = fopen("odd.txt", "w");
    even_ptr = fopen("even.txt","w" );

    

    //line tracker
    int line = 0;
    int int_holder;

    while (!feof(infile) && !ferror(infile)){

        if (fgets(data[line], sizeof(buffer), infile)){

            
            int_holder = atoi(data[line]);


            
            if (int_holder %2 == 0){
                printf("%d is even\n", int_holder);

                fwrite(&int_holder, sizeof(int_holder),1,even_ptr);
                
            }

            else{
                fwrite(&int_holder, sizeof(int_holder),1,odd_ptr);
            }


        line++;
        if (line >= MAX_Lines) break;
            
        }
        


    }
    fclose(infile);
    fclose(even_ptr);
    fclose(odd_ptr);



    return 0;

}