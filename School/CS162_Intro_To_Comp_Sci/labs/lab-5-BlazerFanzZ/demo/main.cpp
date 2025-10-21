#include <iostream>

#include "rectangle.hpp"

using std::cout;
using std::endl;

int main() {
	// Using default constructor and setters
	rectangle r1;
	r1.set_width(10);
	r1.set_height(2.5);
	r1.print();
	cout << "r1's area: " << r1.area() << endl;

	// Using nondefault constructor
	rectangle r2(10, 2.5);
	r2.print();
	cout << "r2's area: " << r2.area() << endl;
}
