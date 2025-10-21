#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//to check memory leaks:
//1. compile the program with -g flag, i.e.,
//   g++ dynamic_memory.cpp -g
//
//2. attach valgrind to the executable, i.e.,
//   valgrind --leak-check=full ./a.out

// Takes an int argument representing the size of the array, 
// and returns the base address of the dynamically allocated
// array
int* create_array1(int size){
	//Cael did this one
	cout << "pick a number: ";
	cin >> size;
	int *array = new int [size];
	return array;
}


// Takes a reference to an int pointer, and an int argument
// representing the size of the array. Stores the base address
// of the dynamically allocated array in the int pointer
// that’s supplied via the reference parameter
void create_array2(int*& array, int size){
	cout << "pick a number: ";
	cin >> size;
	array = new int[size];
	for(int i = 0; i < size; i++){
		int* ptr = &array[i];
		cout << ptr << endl;
	}


}

// Takes a pointer to an int pointer, and an int argument
// representing the size of the array. Stores the base address
// of the dynamically allocated array in the int pointer
// that’s supplied via the pointer parameter (i.e., stores the
// base address in the int pointer that the int double-pointer
// parameter points to)
void create_array3 (int** array, int size);
//Katie did this one, wasnt able to copy it.


int main()
{
	int size;
	int* arr;
	int *array1 = create_array1(size);
	//function calls go here:
	create_array2(arr, size);

	delete [] arr;
	delete [] array1;
	
	return 0;
}
