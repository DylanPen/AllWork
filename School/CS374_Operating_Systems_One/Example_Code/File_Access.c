#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* file = fopen("file.csv", "r"); //read = "r", write = "w", append = "a"
    if(file == NULL){
        printf("%s\n", "failed to open file");
    }

    //File offset: imaginary cursor that traverses the file as you read from it

    char* line;
    size_t n = 0;
    size_t string_length = getline(&line, &n, file); 
    //can use stdin instead of file for user input
    line[string_length - 1] = '\0';

    printf("%s\n", line);

    free(line);

    //if I copied code above, it would read the second line from the text file
    //becasue the file offset has moved

    while(1){
        char* line = NULL;
        size_t n = 0;
        size_t string_length = getline(&line, &n, file); 
        if(feof(file)){
            free(line);
            break;
        }

        //Tokenize using strtok

        //Create copies of the tokens of the heap, use strcpy

        //store pointers in movie struct attributes

        //add to linked list

        /*
        line[string_length - 1] = '\0';

        printf("%s\n", line);
        */

        free(line);
    }

    fclose(file);

    //At end of program, free all movies.
}