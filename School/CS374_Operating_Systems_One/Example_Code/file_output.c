#include <stdio.h>

int main(){
    //When you open a file in a progeam, a  file descriptor is created
    //to represent the programs handle on that file.

    //File descriptors are just integers
    //File descriptor 0 represents standard input.
    //File descriptor 1 represents standard output.
    //File descriptor 2 represents standard error.

    //if the program opens files, it usually starts at 3 and counts up

    //Every process has its own mappings from file descriptors to files

    //every process has a file descriptor table
    FILE* file = fopen("file.csv", "w");
    fprintf(file, "Name,Age\n");

    int age = 72;
    fprintf(file, "John,%d\n", age);


    fclose(file);
}