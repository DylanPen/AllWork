#include <iostream>

#include "person.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// Prompt the user for the size of the array
	int size;
	cout << "Enter number of people: ";
	cin >> size;

	// Allocate array's memory
	person *people = create_person_array(size);

	// Initialize / populate the array
	init_person_array(people, size);

	// Print the array
	print_person_array(people, size);

	// Delete the array
	delete_person_array(people);

	// Assigning to null is good practice. Otherwise, there's no way to
	// tell (programmatically, like with an if statement) whether the
	// pointer still points to allocated memory.
	people = nullptr; 

	return 0;
}
