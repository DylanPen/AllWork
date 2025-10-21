#include <iostream>
#include <string>

#include "person.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


person* create_person_array(int size){
	person *array = new person[size];
	return array;
}

void init_person_array(person* array, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter name for person " << (i + 1) << ": ";
		cin >> array[i].name;
		cout << "Enter age for person " << (i + 1) << ": ";
		cin >> array[i].age; 
		cout << endl;
	}
	return;
}

void print_person_array (person* array, int size){
	for (int i = 0; i < size; ++i)
	{
		cout << "person " << i+1 << ": " << endl;
		cout << "Name: " << array[i].name << endl;
		cout << "Age: " << array[i].age << endl;
		cout << endl;
	}
	return;
}

void delete_person_array(person* array){
	delete [] array;
}
