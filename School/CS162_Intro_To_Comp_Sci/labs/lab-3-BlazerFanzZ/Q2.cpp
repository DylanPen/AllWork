/*CS 162 - Lab 3 - Q.2*/

#include <iostream>

// This is an exercise in pass-by-value vs pass-by-pointer
// vs pass-by-reference. When the inline comments say "a", they're
// really referring to the value pointed to by a. When they say
// "b", they're really referring to the value referenced by b.
int foo(int* a, int& b, int c){
	/*Set a to 2 times its original value*/
	*a = (*a) * 2;
	//std::cout << a << std::endl;

	/*Set b to half of its original value*/
	b = b/2;
	//std::cout << b << std::endl;

	/*Assign a + b to c*/
	c = *a + b;
	//std::cout << c << std::endl;

	/*Return c*/
	return c;
}

int main(){
	/*Declare three integers x, y, and z, and initialize them to 7, 8, 9 respectively*/
	int x = 7, y = 8, z = 9;

	/*Print the values of x, y and z*/
	std::cout << x << std::endl << y << std::endl << z << std::endl;

	/*Call foo() appropriately, passing x, y, and z as arguments by pointer, reference, and value*/
	z = foo(&x, y, z);

	/*Print the value returned by the previous call to foo() (did you remember to store it?)*/
	std::cout << z << std::endl;
	/*Print the values of x, y and z again*/
	std::cout << x << std::endl << y << std::endl << z << std::endl;
	/*Is the return value different than the value of z? Why or why not? */
	//yes becaseu it was passed by value not by reference or pointer.
}
