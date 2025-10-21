#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Structure types

struct person {
    int age;
    double favorite_number;
};

//Functions

double volume_of_sphere(double radius){
    //Function body
    return 4.0 / 3.0 * 3.1415926535897 * pow(radius, 3);
}

void print_hello_world(){
    printf("Hello World!");
}

void print_person(struct person p){
    printf("%d", p.age);
    printf("%lf", p.favorite_number);
}

void change_me(int* y){
    *y = 10;
}

double average(float* array, int size){
    float sum = 0.0;
    for(int i = 0; i < size; ++i){
        sum += array[i];
    }
    return sum;
}

//int* return5(){
//    int x = 5;
//    return &x;
//}

int main(){ 
    /*
    printf("Hello, World!\n");
    fflush(stdout);
    */

    //Primitive data types in C;
    //int: Integer
    //float: Floating point number
    //long int (long): Long integer 
    //double: Double-precision floating point number
    //char: Character
    
    //Literals:
    //int: 12
    //float: 3.14f
    //long int (long): 12l
    //double; 3.14
    //char: 'c'

    //the first argument of printf is the format string
    //the format string is text with placeholders
    //those placeholders are called format specifiers
    //%d is a placeholder for a whole decimal value
    //%f if a placeholder for floating point values
    //%lf is a placeholder for long floating point values (i.e. doubles)
    //%ld is a placeholder for long decimal values (i.e. long int)
    printf("%d %lf\n", 12 * 3, 3.14f);

    //Arithmetic opperators:
    // +
    // -
    // *
    // /
    // %
    // ^ (Bitwise XOR)

    // Floating point -> Integral. Rule is truncation
    // Integral type -> floating point. rule is add .0 at the end
    printf("%d\n", (int) (1.0 / 2));

    //Before you can use a variable, you must declare it first.
    //To declare a variable:
    int favorite_number;

    //IMPORTANT: Using an uninitialized variable results in undefined behavior
    printf("%d\n", favorite_number);

    //To assign a value to a variable, use the assignment opperator
    //When you first assign a vlaue to a variable, you initialize it
    favorite_number = 100;

    int x = 10;

    //Relational opperators
    //==
    //!=
    //>
    //>=
    //<
    //<=

    //Logical opperators
    //||
    //&&
    //!
    //"short circuiting":
    //|
    //&

    //if statements in C:
    if(/*Boolean expression*/x == 1){ 
        //Body
    }
    else if(/*Boolean expression*/x == 2){

    }
    else{

    }

    //Loops in C
    //While loops
    //do while loops
    //for loops

    int i = 0;
    while(i < 10){
        printf("%d\n", i);
        i++;
    }

    do{
        printf("%d\n", i);
        i--;
    } while(i > 0);

    for(i = 0; i < 20; ++i){
        printf("hi\n");
    }

    //Break ends loop
    //Continue jumps to next part of loop

    //To create an array in C:
    int arr[100];

    //To access an array you index it
    arr[0] = 5;

    int my_arr[10] = {1,2,3,4,5,6,7,8};
    //last 2 slots ([8] and [9] are 0)

    int zeros[100] = {0};

    //This is a buffer over-read
    //int some_int_var = my_array[10];

    //This is a buffer overflow
    //my_arr[10] = 5

    //buffer over-reads and overflows invoke undefined behavior

    //USING VALGRIND
        //gcc -g -o <name> <program_file>
        //valgrind <name>
    double volume = volume_of_sphere(2.0);
    print_hello_world();

    struct person p;
    p.age = 4;
    p.favorite_number = 21.0;

    //Pointers
    char mychar, mychar2;
    mychar = 'C';
    char* mypointer;
    mypointer = &mychar;
    char* mypointer2 = mypointer;
    mypointer2 = &mychar2;
    *mypointer2 = *mypointer;

    int z = 5;
    change_me(&z);

    struct person john;
    struct person sally;

    struct person* john_ptr = &john;
    (*john_ptr).age = 27;
    john_ptr->age = 28;

    //Double pointers
    struct person** john_ptr_ptr = &john_ptr;
    (*john_ptr_ptr)->age = 30; 

    *john_ptr_ptr = &sally;
    (*(*john_ptr_ptr)).age = 15; //changes age of sally

    //in C, NULL is a macro for 0
    int* my_ptr = NULL;

    float numbers[10] = {1, 2, 3};
    printf("%p\n", numbers);

    float* pointer = numbers;
    //Same thing
    *pointer = 5.4;
    pointer[0] = 5.4;

    printf("%f\n", numbers[0]);

    double av = average(numbers, 10);

    //Dangling pointers
    //A pointer that leads to nothing, different than a NULL pointer
    //Its a pointer that used to point to something, but now doesn't

    //int* some_pointer = return5();
    //some_pointer is a dangling pointer;
    //dereferencing is known as a use-after-free error
    //this invokes undefined behavior

    //Strings
    //In C, a string is an array of characters which contants end in one or more NULL terminators
    //There are 3 ways of creating C strings:

    //Method 1.
    //This creates an array of characters that is big enough to store the desired C string.
    //This is an array of 6, need room for the null terminator.
    //it populates the array with each char of the string with a null term at the end
    //It then gives the base address of the array, IE. the first char of the array

    //IMPORTANT: the C string is IMMUTABLE when made this way, meaning it cant be changed.
    const char* my_c_string_1 = "Hello";

    //my_c_string_1[0] = 'J' does not work and will seg fault of not const.

    //Method 2.
    //This creates an array of charactes that is just big enough to store the C string.
    //Same as last one but is MUTABLE
    //The array length is FIXED to at least 6, cant trust it to be larger than 6.

    char my_c_string_2[] = "Hello";
    my_c_string_2[0] = 'J'; //This is ALLOWED

    printf("%s\n", my_c_string_2);


    //Method 3.
    // Creates array of Chars of specified size and populates the first n+1 elemetnts
    // All other elemtns are undefined

    char my_c_string_3[256] = "Hello";
        printf("%s\n", my_c_string_3);

    char user_input[256];
    printf("%s\n", "Enter your name: ");
    fgets(user_input, 256, stdin);
    //strlen(user_input); returns # of chars in string before NULL terminators
    printf("%s\n", user_input);
    char age_string[256];
    int age = strtol(age_string, NULL, 10);

    //Copy a string
    const char* c_string = "hole freaking airball";
    char c_string_2[strlen(c_string) + 1];
    strcpy(c_string_2, c_string);

}