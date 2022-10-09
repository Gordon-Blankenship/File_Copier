/*
    Tre Blankenship
    IT383 Spr22 - Dr. Kyoungwon Suh
    Program will copy a file from a source
    into 2 separate destinations precisely
    * Can handle .bin and .txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){

    // create buffer and size of bytes
    char buffer[1024];
    size_t byteSize;

    // Must be 3 args passed in to line
    if(argc == 4){
        // open files with command line
        FILE *dest1 = fopen(argv[1], "w+"); // Destination file 1
        FILE *dest2 = fopen(argv[2], "w+"); // Destination file 2
        FILE *source= fopen(argv[3], "w+"); // Source file

        // Ensure no errors in opening files
        if(ferror(dest1)){
            printf("Error opening destination file 1: %s\n", strerror(errno));
            exit(1);
        }
        if(ferror(dest2)){
            printf("Error opening destination file 2: %s\n", strerror(errno));
            exit(1);
        }
        if(ferror(source)){
            printf("Error opening source file: %s\n", strerror(errno));
            exit(1);
        }

        // Read into the buffer from the source until EOF
        while((byteSize = fread(buffer, 1, sizeof(buffer), source)) > 0){

            // Write to the destinations
            fwrite(buffer, 1, byteSize, dest1);
            fwrite(buffer, 1, byteSize, dest2);
            
        }

        // Close all 3 files
        fclose(dest1);
        fclose(dest2);
        fclose(source);
    }
    else{
        printf("Incorrect # of Arguments\n");
        printf("Correct Usage: ./executable destination1 destination2 source\n");
        exit(1);
    }

    return(0);
}