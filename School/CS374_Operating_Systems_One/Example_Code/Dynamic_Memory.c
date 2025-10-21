#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //Automatic variable. Automatic storage duration
    //Automatic variables will always live at least as long as their scopes
    //Automatic variables are stored on the stack.

    //Dynamic memory has dynamic storage duration. Dynamic memory exists until you delete it.

    //Arrays can never be changed
    //Trick: Create new array, copy data, delete the old array

    //"The Stack" is a stack data structure, LIFO (Last in, first out)

    //Creating dynamic memory:
    size_t size = 10; 
    double* array = (double*) malloc(sizeof(double) * size);
    
    //If I want to add to the 11th element
    //Step 1: Make a new array of correct size
    double* new_array = (double*) malloc(sizeof(double) * (size + 1));

    //Step 2: Copy data over
    memcpy(new_array, array, sizeof(double) * size);
    size = 11;

    //Step 3: add new element to end of new array
    new_array[10] = 3.14;

    //Step 4: Delete old array
    free(array);
    //array now points to an old, deleted array (dangling pointer)

    //Step 5: Update old pointer to point to new array
    array = new_array;

    //Check for memory leaks
        //compile with -g
        // valgrind <executable file name>
        //memory leak for new array (still need to free at end of program)
    free(array); //free(new_array) also works, they point to the same thing.
    array = NULL;
    //This prevents double frees, which could cause undefined behavior.




}
